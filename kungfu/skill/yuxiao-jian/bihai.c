#include <ansi.h>
#include <combat.h>

#define BIHAI "��" HIW "�̺�����������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int damage, skill;
        object ob;

        if (userp(me) && ! me->query("can_perform/yuxiao-jian/bihai"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(BIHAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(ob = me->query_temp("handing")) || ! ob->valid_as_xiao())
        {
                if (! objectp(ob = me->query_temp("weapon"))
                   || ! ob->valid_as_xiao())
                {
                        // ����ı���Ҳ������Ϊ��ʹ��
                        return notify_fail("������û������������ʩչ" BIHAI "��\n");
                }
        }

        skill = me->query_skill("yuxiao-jian", 1);

        if (skill < 180)
                return notify_fail("�����｣���ȼ�����, ����ʩչ" BIHAI "��\n");

        if ((int)me->query_skill("bibo-shengong", 1) < 180)
                return notify_fail("��̲�����Ϊ����������ʩչ" BIHAI "��\n");

        if ((int)me->query_skill("bihai-chaosheng", 1) < 180)
                return notify_fail("��ı̺�������̫�ͣ�����ʩչ" BIHAI "��\n");

        if (me->query_skill_mapped("sword") != "yuxiao-jian")
                return notify_fail("��û�м������｣��������ʩչ" BIHAI "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ���������������ʩչ" BIHAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("yuxiao-jian", 1) +
             me->query_skill("bibo-shengong", 1) +
             me->query_skill("bihai-chaosheng", 1);

        dp = target->query_skill("force") +
             target->query_skill("parry") +
             target->query_skill("bihai-chaosheng", 1);

        damage = 0;

        msg = HIW "\nֻ��$N" HIW "�ְ������̤�����ķ�֮λ�����"
              "һ�����̺�����������������������������ٻ�������"
              "���˼����������������Ʈ��������͵Ķ���������\n" NOR;

        if (ap + random(ap) > dp)
        {
                msg += HIR "$n" HIR "ֻ����ͷһ�������鲻�Խ���¶"
                       "����һ˿΢Ц��\n" NOR;
                damage += ap / 5 + random(ap / 5);
        } else
                msg += HIC "$n" HIC "����������һ��������������Ӧ��"
                       "ԣ�硣\n" NOR;

        msg += HIW "\nͻȻ�����Ƕ���������Ʈ����������ת������һ��Ů"
               "��һ���̾Ϣ��һ�������������һ���ȴ�������´����"
               "���л���\n" NOR;

        if (ap + random(ap / 2) > dp)
        {
                msg += HIR "$n" HIR "ֻ��ȫ����Ѫ���ڣ���ֻ��������"
                       "�����Ҷ�һ����\n" NOR;
                damage += ap / 4 + random(ap / 4);
        } else
                msg += HIC "$n" HIC "����������һ��������������Ӧ��"
                       "ԣ�硣\n" NOR;

        msg += HIW "\n��������������󺣺��������޲���Զ����ˮ����"
               "�ƽ����������죬��������ӿ��������ɽ������ˮ����Ծ"
               "�����������ХŸ�ɣ�ˮ������ȺħŪ�����������֮����"
               "��\n" NOR;

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "��ʱ��$n" HIR "ֻ����ͷ���ȣ�������"
                       "˵���������ܡ�\n" NOR;
                damage += ap / 3 + random(ap / 3);
        } else
                msg += HIC "$n" HIC "����������һ��������������Ӧ��"
                       "ԣ�硣\n" NOR;

        msg += HIW "\nʱ�����ȴ��������������ϸ�������������ţ���"
               "����󺣳��˺�ˮƽ�羵һ�㣬������ȴ���ǰ����ļ�����"
               "ӿ���ȡ�\n" NOR;

        if (ap / 2 + random(ap / 2) > dp)
        {
                msg += HIR "��ʱ$n" HIR "�����ݾ�����ȫ����Ѫ������"
                       "��Ҳ�޷�����\n" NOR;
                damage += ap / 2 + random(ap / 2);
        } else
                msg += HIC "$n" HIC "����������һ��������������Ӧ��"
                       "ԣ�硣\n" NOR;

        target->receive_damage("jing", damage * 2 / 3, me);
        target->receive_wound("jing", damage / 2, me);

        me->start_busy(3 + random(3));
        me->add("neili", -200);

        message_sort(msg, me, target);
        return 1;
}
