#include <ansi.h>
#include <combat.h>

#define CHU "��" HIW "ѩ������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/xueshan-jian/chu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHU "��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" CHU "��\n");

        if (me->query_skill("xueshan-jian", 1) < 140)
                return notify_fail("���ѩɽ������Ϊ����������ʩչ" CHU "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" CHU "��\n");

        if (me->query_skill_mapped("sword") != "xueshan-jian")
                return notify_fail("��û�м���ѩɽ����������ʩչ" CHU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����" + weapon->name() + HIW
              "����������һ�С�ѩ����������������ʵ��ʵ����"
              "�飬����˷���$n" HIW "��ȥ��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        attack_time = 6;

        if (ap / 2 + random(ap * 2) > dp)
        {
                msg += HIR "$n" HIR "ֻ����Ӱ���أ���ʱ�ۻ���"
                       "�ң������˸����ֲ�����ƣ�ڱ�����\n" NOR;
                count = ap / 10;
                me->add_temp("apply/attack", count);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "������ӿ����"
                       "��Ϯ�壬��æ���������С��Ӧ����\n"
                       NOR;
                count = 0;
        }
        message_combatd(msg, me, target);

        me->add("neili", -attack_time * 20);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(attack_time));
        return 1;
}
