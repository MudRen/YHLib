#include <ansi.h>

inherit __DIR__"skpaper";

void create()
{
        set_name(NOR + WHT "ȭ���ƪ" NOR, ({ "quandian canpian6", "quandian", "canpian6" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ų�ȱ��ȫ����ҳ��\n" NOR);
                set("value", 30);
                set("no_sell", "ʲô��������һ����ֽͷҲ������Ǯ��");
                set("material", "paper");
                set("skill_name", "����צ��");
                set("skill_type", "claw");
                set("power_point", 30000);
                set("need_exp", 300000);
                set("min_lvl", 100);
                set("max_lvl", 300);
        }
        setup();
}
