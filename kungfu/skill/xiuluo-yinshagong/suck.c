#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int exert(object me, object target)
{
        mapping p;
        string msg;
        object ob;
        int amount;
        int exp;
        int lvl;
        int sk;

        if (! target || target == me)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target)
                return notify_fail("��Ҫȡ��ֻ��Ķ�Һ��ҩ��\n");

        if (! target->is_worm())
                return notify_fail("�����Щ���ǿɲ��Ƕ��档\n");

        if (living(target))
                return notify_fail("��ֻ�滹�������أ�����������\n");

        if ((int)me->query_skill("wudu-qishu", 1) < 100)
                return notify_fail("����嶾����������죬�������ƶ�ҩ��\n");

        if ((int)me->query_skill("xiuluo-yinshagong", 1) < 100)
                return notify_fail("��������ɷ����Ϊ�������������ƶ�ҩ��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�������������㣬�������ƶ�ҩ��\n");

        me->add("neili", -50);
        me->start_busy(random(3));

        msg = HIR "\n$N" HIR "���ʳָ������" + target->name() +
              HIR "������Ĭ�������ȳ���Һ��ҩ��\n" NOR;

        p = target->query("worm_poison");
        if (! mapp(p))
                return notify_fail("��������Ū����ʲô��Һ���ˡ�\n" NOR);

        lvl = (int)me->query_skill("poison", 1) / 3 +
              (int)me->query_skill("wudu-qishu", 1) / 3 +
              (int)me->query_skill("xiuluo-yinshagong", 1) / 3;

        amount = p["level"] * p["remain"];
        if (amount > lvl)
                amount = lvl;
        
        p["remain"] = (p["level"] * p["remain"] - amount) /
                       p["level"];
        target->apply_condition("poison-supply", 1);

        if (! amount)
        {
                msg += WHT "$N" WHT "���˰��죬���ɶҲû�м�����������"
                       "��æ���ˡ�\n\n" NOR;
                message_vision(msg, me);
                return 1;
        }

        if (amount < lvl)
        {
                msg += WHT "$N" WHT "����һ�㶾Һ������\n" NOR;
                message_vision(msg, me);
                tell_object(me, HIY "��ϧ��㶾Һ����һ�Ŷ�ҩ��������\n\n" NOR);
                return 1;
        }

        msg += HIW "$N" HIW "��" + target->name() + HIW "�Ķ�Һ�Ƴ�����"
               "�����������»�����һ�ž�Ө��͸��ҩ�衣\n" NOR;
        message_vision(msg, me);
        tell_object(me, HIC "��������һ�ų涾ҩ�衣\n\n" NOR);

        exp = lvl / 4;
        me->improve_skill("poison", 2 + random(exp));
        if (me->can_improve_skill("wudu-qishu"))
                me->improve_skill("wudu-qishu", 2 + random(exp / 2));

        if (me->can_improve_skill("xiuluo-yinshagong"))
                me->improve_skill("xiuluo-yinshagong", 2 + random(exp / 3), 1);

        ob = new("/clone/misc/chongdu");
        ob->set("poison", ([
                "level" : lvl,
                "id"    : me->query("id"),
                "name"  : "�涾",
                "duration" : 10,
        ]));
        ob->move(me, 1);

        return 1;
}

