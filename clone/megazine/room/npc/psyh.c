#include <ansi.h>

inherit NPC;
inherit F_DEALER;

mixed ask_me();

void create()
{
        set_name("����Ѿ��", ({ "paisong yahuan","yahuan","paisong"}) );
        set("title",HIW "����������־��" NOR);
        set("gender", "Ů��" );
	set("age", 21);
	set("long", "����һλ����������С�㣬�����ڷ��͡���������־,�������������Ҫ��־��\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С��");

        set("inquiry", ([ 
                "zazhi": "���������ṩ����ҵġ���������־��\n",
                "������־" : (: ask_me :),
                "��־"     : (: ask_me :),
                "��־Ŀ¼" : (: ask_me :),
                "���" : "�������֪�������ǲ����˰��������������𾴵��糤����\n",
                "wfoxd": "�������֪�������ǲ����˰��������������𾴵��糤����\n",
        ]));

        set("chat_chance", 10);
        set("chat_msg", ({
                "����С��˵�������ǵġ���������־���Ǻã��Ƴ��͵õ��˴�ҵ��Ͽɡ�\n"
                "����С�����˵������û��������������־���Ǿ�̫��ϧ�ˣ�\n",
                "����С������ϵġ���������־������һ�¡�\n",
        }));

	setup();
        carry_object("clone/cloth/female5-cloth")->wear();
}

void init()
{
	add_action("do_follow","follow");
}

int do_follow(string arg)
{
	object me;

        if (arg != "me")
                return 0;

        me = this_player();
        if (me->query("id") != "wfoxd")
                return 0;

        message_vision("$N����$n�ĺ��档\n", this_object(), me);
        set_leader(me);
        return 1;
}

mixed ask_me()
{
	object me, ob;

	me = this_player();
	if (me->query_temp("��־") == 1)
	        return "���Ѿ������㣬����ÿ������ֻ��Ҫһ�ᡣ";

	command("say �õģ������ϸ��㡣");
        ob = new("/clone/megazine/obj/zazhi6");
  	ob->move(me);
  	message_vision("����Ѿ�߸���$Nһ�᡼��������־Ŀ¼��\n", me);
  	me->set_temp("��־", 1);
        return 1;
}
