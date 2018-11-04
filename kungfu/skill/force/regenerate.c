// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
        int neili_cost;
        int lvl;
        int heal;

	if (target != me)
		return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");
	
	heal = (int)me->query("eff_jing") - (int)me->query("jing");
	if (heal < 10)
		return notify_fail("�����ھ�����ʢ��\n");

        lvl = me->query_skill("force");
        if (lvl <= 0) lvl = 1;
        neili_cost = heal * 60 / lvl;
        if (me->query("breakup"))
                neili_cost = neili_cost * 7 / 10;
        if (neili_cost < 20) neili_cost = 20;
        if (neili_cost > me->query("neili"))
        {
                neili_cost = me->query("neili");
                heal = neili_cost * lvl / 60;
        }
        if (neili_cost < 20) neili_cost = 20;

	if ((int)me->query("neili") < neili_cost)
		return notify_fail("�������������\n");

	me->add("neili", -neili_cost);
	me->receive_heal("jing", heal);
	
        message_vision("$N�������˼����������������ö��ˡ�\n", me);

        if (me->is_fighting()) me->start_busy(1);
	
	return 1;
}
