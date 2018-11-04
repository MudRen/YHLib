#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("����Сͯ", ({ "maika xiaotong", "xiaotong" }));
        set("nickname", HIR "��������CARD" NOR);

        set("gender", "����");
        set("age", 8);
        set("str", 100);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 800000);
        set("attitude", "friendly");

        set("vendor_goods", ([
                "clone/megazine/obj/duka_11a" : 1000000,
                "clone/megazine/obj/duka_22a" : 1000000,
        ]));

        setup();
        set_max_encumbrance(100000000);
}
void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_drop", "drop");
}

