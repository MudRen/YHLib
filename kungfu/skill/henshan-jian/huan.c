#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIW "�ý�ʽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
  
        me = this_player();

        if (userp(me) && ! me->query("can_perform/henshan-jian/huan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" HUAN "��\n");

        if ((int)me->query_skill("henshan-jian", 1) < 60)
                return notify_fail("���ɽ����������죬����ʩչ" HUAN "��\n");

        if (me->query_skill_mapped("sword") != "henshan-jian")
                return notify_fail("��û�м�����ɽ����������ʩչ" HUAN "��\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("����ڹ���򲻹�������ʩչ" HUAN "��\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�����ڵ���������������ʩչ" HUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIC "\n$N" HIC "���������ڽ�������Ȼ�ӿ죬����" + wn +
              HIC "�����˶������Ǽ佣����ɢ��������ã�����������" + wn +
              HIC "һ��Ϯ��$n" HIC "��" NOR;

        message_sort(msg, me, target);

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 3 + random(ap / 2);
         	msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 10,
                                          HIR "$n" HIR "�����ۻ����ң�ȴ�ֲ���"
                                          "������·������ѱ�" + wn + HIR "�̳�"
                                          "һ��������\n" NOR);
         	me->start_busy(2);
         	me->add("neili", -50);
        } else
        {
         	msg = CYN "Ȼ��$n" CYN "��δ�ܻ�������������һ��"
                      "���$N" CYN "��һ����\n" NOR;

         	me->start_busy(2);
         	me->add("neili", -30);
        }
        message_combatd(msg, me, target);

        return 1;
}



