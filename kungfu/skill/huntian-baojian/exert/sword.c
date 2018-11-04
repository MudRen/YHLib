#include <ansi.h>

inherit F_CLEAN_UP;

void dest_sword(object me);

int exert(object me, object target)
{
        object weapon;

        if (target != me)
                return notify_fail("�����ɽ�ֻ�ܶ��Լ�ʹ�á�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�������������\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������Ѿ��������ˡ�\n");

        if (present("jian qi", me))
                return notify_fail("�������Ѿ���һ�������ˡ�\n");

        me->add("neili", -30);

        message_combatd(HIW "$N" HIW "ʳָ��㣬ָ���ʱ����������²�����"
                        "��â������һ�����ν�����\n" NOR, me);

        weapon = new("/clone/weapon/jianqi");
        weapon->move(me);
        weapon->wield();

        me->start_call_out((: call_other, __FILE__, "dest_sword",
                              me :), 50);

        if (me->is_fighting())
                me->start_busy(1);

        return 1;
}

void dest_sword(object me)
{
        object weapon;

        if (objectp(weapon = me->query_temp("weapon"))
           && (string)weapon->query("skill_type") == "sword"
           && (string)weapon->query("id") == "jian qi")
        {
                if (me->is_fighting())
                        me->start_call_out((: call_other, __FILE__, "dest_sword",
                                              me :), 2);
                else
                        destruct(weapon);
        }
}
