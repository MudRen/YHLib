#include <ansi.h>
#include <combat.h>

#define DAN "��" HIW "���ĵ�" NOR "��"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object du;
        int lvl, lvp, damage, pos;
        int an, dn, ap, dp;
        string name, fire, msg;

        if (userp(me) && ! me->query("can_perform/chousui-zhang/dan"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        lvl = me->query_skill("chousui-zhang", 1);
        lvp = me->query_skill("poison");

        if (lvl < 120)
                return notify_fail("��ĳ����Ʋ�����죬����ʩչ" DAN "��\n");

        if (lvp < 180)
                return notify_fail("��Զ������˽ⲻ��������ʩչ" DAN "��\n");

        if ((int)me->query_skill("throwing") < 150)
                return notify_fail("�㰵���ַ���򲻹�������ʩչ" DAN "��\n");

        if (me->query_skill_mapped("strike") != "chousui-zhang")
                return notify_fail("��û�м��������ƣ�����ʩչ" DAN "��\n");

        if (me->query_skill_prepared("strike") != "chousui-zhang")
                return notify_fail("��û��׼�������ƣ�����ʩչ" DAN "��\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ���㣬����ʩչ" DAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ���Ϣ���㣬����ʩչ" DAN "��\n");

        // ����NPC����ֱ��ʩչ
        if (userp(me) && ! objectp(du = me->query_temp("handing")))
                return notify_fail("���������(hand)Щ��ҩ����ʩչ" DAN "��\n");

        if (objectp(du) && ! mapp(du->query("poison")))
                return notify_fail("���������õ�" + du->name() + NOR "��"
                                   "�Ƕ�ҩ������ʩչ" DAN "��\n");

        if (objectp(du) && du->query("no_shot"))
                return notify_fail("��" + du->name() + NOR "�����ȥ����"
                                   "����̫�ðɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        // ���ݳ����ƺͶ����Ĳ�ͬ�����費ͬ����Ϣ
        if (lvl >= 200 && lvp >= 270)
        {
                pos = 300 + random(lvp * 4 / 3);
                fire = "һ��Ө��ɫ��" HIG "����" HIR;
        } else
        if (lvl >= 180 && lvp >= 240)
        {
                pos = 200 + random(lvp * 3 / 4);
                fire = "һ�����ɫ�Ļ���";
        } else
        if (lvl >= 150 && lvp >= 210)
        {
                pos = 100 + random(lvp * 2 / 3);
                fire = "�������ɫ��" NOR + RED "����" HIR;
        } else
        {
                pos = 50 + random(lvp / 2);
                fire = "һ�㰵��ɫ��" NOR + RED "����" HIR;
        }

        if (objectp(du))
                name = du->name();
        else
                name = NOR + RED "����";

        msg = HIR "$N" HIR "����һ����ʩ�������ɾ�����" HIW "���ĵ�"
              HIR "����������" + name + HIR "��ಡ��ĵ����˳�ȥ��\n"
              "ȴ����" + name + HIR "������;������ر��ѿ�������" +
              fire + "ƮȻϮ��$n" HIR "��\n" NOR;

        an = me->query("max_neili") + me->query("neili") / 4;
        dn = target->query("max_neili") + target->query("neili") / 4;

        // �����ж�����������Է�������������Ч
        if (an / 2 + random(an) < dn * 2 / 3)
        {
                msg += WHT "Ȼ��$n" WHT "ȫȻ���������ϣ�����һ�����ѽ�$N"
                       WHT "�����Ļ�������\n" NOR;
                me->start_busy(3);
                me->add("neili", -150);
        } else
        {
                ap = me->query_skill("strike") +
                     me->query_skill("poison") * 3 / 4;

                // ������NPC��������֣��ټ������״��
                if (userp(me))
                        dp = target->query_skill("dodge") +
                             target->query_skill("martial-cognize");
                else
                        dp = target->query_skill("dodge") +
                             target->query_skill("parry");

                damage = pos / 2 + random(pos / 2);

                if (ap / 2 + random(ap) > dp)
                {
                        msg += COMBAT_D->do_damage(me, target, REMOTE_ATTACK, damage, 15,
                                                  (: final, me, target, damage :));
                        me->start_busy(2);
                        me->add("neili", -200);
                } else
                {
                        msg += CYN "����$n" CYN "���Ʋ����æ��Ų���Σ���"
                               "�ڱܿ���$N" CYN "�����Ļ��档\n" NOR;
                        me->start_busy(3);
                        me->add("neili", -100);
                }
        }
        message_combatd(msg, me, target);

        // ���Ķ�ҩ����
        if (objectp(du))
        {
                if (du->query_amount())
                {
                        du->add_amount(-1);

                        if (du->query_amount() < 1)
                                destruct(du);
                } else
                        destruct(du);
        }
        return 1;
}

string final(object me, object target, int damage)
{
        object cloth;
        string name;
        int lvp = me->query_skill("poison");

        if (objectp(cloth = target->query_temp("armor/cloth")))
        {
                if (cloth->query("stable", 1) < 100)
                {
                        cloth->add("consistence", -1 - random(10));

                        if (cloth->query("consistence") < 0)
                                cloth->set("consistence", 0);
                }
                name = cloth->name();
        } else
        if (objectp(cloth = target->query_temp("armor/armor")))
        {
                if (cloth->query("stable", 1) < 100)
                {
                        cloth->add("consistence", -1 - random(10));

                        if (cloth->query("consistence") < 0)
                                cloth->set("consistence", 0);
                }
                name = cloth->name();
        } else
                name = "����";

        target->affect_by("fire_poison",
                ([ "level"    : lvp / 2 + random(lvp / 2),
                   "id"       : me->query("id"),
                   "duration" : 3 + random(lvp / 30) ]));

        target->receive_damage("jing", damage / 2, me);
        target->receive_wound("jing", damage / 3, me);

        return  HIR "$n" HIR "һ�����������Ƕ�ʱ����" + name +
                HIR "֮�ϣ�����ȼ��������Ƥ���յ��������졣\n" NOR;
}
