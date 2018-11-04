inherit WORM;
#include <ansi.h>

void create()
{
        set_name(WHT "�ұ�Ы" NOR, ({ "huibei xie", "huibei", "xie" }));
        set("long", WHT "����һֻ���������˻�ë�Ķ�Ы��\n" NOR);
        set("race", "Ұ��");
        set("age", random(10));
        set("attitude", "peaceful");

        set("max_qi", 200);
        set("max_jing", 100);

        set("str", 30);
        set("con", 30);
        set("limbs", ({ "ͷ��", "����", "β��" }));
        set("verbs", ({ "bite" }));

        set("worm_poison", ([
                "level"  : 25,
                "perhit" : 10,
                "remain" : 30,
                "maximum": 30,
                "supply" : 1,
        ]));

        set("combat_exp", 1000 + random(1000));

        set_temp("apply/attack", 25);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 20);
        set_temp("apply/defence", 20);
        setup();
}

void die()
{
        message_vision(HIR "\n$N" HIR "���ڵ��ϣ����ˡ�\n\n" NOR, this_object());
        destruct(this_object());
}
