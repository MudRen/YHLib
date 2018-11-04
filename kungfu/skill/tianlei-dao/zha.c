#include <ansi.h>
#include <combat.h>

#define ZHA "��" HIY "����ը��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
  
        me = this_player();

        if (userp(me) && ! me->query("can_perform/tianlei-dao/zha"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHA "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "blade")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" ZHA "��\n");

        if ((int)me->query_skill("tianlei-dao", 1) < 150)
                return notify_fail("�����׾���������죬����ʩչ" ZHA "��\n");

        if (me->query_skill_mapped("blade") != "tianlei-dao")
                return notify_fail("��û�м������׾���������ʩչ" ZHA "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHA "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" ZHA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIW "\n$N" HIW "һ��ŭ�ȣ��ھ����ǣ�ʩչ�����С�" HIY "����ը��" HIW 
              "������" + wn + HIW "�����Ļ���������������ˣ���������һ�㡣" NOR;

        message_sort(msg, me, target);

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
         	msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 65,
                                          HIR "$n" HIR "��$N" HIR "�������ͣ���"
                                          "����˸��������������һ����һ����Ѫ" 
                                          "��ӿ������\n" NOR);
         	me->start_busy(2 + random(4));
         	me->add("neili", -240);
        } else
        {
         	msg = CYN "Ȼ��$n" CYN "�Կ��ƿ죬����"
                      "һ����������С�\n" NOR;

         	me->start_busy(2);
         	me->add("neili", -180);
        }
        message_combatd(msg, me, target);

        return 1;
}



