#include <ansi.h>
#include <combat.h>

#define WAN "��" HIR "�򽣷���" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        string msg, wn;
        object weapon;
        int ap, dp, damage;

        me = this_player();

        if (userp(me) && ! me->query("can_perform/zhurong-jian/wan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(WAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" WAN "��\n");

        if ((int)me->query_skill("zhurong-jian", 1) < 160)
                return notify_fail("��ף�ڽ���������죬����ʩչ" WAN "��\n");

        if (me->query_skill_mapped("sword") != "zhurong-jian")
                return notify_fail("��û�м���ף�ڽ���������ʩչ" WAN "��\n");

        if ((int)me->query_skill("force") < 220)
                return notify_fail("����ڹ���򲻹�������ʩչ" WAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" WAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();
                            
        msg = HIM "\n$N" HIM "����ͻ�䣬������ע�뽣�������ʱ���ͨ�죬һʽ��"
              HIR "�򽣷���" HIM "��ʹ������ʱ��Х������������" + wn + HIM "����"
              "ǧ������У�����$n" HIM "����" NOR; 

        message_sort(msg, me, target);

        ap = me->query_skill("sword");
        dp = target->query_skill("dodge");

        if (random(ap) > dp / 2)
        {
         	damage = ap / 2 + random(ap);
         	damage += random(damage / 3);

                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                          (: final, me, target, damage :));
                me->start_busy(3);
         	me->add("neili", -200);
        } else
        {
         	msg = CYN "$n" CYN "�۽�" +wn + CYN"������ǿ���򶨣�"
                      "������������$N" CYN "��������������¡�\n" NOR;

       		me->start_busy(4);
         	me->add("neili", -100);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        int lvl, n;

        lvl = me->query_skill("zhurong-jian", 1);
        n = 1 + random(lvl / 20);

        target->affect_by("zhurong_jian",
                ([ "level"    : lvl + random(lvl),
                   "id"       : me->query("id"),
                   "duration" : lvl / 50 + random(lvl / 20) ]));

        return  HIR "ֻ��$N" HIR "��һ�м���硢�����$n"
                HIR "���о��ɲ���������ʯ�䣬�ѱ�$N" HIR
                "����" + chinese_number(n) + "�������˴���"
                "�����죬��Ѫ������������\n" NOR;
}
