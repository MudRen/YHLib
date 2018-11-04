#include <ansi.h>
#include <combat.h>

#define TIAN "��" HIC "��������" NOR "��"

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

        if (userp(me) && ! me->query("can_perform/yuxiao-jian/tian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
                return notify_fail(TIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" TIAN "��\n");

        if (me->query_skill_mapped("sword") != "yuxiao-jian")
                return notify_fail("��û�м������｣��������ʩչ" TIAN "��\n");

        skill = me->query_skill("yuxiao-jian", 1);

        if (skill < 120)
                return notify_fail("�����｣���ȼ�����������ʩչ" TIAN "��\n");

        if ((int)me->query_skill("bibo-shengong", 1) < 120)
                return notify_fail("��̲�����Ϊ����������ʩչ" TIAN "��\n");

        if (me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" TIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "һ����Х������" + weapon->name() +
              HIC "����������������ֹ����Ӱ��ҹĻ������$n" HIC "��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("force");

        if (dp < 1) dp = 1;
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -120);
                qi_wound = (int)me->query_skill("sword") +
                           (int)me->query_skill("bibo-shengong", 1);
                qi_wound = qi_wound / 2 + random(qi_wound / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, qi_wound, 66,
                                           HIR "$n" HIR "��ʱ������ǰ�����������˫������"
                                           "������ȫ���������һ�㣡\n" NOR);
                me->start_busy(1 + random(3));
        } else
        {
                me->add("neili", -50);
                msg += CYN "����$n" CYN "���ľ��������ֻ�������$N"
                       CYN "������Ʋ��һ�ߡ�\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}
