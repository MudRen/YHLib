#include <ansi.h>

inherit NPC;
inherit F_DEALER;

int redeem(string arg);
mixed ask_back();

void create()
{
        set_name("���", ({ "tang nan", "tang", "nan" }));
        set("title", "�����ϰ�");
        set("shen_type", 0);
        set("gender", "����");
        set_max_encumbrance(100000000);
        set("age", 35);
        set("str", 100);
        set("long", "��˵������Ĵ��Ƽҵĺ����\n");
        set("no_get_from", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");

        set("inquiry", ([
                "���־�ת" : (: ask_back :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
}

mixed ask_back()
{
        object me;

        me = this_player();
        if (me->query("family/family_name") != "������")
        {
                message_vision(CYN "$N" CYN "һ��ãȻ����ɶ���ղ���˵ɶ��\n" NOR,
                               this_object(), me);
                return -1;
        }

        message_sort(HIY "\n$N" HIY "���˿�$n" HIY "����Ц�������漴��$n"
                     HIY "���ߵ���˵������С�����Ϊ�����˼�׼�����ˣ���"
                     "�ڹ�̨���棬����������ɡ���˵��$N" HIY "������$n"
                     HIY "�첽��������ȥ��\n\n" NOR, this_object(), me);
        me->move("/d/city/xsmidao");
        tell_object(me, CYN + name() + "˵�������������һֱ���Ͼ����ˡ�\n"
                        HIC + name() + "˵��㼱��ææ���˻�ȥ��\n" NOR);
        return -1;
}

void unconcious()
{
        die();
}

void die()
{
        message_vision("\n$N���ˡ�\n", this_object());
        destruct(this_object());
}
