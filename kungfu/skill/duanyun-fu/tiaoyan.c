// tiaoyan.c ��������֮������ʽ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int lvl;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("������ʽ��ֻ����ս���жԶ���ʹ�á�\n");

        if ((lvl = me->query_skill("duanyun-fu")) < 60)
                return notify_fail("��Ķ��������������ң�����ʩչ������ʽ����\n");

        if (me->query("neili") < 100)
                return notify_fail("��������������޷�ʩչ������ʽ����\n");

        msg = HIG "$N" HIG "ʹ����������֮������ʽ�������⼲��$n" HIG "˫�ۡ�\n" NOR;

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        me->start_busy(2);
        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
                me->add("neili", -50);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, lvl, 45,
                                           HIR "���$p" HIR "ֻ������ǰһ�ڣ�˫��һ"
                                           "���ʹ��Ѫ�����档\n" NOR);
        } else
                msg += HIG "����$p" HIG "������$P" HIG "����ͼ����æ�㿪�ˡ�\n" NOR;

        message_combatd(msg, me, target);

        return 1;
}
