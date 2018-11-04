#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���", ({ "fei yan", "fei", "yan" }));
	set("nickname", HIM "��������" NOR);
        set("title", "�ϰ���");
	set("long", @LONG
���ԭ������¥������Ϊ������Ϊ�������Σ���ɱ����
ү�Ĺ��ӣ��ձ�������������˵�����������ȣ��Ӵ���
�����������������������������е�˵��������Ǻ���
����������������һ���������������������˶�����Ϊ
���������ɡ���
LONG);
        set("shen_type", 1);
        set("gender", "Ů��");
        set("age", 25);
	set("per", 28);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_temp("apply/damage", 25);
        set("combat_exp", 800000);
	set("no_get", "1");
        set("attitude", "friendly");
        set("vendor_goods", ({
		"/d/henshan/yueqi/shixuanqin-zhanguo",
		"/d/henshan/yueqi/jiuxiaoqin",
		"/d/henshan/yueqi/zhongnishi",
		"/d/henshan/yueqi/jiaoyeqin",
		"/d/henshan/yueqi/qin-jueyin",
		"/d/henshan/yueqi/qin-konggu",
		"/d/henshan/yueqi/qin-jimo",
		"/d/henshan/yueqi/qin-tianlai",
		"/d/henshan/yueqi/huqin",
		"/d/henshan/yueqi/zhuxiao",
		"/d/henshan/yueqi/honghuqin",
		"/d/henshan/yueqi/zhuxiao-youlan",
		"/d/henshan/yueqi/zhuxiao-shuiyun",
		"/d/henshan/yueqi/zhuxiao-liuquan",
		"/d/henshan/yueqi/zhuxiao-qingyin",	
		"/d/henshan/yueqi/yuepu-book",
		"/d/henshan/yueqi/yueqi-book",
		"/d/henshan/yueqi/huxian-book",
        }));
        
	set("inquiry", ([
		 "�ŷ��" : "�Ź��ӣ���������\n",
	]));

        setup();
        carry_object("/d/henshan/npc/obj/female-shoe")->wear();
	carry_object("/d/henshan/npc/obj/female1")->wear();

}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	if (interactive(ob) && ! is_fighting()) 
	{
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment()) return;

	say(CYN "���Ц��˵������λ" + RANK_D->query_respect(ob)+ "����"
	    "��������Ӧ�о��У�����㿴����\n" NOR);

	return;
}
