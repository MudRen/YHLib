inherit WORM;
#include <ansi.h>

void create()
{
        set_name(RED "ǧ�����" NOR, ({ "qianjie wugong", "qianjie", "wugong" }));
        set("long", RED "����һ�����߶೤����򼣬��������ǧ��������ɡ�\n" NOR);
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
                "level"  : 40,
                "perhit" : 20,
                "remain" : 35,
                "maximum": 35,
                "supply" : 1,
        ]));

        set("combat_exp", 1500 + random(1500));

        set_temp("apply/attack", 25);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 40);
        set_temp("apply/defence", 40);
        setup();
}

void die()
{
        message_vision(HIR "\n$N" HIR "���ڵ��ϣ����ˡ�\n\n" NOR, this_object());
        destruct(this_object());
}
