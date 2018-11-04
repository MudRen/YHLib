// practice.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object where = environment(me);
        string skillname;
        string base_skname;
        int skill, skill_basic, times, i;
        int t = time();
        int improve;

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (t == me->query_temp("time/practice"))
                return notify_fail("��ող���ϰ���������Ҫ������ϰ������"
                                   "ָ����ϰ�Ĵ�������\n");

        if (me->is_fighting())
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        if (environment(me)->query("no_fight") && me->query("doing") != "scheme")
                return notify_fail("���޷�������ط�������ϰ��\n");

        if (! arg) return (__DIR__"enable")->main(me, arg);

        if ((sscanf(arg, "%s %d", base_skname, times) != 2))
        {
                times = 1;
                base_skname = arg;
        }
            
        if (times < 1 || times > 50)
                return notify_fail("��ϰ�����������һ�Σ������ܳ�����ʮ�Ρ�\n");

        if (! stringp(skillname = me->query_skill_mapped(base_skname)))
                return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

        skill_basic = me->query_skill(base_skname, 1);
        skill = me->query_skill(skillname, 1);

        if (skill < 1)
                return notify_fail("�����û��ѧ������ܰɣ�\n");

        if (skill_basic < 1)
                return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");

        if (skill_basic <= skill)
                return notify_fail("���" + to_chinese(base_skname) +
                                   "��򲻹������Լ���������" +
                                   to_chinese(skillname) + "��ˮƽ��\n");

        notify_fail("�����ڲ�����ϰ����ܡ�\n");
        if (! SKILL_D(skillname)->valid_learn(me)) return 0;

        if (! XUE_CMD->can_learn(me, skillname))
                return 0;

        notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");

        if (! me->can_improve_skill(skillname))
                return notify_fail("Ҳ����ȱ��ʵս���飬�����ϰ��û��������\n");

        me->set_temp("time/practice", t);

        if (skill >= 500)
                improve = skill_basic / 30;
        else
        if (skill >= 300)
                improve = skill_basic / 10;
        else
                improve = skill_basic / 5 + 1;

        for (i = 0; i < times; i++)
        {
                if (SKILL_D(skillname)->practice_skill(me))
                        me->improve_skill(skillname, improve, skill_basic > skill ? 0 : 1);
                else break;
        }
        if (i > 0)
                write(HIC "�����Ű�" + to_chinese(skillname) +
                      "����" + chinese_number(i) + "�ˡ�\n" NOR);

        if (i >= times)
                return 1;

        return 0;
}

int help(object me)
{
        write(@TEXT
ָ���ʽ��practice | lian <��������> <����>

���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��
רҵ���ܡ��������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ��������
��������������ֻ����������ܵĵȼ��йأ����仰˵���ڼ���ϰ��
ʹ�����ѧ���������ʤ��������Ψһ;������Ȼ������֮ǰ�����
��ʵ�������л���㹻�ľ�����������Ļ������ܡ�

�������ָ�apprentice, research, skills, study, learn

TEXT);
        return 1;
}

