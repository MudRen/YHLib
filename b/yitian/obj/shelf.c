#include <ansi.h>
inherit ITEM;

#define YITIAN    "/clone/lonely/yitianjian"

void create()
{
        object ob;
        set_name(NOR + RED "��ľ����" NOR, ({ "shelf" }));
        set("long", NOR + RED "\n����һ�����ϵȺ�ľ���ƶ��ɵĽ��ܡ�\n" NOR);
        set_weight(5000000);
        set_max_encumbrance(800000);

        set("unit", "��");
        set("no_get", 1);
        if (clonep())
        {
                set_default_object(__FILE__);
                ob = find_object(YITIAN);

                if (! ob)
			ob = load_object(YITIAN);

                if (! environment(ob))
			ob->move(this_object());
        }
}