#include <ansi.h>

inherit NPC;
inherit F_GUARDER;

void create()
{
        set_name("����", ({ "men wei", "men", "wei" }));
        set("long", @LONG
���Ǹ��긻��ǿ������������ʮ�����ϡ���Ȼ
�������ղ��ߣ����Ǿ���ŷ�����ѵ��������
���˿ɵС�
LONG);
        set("nickname", WHT "��ʨ��" NOR);
        set("gender", "����" );
        set("age", 22);
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 23);
        set("int", 23);
        set("con", 22);
        set("dex", 20);

        set("max_qi", 1200);
        set("max_jing", 600);
        set("neili", 1700);
        set("max_neili", 200);
        set("combat_exp", 50000 + random(50000));
        set("score", 10000);

        set_skill("force", 100);
        set_skill("dodge", 80);
        set_skill("unarmed", 100);
        set_skill("parry", 80);

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);

        set("coagents", ({
                ([ "startroom" : "/d/baituo/dating",
                   "id"        : "ouyang feng" ]),
        }));

        create_family("ŷ������", 0, "����");

        setup();
        add_money("silver", 2);
        carry_object("/d/baituo/obj/dadao")->wield();
}

void init()
{
        object ob;

        ::init();

        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        if (check_family(ob, "ŷ������"))
        {
                say(CYN "����Ц�����ص�����λ" + RANK_D->query_respect(ob) +
                    CYN "�������ˣ�������ɡ�\n" NOR);
                return;
        }

        if ((int)ob->query("shen") > 200)
        {
                say(CYN "��������һ�ɵ�����λ" + RANK_D->query_respect(ob) +
                    CYN "���������鷳�İɣ�\n");
                return;
        }
}
