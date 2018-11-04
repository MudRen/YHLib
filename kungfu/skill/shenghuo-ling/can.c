#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define CANXUE "��" HIR "��Ѫ��" NOR "��"

int perform(object me, object target)
{
        object weapon;
        string msg;
        int count;
        int damage, skill;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/shenghuo-ling/can"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        skill = me->query_skill("shenghuo-ling", 1);

        if (! (me->is_fighting()))
                return notify_fail(CANXUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õı������ԣ�����ʹ��ʥ���֮"
                                   CANXUE "��\n");

        if (skill < 220)
                return notify_fail("���ʥ����ȼ�����, ����ʹ��ʥ����"
                                   "��֮" CANXUE "��\n");

        if (me->query_skill("force") < 350)
                return notify_fail("����ڹ���򲻹�������ʹ��ʥ���֮"
                                   CANXUE "��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ���㣬����ʹ��ʥ���֮"
                                   CANXUE "��\n");

        if (me->query("neili") < 400)
                return notify_fail("�����������������ʹ��ʥ���֮" CANXUE "��\n");

        if (me->query_skill_mapped("sword") != "shenghuo-ling")
                return notify_fail("��û�м���ʥ������޷�ʹ��" CANXUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ����Х������" + weapon->name() +
              HIR "һת��������ʱ��ù����ޱȣ������벻���ķ�"
              "λ����$n" HIR "��\n" NOR;

        // ���ʥ�������߱��� max_hit����������˺���
        // ԭ���и���˺��ѿ�͸�����������Գ������ӹ�
        // ����Ч�ʷǳ���
        if (random(me->query_skill("sword")) > target->query_skill("parry") / 3)
        {
                msg += HIR "$n" HIR "��ȫ�޷���͸$N" HIR "������ʵ�����ɵ���"
                       "�����⣬��ʽһ�ͣ���ʱ�����ٳ���\n" NOR;
                count = me->query_skill("shenghuo-ling", 1) / 6;
                me->add_temp("shenghuo-ling/max_hit", 1);
        } else
        {
                msg += HIY "$n" HIY "��$N" HIY "������ӿ���ĵ�һ��������"
                       "��С�Ľ��С�\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        me->add("neili", -300);
        me->add_temp("apply/attack", count);

        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->delete_temp("shenghuo-ling/max_hit");
        me->start_busy(1 + random(4));
        return 1;
}
