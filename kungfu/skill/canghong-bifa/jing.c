#include <ansi.h>
#include <combat.h>

#define JING "��" HIM "����һ��" NOR "��"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/canghong-bifa/jing"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(JING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" JING "��\n");

        skill = me->query_skill("canghong-bifa", 1);

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" JING "��\n");

        if (me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" JING "��\n");

        if (skill < 100)
                return notify_fail("��Ժ�ʷ���Ϊ���ޣ�����ʩչ" JING "��\n");

        if (me->query_skill_mapped("dagger") != "canghong-bifa")
                return notify_fail("��û�м����Ժ�ʷ�������ʩչ" JING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "����" + weapon->name() + HIM "�󿪴�ϣ�����������"
              "�գ��Ѳ�����������һ������������$n" HIM "��\n" NOR;
 
        ap = me->query_skill("dagger");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -200);
                damage = 100 + ap / 3 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "��ʱֻ���á����͡�һ����$n" HIR
                                           "�ؿڱ�$N" HIR "һ�ʴ��У�����һ����Ѫ��\n" NOR);
                me->start_busy(1);
                if (ap / 3 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(ap / 25 + 1);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN
                       "����ʽ�������һһ��⣬û¶���"
                       "������\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
