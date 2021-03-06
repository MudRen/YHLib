#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW "獨角獸" NOR, ({ "unicorn" }));
        set("race", "野兽");
        set("age", 5);
        set("attitude", "peaceful");
        
        set("limbs", ({ "头部", "身体", "前蹄", "后蹄", "尾巴" }));
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
