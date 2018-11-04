// tell.c

#include <ansi.h>
#include <net/dns.h>
#include <net/messaged.h>
#include <mudlib.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int notice_user(string my_name, string my_id, object obj, string tell_out);
int help(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, msg, mud;
        string my_id;
	object obj;
        string no_tell, can_tell;
        string tell_out;

	if (! arg || sscanf(arg, "%s %s", target, msg) != 2)
                return help(me);

	if (sscanf(target, "%s@%s", target, mud) == 2)
	{
		if (GTELL->send_gtell(mud, target, me, msg))
		{
			write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
			return 1;
		}
	}

	obj = find_player(target);
	if (! obj || ! me->visible(obj))
	{
		if (MESSAGE_D->send_msg_to(me, target, msg))
			return 1;
		return notify_fail("����û�û�е�¼�����޷�������̸��\n");
	}

        my_id = me->query("id");
        no_tell = obj->query("env/no_tell");
	if (! wizardp(me) && (no_tell == "all" || no_tell == "ALL" ||
	    is_sub(my_id, no_tell)))
        {
                can_tell = obj->query("env/can_tell");
                if (! is_sub(my_id, can_tell))
		        return notify_fail("����˲���������������\n");
        }

	if (! interactive(obj) || obj->is_net_dead())
		return notify_fail("�������ڲ������ϣ���������Ļ���\n");

	if (! living(obj))
		return notify_fail("�������ڿ�����������˵�Ļ���...\n");

        if (me->ban_say(1))
                return 0;

        if (obj == me)
        {
                message_vision("$N�����\n", me);
                return 1;
        }

        tell_out = sprintf(HIG "%s�����㣺%s\n" NOR,
		           me->name(1) + HIG + "(" +
                           capitalize(my_id) + ")", msg);
        if (! notice_user(me->name(1), my_id, obj, tell_out))
                return 1;

	write(sprintf(HIG "�����%s(%s)��%s\n" NOR,
                      obj->name(1) + HIG,
                      capitalize(obj->query("id")), msg));

        if (query_idle(obj) >= 120)
                write(YEL "����" + obj->name(1) +
                      YEL "�Ѿ�����Ȧ�з�����" + chinese_number(query_idle(obj) / 60) +
                      "�����ˣ�����û�����̻ش��㡣\n");

	return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg, int wiz_level)
{
	object ob;
	string fromid;
	string no_tell;
	string can_tell;
        mapping conn;
        string reject;
        string tell_out;

	if (ob = MESSAGE_D->find_user(to))
        {
		if (ob->query("env/invisible"))
			return "��������ڲ������ϡ�";

		fromid = lower_case(from + "@" + mud);
		no_tell = ob->query("env/no_tell");
		if ((! intp(wiz_level) || wiz_level < 3) &&
                    (no_tell == "all" || no_tell == "ALL" ||
	             is_sub(fromid, no_tell)))
        	{
                	can_tell = ob->query("env/can_tell");
                	if (! is_sub(fromid, can_tell))
		        	return "����˲���������������";
        	}

		fromid = capitalize(from) + "@" + upper_case(mud);
		msg = replace_string(msg, "\n", "");
		if (cname)
                        tell_out = sprintf(HIG "%s(%s)�����㣺%s\n" NOR,
                                           cname, fromid, msg);
		else
                {
                        cname = "δ֪";
			tell_out = sprintf(HIG "%s �����㣺%s\n" NOR,
				           fromid, msg);
                }

                to = capitalize(to);
                if (! notice_user(cname, fromid, ob, tell_out))
                        msg = sprintf(HIG "��Ļ�û���͵�%s(%s@%s)�Ķ��ߡ�\n" NOR,
                                      ob->name(1), to, upper_case(INTERMUD_MUD_NAME));
                else
		        msg = sprintf(HIG "�����%s(%s@%s)��%s" NOR, ob->name(1), to,
			              upper_case(INTERMUD_MUD_NAME), msg);
                return msg;

	} else
		return "��������ڲ������ϡ�";
}

// ����Ϣ�͸��Է�
int notice_user(string my_name, string my_id, object obj, string tell_out)
{
        int i;
        mixed info;
        mixed *list;
        mixed piece;

        if (obj->query("env/jam_talk"))
        {
                // ����ʽ��̸
                info = ({ my_name, my_id, tell_out });
                list = obj->query_temp("tell_list");
                if (! arrayp(list) || sizeof(list) < 1)
                {
                        // �Է�û��������Ϣ��ֱ��֪ͨ�Է�
                        tell_object(obj, tell_out);
                        obj->set_temp("reply", my_id);
                        list = ({ info });
                } else
                if (arrayp(list[0]) && sizeof(list[0]) >= 3 &&
                    list[0][1] == my_id)
                {
                        // �Է����������Ǻ��ҽ�̸����Ϣ������
                        // ������Ϣ��û�б�Ҫ�ӳٷ�����
                        tell_object(obj, tell_out);
                } else
                {
                        // �������е���ʷ��Ϣ���鿴�Ƿ��Ѿ���
                        // ��̸�ļ�¼��
                        for (i = 1; i < sizeof(list); i++)
                        {
                                piece = list[i];
                                if (! arrayp(piece) || sizeof(piece) < 3 ||
                                    ! stringp(piece[2]))
                                {
                                        // ������ʷ��¼���Ϸ�
                                        list[i] = 0;
                                        continue;
                                }

                                if (piece[1] == my_id)
                                {
                                        // �ҵ��˺ͶԷ���ǰ��̸����Ϣ
                                        if (strlen(piece[2]) > 32768)
                                        {
                                                // ��ʷ��Ϣ�Ѿ�����32K��
                                                write("���Ѿ�˵�˺ö໰�ˣ��ȵȱ�������ɡ�\n");        
                                                return 0;
                                        }

                                        // ��¼��ν�̸����Ϣ
                                        piece[2] += tell_out;
                                        info = 0;
                                }
                        }
                        list -= ({ 0 });

                        // ����˻���û������Ļ���
                        if (arrayp(info))
                        {
                                if (sizeof(list) > 12)
                                {
                                        write(obj->name(1) + "�����Ѿ���̫��"
                                              "�Ļ��ˣ��㻹�ǵȻ����˵�ɡ�\n");
                                        return 0;
                                }

                                // ��¼��仰
                                list += ({ info });
                                if (! in_input(obj))
                                        obj->write_prompt();
                        }
                }
                obj->set_temp("tell_list", list);
        } else
        {
                // ��������
                obj->set_temp("reply", my_id);
                tell_object(obj, tell_out);
        }

        return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵��������Է�ѡ������ʽ��
̸����ô�����ܲ�������������˵�Ļ���

�������ָ�reply��skip
HELP );
	return 1;
}
