// murongbo.c Ľ�ݲ�

#include <ansi.h>
#include "murong.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

mixed try_learn_sk();
int try_learn_chz();

#define HUPO "/clone/lonely/hupohuan"

void create()
{
	set_name("Ľ�ݲ�", ({ "murong bo", "murong", "bo" }));
	set("long", @LONG
���ǹ���Ľ�ݵĴ��ˣ�����˵����Ľ�����������书��Ϊ�ܳ�
֮�ˡ������ܹ�ͨ���°ټ�֮����������Ϊ��ͨĽ�ݼҾ�����
LONG );
	set("nickname", HIM "�Ա�֮�� ��ʩ����" NOR);
	set("gender", "����");
	set("age", 54);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 31);
	set("int", 37);
	set("con", 34);
	set("dex", 33);

	set("qi", 5700);
	set("max_qi", 5700);
	set("jing", 2800);
	set("max_jing", 2800);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 145);

	set("combat_exp", 2650000);

	// base skill
	set_skill("force", 280);
	set_skill("literate", 220);
	set_skill("unarmed", 260);
	set_skill("cuff", 280);
    set_skill("finger", 280);
	set_skill("strike", 260);
	set_skill("hand", 260);
	set_skill("claw", 260);
	set_skill("club", 260);
	set_skill("sword", 280);
	set_skill("blade", 260);
	set_skill("staff", 260);
	set_skill("dodge", 260);
	set_skill("parry", 300);

	// shaolin skill. No teach
	set_skill("banruo-zhang", 240);
	set_skill("cibei-dao", 240);
	set_skill("damo-jian", 240);
	set_skill("fengyun-shou", 240);
	set_skill("fumo-jian", 240);
	set_skill("hunyuan-yiqi", 240);
	set_skill("shaolin-xinfa", 240);
	set_skill("jingang-quan", 240);
	set_skill("longzhua-gong", 240);
	set_skill("luohan-quan", 240);
	set_skill("nianhua-zhi", 240);
	set_skill("pudu-zhang", 240);
	set_skill("qianye-shou", 240);
	set_skill("sanhua-zhang", 240);
	set_skill("riyue-bian", 240);
	set_skill("shaolin-shenfa", 240);
	set_skill("weituo-gun", 240);
	set_skill("wuchang-zhang", 240);
	set_skill("xiuluo-dao", 240);
	set_skill("yingzhua-gong", 240);
	set_skill("yizhi-chan", 240);
	set_skill("zui-gun", 240);

        // other skill
    set_skill("wudang-jian", 240);
	set_skill("xunlei-jian", 240);
	set_skill("quanzhen-jian", 260);
	set_skill("jidian-jian", 260);
	set_skill("hanmei-jian", 260);
	set_skill("baxian-jian", 260);
	set_skill("emei-jian", 260);
	set_skill("kunlun-jian", 260);
	set_skill("songfeng-jian", 260);
	set_skill("huashan-sword", 260);
	set_skill("yunhe-jian", 260);


	// murong skill
	set_skill("zihui-xinfa", 280);
	set_skill("murong-xinfa", 280);
	set_skill("douzhuan-xingyi", 300);
	set_skill("beidou-xianzong", 280);
	set_skill("canhe-zhi", 280);
	set_skill("qixing-quan", 280);
	set_skill("murong-jian", 280);
    set_skill("longcheng-shendao", 260);
    set_skill("martial-cognize", 220);

	map_skill("force", "zihui-xinfa");
	map_skill("dodge", "beidou-xianzong");
	map_skill("cuff",  "qixing-quan");
	map_skill("parry", "douzhuan-xingyi");
    map_skill("finger", "canhe-zhi");
	map_skill("sword", "murong-jian");
	map_skill("blade", "longcheng-shendao");

    prepare_skill("finger", "canhe-zhi");
    prepare_skill("cuff", "qixing-quan");

	set("no_teach", ([
		"banruo-zhang"  : (: try_learn_sk :),
		"cibei-dao"     : (: try_learn_sk :),
		"damo-jian"     : (: try_learn_sk :),
		"fengyun-shou"  : (: try_learn_sk :),
		"fumo-jian"     : (: try_learn_sk :),
		"hunyuan-yiqi"  : (: try_learn_sk :),
		"shaolin-xinfa" : (: try_learn_sk :),
		"jingang-quan"  : (: try_learn_sk :),
		"longzhua-gong" : (: try_learn_sk :),
		"luohan-quan"   : (: try_learn_sk :),
		"nianhua-zhi"   : (: try_learn_sk :),
		"pudu-zhang"    : (: try_learn_sk :),
		"qianye-shou"   : (: try_learn_sk :),
		"sanhua-zhang"  : (: try_learn_sk :),
		"riyue-bian"    : (: try_learn_sk :),
		"shaolin-shenfa": (: try_learn_sk :),
		"weituo-gun"    : (: try_learn_sk :),
		"wuchang-zhang" : (: try_learn_sk :),
		"xiuluo-dao"    : (: try_learn_sk :),
		"yingzhua-gong" : (: try_learn_sk :),
		"yizhi-chan"    : (: try_learn_sk :),
		"zui-gun"       : (: try_learn_sk :),
                "canhe-zhi"     : (: try_learn_chz :),
	]));

	create_family("Ľ������", 15, "ׯ��");
	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "finger.canhe" :),
		(: perform_action, "parry.yi" :),                
		(: perform_action, "finger.lian" :),
		(: perform_action, "finger.zhi" :),
	}));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 120);
        set_temp("apply/armor", 200);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 100);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -36000)
        {
                command("say ��Ľ�ݲ���������������Щ��ν������ʿ������");
                command("say �㻹����ذɣ�");
                return;
        }
        if ((int)ob->query("combat_exp") < 500000)
        {
                command("say �����ھ�����ǳ�����Ƕ��ڽ��������߰ɡ�");
                return;
        }
        if ((int)ob->query_skill("douzhuan-xingyi", 1) < 130)
        {       
                command("say ��ת��������Ľ�����Ҿ������㲻�ú���ϰ����������������");
                return;
        }
        if ((int)ob->query_skill("murong-xinfa", 1) < 120)
        {       
                command("say ��Ľ�������书���������һ�������ӻ����ķ���");
                command("say ���Ľ���ķ���������������ȥ���������ɡ�");
                return;
        }
        if ((int)ob->query_skill("dodge") < 200)
        {
                command("say ��Ľ�������书��������ɵ�����");
                command("say ���Ƿ�Ӧ�����Ṧ��Ϊ�϶��µ㹦��");
                return;
        } 
       
        command("haha");
        command("pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        message_vision("Ľ�ݲ���ϲ������Ľ�ݼ�����Ӣ�ŵ�����������������\n",
                       this_object());
}

