inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIM "����֮ͫ����" NOR, ({"leishen tong", "leishen", "tong"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "��̼䣬�߲�֮��͸����أ��������֮ʥ�ӵ������һ���������\n" NOR);
                set("unit", "��");
                set("value", 12000);
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 90 + random(11));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

