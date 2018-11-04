// bizhen-qingzhang  �������� ����
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (userp(me) && ! me->query("can_perform/bizhen-qingzhang/pengpai"))
                return notify_fail("�㻹����ʹ����һ�У�\n");

        if (me->query_temp("weapon"))
                return notify_fail("�������ֲ���ʩչ�����ȡ���һ�У�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail("�����ȡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (me->query_skill("bizhen-qingzhang", 1) < 180)
                return notify_fail("��ı������ƻ�������죬���������������ˣ�\n");

        if (me->query_skill_mapped("strike") != "bizhen-qingzhang")
                return notify_fail("��û�м����������ƣ��޷�ʹ�á����ȡ���һ�У�");

        if (me->query_skill("force") < 300)
                return notify_fail("���ڹ�����Ϊ�������޷����������ˣ�\n");

        if (me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ�������޷����������ˣ�\n");

        if (me->query("neili") < 500)
                return notify_fail("��������������޷����������ˣ�\n");
 
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "һ����ߣ�˫�ƻ����һ����Ȧ��"
              "���ƶ�������ʱһ����ӿ���ȵľ����粨��һ����$n"
              HIW "ӿ����\n" NOR;
 
        ap = me->query_skill("strike");
        dp = target->query_skill("parry");

        me->start_busy(3);
        me->add("neili", -200);

        if (ap / 2 + random(ap) < dp)
        {
                msg += HIY "ֻ��$n" HIY "���Ų�æ������һ���������$N" HIY "��һ����\n"NOR;
        } else
        {
                me->add("neili", -300);
                damage = ap / 2 + random(ap / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "ֻ��$n" HIR "�޷��ε�����ӿ���ȵ����������һ�����Ѫ������ֱ�߷ɳ���\n" NOR);
        }

        message_combatd(msg, me, target);
        return 1;
}

