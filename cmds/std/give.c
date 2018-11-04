// give.c

#include <ansi.h>
inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
        string no_accept;
        mixed info;
	int i, amount;

	if (! arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if (sscanf(arg, "%s to %s", item, target) == 2 ||
	    sscanf(arg, "%s %s", target, item) == 2 );
	else return notify_fail("��Ҫ��˭ʲô������\n");

	if (! objectp(who = present(target, environment(me))))
        {
                string ext;

                if (sscanf(arg, "%s %s %s", ext, target, item) != 3 ||
                    ! objectp(who = present(ext + " " + target, environment(me))))
		        return notify_fail("����û������ˡ�\n");
        }

        if (me == who)
                return notify_fail("���Լ����Լ���������\n");

        if (! living(who))
                return notify_fail("�㻹�ǵõ��˼�������˵�ɡ�\n");

	if (playerp(me) && stringp(no_accept = who->query("env/no_accept")))
        {
                if ((no_accept == "all" || no_accept == "ALL" ||
                     is_sub(me->query("id"), no_accept)) &&
                    ! is_sub(me->query("id"), who->query("env/can_accept")))
                {
                        // user refuse to accept
		        return notify_fail("�˼����ڲ���Ҫʲô������\n");
                }
        }

	if (sscanf(item, "%d %s", amount, item) == 2)
        {
		if (! objectp(obj = present(item, me)))
			return notify_fail("������û������������\n");

		if (me->query_temp("is_riding") == obj)
			return notify_fail("�����������ء�\n");

		if (info = obj->query("no_drop"))
			return notify_fail(stringp(info) ? info : "�����������������ˡ�\n");

		if (! obj->query_amount())
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");

		if (amount < 1)
			return notify_fail("����������������һ����\n");

		if (amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");

		else if (amount == (int)obj->query_amount())
                {
			do_give(me, obj, who);
                        return 1;
		} else
                {
			obj->set_amount((int)obj->query_amount() - amount);
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else
                        if (obj2)
                        {
				obj->set_amount((int)obj->query_amount() + amount);
                                destruct(obj2);
				return 1;
			}
		}
	}

	if (item == "all")
        {
                if (time() - me->query_temp("give_all") < 5)
                        return notify_fail("�벻ҪƵ����ʹ�� all ������\n");

		inv = all_inventory(me);
		for (amount = 0, i = 0; i < sizeof(inv); i++)
                {
                        if (! living(me)) break;
                        if (environment(me) != environment(who)) break;
			if (me->query_temp("is_riding") != inv[i])
				amount += do_give(me, inv[i], who);
		}
                if (! amount)
		{
                        write("��ʲô��û�и���ȥ��\n");
			return 1;
		}
                if (userp(me) && userp(who))
                        log_file("static/give", sprintf("  %s  %sת������"
                                 "��Ʒ��    %s\n", log_time(), log_id(me),
                                 log_id(who)));

		write("�����ˡ�\n");
                me->set_temp("give_all", time());
		return 1;
	}

	if (! objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");

	if (me->query_temp("is_riding") == obj)
		return notify_fail("�����������ء�\n");

	do_give(me, obj, who);
        return 1;
}

int do_give(object me, object obj, object who)
{
	if (obj->query("no_drop"))
        {
		tell_object(me, "�����������������ˡ�\n");
                return 0;
        }

	if (living(obj))
	{
		tell_object(me, "���ģ�����ô����������Ҳ����\n");
		return 0;
	}

	switch ((string)obj->query("equipped"))
	{
	case "worn":
		tell_object(me, obj->name() + "�������������ܸ����ˡ�\n");
                return 0;

	case "wielded":
                tell_object(me, obj->name() + "������װ�����ܸ����ˡ�\n");
                return 0;
	}
		
        message_vision("$N�ó�" + obj->short() + "��$n��\n", me, who);
	if (! playerp(who))
        {
                function f;
                int r;

                // ������Ʒ��ʱ�������ж��Ƿ������صĽ��պ���
                f = who->query_temp("override/accept_object", 1);
                if (functionp(f))
                        r = (*f)(who, me, obj);
                else
                        r = 0;

                if (! r)
                        // ���صĺ��������ܣ�Ҳ������(����-1)
                        // ��ô�͵���accept_object���д���
                        r = who->accept_object(me, obj);

                if (! objectp(who))
                        return 0;

                switch (r)
                {
                case 0:
                        message_vision("$n����Ҫ$N��" + obj->name() + "��\n", me, who);
        		return 0;
                case -1:
                        // The receiver will handle all the things
                        if (! obj || environment(obj) == who)
                                return 1;
                        return 0;
                default:
                        break;
                }
                if (! objectp(obj))
                        // The receive has destructted the object
                        return 1;
        }

	if (! playerp(who) && obj->value())
        {
		message_vision("$n�ӹ���$N��" + obj->short() + "��\n", me, who);
		destruct(obj);
		return 1;
	}

        if (! obj->move(who))
        {
                message_vision("Ȼ��$nû����ס$N��" + obj->name() + "��\n", me, who);
                return 0;
        }

        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��give <��Ʒ����> | all to <ĳ��>
          give <ĳ��> <��Ʒ����> | all
 
���ָ��������㽫ĳ����Ʒ�����ˣ���Ȼ��������Ҫӵ��������Ʒ��
 
HELP);
        return 1;
}
