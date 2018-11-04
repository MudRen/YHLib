#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("��ũ", ({ "hua nong", "hua", "nong" }));
        set("title", HIY "��������" NOR); 
        set("gender", "����");
        set("long", "һ���������ص���ũ���������������Ի�\n"
                    "�ֲ���ʮ�꣬�����Ҳ���ڴ��ֻ�������\n"
                    "������һЩ���ӡ�\n");
        set("str", 100);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 800000);
        set("attitude", "friendly");

        set("vendor_goods", ([
                __DIR__"obj/huazhong": 1,
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        set_max_encumbrance(100000000);
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
