#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define SHA "��" HIR "��ɱ" NOR "��"

string final(object me, object targer, int lvl);

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage;
        int lvl;

        if (userp(me) && ! me->query("can_perform/yinfeng-dao/jue"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHA "ֻ����ս����ʹ�á�\n");

        if ((int)me->query_skill("yinfeng-dao", 1) < 140)
                return notify_fail("������絶��������죬�޷�ʩչ" SHA "������\n");

        if ((int)me->query_skill("force") < 260)
                return notify_fail("���ڹ���򲻹�������ʩչ" SHA "������\n");

        if ((int)me->query("max_neili") < 2400)
                return notify_fail("��������������޷�ʩչ" SHA "��������\n");

        if ((int)me->query("neili") < 400)
                return notify_fail("��������������޷�ʩչ" SHA "��������\n");

        if (me->query_skill_mapped("strike") != "yinfeng-dao") 
                return notify_fail("��û�м������絶���޷�ʹ��" SHA "������\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʹ�����絶��" HIR "�� ɱ" HIW"���������ƾ��ó�һƬƬ�йǺ�"
              "����쫷�����$nȫ��\n" NOR;
 
        lvl = me->query_skill("yinfeng-dao", 1);

        ap = me->query_skill("strike") + me->query_skill("force");
        dp = target->query_skill("parry") + me->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 70,
                                           (: final, me, target, lvl :));
              
                me->add("neili", -350);
                me->start_busy(1);
        } else
        {
                msg += CYN "����$n��æ��������������㿪����һ����\n" NOR;
                me->start_busy(3);
                me->add("neili", -150);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int lvl)
{
       target->affect_by("yinfeng_dao",
                       ([ "level"    : me->query("jiali") + random(me->query("jiali")),
                          "id"       : me->query("id"),
                          "duration" : lvl / 50 + random(lvl / 20) ]));

       return HIR "���ֻ��$nһ���Һ���ȫ����ҪѨͬʱ�����纮�����У������ιǣ���Ѫ��й������\n" NOR;
}

