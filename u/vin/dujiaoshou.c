#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "���ǫF" NOR, ({ "unicorn" }));
        set("race", "Ұ��");
        set("age", 5);
        set("attitude", "peaceful");
        
        set("limbs", ({ "ͷ��", "����", "ǰ��", "����", "β��" }));
        set("verbs", ({ "bite", "claw" }));

        set("max_qi", 100000);
        set("max_jing", 100000);
        set("neili", 100000);
        set("max_neili", 100000);

        set("combat_exp", 100000000);
        set_temp("apply/attack", 2000);
        set_temp("apply/defense", 2000);
        set_temp("apply/unarmed_damage", 5000);
        set_temp("apply/armor", 5000);

        setup();
}
