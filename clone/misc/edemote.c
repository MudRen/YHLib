// edemote.c emote�༭��

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
        set_name(HIC "���鶯�ʱ༭��" NOR, ({"emote editor", "editor"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ܿ������ֵֹ���������������˵��(help editor)��\n");
                set("value", 1);
                set("no_sell", 1);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

int do_help(string arg)
{
        if (! arg || ! id(arg))
                return notify_fail("��Ҫ��ʲô������\n");
        write (@HELP
���ڱ��鶯�ʱ༭����˵����

����ʹ�õ�������� edemote��cpemote��rnemote��������μ���
Щ����İ�����

HELP );
        return 1;
}

