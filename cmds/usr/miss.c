// miss ׷Ѱ��Ʒ

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;

	if (! str)
                return notify_fail("��Ҫ׷Ѱʲô��Ʒ��\n");

        if (! stringp(str = me->query("can_summon/" + str)))
                return notify_fail("�㲻֪�����׷Ѱ�����Ʒ��\n");

	if (me->is_ghost())
		return notify_fail("���㻹������׷Ѱ�ɡ�\n");

        if (me->is_busy() || me->is_fighting() || me->query("doing"))
                return notify_fail("����æ������˵�ɣ�\n");

        if (! objectp(ob = find_object(str)) || ! environment(ob))
                return notify_fail("���������Ҳ�޷���Ӧ�������Ʒ��\n");

        if (ob->query("magic/blood") < 3)
                return notify_fail("���������Ʒ���ں϶Ȳ������޷�׷Ѱ�������Ʒ��\n");

        ob->receive_miss(me);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : miss <������Ʒ��ID>

��ָ�������׷Ѱ�����Ƶ���Ʒ��������һ���ľ�������������
HELP
    );
    return 1;
}
