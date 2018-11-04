#include <ansi.h>
#include <combat.h>

#define HUI "��" HIW "���ѩ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count;
        int i, attack_time;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/xueshan-jian/hui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUI "��\n");

        if (me->query_skill("force") < 50)
                return notify_fail("����ڹ�����Ϊ����������ʩչ" HUI "��\n");

        if (me->query_skill("xueshan-jian", 1) < 30)
                return notify_fail("���ѩɽ������Ϊ����������ʩչ" HUI "��\n");

        if (me->query("neili") < 50)
                return notify_fail("�����������������ʩչ" HUI "��\n");

        if (me->query_skill_mapped("sword") != "xueshan-jian")
                return notify_fail("��û�м���ѩɽ����������ʩչ" HUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("xueshan-jian", 1);
        dp = target->query_skill("parry", 1);

        msg = HIW "$N" HIW "�ؽ����裬һʽ�����ѩ�衹ʩ�����������಻������"
              "Х��������ͼ��$n" HIW "�������С�\n" NOR;

        me->add("neili", -30);
        if (random(ap) > dp / 2)
        {
                msg += HIR "$n" HIR "ֻ�����ؽ�Ӱ����ǵ����Լ���"
                       "�����ٱ����˸���æ���ң���֪���Ӧ�ԡ�\n"
                       NOR;
                target->start_busy(ap / 16 + 2);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ����"
                       "����㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
