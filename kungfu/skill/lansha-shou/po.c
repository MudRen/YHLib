#include <ansi.h>
#include <combat.h>

#define PO "��" HIB "�Ƶ���ɰ" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int lvl;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/lansha-shou/po"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail(PO "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("lansha-shou", 1) < 100)
                return notify_fail("����ɰ�ֲ�������������ʩչ" PO "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("���������Ϊ���㣬����ʩչ" PO "��\n");

        if (me->query_skill_mapped("hand") != "lansha-shou")
                return notify_fail("��û�м�����ɰ�֣�����ʩչ" PO "��\n");

        if (me->query_skill_prepared("hand") != "lansha-shou")
                return notify_fail("��û��׼����ɰ�֣�����ʩչ" PO "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "���μ�ת���������ȣ���Ȼʩ����ɰ�־�����" NOR +
              HIB "�Ƶ���ɰ" NOR + HIG "������$n" HIG "��ǰ��Ѩץ�䣡\n" NOR;

        lvl = me->query_skill("lansha-shou", 1);

        ap = me->query_skill("hand");
        dp = target->query_skill("force");

        me->start_busy(3);
        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap / 2 + random(ap / 3);
                me->add("neili", -100);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 20,
                                          (: final, me, target, damage :));
        } else
        {
                msg += CYN "$n" CYN "��$N"
                       CYN "������ӿ�������񵲣����ڻ��⿪����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        int lvl = me->query_skill("lansha-shou", 1) / 2 * 3;

        target->affect_by("sha_poison",
                ([ "level"    : me->query("jiali") + random(me->query("jiali")),
                   "id"       : me->query("id"),
                   "duration" : lvl / 50 + random(lvl / 30) ]));

        return HIR "$n" HIR "���ܲ������Ǳ�$N" HIR
               "ץ�����Ѫ�ۣ��˿ھ�������Ѫ������"
               "�����׹⡣\n" NOR;
}

