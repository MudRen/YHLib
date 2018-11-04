// qi.c ���ν���

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define QI "��" HIG "���ν���" NOR "��"

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);


        if (userp(me) && ! me->query("can_perform/liumai-shenjian/qi"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(QI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 420)
                return notify_fail("����ڹ���򲻹���ʹ����" QI "��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ��������ʹ�����Ϭ����" QI "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʹ��" QI "��\n");

        if (me->query_skill("liumai-shenjian", 1) < 200)
                return notify_fail("�����������Ϊ���ޣ��޷�ʹ��" QI "��\n");

        if (me->query_skill_prepared("finger") != "liumai-shenjian")
                return notify_fail("��û��׼�������񽣣��޷�ʹ��" QI "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "��ָһ����һ���������׵����ν���ֱ��$n" HIG "��ǰ��ȥ��\n" NOR;  

        ap = me->query_skill("finger");
        dp = target->query_skill("force");
        weapon = target->query_temp("weapon");
        me->start_busy(3);
        if (ap * 2 / 3 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -400);
                if (! objectp(weapon) || weapon->query("skill_type") == "pin")
                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 86,
                                                   HIR "$n" HIR "ֻ������ǰһ���ʹ����Ѫ"
                                                   "�Դ��ڼ����������ǰ��ʱһ�ڣ�\n" NOR);
                else
                if (weapon->is_item_make() || weapon->query("damage") > 180 ||
                    weapon->query("skill_type") == "hammer")
                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 74,
                                                   HIR "$n" HIR "��" + weapon->name() + HIR "��ͼ�мܣ�"
                                                   HIR "������ɽ������Ϭ����͸��" + weapon->name() +
                                                   HIR "ֱ���$n" HIR "������Ѫ������������Ҫ��ת������\n" NOR);
                else
                {
                        msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 55,
                                                   HIR "$n" HIR "��ת" + weapon->name() + HIR "��������"
                                                   "ǰ��ֻ��ž��һ����" + weapon->name() +
                                                   HIR "������أ��������죡\n$n" HIR "����"
                                                   "���������ۡ�������һ����Ѫ����ɫ��ĲҰס�\n" NOR);
                        weapon->move(environment(me));
                        weapon->set("no_wield", weapon->name() + "�Ѿ�����ˣ�û��װ���ˡ�\n");
                        weapon->set_name("�����" + weapon->name());
                        weapon->set("value", 0);
                }
        } else
        {
                msg += CYN "����$p" CYN "�ڹ���Ϊ������Ὣ����������������Ρ�\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

