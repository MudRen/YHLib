#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("������", ({ "yin changsheng", "yin", "changsheng" }));
        set("title", HIR "ڤ���ز�����ǰ" NOR);
	set("nickname", HIB "����" NOR);
        set("shen_type", 1);

        set("gender", "����");
        set("age", 475);
        set("long","���������Ǹ������ţ����ڷᶼɽ�������ɣ����⡸��������\n");

        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("magic", 500);
        set_temp("apply/damage", 2000);
        set_temp("apply/parry", 2000);
        set_temp("apply/dodge", 2000);
        set_temp("apply/attack", 2000);
        set_temp("apply/force", 2000);

        set("combat_exp", 20000000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/death/obj/armor1",
        }));
        
        setup();
        carry_object(__DIR__"obj/cloth5")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
