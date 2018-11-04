#include <ansi.h>
#include <combat.h>

#define CHUAN "��" HIM "���´���" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string wn, msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/raozhi-roujian/chuankong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHUAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CHUAN "��\n");

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" CHUAN "��\n");

        if (me->query_skill("raozhi-roujian", 1) < 100)
                return notify_fail("�����ָ�ὣ��Ϊ����������ʩչ" CHUAN "��\n");

        if (me->query_skill_mapped("sword") != "raozhi-roujian")
                return notify_fail("��û�м�����ָ�ὣ������ʩչ" CHUAN "��\n");

        if (me->query("neili") < 250)
                return notify_fail("��������������������ʩչ" CHUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        message_sort(HIM "\nֻ��$N" HIM "ĺ����һ����Х���������䣬��"
                     "��" + wn + HIM "���Ƴ���һ��������������ۣ�Ʈ��"
                     "����������$n" HIM "���ţ�������;������΢������"
                     "Ȼ���˹�ȥб��$n" HIM "�Ҽ磬��ʽ����֮����\n" NOR,
                     me, target);

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap);
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
                                          HIR "���$pһ���������Ǳ�$P���д��У�"
                                          "һ���Һ�����Ѫ�ɽ�������\n" NOR);
                me->start_busy(2);
                me->add("neili", -150);
        } else
        {
                msg = CYN "����$p�������ң��������������"
                      "������$P�Ľ��С�\n" NOR;
                me->start_busy(3);
                me->add("neili", -60);
        }
        message_vision(msg, me, target);

        return 1;
}
