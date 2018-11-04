#include <ansi.h>
#include <combat.h>

#define QIAN "��" HIY "Ǭ��һ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/jinyuan-gun/qian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" QIAN "��\n");

        if (me->query_skill("force") < 180)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" QIAN "��\n");

        if (me->query_skill("jinyuan-gun", 1) < 120)
                return notify_fail("��Ľ�Գ������Ϊ����������ʩչ" QIAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" QIAN "��\n");

        if (me->query_skill_mapped("club") != "jinyuan-gun")
                return notify_fail("��û�м�����Գ����������ʩչ" QIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����ǰ��ŭ��һ��������" + weapon->name() +
              HIY "�����趯����ʱ���ɳ��ʯ�����������\n���ڿ�ɳ쫷���"
              "��$N" HIY "��Ȼ�߸�Ծ��ӭͷһ����$n" HIY "���䣡\n" NOR;

        ap = me->query_skill("club");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap * 2 / 3);
                me->add("neili", -150);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 35,
                                           HIR "$n" HIR "�����������֣��Ǹ���Ϣ"
                                           "�����ۡ����³�һ����Ѫ������㵹��\n" NOR);
        } else
        {
                me->add("neili", -100);
                me->start_busy(3);
                msg += CYN "$n" CYN "������˿�����⣬��æ�����Ծ����"
                       "�������ԶϽ���ʯ��һ����\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
