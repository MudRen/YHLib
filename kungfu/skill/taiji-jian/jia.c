#include <ansi.h>
#include <combat.h>

#define JIA "��" HIC "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon, weapon2;
        int skill, ap, dp, damage;
        string wn1, wn2, msg;

        if (userp(me) && ! me->query("can_perform/taiji-jian/jia"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(JIA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" JIA "��\n");

        skill = me->query_skill("taiji-jian", 1);

        if (skill < 150)
                return notify_fail("���̫�������ȼ�����������ʩչ" JIA "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" JIA "��\n");
 
        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("��û�м���̫������������ʩչ" JIA "��\n");

        if (! objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("�Է�û��ʹ�ñ���������ʩչ" JIA "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn1 = weapon->name();
        wn2 = weapon2->name();

        msg = HIC "ֻ��$N" HIC "���������Խ����˽�������" + wn1 + HIC "ÿ�����Ի���"
              "�̳��������ջأ�ÿ��һ�ж��Ʒ�\n��һ��ϸ˿��Ҫȥ����$n" HIC "��" + wn2 +
              HIC "֮�ϡ�\n" NOR;
        me->add("neili", -50);

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap * 4 / 3) > dp)
        {
                me->add("neili", -30);
                damage = ap / 8 + random(ap / 8);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 10,
                                           HIR "ȴ��$n" HIR "����" + wn2 + HIR "��" +
                                           wn1 + HIR "��ס�󲻶����������������ټ�ɬ"
                                           "�ͣ��������ɿ�к������\n" NOR);
                me->start_busy(1);
                if (ap / 2 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 30 + 2);
        } else
        {
                msg += CYN "$n" CYN "������ʧɫ����æԾ�����������Ű���$N"
                       CYN "��������\n" NOR;
                me->add("neili", -10);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
