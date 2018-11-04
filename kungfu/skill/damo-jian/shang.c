#include <ansi.h>
#include <combat.h>

#define SHANG "��" HIG "��Ħ����" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/damo-jian/shang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" SHANG "��\n");

	if ((int)me->query_skill("damo-jian", 1) < 250)
                return notify_fail("���Ħ����������죬����ʩչ" SHANG "��\n");

        if (me->query_skill_mapped("sword") != "damo-jian")
                return notify_fail("��û�м�����Ħ����������ʩչ" SHANG "��\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("���������Ϊ����������ʩչ" SHANG "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" SHANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "������" + weapon->name() +
              HIG "����һ�񣬽����������죬���ν���ֱָ$n"
              HIG "����ҪѨ��\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 3);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 15,
                                           (: final, me, target, damage :));
                me->start_busy(3);
                me->add("neili", -200);
	} else
        {
		msg += CYN "����$n" CYN "�������ʹ��$P"
                       CYN "��һ��û�����κ����á�\n" NOR;
		me->start_busy(4);
                me->add("neili", -100);
	}
	message_combatd(msg, me, target);

	return 1;
}

string final(object me, object target, int damage)
{
        int lvl = me->query_skill("damo-jian", 1);

        target->affect_by("damo_shangshen",
                ([ "level"    : lvl + random(lvl),
                   "id"       : me->query("id"),
                   "duration" : lvl / 50 + random(lvl / 20) ]));

        target->receive_damage("jing", damage / 2, me);
        target->receive_wound("jing", damage / 4, me);

        return HIR "���$n" HIR "ֻ������Ѩ��һʹ����ǰһ��"
               "�ڣ�������ѣ�����Լ���ս����\n" NOR;
}
