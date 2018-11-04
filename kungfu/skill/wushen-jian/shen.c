#include <ansi.h>
#include <combat.h>

#define SHEN "��" HIM "����Ԫ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
        me = this_player();

        if (userp(me) && ! me->query("can_perform/wushen-jian/shen"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHEN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHEN "��\n");

        if ((int)me->query_skill("wushen-jian", 1) < 240)
                return notify_fail("���ɽ���񽣲�����죬����ʩչ" SHEN "��\n");

        if (me->query_skill_mapped("sword") != "wushen-jian")
                return notify_fail("��û�м�����ɽ���񽣣�����ʩչ" SHEN "��\n");

        if ((int)me->query_skill("force", 1) < 220)
                return notify_fail("����ڹ���򲻹�������ʩչ" SHEN "��\n");

        if ((int)me->query_skill("dodge", 1) < 200)
                return notify_fail("����Ṧ��򲻹�������ʩչ" SHEN "��\n");  

        if ((int)me->query("max_neili") < 5500)
                return notify_fail("���������Ϊ���㣬����ʩչ" SHEN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" SHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIM "\n$N" HIM "һ��ŭ�ȣ��ھ����ǣ�����" + wn +
              HIM "�����ǧ�����Ǽ仯��������̰�������⣬��"
              "����$P����ر�죬���Ž���ͬʱ����" HIR
              "ף��" HIM "������" HIY "�ϸ�" HIM "������" NOR
              WHT "ʯ��" HIM "������" HIG "ܽ��" HIM "������"
              HIW "����" HIM "�����׽�������ʹ��������ʯ��"
              "��Ϯ��$n" HIM "ȫ��" NOR;

        message_sort(msg, me, target);
        
        ap = me->query_skill("wushen-jian", 1) +
             me->query_skill("martial-cognize", 1);

        dp = target->query_skill("dodge", 1) +
             target->query_skill("martial-cognize", 1);

        if (ap * 2 / 3 + random(ap) > random(dp))
        {
                damage = me->query_skill("wushen-jian", 1) +
                         me->query_skill("force", 1) +
                         me->query_skill("martial-cognize", 1);

                damage += random(damage / 2);

                // ���֮һ�ļ��ʿɱ��м�
                if (random(10) <= 1 && ap / 2 < dp)
                {
                        damage = damage / 3;

                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
                                                  HIG "\n$n" HIG "��$N" HIG "������⽣��"
                                                  "���ˣ���æ������������мܡ���֪$P��"
                                                  "�������Ƿ���$pһ���ƺߣ����˼�������"
                                                  "��һ����Ѫ��\n" NOR);
                        me->add("neili", -200);
                        me->start_busy(3 + random(2));
                } else 
                {
                        msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 100 + random(10),
                                                  HIR "\n$n" HIR "��$N" HIR "��������ͷ�"
                                                  "���䣬�����ݺᣬ��Х�����Լ�Ϯ������"
                                                  "�ײ��ɴ󾪣���ʱ���á����͡�һ������"
                                                  "��͸�������\n" NOR);
                        me->add("neili", -300);
                        me->start_busy(3 + random(3));
                }
        } else
        {
                msg = CYN "\nȻ��$n" CYN "�Կ�Կ죬����һ��"
                      "��Ȼ���$N" CYN "��һ�С�\n" NOR;
                me->add("neili", -150);
                me->start_busy(3);
        }
        message_sort(msg, me, target);
        return 1;
}
