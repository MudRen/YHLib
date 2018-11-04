#include <ansi.h>
#include <combat.h>

#define HUI "��" HIR "�桤�����ֻ�" NOR "��"

inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);
string attack3(object me, object target, int damage);
string attack4(object me, object target, int damage);
string attack5(object me, object target, int damage);
string attack6(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string wn, msg;
        object sroom, room;
        int ap, dp, damage;

        if (userp(me) && ! me->query("can_perform/lunhui-jian/hui"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUI "��\n");

        if ((int)me->query_skill("force") < 750)
                return notify_fail("����ڹ���Ϊ����������ʩչ" HUI "��\n");

        if ((int)me->query("max_neili") < 10000)
                return notify_fail("���������Ϊ����������ʩչ" HUI "��\n");

        if ((int)me->query_skill("buddhism", 1) < 500)
                return notify_fail("��������ķ����򲻹�������ʩչ" HUI "��\n");

        if ((int)me->query_skill("lunhui-jian", 1) < 500)
                return notify_fail("�������ֻؽ���򲻹�������ʩչ" HUI "��\n");

        if (me->query_skill_mapped("sword") != "lunhui-jian")
                return notify_fail("��û�м��������ֻؽ�������ʩչ" HUI "��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("��������������������ʩչ" HUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        message_combatd(HIW "$N" HIW "��¶�黨֮�⣬��������" + wn +
                        HIW "����ʱ�̲���ת���������ɣ�˵��������͡�"
                        "\n" NOR, me, target);

        //  ��¼������ķ���
        if (! objectp(sroom = environment(me)))
                return 1;

        ap = me->query_skill("sword") +
             me->query_skill("buddhism", 1);

        dp = target->query_skill("parry") +
             target->query_skill("buddhism", 1);

        damage = ap + random(ap);

        // �����ֻ�֮�˼��
        room = find_object("/d/special/liudaolunhui/rendao");
        if (! room) room = load_object("/d/special/liudaolunhui/rendao");

        me->move(room);
        target->move(room);

        message_vision(HIY "\n$N" HIY "��������һ�����������ֵ�" + wn +
                       HIY "�������죬����˵����������������\n" NOR, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                           (: attack1, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_vision(msg, me, target);

        // �����ֻ�֮������
        room = find_object("/d/special/liudaolunhui/chushengdao");
        if (! room) room = load_object("/d/special/liudaolunhui/chushengdao");

        me->move(room);
        target->move(room);

        message_vision(HIY "\nȴ��$N" HIY "���ޱ��飬������" + wn +
                       HIY "�͵���ǰһ�ݣ����綾�߰�����$n" HIY "��\n"
                       NOR, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                           (: attack2, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_vision(msg, me, target);

        // �����ֻ�֮�����
        room = find_object("/d/special/liudaolunhui/eguidao");
        if (! room) room = load_object("/d/special/liudaolunhui/eguidao");

        me->move(room);
        target->move(room);

        message_vision(HIY "\n$N" HIY "һ����̾���������Ž���������" +
                       wn + HIY "��Ѫ��֮����Ũ����$n" HIY "ӭͷն�䡣\n"
                       NOR, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                           (: attack3, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_vision(msg, me, target);

        // �����ֻ�֮���޵�
        room = find_object("/d/special/liudaolunhui/xiuluodao");
        if (! room) room = load_object("/d/special/liudaolunhui/xiuluodao");

        me->move(room);
        target->move(room);

        message_vision(HIY "\n����$N" HIY "����΢�Σ���ʱ�ó�ʮ������"
                       "Ӱ��ʮ����" + wn + HIY "����$n" HIY "��ȥ��"
                       "\n" NOR, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                           (: attack4, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_vision(msg, me, target);

        // �����ֻ�֮������
        room = find_object("/d/special/liudaolunhui/diyudao");
        if (! room) room = load_object("/d/special/liudaolunhui/diyudao");

        me->move(room);
        target->move(room);

        message_vision(HIY "\n������$N" HIY + wn + HIY "һ������������"
                       "����������һ�����캮������������ɢ��ȥ��\n" NOR,
                       me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                           (: attack5, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_vision(msg, me, target);

        // �����ֻ�֮�켫��
        room = find_object("/d/special/liudaolunhui/tiandao");
        if (! room) room = load_object("/d/special/liudaolunhui/tiandao");

        me->move(room);
        target->move(room);

        message_vision(HIY "\n$N" HIY "���⻯�����⻯��������" + wn +
                       HIY "���������ڿգ����Ƽ��գ����Ϊ֮ʧɫ��\n"
                       NOR, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 300,
                                           (: attack6, me, target, damage :));
        } else
        {
                msg = CYN "����$n" CYN "�������񣬷�����"
                      "�ܣ�������ж�����Ρ�\n" NOR;
        }
        message_vision(msg, me, target);

        me->start_busy(3 + random(3));
        me->add("neili", -500 - random(500));

        // Ϊʲô���У�Ϊ�˻����Ϊ������Ŀ����
        tell_object(me, "\n\n");
        tell_object(target, "\n\n");

        // ת�ƻ�����ķ���
        me->move(sroom);
        target->move(sroom);

        // ����ͨ������������
        if (target->query("qi") < 0)
                target->die(me);

        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "ֻ����ͷһ����࣬���̲�סҪ��"
              "������������һ��Ż��һ����Ѫ��\n" NOR;

        if (! target->query_temp("liudaolunhui"))
        {
                msg += WHT "$p��Ȼ�����ȫ�����������һ˿"
                       "˿Զ���Լ���ȥ������֮����\n" NOR;

                target->add_temp("apply/attack", -damage);
                target->add_temp("apply/parry", -damage);
                target->add_temp("apply/dodge", -damage);
                target->set_temp("liudaolunhui", 1);
        }
        return msg;
}

string attack2(object me, object target, int damage)
{
        object weapon;
        string wn, msg;

        msg = HIR "��Ȼ��$n" HIR "�е��ؿڴ�һ����ȣ�����"
              "Ϯ�壬����һ��Ѫ�ꡣ\n" NOR;

        if (objectp(weapon = target->query_temp("weapon")))
        {
                wn = weapon->name();
                msg += WHT "�����������ϡ��������죬$n" WHT "��" + wn +
                       WHT "����$N" WHT "�ʳ��˿����Ƭ��\n" NOR;

                weapon->set("consistence", 0);
                weapon->move(target);
        }
        return msg;
}

string attack3(object me, object target, int damage)
{
        int shd;
        string msg;

        msg = HIR "�����������������Ѫ�ˣ�$n" HIR "ֻ��ͷ��Ŀ"
              "ѣ����֫������������ս��\n" NOR;

        if (target->query_temp("shield"))
        {
                shd = target->query_temp("apply/armor");

                target->add_temp("apply/armor", -shd);
                target->delete_temp("shield");

                msg += WHT "$N" WHT "����ӿ�������������ʱ��$n"
                       WHT "�Ļ��������ݻٵõ�Ȼ�޴档\n" NOR;
        }
        return msg;
}

string attack4(object me, object target, int damage)
{
        object cloth, armor;
        string cn, an, msg;

        msg = HIR "$n" HIR "��ʱ��ʧɫ��˲���ѱ�$N" HIR "����"
              "������ֱ����Ѫ��ģ����\n" NOR;

        if (objectp(cloth = target->query_temp("armor/cloth")))
        {
                cn = cloth->name();
                msg += WHT "������Ȼ��������$n" WHT "���ŵ�" + cn +
                       WHT "��$N" WHT "���������£�������÷��顣\n"
                       NOR;

                cloth->set("consistence", 0);
                cloth->move(target);
        } else
        if (objectp(armor = target->query_temp("armor/armor")))
        {
                an = armor->name();
                msg += WHT "������������һ�����죬$n" WHT "���ŵ�" +
                       an + WHT "����$N" WHT "���ѣ����ɿ����Ƭ��\n"
                       NOR;

                armor->set("consistence", 0);
                armor->move(target);
        }
        return msg;
}

string attack5(object me, object target, int damage)
{
        string msg;

        msg = HIR "ֻ��$n" HIR "ȫ��һ��鴤����������Я�ļ�������"
              "�������У���ʹ�ѵ���\n" NOR;

        if (! target->query_condition("poison"))
        {
                target->affect_by("poison",
                	([ "level"    : damage * 2,
                           "name"     : "��������",
                           "id"       : me->query("id"),
                           "duration" : damage / 20 ]));

                msg += WHT "��ʱ��$n" WHT "����һ���溮ɢ���߾�����"
                       "���·���ѪҺ��ֹͣ��������\n" NOR;
        }
        return msg;
}

string attack6(object me, object target, int damage)
{

        string msg;

        msg = HIR "$N" HIR "����Ѹ��֮������$n" HIR "�����м���أ�"
              "�����ӵ��������ִ��С�\n" NOR;

        if (! target->query_temp("no_exert")
           || ! target->query_temp("no_perform"))
        {
                target->set_temp("no_exert", 1);
                target->set_temp("no_perform", 1);

                msg += WHT "$n" WHT "ֻ�е�ȫ��������ɢ����Ԫ�߽⣬��"
                       "�����е��书�������Ŵ�����\n" NOR;
        }
        return msg;
}
