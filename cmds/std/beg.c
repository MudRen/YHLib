// beg.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string what, who;
        object ob, victim;
        int sp, dp;

        object where = environment(me);

        seteuid(getuid());

        if (me->query("family/family_name") != "ؤ��")
          	return notify_fail("ֻ����ؤ�������֡�\n");

        if (environment(me)->query("no_beg")
           || environment(me)->query("no_fight"))
                return notify_fail("���ﲻ����л��������ַ��ĵط���\n");

        if (me->query_temp("begging"))
                return notify_fail("���Ѿ������˼������ˡ�\n");

        if (! arg || sscanf(arg, "%s from %s", what, who) != 2)
                return notify_fail("ָ���ʽ��beg <��Ʒ> from <����>\n");

        victim = present(who, environment(me));

	if (what != "cash" && what != "gold"
           && what != "silver" && what != "coin")
		return notify_fail("��ֻ������Ӳͨ����\n");

        if (! victim || victim == me)
		return notify_fail("�������ֵĶ��������\n");

        if (! living(victim) || ! objectp(victim))
		return notify_fail("��Ҫ��˭���֣�\n");

        if (victim->query("family/family_name") == "ؤ��")
                return notify_fail("�Ǽһ�Ҳ����ؤ�����ֲ���ʲô��\n");

        if (! wizardp(me) && wizardp(victim))
		return notify_fail("�������һ�£����û��Ǳ����Ǽһ�Ϊ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ�ļһ�ŵ���˵�ɡ�\n");

        if (victim->is_fighting())
                return notify_fail(victim->name() + "���ڴ�ܣ�û�����㡣\n");

        ob = present(what, victim);
        if (! ob) ob = present("cash", victim);
        if (! ob) ob = present("gold", victim);
	if (! ob) ob = present("silver", victim);
	if (! ob) ob = present("coin", victim);

        if (! ob)
                return notify_fail("������" + victim->name() + "����û��ʲ"
                                   "���������Ȥ�Ķ�����\n");

        if (ob->query("equipped") || ob->query("no_drop"))
                return notify_fail("�������˵�����һ�϶�������㡣\n");

        sp = (int)me->query_skill("begging");
	sp = sp * sp * sp / 10;

        if (sp < 1) sp = 1;
        dp = (int)victim->query("jing") + ob->value() / 5;

        message_vision(WHT "ֻ��$N" WHT "�����Ͱ͵���$n"
                       WHT "����˵������λ" + RANK_D->query_respect(victim) +
                       WHT "�����кã����ҵ�Ǯ�ɡ�\n" NOR, me, victim); 

        me->set_temp("begging", 1);
        call_out( "compelete_beg", 3, me, victim, ob, sp, dp);
        return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
        int amount;
	int bcount;
        object ob1;
        object where;

        if (! objectp(me))
                return;

        me->delete_temp("begging");

        where = environment(me);

	if (! objectp(ob) || ! living(me) || me->is_fighting())
		return;

        if (! victim || environment(victim) != environment(me))
        {
                tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
                return;
        }

        if (environment(ob) != victim)
        {
                tell_object(me, "̫��ϧ�ˣ��˼Һ����Ѿ�û��" +
                                ob->name() + "�ˡ�\n");
                return;
        }

        if (living(victim) && (random(sp + dp) > dp))
        {
                if (! ob->query("money_id") || ! (amount = ob->query_amount()))
                {
                        tell_object(me, HIY "���������߰ɣ���һ������Ѿ�"
                                        "û�ж�����ˮ��ե�ˡ�\n" NOR);
                        return;
                }

		bcount = amount / 5;
		if (! bcount) bcount = 1;
                ob->set_amount(amount - bcount);

                ob1=new("/clone/money/" + ob->query("money_id"));
                ob1->set_amount(bcount);
                ob1->move(me);

                message_vision(HIC "$n" HIC "������ü������̾�˿���������" +
                               ob1->query("unit") + ob1->name() +
                               HIC "�Ӹ�$N" HIC "��\n" NOR, me, victim);

      		if (me->can_improve_skill("begging"))
          		me->improve_skill("begging", random(me->query("int")));

      		if ((int)me->query("potential") < (int)me->query_potential_limit())
                        me->add("potential", 1);

                me->add("combat_exp", 1);
                me->start_busy(3 + random(4));
        } else
        {
                if (random(sp) > dp / 2)
                {
                        message_vision(HIR "$n" HIR "�ݺݵص���$N"
                                       HIR "һ�ۣ��ȵ���������$N"
                                       HIR "ֻ�û�������߿��ˡ�\n"
                                       NOR, me, victim);
                	me->start_busy(3);
                        return;
                }
                message_vision(CYN "$n" CYN "Ť��ͷȥ�����һ������$N"
                               CYN "������\n" NOR, me, victim);
                me->start_busy(3);
        }
}

int help(object me)
{
write(@HELP
ָ���ʽ��beg <����> from <ĳ��>

������ǽл��ӣ�������������������ֵ�Ǯ��
HELP);
        return 1;
}
