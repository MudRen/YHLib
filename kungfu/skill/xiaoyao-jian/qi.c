#include <ansi.h>
#include <combat.h>

#define LUO "��" HIW "�潣��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
  
        me = this_player();

        if (userp(me) && ! me->query("can_perform/xiaoyao-jian/qi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LUO "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LUO "��\n");

        if ((int)me->query_skill("xiaoyao-jian", 1) < 160)
                return notify_fail("����ң����������죬����ʩչ" LUO "��\n");

        if (me->query_skill_mapped("sword") != "xiaoyao-jian")
                return notify_fail("��û�м�����ң����������ʩչ" LUO "��\n");

        if ((int)me->query_skill("force", 1) < 160)
                return notify_fail("����ڹ���򲻹�������ʩչ" LUO "��\n");

        if (me->query("max_neili") < 2200)
                return notify_fail("��������Ϊ���㣬����ʩչ" LUO "��\n");

        if ((int)me->query("neili") < 350)
                return notify_fail("�����ڵ���������������ʩչ" LUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIW "\n$N" HIW "��" + wn + HIW "бָ���գ��͵ط���Ծ��"
              + wn + HIW "������ң�Ʈ����������Ȼ���ƿճ��죬" + wn + HIW
              "ֱָ��$n" HIW "�ʺ���������ң����֮��" HIG "�潣��" HIW "����"
              "���������о��棬�����ޱȡ�" NOR;

        message_sort(msg, me, target);

        ap = me->query_skill("sword") + me->query_skill("dodge");
        dp = target->query_skill("parry") + target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 4);

         	msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 78,
                                          HIR "$n" HIR "ֻ��һ�����Ӱ��Ϯ����"
                                          "���о������ѣ�����Ѫ�Ѵ�$n�ؿ������\n" 
                                          NOR);
         	me->start_busy(2 + random(4));
         	me->add("neili", -300);
        } else
        {
         	msg = CYN "Ȼ��$n" CYN "�����ֿ죬����һ��"
                      "���$N" CYN "��һ����\n" NOR;

         	me->start_busy(2);
         	me->add("neili", -200);
        }
        message_combatd(msg, me, target);

        return 1;
}



