// ouyangke.c

#include <ansi.h>
#include "ouyang.h"

inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;

void greeting(object ob);
int  accept_object(object who, object ob);
void do_back();
mixed ask_shenshe();

void create()
{
	seteuid(getuid());
	set_name("ŷ����", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "��һ��Ʈ�ݵİ�ɫ��������ҡ���ȣ��������š�\n");
	set("title", "����ɽ��ׯ��");
	set("nickname", HIM "��������" NOR);
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 25);
	set("int", 29);
	set("con", 25);
	set("dex", 26);

	set("qi", 1700);
	set("max_qi", 1700);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 300000);

	set_skill("cuff",  130);
	set_skill("dodge", 120);
	set_skill("parry", 140);
	set_skill("force", 130);
	set_skill("staff", 100);
	set_skill("training", 80);
	set_skill("hamagong",130);
	set_skill("chanchu-bufa", 120);
	set_skill("lingshe-quan", 130);
	set_skill("baibian-daxue", 120);
        set_skill("poison", 120);
        set_skill("finger", 100);
        set_skill("shedu-qiqiao", 120);
	set_skill("medical", 150);
	set_skill("baituo-michuan", 150);
        set_skill("literate", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("cuff",  "lingshe-quan");
	map_skill("parry", "baibian-daxue");
	map_skill("staff", "baibian-daxue");
        map_skill("shedu-qiqiao", "shedu-qiqiao");
        map_skill("finger", "shedu-qiqiao");

        prepare_skill("finger", "shedu-qiqiao");
        prepare_skill("cuff", "lingshe-quan");

        create_family("ŷ������", 6, "����");

	set("chat_chance", 2);
	set("chat_msg", ({
		CYN "ŷ���˰�ֽ��һչ��ת����ȥ��������������֪�����ѵá���\n" NOR,
	}) );

        set("inquiry", ([
                "��·����" : (: ask_shenshe :),
                "����"     : (: ask_shenshe :),
        ]));

        set_temp("shenshe_count", 5);

	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();

	if (interactive(ob = this_player()) && ! is_fighting()) 
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;

        if (check_family(ob, "ŷ������"))
        {
                command("nod " + ob->query("id"));
                return;
        }

	if ((string)ob->query("gender") == "Ů��")
	{
                if (ob->query("per") < 22)
                        return;

                if (ob->query("sex/ŷ����"))
                {
                        command("kiss " + ob->query("id"));
                        command("say ��ô����Ҫ��Ҫ�������Σ�");
                } else
        	switch(random(3))
        	{
        	case 0: command("kiss "+(string)ob->query("id"));break;
        	case 1: command("kiss6 "+(string)ob->query("id"));break;
        	case 2: command("smile "+(string)ob->query("id"));break;
        	}
     
	}
	else
           say(CYN "ŷ����̾��һ����˵����λ" + RANK_D->query_respect(ob) +
               CYN "����Ҫ���ܸ���Ūһ��Ů�����ͺ��ˡ�\n" NOR);
	return;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") == "Ů��" &&
            (string)ob->query("born_family") != "ŷ������")
        {
		message_vision(CYN "ŷ���˶����˵������λ" + RANK_D->query_respect(ob) +
		               CYN "�����ҵĺ���֪������\nϧ�ҹ����ޣ����ܴ����书���㻹"
                               "�����ҵ�С檰ɡ�\n" NOR, ob);
                return;
        }

        if (! permit_recruit(ob))
                return;

        message_vision("$N������... �ܺã�\n", this_object());
	command("recruit " + ob->query("id"));
        if (! ob->query("special/shenshe"))
        {
                command("say �㻹����ʹ����·���߰ɣ��Ҹ�����ھ�����ɲ�Ҫ�����ˣ�");
                command("whisper " + ob->query("id") + " �ھ��ǣ�@#$%^&*����"
                        "������·���ߵ�������ɳĮ�Ϳ��������ߴ���ؼ��ˣ�");
                ob->set("special/shenshe", 1);
        }
}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "Ů��")
	{
		message_vision(CYN "ŷ���˰ڰ���˵������λ" + RANK_D->query_respect(ob) +
		               CYN "���������۸�Ů�����أ�\n" NOR, ob);
		return 0;
        }

        return ::accept_fight(ob);
}
 
