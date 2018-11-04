#include <ansi.h>
#include <combat.h>

#define CANG "��" HIW "��Ы����" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int skill, i;

        if (userp(me) && ! me->query("can_perform/jifeng-cixuefa/cang"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(CANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" CANG "��\n");

        skill = me->query_skill("jifeng-cixuefa", 1);

        if (me->query_skill("force") < 120)
                return notify_fail("����ڹ���Ϊ����������ʩչ" CANG "��\n");

        if (me->query_skill("dodge") < 120)
                return notify_fail("����Ṧ��Ϊ����������ʩչ" CANG "��\n");

        if (skill < 100)
                return notify_fail("��ļ����Ѩ����Ϊ���ޣ�����ʩչ" CANG "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" CANG "��\n");

        if (me->query_skill_mapped("dagger") != "jifeng-cixuefa")
                return notify_fail("��û�м��������Ѩ��������ʩչ" CANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "һ��߳�ȣ�����" + weapon->name() + HIY "������̣�����"
              "����������㳯$n" HIY "��ȥ��\n" NOR;
        message_combatd(msg, me, target);
        me->add("neili", -80);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1 + random(4));
        return 1;
}
