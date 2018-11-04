// exercise.c

#include <skill.h>

inherit F_CLEAN_UP;

int exercising(object me);
int halt_exercise(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int exercise_cost;
	string force;
	object where;
        int n;

	seteuid(getuid());
	where = environment(me);

	if (where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("��������æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("ս���в������ڹ������߻���ħ��\n");

	if (! stringp(force = me->query_skill_mapped("force")))
		return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

	if (! arg || ! sscanf(arg, "%d", exercise_cost))
		return notify_fail("��Ҫ��������������\n");

	if (exercise_cost < 10)
		return notify_fail("����ڹ���û�дﵽ�Ǹ����磡\n");

	if ((int)me->query("qi") < exercise_cost)
		return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

	if ((int)me->query("jing") * 100 / (int)me->query("max_jing") < 70)
		return notify_fail("�����ھ��������޷�������Ϣ��������\n");

        if (environment(me)->query("no_fight")
           && ! environment(me)->query("can_dazuo")
           && me->query("doing") != "scheme")
                return notify_fail("���޷�������ط����Ĵ�����\n");

        notify_fail("���޷�˳������ת��Ϣ��\n");
        if (SKILL_D(force)->do_effect(me))
                return 0;

	write("�������������ù���һ����Ϣ��ʼ������������\n");

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
        me->set_short_desc("�����ڵ�������������");
	message_vision("$N��ϥ���£���ʼ����������\n", me);
	me->start_busy(bind((:call_other, __FILE__, "exercising" :), me),
                       bind((:call_other, __FILE__, "halt_exercise" :), me));
	return 1;
}

int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = (int)me->query_skill("force") / 5;

        neili_gain = 1 + neili_gain / 2 + random(neili_gain) +
                     environment(me)->query("exercise_improve");
        if (neili_gain < 0) neili_gain = 1;

	if (exercise_cost > 0)
        {
                if (neili_gain > exercise_cost)
                        neili_gain = exercise_cost;
                
                if (neili_gain > me->query("qi"))
                {
                        neili_gain = me->query("qi");
                        me->set_temp("exercise_cost", 0);
                        me->set_short_desc(0);
                        exercise_cost = 0;
                } else
                {
                        me->set_temp("exercise_cost", exercise_cost -= neili_gain);
                }
                me->add("neili", neili_gain);
                me->add("qi", -neili_gain);
                
                if (exercise_cost > 0)
                	return 1;
        }

	me->set_temp("pending/exercise", 0);
        me->set_short_desc(0);
	message_vision("$N�˹���ϣ��������˿�����վ��������\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else
        {
		if ((int)me->query("max_neili") >= (int)me->query_current_neili_limit())
                {
			write("���������Ϊ�ƺ��Ѿ��ﵽ��ƿ����\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		} else
                {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
			write("������������ˣ���\n");
			return 0;
		}
	}
}

int halt_exercise(object me)
{
        tell_object(me, "�㽫����ѹ�ص��վ��������\n");
        tell_room(environment(me), me->name() + "����һ������վ��������\n", me);
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
        me->set_short_desc(0);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise|dazuo [<�ķѡ���������> ������� 10]

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������ע�⣺�㲻���ڲ���
ս���ĵط�������

HELP );
        return 1;
}
