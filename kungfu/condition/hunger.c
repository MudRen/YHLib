// hunger.c

#include <condition.h>
#include <ansi.h>

int dispel() { return 0; }

int update_condition(object me, int duration)
{
        if (me->query("food") > 0 && me->query("water") > 0)
                return 0;

	if (! interactive(me) ||
	    ! environment(me) ||
	    environment(me)->is_chat_room())
		return CND_CONTINUE;

	if (duration == 4)
	{
                if (me->query("food") <= 0 && me->query("water") <= 0)
			tell_object(me, HIY "�����ͷ���ۻ����ʵú���ð�̣�����"
                                    "Ҫ�Ͽ��ҵ�ԺȵĶ����ˡ�\n"NOR);
                else
                if (me->query("food") <= 0)
			tell_object(me, HIY "�����ͷ���ۻ�������Ҫ�Ͽ��ҵ�Ե��ˡ�\n" NOR);
                else
		if (me->query("water") <= 0)
			tell_object(me, HIY "\n��ʵú���ð�̣�����Ҫ�Ͽ�ȵ�ʲô�ˡ�\n" NOR);
	}
	else
	if (duration == 7)
	{
                if (me->query("food") <= 0 && me->query("water") <= 0)
			tell_object(me, HIR "���ּ��ֿʣ������Լ���Ҫ���ˡ�\n"NOR);
                else
                if (me->query("food") <= 0)
			tell_object(me, HIR "����ÿ����ˡ�\n"NOR);
                else
		if (me->query("water") <= 0)
			tell_object(me, HIR "��ʵ�Ҫ�����ˡ�\n"NOR);
	}
	else
	if (duration >= 13)
	{
                if (wizardp(me))
                {
                        tell_object(me, HIY "���ۿ���Ҫ�����ˣ�����������ʦ���䣡"
                                        "�䣡�䣡���������ڰѱ����\n" +
                                        "�Ĳ�֪��ʲô���������¶ǣ��о��ö��ˡ�\n" NOR);
                        me->set("food", me->max_food_capacity());
                        me->set("water", me->max_food_capacity());
                        return 0;
                }

                if (me->query("mud_age") < 86400)
                {
                        tell_object(me, HIY "���ۿ���Ҫ�����ˣ�ͻȻ���µ����ڱ�ţ"
                                        "�̣���һ�����ĺȣ��о���\n" +
                                        "���Ǻö��ˡ�\n" NOR);
                        me->set("food", me->max_food_capacity());
                        me->set("water", me->max_food_capacity());
                        return 0;
                }

                if (me->query("food") <= 0 && me->query("water") == 0)
			tell_object(me, HIR "���ּ��ֿʣ��������˹�ȥ��\n"NOR);
                else
                if (me->query("food") <= 0)
			tell_object(me, HIR "��������˹�ȥ��\n"NOR);
                else
		if (me->query("water") <= 0)
			tell_object(me, HIR "��ʵ����˹�ȥ��\n"NOR);
		me->receive_damage("qi", 0);
                me->unconcious();
                return 0;
	}
        
        me->apply_condition("hunger", duration + 1);
	return CND_CONTINUE;
}
