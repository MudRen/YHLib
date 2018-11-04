inherit WORM;
#include <ansi.h>

void create()
{
        set_name(HIB "�������" NOR, ({ "baizu wugong", "baizu", "wugong" }));
        set("long", WHT "����һ��һ�߶೤����򼣬���а��㡣\n" NOR);
        set("race", "Ұ��");
        set("age", random(10));
        set("attitude", "peaceful");

        set("max_qi", 250);
        set("max_jing", 100);

        set("str", 30);
        set("con", 30);
        set("limbs", ({ "ͷ��", "����", "β��" }));
        set("verbs", ({ "bite" }));

        set("worm_poison", ([
                "level"  : 20,
                "perhit" : 10,
                "remain" : 30,
                "maximum": 30,
                "supply" : 1,
        ]));

        set("combat_exp", 500 + random(500));

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 15);
        set_temp("apply/armor", 15);
        set_temp("apply/defence", 20);
        setup();
}

void die()
{
        message_vision(HIR "\n$N" HIR "���ڵ��ϣ����ˡ�\n\n" NOR, this_object());
        destruct(this_object());
}
