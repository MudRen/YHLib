#include <ansi.h>
#include <combat.h>

#define BASHI "��" HIY "��ʽ��һ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int count,d_count,qi, maxqi, skill;

        if (userp(me) && ! me->query("can_perform/jinding-zhang/bashi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(BASHI "ֻ����ս���жԶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(BASHI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�������������������ʩչ" BASHI "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" BASHI "��\n");

        if ((int)me->query_skill("jinding-zhang", 1) < 100)
                return notify_fail("��Ľ����Ƶ���ϰ����������ʩչ" BASHI "��\n");

        if (me->query_skill_mapped("strike") != "jinding-zhang")
                return notify_fail("��û�м��������ƣ�����ʩչ" BASHI "��\n");

        if (me->query_skill_prepared("strike") != "jinding-zhang")
                return notify_fail("������û��׼��ʹ�ý����ƣ�����ʩչ" BASHI "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "��������һ����������ȫ��Ĺ�����"
              "˫�������ĳ���ֻ���ù���һ���죡\n" NOR;
        if (random(me->query_skill("strike")) > (int)target->query_skill("force") / 2)
        {
                damage  = (int)me->query_skill("linji-zhuang", 1);
                damage += (int)me->query_skill("jinding-zhang", 1);
                damage /= 3;
                damage += random(damage);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "ֻ��������ӰƮ������������$n" HIR
                                           "ȫ�������λ��$n" HIR "��ʱ����������"
                                           "�ƣ�\n" NOR);
                me->add("neili", -100);
                me->start_busy(2);
         } else
         {
                msg += CYN "����$p" CYN "�͵����һԾ��������$P"
                       CYN "�Ĺ�����Χ��\n" NOR;
                me->start_busy(3);
         }
         message_combatd(msg, me, target);
         return 1;
}
