#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIW "�һ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/xuanxu-dao/huan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUAN "��\n");

        if (me->query_skill("force") < 120)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" HUAN "��\n");

        if (me->query_skill("xuanxu-dao", 1) < 80)
                return notify_fail("������鵶����Ϊ����������ʩչ" HUAN "��\n");

        if (me->query_skill_mapped("blade") != "xuanxu-dao")
                return notify_fail("��û�м������鵶��������ʩչ" HUAN "��\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������������ʩչ" HUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʹ�����鵶���еľ����һ����������ɻ�������������ֻ"
              "�ʵ�$n" HIW "��ǰһƬӰ����\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                me->add("neili", -180);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "�����������������������죬$p" HIR "һ��"
                                           "�ҽУ�ȫ�������ͷ������һһ�ʶϣ���̲�����"
                                           "������ȥ��\n" NOR );
        } else
        {
                me->add("neili", -60);
                me->start_busy(3);
                msg += CYN "����$p" CYN "�����񵲣�$P" CYN 
                       "ֻ���þ�������˥�ߣ����е��⽥���� \n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
