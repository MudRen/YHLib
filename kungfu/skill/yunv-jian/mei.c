#include <ansi.h>
#include <combat.h>

#define MEI "��" HIM "ǧ�˰���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, wn;
        object weapon;
        int level;
  
        me = this_player();

        if (userp(me) && ! me->query("can_perform/yunv-jian/mei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(MEI "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" MEI "��\n");

        if ((int)me->query_skill("yunv-jian", 1) < 40)
                return notify_fail("����Ů����������죬����ʩչ" MEI "��\n");

        if (me->query_skill_mapped("sword") != "yunv-jian")
                return notify_fail("��û�м�����Ů����������ʩչ" MEI "��\n");

        if ((int)me->query_skill("dodge") < 60)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" MEI "��\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�����ڵ���������������ʩչ" MEI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIC "\n$N" HIC "��Ȼ����̬��ǧ����Ʈ�ݣ�����һ�����"
              "���˵�Ů�����������һ��������$N����" + wn + HIC "ȴ"
              "������������ӯ�ػζ������ƺ����·���ȴ��������������"
              "������ʽ��" NOR;

        message_sort(msg, me, target);

        level = me->query_skill("yunv-jian", 1);
        me->add("neili", -50);
        if (level / 2 + random(level) > target->query_skill("dodge", 1))
        {
		msg = HIY "$N" HIY "������$n" HIY "��ʽ�е���ʵ����æ"
                      "��ס�Լ�ȫ��һʱ������Ӧ�ԣ�\n" NOR; 
                target->start_busy(2 + random(level / 24));
                me->start_busy(random(2));
	} else
        {
		msg = CYN "����$N" CYN "������$n" CYN "���������У���"
                      "ʱһ˿���ң���������\n" NOR;
                      
                me->start_busy(2);
	}
	message_combatd(msg, target, me);

	return 1;
}