int accept_object(object who, object ob)
{
	object obn;
        int addition;

        if (! who || environment(who) != environment()) return 0;
	if (! objectp(ob)) return 0;
	
	if (! present(ob, who))
                return notify_fail("��û�����������\n");

	if (! ob->is_character() || (string)ob->query("gender") != "Ů��")
	{
              	command("say ��ŷ���˲���Ҫ���������");
                return 0;
        }

	if (ob->is_corpse())
	{
		command("slap " + who->query("id"));
		command("say �����㣬��Ȼ�þ�ʬ������Ū�ң��һ�������");
		return 0;
	}

        if ((string)ob->query("born_family") == "ŷ������")
        {
                command("kick " + who->query("id"));
                command("slap " + who->query("id"));
                command("say �ҿ����㵨�ӿ��治С�����ҵİ�����Ҳ���۸���");
                return 1;
        }

	if (environment(this_object())->query("short") == "����Ժ")
	{
               	command("say ���Ѿ���Ů���ˣ�������������ɡ�");
                return 0;
        }

	if ((int)ob->query("age") <18)
	{
                command("fear");
                command("say δ������Ů������Ҫ��");
                return 0;
        }

        if ((int)ob->query("age") > 29)
	{
        	command("say �����ϹŶ������������Լ��ɣ�");
                return 0;
        }

        addition = 0;
        if (userp(ob))
        {
                // 5 + 2 :: because times & first will occupy two item
                if (sizeof(ob->query("sex")) > 4 + 2 )
                {
                        command("say ��������Ů���˾��ɷ���ŷ���˿ɲ���Ҫ��");
                        return 0;
                }

                if (ob->query("per") < 25)
                {
                        command("shrug");
                        command("say �⡭�����ֻ�ɫҲδ����˵㣬��"
				"Ҳ�Ҹ�Ư��Щ�İ���");
                        return 0;
                }

                addition += ob->query("per");
                if ((int) ob->query("sex/times") == 0)
                {
                        command("say �ۣ��⻹�Ǹ���Ů����ôҲ�ö��"
			        "�������ѣ�");
                        addition += 30;
                }
        }

        if (ob->query("sex/ŷ����") >= 3)
        {
                command("shake");
                command("say ��Ů�����Ѿ������ˣ����Ը����Űɡ�");
                return 0;
        }

	obn=new("/clone/money/silver");
        obn->set_amount(20 + addition);
        obn->move(who);

        message_vision(HIC "$n" HIC "��" + ob->name() + HIC "������$N"
                       HIC "��\n\n" NOR, this_object(), who);

        message_vision(HIY "$N" HIY "һ�Ѱ�" + ob->name() + HIY "����"
                       "�����$n" HIY "˵������������������ѣ���"
                       "��ͷ����\n˵�꣬��Я��" + ob->name() + HIY "��"
                       "����Ժ��ȥ��\n" NOR, this_object(), who);

        ob->move("/d/city/lichunyuan");
        move("/d/city/lichunyuan");

        message_vision("$N���Ż��Բ��ѵ�$n���˽�����\n", this_object(), ob);

        ob->add("sex/ŷ����", 1);
        ob->add("sex/times",  1);
        if (ob->query("sex/times") == 1)
                ob->set("sex/first", "ŷ����");

        ob->revive();
        tell_object(ob, HIY "��ո������۾���ȴ����һ����"
		        "�������㣬����һ�����������˹�ȥ��\n\n" NOR);
        command("kiss " + ob->query("id"));
        command("say ���������ʲôô�����" + who->name() + "�����͹����İ���");
        shout(sprintf(HIW "\n%s(%s)���������������������ȡ�����������\n\n" NOR,
                      ob->name() + HIW, ob->query("id")));

        if (! userp(ob))
        {
                ob->set("chat_chance", 15);
                ob->set("chat_msg", ({CYN + ob->name() + CYN "��ס�ĳ�����\n" NOR,
                                      CYN + ob->name() + CYN "���ʵ���" + this_object()->name() +
                                      CYN "�����������������������\n" NOR,
                                      CYN + ob->name() + CYN "�����������Ҳ�����ˣ�\n" NOR,
                }) );
        }

        remove_call_out("do_back");
        call_out("do_back", 10 + random(10));
        return -1;
}

void do_back()
{
        remove_call_out("do_back");
        if (base_name(environment()) == query("startroom"))
                return;

        if (! living(this_object()) ||
            is_busy() || is_fighting())
        {
                call_out("do_back", 10 + random(10));
                return;
        }

        message_vision(HIW "$N" HIW "��ҡ���ȣ�ƮȻ��ȥ��\n" NOR, this_object());
        move(query("startroom"));
        message_vision(HIW "$N" HIW "��ҡ���ȣ�ʩʩȻ�����˹�����\n" NOR, this_object());
}

mixed ask_shenshe()
{
        object me;
        object ob;

        me = this_player();
        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������Ҵ��������ʲô��";

        if (time() - me->query_temp("ask_shenshe") < 900)
                return "�Ҳ��Ǹոո���һ����������ô��Ҫ��";

        if (query_temp("shenshe_count") < 1)
                return "û�ˣ����ֲ���������ģ������������ô�ࣿ";

        me->set_temp("ask_shenshe", time());

        add_temp("shenshe_count", -1);
        ob = new("/d/baituo/obj/shenshe");
        message_vision(HIC "$N" HIC "�������ܣ�����һ�������ظ�$n"
                       HIC "��\n" NOR, this_object(), me);
        ob->move(me, 1);
        return "�ţ���ɵ��պ��ˣ��𵽴��ҷš�";
}

void reset()
{
        set("shenshe_count", 5);
}