mixed try_learn_sk()
{
	object me;

	me = this_player();
	if (me->query_temp("has_asked/murongbo"))
		return "�㻹�ǰ���ѧ���Ź���ɡ�";

	command("shake");
	command("say ��˵���ֵ��书ѧ�˶������к�����Ͳ�Ҫѧ�ˡ�");
	me->set_temp("has_asked/murongbo", 1);
	return -1;
}
// ������120��������20���󷽿�ѧϰ��
int try_learn_chz()
{
       object me = this_player();

       if (me->query("shen") > 0)
       {
                command("heng");
                command("��������������Щ��ν������ʿ���㻹����ذɣ�");
                return -1;
       }
       if (me->query("born_family") != "Ľ������")
       {
                command("sneer");
                command("say �㲻������Ľ�ݼҵ��ˣ�����������ָ�㡣");
                command("say ���»�����ذɣ�");
                return -1;
       }
       if (me->query("family/master_id") != this_object()->query("id"))
       {
            command("shake");
	        command("say �������Һ��޹ϸ�����������ָ�㣿");
        	return -1;
       }
       if (me->query_skill("canhe-zhi", 1) < 150)
       {
	        command("shake");
	        command("say ��κ�ָ��򻹲�����������ȥ�����ϰ��");
	        return -1;
       }                         

       return 0;
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

        case "��ת����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/douzhuan-xingyi/yi",
                           "name"    : "��ת����",
                           "sk1"     : "douzhuan-xingyi",
                           "lv1"     : 160,
                           "sk2"     : "zihui-xinfa",
                           "lv2"     : 180,
                           "force"   : 160,
                           "gongxian": 900,
                           "shen"    : -60000, ]));
                break;

        case "����ָѨ" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/canhe-zhi/zhi",
                           "name"    : "����ָѨ",
                           "sk1"     : "canhe-zhi",
                           "lv1"     : 140,
                           "dodge"   : 140,
                           "force"   : 140,
                           "gongxian": 600,
                           "shen"    : -75000, ]));
                break;

        case "��ڤ����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/canhe-zhi/you",
                           "name"    : "��ڤ����",
                           "sk1"     : "canhe-zhi",
                           "lv1"     : 140,
                           "force"   : 150,
                           "gongxian": 800,
                           "shen"    : -80000, ]));
                break;

        case "��ս���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/canhe-zhi/jin",
                           "name"    : "��ս���",
                           "sk1"     : "canhe-zhi",
                           "lv1"     : 160,
                           "force"   : 160,
                           "gongxian": 1000,
                           "shen"    : -95000, ]));
                break;

        case "�κϽ���" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/canhe-zhi/canhe",
                           "name"    : "�κϽ���",
                           "sk1"     : "canhe-zhi",
                           "lv1"     : 160,
                           "force"   : 180,
                           "gongxian": 1200,
                           "shen"    : -130000, ]));
                break;

        case "������" :
                return MASTER_D->give_item(me, this_object(),
                        ([ "item"    : HUPO,
                           "master"  : 1,
                           "sk1"     : "zihui-xinfa",
                           "lv1"     : 180,
                           "shen"    : -50000, ]));
                break;

        default:
                return 0;
        }
}

void unconcious()
{
        die();
}

