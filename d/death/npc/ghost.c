#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "ghost" }) );
        set("long", HIB "\n\nһ�����ߵĻ��ǡ�\n" NOR);
        set("attitude", "peaceful");
        set("title", HIB "(����)" NOR);

        setup();
}

void receive_damage(string type, int n)
{
        return;
}

void receive_wound(string type, int n)
{
        return;
}
