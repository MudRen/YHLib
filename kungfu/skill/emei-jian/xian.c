#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIY "������" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/emei-jian/xian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" XIAN "��\n");

        if ((int)me->query_skill("emei-jian", 1) < 60)
                return notify_fail("��Ķ��ҽ���������죬�޷�ʩչ" XIAN "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����������������޷�ʩչ" XIAN "��\n");

        if (me->query_skill_mapped("sword") != "emei-jian") 
                return notify_fail("��û�м������ҽ������޷�ʩչ" XIAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "�粽��ǰ������" + weapon->name() +
              HIY "����ü������ת��ɣ����������ֱ����$n"
              HIY "��\n" NOR;

        me->add("neili", -75);
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        me->start_busy(3);
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 3);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
                                           (: final, me, target, damage :));
        } else
        {
                msg += HIC "��$n" HIC "ȴ������㣬һ˿���ң�"
                       "ȫ�񽫴��л��⿪����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        return  HIR "��ʱֻ�����͡���һ����$n" HIR "�Ը�������"
                "����һ��������Ѫ���졣\n" NOR;
}

