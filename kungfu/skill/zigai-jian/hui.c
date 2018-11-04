#include <ansi.h>
#include <combat.h>

#define HUI "��" HIC "�ϸǻ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
  
        me = this_player();

        if (userp(me) && ! me->query("can_perform/zigai-jian/hui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" HUI "��\n");

        if ((int)me->query_skill("zigai-jian", 1) < 120)
                return notify_fail("���ϸǽ���������죬����ʩչ" HUI "��\n");

        if (me->query_skill_mapped("sword") != "zigai-jian")
                return notify_fail("��û�м����ϸǽ���������ʩչ" HUI "��\n");

        if ((int)me->query_skill("force") < 150 )
                return notify_fail("����ڹ���򲻹�������ʩչ" HUI "��\n");
        
        if ((int)me->query_skill("dodge") < 120)
                return notify_fail("����Ṧ��򲻹�������ʩչ" HUI "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�����ڵ���������������ʩչ" HUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIY "\n$N" HIY "����ת�����һ�ݣ��������ߣ�$n" HIY "�˻�ͦ"
              "����ǰ��" HIY "�ۼ�$n" HIY "��\n�����֣�����$N" HIY "���"
              "�����̣�" + wn + HIY "ֱָ$n" HIY "��" NOR;

        message_sort(msg, me, target);
        
        ap = me->query_skill("zigai-jian", 1);
        dp = target->query_skill("dodge", 1);

        if (ap / 2 + random(ap) > dp)
        {
         	damage = ap + random(ap / 2);

         	msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 45,
                                          HIR "$n" HIR "����һ������֪�мƣ���"
                                          + wn + HIR "ͻ������Ѹ���ޱȣ���Ȼ��"
                                          "�ܲ�����\n" NOR);

         	me->start_busy(2);
         	me->add("neili", -100);
        } else
        {
         	msg = CYN "Ȼ��$n" CYN "�ۼ�" + wn + CYN "��������$n"
                      CYN "��Ѹ���ޱȣ��������һ�ݣ�$N" CYN "����"
                      "���ա�\n" NOR;

         	me->start_busy(3);
         	me->add("neili", -50);
        }
        message_combatd(msg, me, target);

        return 1;
}



