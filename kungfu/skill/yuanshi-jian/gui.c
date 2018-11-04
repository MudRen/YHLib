#include <ansi.h>
#include <combat.h>

#define GUI "��" HIY "��ع�Ԫ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/yuanshi-jian/gui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(GUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" GUI "��\n");

	if ((int)me->query_skill("yuanshi-jian", 1) < 140)
		return notify_fail("���ԭʼ����������죬����ʩչ" GUI "��\n");

	if (me->query("neili") < 400)
		return notify_fail("�����������������ʩչ" GUI "��\n");

        if (me->query_skill_mapped("sword") != "yuanshi-jian")
                return notify_fail("��û�м���ԭʼ����������ʩչ" GUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIY "$N" HIY "��ת�ھ�������" + weapon->name() + HIY "��ʱ�����"
              "˸��������Ȼ��������$n" HIY "�����ȥ��\n" NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2;
                damage = damage + random(damage);

                me->add("neili", -250);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 65,
                                           HIR "ֻ��$N" HIR + weapon->name() + HIR
                                           "��â������$p" HIR "��ʱֻ��һ��������"
                                           "�Ķ�����Ż��һ����Ѫ��\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += CYN "����$n" CYN "�͵���ǰһԾ��������$N"
                       CYN "�Ĺ�����Χ��\n"NOR;
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
