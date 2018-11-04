#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("���ĸ�", ({ "jiang sigen", "jiang", "sigen" }));
        set("title", "�컨��ʮ������");
        set("nickname", YEL "ͭͷ����" NOR);
        set("long", "ͭͷ���㽯�ĸ��ڻ�������ʮ���ѽ��Σ�����\n"
                    "��������\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 2500);
        set("max_jing", 2500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 10000);

        set_skill("force", 100);
        set_skill("honghua-xinfa", 100);
        set_skill("unarmed", 100);
        set_skill("changquan", 100);
        set_skill("dodge", 100);
        set_skill("yanzi-chuanyun", 100);
        set_skill("staff", 120);
        set_skill("fengmo-zhang", 120);
        set_skill("parry", 100);
        set_skill("martial-cognize", 60);
        set_skill("literate", 100);

        map_skill("force"  , "honghua-xinfa");
        map_skill("staff"  , "fengmo-zhang");
        map_skill("unarmed" , "changquan");
        map_skill("dodge"  , "yanzi-chuanyun");
        map_skill("parry"  , "fengmo-zhang");

        prepare_skill("unarmed", "changquan");

        set("coagents", ({
                ([ "startroom" : "/d/kaifeng/hh_woshi",
                   "id"        : "chen jialuo" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "�����վס�����Ǻ컨�������ɵ���"
                                "������߶��ط���" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ����ҷ�������" NOR,
        ]));

        create_family("�컨��", 4, "������");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "staff.lun" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/kaifeng/npc/obj/tiejiang")->wield();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < -1000)
        {
                command("say �Һ컨�᲻�ղ���֮�ˣ��㻹���߰ɡ�");
                return;
        }

        command("nod");
        command("say �š����Ҿ�������ɡ�");
        command("recruit " + me->query("id"));
}

void hit_ob(object ob)
{
        object me = this_object();
        object where = environment (me);
        object guard1 = present ("yang chengxie", where);
        object guard2 = present ("honghua dizi", where);
        object guard3 = present ("honghua dizi 2", where);
        object guard4 = present ("honghua dizi 3", where);
        object guard5 = present ("honghua dizi 4", where);

        set_temp("my_killer", ob);
        ::kill_ob(ob);

        if (guard1 && ! guard1->is_fighting())
        {
                message_vision (HIW "\n���Э��ŭ���ȵ�����Ȼ�۵����Ǻ컨��"
                                "ͷ�����ˣ���Ҳ������ϣ�\n\n" NOR, guard1);
                guard1->kill_ob(ob);
        }

        if (guard2 && ! guard2->is_fighting())
                guard2->kill_ob(ob);

        if (guard3 && ! guard3->is_fighting())
                guard3->kill_ob(ob);

        if (guard4 && ! guard4->is_fighting())
                guard4->kill_ob(ob);

        if (guard5 && ! guard5->is_fighting())
                guard5->kill_ob(ob);
}

void kill_ob(object ob)
{
        object me = this_object();
        object where = environment (me);
        object guard1 = present ("yang chengxie", where);
        object guard2 = present ("honghua dizi", where);
        object guard3 = present ("honghua dizi 2", where);
        object guard4 = present ("honghua dizi 3", where);
        object guard5 = present ("honghua dizi 4", where);

        set_temp("my_killer", ob);
        ::kill_ob(ob);

        if (guard1 && ! guard1->is_fighting())
        {
                message_vision (HIW "\n���Э��ŭ���ȵ�����Ȼ�۵����Ǻ컨��"
                                "ͷ�����ˣ���Ҳ������ϣ�\n\n" NOR, guard1);
                guard1->kill_ob(ob);
        }

        if (guard2 && ! guard2->is_fighting())
                guard2->kill_ob(ob);

        if (guard3 && ! guard3->is_fighting())
                guard3->kill_ob(ob);

        if (guard4 && ! guard4->is_fighting())
                guard4->kill_ob(ob);

        if (guard5 && ! guard5->is_fighting())
                guard5->kill_ob(ob);
}