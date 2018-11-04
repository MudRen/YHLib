#include <ansi.h>
#include <combat.h>

#define HAO "��" HIW "��´���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
  
        me = this_player();

        if (userp(me) && ! me->query("can_perform/chuanyue/hao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HAO "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" HAO "��\n");

        if ((int)me->query_skill("chuanyue-jian", 1) < 120)
                return notify_fail("�����׽���������죬����ʩչ" HAO "��\n");

        if (me->query_skill_mapped("sword") != "chuanyue-jian")
                return notify_fail("��û�м������׽���������ʩչ" HAO "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" HAO "��\n");

        if ((int)me->query("neili") < 400)
                return notify_fail("�����ڵ���������������ʩչ" HAO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                           
        msg = HIY "\n$N" HIY "������" + wn + HIY "��ת���ܣ�Ȼ��"
              "�͵��ڿն���ʩ�����С�" HIW "��´���" HIY "����"
              "�����ӫӫ�ҳ��գ�����ӯӯնȺ�ۡ��������н�����"
              "�ǣ����ư��磬���ֱ�£�Ϯ��$n\n " HIY "��" NOR;

        message_sort(msg, me, target);

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
         	msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 48,
                                          HIR "$n" HIR "ֻ��һ������Ӱ��Ϯ����"
                                          "���о������ѣ�����Ѫ�Ѵ�$n�ؿ������\n" 
                                          NOR);
         	me->start_busy(2 + random(4));
         	me->add("neili", -200);
        } else
        {
         	msg = CYN "Ȼ��$n" CYN "�����ֿ죬����һ��"
                      "���$N" CYN "��һ����\n" NOR;

         	me->start_busy(2);
         	me->add("neili", -180);
        }
        message_vision(msg, me, target);

        return 1;
}



