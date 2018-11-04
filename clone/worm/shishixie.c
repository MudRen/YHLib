inherit WORM;
#include <ansi.h>

void create()
{
        set_name(HIR "ʳʬЫ" NOR, ({ "shishi xie", "shishi", "xie" }));
        set("long", HIR "����һ������������ȫ�����׵Ķ�Ы�ӡ�\n" NOR);
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
                "level"  : 80,
                "perhit" : 30,
                "remain" : 35,
                "maximum": 35,
                "supply" : 2,
        ]));

        set("combat_exp", 25000 + random(25000));

        set_temp("apply/attack", 80);
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 80);
        set_temp("apply/defence", 80);
        setup();
}

void die()
{
        message_vision(HIR "\n$N" HIR "���ڵ��ϣ����ˡ�\n\n" NOR, this_object());
        destruct(this_object());
}
