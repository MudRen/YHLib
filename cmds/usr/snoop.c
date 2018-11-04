// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string msg;
        object sob;
	object ob;

	if (! interactive(me))
		return 0;

	if (! arg)
	{
		if (objectp(ob = query_snooping(me)))
			write("���������ڼ���" + ob->query("name") +
			      "���յ���ѶϢ��\n");
                else
                        write("������û�м����κ��ˡ�\n");

		return 1;
	} else
        if (arg == "none")
	{
		snoop(me);
		write("Ok.\n");
		return 1;
	} else
        if (sscanf(arg, "-i %s", arg) || arg == "-i")
        {
                if (! SECURITY_D->valid_grant(me, "(admin)"))
                {
                        write("��������\n");
                        return 1;
                }

                if (arg == "-i")
                        ob = me;
                else
                        ob = find_player(arg);
                if (! objectp(ob))
                {
                        write("û���ҵ� " + arg + " �����ң��޷��鿴��Ϣ��\n");
                        return 1;
                }

                msg = "Ŀǰ�й�" + ob->name(1) + "(" + geteuid(ob) + ")�ļ���������£�\n";
                if (objectp(sob = query_snooping(ob)))
                        msg += "���ڼ���" + sob->name(1) + "(" + geteuid(sob) +
                               ")�յ�����Ϣ��\n";
                else
                        msg += "û�м����κ��ˡ�\n";

                if (objectp(sob = query_snoop(ob)))
                        msg += "���ڱ�" + sob->name(1) + "(" + geteuid(sob) +
                               ")������\n";
                else
                        msg += "û�б��κ���������\n";

                write(msg);
                return 1;
        }

	ob = find_player(arg);
	if (! ob) ob = find_living(arg);
	if (! ob || ! me->visible(ob))
		return notify_fail("û������ˡ�\n");

	if (! interactive(ob))
		return notify_fail("�����Ҳ������ϣ��޷�������\n");

	if (! is_sub(me->query("id"), ob->query("env/can_snoop")) &&
            ! SECURITY_D->valid_grant(me, "(arch)"))
		return notify_fail("�����Ҳ������������\n");

	if (wiz_level(ob) > wiz_level(me))
		return notify_fail("���Ȩ�޲��������Է���\n");

	if (me == ob) return notify_fail("���� snoop none ���������\n");
		
	snoop(me, ob);
	write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");
	if (playerp(ob)) log_file("snoop",
		sprintf("%s(%s-%s) snoops %s on %s.\n", me->name(1),
			geteuid(me), query_ip_number(ob), ob->name(1),
			ctime(time()) ) );

	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��snoop <ĳ��> | none | -i <ĳ��>

��������ʹ������������ѶϢ��snoop none ��ȡ�������������
�Է���ǰ���ǶԷ���������ô������������ can_snoop Ϊ���ID��

ʹ�� -i �������Բ鿴ĳ��Ŀǰ��������Ϣ��
TEXT );
	return 1;
}
