// pengxin.c ��������

#include <ansi.h>
#include <combat.h>

#define XIN "��" HIM "��������" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int damage;
        int delta;
 
        if (userp(me) && ! me->query("can_perform/yuenv-jian/xin"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
	        return notify_fail(XIN "ֻ����ս���жԶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
	        return notify_fail("��ʹ�õ��������ԡ�\n");

	if (me->query_skill("sword", 1) < 200)
		return notify_fail("��Ľ�����Ϊ����������ʩչ" XIN "��\n");

	if (me->query_skill("yuenv-jian", 1) < 140)
		return notify_fail("���ԽŮ��������Ϊ����������ʩչ" XIN "��\n");

	if (me->query_skill("dodge") < 150)
		return notify_fail("����Ṧ��Ϊ����������ʩչ" XIN "��\n");

	if (me->query("neili") < 200)
		return notify_fail("�������������\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        if (me->query("gender") == "Ů��" &&
            target->query("gender") == "Ů��")
                delta = target->query("per") - me->query("per");
        else
                delta = 0;

	msg = HIG "\n$N" HIG "����һ����̾�����е�" + weapon->name() +
              HIG "������������$n" HIG "���ؿڡ�\n����������ӯ�鶯��������������"
              "��ɱ�˼�Ҳ����һ˿����֮����\n" NOR;

        if (delta > 0)
                msg += HIY "$n" HIY "ֻ����$N" HIY "��������Ȼ͸��"
                       "һ�ɱ���ĺ��⣬���в���һ����\n" NOR;
        else
                delta = 0;

	me->add("neili", -180);
        ap = (me->query_skill("sword") + me->query_skill("dodge")) / 2;
        dp = target->query_skill("dodge");
        me->start_busy(1);
        if (ap * 7 / 10  + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2) + delta * 50;

                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIR "$n" HIR "���һ������æ��ܣ�Ȼ����"
                                           "�����ĺÿ죬�����ÿ���\nֻ��$p" HIR
                                           "һ���ҽУ��ؿ��Ѿ����������ˣ�\n" NOR);
                if (ap / 2 + random(ap) > dp)
                {
                        damage /= 3;
                        msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                                   HIC "$n�ش�֮�²�������������$P"
                                                   HIC "��״���ִ̳�" + weapon->name() +
                                                   HIC "������һ����\n" HIR "����$p"
                                                   HIR "����һ���ҽУ�ʹ�಻����\n" NOR);
                }
        } else
        {
                msg += HIC "$n" HIC "��״���μ��ˣ��ܿ���$N"
                       HIC "�����ν���������һ����\n" NOR;
        }

        message_combatd(msg, me, target);

	return 1;
}
