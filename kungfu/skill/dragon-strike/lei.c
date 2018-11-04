#include <ansi.h>
#include <combat.h>

#define LEI "��" HIY "����һ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/dragon-strike/lei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LEI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LEI "ֻ�ܿ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("���ڹ���Ϊ����������ʩչ" LEI "��\n");

        if ((int)me->query("max_neili") < 2500)
                return notify_fail("��������Ϊ����������ʩչ" LEI "��\n");

        if ((int)me->query_skill("dragon-strike", 1) < 180)
                return notify_fail("�㽵��ʮ���ƻ�򲻹�������ʩչ" LEI "��\n");

        if (me->query_skill_mapped("strike") != "dragon-strike")
                return notify_fail("��û�м�������ʮ���ƣ�����ʩչ" LEI "��\n");

        if (me->query_skill_prepared("strike") != "dragon-strike")
                return notify_fail("��û��׼������ʮ���ƣ�����ʩչ" LEI "��\n");

        if ((int)me->query("neili") < 600)
                return notify_fail("��������������������ʩչ" LEI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "Ĭ���ڹ���ʩչ��" LEI + HIC "��ȫ����ת��������"
              "Խ��Խ�죬��\n����һ�����磬��Ȼ�䣬$N" HIC "�Ѿ�������"
              "�÷�����" HIC "$n��\n"NOR;  

        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("dodge") + target->query("dex") * 10;
        me->start_busy(3);
        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -400);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70,
                                           HIR "$p" HIR "ֻ��һ������Ӱ�ж�Ȼ�ֳ�$P"
                                           HIR "��˫ȭ��������������ܣ������ػ��У�\n��"
                                           "���������ڲ��ݣ�������Ѫ����������\n" NOR);
        } else
        {
                msg += HIG "����$p" HIG "������$P" HIG "����ͼ��û"
                       "���ܵ��Ի�������һ�ߡ�\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

