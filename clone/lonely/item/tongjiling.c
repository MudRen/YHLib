#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + RED "ͨ����" NOR, ({ "tongji ling", "tongji", "ling" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + RED "����һ����Ͱ͵�ͨ������滹��"
                            "������Ѫ����\n" NOR);
                set("unit", "��");
                set("value", 10);
                set("no_sell", "�١��ٸ���ͨ�����Ҳ��������Ǯ��");
                set("material", "paper");
        }
        setup();
}
