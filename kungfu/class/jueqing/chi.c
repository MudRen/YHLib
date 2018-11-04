#include <ansi.h>
#include "jueqing.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
        set_name("��ǧ��", ({ "qiu qianchi", "qiu", "qianchi" }));
        set("nickname", HIG "��������" NOR);
        set("long", @LONG
���������ư�İ�������ˮ��Ư��ǧ������ã�
ֻ����ͷ��ɢ�ң���ɫ���ϣ��������á�
LONG);

        set("gender", "Ů��");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
       
        set("qi", 6000);
        set("max_qi", 6000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 200);
        set("combat_exp", 3000000);

        set_skill("force", 260);
        set_skill("tiezhang-xinfa", 260);
        set_skill("jueqing-xinfa", 260);
        set_skill("tianlei-shengong", 260);
        set_skill("dodge", 260);
        set_skill("jueqing-shenfa", 260);
        set_skill("dengping-dushui", 260);
        set_skill("strike", 260);
        set_skill("strike", 260);
        set_skill("jueqing-zhang", 260);
        set_skill("guhong-zhang", 260);
        set_skill("parry", 260);
        set_skill("tie-zhang", 260);
        set_skill("chuanxin-zhang", 260);
        set_skill("cuff", 260);
        set_skill("tiexian-quan", 260);
        set_skill("sword", 240);
        set_skill("jueqing-jian", 240);
        set_skill("unarmed", 240);
        set_skill("feilong-zhang", 240);
        set_skill("staff", 240);
        set_skill("literate", 160);
        set_skill("martial-cognize", 220);

        map_skill("force", "tianlei-shengong");
        map_skill("unarmed", "chuanxin-zhang");
        map_skill("strike", "tie-zhang");
        map_skill("cuff", "tiexian-quan");
        map_skill("parry", "tie-zhang");
        map_skill("dodge", "dengping-dushui");
        map_skill("staff", "feilong-zhangfa");

        prepare_skill("strike", "tie-zhang");

        create_family("�����", 4, "��������");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.lei" :),
                (: perform_action, "strike.ying" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        setup();

        carry_object("/d/gaibang/npc/obj/cloth")->wear();
}

void attempt_apprentice(object me)
{
        string purename, name, new_name;

        if (! permit_recruit(me))
                return;

        if (me->query("family/master_name") == "����ֹ")
        {
                command("sneer");
                command("say ����ǧ�߿ɲ��չ���ֹ�Ƕ�����ͽ�ܡ�");
                return;
        }

        if ((int)me->query("shen") > -60000)
        {
                command("heng");
                command("say ����ǧ�߿ɲ����Ĵ����������ͽ�ܡ�");
                return;
        }

        if ((int)me->query("combat_exp") < 400000)
        {
                command("heng");
                command("say ������������ܼ̳��ҵ��²���");
                return;
        }

        if ((int)me->query_skill("force") < 140)
        {
                command("say Ҫѧ�ҵ����ƾ������ڹ��Ǿ������ɣ��㻹���ȶ������ɡ�");
                return;
        }

        if ((int)me->query_skill("strike", 1) < 80)
        {
                command("say Ҫѧ�ҵ����ƾ�������Ҫ��տ���Ʒ����������ҿ�������"
                        "�����µĹ��򻹲�������");
                return;
        }

        command("say ��������");
        command("say �Ҿ��������ˣ�ϣ������������񹦣���֮������");
        command("recruit " + me->query("id"));

        if ( me->query("move_party/����ȡ����ư�") &&
             me->query("surname") == "����" )
        {
                name = me->query("name");
                purename = me->query("purename");

                new_name = "��" + purename;

                me->set("surname", "��");
                me->set("name", new_name);
                me->delete("move_party/����ȡ����ư�", 1);

                command("say ����ֹ���ϼһﲻ�Ǹ����������Ժ��Ǹ���������Ϊ�á�");
                command("say �ӽ��Ժ���ͽ���" + new_name + "�ɡ�");
        }
}


int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "�Ƽ���ɽ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tiexian-quan/jia",
                           "name"    : "�Ƽ���ɽ",
                           "sk1"     : "tiexian-quan",
                           "lv1"     : 60,
                           "force"   : 80,
                           "gongxian": 100,
                           "shen"    : -60000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/feilong-zhang/fei",
                           "name"    : "������",
                           "sk1"     : "feilong-zhang",
                           "lv1"     : 150,
                           "force"   : 120,
                           "gongxian": 300,
                           "shen"    : -60000, ]));
                break;

        case "����׶" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/chuanxin-zhang/zhui",
                           "name"    : "����׶",
                           "sk1"     : "chuanxin-zhang",
                           "lv1"     : 80,
                           "force"   : 140,
                           "gongxian": 220,
                           "shen"    : -70000 ]));
                break;

        case "��Ӱ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tie-zhang/ying",
                           "name"    : "��Ӱ��",
                           "sk1"     : "tie-zhang",
                           "msg1"    : "$N���˵�ͷ����$n����������"
                                       "���˼��䣬��Ȼ���������ƣ�"
                                       "˫�Ƽ�����ת����Ӱ����ʵʵ"
                                       "��һ�ƺ���������ĳ�����ʽ"
                                       "���棬ֱ����$nĿ�ɿڴ���",
                           "lv1"     : 100,
                           "force"   : 160,
                           "gongxian": 400,
                           "shen"    : -85000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/tie-zhang/lei",
                           "name"    : "������",
                           "msg1"    : "$NͶ��$n�����һЦ��˵������"
                                       "�����ˣ����漴ֻ��$N�ʹ�����"
                                       "��˫�Ƶ�ʱ��û�죬��$n����"
                                       "֮��˫�ƻ�Ϊһ���Ƶ������ն"
                                       "������ֻ�������꡹һ����һ��"
                                       "��ʯӦ�����飡",
                           "sk1"     : "tie-zhang",
                           "lv1"     : 120,
                           "gongxian": 600,
                           "shen"    : -950000, ]));
                break;


        default:
                return 0;
        }
}

void unconcious()
{
        die();
}

