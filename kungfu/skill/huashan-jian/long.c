// feilong.c ��ɽ���������������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define LONG "��" HIY "�������" NOR "��"

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/huashan-jian/long"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LONG "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�\n");

        if ((int)me->query_skill("huashan-jian", 1) < 150)
                return notify_fail("�㻪ɽ����������죬�޷�ʩչ" LONG "��\n");

        if ((int)me->query_skill("force") < 150 )
                return notify_fail("���ڹ���򲻹����޷�ʩչ" LONG "��\n");

        if ((int)me->query("neili") < 220)
                return notify_fail("�����������������޷�ʩչ" LONG "��\n");

        if (me->query_skill_mapped("sword") != "huashan-jian")
                return notify_fail("��û�м�����ɽ�������޷�ʩչ" LONG "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "���������һ�������������̽����˾��ڱۣ���"
              "��һ����$n" HIC "���˳�ȥ��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");
        if (ap > dp / 2 * 3 && ap / 2 + random(ap) > dp)
        {
                me->start_busy(3);
                damage = target->query("max_qi") / 4 + ap;
                damage += random(damage / 4);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                           HIR "$n" HIR "��æԾ�𣬵����������ֻ��һ���ʹ������"
                                           "������������Ѫ�ɽ���Ƥ�����\n" NOR);
                me->add("neili", -200);
        } else
        {
                me->start_busy(3);
                msg += CYN "Ȼ��$n" CYN "����һЦ��������ָ������"
                       "��$N" CYN "�Ľ����ϣ���б����ء�\n" NOR;
                me->add("neili", -120);
        }

        weapon->move(environment(me));
        message_combatd(msg, me, target);
        return 1;
}
