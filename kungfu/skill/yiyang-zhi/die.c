#include <ansi.h>
#include <combat.h>

#define DIE "��" HIR "��������" NOR "��"

inherit F_SSERVER;

string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ",
"�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ", "����Ѩ", "����Ѩ", "���Ѩ",
"�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", }); 

int perform(object me, object target)
{
        int damage;
        string msg, wp;
        object weapon;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/yiyang-zhi/die"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DIE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DIE "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("yiyang-zhi", 1) < 200)
                return notify_fail("��һ��ָ��������죬����ʩչ" DIE "��\n");

        if ((int)me->query_skill("jingluo-xue", 1) < 200)
                return notify_fail("��Ծ���ѧ�˽ⲻ��������ʩչ" DIE "��\n");

        if (me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("��û�м���һ��ָ��������ʩչ" DIE "��\n");

        if (me->query_skill_prepared("finger") != "yiyang-zhi")
                return notify_fail("��û��׼��һ��ָ��������ʩչ" DIE "��\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���򲻹�������ʩչ" DIE "��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ���㣬����ʩչ" DIE "��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("�����ڵ���������������ʩչ" DIE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        damage = (int)me->query_skill("finger");
        damage += random(damage);

        ap = me->query_skill("finger");
        dp = target->query_skill("parry");

        msg = HIW "ͻȻ��";

        if (objectp(weapon = target->query_temp("weapon")))
        {
                wp = weapon->name();
                msg += "$N" HIW "��ָһ�����$n" HIW "����" + wp + NOR + HIW
                       "�������ϡ�" HIY "���" HIW "������" HIY "����" HIW "��"
                       "����" HIY "����" HIW "����Ѩ��\n" NOR;

                ap = me->query_skill("finger");
                dp = target->query_skill("force");

                if (ap / 3 + random(ap) > dp)
                {
                        msg += HIR "��ʱ��$n" HIR "ֻ��������һ�飬����" + wp +
                               HIR "��Ҳ�óֲ�ס�����ֵ��ڵ��ϡ�\n\n" HIW "��"
                               "����";
                        me->add("neili", -150);
                        weapon->move(environment(target));
                } else
                {
                        msg += CYN "����$n" CYN "������" + wp + NOR + CYN "ת"
                               "�����֣����ڻ�������һ�С�\n\n" HIW "������";
                        me->add("neili", -100);
                }
        }

        msg += "$N" HIW "������ָ��һʽ��" HIR "��������" HIW "���������ʱһ��"
               "����������ֱϮ$n" HIW "�ؿڣ�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70,
                                           HIR "���$n" HIR "��$N" HIR "һָ����"
                                           HIY + xue_name[random(sizeof(xue_name))] +
                                           HIR "��ȫ�������������ϣ���ʱŻ��һ��"
                                           "����Ѫ��\n" NOR);

		target->add_temp("yiyang-zhi/die", 1);
        } else
        {
                msg += CYN "����$p" CYN "�����磬ȫ��������$P"
                       CYN "�⾫���һָ��\n" NOR;
        }

        ap = me->query_skill("finger");
        dp = target->query_skill("dodge");

        msg += "\n" HIW "����$N" HIW "̤ǰһ�������������ŷ�������һָ����$n" HIW
               "��ȥ��ָ���ݺᣬ��Ȼ���죡\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80,
                                           HIR "���$n" HIR "��$N" HIR "һָ����"
                                           HIY + xue_name[random(sizeof(xue_name))] +
                                           HIR "��ȫ�������������ϣ���ʱŻ��һ��"
                                           "����Ѫ��\n" NOR);

		target->add_temp("yiyang-zhi/die", 1);
        } else
        {
                msg += CYN "����$p" CYN "�����磬ȫ��������$P"
                       CYN "�⾫���һָ��\n" NOR;
        }

        ap = me->query_skill("finger");
        dp = target->query_skill("force");

        msg += "\n" HIW "���$N" HIW "һ���ͺȣ���ָ���͡���һ�����������ָ��ͬ"
               "ʱ����$n" HIW "ȫ�����ҪѨ��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90,
                                           HIR "���$n" HIR "��$N" HIR "һָ����"
                                           HIY + xue_name[random(sizeof(xue_name))] +
                                           HIR "��ȫ�������������ϣ���ʱŻ��һ��"
                                           "����Ѫ��\n" NOR);

		target->add_temp("yiyang-zhi/die", 1);
        } else
        {
                msg += CYN "����$p" CYN "�����磬ȫ��������$P"
                       CYN "�⾫���һָ��\n" NOR;
        }

        if (target->query_temp("yiyang-zhi/die", 1) == 3
           && target->query("neili"))
        {
                msg += HIY "\n$n" HIY "��$N" HIY "��ָ���У�ȫ��������"
                       "ɢ������ƺӾ��̣�������ʱ��к������\n\n" NOR;
		target->set("neili", 0);
        }
        me->start_busy(4 + random(4));
        me->add("neili", -800);
	target->delete_temp("yiyang-zhi/die");
        message_combatd(msg, me, target);

        if (! target->query("neili"))
                tell_object(target, HIC "��ֻ�������ھ��ƿտ���Ҳ��һʱ"
                                    "˵���������ܡ�\n" NOR);

        return 1;
}
