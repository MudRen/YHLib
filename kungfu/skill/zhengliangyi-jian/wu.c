#include <ansi.h>
#include <combat.h>

#define WU "��" HIW "������ɫ" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/zhengliangyi-jian/wu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (environment(me)->query("no_fight"))
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        // ִ��������������ⷿ���ֹ�����жϾ��顣
        if (environment(me)->query("skybook"))
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if (! target || ! target->is_character()
           || target->query("not_living"))
                return notify_fail(WU "ֻ�ܶԶ���ʹ�á�\n");

        if (target == me)
                return notify_fail("����㹥���Լ���\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" WU "��\n");

        if ((int)me->query_skill("zhengliangyi-jian", 1) < 160)
                return notify_fail("��������ǽ���������죬����ʩչ" WU "��\n");

        if ((int)me->query_skill("dodge") < 220)
                return notify_fail("����Ṧ����㣬����ʩչ" WU "��\n");

        if (me->query_dex() < 45)
                return notify_fail("��������̫�����ʩչ" WU "��\n");

        if (me->query("neili") < 200)
                return notify_fail("��������������������ʩչ" WU "��\n");

        if (me->query_skill_mapped("sword") != "zhengliangyi-jian") 
                return notify_fail("��û�м��������ǽ���������ʩչ" WU "��\n");

        if ((int)target->query_condition("die_guard"))
                return notify_fail("�Է������ٸ��������أ����Ǳ�ȥ���ǡ�\n");

        if (target->query_competitor())
                return notify_fail("�����ʱ���������������Ľ�����\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ����Ц��ͻȻʹ��һ�С�������ɫ��������$n"
              HIW "�����ȥ��\n" NOR;

        me->add("neili", -200);
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        me->start_busy(2);
        if (ap / 2 + random(ap) > dp)
        {
                damage = ap * 2 / 3 + random(ap / 3);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
                                           (: final, me, target, damage :));
        } else
        {
                msg += HIC "����$p" HIC "������$P" HIC "����ͼ������"
                       "һԾ���𣬽�$P" HIC "���л��������Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);
        me->want_kill(target);

        if (! target->is_killing(me))
                target->kill_ob(me);
        return 1;
}

string final(object me, object target, int damage)
{
        object weapon;
        weapon = me->query_temp("weapon");

        return  HIW "���$n" HIW "��û�в��$N" HIW "��ɱ�⣬˿��û��"
                "��һ�з������ϣ�ֻ\n��������΢����ǰһ�㡣\n" NOR +
                HIR "��ʱֻ��$N" HIR "����һ������ʱֻ����������һ��"
                "�ƿ�֮�죬$n" HIR "\nһ���Һ���" + weapon->name() +
                HIR "������͸�����롣\n" NOR;
}

