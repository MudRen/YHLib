#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��Ʀ", ({ "di pi", "di", "pi" }));
        set("gender", "����" );
        set("age", 20);
        set("long", "����һ���ȵ��������ĵ�Ʀ��\n");
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set("combat_exp", 750);
        set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();

        set("chat_chance", 15);
        set("chat_msg", ({
                CYN "��Ʀ���Ժ����ĺ������������ð�������ְ���\n" NOR,
                CYN "��Ʀ����ǽ�ǣ������������������\n" NOR,
        }));
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("silver",8);
}
