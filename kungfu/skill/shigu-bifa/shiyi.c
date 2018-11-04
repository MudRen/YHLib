#include <ansi.h>
#include <combat.h>

#define SHIYI "��" HIW "ʫ���ݺ�" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int skill, i;

        if (userp(me) && ! me->query("can_perform/shigu-bifa/shiyi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(SHIYI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" SHIYI "��\n");

        skill = me->query_skill("shigu-bifa", 1);

        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" SHIYI "��\n");

        if (skill < 120)
                return notify_fail("���ʯ�Ĵ�Ѩ�ʷ���Ϊ���ޣ�����ʩչ" SHIYI "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" SHIYI "��\n");

        if (me->query_skill_mapped("dagger") != "shigu-bifa")
                return notify_fail("��û�м���ʯ�Ĵ�Ѩ�ʷ�������ʩչ" SHIYI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "�ݲ���ǰ������" + weapon->name() + HIW "�󿪴�"
              "�ϣ��������಻���������س���˲����$n" HIW "�������У�\n" NOR;
        message_combatd(msg, me, target);
        me->add("neili", -80);

        for (i = 0; i < 4; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->start_busy(1 + random(4));
        return 1;
}
