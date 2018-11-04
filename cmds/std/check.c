// skills.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, man, *all;
	mapping skl, lrn, map;
	string msg, *sname, *mapped;
	int sp, dp;
	int i, cost;
        int lvl, sklvl;
        int precise;

	seteuid(getuid());

        if (me->query("family/family_name") != "ؤ��")
		return notify_fail("�㲻֪��������˲�̽�鱨��\n");

        if ((sklvl = me->query_skill("checking", 1)) < 30)
		return notify_fail("��Ĵ�̽������δ���죬�޷�"
				   "�˽���˵ļ��ܡ�\n");

	all = all_inventory(environment(me));

	for (i = 0; i < sizeof(all); i++)
	{
		if (living(all[i])
                   && ! userp(all[i])
                   && all[i]->query("can_speak")
                   && ! all[i]->query("not_living"))
		{
			man = all[i];
			break;
		}
	}

	if (! objectp(man))
		return notify_fail("����Χ��û�ˣ�û�취������\n");

	if (! arg)
		return notify_fail("��Ҫ����˭�ļ��ܣ�\n");

        if (present(arg, environment(me)))
		return notify_fail("��Ҫ�������˾��ڱ��ϣ�������"
				   "�ʲ����׵��ɣ�\n");

	ob = find_player(arg);
	if (! ob) ob = find_living(arg);
	if (! ob) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");

	if (ob == me)
		return notify_fail("�����ڰɣ�Ҫ���˸������Լ��ļ��ܣ�\n");

	cost = me->query("max_jing") / (sklvl / 10) - 10;
        if (cost < 40) cost = 30 + random(10);

	if (me->query("jing") <= cost)
		return notify_fail("������̫���ˣ��޷�ȥ�������˵ļ��ܡ�\n");

        if (ob->query("special_skills/emperor"))
                return notify_fail("�������������ӣ��޷�֪̽�����ԡ�\n");

        me->receive_damage("jing", cost);

	tell_object(me, WHT "\n������ǰȥ��С���������" + man->name() +
                        WHT "��������" + ob->name() + WHT "�������\n" NOR);

	message("vision", WHT "ֻ��" + me->name() + WHT "����Ц������" +
			  man->name() + WHT "˵�Ż��������ڴ���Щʲô��"
                          "\n" NOR, environment(me), ({ me, man }) );

	sp = me->query_skill("checking") * 10 + 
	     me->query("jing") * 3;

	dp = ob->query("jing") * 2;

	if (userp(ob) && me->query("combat_exp") <
                         ob->query("combat_exp") * 2 / 3)
		return notify_fail(CYN + man->name() + CYN "����ü������"
                                   + ob->name() + CYN "����ǿ���ˣ���û��"
                                   "ȥ������������\n" NOR);

	if (random(sp) < random(dp))
		return notify_fail(CYN + man->name() + CYN "ҡ��ҡͷ��˵"
                                   "�����Ҽǲ�������ˣ��㻹��ȥ���ʱ���"
                                   "�ɡ�\n" NOR);

        msg = HIG + man->name() + HIG "���ĸ����㣺" +
              ob->name() + HIG;

	skl = ob->query_skills();

	if (! sizeof(skl))
	{
                msg += "ɶ�����ᣬ���������\n" NOR;
		write(msg);
		return 1;
	}

	sname  = sort_array(keys(skl), (: strcmp :));
	
	map = ob->query_skill_map();
	if (mapp(map)) mapped = values(map);
	if (! mapped) mapped = ({});

	lrn = ob->query_learned();
	if (! mapp(lrn)) lrn = ([]);
	
	i = random(sizeof(skl));

        // ����Ǵ������ļ��ܵľ�ȷ��
        precise = 1000 / sklvl;
        lvl = (skl[sname[i]] + precise / 2) / precise * precise;

        msg += "������" + to_chinese(sname[i]) + "������������" +
               chinese_number(lvl) + "���˰ɡ�\n" NOR;

	if (me->can_improve_skill("checking"))
		me->improve_skill("checking", random(me->query("int")));

        write(msg);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��check|dating [<ĳ��>]

���ָ������������������ѧ���ļ��ܡ���Ҳ����ָ��һ��������
ʦͽ��ϵ�Ķ����� skills | cha ���Բ�֪�Է��ļ���״��������
��Ϊؤ�����ר�ã�����ѧϰ��Ӧ�ļ��ܡ�������ܲ��ߣ���ô����
�����Ŀ��ܻ���һЩ���롣�����̽Ŀ������ҵĻ�������ѧǿ����
̽��̫�࣬���̽�����κ���Ϣ��

HELP);
        return 1;
}
