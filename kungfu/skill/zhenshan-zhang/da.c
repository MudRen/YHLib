#include <ansi.h>
#include <combat.h>

#define DA "��" WHT "��ɽ��ţ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/zhenshan-zhang/da"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" DA "��\n");         
                
        if ((int)me->query_skill("zhenshan-zhang", 1) < 40)
                return notify_fail("�����ɽ�Ʋ�����죬����ʩչ" DA "��\n");

        if (me->query("max_neili") < 200)
                return notify_fail("����ڹ���Ϊ���㣬����ʩչ" DA "��\n");

        if (me->query_skill_mapped("strike") != "zhenshan-zhang")
                return notify_fail("��û�м�����ɽ�ƣ�����ʩչ" DA "��\n");

        if (me->query_skill_prepared("strike") != "zhenshan-zhang")
                return notify_fail("��û��׼��ʹ����ɽ�ƣ�����ʩչ" DA "��\n");

        if (me->query("neili") < 50)
                return notify_fail("����������̫��������ʩչ" DA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "�Ŷ���������һ������ʹ����ɽ��ţ��˫�ƶ�׼$n"
              WHT "ƽƽ�Ƴ���\n" NOR;
        me->add("neili", -30);

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {
                me->start_busy(3);
                target->start_busy(random(3));
                
                damage = (int)me->query_skill("force", 1);
                damage = damage / 3 + random(damage / 3);
                
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30,
                                           HIR "$n" HIR "������æ���һ�ݣ���ȴֻ��"
                                           "�ؿ�һ�𣬶�ʱ�����������ѱ�$N" HIR "��"
                                           "�����ˣ�\n:����@?");
        } else 
        {
                me->start_busy(3);
                msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ����û���ϵ���\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}

