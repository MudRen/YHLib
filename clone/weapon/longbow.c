// longbow.c

#include <ansi.h>

inherit __DIR__"bow";

void create()
{
        set_name("����", ({ "long bow", "bow", "chang gong", "gong" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "һ�ų������������Ϊ���£������൱�õ�׼ȷ�ȡ�\n");
		set("value", 80000);
                set("power", 180000);   // ��������
                set("accuracy", 150);   // ׼ȷ��150%
        }
        setup();
}
