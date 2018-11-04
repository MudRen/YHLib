#include <ansi.h>
#include "gumu.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_zhen();

void create()
{
        set_name("��Ī��", ({ "li mochou", "li", "mochou" }));
        set("long", @LONG
�����ü�Ϊ��ò���������Ŀ�����˲���������
LONG);
	set("nickname", HIM "��������" NOR);
        set("gender", "Ů��");
        set("rank_info/respect", "����");
        set("age", 27);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set("shen_type", -1);

        create_family("��Ĺ��", 3, "����");

        set_skill("unarmed", 220);
        set_skill("force", 220);
        set_skill("suxin-jue", 220);        
        set_skill("yunv-xinjing", 220);
        set_skill("dodge", 220);
        set_skill("yunv-shenfa", 220);
        set_skill("qixing-bu", 220);
	set_skill("whip", 240);
        set_skill("yunzhou-fufa", 240);
        set_skill("sanwu-shou", 240);
        set_skill("strike", 220);
        set_skill("chilian-shenzhang", 220);
        set_skill("wudu-shenzhang", 220);
        set_skill("sword", 220);
        set_skill("yunv-jian", 220);  
        set_skill("unarmed", 220);
        set_skill("meinv-quan", 220);
        set_skill("throwing", 240);
        set_skill("bingpo-shenzhen", 240);
        set_skill("literate", 220);
        set_skill("martial-cognize", 220);

        set("jiali", 150);

        map_skill("force", "yunv-xinjing");
        map_skill("strike", "wudu-shenzhang");
        map_skill("whip", "sanwu-shou");
        map_skill("dodge", "qixing-bu");
        map_skill("parry", "wudu-shenzhang");
        map_skill("sword", "yunv-jian");
        map_skill("throwing", "bingpo-shenzhen");
        map_skill("unarmed", "meinv-quan");
        set("combat_exp", 400000);

        set("max_qi", 6900);
        set("max_jing", 1400);
        set("neili", 5000);
        set("max_neili", 5000);

        prepare_skill("strike", "wudu-shenzhang");
        prepare_skill("unarmed", "meinv-quan");

        set("bingpo-zhen", 3);

        set("inquiry", ([
                "С��Ů"     : "�����ҵ�ʦ�á����������ʲô��",
                "�ֳ�Ӣ"     : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",
                "��������"   : (: ask_zhen :),
        ]));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.huan" :),
                (: perform_action, "strike.shi" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();
        carry_object("/d/quanzhou/obj/fuchen");
        carry_object("/d/wudang/obj/greenrobe")->wear();

}

int do_look(string target)
{
        object me;
 
        me = this_player();

        if (! id(target))
                return notify_fail("��Ҫ��ʲô��");

        if ((string)me->query("gender") != "Ů��")
        {
	        message_vision(HIR "��Ī���ŭ���ȵ��������������"
                               "Щ����ĳ����ˣ�ȥ���ɣ�\n" NOR, me);
                kill_ob(this_player());
        }
        return 1;
}

void attempt_apprentice(object ob)
{
        object me = this_player();

        if (! permit_recruit(ob) )
                return;

        if ((int)me->query("shen") > -70000)
        {
                command("heng");
                command("say ����Ī��ɲ����Ĵ����������ͽ�ܡ�");
                return;
        }

        if ((int)me->query("combat_exp") < 400000)
        {
                command("heng");
                command("say ������������ܼ̳��ҵ��²���");
                return;
        }
        if ((int)me->query_skill("force") < 160)
        {
                command("say Ҫѧ���嶾���ƣ����Ƚ��ڹ�����ʵ��");
                return;
        }

        if ((int)me->query_skill("strike", 1) < 120)
        {
                command("say Ҫѧ�ҵ��嶾���ƣ���Ҫ��տ���Ʒ���������"
                        "�ҿ������������µĹ��򻹲�������");
                return;
        }

        command("nod");
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
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

        case "��ħ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yunzhou-fufa/feng",
                           "name"    : "��ħ��",
                           "sk1"     : "yunzhou-fufa",
                           "lv1"     : 50,
                           "gongxian": 50,
                           "shen"    : -75000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/bingpo-shenzhen/bing",
                           "name"    : "������",
                           "sk1"     : "bingpo-shenzhen",
                           "lv1"     : 110,
                           "force"   : 140,
                           "gongxian": 400,
                           "shen"    : -80000, ]));
                break;

        case "������Ϊ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sanwu-shou/wei",
                           "name"    : "������Ϊ",
                           "sk1"     : "sanwu-shou",
                           "lv1"     : 60,
                           "gongxian": 300,
                           "shen"    : -80000, ]));
                break;

        case "����������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/chilian-shenzhang/lian",
                           "name"    : "����������",
                           "sk1"     : "chilian-shenzhang",
                           "lv1"     : 110,
                           "force"   : 140,
                           "gongxian": 400,
                           "shen"    : -85000, ]));
                break;

        case "ǧ�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/wudu-shenzhang/huan",
                           "name"    : "ǧ�����",
                           "sk1"     : "wudu-shenzhang",
                           "lv1"     : 90,
                           "dodge"   : 140,
                           "gongxian": 500,
                           "shen"    : -90000, ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sanwu-shou/zhi",
                           "name"    : "��������",
                           "sk1"     : "sanwu-shou",
                           "lv1"     : 90,
                           "dodge"   : 100,
                           "gongxian": 400,
                           "shen"    : -95000, ]));
                break;

        case "�޿ײ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sanwu-shou/kong",
                           "name"    : "�޿ײ���",
                           "sk1"     : "sanwu-shou",
                           "lv1"     : 120,
                           "force"   : 160,
                           "gongxian": 600,
                           "shen"    : -110000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/wudu-shenzhang/shi",
                           "name"    : "������",
                           "sk1"     : "wudu-shenzhang",
                           "lv1"     : 140,
                           "force"   : 180,
                           "gongxian": 800,
                           "shen"    : -120000, ]));
                break;
        default:
                return 0;
        }
}

string ask_zhen()
{
        object me;
        object ob;
        mapping fam;

        me = this_player();

        if (me->query("family/master_name") != "��Ī��")
                return RANK_D->query_respect(me) + "���Һ��޹ϸ𣬺�����"
                "���ҵİ�����\n";

        if (me->query_skill("bingpo-zhen", 1) < 100)
                return RANK_D->query_respect(me) + "�ı��������ַ���򻹲�����"
                "�����˱�������Ҳû��ʲô�á�\n";

        if (query("bingpo-zhen") < 1)
                return "�������ˣ�����ͷ�ı��������Ѿ������ˡ�\n";

        add("bingpo-zhen", -1);
        
        message_vision(HIY "$N�ó�һ��" HIW "��������" HIY "�ݸ�$n��\n" NOR, this_object(), me);

        ob = new("/d/gumu/obj/bingpo-zhen");
        ob->move(me, 1);

        return "�ðɣ������������������ȥ�ðɡ�\n";
}

void reset()
{
        set("bingpo-zhen", 4 + random(2));
}
