inherit WORM;
#include <ansi.h>

void create()
{
        set_name(HIY "�������" NOR, ({ "jinxian wugong", "jinxian", "wugong" }));
        set("long", HIY "����һֻ��ɫ����򼣬������һ��Ѫ�ߡ�\n" NOR);
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
                "level"  : 60,
                "perhit" : 20,
                "remain" : 40,
                "maximum": 40,
                "supply" : 3,
        ]));

        set("combat_exp", 25000 + random(25000));

        set_temp("apply/attack", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 100);
        set_temp("apply/defence", 100);
        setup();
}

void die()
{
        message_vision(HIR "\n$N" HIR "���ڵ��ϣ����ˡ�\n\n" NOR, this_object());
        destruct(this_object());
}
