// dispel.c

#include <ansi.h>

int exert(object me, object target)
{
        int i;
        int still_ill;
        string force_name;
        string *cnds;
        mapping conditions;

        if (me->query("neili") < 300)
        {
                write("����������㣬�޷�����һ�����졣\n");
                return 1;
        }

        force_name = to_chinese(me->query_skill_mapped("force"));

        if (me == target)
        {
                message_vision(HIW "$N" HIW "����һ�������ֻ��������˳�����\n" NOR, me);
                tell_object(me, YEL "��Ĭ��" + force_name + YEL "����ʼ�ų���"
                                "���е��쳣֢״��\n" NOR);
                me->add("neili", -100);
        } else
        {
        	if (me->is_fighting(target))
        	{
        		write("��������������أ�������˼�������\n");
                        return 1;
                }

                if (target->is_fighting())
                {
                	write("�Է����ڴ�ܣ����ǵ�����������˵�ɡ�\n");
                        return 1;
                }

                if (target->is_busy())
                {
                	write("�Է�������æ���أ���������Щ��˵�ɡ�\n");
                        return 1;
                }

                message_vision(HIW "$N" HIW "����һ������������ճ��$n"
                               HIW "�ı���\n" NOR, me, target);
                tell_object(me, YEL "��Ĭ��" + force_name + YEL "����"
                                "ʼ����" + target->name() + YEL "�ų�"
                                "�����е��쳣֢״��\n" NOR);
                tell_object(target, YEL + me->name() + YEL "�����˹���"
                                    "�����ų������е��쳣֢״��\n" NOR);
                me->add("neili", -250);
        }

        still_ill = 0;
        conditions = target->query_condition(); 
        if (conditions)
        {
                cnds = keys(conditions);
                for (i = 0; i < sizeof(cnds); i++)
                {
                        switch(target->dispel_condition(me, cnds[i]))
                        {
                        case 0:
                                continue;
                        case -1:
                                still_ill = 1;
                                continue;
                        }
        
                        if (me == target)
                        {
                                tell_object(me, WHT "���Ϣ��ϣ��������ջص�"
					    "�\n" NOR);
                                me->start_busy(1 + random(2));
                        } else
                        {
                                tell_object(me, WHT "���Ϣ��ϣ��������ջ�"
					    "���\n" NOR);
                                tell_object(target, WHT "�������Ϣһ����������" +
                                            me->name() + "�չ��ˡ�\n");
                                me->start_busy(2 + random(3));
                                target->start_busy(1 + random(2));
                                message_vision(WHT "$N" WHT "�����ƴ�$n" WHT "����"
                                               "���˻�����\n" NOR, me, target);
                        }
                        return 1;
                }
        }

        if (still_ill)
        {
                if (me == target)
                {
                        tell_object(me, MAG "���Ϣ���ã�û��һ��Ч����\n" NOR);
                        message_vision(HIG "$N" HIG "��ɫ���˱䣬��Щ��"
				       "̫��Ȼ��\n" NOR, me);
                        me->start_busy(3 + random(3));
                } else
                {
                        tell_object(me, MAG "���˹����ã�û�ܷ��Ӱ�����á�\n" NOR);
                        tell_object(target, MAG "�������Ϣһ�����ң�˵����"
				            "�����ܡ�\n����" + me->name() +
					    "�ǲ��ܸ���������ˡ�\n" NOR);

                        message_vision(HIG "$N�����ƴ�$n�������˻�������ɫ"
					   "˵�������ѿ���\n" NOR, me, target);

                        me->start_busy(6 + random(6));
                        target->start_busy(4 + random(4));
                }
        } else
        {
                if (me == target)
                {
                        tell_object(me, "�����û�����Լ����κ��쳣��\n");
                        message_vision(WHT "$N" WHT "ü��΢΢һ�����漴��"
				       "��������\n" NOR, me);
                        me->start_busy(1);
                } else
                {
                        tell_object(me, "�����û����" + target->name() +
                                   "���κ��쳣��\n");
                        tell_object(target, "�������Ϣһ����������" +
                                    me->name() + "�չ��ˣ�����㱾��û��ʲ"
				    "ô�쳣�ɡ�\n");
                        message_vision(WHT "$N" WHT "�����ƴ�$n" WHT "��������"
				       "������\n" NOR, me, target);
                        me->start_busy(2);
                        target->start_busy(1);
                }
        }

	return 1;
}
