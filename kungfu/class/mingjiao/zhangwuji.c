//zhangwuji.c
// by rcwiz 2003 for yhonline

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

void create()
{
    
    set_name("���޼�", ({ "zhang wuji", "zhang", "wuji" }));

    set("long", @LONG
���̽������޼ɣ�ͳ������ʮ����ڣ��������ƣ�߳��ǧ�
�������񹦡�����Ǭ����Ų�ơ��������£��ǽ����в�������
����Ӣ�ۡ�
LONG );

    set("title", HIR "���̽���" NOR);
    set("gender", "����");
    set("age", 24);
    set("shen_type", 1);
    set("attitude", "friendly");
    set("class", "fighter");

    set("str", 33);
    set("int", 35);
    set("con", 38);
    set("dex", 33);

    set("qi", 8800);
    set("max_qi", 8800);
    set("jing", 3700);
    set("max_jing", 3700);
    set("neili", 12000);
    set("max_neili", 12000);
    set("jiali", 200);

    set("combat_exp", 5000000);
    set("score", 455000);
    
    set_skill("force", 360);
    set_skill("unarmed", 340);
    set_skill("dodge", 340);
    set_skill("parry", 340);
    set_skill("cuff", 340);
    set_skill("sword", 340);
    set_skill("jiuyang-shengong", 360);
    set_skill("shenghuo-shengong", 360);
    set_skill("shenghuo-xinfa", 360);
    set_skill("qiankun-danuoyi", 360);
    set_skill("shenghuo-bu", 340);
    set_skill("qishang-quan", 340);
    set_skill("taiji-quan", 340);
    set_skill("taiji-jian", 340);
    set_skill("shenghuo-ling", 340);

    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "jiuyang-shengong");
    map_skill("cuff", "qishang-quan");
    map_skill("sword", "shenghuo-ling");
    map_skill("parry", "qiankun-danuoyi");

    create_family("����", 36, "����");

    prepare_skill("cuff", "qishang-quan");

    set("no_teach", ([
	  "jiuyang-shengong"  : "����ҿɲ��ܴ��㡣",
	  "taiji-jian"        : "�㻹������̫ʦ���ɣ�",
	  "taiji-quan"        : "�㻹������̫ʦ���ɣ�",
	  "qishang-quan"      : "��ѧ����ȭ�㻹�������常лѷ�ɣ�",
	  "qiankun-danuoyi"   : "Ǭ����Ų��ֻ�����̽��������������ѵ�������������",
    ]));

    set("chat_chance_combat", 120); 
    set("chat_msg_combat", ({
	(: command("perform sword.hua") :),
	(: command("perform sword.xi") :),
	(: command("perform sword.lian") :),
	(: command("perform sword.can") :),
	(: command("perform cuff.shang") :),
	(: command("perform cuff.fei") :),
	(: command("yun shield") :),
	(: command("yun powerup") :),
	(: command("yun recover") :),
    }) );

    set("inquiry",([
          "����" :     "���������������ʲô����\n",
          "��ëʨ��" : "�������常л������ְ˾��\n",
          "лѷ" :     "���������常�Ĵ�š�\n",
          "�Ŵ�ɽ" :   "�������Ҹ���������? \n",
          "������" :   "����������������΢������\n",
          "������" :   "��̫ʦ�������ɺ�? \n",
          "����" :     "����ʧһ֪��, ����λ�, �������, ����, ��������?\n",
          "С��" :     "С���ҿ�һֱ�������ĺô���\n",
          "������" :   "������ȥ����ɽ, �������ҡ�\n",
    ]));


    set_temp("apply/attack", 180);
    set_temp("apply/damage", 180);
    set_temp("apply/unarmed_damage", 180);
    set_temp("apply/armor", 180);

    setup();
    carry_object("/d/mingjiao/obj/baipao")->wear();
    carry_object("/clone/weapon/gangjian")->wield();

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 90000)
        {
                command("say ����������������û�������������ذɡ�");
                return;
        }
      
        if (ob->query_skill("shenghuo-xinfa", 1) < 180)
        {       
                command("say ��ʥ���ķ�������죬������ȥ����ϰһ�°ɣ�");
                return ;
        }

        if (ob->query_skill("force", 1) < 180)
        {       
                command("say ������ڹ���򲻹�����ôѧ�����̵�ʥ���񹦣�");
                return ;
        }
     
        if (ob->query("combat_exp") < 800000)
        {
                command("say �㽭�����黹��������ȥ��ĥ��һ�°ɣ�");
                return ;
        }

        command("nod");
        command("say �ã��ã������Ҿ�����Ϊ���ӣ���������ʥ���񹦴�������");
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


        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenghuo-ling/xi",
                           "name"    : "������",
                           "sk1"     : "shenghuo-ling",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        case "������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenghuo-ling/lian",
                           "name"    : "������",
                           "sk1"     : "shenghuo-ling",
                           "lv1"     : 160,
                           "neili"   : 2200,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        case "�⻪��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenghuo-ling/hua",
                           "name"    : "�⻪��",
                           "sk1"     : "shenghuo-ling",
                           "lv1"     : 160,
                           "neili"   : 2400,
                           "gongxian": 900,
                           "shen"    : 80000, ]));
                break;

        case "��Ѫ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenghuo-ling/can",
                           "name"    : "��Ѫ��",
                           "sk1"     : "shenghuo-ling",
                           "lv1"     : 220,
                           "neili"   : 5000,
                           "force"   : 350,
                           "gongxian": 1000,
                           "shen"    : 100000, ]));
                break;

        case "����һ��" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/hun",
                           "free"    : 1,
                           "name"    : "����һ��",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 180,
                           "neili"   : 2000,
                           "force"   : 270,
                        ]));
                break;

        case "���ػ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/jiu",
                           "free"    : 1,
                           "name"    : "���ػ���",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 200,
                           "neili"   : 5000,
                           "force"   : 320,
                         ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/po",
                           "free"    : 1,
                           "name"    : "��������",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 220,
                           "sk2"     : "sword",
                           "lv2"     : 240,
                           "sk3"     : "force",
                           "lv3"     : 240,
                           "neili"   : 5500,
                        ]));
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/pi",
                           "free"    : 1,
                           "name"    : "��������",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 220,
                           "sk2"     : "blade",
                           "lv2"     : 240,
                           "sk3"     : "force",
                           "lv3"     : 240,
                           "neili"   : 5500,
                        ]));
                break;

        case "ħ�����޼�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jiuyang-shengong/ri",
                           "free"    : 1,
                           "name"    : "ħ�����޼�",
                           "sk1"     : "jiuyang-shengong",
                           "lv1"     : 260,
                           "neili"   : 8000,
                        ]));
                break;


        default:
                return 0;
        }
}

void unconcious()
{
        die();
}



