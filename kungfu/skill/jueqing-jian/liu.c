#include <ansi.h>
#include <combat.h>

#define LIU "��" HIR "��ˮ����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
  
        me = this_player();

        if (userp(me) && ! me->query("can_perform/jueqing-jian/liu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIU "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LIU "��\n");

        if ((int)me->query_skill("jueqing-jian", 1) < 60)
                return notify_fail("����齣��������죬����ʩչ" LIU "��\n");

        if (me->query_skill_mapped("sword") != "jueqing-jian")
                return notify_fail("��û�м������齣��������ʩչ" LIU "��\n");

        if ((int)me->query_skill("force") < 80 )
                return notify_fail("����ڹ���򲻹�������ʩչ" LIU "��\n");
        
        if ((int)me->query("neili") < 60)
                return notify_fail("�����ڵ���������������ʩչ" LIU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIY "\n$N" HIY "��̾һ����һ�ɱ���֮��ӿ����ͷ������" + wn +
              HIY "Ѹ���ޱȵش̳��������ಣ���ȫ�����$n" HIY "�Ĺ��ƣ�"
              "���Լ���������֮���⣬�����Ǿ���Ⱦ�ѧ��" HIR "��ˮ����" HIY
              "����" NOR; 

        message_sort(msg, me, target);
        
        ap = me->query_skill("jueqing-jian", 1);
        dp = target->query_skill("parry", 1);

        if (ap / 2 + random(ap) > dp)
        {
         	damage = ap + random(ap / 4);

         	msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 24,
                                          HIR "$n" HIR "��$N" HIR "���н���Ѹ"
                                          "�ͣ������Լ�������������һ����������"
                                          "����\n" NOR);

         	me->start_busy(1+random(2));
         	me->add("neili", -60);
        } else
        {
         	msg = CYN "Ȼ��$n" CYN "�ۼ�" + wn + CYN "��������$n"
                      CYN "��Ѹ���ޱȣ��������һ�ݣ�$N" CYN "����"
                      "���ա�\n" NOR;

         	me->start_busy(2);
         	me->add("neili", -30);
        }
        message_combatd(msg, me, target);

        return 1;
}



