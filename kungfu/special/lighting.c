// lighting.c ��������
// Created by Vin 8/5/2002

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
inherit F_SSERVER;

string name() { return HIW "�B�i�W�" NOR; }

#define LIGHTING "��" HIW "�B�i�W�" NOR "��"

int perform(object me, object target)
{
        string msg;
        int damage;

        if (! wizardp(me) && me->query("id") != "vin")
                return notify_fail(LIGHTING "ֻ������ʦʩչ��\n");

        if (! me->is_fighting())
                return notify_fail(LIGHTING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        target = me->select_opponent();

        if (! target || ! target->is_character()
           || target->query("not_living"))
                return notify_fail("������˭ʩչ" LIGHTING  "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "ʩչ���g��" HIW "�B�i�W�" NOR +
              WHT "���������b�����ȵ�ķ�������ɡ�̩�ﰢ�ա����ء�\n" NOR;

        me->start_busy(1);

        if (wiz_level(target) <= wiz_level(me)
           && target->query("id") != "vin")
        {
                damage = 8000 + random(8000);
                target->receive_wound("qi", damage, me);
                target->receive_wound("jing", damage / 2, me);

                msg += HIW "���rֻҊ�����W늏���������M������$n"
                       HIW "���ϣ�ֱ����$n" HIW "�߸[������Ѫ���ĞR��\n" NOR;
        } else
        {
                msg += HIW "���rֻҊ�����W늏���������M������$n"
                       HIW "���ϣ�����ɢ�^��$n" HIW "�s��һ�c����Ҳ�]�С�\n" NOR;
        }
        message_combatd(msg, me, target);
        me->want_kill(target);

        if (! target->is_killing(me))
                target->kill_ob(me);
        return 1;
}
