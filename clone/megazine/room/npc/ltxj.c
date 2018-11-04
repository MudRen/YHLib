#include <ansi.h>

inherit NPC;

int ask_me();
int unm;

void create ()
{
        set_name("����Ѿ��" ,({"liaotian yahuan", "yahuan", "liaotian"}));
        set("gender","Ů��");
        set("title", HIW "����������־��" NOR);
        set("nickname", HIB "���޵�" NOR);
        set("age", 18);
        set("long", "����Ѿ����Ȼ�ŵ����ˣ����������Ѿ����˺ܸߵ����衣\n"
                    "����������֮ò����ɫ���������޾��ף������˼����ӣ�\n");
        set("str", 10);
        set("dex", 16);
        set("con", 30);
        set("int", 56);

        set_skill("idle-force", 300);

        set("combat_exp", 2000);

        set("max_qi", 200);
        set("max_jing", 200);
        set("max_neili", 100);
        set("neili", 100);

        set("attitude","friendly");
        set("inquiry",([
                "Ϊʲô" : "���ǲ�...", 
                "С��" : "С���һ����ûʲô��˵��", 
                "С������" : "����������ֵĴ����ˡ�", 
                "�糤����" : "�����.....��֪���������ǲ���������", 
                "����" : "��ҵĻ�������һ�԰���", 
                "�����ұ���" : "��ҵĻ�������һ�԰���", 
                "����" : "��ҵĻ�������һ�԰���", 
                "���" : "�Ҿ͸ң���....", 
                "������" : "�����ҵ����ܣ�", 
                "�ռ�����" : "����㶼��֪������������þ����ռ�������", 
                "����" : "����...������ܸ�����Ŷ��", 
                "�Ⱦ�" : "����.", 
                "��Щʲô��" : "���Ҫ��˵����", 
                "��Щʲô" : "���Ҫ��˵����", 
                "�������" : "��ΪʲôҪ�������أ�", 
                "���" : "��ΪʲôҪ�������أ�", 
                "���" : "���������𾴵��糤���ˡ�", 
                "��ʲô" : "������ʲô����", 
                "name" : "�Ҿ���ר�ź�������������Ѿ�ߡ�",
                "����" : "���Ǻ�������Щ���ĵ������졣",
                "����ħ" : "����Ҳ��֪��ѽ�������ռ������ĸ���ѽ.",
                "���Ư��" : (: ask_me :),
                "�����" : "�ҿɰﲻ����ʲô�����������컹����Ŷ��",
                "help" : "�ҿɰﲻ����ʲô�����������컹����Ŷ��",
                "�����������?" : "��Ȼ��������",
                "chat" : "��Ȼ��������",
                "����" : "��Ȼ��������",
                "miller" : "�ҿ�������Ѿ�ߣ�",
                "kill" : "С�����İ�?�����۸��ң�",
                "fight" : "С�����İ�?�����۸��ң�",
                "������" : "����չ�18���أ�",
                "����" : "����չ�18���أ�",
                "age" : "����չ�18���أ�",
                "����" : "����չ�18���أ�",
                "����������ʲô����" : "���������ѽ��",
                "work" : "���Ǻ�������Щ���ĵ������졣",
                "here" : "�����ǡ���������־�����ء�",
        ]));

        setup();
        set("chat_chance", 1);
        set("chat_msg",({ "����С������˵������˭�ܱ��һ��������أ�\n", }));
        carry_object("/clone/cloth/female1-cloth")->wear();
        carry_object("/clone/cloth/female-shoe")->wear();

}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1, ob);
        }

        add_action("do_look", "look");
        add_action("do_hug", "hug");
        add_action("do_hug", "hug1");
        add_action("do_hug", "marry");
        add_action("do_hug", "lovelook");
        add_action("do_hug", "fang");
        add_action("do_hug", "hug2");
        add_action("do_hug", "hug3");
        add_action("do_hug", "18mo");
        add_action("do_hug", "mo");
        add_action("do_hug", "kiss");
        add_action("do_hug", "kiss1");
        add_action("do_hug", "kiss2");
        add_action("do_hug", "kiss3");
        add_action("do_hug", "love1");
        add_action("do_hug", "love2");
        add_action("do_hug", "love3");
        add_action("do_hug", "colorlook");
        add_action("do_kok", "kok");
        add_action("do_kok", "slap");
        add_action("do_kok", "kick");
        add_action("do_kok", "pat");
        add_action("do_kok", "nip");
        add_action("do_kok", "fight");
        add_action("do_kok", "kill");
        add_action("do_wuliao", "wuliao");
        add_action("do_wuliao", "chat");
}

