#include <ansi.h>
#include <combat.h>

#define ZONG "��" HIY "�����" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/rulai-zhang/zong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZONG "ֻ�ܿ���ʩչ��\n");
                
        if (me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ����������ʩչ" ZONG "��\n");

        if ((int)me->query_skill("force") < 280)
                return notify_fail("����ڹ�����㣬����ʩչ" ZONG "��\n");

        if ((int)me->query_skill("rulai-zhang", 1) < 150)
                return notify_fail("��ǧ�������ƻ�򲻹�������ʩչ" ZONG "��\n");

        if (me->query_skill_prepared("strike") != "rulai-zhang")
                return notify_fail("��û��׼��ǧ�������ƣ�����ʩչ" ZONG "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" ZONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "\n$N" HIY "���¸������飬�ߺ���ţ���ƮƮ�ĳ�һ�ƣ���ʽ"
              "��ΪѰ�������Ƶ���;����Ȼ΢΢ҡ�Σ���ʱһ�Ʊ����ƣ����Ʊ���"
              "�ƣ����Ʊ���ƣ�����ǵ�����$n" HIY "��" NOR;

        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("parry") + target->query("dex") * 10;

        if (ap / 2 + random(ap) > dp)
        {
                // ���ӵ�йٴ̼�:)
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        me->start_busy(1);
		        me->add("neili", -100);
                        msg += HIY "�漴����$N" HIY "�����ȵ�����" HIR "�ҷ�����" HIY
                               "����̼䣬����$N" HIY "�����ֱ�Ϊʮ���ƣ������ٻû�Ϊ"
                               "��ʮ���ƣ����Ʋ�����������׳�������ư��磬�����س�"
                               "���纣������$n" HIY "ӿȥ��\n\n" HIR "$n" HIR "�����"
                               "�����޾������ƣ���Ȼ�����˵ֿ��������������Դ��С�\n" NOR;

		        message_sort(msg, me, target);
		        me->add_temp("apply/attack", ap);
		        me->add_temp("rulai-zhang/hit_msg", 1);
		        for (i = 0; i < 32; i++)
        		{
		                if (! me->is_fighting(target))
                	        break;
                		if (random(5) < 2 && ! target->is_busy())
                        	target->start_busy(1);

                		COMBAT_D->do_attack(me, target, 0, 0);
        		}
		        me->add_temp("apply/attack", -ap);
		        me->delete_temp("rulai-zhang/hit_msg");
        		return 1;
                } else
		{
                	count = ap / 6;
                	msg += HIR "\n$n" HIR "�����Ʋ����������纣����һʱ"
                               "ֻ��ͷ��Ŀѣ�������ֵ���\n" NOR;
		}
        } else
        {
                msg += HIC "\n$n" HIC "�����Ʋ����������纣������æ"
                       "����������ǿ�ֵ���\n" NOR;
                count = 0;
        }

        message_sort(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add_temp("rulai-zhang/hit_msg", 1);
        me->add("neili", -300);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(8));
        me->add_temp("apply/attack", -count);
        me->delete_temp("rulai-zhang/hit_msg");
        return 1;
}
