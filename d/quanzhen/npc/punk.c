#include <ansi.h>
inherit NPC;

void create()
{
        set_name("С��å", ({ "xiao liumang", "xiao", "liumang" }));
        set("gender", "����" );
        set("age", 18);
        set("long", "����һ�����ֺ��е�С��å��\n");
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 500);
        set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                CYN "��å������������а����������һ�����ƣ���С�������־�Ȼ\n"
                "������һ����������\n" NOR,

                CYN "��å�������Լ��Ŀڴ���̾�˿���˵��������Ǯ������С��ƭȥ\n"
                "�ˣ�����ȥ�Ҵ仨�ˡ�\n" NOR,

                CYN "��å���¶��һ˿аЦ��˵�����仨�������������̵Ĺ�������\n" NOR,
        }));
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("silver", 5);
}
