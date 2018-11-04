#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("Сѧͯ", ({ "xue tong","tong" }) );
        set("gender", "����" );
        set("age", 14);
        set("per", 30);
        set("long", "����һ��ʮ�������Сͯ�����Ĳ����ɵĸ��������������š�\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 5);
        set_skill("unarmed", 5);
        set_skill("parry", 5);
        set("max_qi", 200);

        set("chat_chance", 10);
        set("chat_msg", ({
                CYN "Сѧͯ�϶��������������֮�����Ա���������������\n" NOR,
                CYN "Сѧͯҡͷ���Ե�����������𣚣�ں����ޣ������㣬���Ӹ��ϡ�\n" NOR,
                CYN "Сѧͯ���������������������������������������������������\n" NOR,
                CYN "Сѧͯ�������͵������߲�����������˯������\n" NOR,
        }));

        setup();
        add_money("coin", 50);

        carry_object("/d/city/obj/cloth")->wear();
}
