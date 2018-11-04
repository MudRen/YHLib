#include <ansi.h>
#include <combat.h>

#define YIN "��" HIR "����ĥ" NOR "��"

inherit F_SSERVER;

string finala(object me, object target, int damage);
string finalb(object me, object target, int damage);

int perform(object me, object target)
{
        string msg;
        int ap, dp, dd;
        int damage;

        if (userp(me) && ! me->query("can_perform/tie-zhang/yin"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YIN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tie-zhang", 1) < 220)
                return notify_fail("�������Ʒ���򲻹�������ʩչ" YIN "��\n");

        if (me->query_skill_mapped("strike") != "tie-zhang")
                return notify_fail("��û�м��������Ʒ�������ʩչ" YIN "��\n");

        if (me->query_skill_prepared("strike") != "tie-zhang")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" YIN "��\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ����������ʩչ" YIN "��\n");

        if ((int)me->query("max_neili") < 3500)
                return notify_fail("���������Ϊ����������ʩչ" YIN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" YIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʩ�����ƾ�����" HIR "����ĥ"
              HIW "�������Ʋ��Ű��������Я����������$n"
              HIW "��ȥ��\n" NOR;  

        ap = me->query_skill("strike") + me->query("str") * 5;
        dp = target->query_skill("parry") + target->query("con") * 5;
        dd = target->query_skill("dodge") + target->query("dex") * 5;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 55,
                                           (: finala, me, target :));
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "�Ƴ���磬��֪"
                       "���к��ż�������������б��������\n" NOR;
        }

        msg += HIR "\n������$N" HIR "����һ���Ʒ��������ϯ"
               "����һ�����ˣ���$n" HIR "��ǰ��Ȼ���䡣\n" NOR;  

        if (ap / 2 + random(ap) > dd)
        {
                damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70,
                                           (: finalb, me, target :));
        } else
        {
                msg += CYN "$n" CYN "���ź�Х���������ۼ�$N" CYN
                       "������磬��æ��Ծ��ܿ�����\n" NOR;
        }
        me->start_busy(3 + random(3));
        me->add("neili", -400);
        message_combatd(msg, me, target);
        return 1;
}

string finala(object me, object target, int damage)
{
        int lvl;
        lvl = me->query_skill("strike");

        target->affect_by("tiezhang_yin",
                       ([ "level" : me->query("jiali") + random(me->query("jiali") / 2),
                          "id"    : me->query("id"),
                          "duration" : lvl / 50 + random(lvl / 50) ]));

        return HIW "���Ǽ�$n" HIW "�ѱ�$N" HIW "�����ƾ�����Ҫ"
               "�������ɵû���һ��������֮����\n" NOR;
}

string finalb(object me, object target, int damage)
{
        int lvl;
        lvl = me->query_skill("strike");

        target->affect_by("tiezhang_yang",
                       ([ "level" : me->query("jiali") + random(me->query("jiali") / 2),
                          "id"    : me->query("id"),
                          "duration" : lvl / 50 + random(lvl / 50) ]));

        return HIR "ֻ���͵�һ����$N" HIR "��������ܸ����"
               "$n" HIR "�ؿڣ�����������߹ǡ�\n" NOR;
}
