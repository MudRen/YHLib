#include <ansi.h>
#include <combat.h>

#define HENG "��" HIR "��ɨǧ��" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int ap, int dp);
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (userp(me) && ! me->query("can_perform/baisheng-daofa/heng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail(HENG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" HENG "��\n");

	if ((int)me->query_skill("baisheng-daofa", 1) < 150)
		return notify_fail("���ʤ�����������ң�����ʩչ" HENG "��\n");

        if (me->query_skill_mapped("blade") != "baisheng-daofa")
                return notify_fail("��û�м�����ʤ����������ʩչ" HENG "��\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("����ڹ���򲻹�������ʩչ" HENG "��\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("�����ڵ���������������ʩչ" HENG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("blade") + me->query_str() * 5;
        if (me->query("character") == "��������")
        {
                msg = HIR "$N" HIR "��Ŀ��ȣ�ɱ����Ȼ�����ֳ�" + weapon->name() +
                      HIR "���޷��˵���Ȼ��ɨ$n" HIR "��ȫȻ����������������Ȼ��\n" NOR;
                ap += ap * 1 / 4;
        } else
                msg = HIR "$N" HIR "�����ھ�����ȫ��������ע��" + weapon->name() +
                      HIR "֮�ϼ�ն��������ৡ���һ��ɨ��$n" HIR "��ȥ��\n" NOR;

        dp = target->query_skill("force") + target->query_str() * 5;
        damage = 0;
        if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap / 3);
                me->add("neili", -350);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           (: final, me, target, ap, dp :));
		me->start_busy(3);
	} else 
	{
		msg += HIC "$n" HIC "�����мܣ�Ӳ�����ĵ�ס���������ʧɫ֮��ɱһ����\n" NOR;
                me->add("neili", -150);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}

string final(object me, object target, int ap, int dp)
{
        object weapon;
        string msg;

        msg = HIR "$n" HIR "��æ�ֵ���ȴ�����мܵ�ס��������"
              "����һ����÷������Զ��ƽɳ��";
        if (ap / 3 > dp)
        {
                msg += "�ʹ˱�����\n" NOR;
                call_out("char_killed", 0, target, me);
        } else
        if ((ap / 2 > dp) && objectp(weapon = target->query_temp("weapon")))
        {
                msg += "���е�" + weapon->name() + HIR "��Ҳ����ס��Ӧ��������\n" NOR;
                weapon->move(environment(me));
        } else
                msg += "\n" NOR;
        return msg;
}

void char_killed(object ob, object me)
{
        if (objectp(ob) && objectp(me) && me->is_fighting(ob) &&
            environment(ob) == environment(me))
                ob->die(me);
}
