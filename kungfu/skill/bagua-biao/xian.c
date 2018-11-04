#include <ansi.h>
#include <combat.h>

#define XIAN "��" HIY "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object anqi;
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/bagua-biao/xian"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(XIAN "ֻ�ܿ���ʩչ��\n");

        if (! objectp(anqi = me->query_temp("handing"))
           || (string)anqi->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����Ű�����\n");

        if (me->query_skill_mapped("strike") != "bagua-zhang") 
                return notify_fail("��û�м��������ƣ�����ʩչ" XIAN "��\n");

        if (me->query_skill_prepared("strike") != "bagua-zhang") 
                return notify_fail("��û��׼�������ƣ�����ʩչ" XIAN "��\n");

        if (me->query_skill_mapped("throwing") != "bagua-biao") 
                return notify_fail("��û�м��������ھ�������ʩչ" XIAN "��\n");

        if ((int)me->query_skill("bagua-zhang", 1) < 120)
                return notify_fail("��İ����Ʋ�����죬����ʩչ" XIAN "��\n");

        if ((int)me->query_skill("bagua-biao", 1) < 120)
                return notify_fail("��İ����ھ�������죬����ʩչ" XIAN "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ" XIAN "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ" XIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "ͻȻֻ��$N" HIY "�ȵ�����$n" HIY "���У���"
              "˵�굥��һ���׶�ʱ�ܳ�һ����⣬ֱ��$n" HIY
              "��ȥ��\n" NOR;

        ap = me->query_skill("strike", 1) +
             me->query_skill("throwing");

        dp = target->query_skill("dodge", 1) +
             target->query_skill("parry", 1);

        me->start_busy(3);
        if (anqi->query_amount() > 0)anqi->add_amount(-1);

        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap / 3 + random(ap / 2);
                me->add("neili", -100);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIY "��ֻ��$n" HIY "����һЦ������һ��"
                                           "�����˹�ȥ��\n" NOR + HIR "��֪���ŵ�"
                                           "�����������У���$p" HIR "��Ӧʱ$N" HIR
                                           "������ǰ��˫����ʩ�����ص�ӡ��$n" HIR
                                           "��ǰ��\n" NOR);
        } else
        {
                msg += HIY "����$p" HIY "������$P" HIY "����ͼ��û"
                       "���ܵ��Ի����ֽ�����ȫ������������\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
