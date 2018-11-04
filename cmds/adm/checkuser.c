// checkuser.c
// Doing

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object ob;
        int period;
        int min;
        int sec;

	seteuid(geteuid(me));

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

	if(!arg)
		ob = me;
	else
        {
		if (! ob) ob = find_player(arg);
		if (! ob) ob = find_living(arg);
                if (! ob) return notify_fail("��Ҫ�����һλʹ���ߣ�\n");
	}

        period = time() - (int) ob->query("last_save");
        min = period / 60;
        sec = period - min * 60;
        if (period == 0)
                write ("��ʹ���߸ոձ�������ȡ�\n");
        else
        {
                write("��ʹ���߾��ϴδ���ʱ����");
                if (min) write (chinese_number(min) + "����");
                if (sec) write (chinese_number(sec) + "��");
                write ("��\n");
        }

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : checkuser <user>

�������������ѯʹ���ߵ�ĳЩ״̬�� 

HELP
    );
    return 1;
}
 
