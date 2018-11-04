#include <ansi.h>
#include <combat.h>

#define LING "��" HIW "�����貨" NOR "��"

inherit F_SSERVER;

void remove_effect(object me, int amount, int amount1);


int perform(object me, object target)
{
        string msg;
	int level, count;
        
        if (userp(me) && ! me->query("can_perform/lingbo-weibu/ling"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if ((level = me->query_skill("lingbo-weibu", 1)) < 120)
                return notify_fail("����貨΢������������������ʩչ" LING "��\n" NOR);

        if ((int)me->query("neili") < 600)
                return notify_fail("�������������㣬����ʩչ" LING "��\n" NOR);

        if (me->query_temp("lingbo"))
                return notify_fail("���Ѿ����������貨���ˡ�\n");

        if( me->query("gender") == "Ů��")
               msg = HIW "\n$N" HIW "�����������������������ʮ"
                     "���ԣ����貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�"
                     "$N" HIW "�����������������ζ�ʱ��ӯ�ޱȣ�"
                     "΢���貨���������ң���ַ��ӵ����쾡����\n" NOR;

        else   msg = HIC "\n$N" HIC "�����������������������ʮ"
                     "���ԣ����貨΢����ͷ��βѸ���ޱȵ�����һ�Ρ�"
                     "ֻ��$N" HIC "��̬Ʈ�ݣ�Ӱ���ҷɣ����ζ�ʱ��"
                     "ӯ�ޱȣ��������ң���ַ��ӵ����쾡����\n" NOR;

        message_sort(msg, me);

        count = level / 30;

        if (me->is_fighting())
                me->start_busy(2);

        me->add_temp("dex", count);
        me->set_temp("lingbo", 1);
        me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), level / 2);

        me->add("neili", -400);
        return 1;

}
void remove_effect(object me, int amount, int amount1)
{
        if ((int)me->query_temp("lingbo"))
        {
                me->add_temp("dex", -amount);
                me->delete_temp("lingbo");
                tell_object(me, "��ġ������貨���˹���ϣ��������ջص��\n");
        }
}
