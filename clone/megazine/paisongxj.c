#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name(HIG "����С��" NOR, ({ "paisong xiaojie"}) );
       set("title",HIG "��������־����" NOR);
        set("gender", "Ů��" );
	set("age", 21);
	set("long",
		"����һλ����������С�㣬�����ڷ��͡���������־,������ֻҪ����һ�����ӾͿ����õ���־�ˡ�\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С��");
       set("inquiry", ([ 
"zazhi": "���������ṩ����ҵġ���������־��\n",
"������־": "���������ṩ����ҵġ���������־��\n",
"���": "�������֪��,���ǲ����˰�,�����������𾴵��糤��!\n",
"wfoxd": "�������֪��,���ǲ����˰�,�����������𾴵��糤��!\n",
]) );
       set("chat_chance", 15); 
       set("chat_msg", ({
"����С��˵�������ǵġ���������־���Ǻã��Ƴ��͵õ��˴�ҵ��Ͽɡ�\n"
"����С�����˵������û��������������־���Ǿ�̫��ϧ��! \n",
"����С������ϵġ���������־������һ�¡�\n",
}) );
	setup ();
            carry_object("clone/cloth/female5-cloth")->wear();
       
}

int accept_object(object me, object ob)
{
        object ling;
        
        command("smile");
        command("say ��λ" + RANK_D->query_respect(me) + "�����۹� ��");

        if( ob->query("money_id") && ob->value() >= 100 && me->query("class") != "bonze" ) 
        {
                command("say " + RANK_D->query_respect(me) + 
                "���������־��");
                ling=new(__DIR__"obj/zazhi2");
                ling->move(me);
                message_vision("����С���$Nһ��"HIG"����������־"NOR"��\n", me);
                command("say ����־�������ڳ�һ�ڣ���ע����һ�ڵĳ������ڣ�");
                return 1;
        }

        return 1;
}
