// summon. ȡ�ر���

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;

	if (! str)
                return notify_fail("��Ҫ�ٻ�ʲô��Ʒ��\n");

        if (! stringp(str = me->query("can_summon/" + str)))
                return notify_fail("�㲻֪������ٻ������Ʒ��\n");

	if (me->is_ghost())
		return notify_fail("���㻹�������ٻ��ɡ�\n");

        call_other(str, "???");
        ob = find_object(str);
        if (! ob || ! ob->receive_summon(me))
        {
                message_vision(HIM "$N" HIM "��������������������"
                               "�ʡ�\nȻ��ʲôҲû�з��� :)\n", me);
        }

	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : summon <��Ʒ��ID>

��ָ��������ĳЩ��Ʒ����������װ���ϣ���Ȼ�����һ����
����ʩչ�������С�
HELP
    );
    return 1;
}
