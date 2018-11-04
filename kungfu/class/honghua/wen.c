#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_GUARDER;

mixed ask_skill1();

void create()
{
        set_name("��̩��", ({ "wen tailai", "wen","tailai" }));
        set("title", "�컨���ĵ���");
        set("nickname", HIW "������" NOR);
        set("long", "��̩���ųơ������֡���ʮ�������˵�������\n"
                    "���²�֪���й�������������ͽ��ԡ�\n");
        set("gender", "����");
        set("age", 34);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 10000);

        set_skill("force", 200);
        set_skill("honghua-xinfa", 200);
        set_skill("tianchi-neigong", 200);
        set_skill("strike", 220);
        set_skill("benlei-zhang", 220);
        set_skill("dodge", 200);
        set_skill("hanwang-qingdao", 200);
        set_skill("blade", 200);
        set_skill("yanzi-chuanyun", 200);
        set_skill("parry", 200);
        set_skill("martial-cognize", 180);
        set_skill("literate", 150);

        map_skill("force"  , "tianchi-neigong");
        map_skill("blade"  , "hanwang-qingdao");
        map_skill("strike" , "benlei-zhang");
        map_skill("dodge"  , "yanzi-chuanyun");
        map_skill("parry"  , "benlei-zhang");

        prepare_skill("strike", "benlei-zhang");

        set("coagents", ({
                ([ "startroom" : "/d/kaifeng/hh_houting",
                   "id"        : "zhao banshan" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "�����վס�����Ǻ컨�������ɵ���"
                                "������߶��ط���" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ����ҷ�������" NOR,
        ]));

        create_family("�컨��", 4, "�ĵ���");

        set("inquiry", ([
                "�������"  : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.lei" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/d/wudang/obj/greyrobe")->wear();
    
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < 10000)
        {
                command("say �ߣ�����̩���Ӳ�������֮�ˡ�");
                return;
        }

        if ((int)me->query("combat_exp") < 150000)
        {
                command("say ��Ľ�������̫ǳ�����������㣬����Ҳ������Ϊ��");
                return;
        }

        if ((int)me->query_skill("honghua-xinfa", 1) < 60)
        {
                command("say ���������ڹ��ķ���û���ã���ôϰ�Ҹ�����Ʒ���");
                return;
        }

        command("haha");
        command("say �����������Ժ�͸����Ұɡ�");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/benlei-zhang/lei"))
                return "���а������Ѿ��̸�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("benlei-zhang", 1) < 1)
                return "�������������ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 600)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 20000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����㣬ѧ������һ�С�";

        if (me->query_skill("benlei-zhang", 1) < 120)
                return "������������ƻ����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��Ц��������$N" HIY "˵�������벻��"
                       "����Ʒ���Ȼ���������\n�裬�����Ҵ��������ֺη�"
                       "����˵�գ�$n" HIY "�漴�ڿ����ƣ���\n������ʾ����"
                       "��\n" NOR, me, this_object());

        command("haha");
        command("say �ղ���Щȫ�������Ʒ��ľ��裬��Ҫ���������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ������������\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("benlei-zhang"))
                me->improve_skill("benlei-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/benlei-zhang/lei", 1);
        me->add("gongxian", -600);

        return 1;
}

void unconcious()
{
        die();
}
