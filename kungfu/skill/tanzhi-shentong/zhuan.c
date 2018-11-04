#include <ansi.h>
#include <combat.h>

#define ZHUAN "��" HIR "תǬ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string msg;

        if (userp(me) && ! me->query("can_perform/tanzhi-shentong/zhuan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHUAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tanzhi-shentong", 1) < 220)
                return notify_fail("��ĵ�ָ��ͨ������죬����ʩչ" ZHUAN "��\n");

        if ((int)me->query_skill("qimen-wuxing", 1) < 200)
                return notify_fail("�������������Ϊ����������ʩչ" ZHUAN "��\n");
 
        if (me->query_skill_mapped("finger") != "tanzhi-shentong")
                return notify_fail("��û�м�����ָ��ͨ������ʩչ" ZHUAN "��\n");

        if (me->query_skill_prepared("finger") != "tanzhi-shentong")
                return notify_fail("��û��׼����ָ��ͨ������ʩչ" ZHUAN "��\n");

        if (me->query("max_neili") < 3500)
                return notify_fail("���������Ϊ���㣬����ʩչ" ZHUAN "��\n");

        if (me->query("neili") < 800)
                return notify_fail("�����ڵ���������������ʩչ" ZHUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "��ȫ��������һָ��ָ�����ն�ʮ���޷�λ�ƹ��������"
              "���һ�����" HIR "תǬ��" HIC "��������\n" NOR;

        ap = me->query_skill("finger", 1) +
             me->query_skill("qimen-wuxing", 1) +
             me->query_skill("tanzhi-shentong", 1);

        dp = target->query_skill("force") +
             target->query_skill("parry", 1) +
             target->query_skill("qimen-wuxing", 1);

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                	me->start_busy(2);
                        msg += HIR "���Ǽ�$n" HIR "ֻ����âһ����$N" HIR "ʳָ"
                               "������$p" HIR "ӡ�ð�ߣ�ָ����ʱ���Զ��롣\n"
                               HIW "���������ۡ���һ�������Ͼ�Ȼ���������Խ���"
                               "\n" NOR "( $n" RED "���˹��أ��Ѿ�������в���"
                               "����ʱ�����ܶ�����" NOR ")\n";
                        damage = -1;
                } else
		{
                	me->start_busy(5);
                	damage = ap / 2 + random(ap);
                	me->add("neili", -500);
                	msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 100,
                        	                   HIR "���Ǽ�$n" HIR "ֻ����âһ����$N"
                                                   HIR "ʳָ������$p" HIR "���ð�ߣ�ָ��"
                                                   "��ʱ������롣\n���������͡���һ����"
                                                   "���Ͼ�Ȼ����������Ѫ��\n" NOR);
		}
        } else
        {
                me->start_busy(4);
                me->add("neili", -300);
                msg += CYN "$p" CYN "��$P" CYN "��ʽ���أ����д�"
                       "�⣬��ʱ���Ծ���ɣ�����������\n" NOR;
        }
        message_combatd(msg, me, target);

        if (damage < 0)
                target->die(me);

        return 1;
}
