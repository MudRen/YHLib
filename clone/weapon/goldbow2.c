// goldbow.c

#include <ansi.h>

inherit __DIR__"bow";

void create()
{
        set_name(HIR "��ԧ��" NOR, ({ "chiyuan nu", "chiyuan", "nu", "bow" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", HIR "����һ��Ǧ�������������ƣ������ǳ���ϸ����\n" NOR);
                set("no_sell", "�ҵ��졭�������Ķ�����Ҳ����������");
		set("value", 80000);
                set("power", 200000);   // ��������
                set("accuracy", 200);   // ׼ȷ��200%
        }
        setup();
}
