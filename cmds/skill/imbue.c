// imbue.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string item, imbue;
	object obj, dest;

	if (! arg)
                return notify_fail("��Ҫ��ʲô�����Ͻ���������Ʒ��\n");

        if (me->is_busy())
                return notify_fail("��æ����������������������ɣ�\n");

        if (me->is_fighting())
                return notify_fail("���������ڴ�ܣ�ûʱ������Щ���顣\n");

        if (sscanf(arg, "%s with %s", item, imbue) != 2 &&
            sscanf(arg, "%s in %s", imbue, item) != 2)
                return notify_fail("��Ҫ�����������ʲô��Ʒ��\n");

	if (! objectp(obj = present(imbue, me)))
		return notify_fail("������û���������������������롣\n");

	if (! objectp(dest = present(item, me)))
		return notify_fail("������û���������ߡ�\n");

        notify_fail("���޷���" + obj->name() + "����" +
                    dest->name() + "��\n");
	return dest->do_imbue(me, obj);
}

int help(object me)
{
write(@HELP
ָ���ʽ : imbue <������Ʒ> in <����>
           imbue <����> with <������Ʒ>

���ָ��������㽫ĳ��������Ʒ��������һ�ֵ����У��Զ�������
���߻��Ƿ�������������
HELP
    );
    return 1;
}
