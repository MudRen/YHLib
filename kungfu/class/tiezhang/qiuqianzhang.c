#include <ansi.h>
#include "tiezhang.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��ǧ��", ({ "qiu qianzhang", "qiu", "qianzhang", "zhang" }));
        set("long", "����һ��������ͷ�����Ƹ�������㴩��Ь����\n"
                    "�ֻ���һ�Ѵ����ȡ��������ͻ������ı��顣\n");

        set("gender", "����");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 23);
        set("int", 30);
        set("con", 26);
        set("dex", 25);
        set("env/wimpy", 70);
       
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 100000);
        set("score", 40000);

        set_skill("force", 100);
        set_skill("tiezhang-xinfa", 100);
        set_skill("dodge", 120);
        set_skill("lingxu-bu", 120);
        set_skill("strike", 120);
        set_skill("parry", 120);
        set_skill("tongbi-zhang", 120);
        set_skill("tie-zhang", 120);
        set_skill("chuanxin-zhang", 120);
        set_skill("feilong-zhang", 120);
        set_skill("guyue-chan", 120);
        set_skill("staff", 100);
        set_skill("literate", 80);
        set_skill("martial-cognize", 80);

        map_skill("force", "tiezhang-xinfa");
        map_skill("strike", "tongbi-zhang");
        map_skill("parry", "tongbi-zhang");
        map_skill("dodge", "lingxu-bu");
        map_skill("staff", "feilong-zhang");

        prepare_skill("strike", "tongbi-zhang");

        set("no_teach", ([
                "tie-zhang" : "�ٺٺ٣������ⲻ�������ҵ�ͨ�������Ʋ������־�"
                              "ѧ���㻹������������ɡ�",
        ]));

        create_family("���ư�", 15, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "cuff.jia" :),
                (: perform_action, "staff.fei" :),
                (: exert_function, "recover" :),
        }) );

        
        set("inquiry", ([
                "name" : "�ǵ��ȸ����������һ����������ô��ǧ�ɡ��������Ų�������Ҳ���ѵ�������\n",
                "here" : "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������\n",
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
        add_money("silver", 100);

        set("chat_chance", 10);
        set("chat_msg", ({
                CYN "��ǧ�ɴ�����ֵ�˵���������ư��������µ����飬û��үү��"
                "֪���ģ���\n" NOR,
                CYN "��ǧ�����ص�˵������һ���ڹ������гɣ��Ϳ��Դӻ�����ľ"
                "�в���������ˣ���\n" NOR,
        }) );
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ( me->query("family/family_name") &&
             me->query("family/family_name") == "�����" &&
             me->query("family/master_name") == "��ǧ��" )
        {
                command("yi");
                command("say �ҵ���˭��ԭ�������õĵ��ӣ����Ǳ�������һ���ˡ�");
                command("sigh");
                command("say ��������������������㻹��ȥ�Ҷ��ܰɡ�");
                me->set("move_party/����ȡ����ư�", 1);
                return;
        }

        if ((int)me->query("shen") > 0)
        {
                command("heng");
                command("say ����ģ�үү������������Ĵ������С���˵�����");
                return;
        }

        command("say үү���书�������������޺úø�����ѧ��׼û��");
        command("recruit " + me->query("id"));
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "���ǻ����ˣ�����������үү��ѵ��ѵ�㣡\n");
        command("say ��Ӵ����⣬��⣬�������治���ɣ����һ�ᣬ�Ҷ���ʹ��Ҫ������\n");
        return 0;
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "�����Ⱥ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tongbi-zhang/chu",
                           "name"    : "�����Ⱥ",
                           "sk1"     : "tongbi-zhang",
                           "lv1"     : 80,
                           "force"   : 40,
                           "gongxian": 60,
                           "shen"    : -5000, ]));
                break;

        case "��¾���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/guyue-chan/jing",
                           "name"    : "��¾���",
                           "sk1"     : "guyue-chan",
                           "lv1"     : 80,
                           "force"   : 40,
                           "gongxian": 80,
                           "shen"    : -8000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/feilong-zhang/fei",
                           "name"    : "������",
                           "sk1"     : "feilong-zhang",
                           "lv1"     : 160,
                           "force"   : 240,
                           "neili"   : 2500,
                           "gongxian": 400,
                           "shen"    : -20000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}
