#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("�ٻ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_prepared("unarmed") != "baihua-quan" &&
            me->query_skill_prepared("cuff") != "baihua-quan" &&
            me->query_skill_prepared("strike") != "baihua-quan" &&
            me->query_skill_prepared("claw") != "baihua-quan" &&
            me->query_skill_prepared("hand") != "baihua-quan")
                return notify_fail("������û��׼��ʹ�ðٻ���ȭ���޷�ʩչ�ٻ����ң�\n");
 
        if (me->query_temp("weapon"))
                return notify_fail("�ٻ��������ǿ��ֲ���ʩչ��\n");

        if (me->query("neili") < 300)
                return notify_fail("��������������޷�ʩչ�ٻ����ҡ�\n");

        if ((lvl = me->query_skill("baihua-quan", 1)) < 160)
                return notify_fail("��İٻ���ȭ���������죡\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "ֻ��$Nʹ���ٻ���ȭ�ľ���ٻ����ң��������м���ӥצ�������ֲ�ȭ���������ơ���\n"
                  "��ȥ�ǰ����ƣ��ջ�ʱ����̫��ȭ������ӳ£����޹��ɣ�ֻ��$n�ۻ����ҡ�\n\n" NOR;
        i = 10;
        if (lvl * 2 / 3 - random(lvl) > (int)target->query_skill("parry") / 2)
        {
                msg += HIW "$nֻ�е�ͷ��Ŀѣ��ֻ��$N���ơ���צ����ȭ����ָ����ǵص����Լ�������λϮ����\n"
                           "ֻһ˲�䣬ȫ���Ѷ�����ʮ���˺ۣ�"NOR+HIR"��Ѫ"NOR+HIW"��к��ֹ��\n"NOR;
                count = me->query_skill("baihua-quan", 1) / 6;
                me->add_temp("apply/attack", count);
                i += random(5);
        } else
        {
                msg += HIY "$nֻ��$N��ȭ�籼����ȭ�ͷ׵ݳ�����æ����������ǿ�ֵ���\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        me->add("neili", -300);

        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 5 && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(6));
        return 1;
}


