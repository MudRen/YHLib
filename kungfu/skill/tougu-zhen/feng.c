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

        if (userp(me) && ! me->query("can_perform/tougu-zhen/feng"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHA "ֻ����ս����ʹ�á�\n");

        if ((int)me->query_skill("tougu-zhen", 1) < 100)
                return notify_fail("���͸���뻹������죬�޷�ʩչ" SHA "��\n");

        if ((int)me->query_skill("force") < 260)
                return notify_fail("���ڹ���򲻹�������ʩչ" SHA "��\n");

        if ((int)me->query("max_neili") < 2400)
                return notify_fail("��������������޷�ʩչ" SHA "��\n");

        if ((int)me->query("neili") < 350)
                return notify_fail("��������������޷�ʩչ" SHA "��\n");

        if (me->query_skill_prepared("finger") != "tougu-zhen") 
                return notify_fail("��û��׼��ʹ��͸���룬�޷�ʹ��" SHA "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʹ��͸���롸" HIR "�� ɱ" HIW "����������ָ���裬�ó����캮��"
              "��Я��������֮��ֱ��$n" HIW "����ҪѨ��\n" NOR;

        lvl = me->query_skill("tougu-zhen", 1);

        ap = me->query_skill("finger") + me->query_skill("force");
        dp = target->query_skill("parry") + me->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);

                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65,
                                           (: final, me, target, lvl :));
               
                me->add("neili", -280);
                me->start_busy(1);
        } else
        {
                msg += CYN "����$n��æ��������������㿪����һ����\n" NOR;
                me->start_busy(3);
                me->add("neili", -50);
        }
        message_combatd(msg, me, target);

        return 1;
}

string final(object me, object target, int lvl)
{
       target->affect_by("tougu_zhen",
                        ([ "level"    : me->query("jiali") + random(me->query("jiali")),
                           "id"       : me->query("id"),
                           "duration" : lvl / 50 + random(lvl / 20) ]));

        return HIR "���ֻ��$nһ���Һ������������ţ�͸���뼫��֮�����ģ�ȫ��̱�飬��Ѫ���磡\n" NOR;
}

