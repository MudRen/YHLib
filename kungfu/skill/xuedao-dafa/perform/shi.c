#include <ansi.h>
#include <combat.h>

#define SHI "��" HIR "��Ѫ��" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int ap, dp, damage;
        int i, count;

        if (userp(me) && ! me->query("can_perform/xuedao-dafa/shi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(SHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHI "��\n");

	if ((int)me->query_skill("force") < 250)
		return notify_fail("����ڹ���򲻹�������ʩչ" SHI "��\n");

	if ((int)me->query_skill("xuedao-dafa", 1) < 180)
		return notify_fail("���Ѫ���󷨻������ң�����ʩչ" SHI "��\n");

        if (me->query_skill_mapped("force") != "xuedao-dafa")
                return notify_fail("��û�м���Ѫ����Ϊ�ڹ�������ʩչ" SHI "��\n");

        if (me->query_skill_mapped("blade") != "xuedao-dafa")
                return notify_fail("��û�м���Ѫ����Ϊ����������ʩչ" SHI "��\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("��Ŀǰ��Ѫ����������ʩչ" SHI "��\n");

	if ((int)me->query("neili") < 500)
                return notify_fail("��Ŀǰ�������㣬����ʩչ" SHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("blade") + me->query("str") * 10;
        dp = target->query_skill("dodge") + target->query("dex") * 10;

        msg = HIY "$N" HIY "��Ȼʩ����" HIR "��Ѫ��" HIY "��������" +
              weapon->name() + HIY "�����ޱ�ɱ�⣬Я�ŷ���֮����$n" HIY
              "��ն��ȥ��\n"NOR;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 75,
                                           HIR "$n" HIR "ֻ����ǰһ��Ѫ����������"
                                           "���ѱ�$N" HIR "��һ�����˸����С�\n" NOR);
        } else
        {
                msg += CYN "$p" CYN "ֻ��$P" CYN "������ӿ�����Եֵ�����"
                       "��������Ծ�����ߡ�\n" NOR;
        }

        msg += HIY "\n������$N" HIY "��Ŀ��ȣ�����" + weapon->name() +
               HIY "һ�񣬱ų�����Ѫ�⣬����ǵ�����$n" HIY "��\n"NOR;

        if (random(me->query_skill("blade")) > target->query_skill("parry") / 2)
        {
                msg += HIR "��ʱ��$n" HIR "ֻ����Χɱ��������ȫ����Ѫ��"
                       "���������мܡ�\n" NOR;
                count = me->query_skill("xuedao-dafa", 1) / 4;
        } else
        {
                msg += HIY "��ʱ��$n" HIY "ֻ����Χɱ���������ĵ�΢΢һ"
                       "������æ�����мܡ�\n" NOR;
                count = 0;
        }
	message_combatd(msg, me, target);

        me->add_temp("apply/attack", count);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);

        	COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->receive_wound("qi", 80);
        me->add_temp("apply/attack", -count);
	me->start_busy(3 + random(5));
        me->add("neili", -200 - random(300));
	return 1;
}
