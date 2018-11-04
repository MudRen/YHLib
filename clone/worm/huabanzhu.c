inherit WORM;
#include <ansi.h>

void create()
{
        set_name(HIR "������" NOR, ({ "huaban zhu", "huaban", "zhu" }));
        set("long", HIR "����һֻȫ����ʰ�쵵Ķ�֩�롣\n" NOR);
        set("race", "Ұ��");
        set("age", random(10));
        set("attitude", "peaceful");

        set("max_qi", 300);
        set("max_jing", 150);

        set("str", 30);
        set("con", 30);
        set("limbs", ({ "ͷ��", "����", "����", "����" }));
        set("verbs", ({ "bite" }));

        set("worm_poison", ([
                "level"  : 40,
                "perhit" : 15,
                "remain" : 30,
                "maximum": 30,
                "supply" : 2,
        ]));

        set("combat_exp", 5000 + random(5000));

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 15);
        set_temp("apply/armor", 30);
        set_temp("apply/defence", 30);
        setup();
}

void die()
{
        message_vision(HIR "\n$N" HIR "���ڵ��ϣ����ˡ�\n\n" NOR, this_object());
        destruct(this_object());
}
