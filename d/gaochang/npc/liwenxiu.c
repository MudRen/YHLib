#include <ansi.h>
inherit NPC;

int ask_supu();
int ask_parent();
int ask_gaochang();

void create()
{
        set_name("������", ({ "li wenxiu", "li", "wenxiu" }));
        set("gender", "Ů��");
        set("age", 18);
        set("long", "�������崿���㣬��ȻһЦ������������Ȼ�Ķ���\n");
        set("combat_exp", 300000);
        set("shen_type", 1);

        set("max_qi", 1500);
        set("max_neili", 1000);
        set("neili", 1000);
        set("jiali", 100);
        set_skill("force", 150);
        set_skill("whip", 150);
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);

        set("chat_chance", 3);
        set("chat_msg", ({
                CYN "�����������ؿ���Զ������̾����Ҳ��֪��ʱ�����ټ������ա���\n" NOR,
                CYN "������޺޵ص�����ĸ֮����һ��ҪѪծѪ����\n" NOR,
        }) );

        set("inquiry", ([
                "����"     : (: ask_supu :),
                "��ĸ"     : (: ask_parent :),
                "��ĸ֮��" : (: ask_parent :),
                "�߲��Թ�" : (: ask_gaochang:),
                "�߲���ͼ" : (: ask_gaochang:),
                "��������" : "�����Ҹ��ף��������Ҷ���֮ǰ����ĸ�㶼��ȥ���ˡ�",
        ]) );
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 200);

        setup();
        carry_object(__DIR__"obj/liuxingchui")->wield();
        carry_object("/d/city/npc/cloth/hat")->wear();
        carry_object("/d/city/npc/cloth/boots")->wear();
        carry_object("/d/city/npc/cloth/xian-cloth")->wear();
}

void init()
{
        object me;

        ::init();

        if (interactive(me = this_player()) && ! is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{
        if (! me || environment(me) != environment()) return;

        if ((string)me->query("gender") == "����")
		command("sigh " + me->query("id"));
        else
		command("look " + me->query("id"));
        return;
}

int ask_supu()
{
	say(CYN "��������Ȼ���������׸�ĸ˫�����������Ҷ�ʱ�Ļ�顣\n" NOR);
	this_player()->set_temp("marks/��1", 1);
	return 1;
}

int ask_parent()
{
	if ((int)this_player()->query_temp("marks/��1"))
	{
		say(CYN "���������ʵ����Ҹ�ĸ�Ǳ������ҼҸ߲���ͼ�ļ���������\n"
                    "��������ŵ�����һ��Ҫ���г��ˣ�Ϊ�Ҹ�ĸ����\n" NOR);
		this_player()->set_temp("marks/��2", 1);
		return 1;
	} else
	{
		say(CYN "������˵������ĸ֮�𣬲������졣\n" NOR);
		return 1;
	}
}

int ask_gaochang()
{
	object map, me = this_player();
        int exp, pot, sc;

        exp = 100 + random(200);
        pot = random(50);
        sc = random(3);

	if (me->query_temp("marks/��3"))
	{
                command("hmm " + me->query("id"));
                command("say �Ҳ����Ѿ��ѵ�ͼ����������");
                return 1;
        } else
	if (me->query_temp("marks/��2") && me->query("combat_exp") < 10000)
	{
                command("shake " + me->query("id"));
                command("say ��Ľ�������̫ǳ���α�ȥ��������");
                return 1;
        } else
	if (me->query_temp("marks/��2"))
	{
		say(CYN "������̾�����߲��Թ�����ʵʲô��û�У����ͼ��Ҫ����ȥ���ˡ�\n" NOR);
		map = new("/d/gaochang/obj/map");
		map->move(me, 1);
        	message_vision ("�������ó�" YEL "�߲��Թ���ͼ" NOR "(map)��$N��\n", me);
		if (! (int)me->query("skybook/baima/map"))
		{
               		me->add("combat_exp", exp);
               		me->add("potential", pot);
               		me->add("score", sc);
               		tell_object(me, HIW "\n��ɹ��ĵõ��˸߲��Թ���ͼ��\n" NOR + HIC "ͨ"
                                        "����ε�������������" + chinese_number(exp) + "��"
                                        "���顢" + chinese_number(pot) + "��Ǳ���Լ�" +
                                        chinese_number(sc) + "�㽭��������\n\n" NOR);
                        me->set("skybook/baima/map", 1);
		}
		me->set_temp("marks/��3", 1);
        } else
	{
   		message("vision", HIR "�����㲪Ȼ��ŭ���ȵ�����Ҳ�����Ҹ�ĸ�ĸ߲���"
                                  "ͼ���Ҹ���ƴ�ˣ�\n" NOR, environment());
		kill_ob(me);
	}
	return 1;
}
