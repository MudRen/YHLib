#include <ansi.h>;
inherit KNOWER;

void create()
{
        set_name("����", ({ "a man", "a", "man" }));
        set("gender", "Ů��");
        set("age", 18);
        set("long", "�����Ĺ����˹������������Ŀ毺ã��۹�����˸��Ц�⡣\n");
        set("shen_type", 1);
        set("per", 30);
        set("shen", 200);
        set("combat_exp", 2000);
        set("str", 16);
        set("dex", 18);
        set("con", 12);
        set("int", 24);
        set("attitude", "friendly");
        set("inquiry", ([
                "����" : "�������������㡣\n",
                "ë̺" : "���ˣ��뵽��������ѡ��\n",
                "������" : "������һ���������ء�\n",
        ]));
        setup();
        add_money("silver", 30);
        carry_object(__DIR__"obj/qcloth")->wear();
}
