#include <ansi.h>;
inherit ITEM;

string *names = ({
HIW "÷��" NOR,
HIM "÷��" NOR,
HIC "÷��" NOR,
HIY "÷��" NOR,
HIR "÷��" NOR,
});
void create()
{
        int i = random(sizeof(names));
        set_name(names[i], ({"mei ban", "mei", "ban"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("long", "һƬ�ոմ�����Ʈ���÷�ꡣ\n");
                set("value", 0);
                set("material", "plant");
                set_weight(1);
        }
        setup();
}

