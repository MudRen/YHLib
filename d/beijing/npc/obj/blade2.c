#include <weapon.h>
#include <ansi.h>

inherit BLADE;
void create()
{
        set_name("�̵�",  ({ "duan dao", "dao", "blade" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
                set("long", "һ���⼣�߰ߵĶ̵���������ֵ��������Ǯ��\n");
                set("no_sell", "���ߣ������ߡ�����ͭ����ֵʲôǮ��");
                set("material", "steel");
        }
        init_blade(10);
        setup();
}

