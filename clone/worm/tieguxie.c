inherit WORM;
#include <ansi.h>

void create()
{
        set_name(CYN "����Ы" NOR, ({ "tiegu xie", "tiegu", "xie" }));
        set("long", CYN "����һ��ȫ�������׹�Ķ�Ы�ӡ�\n" NOR);
        set("race", "Ұ��");
        set("age", random(10));
        set("attitude", "peaceful");

        set("max_qi", 500);
        set("max_jing", 300);

        set("str", 40);
        set("con", 30);
        set("limbs", ({ "ͷ��", "����", "β��" }));
        set("verbs", ({ "bite" }));

        set("worm_poison", ([
                "level"  : 70,
                "perhit" : 10,
                "remain" : 45,
                "maximum": 45,
                "supply" : 1,
        ]));

        set("combat_exp", 25000 + random(25000));

        set_temp("apply/attack", 50);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 200);
        set_temp("apply/defence", 100);
        setup();
}

void die()
{
        message_vision(HIR "\n$N" HIR "���ڵ��ϣ����ˡ�\n\n" NOR, this_object());
        destruct(this_object());
}
