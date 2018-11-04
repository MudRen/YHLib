#include <ansi.h>
inherit NPC;

mixed teach_hunting();

void create()
{
        set_name("����", ({"hunter"}));
        set("gender", "����" );
        set("class", "swordman");
        set("age", 45);
        set("str", 200);
        set("con", 26);
        set("int", 28);
        set("dex", 200);
        set("combat_exp", 12000000);
        set("attitude", "peaceful");

	set_skill("unarmed", 300);
	set_skill("dodge", 300);

        set("max_qi", 4500);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 150);

	set("inquiry", ([
		"hunting" : ( :teach_hunting: ),
		"����"    : ( :teach_hunting: ),
	]));
	
	setup();
	carry_object("/clone/cloth/cloth")->wear();

 }

int accept_object(object me, object ob)
{ 
        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0; 
        if ( !present(ob, me) ) return notify_fail("��û�����������");
        if ( (string)ob->query("id") == "bushou jia") 
        {
		command("nod");
		command("say ��������õ��ţ���������Ϊ���������Ը�⣬��\n����"
			"����һЩ���Եļ��ɡ�");
 		me->set_temp("marks/hunter", 1);
		return 1;
        }
        else 
        {
                 command("shake");
                 command("say ����ʲô�������Ҳ���Ҫ��");                
        }   

   	return 1;
}



mixed teach_hunting()
{
	object me = this_player();
	int jing, add;
	
	jing = me->query("jing");
	add = me->query_int() + random(me->query_int() / 2 );

	if (! me->query_temp("marks/hunter"))
		return "���������������γ����ԣ�\n";

	if (me->is_busy() || me->is_fighting())
	{
		write("��������æ�š�\n");
		return 1;
	}
	
	if (jing < 20)
	{
		write("��ľ����޷����С�\n");
		return 1;
	}

	if ((me->query("potential") - me->query("learned_points")) < 1)
	{
		write("���Ǳ�ܲ������޷�����ѧϰ��\n");
		return 1;
	}
	write(HIW "���˸��㽲�����йز��Ե�һЩ���ɡ�\n" NOR);
	write(HIY "���������˵�ָ�����ƺ������ĵá�\n" NOR);

	me->add("learned_points", 1);

	me->improve_skill("hunting", add);

	me->add("jing", -(5 + random(6)));

	return 1;
		
}


