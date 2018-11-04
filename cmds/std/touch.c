// touch.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;

	if (! arg)
                return notify_fail("��Ҫ����ʲô��Ʒ��\n");

	if (! objectp(obj = present(arg, me)) &&
            ! objectp(obj = present(arg, environment(me))))
		return notify_fail("������û����������������Ҳû�С�\n");

        if (obj->is_character())
                return notify_fail("����Ҷ�" + obj->name() + "�ˡ�\n");

        notify_fail("������һ��" + obj->name() + "��\n");
        return obj->do_touch(me);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : touch <��Ʒ����>
 
���ָ��������㸧��ĳ�����������Է�����������������
 
HELP );
        return 1;
}
