
#include <ansi.h>

inherit F_SSERVER;

#define XUAN "��" HIW "̫������" NOR "��"
 
int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i, ap, dp;
        object weapon;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/taixuan-gong/xuan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(XUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
	if ((int)me->query("neili") < 800)
		return notify_fail("��������������޷�ʩչ" XUAN "��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ��������ʹ��" XUAN "��\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("����ڹ���򲻹�������ʩչ" XUAN "��\n");

	if ((lvl = (int)me->query_skill("taixuan-gong", 1)) < 240)
		return notify_fail("���̫�����������������޷�ʹ��" XUAN "��\n");

        // δѧ����μ�������ֻ�ܼ���Ϊȭ��ʩչ ̫������
        if (! me->query("can_learned/taixuan-gong/enable_weapon"))
        {
             weapon = me->query_temp("weapon");
             if (objectp(weapon))
                     return notify_fail("�㻹û��ѧ���������̫������������������ֻ�ܿ���ʩչ��\n");

             if (me->query_skill_mapped("unarmed") != "taixuan-gong"
                 || me->query_skill_prepared("unarmed" != "taixuan-gong"))
                       return notify_fail("��û��׼��̫�������޷�ʹ��" XUAN "��\n");

        }
        else // �Ѿ�ѧ������̫������������
        {
             weapon = me->query_temp("weapon");
             // ��û�г�����ʱ�ж�ʩչ������Ҫ׼��Ϊȭ��
             if (! objectp(weapon))
             {
                    if (me->query_skill_mapped("unarmed") != "taixuan-gong"
                        || me->query_skill_prepared("unarmed" != "taixuan-gong"))
                              return notify_fail("��û��׼��̫�������޷�ʹ��" XUAN "��\n");
             }          
             // �ֳ�����������Ϊ�����߽�
             else if (objectp(weapon) && (string)weapon->query("skill_type") != "sword"
                      && (string)weapon->query("skill_type") != "blade")
                              return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" XUAN "��\n");

             if (objectp(weapon) && me->query_skill_mapped("sword") != "taixuan-gong"
                 && (string)weapon->query("skill_type") == "sword")
                              return notify_fail("�㻹û�м���̫�������޷�ʩչ" XUAN "��\n");
             
             else if (objectp(weapon) && (string)weapon->query("skill_type") == "blade"
                      && me->query_skill_mapped("blade") != "taixuan-gong")
                              return notify_fail("�㻹û�м���̫�������޷�ʩչ" XUAN "��\n");                              
                         
        }
        if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "\n��ʱ��$N" HIW "ֻ��˼����ӿ����������˫�ۣ��ٲ����$n"
              HIW "����мܣ�ֻ��ʩ�й�������ʱ���͵�ʯ���ϵ�ǧ������"
              "ʽ��ת���Ѵ�$N" HIW "�ĵ״������㣬������$n" HIW "Ϯȥ��\n" NOR;

	message_sort(msg, me, target);
	me->add("neili", -600);
        ap = me->query_skill("taixuan-gong, 1");
        dp = target->query_skill("dodge", 1);
       
        if (ap / 3 + random(ap) > dp)
                  count = ap / 8;
  
        else count = 0;

        me->add_temp("apply/attack", count);

        for (i = 0; i < 15; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);

        	COMBAT_D->do_attack(me, target, 0, i * 2);
        }
        me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(5));
	return 1;
}

