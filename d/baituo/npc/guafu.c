#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�Ѹ�", ({ "gua fu", "gua", "fu" }));
        set("gender", "Ů��" );
        set("age", 25);
        set("long", "һ������Ư���ֲ��ʼ�į��С�Ѹ���\n");
        set("shen_type", -1);
        set("combat_exp", 10000);
        set("str", 18);
        set("dex", 19);
        set("con", 19);
        set("int", 19);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
                CYN "С�Ѹ����ţ��ҿ����ķ��ۣ�����ôƲ���Ҳ�����Ӵ��\n" NOR,
                CYN "С�Ѹ�Ĩ�˰����ᣬ���������һ�ۡ�\n" NOR,
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
