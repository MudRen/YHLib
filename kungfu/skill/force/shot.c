#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        object du;
        int an, dn, ap, dp;
        int f, i, skill;
        string msg;

        f = me->query_skill_mapped("force");
        skill = me->query_skill("force");

        if (me->query_skill_mapped("force") != "xiuluo-yinshagong"
           && me->query_skill_mapped("force") != "huagong-dafa"
           && me->query_skill_mapped("force") != "hamagong"
           && me->query_skill_mapped("force") != "shennong-xinjing"
           && me->query_skill_mapped("force") != "huaxue-shengong")
                return notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");

        if (skill < 150)
                return notify_fail("����ڹ���Ϊ������\n");

        if ((int)me->query_skill("poison", 1) < 100)
                return notify_fail("��Ļ���������򲻹���\n");

        if ((int)me->query_skill("throwing", 1) < 100)
                return notify_fail("��Ļ���������򲻹���\n");

        if (environment(me)->query("no_fight"))
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        // ִ��������������ⷿ���ֹ�����жϾ��顣
        if (environment(me)->query("skybook"))
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�������������\n");

        if (! objectp(du = me->query_temp("handing")))
                return notify_fail("�����׼��(hand)�ö�ҩ��˵��\n");

        if (! mapp(du->query("poison")))
                return notify_fail("���������õ�" + du->name() + NOR
                                   "���Ƕ�ҩ���޷����䡣\n");

        if (du->query("no_shot"))
                return notify_fail("��" + du->name() + NOR "�����ȥ"
                                   "���ƺ���̫�ðɡ�\n");

        if (! target || me == target
           || ! target->is_character()
           || target->query("not_living"))
                return notify_fail("���빥��˭��\n");

        if (target->query_condition("die_guard"))
                return notify_fail("����������ٸ������ţ����Ǳ�ȥ���ǡ�\n");

        if (target->query_competitor())
                return notify_fail("�����ʱ���������������Ľ�����\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "һ����Ц��Ĭ��" + to_chinese(f) +
              HIM "�ھ�����ָճס" + du->name() +
              HIM "��׼$n" HIM "��ಡ��ĵ����˳�ȥ��\n" NOR;

        me->start_busy(1 + random(3));
        me->add("neili", -100);

        an = me->query("max_neili") + me->query("neili") / 2;
        dn = target->query("max_neili") + target->query("neili") / 2;

        if (an / 2 + random(an) < dn * 2 / 3)
        {
                msg += WHT "Ȼ��$n" WHT "ȫȻ���������ϣ�����һ�����ѽ�$N"
                       WHT "�����Ķ��ؾ������䡣\n" NOR;
        } else
        {
                ap = me->query_skill("force") +
                     me->query_skill("poison") +
                     me->query_skill("throwing");

                dp = target->query_skill("dodge") +
                     target->query_skill("parry") +
                     target->query_skill("martial-cognize");

                if (ap / 2 + random(ap) > dp)
                {
                        msg += HIG "$n" HIG "��æ�����ܣ�����Ȼ��������ʱ"
                               "�̹�������$p" HIG "�ٸ�һ����ԡ�\n" NOR;
                        target->affect_by(du->query("poison_type"),
                                          du->query("poison"));

                        if (! target->is_busy())
                                target->start_busy(2);
                } else
                {
                        msg += CYN "����$n" CYN "���Ʋ����æ��Ų���Σ���"
                               "�ڱܿ���$N" CYN "�ĵ���������\n" NOR;
                }
        }
        message_combatd(msg, me, target);

        if (du->query_amount())
        {
                du->add_amount(-1);

                if (du->query_amount() < 1)
                        destruct(du);
        } else
                destruct(du);

        me->want_kill(target);

        if (! target->is_killing(me))
                target->kill_ob(me);

        return 1;
}

