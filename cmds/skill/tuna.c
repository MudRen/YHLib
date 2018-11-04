// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

private int respirate_cost;
int respirating(object me);
int halt_respirate(object me);

int main(object me, string arg)
{
	seteuid(getuid());
	
	if ((int)me->query("age") < 24)
		return notify_fail("�����ڻ����ᣬ�Ժ������ɣ�\n");

	if (environment(me)->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (me->is_busy())
		return notify_fail("��������æ���أ�\n");

	if (me->is_fighting())
		return notify_fail("ս�������ɣ�����ֻ�����ɲ���������\n");

	if (! arg || ! sscanf(arg, "%d", respirate_cost))
		return notify_fail("��Ҫ�����پ����У�\n");

	if (respirate_cost <= 0)
		return notify_fail("�㲻�����ɣ�\n");

	if ((int)me->query("jing") < respirate_cost)
		return notify_fail("�����ھ����㣬�޷����о�����\n");

	if ((int)me->query("qi") * 100 / (int)me->query("max_qi") < 70)
		return notify_fail("����������״��̫���ˣ��޷����о���\n");

        if (environment(me)->query("no_fight") && me->query("doing") != "scheme")
                return notify_fail("���޷�������ط��������ɡ�\n");

	write("������۾���ʼ������\n");
	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
        me->set_short_desc("�����ڵ�������������");
	message_vision("$N��ϥ���£���ʼ����������\n", me);
	me->start_busy(bind((:call_other, __FILE__, "respirating" :), me),
                       bind((:call_other, __FILE__, "halt_respirate" :), me));
	return 1;
}

int respirating(object me)
{
	int respirate_cost = (int)me->query_temp("respirate_cost");
	int jingli_gain = (int)me->query_skill("force") / 10;
        jingli_gain = 1 + jingli_gain / 2 + random(jingli_gain);

	if (respirate_cost > 0)
        {
                if (jingli_gain > respirate_cost)
                        jingli_gain = respirate_cost;
        
                if (jingli_gain > me->query("jing"))
                {
                        jingli_gain = me->query("jing");
                        respirate_cost = 0;
                        me->set_temp("respirate_cost", 0);
                        me->set_short_desc(0);
                } else
                {
                        me->set_temp("respirate_cost",
                                     respirate_cost -= jingli_gain);
                }
        
        	me->add("jingli", jingli_gain);
        	me->add("jing", -jingli_gain);
        
        	if (respirate_cost > 0)
        		return 1;
        }

	me->set_temp("pending/respirate", 0);
        me->set_short_desc(0);
	respirate_cost = 0;
	message_vision("$N������ϣ�����˫�ۣ�վ��������\n", me);
	if((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else
        {
		if ((int)me->query("max_jingli") > (int)me->query_current_jingli_limit())
		{
			write("��ľ�����Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
			me->set("jingli", (int)me->query("max_jingli"));
			return 0;
		}
		else
		{
			me->add("max_jingli", 1);
			me->set("jingli", (int)me->query("max_jingli"));
			write("��ľ��������ˣ���\n");
			return 0;
		}
	}
}

int halt_respirate(object me)
{
        tell_object(me, "�㽫������ѹ�ص��վ��������\n");
        tell_room(environment(me), me->name() + "����һ������վ��������\n", me);
	respirate_cost = 0;
	if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		me->set("jingli", (int)me->query("max_jingli") * 2);
                        me->set_short_desc(0);
	me->set_temp("pending/respirate", 0);
        me->set_short_desc(0);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : respirate|tuna [<�ķѡ���������>]
 
������������24���Ժ󣬿���ͨ���������У����á�������������
�����������项�ķ�������ľ�ת��ɾ�����ע�⣺�㲻���ڲ�
��ս���ĵط����ɡ�

See also: exercise
HELP
        );
        return 1;
}
