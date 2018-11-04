#include <ansi.h>
#include <combat.h>

#define SUI "��" HIW "��������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        string pmsg;
        string *limbs;
        string  limb;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/zhengliangyi-jian/sui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ��޷�ʩչ" SUI "��\n");

        if ((int)me->query_skill("zhengliangyi-jian", 1) < 180)
                return notify_fail("��������ǽ���������죬����ʩչ" SUI "��\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("����ڹ�����㣬����ʩչ" SUI "��\n");

        if (me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬����ʩչ" SUI "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" SUI "��\n");

        if (me->query_skill_mapped("sword") != "zhengliangyi-jian") 
                return notify_fail("��û�м��������ǽ���������ʩչ" SUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����һ����Ц����" + weapon->name() + HIY
              "����ָ���Լ��ؿڣ�����бб���⣬���˴������������ֱ"
              "��$n" HIY "��ȥ��\n" NOR;
        me->add("max_neili", -50);

        me->want_kill(target);
        target->kill_ob(me);
        ap = me->query_skill("sword");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap * 3 / 2) > dp)
        {
                me->start_busy(6);
                me->set("neili", 0);
                me->add("max_neili", -random(50));
                damage = 0;

                if (ap < dp * 3 / 4 &&
                   me->query("max_neili") < target->query("max_neili") * 3 / 4)
                {
                        msg += HIY "����$n" HIY "һ����ߣ������������У���˳��ת��һ"
                               "������$N" HIY "���š�\n" NOR + HIR "ֻ�������ꡱһ��"
                               "��$n" HIR "�������ô���$N" HIR "ͷ����$N" HIR "����һ"
                               "���������̱����\n" NOR;
                        message_combatd(msg, me, target);
                        me->set_temp("die_reason", "ʹ��һ���������ԣ�ƴ�����ɣ�����"
                                     + target->name() + "����");
                        me->die(target);
                        return 1;
                } else
                if (ap > dp &&
                   me->query("max_neili") > target->query("max_neili"))
                {
                        msg += HIR "$n" HIR "�ۼ�$N" HIR "��������׺�����һ�о�����"
                               "���ֵ����������ڼ��㣬���½��������ִ��С�\nֻ������"
                               "�͡�һ����" + weapon->name() + HIR "��Ȼ͸��$n" HIR
                               "ǰ�ض��룬���һ��Ѫ�ꡣ\n" NOR;
                        message_combatd(msg, me, target);
                        target->set_temp("die_reason", "��" + me->name() + "ʹһ����"
                                         "�����Դ�����");
                        target->die(me);
                        return 1;
                } else
                if (ap / 2 + random(ap * 2 / 3) > dp)
                {
                        msg += HIR "$n" HIR "�ۼ�$N" HIR "��������׺���ֻ����һ�о�"
                               "���޷��ֵ����������ڼ��㣬����֮��һ�����Ķ�������\n"
                               "��$N" HIR "���ţ���Ҳ��ͬ���ھ���������ֻ�������͡�һ"
                               "����" + weapon->name() + HIR "��Ȼ͸��$n" HIR "ǰ�أ�"
                               "���һ��Ѫ�ꡣ\nͬʱ$n" HIR "��һ��Ҳ���ô���$N" HIR
                               "ͷ�������á����ꡱһ����$N" HIR "ͷ�ǹ���ȫ���ѣ�����"
                               "��̱����\n" NOR;
                        message_combatd(msg, me, target);
                        me->set_temp("die_reason", "ʹ��һ������������" +
                                     target->name() + "ͬ���ھ���");
                        target->set_temp("die_reason", "��" + me->name() + "ʹһ����"
                                         "�����ԣ�����һ��ȥ���˺ڰ��޳�");
                        target->die(me);
                        me->die();
                        return 1;
                } else
                {
                        target->start_busy(2 + random(6));
        
                        damage = ap + (int)me->query_skill("force");
                        damage = damage / 2 + random(damage);

                        if (arrayp(limbs = target->query("limbs")))
                                limb = limbs[random(sizeof(limbs))];
                        else
                                limb = "Ҫ��";
                        pmsg = HIR "$n" HIR "�ۼ�$N" HIR "��������׺���ֻ����һ�о�"
                               "���޷��ֵ�����æ�������ܣ�Ȼ��ֻ����������һ������\n"
                               "��" + weapon->name() + HIR "��Ȼ�̴�" + limb + HIR "��"
                               "���һ��Ѫ�ꡣ\n" NOR;
                        msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage,
                               150, pmsg);
                }
        } else 
        {
                me->start_busy(8);
                msg += HIY "����$n" HIY "�����ϵ�$N"
                       HIY "�д�һ�ţ����μ������㿪"
                       "����һɱ�š�\n" NOR;
        }
        message_combatd(msg, me, target);
        return 1;
}

