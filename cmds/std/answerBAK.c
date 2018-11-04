// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string st, target;
	object ob, obj, env;
        mixed info;

	if (! arg || arg == "")
		return notify_fail("��Ҫ�ش�ʲô��\n");

        env = environment(me);

        if (me->query_temp("quest_gift/npc"))
        {
                int gift, gongxian;
                string un;

                obj = me->query_temp("quest_gift/npc");
                obj = present(obj, env);

                gongxian = me->query_temp("quest_gift/gongxian");

                if (arg == "Y" || arg == "y" || arg == "yes")
                        gift = 2;

                if (arg == "N" || arg == "n" || arg == "no")
                        gift = 1;

                if (objectp(obj) && environment(obj) == env
                   && living(obj) && gift == 2)
                {
                        message_vision(CYN "\n$N" CYN "��æ���ͷ��˵"
                                       "�����ⶫ��������Ҳ��Ҫ���ͽ���"
                                       "�Ұɡ�\n" NOR, me);

                        if (me->query("gongxian") < gongxian)
                        {
                                message_vision(CYN "$N" CYN "ͻȻһ�"
                                               "��˵�����ţ����������"
                                               "��������Ŭ�����´ΰɡ�"
                                               "\n" NOR, obj);
                                me->delete_temp("quest_gift");
                                return notify_fail(HIY "�������������"
                                                   "����ֵ�����ˡ�\n" NOR);
                        }

        	        ob = new(me->query_temp("quest_gift/obj"));

                        if (! ob)
                        {
                                message_vision(CYN "$N" CYN "���Ƶ���"
                                               "�ף��ҵĶ����أ��ղŻ�"
                                               "�ڣ���ôͻȻ��û�ˡ�\n"
                                               NOR, obj);
                                me->delete_temp("quest_gift");
                                return notify_fail("��Ʒ�ļ�����������"
                                                   "��������ʦ��ϵ��\n");
                        }

                        if (ob->query("base_unit"))
                                un = ob->query("base_unit");
                        else
                                un = ob->query("unit");

                        me->add("gongxian", -gongxian);
                        me->delete_temp("quest_gift");

                        message_vision(CYN "$n" CYN "΢΢һЦ���ӻ���"
                                       "ȡ��һ" + un + ob->name() +
                                       CYN "����$N" CYN "��\n" NOR,
                                       me, obj);
                        ob->move(me, 1);
                        return 1;
                } else
                if (objectp(obj) && environment(obj) == env
                   && living(obj) && gift == 1)
                {
                        message_vision(CYN "\n$N" CYN "��Ϊ���ε�˵����"
                                       "�š����������ⶫ��Ҳ���ô�����"
                                       "�����˰ɡ�\n" NOR, me);

                        message_vision(CYN "$n" CYN "��$N" CYN "̾����"
                                       "��Ҳ�գ���Ȼ�㲻��Ҫ���ⶫ����"
                                       "���������˰ɡ�\n" NOR, me, obj);

                        me->delete_temp("quest_gift");
                        return 1;
                }
        } else
                obj = 0;

	if (sscanf(arg, "%s %s", st, arg) == 2 &&
            ! objectp(obj = present(st, env)))
	{
		arg = st + " " + arg;
	}

        if (info = env->query("no_say"))
        {
                if (stringp(info))
                {
                        write(info);
                        return 1;
                }

                write("����ط����ܽ�����\n");
                return 1;
        }

	if (! stringp(target = me->query_temp("ask_you")))
		return notify_fail("�ղ�û��������ѯ�ʡ�\n");

        if (me->ban_say(1))
                return 0;

        if (objectp(obj) && ! playerp(obj) && ! obj->is_chatter())
                obj = 0;

	if (! obj) obj = find_player(target); 
	if (! obj) obj = MESSAGE_D->find_user(target); 

	if (! obj)
		return notify_fail("�ղ�����ѯ�ʵ��������޷������㣬��"
                                   "���Ѿ��뿪��Ϸ�ˡ�\n");

        if (environment(obj) != environment(me))
                return notify_fail("�ղ�����ѯ�ʵ������ڲ��������ˡ�\n");

	message_vision(CYN "$N" CYN "�ش�$n" CYN
		       "����" HIG + arg + NOR CYN "��\n" NOR, me, obj);

	if (userp(obj) || obj->is_chatter())
        {
                obj->set_temp("ask_you", me->query("id"));
                return 1;
        }

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��answer [ <player> ] <ѶϢ>

����������ָ��͸ղ��� ask ����˵����ʹ����˵�������
ָ���������ش�ָ������ҡ�

see also : tell
HELP
	);
	return 1;
}
