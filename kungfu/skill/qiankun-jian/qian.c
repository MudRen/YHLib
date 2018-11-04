// qian.c

#include <ansi.h>
#include <combat.h>

#define QIAN "��" HIY "Ǭ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/qiankun-jian/qian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" QIAN "��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" QIAN "��\n");

        if (me->query_skill("qiankun-jian", 1) < 100)
                return notify_fail("���Ǭ������Ϊ����������ʩչ" QIAN "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" QIAN "��\n");

        if (me->query_skill_mapped("sword") != "qiankun-jian")
                return notify_fail("��û�м���Ǭ���񽣣�����ʩչ" QIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����һչ��ʩչǬ����������������"
              + weapon->name() + HIY "бб�̳��������ʱ����"
              "һ����������â��ֱ��$n" + HIY "��ȥ��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                me->add("neili", -150);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "$n" HIR "��״��æ�񵲣�����������"
                                           "����ֻ��ȫ��һ�飬������͸�ض�����\n"
                                           NOR);
        } else
        {
                me->add("neili", -50);
                me->start_busy(3);
                msg += CYN "����" CYN "$n" CYN "һ����"
                       "Ц������һԾ���𣬱ܿ���" CYN
                       "$N" CYN "�����Ľ�����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
