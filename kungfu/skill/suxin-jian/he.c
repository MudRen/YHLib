#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("˫�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ�������죬����ʹ��˫����赡�\n");

        if ((int)me->query_skill("suxin-jian", 1) < 80)
                return notify_fail("�����Ů���Ľ�������죬����ʹ��˫����赡�\n");

        if ((int)me->query_skill("quanzhen-jian", 1) < 50)
                return notify_fail("���ȫ�潣��������죬����ʹ��˫����赡�\n");

        if ((int)me->query("neili", 1) < 400)
                return notify_fail("����������̫��������ʹ��˫����赡�\n");

        if (me->query_skill_mapped("sword") != "suxin-jian")
                return notify_fail("��û�м�����Ů���Ľ�������ʹ��˫����赡�\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "������ȫ�潣�����⣬���ֻ���Ů������"
              "�У�˫�����ͬʱ�̳���\n" NOR;

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                me->start_busy(2);

                damage = (int)me->query_skill("sword", 1) +
                         (int)me->query_skill("quanzhen-jian", 1) +
                         (int)me->query_skill("yunv-jian", 1);

                damage = damage / 2 + random(damage / 2);
                me->add("neili", -350);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 65,
                                           HIR "$n" HIR "����$N" HIR "˫�����裬��ʽ������"
                                           "������Ϊ��һ����ȥ������֪����Ǻã�\n"
                                           HIR"һ��֮�£�$N" HIR "�Ľ����Ѿ���ʽ���룡$n"
                                           HIR "һ���ҽ�֮�£���ʱ�����ش���\n" NOR);
        } else
        {
                me->start_busy(3);
                msg += CYN "����$p" NOR CYN "������$P" NOR CYN "����ͼ����"
                       "�Լ���ȫ�����»����ܲ�͸�磬��$P" NOR CYN "�޼ƿ�ʩ��\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
