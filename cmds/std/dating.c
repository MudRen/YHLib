// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, man, *all;
	mapping skl, lrn, map;
	string *sname, *mapped;
	int sp, dp;
	int i, cost;
        int sklvl;
        int precise;

	seteuid(getuid());

	all = all_inventory(environment(me));
	for (i = 0; i < sizeof(all); i++)
	{
		if (living(all[i]) && ! userp(all[i]) &&
		    all[i]->query("can_speak") &&
		    ! all[i]->query("not_living"))
		{
			man = all[i];
			break;
		}
	}

        if (me->query("family/family_name") != "ؤ��")
		return notify_fail("ֻ����ؤ���ܴ�̽���˵ļ��ܣ�\n");

	if (! objectp(man))
		return notify_fail("��Χû���ܰ���ȥ�˽���˵ļ��ܣ�\n");

        if ((sklvl = me->query_skill("checking", 1)) < 30)
		return notify_fail("��Ĵ�̽������δ���죬�޷�"
				   "�˽���˵ļ��ܣ�\n");

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
        me->receive_damage("jing", cost);

	tell_object(me, HIY "\n������ǰȥ��С���������" + man->name() + HIY
			"��������" + ob->name() + HIY "�������\n" NOR);

	message("vision", HIY "ֻ��" + me->name() + HIY "����Ц����" HIY +
			  man->name() + HIY "˵�Ż��������ڴ���Щʲô��\n" NOR, 
		          environment(me), ({ me, man }) );

	sp = me->query_skill("checking") * 10 + 
	     me->query("jing") + man->query("jing");
	dp = ob->query("jing") * 2;

	if (me->query("combat_exp") < ob->query("combat_exp") * 2 / 3)
		return notify_fail(CYN + man->name() + CYN "ҡ��ҡͷ��˵������"
                                   + ob->name() + CYN "����ǿ���ˣ�û����ñ�ȥ"
                                   "���ǡ�\n" NOR);

	if (random(sp) < random(dp))
		return notify_fail(CYN + man->name() + CYN "ҡ��ҡͷ��˵������"
                                   "�¿ɲ������" + RANK_D->query_respect(me) +
				   CYN "����ȥ����˴���һ�°ɣ�\n" NOR);
	skl = ob->query_skills();
	if (! sizeof(skl))
	{
		write(WHT + man->name() + WHT "�����㣺 " + ob->name() +
		      WHT "Ŀǰ��û��ѧ���κμ��ܡ�\n" NOR);
		return 1;
	}
	write(WHT + man->name() + WHT "�����㣺 " + ob->name() + WHT "Ŀ"
              "ǰ��ѧ���ļ��ܣ�\n" NOR);
	sname  = sort_array(keys(skl), (: strcmp :));
	
	map = ob->query_skill_map();
	if (mapp(map)) mapped = values(map);
	if (! mapped) mapped = ({});

	lrn = ob->query_learned();
	if (! mapp(lrn)) lrn = ([]);
	
	i = random(sizeof(skl));

        // ����Ǵ������ļ��ܵľ�ȷ��
        precise = 1000 / sklvl;

	write(sprintf("%s%s%-40s" NOR " - %3d\n", 
		(lrn[sname[i]] >= (skl[sname[i]] + 1) * (skl[sname[i]] + 1)) ? HIM : "",
		(member_array(sname[i], mapped) == -1? "  " : "��"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		(skl[sname[i]] + precise / 2) / precise * precise));

	if (me->can_improve_skill("checking"))
		me->improve_skill("checking", random(me->query("int")));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : check|dating [<ĳ��>]

���ָ������������������ѧ���ļ��ܡ���Ҳ����ָ��һ������
��ʦͽ��ϵ�Ķ����� skills|cha ���Բ�֪�Է��ļ���״����

������Ϊؤ�����ר�ã�����ѧϰ��Ӧ�ļ��ܡ�������ܲ��ߣ���
ô���������Ŀ��ܻ���һЩ���롣�����̽Ŀ�����ѧǿ����̽��
̫�࣬���̽�����κ���Ϣ��

HELP);
    return 1;
}
