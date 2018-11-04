#include <ansi.h>
#include <combat.h>

#define SHI "��" NOR + WHT "��ʬ��" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object *corpse;
        int lvl, lvp, damage;
        int ap, dp;
        string name, msg;

        if (userp(me) && ! me->query("can_perform/chousui-zhang/shi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (userp(me) && (me->query_temp("weapon")
           || me->query_temp("secondary_weapon")))
                return notify_fail(SHI "ֻ�ܿ���ʩչ��\n");

        lvl = me->query_skill("chousui-zhang", 1);
        lvp = me->query_skill("poison");

        if (lvl < 140)
                return notify_fail("��ĳ����Ʋ�����죬����ʩչ" SHI "��\n");

        if (lvp < 200)
                return notify_fail("��Զ������˽ⲻ��������ʩչ" SHI "��\n");

        if ((int)me->query_skill("throwing") < 180)
                return notify_fail("�㰵���ַ���򲻹�������ʩչ" SHI "��\n");

        if (me->query_skill_mapped("strike") != "chousui-zhang")
                return notify_fail("��û�м��������ƣ�����ʩչ" SHI "��\n");

        if (me->query_skill_prepared("strike") != "chousui-zhang")
                return notify_fail("��û��׼�������ƣ�����ʩչ" SHI "��\n");

        if ((int)me->query("max_neili") < 1200)
                return notify_fail("���������Ϊ���㣬����ʩչ" SHI "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ���Ϣ���㣬����ʩչ" SHI "��\n");

        corpse = filter_array(all_inventory(environment(me)),
                             (: base_name($1) == CORPSE_OB
                             && ($1->query("defeated_by") == this_player()
                             || ! $1->query("defeated_by")) :));

        if (userp(me) && sizeof(corpse) < 1)
                return notify_fail("�㸽��û�к��ʵ�ʬ�壬����ʩչ" SHI "��\n");

        // ����ȼ� 250 ���ϵ����� NPC ʩչ����
        if (! userp(me) && lvl < 250 && sizeof(corpse) < 1)
                return notify_fail("�㸽��û�к��ʵ�ʬ�壬����ʩչ" SHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if (sizeof(corpse) >= 1)
                name = corpse[0]->name();
        else
                name = "·�ߵ�����";

        msg = WHT "$N" WHT "����ץ��" + name + WHT "������"
              HIR "��ʬ��" NOR + WHT"�������������ϣ���$n"
              WHT "������ȥ��\n" NOR;

        ap = me->query_skill("strike") +
             me->query_skill("poison");

        // ������NPC��������֣��ټ������״��
        if (userp(me))
                dp = target->query_skill("dodge") +
                     target->query_skill("martial-cognize");
        else
                dp = target->query_skill("dodge") +
                     target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 75,
                                          (: final, me, target, damage :));
                me->start_busy(3);
                me->add("neili", -300);
        } else
        {
                msg += CYN "����$n" CYN "���Ʋ����æ��Ų���Σ���"
                       "�ڱܿ���$N" CYN "������ʬ�塣\n" NOR;
                me->start_busy(4);
                me->add("neili", -200);
        }
        message_combatd(msg, me, target);

        if (sizeof(corpse) >= 1)
                destruct(corpse[0]);

        return 1;
}

string final(object me, object target, int damage)
{
        int lvp = me->query_skill("poison") * 2 / 3;

        target->affect_by("corpse_poison",
                ([ "level"    : lvp + random(lvp),
                   "id"       : me->query("id"),
                   "duration" : 5 + random(lvp / 20) ]));

        target->receive_damage("jing", damage / 4, me);
        target->receive_wound("jing", damage / 8, me);

        return  HIR "$n" HIR "ֻ��һ�ɶ����������֮��������"
                "�ܣ��ٱ�ʬ��������С�\n" NOR;
}
