// wear.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if (! arg) return notify_fail("��Ҫ����ʲô��\n");

	if (arg == "all")
        {
		inv = all_inventory(me);
		for(count = 0, i = 0; i < sizeof(inv); i++)
                {
			if (inv[i]->query("equipped")) continue;
			if (do_wear(me, inv[i])) count++;
		}
                if (! count)
                        write("��ʲô��û�д��ϡ�\n");
                else
		        write("�㴩���ˡ�\n");
		return 1;
	}

	if (! objectp(ob = present(arg, me)))
		return notify_fail("������û������������\n");

	if (ob->query("equipped"))
        {
		inv = all_inventory(me) - ({ ob });
		for(count = 0, i = 0; i < sizeof(inv); i++)
                {
			if (! inv[i]->id(arg)) continue;
			if (inv[i]->query("equipped")) continue;
			if (do_wear(me, inv[i]))
                        {
				count++;
				break;
			}
		}
		if (! count)
			return notify_fail("���Ѿ�װ�����ˡ�\n");

		return 1;
	}

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;
        mapping p;
        mixed notice;

        if (notice = ob->query_temp("no_wear"))
        {
                if (stringp(notice)) write(notice);
                return notify_fail("�������Ա�İɣ�\n");
        }

	if (ob->query("female_only") &&
	    (string)me->query("gender") =="����")
		return notify_fail("����Ů�˵���������һ��������Ҳ�봩����Ҳ���ߣ�\n");

	if (ob->wear())
        {
		if (! stringp(str = ob->query("wear_msg")))
			switch (ob->query("armor_type"))
                        {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N����һ" + ob->query("unit") + "$n" YEL "��\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "hands":
					str = YEL "$N����һ" + ob->query("unit") + "$n" YEL "��\n" NOR;
					break;
				case "waist":
					str = YEL "$N��һ" + ob->query("unit") + "$n" YEL "�������䡣\n" NOR;
					break;
				default:
					str = YEL "$Nװ��$n" YEL "��\n" NOR;
			}
                if (ob->query_temp("daub") &&
                    ob->query("armor_type") != "hands")
                        DAUB_CMD->check_poison(me, ob);

		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��wear <װ������>
 
���ָ������װ��ĳ�����ߡ�
 
HELP );
        return 1;
}
