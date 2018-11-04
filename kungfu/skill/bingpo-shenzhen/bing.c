#include <ansi.h>
#include <combat.h>

#define BING "��" HIG "������" NOR "��"

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, n;
        int ap, dp, p;
        string msg, pmsg;
        object weapon;

        if (! me->query("can_perform/bingpo-shenzhen/bing"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(BING "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("handing")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("����������û�����Ű���������ʩչ" BING "��\n");

        if (weapon->query_amount() < 1)
                return notify_fail("������û���룬�޷�ʩչ" BING "��\n");

        if ((skill = me->query_skill("bingpo-shenzhen", 1)) < 120)
                return notify_fail("��ı������벻����죬����ʩչ" BING "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ���㣬����ʩչ" BING "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬����ʩչ" BING "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ" BING "��\n");

        if ((int)target->query_temp("bingpo"))
                return notify_fail("�Է��Ѿ�������ľ��У������Ƿ���һ"
                                   "�����Ͽ�����ɣ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->add("neili", -120);
        weapon->add_amount(-1);

        msg = HIY "ֻ��$N" HIY "����΢��������һת��һ�С�" HIW "������"
              HIY"����������" + weapon->name() + HIY "�͵������ɲ��\n"
              "�䣬�������죬" + weapon->name() + HIY "��ͬһ�����ǻ�����"
              "Ϯ��$n��\n" NOR;

        ap = me->query_skill("throwing");
        dp = target->query_skill("dodge");

        if (ap + random(ap / 2) > dp)
        {
                if (target->query_skill("parry") < me->query_skill("throwing"))
                {

                        msg += HIR "ֻ��$n" HIR "�ҽ�һ����" + weapon->name() + HIR 
                               "�Ѿ�����Ҫ����ֻ���˿ڴ�͸�������⣬�پ�ȫ����"
                               "��������\n"NOR; 
  
                        target->receive_damage("qi", skill + random(skill), me);
                        target->receive_wound("qi", skill + random(skill / 2), me);
                        target->set_temp("bingpo", 1);
                        target->add_temp("apply/attack", -70);
                        target->add_temp("apply/dodge", -70);
                        target->add_temp("apply/parry", -20);  

                        COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target, me->query("jiali") + 180);

                        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                        if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                                 msg += pmsg;  

                        msg += "( $n" + eff_status_msg(p) + " )\n";

                        message_combatd(msg, me, target);

                        tell_object(target, RED "������ҪѨ�ܵ���������ȫ����"
                                            "���᲻�ϰ��������\n" NOR);
                        tell_object(me, HIC "����֪�ղ������Ѵ��жԷ�Ҫ��������������Ц��\n" NOR);
                        call_out("back", 2 + random(skill / 15), target);
                } else
                {
                        msg += HIR "$n" HIR "�ۼ�����Ϯ�����������������"
                               "Ȼ����һ�����ˡ�\n" NOR, me, target;

                        target->receive_damage("qi", 100);
                        target->receive_wound("qi", 40);
                        COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target, me->query("jiali") / 2);
                        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                        msg += "( $n" + eff_status_msg(p) + " )\n";

                        message_combatd(msg, me, target);

                        tell_object(target, RED "��ֻ��ȫ����һ���ʹ��֪���Լ�"
                                            "�䱻���У���ȴ�Ǳܿ���Ҫ����\n" NOR);
                        me->start_busy(1 + random(2));
                }
        } else
        {        msg += CYN "����$n" CYN "�����ɣ�С�����ܣ��ò����ױܿ���"
                                 CYN "$N" CYN "Ѹ�����Ĺ�����\n" NOR;
                 message_combatd(msg, me, target);
                 me->start_busy(3);
        }
        return 1;
}

void back(object target)
{
        if (objectp(target))
        {
                target->add_temp("apply/attack", 70);
                target->add_temp("apply/dodge", 70);
                target->add_temp("apply/parry", 20);
                tell_object(target, HIY "���������������һ˿˿�Ļָ��ˡ�\n" NOR);
                target->delete_temp("bingpo");
        }
}
