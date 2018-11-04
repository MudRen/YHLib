// free.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob;
        object card;
        int time;

        if (! SECURITY_D->valid_grant(me, "(arch)"))
                return 0;

	if (! arg)
                return notify_fail("��Ҫ��˭����������\n");

        if (sscanf(arg, "%s %d", arg, time) != 2)
                time = 0;

        ob = find_player(arg);
        if (! ob || ! me->visible(ob))
                return notify_fail("û�������ҡ�\n");

        if (! ob->is_in_prison())
                return notify_fail("����������û�б����ա�\n");

        if (! SECURITY_D->valid_grant(me, "(arch)"))
        {
                if (! objectp(card = present("help card", me)))
                        return notify_fail("��û��Ȩ�����˷ų�����\n");

                message_vision("$N����һ�ſ�Ƭ��ƴ����߶��̫���Ͼ���������" +
                               ob->name(1) + "�����޹�����\n", me);
                destruct(card);
        }

        ob->leave_prison(me, time);
        return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : free <���ID>
 
���ָ���������ѱ����յ�����ͷų�����

see also : throw
 
HELP
    );
    return 1;
}
