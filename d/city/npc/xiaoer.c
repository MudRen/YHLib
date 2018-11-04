#include <ansi.h>
#include <command.h>

inherit NPC;

void create()
{
        set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        setup();
        if (clonep()) keep_heart_beat();
}

string accept_ask(object me, string topic)
{
        switch (random(5))
        {
        case 0:
                return "�ˣ���æ���أ������������¥������ֵ����İɣ�";

        case 1:
                return "���ɶ��û����æ����ô��";

        case 2:
                return "��ѽѽ����û����æ����ô��Ҫ������Ϣ��ȥ��������¥������ֵܰɣ�";

        case 3:
                return "������ݵ��ϰ��ﰢ��ɩ��ϢҲ��ͨ����Щү��ʲô����������Ҫ��������ȥ��";

        default:
               return "��������¥������ֵ���Ϣ�Ž���ͨ����ȥ�����İɡ�";
        }
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
        add_action("do_drop", "drop");
  	add_action("do_exchange", "exchange");
  	add_action("do_exchange", "duihuan");
}

void greeting(object ob)
{
        if ( ! ob || environment(ob) != environment() ) return;
        switch( random(2) )
        {
        case 0:
                say( CYN "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "�������ȱ��裬ЪЪ�Ȱɡ�\n" NOR);
                break;
        case 1:
                say( CYN "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                   + CYN + "����������\n" NOR);
                break;
        }
}

int accept_object(object me, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 1000) 
        {
                tell_object(me, CYN "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n" NOR);
                me->set_temp("rent_paid",1);
                return 1;
        }

        switch (random(6))
        {
        case 0:
                command("say �ã��ã�");
                break;
        case 1:
                command("say ����Ҫ�Ķ���ȫ���ң�");
                break;
        }

        if (! ob->is_character())
        {
                destruct(ob);
                return -1;
        }
        return 1;
}

void heart_beat()
{
        string start_room;
        object ob;

        if (stringp(start_room = query("startroom"))
           && find_object(start_room) == environment())
        {
                foreach (ob in all_inventory(environment()))
                {
                        if (! ob->is_character()
                           || interactive(ob)
                           || playerp(ob)
                           || ob->query_temp("owner"))
                                continue;

                        if (stringp(start_room = ob->query("startroom"))
                           && find_object(start_room) == environment())
                                continue;

		        if ((string)ob->query("id") == "corpse")
                        	message_vision(HIC "\n$N" HIC "վ������$n" HIC "�ൽ"
                                               "���⣬Ȼ�����������µ����˻�����\n\n"
                                               NOR, this_object(), ob);
			else
                        	message_vision(CYN "\n$N" CYN "��$n" CYN "����ǸȻ��˵"
                                               "�����Բ�ס��С���Ѿ������ˡ�\n" HIC "$n"
                                               HIC "����һ㶣�ҡ��ҡͷ���������ֵ�ת��"
                                               "��ȥ��\n" NOR, this_object(), ob);
                        ob->move("/d/city/beidajie1");
                }
        }
        ::heart_beat();
}

int do_drop(string arg)
{
        int i;
        object *obs;
        object ob;
        object me;

        if (! arg)
                return 0;

        me = this_player();
        if (objectp(ob = present(arg, me)) &&
            ob->is_character() && ! playerp(ob))
        {
                me->add_temp("static/drop_npc", 1);
                if (me->query_temp("static/drop_npc") > 1 &&
                    me->query("combat_exp") >= 50000)
                {
                        message_vision(CYN "\n$N" CYN "��ŭ���������" + RANK_D->query_rude(ob)
                                       + CYN "�����������ң�\n" NOR + HIC "˵��$N" HIC "һ����"
                                       "�У������ʱ���˳������������ţ���$n" HIC "��" + ob->name()
                                       + HIC "һ�����˳�ȥ��\n\n" NOR, this_object(), me);

                        ob->move("/d/city/beidajie1");
                        me->move("/d/city/beidajie1");
                        message("vision", HIC "ֻ���͵괦�鶣���һ����죬���" + me->name()
                                          + HIC "��" + ob->name() + HIC "һ����˳�����\n"
                                          NOR, environment(me), me);

                        me->receive_damage("qi", 1);
                        ob->die();
	                me->unconcious();
                        return 1;
                }

                message_vision(CYN "\n$N" CYN "ŭ���������������������ֲ��ǹײĵ꣬����Ҫ��"
                               "���˽������\n" NOR + HIC "˵��$N" HIC "һ���֣���ʱ����һȺ"
                               "���δ󺺣���$n" HIC "��" + ob->name() + HIC "һ����˳�ȥ��\n\n"
                               NOR, this_object(), me);

                ob->move("/d/city/beidajie1");
                me->move("/d/city/beidajie1");
                message("vision", HIC "ֻ���͵괦����һ���������" + me->name() + HIC "���˸�"
                                  "�˳����������������" + ob->name() + HIC "Ҳ�����˳�����"
                                  "\n" NOR, environment(me), me);
                me->receive_damage("qi", 1);
                return 1;
        }

        if (! DROP_CMD->main(me, arg))
                return 0;

        if (! GET_CMD->main(this_object(), arg))
                return 1;

        obs = all_inventory(this_object());
        for (i = 0; i < sizeof(obs); i++)
                if (! obs[i]->is_character()) destruct(obs[i]);
        if (! random(5))
        {
                switch (random(4))
                {
                case 0:
                        command("say �㲻Ҫ��Ҫ��");
                        break;
                case 1:
                        command("sigh " + this_player()->query("id"));
                        command("say ��̣������������");
                        break;
                case 2:
                        command("say �ܼ��ӣ��ܼ��ӣ�");
                        break;
                default:
                        command("heihei");
                        break;
                }
        }
        return 1;
}

int do_exchange(string arg)
{
  	object ob, me = this_player();
        int bug, bugp;

        bug = me->query("bug", 1);

        if (! bug)
    		return notify_fail(CYN "��С��������Цһ����û"
                                   "���㡣\n" NOR);

     	if (! arg)
    		return notify_fail(CYN "��С��΢Ц������Ҫ�һ�"
                                   "ʲô������\n" NOR);

     	if (arg == "Ѫ����"
           || arg == "������"
           || arg == "����"
           || arg == "׳�Ƿ�"
           || arg == "���ٸ�"
           || arg == "���۵�"
           || arg == "������")
	{
		bugp = 5;

		if (arg == "Ѫ����")
			ob = new("/clone/fam/pill/puti1");
                else
		if (arg == "������")
			ob = new("/clone/fam/pill/sheli1");
                else
		if (arg == "����")
			ob = new("/clone/fam/pill/linghui1");
                else
		if (arg == "׳�Ƿ�")
			ob = new("/clone/fam/gift/con1");
                else
		if (arg == "���ٸ�")
			ob = new("/clone/fam/gift/dex1");
                else
		if (arg == "���۵�")
			ob = new("/clone/fam/gift/int1");
                else
			ob = new("/clone/fam/gift/str1");
	} else
     	if (arg == "������"
           || arg == "��쵤"
           || arg == "��������")
	{
		bugp = 10;

		if (arg == "������")
			ob = new("/clone/fam/pill/puti3");
                else
		if (arg == "��쵤")
			ob = new("/clone/fam/pill/linghui2");
                else
			ob = new("/clone/fam/pill/sheli3");
	} else
     	if (arg == "������"
           || arg == "ʥ����"
           || arg == "�����˲�"
           || arg == "������֥"
           || arg == "��ɽѩ��")
	{
		bugp = 20;

		if (arg == "������")
			ob = new("/clone/fam/pill/puti4");
                else
		if (arg == "ʥ����")
			ob = new("/clone/fam/pill/sheli4");
                else
		if (arg == "�����˲�")
			ob = new("/clone/fam/pill/renshen1");
                else
		if (arg == "������֥")
			ob = new("/clone/fam/pill/lingzhi1");
                else
			ob = new("/clone/fam/pill/xuelian1");
	} else
     	if (arg == "������ĵ�"
           || arg == "��ɽѩ����"
           || arg == "������֥��"
           || arg == "�׻���Ԫ��"
           || arg == "�������"
           || arg == "��ȸ���絤"
           || arg == "�������ǵ�")
	{
		bugp = 30;

		if (arg == "������ĵ�")
			ob = new("/clone/fam/pill/renshen3");
                else
		if (arg == "��ɽѩ����")
			ob = new("/clone/fam/pill/xuelian3");
                else
		if (arg == "������֥��")
			ob = new("/clone/fam/pill/lingzhi3");
                else
		if (arg == "�������ǵ�")
			ob = new("/clone/fam/gift/con2");
                else
		if (arg == "��ȸ���絤")
			ob = new("/clone/fam/gift/dex2");
                else
		if (arg == "�������")
			ob = new("/clone/fam/gift/int2");
                else
			ob = new("/clone/fam/gift/str2");
	} else
     	if (arg == "ǧ����ĵ�"
           || arg == "ǧ��ѩ����"
           || arg == "ǧ����֥��"
           || arg == "ϴ�������ɵ�"
           || arg == "�����޼��ɵ�"
           || arg == "���ͨ���ɵ�"
           || arg == "�����Ԫ�ɵ�")
	{
		bugp = 50;

		if (arg == "ǧ����ĵ�")
			ob = new("/clone/fam/pill/renshen4");
                else
		if (arg == "ǧ��ѩ����")
			ob = new("/clone/fam/pill/xuelian4");
                else
		if (arg == "ǧ����֥��")
			ob = new("/clone/fam/pill/lingzhi4");
                else
		if (arg == "ϴ�������ɵ�")
			ob = new("/clone/fam/gift/con3");
                else
		if (arg == "�����޼��ɵ�")
			ob = new("/clone/fam/gift/dex3");
                else
		if (arg == "���ͨ���ɵ�")
			ob = new("/clone/fam/gift/int3");
                else
			ob = new("/clone/fam/gift/str3");
	} else
     	if (arg == "�԰׽�")
	{
		bugp = 100;
		ob = new("/clone/fam/max/naobaijin");
	} else
		return notify_fail(CYN "��С������ҡҡͷ������ֻ�ܶһ�"
                                   "�涨��Χ�ڵ���Ʒ��\n" NOR);

        if (bug < bugp)
		return notify_fail(CYN "��С������ҡҡͷ������Ļ��۷�"
                                   "���������޷��һ�������Ʒ��\n" NOR);

        if (! ob)
		return notify_fail(CYN "��С��һ�����е����ף��ҵĶ���"
                                   "���ҵĶ����أ���ʦ����ʦ��\n" NOR);
        me->add("bug", -bugp);

        ob->move(this_object());
        command("give " + ob->query("id") + " to " + me->query("id"));
        command("say ��л�ݹˣ�ϣ���Ժ����ܹ���������ʦ�㱨����");

        CHANNEL_D->do_channel(this_object(), "rumor", sprintf("��˵%s��"
                              "��С������ȡһ%s%s" HIM "��" NOR, me->name(),
                              ob->query("unit"), ob->name()));

    	return 1;
}