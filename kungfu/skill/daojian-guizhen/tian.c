#include <ansi.h>
#include <combat.h>

#define TIAN "��" HIR "����������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string type1, type2, msg;
        object weapon1, weapon2;
        int ap, dp, damage;

        if (me->query_skill("daojian-guizhen", 1) < 200)
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(TIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon1 = me->query_temp("weapon");
        weapon2 = me->query_temp("handing");

        if (! objectp(weapon1) || ! objectp(weapon2))
                return notify_fail("��û��ͬʱװ������������ʩչ" TIAN "��\n");

        if (weapon2->query("consistence") <= 0)
                return notify_fail("���" + weapon2->name() + "�Ѿ�����"
                                   "�𻵣��޷�����ʹ���ˡ�\n");

        type1 = weapon1->query("skill_type");
        type2 = weapon2->query("skill_type");

        if ((type1 != "sword" && type1 != "blade")
           || (type2 != "sword" && type2 != "blade"))
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" TIAN "��\n");

        if ((type1 == "sword" && type2 != "blade")
           || (type1 == "blade" && type2 != "sword"))
                return notify_fail("��û��ͬʱװ������������ʩչ" TIAN "��\n");

        if (me->query_skill_mapped("sword") != "daojian-guizhen"
           || me->query_skill_mapped("blade") != "daojian-guizhen")
                return notify_fail("��û�м����������棬����ʩչ" TIAN "��\n");

        if (me->query_skill("daojian-guizhen", 1) < 250)
                return notify_fail("��Ľ�����ȼ�����������ʩչ" TIAN "��\n");

        if (me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" TIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("sword") +
             me->query_skill("blade") +
             me->query_skill("daojian-guizhen", 1) * 3 / 2;

        dp = target->query_skill("force") +
             target->query_skill("dodge") +
             target->query_skill("parry", 1);

        damage = ap + random(ap / 2);

        msg = HIY "$N" HIY "��" + weapon1->name() + HIY "��" +
              weapon2->name() + HIY "��������ǰ����ת����"
              HIR "����������" HIY "���������ھ��纣Х�㱬����\n" NOR;

        if (ap / 3 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "��$N" HIR "ɱ�����ǣ�������"
                       "�����⣬�мܶ�ʱɢ�ң�ȫȻ��������\n" NOR;
                ap += ap / 5;
                damage += damage / 3;
        } else
        {
                msg += HIG "$n" HIG "��$N" HIG "ɱ�����ǣ�˿����"
                       "�Ҵ��⣬��æ��������Ŭ�����ܸ��š�\n" NOR;
        }

        msg += HIW "\nͻȻ��$N" HIW "����һչ������" + weapon1->name() +
               HIW "����һ����վ��һ���뻡��ֱ��$n" HIW "��ȥ��\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
                                           HIR "$n" HIR "�����ֵ���ȴ�����мܵ�ס"
                                           "����$N" HIR "һ�л���Ҫ������Ѫ�Ĵ���"
                                           "����\n" NOR);
        } else
        {
                msg += CYN "$n" CYN "��֪��һ�е���������æ����"
                       "������С�Ĳ��У�˿������\n" NOR;
        }

        msg += HIW "\n����$N" HIW "�ֽ�����" + weapon2->name() +
               HIW "��$n" HIW "ƽƽ�ݳ�����ʽ���Ƽ򵥣�ȴ�̲���"
               "�����ɱ�š�\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                // ת������
                weapon1->move(me, 1);
                weapon2->wield();

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
                                           HIR "$n" HIR "ֻ���ۻ����ң�ȫȻ�޷���"
                                           "���Ȼ���$N" HIR "һ�����У����һ����"
                                           "Ѫ��\n" NOR);
                // ת�ƻس�ʼ״̬
                weapon2->move(me, 1);
                weapon1->wield();
                me->set_temp("handing", weapon2);
        } else
        {
                msg += CYN "$n" CYN "��֪��һ�е���������æ����"
                       "������С�Ĳ��У�˿������\n" NOR;
        }
        me->start_busy(3 + random(3));
        me->add("neili", -300);
        message_combatd(msg, me, target);
        return 1;
}
