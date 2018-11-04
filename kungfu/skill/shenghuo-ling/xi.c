// xiyan.c

#include <ansi.h>

inherit F_SSERVER;

#define XIYAN "��" HIM "������" NOR "��"

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp;

        if (userp(me) && ! me->query("can_perform/shenghuo-ling/xi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIYAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õı������ԣ�����ʹ��ʥ���֮" XIYAN "��\n");

        skill = me->query_skill("shenghuo-ling", 1);

          if (! objectp(weapon2 = me->query_temp("weapon"))
             || (string)weapon2->query("skill_type") != "sword")
                return notify_fail("�Է�û��ʹ�ñ���������ʹ��ʥ���֮" XIYAN "��\n");

        if (skill < 140)
                return notify_fail("���ʥ����ȼ�����, ����ʹ��ʥ���֮" XIYAN "��\n");

        if (me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬����ʹ��ʥ���֮" XIYAN "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����������������ʹ��ʥ���֮" XIYAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "ͻȻ$N" HIM "�����һЦ��ʹ��ʥ���֮����"
              "�����" + weapon->name() + HIM "�ó�����СȦ"
              "����$n" HIM "��" + weapon2->name() + HIM "����"
              "��ס��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap + random(ap / 2) > dp)
        {
                me->add("neili", -240);
                msg += HIM "$n" HIM "ֻ����ǰ���������Ծ��������ʱֻ��"
                      "ͷ��Ŀѣ������һ�飬����" + weapon2->name() + HIM
                      "�ѱ�$N" HIM "���뻳�У�\n" NOR;
                me->start_busy(2);
                weapon2->move(me, 1);
        } else
        {
                me->add("neili", -100);
                msg += CYN "����$n" CYN "����$N" CYN "����ͼ�������б�"
                      "�л�����ܲ�͸�磬ʹ��$N" CYN "�޴����֡�\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);
        return 1;
}
