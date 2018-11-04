#include <ansi.h>
#include <combat.h>

#define FENG "��" HIR "�����Ļ�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        string wname;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/fenglei-panfa/fenglei"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(FENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "hammer")
                return notify_fail("��Ŀǰ��װ���������޷�ʹ�ó�" FENG "��\n");

        if (me->query_skill_mapped("hammer") != "fenglei-panfa")
                return notify_fail("��û�м��������̷�������ʹ��" FENG "��\n");

        if ((int)me->query_skill("fenglei-panfa", 1) < 150)
                return notify_fail("��ķ����̷�������죬��ʹ����" FENG "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" FENG "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������������ʩչ" FENG "��\n"NOR);

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wname = weapon->name();

        damage = (int)me->query_skill("fenglei-panfa", 1) / 2;
        damage += random(damage / 2);

        // ������ӿ
        ap = me->query_skill("hammer");
        dp = target->query_skill("dodge");
        msg = "\n" HIW "$N" HIW "�ȵ�����������ӿ�������ζ�Ȼ�ӿ죬���ָ߾�"
               + wname + HIW "��������һ��Ϯ��$n" HIW "��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
                                           HIR "$p" HIR "һ�㣬ֻ��$P" HIR "����"
                                           "һ�����ѻ����Լ���ǰ����������������"
                                           "�л������С�\n" NOR);
        } else
        {
                msg += CYN "$p" CYN "�侲�Ƿ���˿����Ϊ����õ�����"
                       "����������ֵ�����©���������\n" NOR;
        }

        // �������
        ap = me->query_skill("hammer");
        dp = target->query_skill("dodge");
        msg += "\n" WHT "$N" WHT "�ȵ�����������꣡������" + wname + WHT "һ"
               "����裬������磬����ǵ�������$n" HIW "��ȥ��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 32,
                                           HIR "$p" HIR "һ�㣬ֻ��$P" HIR "����"
                                           "һ�����ѻ����Լ���ǰ����������������"
                                           "�л������С�\n" NOR);
        } else
        {
                msg += CYN "$p" CYN "�侲�Ƿ���˿����Ϊ����õ�����"
                       "����������ֵ�����©���������\n" NOR;
        }

        // �������
        ap = me->query_skill("hammer");
        dp = target->query_skill("force");
        msg += "\n" HIM "$N" HIM "�ȵ����������������Ծ����գ�����" + wname
               + HIM "һ��������Я�����֮����չ���$n" HIM "��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 33,
                                           HIR "$p" HIR "һ�㣬ֻ��$P" HIR "����"
                                           "һ�����ѻ����Լ���ǰ����������������"
                                           "�л������С�\n" NOR);
        } else
        {
                msg += CYN "$p" CYN "�侲�Ƿ���˿����Ϊ����õ�����"
                       "����������ֵ�����©���������\n" NOR;
        }

        // ��������
        ap = me->query_skill("hammer");
        dp = target->query_skill("parry");
        msg += "\n" HIY "$N" HIY "�ȵ������������������͵���ǰֱ�����ߣ�����"
               + wname + HIY "�ó�һ����â������һ�������\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 35,
                                           HIR "$p" HIR "һ�㣬ֻ��$P" HIR "����"
                                           "һ�����ѻ����Լ���ǰ����������������"
                                           "�л������С�\n" NOR);
        } else
        {
                msg += CYN "$p" CYN "�侲�Ƿ���˿����Ϊ����õ�����"
                       "����������ֵ�����©���������\n" NOR;
        }

        me->start_busy(2 + random(5));
        me->add("neili", -400 - random(100));
        message_combatd(msg, me, target);
        return 1;
}
