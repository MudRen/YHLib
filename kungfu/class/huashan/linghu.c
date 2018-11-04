// linghu.c �����

#include <ansi.h>
#include <qizong.h>

inherit NPC;
inherit F_MASTER;

mixed ask_me();
mixed learn_chongling();

void create()
{
	set_name("�����", ({ "linghu chong", "linghu", "chong" }));
	set("nickname", "��ʦ��");
	set("long", "����Ľ��ݣ�����Ũü���ۣ������Ѱ�����ͬ���������ϴ�\n"
                    "�ǻ�ɽ������һ���еĶ�����֡�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 4800);
	set("max_qi", 4800);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 5700);
	set("max_neili", 5700);
	set("jiali", 60);

	set("combat_exp", 2200000);
	set("score", 150000);

	set_skill("blade", 200);
	set_skill("cuff", 200);
	set_skill("feiyan-huixiang", 200);
	set_skill("strike", 200);
	set_skill("huashan-zhang",200);
	set_skill("unarmed",200);
	set_skill("huashan-quan",120);
	set_skill("force", 200);
	set_skill("yijinjing", 200);
	set_skill("dodge", 200);
	set_skill("parry", 220);
	set_skill("sword", 240);
	set_skill("huashan-jian", 240);
        set_skill("chongling-jian", 240);
	set_skill("dugu-jiujian", 240);
	set_skill("literate", 140);
        set_skill("tanqin-jifa", 240);
        set_skill("xiaoao-jianghu", 240);
        set_skill("qingxin-pushan", 240);

	map_skill("force", "yijinjing");
	map_skill("unarmed", "huashan-quanfa");
	map_skill("strike", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-jian");
	map_skill("sword", "dugu-jiujian");
        map_skill("tanqin-jifa", "xiaoao-jianghu");

	create_family("��ɽ��", 14, "����");

	set("inquiry", ([
		"������" : "�����Ѿ��ܾ�û�м��������˼��ˡ���������",
		"��ӯӯ" : "��Ҫ��ʲô�������鷳��",
                "����������" : "�����ӨӨ�����ҵ�...",
                "Ц������"   : "���������Ϻ�������ʦ����������...����",
		"����"       : (: ask_me :),
                "���齣��"   : (: learn_chongling :),
     	]));

	set("no_teach", ([
		"yijinjing"    : "���������ش����ɷ�����ʦ���ڣ��Ҳ������Խ��㡣",
		"dugu-jiujian" : "�����������ҾŽ���ʱ�����������Բ���˽"
				 "�Դ��ڣ��㻹��ѧϰ�����书�ɣ�",
	]));

	set("music_book", 1);
	setup();	 	
	carry_object("/d/heimuya/npc/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/heimuya/npc/obj/card2");
}

int recognize_apprentice(object me, string skill)
{
        if (skill != "tanqin-jifa" &&
            skill != "xiaoao-jianghu" &&
            skill != "qingxin-pushan")
        {
                command("say �Բ���...�Ҳ��ܴ�������Щ����Ҫ����ѧ����ټ�������ࡣ");
                return -1;
        }

        if (me->query_temp("can_learn/linghu/" + skill))
                return 1;

        me->set_temp("can_learn/linghu/" + skill, 1);
        command("say �ðɣ����Ȼ��" + to_chinese(skill) +
                "����Ȥ���Ҿͽ���һ�㡣");

        return 1;
}

void attempt_apprentice(object ob)
{

        command("say ��һ����ϲ����ң���ڣ����뻪ɽ�ɻ�������ʦ���ɣ�");
        return ;
}

mixed ask_me()
{
	object me;
	object ob;

	me = this_player();
	if (query("music_book") < 1)
		return "�ҵ������Ѿ����ȥ�ˡ�\n";

	ob = new("/clone/book/qin");
	ob->move(me, 1);
	message_vision("$n�����׸���$N����������ȥ�ú�ѧϰ�ɡ�\n",
		       me, this_object());
	set("music_book", 0);
	return 1;
}

void reset()
{
	set("music_book", 1);
}

void unconcious()
{
        die();
}

mixed learn_chongling()
{
        object me = this_player();
        int lv = me->query_skill("huashan-jian", 1);

        if (me->query_skill("chongling-jian"))
               return "�㲻���Ѿ�������\n";

        if (me->query("family/family_name") != "��ɽ��")
               return "��˵ʲô���Ҳ����ף�\n";
 
        if (lv < 100)
               return "�㻪ɽ������Ϊ�������һ����ܴ������У�\n";

        message_vision(HIW "$N" HIW "˵���������׽������Һ�Сʦ��������ʱ��ͻ������"
                       "�������ģ����Ǵӻ�ɽ�������ݻ���������ɿ����ˣ���˵�꽫����"
                       "�齣������ͷ��β�ظ�$n" HIW "��ʾ��һ�飡\n" NOR,
                       this_object(), me);        
        
        command("haha");
        tell_object(me, HIG "��ѧ���ˡ����齣������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("huashan-jian"))
                me->improve_skill("huashan-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);

        command("say ����˶��پͿ��㻪ɽ��������Ϊ�ˣ�ʣ�µľͿ����Լ���ȥ��ϰ��");

        me->set_skill("chongling-jian", lv / 10);
        
        return 1;       
}