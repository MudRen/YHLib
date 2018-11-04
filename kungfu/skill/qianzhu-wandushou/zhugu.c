#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int lvl;
        int damage;

	if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/qianzhu-wandushou/zhugu"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("���ﲻ�ܹ������ˣ�\n");

	if (! target || ! target->is_character())
		return notify_fail("��Ҫ��˭ʩչ��ƾ���\n");

	if (target->query("not_living"))
		return notify_fail("��������ǲ��ǻ��ˡ�\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ��������ʩչ��ƾ���\n");

        if ((int)me->query_skill("qianzhu-wandushou", 1) < 130)
                return notify_fail("���ǧ��������Ϊ���������ڻ��޷�ʩչ��ƾ���\n");

        if (me->query_skill_mapped("hand") != "qianzhu-wandushou")
                return notify_fail("��û�м���ǧ�����֣��޷�ʩչ��ƾ���\n");

        if (me->query("neili") < 400)
                return notify_fail("������������������޷�ʩչ��ƾ���\n");

        msg = HIB "$N" HIB "ʩ����ƾ���ֻ��һ�ƺ�����"
              "ָ��͸����ֻһ����û����$n" HIB "��ü�ģ�\n" NOR;

        lvl = (int)me->query_skill("hand", 1) / 2 +
              (int)me->query_skill("qianzhu-wandushou", 1);
        if (lvl / 2 + random(lvl) > target->query_skill("force"))
        {
                damage = lvl + random(lvl / 2);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
                                           HIR "$p" HIR "ֻ����һ����ɽ�ľ���˳ָ����"
                                           "��������ֻ����ȫ������ܣ����ۡ���һ��"
                                           "�³�һ�ں�Ѫ��\n" NOR);
                target->affect_by("qianzhu_wandushou",
                                  ([ "level" : lvl / 2 + random(lvl / 2),
                                     "id"    : me->query("id"),
                                     "duration" : lvl / 40 + random(lvl / 18) ]));
                me->add("neili", -320);
                me->start_busy(2);
        } else
        {
                msg += CYN "����$p" CYN "�����������������ڹ�"
                       "��������һָ�Ķ�����\n" NOR;
                me->start_busy(4);
                me->add("neili", -80);
        }
        message_combatd(msg, me, target);
        me->want_kill(target);
        if (! target->is_killing(me)) target->kill_ob(me);

        return 1;
}
