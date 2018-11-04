// qianzhenglun.c Ǯ����

#include <ansi.h>

inherit NPC;

int total = random(15);
mapping count = ([]);

void create()
{
	set_name("Ǯ����", ({ "qian zhenglun","qian", "zhenglun"}));
  	set("long", "��Զ�ھֵ���ʦ�����������ڿҿҵĴ�������\n"
                    "�ֵ�����������Թ�����Ĺ����������޽���\n"
                    "΢���׷���Ƥ����ڣ���Ŀ��࣬���ֱ۳���\n"
                    "˫������\n");
	set("title", "��Զ�ھ���ʦ");
  	set("gender", "����");
  	set("age", 45);
	set("shen_type", 1);
	set("class", "fighter");
        set("attitude", "peaceful");

  	set("str", 40);
  	set("int", 30);
	set("dex", 30);
	set("con", 35);
	set("per", 19);

	set("qi", 600);
	set("max_qi", 600);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 75);

  	set("combat_exp", 200000);
	set("score", 50000);

  	set_skill("literate", 40);
  	set_skill("parry", 60);
  	set_skill("force", 60);
  	set_skill("dodge", 60);
  	set_skill("bagua-bu", 40);
  	set_skill("bagua-dao", 40);
	set_skill("nei-bagua", 30);
  	set_skill("blade", 60);

	map_skill("parry","bagua-dao");
	map_skill("blade","bagua-dao");
	map_skill("dodge","bagua-bu");
	map_skill("force","nei-bagua");

  	setup();

  	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
  	add_action("do_yao", "yao");
}

int do_yao(string arg)
{
  	object me = this_player(),
        npc = this_object(), obj;

     	if (! arg)
	{
		tell_object(me, CYN "Ǯ���׵�����Ҫʲô������\n" NOR);
		return 1;
	}

  	if ((string)me->query("family/family_name") != "������")
    		return notify_fail(CYN "Ǯ���׵����Բ���ֻ���ھ���"
                                   "���˲�����ȡ������\n" NOR);

	if (arg != "blade" && arg != "sword" && arg != "dagger"
           && arg != "hammer" && arg != "staff" && arg != "throwing"
           && arg != "whip" && arg != "body" && arg != "helmet"
           && arg != "feet"&& arg != "waist")
     		return notify_fail(CYN "Ǯ���׶���ҡͷ�����Բ�����Ҫ��"
                                   "����������û�С�\n" NOR);

    	if (count[arg] >= total)
   		return notify_fail(CYN "Ǯ���׵����Բ�����Ҫ�Ķ����Ҷ�"
                                   "�Ѿ������ˡ�\n" NOR); 

    	if (arg == "body" || arg == "helmet"
           || arg == "feet" || arg == "waist")
    	{
   		if (me->query_temp("mark/zhenyuan_armor") >= 3)
       			return notify_fail(CYN "Ǯ����ŭ�������Ҫ����ô"
                                           "������ף���������\n" NOR);

   		me->add_temp("mark/zhenyuan_armor", 1);
    	} else
    	{
   		if (me->query_temp("mark/zhenyuan_weapon") >= 3)
       			return notify_fail(CYN "Ǯ����ŭ�������Ҫ����ô"
                                           "�����������������\n" NOR);

   		me->add_temp("mark/zhenyuan_weapon", 1);
    	}

    	count[arg] += 1;
    	obj = new(__DIR__"obj/" + arg);
        obj->set("no_sell", "�ⲻ����Զ�ھ���Ķ���ô���ҿɲ����չ���");
        obj->set("value", 50);
    	command("say ��λ" + RANK_D->query_respect(me) + "��" + 
                obj->query("name") + "Ϊ�����࣬ǧ�������ӡ�");
    	message_vision(HIC "Ǯ���׸���$N" HIC "һ" + obj->query("unit")
                       + obj->query("name")+ HIC "��\n" NOR, me);
    	obj->move(me);
    	return 1;
}