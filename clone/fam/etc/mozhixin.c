inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIY "ħ֮�ġ�ħ" NOR, ({"mozhi xin", "mozhi", "xin"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "���Ǽ���ر�ɫ���������䣬��ħ���������ϵı��֧����ħ�����\n" NOR);
                set("unit", "��");
                set("value", 13000);
                set("can_be_enchased", 1);
                set("magic/type", "magic");
                set("magic/power", 90 + random(11));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

