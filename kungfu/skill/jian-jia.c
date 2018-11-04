// jian-jia.c ����

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "tanqin-jifa"; }

int valid_learn(object me)
{
        if (me->query_skill("tanqin-jifa", 1) < 30)
                return notify_fail("��ĵ��ټ���ˮƽ̫�������������˵�ɣ�\n");

        if (me->query_skill("tanqin-jifa", 1) < me->query_skill("qiuyue-lai", 1))
                return notify_fail("��ĵ��ټ����������ޣ��޷�������������硣\n");

        return 1;
}

int practice_skill(object me)
{
        object ob;

        if (! objectp(ob = me->query_temp("handing")) ||
            ! ob->valid_as_qin())
                return notify_fail("�㲻���������ϣ���ô��ϰ��\n");

        if ((int)me->query("jing") < 80)
                return notify_fail("��ľ��񲻹��ã�û����ϰ�ˡ�\n");

        if ((int)me->query("qi") < 30)
                return notify_fail("�����ڿڸ����ʵ����̫���ˡ�\n");

        me->receive_damage("jing", 25);
        me->receive_damage("qi", 10);

        return 1;
}

void do_effect(object me)
{
        object *obs;
        int i;

        obs = all_inventory(environment(me));
        for (i = 0; i < sizeof(obs); i++)
        {
                if (! obs[i]->is_character() || obs[i] == me || ! living(obs[i]))
                        continue;

                tell_object(obs[i], HIC "�������������š�" HIW "����Բԣ���¶Ϊ˪����ν��"
                                    "�ˣ�����һ������" HIC "��\nȴ��֪���Ϻ�����˲��࣬��"
                                    "�Ƴ�����˼Ľ֮�顣\n" NOR);

                if (obs[i]->query_temp("love") == me->query("id"))
                {
                        tell_object(obs[i], HIM "���������һ��������������ġ����ˡ��ѵ�"
                                            "����ô��\n" NOR);

                        message("vision", HIM "\nֻ��" HIM + obs[i]->name() + HIM "����΢"
                                          "΢һ�졣\n" NOR, environment(obs[i]), ({obs[i]}));

                        continue;
                }
        }
}
