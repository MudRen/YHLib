#include <ansi.h>
#include <combat.h>

#define CUI "��" HIB "�߻���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int lvl;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/heisha-zhang/cui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(CUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ��" CUI "��\n");

        if (me->query_skill_mapped("strike") != "heisha-zhang")
                return notify_fail("��û�м�����ɰ�ƣ�����ʩչ" CUI "��\n");

        if (me->query_skill_prepared("strike") != "heisha-zhang")
                return notify_fail("������û��׼��ʹ�ú�ɰ�ƣ�����ʩչ" CUI "��\n");

        if ((int)me->query_skill("heisha-zhang", 1) < 100)
                return notify_fail("��ĺ�ɰ�Ʋ�������������ʩչ" CUI "��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("���������Ϊ���㣬����ʩչ" CUI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������ʩչ" CUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIB "$N" HIB "��Ц���������ƶ�Ȼһ�񣬴߻����Ȼ����$n"
              HIB "ǰ�أ����Ű��������\n" NOR;  

        lvl = me->query_skill("heisha-zhang", 1);

        ap = me->query_skill("strike");
        dp = target->query_skill("force");

        me->start_busy(3);
        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap / 2 + random(ap / 3);
                me->add("neili", -100);
                target->affect_by("sha_poison",
                               ([ "level" : me->query("jiali") + random(me->query("jiali")),
                                  "id"    : me->query("id"),
                                  "duration" : lvl / 50 + random(lvl / 20) ]));
                                  msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK,
                                         damage, 20, HIR "$n" HIR "ֻ��$N" HIR "�ƾ���"
                                         "�ض�����һʱ˵���������ܣ�Ż��һ��ں�Ѫ��\n"
                                         NOR);
        } else
        {
                msg += CYN "$n" CYN "��$N"
                       CYN "������ӿ�������񵲣����ڻ��⿪����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
