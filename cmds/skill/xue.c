// learn.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int can_learn(object me, string skill);

string *reject_msg = ({
        "˵������̫�����ˣ�����ô�ҵ���\n",
        "�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ����ʲô��\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object where = environment(me);
        string *args;
        string skill, teacher, master, skill_name;
        object ob;
        mixed flag;
        int master_skill, my_skill, jing_cost, times, i;
        int rand;
        int t = time();

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (t == me->query_temp("time/learn"))
                return notify_fail("��ող�ѧϰ���������Ҫ����ѧϰ������ָ��ѧϰ�Ĵ�������\n");

        if (! arg || (i = sizeof(args = explode(arg, " "))) < 2)
                return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����> <����>\n");

        i--;
        if (i >= 2 && sscanf(args[i], "%d", times) && times)
                i--;
        else
                times = 1;
        skill = args[i--];
        if (args[i] == "about" && i >= 1)
                i--;
        teacher = implode(args[0..i], " ");

        if (times < 1 || times > 100)
                return notify_fail("ѧϰ��������һ�Σ����Ҳ���ܳ���һ�ٴΡ�\n");

        if (me->is_fighting())
                return notify_fail("����ĥǹ������������\n");

        if (! (ob = present(teacher, environment(me))) || ! ob->is_character())
                return notify_fail("��Ҫ��˭��̣�\n");

        if (! living(ob))
                return notify_fail("�š�������Ȱ�" + ob->name() +
                                   "Ū����˵��\n");

        if (! me->is_apprentice_of(ob))
        {
                switch (ob->recognize_apprentice(me, skill))
                {
                case 0:
                        return notify_fail(CYN + ob ->name() + CYN +
                                           reject_msg[random(sizeof(reject_msg))]
                                           + NOR);
                case -1:
                        return 1;
                }
        }

        if (! master_skill = ob->query_skill(skill, 1))
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        if (stringp(flag = ob->query("no_teach/" + skill)))
        {
                message_vision(CYN "$N" CYN "ҡҡͷ��˵����" + flag + "\n" NOR, ob);
                return 1;
        } else
        if (intp(flag) && flag)
        {
                if (flag != -1)
                        // show the messaeg if the result was not -1
                        write(CYN + ob->name() + CYN "˵�����Բ���" +
                              to_chinese(skill) + "�ɲ�����㴫�ڡ�\n" NOR);
                return 1;
        }

        if (me->is_apprentice_of(ob) &&
            SKILL_D(skill)->type() == "martial" &&
            me->query_skill(skill, 1) >= SKILL_D(skill)->valid_learn_level())
        {
                write(CYN + ob->name() + CYN "˵�������" + to_chinese(skill) +
                      CYN "�����Ѿ��Ƿ�ͬ�����ˣ��ҾͲ��ٽ��㣬���Լ����о��ɡ�"
                      "\n" NOR);
                return 1;
        }

        my_skill = me->query_skill(skill, 1);
        if (my_skill >= master_skill)
                return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

        if (my_skill >= (int)(master_skill - me->query("betrayer/times") * 2))
                return notify_fail(CYN + ob->name() + CYN "������üͷ��������"
                                   "�����ȥ����ʦ������\n" NOR);

        if (! can_learn(me, skill))
                return 0;

        notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
        if (! SKILL_D(skill)->valid_learn(me)) return 0;

        jing_cost = (100 + my_skill * 2) / (int) me->query("int");
        if (! my_skill)
        {
                jing_cost *= 2;
                me->set_skill(skill,0);
        }

        if ((me->query("potential") - me->query("learned_points")) < times)
                return notify_fail("���Ǳ�ܲ���ѧϰ��ô����ˡ�\n");
        write(sprintf(HIC "�㿪ʼ��%s���" + chinese_number(times) +
                      "���йء�%s�������ʡ�\n" NOR,
                      ob->name(),
                      to_chinese(skill)));

        if (ob->query("env/no_teach"))
        {
                write("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");
                return 1;
        }

        tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
                    me->name(), to_chinese(skill)));

        if (! me->can_improve_skill(skill))
        {
                write("Ҳ����ȱ��ʵս���飬���" +
                      ob->name() + "�Ļش������޷���ᡣ\n");
                return 1;
        }

        if (playerp(ob))
        {
                if ((int)ob->query("jing") > jing_cost * times / 5 + 1)
                        ob->receive_damage("jing", jing_cost / 5 + 1);
                else
                {
                        write("����" + ob->name() + "��Ȼ̫"
                              "���ˣ�û�а취����ʲ�ᡣ\n");
                        tell_object(ob, "������̫���ˣ�û�а취��" +
                                    me->name() + "��\n");
                        return 1;
                }
        }
                
        me->set_temp("time/learn", t);
        for (i = 0; i < times ; i++)
        {
                if ((int)me->query("jing") < jing_cost)
                {
                        if (me->query("env/auto_regenerate") &&
                            SKILL_D("force/regenerate")->exert(me, me))
                        {
                                // try to regenerate & learn again
                                write("����þ������һЩ����������ѧϰ��\n");
                                i--;
                                continue;
                        } else
                        {
                                me->set("jing", 0);
                                break;
                        }
                }

                if (i == 0)
                {
                        if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
                                write(sprintf("������%s��ָ�����ԡ�%s��"
                                               "��һ���ƺ���Щ�ĵá�\n",
                                               ob->name(), skill_name));
                        else
                                write(sprintf("������%s��ָ�����ƺ���Щ"
                                              "�ĵá�\n", ob->name()));
                }
                me->receive_damage("jing", jing_cost);
                me->add("learned_points", 1);
                rand = me->query_int() + my_skill / 5;
                rand /= 2;
                me->improve_skill(skill, 4 + random(rand));
        }

        if (i == 0)
                write("Ȼ�������̫���ˣ��޷��ٽ����κ�ѧϰ�ˡ�\n");
        else
        if (i > 0 && i < times)
                write("���������̫���ˣ�ѧϰ��" + chinese_number(i) +
                      "���Ժ�ֻ����ͣ������\n");

        return 1;
}

int can_learn(object me, string skill)
{
        string skill_name;
        mapping skills;
        string mskill;
        int tmp;
        int i;

        if (stringp(mskill = SKILL_D(skill)->main_skill()) &&
            mskill != skill &&
            me->query_skill(mskill, 1) > 0)
                return notify_fail("������û�б�Ҫ�ٵ���ѧϰ" + to_chinese(skill) + "�ˡ�\n");

        skills = me->query_skills();
        if (! mapp(skills))
                return 1;

        if (! SKILL_D(skill)->valid_enable("force") ||
            SKILL_D(skill)->valid_force("*"))
                return 1;

        foreach (skill_name in keys(skills))
        {
                if (file_size(SKILL_D(skill_name) + ".c") == -1)
                {
                        // No such skill
                        continue;
                }

                if (! SKILL_D(skill_name)->valid_enable("force") ||
                    skill_name == skill)
                        continue;

                if (! SKILL_D(skill_name)->valid_force(skill))
                        return notify_fail(HIR "�㷢��������ѧ��" HIY +
                                           to_chinese(skill_name) + HIR
                                           "��" HIY + to_chinese(skill) +
                                           HIR "��ͻ���ѣ�����û�취��"
                                           "�档\n" NOR);
        }

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : learn|xue <ĳ��> [about] <����> <����>
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

�������ָ�� : apprentice, practice, skills, study
HELP
        );
        return 1;
}

