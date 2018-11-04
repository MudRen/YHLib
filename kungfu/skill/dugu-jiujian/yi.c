#include <ansi.h>
#include <combat.h>

#define YI "��" HIY "����ʽ" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, skill;
        int damage;

        skill = me->query_skill("dugu-jiujian", 1);

        if (me->query("can_learn/dugu-jiujian/nothing"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");       

        if (skill < 90)
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(YI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" YI "��\n");

        if (me->query_skill_mapped("sword") != "dugu-jiujian") 
                return notify_fail("��û�м������¾Ž�������ʩչ" YI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        switch (random(3))
        {
        case 0:
                msg = HIY "$N" HIY "����һ��ָ��$n" HIY "���������$n"
                      HIY "�������ڣ���֮�������������Ѳ⡣\n" NOR;
                break;

        case 1:
                msg = HIY "$N" HIY "���д󿪴��أ������������£�����"
                      "�нԻ�$n" HIY "����������������������\n" NOR;
                break;

        default:
                msg = HIY "$N" HIY "���ֺὣ����$n" HIY "������������"
                      "���е�һ����Ȼ����������˷�����˼��\n" NOR;
                break;
        }

        ap = me->query_skill("sword") +
             me->query_skill("martial-cognize");

        dp = target->query_skill("parry") +
             target->query_skill("martial-cognize") +
             target->query_skill("dugu-jiujian");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "$n" HIR "ȫȻ�޷����$N" HIR "��"
                                           "���еİ��һ�����񣬵����ش���\n" NOR);
                me->start_busy(2);
        } else 
        {
                msg += CYN "��$n" CYN "��Ȼ��֮����û��$N"
                       CYN "���з������ϣ����ּܿ�����©���������\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
