// goldbow.c

#include <ansi.h>

inherit __DIR__"bow";

void create()
{
        set_name(HIY "���������" NOR, ({ "panlong gong", "gong", "panlong", "bow" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", HIY "����һ�Ž�ͭ�������������ƣ������ǳ���ϸ�ĳ�����\n" NOR);
                set("no_sell", "�ҵ��졭�������Ķ�����Ҳ����������");
		set("value", 80000);
                set("power", 250000);   // ��������
                set("accuracy", 120);   // ׼ȷ��120%
        }
        setup();
}
