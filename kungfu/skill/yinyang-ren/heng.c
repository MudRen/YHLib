
#include <ansi.h>
#include <combat.h>

#define HENG "��" HIC "��ճ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/yinyang-ren/heng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || ((string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade"))
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HENG "��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" HENG "��\n");

        if (me->query_skill("yinyang-ren", 1) < 180)
                return notify_fail("��������з���Ϊ����������ʩչ" HENG "��\n");

        if ((int)me->query_skill("dodge") < 200)
                return notify_fail("����Ṧ��򲻹�������ʩչ" HENG "��\n");  

        if ((int)me->query("max_neili") < 2700)
                return notify_fail("���������Ϊ���㣬����ʩչ" HENG "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʩչ" HENG "��\n");

        if (me->query_skill_mapped("sword") != "yinyang-ren"
            && me->query_skill_mapped("blade") != "yinyang-ren")
                return notify_fail("��û�м��������з�������ʩչ" HENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "\nֻ��$N" HIY "����" + weapon->name() + HIY "бָ"
              "���죬��Ȼ����ʽͻ�䣬" + weapon->name() + HIY "����"
              "�������죬һʽ��" HIC "��ճ���" HIY "����������գ�"
              "��ѹȺɽ����������ư��Ϯ��$n" HIY "��\n" NOR;
        message_sort(msg, me, target);

        // ��������������sword��blade���ж�apֵ��
        if (me->query_skill_mapped("sword") == "yinyang-ren")
                ap = me->query_skill("sword");
        else 
                ap = me->query_skill("blade");

        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
                me->add("neili", -240);
                me->start_busy(2 + random(2));
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 75,
                                           HIR "$n" HIR "�������������ͣ� �赲��"
                                           "���� ��ʱ��" + weapon->name() + HIR 
                                           "���ˣ��಻���ԡ�\n" NOR);
        } else
        {
                me->add("neili", -150);
                me->start_busy(1 + random(2));
                msg = CYN "��ȴ��" CYN "$n" CYN "�͵İεض��𣬱ܿ���"
                       CYN "$N" CYN "�������͵�һ�С�\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
