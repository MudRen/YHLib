#include <ansi.h>
inherit F_CLEAN_UP;

int player_pay(object who, object target, int amount);
void destruct_it(object ob);

int main(object me, string arg)
{
        mapping goods;
        int amount;
        int value, val_factor;
        string ob_file;
	object *obs;
        object ob, env, obj;
	string my_id;
	int i;
        
        if(me->is_busy())
                return notify_fail("ʲô�¶��õ���æ����˵�ɣ�\n");

        if (! arg)
                return notify_fail("ָ���ʽ��buy <��Ʒ> from <���>\n");

	if (! (sscanf(arg, "%s from %s", arg, my_id) == 2) )
                return notify_fail("ָ���ʽ��buy <��Ʒ> from <���>\n");

        if (sizeof(all_inventory(me)) >= MAX_ITEM_CARRIED)
        {
                write("�����ϵĶ���̫���ˣ��ȴ���һ���������ɡ�\n");
                return 1;
        }

        // no present or equipped
        env = environment(me);

        if (! (obj = find_player(my_id)) || ! (present(obj->query("id"), env))) 
                return notify_fail("����û��������ˡ�\n");

        if (obj == me)
                return notify_fail("���Լ��������Ա��˳ŵģ�\n");

        if (! obj->query("is_vendor"))
                return notify_fail(obj->name(1) + "���������ˡ�\n");

        if (! obj->query_temp("on_baitan"))
                return notify_fail(obj->name(1) + "��û�а�̯��\n");

        if (! (goods = obj->query("vendor_goods")))
                return notify_fail(obj->name(1) + "��û�ж����κλ��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        ob = present(arg, obj);

	if (! ob || ! objectp(ob))
                return notify_fail(obj->name(1) + "��û�ж����������\n");

        if (! goods[base_name(ob)])
                return notify_fail(obj->name(1) + "��û�ж����������\n");

        value = goods[base_name(ob)];

        if (ob->query_amount())
        {
                object old_ob;
                ob = new(base_name(old_ob = ob));
                ob->set_temp("moved_from", old_ob);
                call_out("destruct_it", 0, ob);
        }

        switch (player_pay(me, obj, value))
        {
        case 0:
                write(CYN + obj->name(1) + CYN "��Цһ�����������"
                      "�⵰��һ�ߴ���ȥ��\n" NOR);
                return 1;
        case 2:
                write(CYN + obj->name(1) + CYN "��ü����������û��"
                      "��Ǯ������Ʊ�ҿ��Ҳ�����\n" NOR);
                return 1;
        default:
                if (ob->query_amount())
                {
                        message_vision("$N��$n����������" + ob->short() + "��\n",
                                        me, obj);
                } else
                {
                        message_vision("$N��$n����������һ" + ob->query("unit") + 
                	               ob->query("name") + "��\n",
			               me, obj);
                }
                ob->move(me, 1);

                if (objectp(ob->query_temp("moved_from")))
                {
                        ob->query_temp("moved_from")->add_amount(-1);
                        ob->delete_temp("moved_from");
                }

        }
        me->start_busy(2);
        return 1;
}

int player_pay(object who, object target, int amount)
{
	object t_ob, g_ob, s_ob, c_ob;
	int tc, gc, sc, cc, left;
	int v;

	seteuid(getuid());

	if (amount >= 100000 && t_ob = present("cash_money", who))
		tc = t_ob->query_amount();
	else
	{
		tc = 0;
		t_ob = 0;
	}

	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;

	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;

	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	
	v = cc + sc * 100 + gc * 10000;

	if (amount < 100000 && v < amount)
	{
		if (present("cash_money", who))
			return 2;
		else
			return 0;
	}

	v += tc * 100000;

	if (v < amount) 
		return 0;
	else {
		left = v - amount;
		if (tc)
		{
			tc = left / 100000;
			left %= 100000;
		}

		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

		if (t_ob && ! g_ob && gc)
		{
			g_ob = new(GOLD_OB);
			g_ob->move(who, 1);
		}

		if (t_ob)
			t_ob->set_amount(tc);

		if (g_ob)
			g_ob->set_amount(gc);
		else
                        sc += (gc * 100);

		if (s_ob)
		 	s_ob->set_amount(sc);
		else
                if (sc)
                {
			s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			s_ob->move(who, 1);
		}

		if (c_ob)
			c_ob->set_amount(cc);
		else
                if (cc)
                {
			c_ob = new(COIN_OB);
			c_ob->set_amount(cc);
			c_ob->move(who, 1);
		}

                target->add("balance", amount * 19 / 20);
                     if (query_ip_number(target) != query_ip_number(who))

                target->add("vendor_score", amount / 2500);
		return 1;
	}
}

void destruct_it(object ob)
{
        if (! ob || environment(ob))
                return;

        destruct(ob);
}


int help (object me)
{
        write(@HELP
ָ���ʽ: buy <��Ʒ> from <���>

��һ��������˹�����Ʒ��

���ָ�list

HELP);
	return 1;
}
