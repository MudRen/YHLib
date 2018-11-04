#include <ansi.h>
#include <combat.h>

#define ZHEN "��" HIW "��豹���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int i, ap, dp;
        object weapon;

        if (userp(me) && ! me->query("can_perform/guzhuo-zhang/zhen"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail(ZHEN "ֻ�ܿ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("���ڹ���Ϊ����������ʩչ" ZHEN "��\n");

        if ((int)me->query("max_neili") < 3600)
                return notify_fail("��������Ϊ����������ʩչ" ZHEN "��\n");

        if ((int)me->query_skill("guzhuo-zhang", 1) < 220)
                return notify_fail("���׾�Ʒ���򲻹�������ʩչ" ZHEN "��\n");

        if (me->query_skill_mapped("strike") != "guzhuo-zhang")
                return notify_fail("��û�м�����׾�Ʒ�������ʩչ" ZHEN "��\n");

        if (me->query_skill_prepared("strike") != "guzhuo-zhang")
                return notify_fail("��û��׼����׾�Ʒ�������ʩչ" ZHEN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������������ʩչ" ZHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "��Ȼ��$N" HIW "ʩ����" HIY "�" HIW "���־���˫����$n"
              HIW "ƽƽ��ȥ��������ʵ�޻������ް�㻨�ɿ��ԡ�\n" NOR;  

        ap = me->query_skill("strike") + me->query("int") * 8;
        dp = target->query_skill("force") + target->query("int") * 8;

        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70,
                                           HIR "$n" HIR "���Ʋ�͸������ʵ��$N" HIR
                                           "˫������$p" HIR "ǰ�أ������꿦�ꡱ��"
                                           "�����������߹ǡ�\n" NOR);
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "�������ƷǷ�������"
                       "�����мܣ�����������Ծ������\n" NOR;
        }

        msg += HIW "\n������$N" HIW "���С�" HIY "��" HIW "���־�����"
               "ʱֻ��$N" HIW "˫�Ʒ׷ɣ�����������Ӱ����$n" HIW "����"
               "�˷���\n"NOR;
        message_combatd(msg, me, target);


        for (i = 0; i < 4; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);

        	COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->add("neili", -400);
        me->start_busy(4 + random(3));
        return 1;
}

