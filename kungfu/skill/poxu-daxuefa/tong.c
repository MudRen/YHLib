#include <ansi.h>
#include <combat.h>

#define TONG "��" HIR "��Ԫͨ��" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

string *finger_name = ({ "������ָ", "��������ָ", "����ʳָ",
                         "������ָ", "��������ָ", "����ʳָ", }); 

int perform(object me, object target)
{
        object weapon;
        string wp, msg;
        int ap, dp, skill;
        int damage;

        if (userp(me) && ! me->query("can_perform/poxu-daxuefa/tong"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        me->clean_up_enemy();
        if (! target) target = me->select_opponent();

        skill = me->query_skill("poxu-daxuefa", 1);

        if (! me->is_fighting(target))
                return notify_fail(TONG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (skill < 120)
                return notify_fail("�������Ѩ���ȼ��������޷�ʩչ" TONG "��\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "dagger")
                return notify_fail("����ʹ�õ��������ԣ��޷�ʩչ" TONG "��\n");

        if (weapon && me->query_skill_mapped("dagger") != "poxu-daxuefa")
                return notify_fail("��û�м��������Ѩ�����޷�ʩչ" TONG "��\n");

        if (! weapon && me->query_skill_prepared("finger") != "poxu-daxuefa")
                return notify_fail("��û��׼�������Ѩ�����޷�ʩչ" TONG "��\n");

        if (target->query_temp("no_exert"))
                return notify_fail("�Է������Ѿ��޷������������ŵ������ɡ�\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ������������޷�ʩչ" TONG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if (weapon)
                wp = "����" + weapon->name();
        else
                wp = finger_name[random(sizeof(finger_name))];

        msg = HIG "$N" HIG "��ת" + wp + HIG "�������仯���ִ�Ѩ�ַ���һʽ��"
              HIR "��Ԫͨ��" HIG "��ֱ��$n" HIG "��ǰҪѨ��\n" NOR;

        ap = me->query_skill("poxu-daxuefa", 1);
        dp = target->query_skill("force", 1);

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap);
                msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 50,
                                           (: final, me, target, damage :));
                me->add("neili", -100);
                me->start_busy(3);
        } else
        {
                msg += CYN "����$n" CYN "���ѿ���$N"
                       CYN "������ʵ������һ�ӣ��ǽ����л������Ρ�\n" NOR;
                me->add("neili", -50);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int ap)
{
        target->set_temp("no_exert", 1);
        call_out("poqi_end", 10 + random(ap / 25), me, target);
        return  HIR "$n" HIR "ֻ���ؿ�һ�飬�ѱ�$N" HIR "����"
                "ҪѨ����ʱȫ���������ͣ��಻���ԣ�\n" NOR;
}

void poqi_end(object me, object target)
{
        if (target && living(target) && target->query_temp("no_exert"))
        {
                message_combatd(HIC "$N" HIC "��������һ��������ɫ��"
                                "��ת�죬�������ö��ˡ�\n" NOR, target);

                target->delete_temp("no_exert");
                tell_object(target, HIY "��е������ҵ���������ƽ��"
                                    "��������\n" NOR);
        }
        return;
}
