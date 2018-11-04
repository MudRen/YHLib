// mie.c  �ط�����������𽣡�

#include <ansi.h>
#include <combat.h>

#define MIE "��" HIR "��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (userp(me) && ! me->query("can_perform/huifeng-jian/mie"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(MIE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ��޷�ʩչ" MIE "��\n");

        if (me->query_skill_mapped("sword") != "huifeng-jian")
                return notify_fail("��û�м����ط�����������޷�ʩչ" MIE "��\n");

        if ((int)me->query_skill("huifeng-jian", 1) < 120)
                return notify_fail("��Ļط��������������죬�޷�ʩչ" MIE "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���򲻹����޷�ʩչ" MIE "��\n");

        if ((int)me->query("neili") < 500)
               return notify_fail("�����������������޷�ʩչ" MIE "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥"
              "���ƽ�$n" HIR "��\n$n" HIR "�������콣�⣬�����Ծ������ֻ��һɲ"
              "��$N" HIR "���콣Ӱ��Ϊһ��ֱ\n��$n" HIR "ǰ�أ�������ף�ֻ��һ"
              "����\n" NOR;

        if (random(me->query_skill("force")) > target->query_skill("force") / 2 ||
            random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
                me->start_busy(2);
                damage = (int)me->query_skill("huifeng-jian", 1);
                damage += random(damage);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
                                           HIR "$n" HIR "ȫȻ�޷���ܣ�" + weapon->name() +
                                           HIR "�˶�����������$p" HIR "���ؿڣ���Ѫ��ʱ�ɽ�"
                                           "������\n" NOR);
                me->add("neili", -150);
        } else
        {
                me->start_busy(3);
                msg += YEL "����$p" YEL "����һЦ��������ת����"
                       "����ָ��������$P" YEL "�Ľ��ϣ�" + weapon->name() +
                       YEL "��$p" YEL "��໮�����о����ա�\n"NOR;
                me->add("neili", -60);
        }
        message_combatd(msg, me, target);
        return 1;
}
