
#include <ansi.h>

inherit F_SSERVER;

#define TAO "��" HIG "��������" NOR "��"

int unconcious_me(object me);

int perform(object me, object target)
{
        object du;
        int damage;
        int ap;
        string msg;
        int lvl;

        if (userp(me) && ! me->query("can_perform/chousui-zhang/tao"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʩչ" TAO "��\n");

        if ((int)me->query_skill("chousui-zhang", 1) < 220)
                return notify_fail("��ĳ����ƻ�򲻹���\n");

        if ((int)me->query_skill("poison", 1) < 250)
                return notify_fail("��Ļ���������򲻹���\n");

        if ((int)me->query_skill("huagong-dafa", 1) < 220)
                return notify_fail("��Ļ����󷨻�򲻹���\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬�޷�������ʩչ" TAO "��\n");

        if ((int)me->query("neili") < 3000)
                return notify_fail("��������Ϣ���㣬�޷�������ʩչ" TAO "��\n");

        if (me->query_skill_prepared("strike") != "chousui-zhang")
                return notify_fail("�㻹û��׼�������ƣ��޷�ʩչ" TAO "��\n");

        if (! me->query_temp("powerup"))
                return notify_fail("����뽫ȫ���������������ʩչ" TAO "��\n");

        if (! objectp(du = me->query_temp("handing")) && userp(me))
                return notify_fail("������Ҫ����(hand)һЩ��ҩ��Ϊ���ӡ�\n");

        if (objectp(du) && ! mapp(du->query("poison")))
                return notify_fail(du->name() + "�ֲ��Ƕ�ҩ���޷���������棿\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "ֻ��$N" HIR "˫ĿѪ�죬ͷ��ɢ�ң��͵����췢��һ����Х��\n\n"
              "$N" HIR "����һ�ᣬ���Լ�������һҧ��������������"
              "���������ʱֻ��������Ѫ���������ȳ��ޱȣ��漴��\n"
              "��$N" HIR "����������ž����һ���죬˫��˳�������"
              "Ѫ��һ�ƣ�ɲ�Ǽ�һ�������ߵ��涾��ǽ�εض��𣬴�\n"
              "����ɽ����֮����$n" HIR "ӿȥ��\n" NOR;
        me->start_busy(4 + random(4));
        me->set("neili", 0);
        me->add("max_neili", -50);

        lvl = me->query_skill("chousui-zhang", 1);
        damage = 1500 + random(lvl * 3);

        if (me->query("max_neili") + random(me->query("max_neili")) <
            target->query("max_neili") * 18 / 10)
        {
                msg += WHT "$n" WHT "��״��æ����������˫����"
                       "���Ƴ����Ʒ����ȣ�ǿ���������ʱ������"
                       "�εõ�ת����Ȼ��ͷ��$N" WHT "��ȥ��\n\n" NOR;
                msg += HIR "$N" HIR "һ����Ц����̾һ������ǰһ�ڣ������˵��ϡ�\n\n" NOR;
                me->add("max_neili", -random(50));

                remove_call_out("unconcious_me");
                call_out("unconcious_me", 1, me);               

        } else
        {
                ap = me->query_skill("poison", 1) / 2 +
                     me->query_skill("force");
                if (ap + random(ap) < target->query_skill("dodge"))
                {
                        msg += CYN "$n" CYN "���Ʋ����æ��Ų���Σ��ܿ���$N" CYN "�Ĺ�����\n" NOR;
                        me->add("max_neili", -random(50));
                        if (! target->is_busy())
                                target->start_busy(5);
                } else
                {
                        msg += HIR "$n" HIR "��������������ӿ����ֻ����ǰһƬͨ�죬"
                               "�ѱ�������ˣ�����ϯ��ȫ������ͷ��Ҫ����һ�㡣\n" NOR;
                        me->add("max_neili", -random(50));
                        target->affect_by("fire_poison",
                                       ([ "level" : me->query("jiali") * 3 + random(me->query("jiali") * 2),
                                          "id"    : me->query("id"),
                                          "duration" : lvl / 20 + random(lvl) ]));
                        target->receive_damage("qi", damage * 2);
                        target->receive_damage("jing", damage / 2);
                        if (! target->is_busy())
                                target->start_busy(10);
                }
        }

        if (objectp(du)) destruct(du);
        message_vision(msg, me, target);
        me->want_kill(target);
        if (! target->is_killing(me)) target->kill_ob(me);

        return 1;
}

int unconcious_me(object me)
{
        if (! objectp(me))
              return 1;

        if (living(me))
              me->unconcious();

        return 1;
}
