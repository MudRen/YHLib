#include <ansi.h>
#include <combat.h>

#define RIYUE "��" HIY "����Ǭ��" NOR "��"

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

        if (userp(me) && ! me->query("can_perform/qiankun-jian/riyue"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(RIYUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" RIYUE "��\n");

        if (me->query_skill("force") < 220)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" RIYUE "��\n");

        if (me->query_skill("qiankun-jian", 1) < 150)
                return notify_fail("���Ǭ������Ϊ����������ʩչ" RIYUE "��\n");

        if (me->query("neili") < 400)
                return notify_fail("�����������������ʩչ" RIYUE "��\n");

        if (me->query_skill_mapped("sword") != "qiankun-jian")
                return notify_fail("��û�м���Ǭ���񽣣�����ʩչ" RIYUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "ֻ��$N" HIY "����" + weapon->name() + HIY
              "һ������Ǭ����������ʩ������ʱ�ó�������Ӱ��"
              "����ǵ���$n" HIY "ϯ���ȥ��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        attack_time = 4;

        if (ap / 2 + random(ap * 2) > dp)
        {
                msg += HIR "$n" HIR "ֻ����Ӱ���أ���ʱ�ۻ���"
                       "�ң������˸����ֲ�����ƣ�ڱ�����\n" NOR;
                count = ap / 10;
                me->add_temp("apply/attack", count);
                attack_time += random(ap / 45);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "������ӿ����"
                       "�ƻֺ룬��æ���������С��Ӧ����\n"
                       NOR;
                count = 0;
        }
                
        message_combatd(msg, me, target);

        if (attack_time > 6)
                attack_time = 6;

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