void greeting(object me)
{
        if (me->query("id") == "wfoxd" || me->query("id") == "miller")
        {
                command("jump " + me->query("id"));
                if (me->query("id") == "miller")
                {
                        command("say �Һ����㰡������ô���ڲ�������");
                        return;
                }
                command("say ���һ�ӭ����糤��鹤�������\n");
                return;
        }
 
        if (me->query("age") < 16)
        {
                 command("say С������ʲô�죬һ��ȥ�棡");
                 command("kick " + me->query("id"));
                 message("vision", me->query("name") + "������Ѿ�����˳�ȥ��\n",
                         environment(me), ({ me }));
                 me->move("/d/city/kedian");
                 message("vison", me->query("name") + "���˴��������˳�����\n",
                         environment(me), ({ me }));
                 return;
        }

        if (me->query("gender") == "����")
        {
                if (me->query("per") >= 27)
                {
                        command("wa " + query("id"));
                        command("say ��λ˧�磬���ǿ��Ժú�������\n");
                }
                else
                {
                        command("nod " + query("id"));
                        command("say ��λ�����кι�ɣ�\n");
                }
        }

        return;
}

int do_look(string target)
{
	object me;
	object ob=this_object();

	me = this_player();
	if (target == "yahuan" || target == "liaotian yahuan" || target == "liaotian")

        {
                command("angry " + me->query("id"));
                command("say ��㿴İ��Ů����һ�ֲ���ò����Ϊ���ѵ�����㶼��֪����");
        }
}

int do_hug(string target)
{
	object me;
	object ob=this_object();

	me = this_player();
	if (id(target))
        { 
                if (me->query_temp("liumang") == 1)
                {
                        message("vision", WHT + ob->query("name") + "(" +ob->query("id")+ ")��" +
                                me->query("class") + me->query("name") + "���Ǳ������ƣ���������ˣ��å�ˣ�\n" NOR, users());
                        message_vision(HIG "����С������ĵ�����һ�£���ֻ�����е����ˣ�\n" NOR, me);
                        me->add("jing", -400);
                        me->delete_temp("liumang");
                        return 1;
                }

                message("vision", WHT + ob->query("name") + "(" +ob->query("id")+ ")��" + "���ע�⣡����" +
                                  me->query("class") + me->query("name") + "��ˣ��å�ˣ�\n"NOR, users());
                message_vision(HIG "����С������ĵ�����һ�£���ֻ�����е����ˣ�\n" NOR, me);
                me->add("jing", -300);
                me->set_temp("liumang",1);
        }
        return 1;
}

int do_kok(string target)
{
	object me;
	object ob=this_object();

	me = this_player();
	if (id(target))
  	{
                if (me->query_temp("liumang") == 1)
	 	{
                        message("vision", WHT + ob->query("name") + "(" +ob->query("id")+ ")��" +
                                          me->query("class") + me->query("name") + "���Ƕ�ϰ�Ѹģ����������۸����ˣ�\n" NOR,
                                          users());
                         message_vision(HIG "����С������ĵ�����һ�£���ֻ�����е����ˣ�\n" NOR, me);
                         me->add("jing", -400);
                         me->delete_temp("liumang");
                         return 1;
                }

	  	message("vision", WHT + ob->query("name") + "(" +ob->query("id")+ ")��" + "���ע�⣡����" +
                                  me->query("class") + me->query("name") + "�����۸����ˣ�\n"NOR, users() );
                message_vision(HIG "����С������ĵ�����һ�£���ֻ�����е����ˣ�\n" NOR, me);
                me->add("jing", -300);
                me->set_temp("liumang",1);
        }

        return 1;
}

int ask_me()
{
	object me , ob;

	me = this_player();
	command("say ����лл��Ŀ佱");
	if (random(5) == 0)
        {
	  	 command("say ��Ȼ��˵����ô�������Ҿ͸���㶫���ɣ�");
                 ob = new("/clone/megazine/obj/zazhi2");
	  	 ob->move(me, 1);
	  	 message_vision("����Ѿ�߸�$N������������־��\n",me);
        }
        return 1;
}

int do_wuliao(string target)
{
        object me;

        if (id(target)) 
                command("say ��Ȼ���������������ǿ�ʼ������İɣ�");

        return 1;
}
