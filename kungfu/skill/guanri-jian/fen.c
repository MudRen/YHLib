#include <ansi.h>
#include <combat.h>

#define FEN "��" HIR "������" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/guanri-jian/fen"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" FEN "��\n");

        if ((int)me->query_skill("guanri-jian", 1) < 150)
                return notify_fail("����ս���������죬����ʩչ" FEN "��\n");

        if (me->query_skill_mapped("sword") != "guanri-jian")
                return notify_fail("��û�м������ս���������ʩչ" FEN "��\n");

        if ((int)me->query("max_neili") < 2000)
                return notify_fail("���������Ϊ����������ʩչ" FEN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" FEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "��ת��������Ȼһ�ơ�" HIR "������" NOR +
              WHT "������������" + weapon->name() + WHT "Я��һ����"
              "������$n" WHT "ȫ��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 75,
                                           (: final, me, target, damage :));

                me->start_busy(3);
                me->add("neili", -300);
        } else
        {
                msg += CYN "����$n" CYN "������$N"
                       CYN "����ͼ��бԾ�ܿ���\n" NOR;
                me->start_busy(4);
                me->add("neili", -100);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        int lvl = me->query_skill("guanri-jian", 1);

        target->affect_by("zhurong_jian",
                ([ "level"    : lvl + random(lvl),
                   "id"       : me->query("id"),
                   "duration" : lvl / 50 + random(lvl / 20) ]));

        return  HIR "ֻ��$n" HIR "һ���Һ���������Ѫ���������"
                "������һ���һ��յ��������졣\n" NOR;
}
