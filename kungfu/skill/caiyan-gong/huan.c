#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIM "��ϼ����" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon, weapon2;
        int skill, ap, dp, damage;
        string wn, msg;

        if (userp(me) && ! me->query("can_perform/caiyan-gong/huan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "club")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUAN "��\n");

        skill = me->query_skill("caiyan-gong", 1);

        if (skill < 120)
                return notify_fail("����๦�ȼ�����������ʩչ" HUAN "��\n");

        if (me->query_skill("dodge") < 180)
                return notify_fail("����Ṧ��򲻹�������ʩչ" HUAN "��\n");
 
        if (me->query_skill_mapped("club") != "caiyan-gong")
                return notify_fail("��û�м������๦������ʩչ" HUAN "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" HUAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        message_sort(HIM "\n$N" HIM "���ʩ����" HIW "��ϼ����"
                     HIM "������������" + wn + HIM "��һ�����"
                     "�ɶ����ģ����ı�ˣ��ɰ˱�ʮ���������ó�"
                     "������" + wn + HIM "����Ӱ������������"
                     "���̶�������ͼ����$n" HIM "����·��\n" NOR,
                     me, target);

        ap = me->query_skill("club");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap * 4 / 3) > dp)
        {
                me->add("neili", -80);
                damage = 50 + ap / 6 + random(ap / 6);
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 45,
                                           (: final, me, target, damage :));

                me->start_busy(2);
        } else
        {
                msg = CYN "$n" CYN "��֮�¼�æԾ�����������Ű���$N"
                      CYN "��Ӱ�ķ�Χ��\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        string msg;

        msg = HIR "$p��ʧɫ֮�½�����$P��������"
              "��������ʹ�ѵ���";

        if (random(3) >= 1 && ! target->is_busy())
        {
                target->start_busy(damage / 15);
                msg += "��Ͼ������\n" NOR;
        } else
                msg += "����������\n" NOR;

        return  msg;
}
