#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define ZONG "��" HIM "���ݺ�" NOR "��"

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage, skill;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/liumai-shenjian/zong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_prepared("finger") != "liumai-shenjian")
                return notify_fail("��û��׼��ʹ�������񽣣��޷�ʩչ" ZONG "��\n");

        skill = me->query_skill("liumai-shenjian", 1);

        if (skill < 260)
                return notify_fail("�����������Ϊ���ޣ��޷�ʹ��" ZONG "��\n");

        if (me->query_skill("force") < 480)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZONG "��\n");

        if (me->query("max_neili") < 8500)
                return notify_fail("���������Ϊ����,�޷�ʩչ" ZONG "��\n");

        if (me->query("neili") < 850)
                return notify_fail("������������������޷�ʩչ" ZONG "��\n");

        if (me->query_temp("weapon"))
                return notify_fail("������ǿ��ֲ���ʩչ" ZONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");


        msg = HIM "$N" HIM "һ����Х��ʮָ�׵����پ�����������ӿ����ͷ������"
              "�˷������಻������ʱ�����籼�������޾������������Ȼ����$n" HIM 
              "��\n" NOR;

        ap = me->query_skill("finger") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("force");
        me->start_busy(4);

        if ((int)target->query_skill("jingluo-xue", 1) >= 200 
            && target->query_skill("dodge", 1) >= 300
            && random (10) == 1 )
        {
                me->add("neili", -600);
                me->start_busy(5);
                msg += HIY "����$n" HIY "����һЦ��������䣬���׵Ķ����һ�У�\n"NOR;
        } else
        if (ap * 2 / 3 + random(ap) > dp)
        { 
                damage = ap * 3 / 2 + random(ap);
                me->add("neili", -800);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 160,
                                           HIR "ֻ��$n" HIR "һ���ҽУ����������"
                                           "͸��������˿ڴ���Ѫ��ʱ��ӿ��ʹ���ѵ���\n" NOR);
        } else
        {
                me->add("neili", -400);
                me->start_busy(5);
                msg += CYN "$n" CYN "��$N" CYN "������ӿ����������"
                       "�мܣ���æ����Ծ����\n" NOR;
        }
        message_sort(msg, me, target);

        return 1;
}

