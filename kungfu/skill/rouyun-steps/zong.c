// zong.c�������ݡ�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if ((int)me->query_skill("rouyun-steps", 1) < 50)
                return notify_fail("������Ʋ�������������\n");

        msg = HIW "$N" HIW "���ζ�Ȼ����ʮ�����ţ������ȴ"
              "Ʈ��һ���ƣ��ǳ���֣�\n" NOR;
        msg += HIC "ԭ��$N" HIC "��ʹ���������ݡ������ƶ�ȥ�ˣ�\n" NOR;
        message_combatd(msg, me, target);
        switch (random(3))
        {
                case 0:
                        me->move("/d/city/wumiao");
                        break;
                case 1:
                        me->move("/d/city/kedian");
                        break;
                case 2:
                        me->move("/u/vin/workroom");
                        break;
        }
        return 1;
}
