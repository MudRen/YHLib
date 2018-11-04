// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *valid_types = ({
        "force",
        "dodge",
        "cuff",
        "strike",
        "finger",
        "hand",
        "claw",
        "sword",
        "blade",
        "staff",
	"hammer",
        "club",
        "whip",
        "dagger",
        "throwing",
        "unarmed",
        "parry",
        "magic",
	"medical",
        "poison",
        "chuixiao-jifa",
        "tanqin-jifa",
        "guzheng-jifa",
	"cooking",
});

int sort_skill(string sk1, string sk2, mapping spos);
int filter_for_enable(string skill, string skill1);
int filter_for_main(string skill, string skill1);
int filter_for_combine(string skill, string skill1);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped, str, skill1;
        string skillname, skcolor;
        string *basic;
        mixed  *lists;
        string *others;
        string fname;
        int valid_check;
        int lvl;
	int i, k;

	seteuid(getuid());

        skill1 = 0;
	if (! arg)
		ob = me;
	else
	{
                string *temp;
		if (sscanf(arg, "%s of %s", skill1, arg) == 2)
                        ; else
                if (temp = explode(arg, " "))
                {
                        if (sizeof(temp) < 2)
                                arg = "me";
                        else
                                arg = implode(temp[0..sizeof(temp) - 2], " ");
                        skill1 = temp[sizeof(temp) - 1];

                        if (file_size(SKILL_D(skill1) + ".c") <= 0)
                        {
                                if (sizeof(temp) < 2)
                                        arg = skill1;
                                else
                                        arg += " " + skill1;
                                ob = present(arg, environment(me));
                                skill1 = 0;
                        }
                } else
                {
                        // if the user was not wizard, I will
                        // treat the arg as skill1, and the
                        // object he check is hiself.
                        if (! wizardp(me) && (! (ob = present(arg, environment(me))) ||
                            ! ob->is_character() ||
			    ! me->is_apprentice_of(ob)))
                        {
                                skill1 = arg;
                                arg = "me";
                        }
                }

		if (ob && ! ob->is_character())
			ob = 0;

                if (skill1 && file_size(SKILL_D(skill1) + ".c") <= 0)
                {
                        if (objectp(ob))
                        {
                                arg = 0;
                                skill1 = 0;
                        } else
                                return notify_fail("û��(" + skill1 +
						   ")���ּ��ܡ�\n");
                }

                if (! ob || ! ob->is_character())
                {
        		if (arg == "me")
        			ob = me;
        		else
        			ob = present(arg, environment(me));
        
        		if (! ob || ! ob->is_character()) ob = find_player(arg);
        		if (! ob || ! ob->is_character()) ob = find_living(arg);
                }

		if (! ob || ! ob->is_character())
			return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
	}

        if (ob != me)
        {
                // call the player, if the player has override the
                // the function & return a nonzero valud, I will
                // return success.
                if ((int)ob->skills(me, skill1))
                        return 1;
        }

        if (ob == me || wizardp(me) ||
            ob->is_apprentice_of(me) ||
            me->is_apprentice_of(ob) ||
            me->query("couple/id") == ob->query("id") ||
            me->is_brother(ob))
                valid_check = 1;
        else
        {
                fname = me->query("league/league_name");
                if (stringp(fname) && fname == ob->query("league/league_name"))
                        valid_check = 1;
                else
                        valid_check = 0;
        }

        if (! valid_check)
		return notify_fail("ֻ����ʦ����ʦͽ/����/���/ͬ�˹�ϵ����"
				   "���ܲ쿴���˵ļ��ܡ�\n");

	skl = ob->query_skills();
	if (! sizeof(skl))
	{
		write((ob==me ? "��" : ob->name()) +
		      "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}

        // calucate spos to sort
        sname = keys(skl);

        str = (ob == me ? "��" : ob->name()) + "Ŀǰ��ѧ����";
        // filter array by skill1
        if (skill1)
        {
                // filter the skill array by skill1
                if (member_array(skill1, valid_types) != -1)
                {
                        // skill1 is a basic skill
                        sname = filter_array(sname, (: filter_for_enable :), skill1);
                        str += to_chinese(skill1) + "����ؼ���";
                } else
                if (SKILL_D(skill1)->main_skill() &&
                    member_array(SKILL_D(skill1)->main_skill(), sname) == -1)
                {
                        // skill1 is a sub skill
                        skill1 = SKILL_D(skill1)->main_skill();
                        sname = filter_array(sname, (: filter_for_main :), skill1);
                        str += to_chinese(skill1) + "�е���ʽ";
                } else
                {
                        sname = filter_array(sname, (: filter_for_combine :), skill1);
                        str += to_chinese(skill1) + "�Ϳ��Լ����Ļ����似���ܹ������ļ���";
                }
        } else
                str += "���м���";

        if (! sizeof(sname))
        {
                write("��Ŀǰ��û�����ոü��ܡ�\n");
                return 1;
        }

        // sort all the skills
        // select all the basic skill of the skill list
        basic = filter_array(valid_types, (: member_array($1, $(sname)) != -1 :));

        // allocate the string array for each basic skill
        lists = allocate(sizeof(basic));

        // allocate the other skill for none apply to all the basic skill
        others = ({ });

        // select out all the special skill & other skill
        sname -= basic;
        for (i = 0; i < sizeof(sname); i++)
        {
                // let's check every special skill & other skill
                if (! sname[i]) continue;

                // enable for basic skill
                for (k = 0; k < sizeof(basic); k++)
                {
                        string main_skill;

                        if (SKILL_D(sname[i])->valid_enable(basic[k]))
                        {
                                // yes, I record this special skill
                                if (! lists[k])
                                        lists[k] = ({ sname[i] });
                                else
                                        lists[k] += ({ sname[i] });

                                // Is this a sub skill ?
                                if (main_skill = SKILL_D(sname[i])->main_skill())
                                {
                                        // yes, I select out all the other sub skills
                                        int st;
                                        for (st = i + 1; st < sizeof(sname); st++)
                                                if (sname[st] &&
                                                    SKILL_D(sname[st])->main_skill() == main_skill)
                                                {
                                                        // record it
                                                        lists[k] += ({ sname[st] });
                                                        sname[st] = 0;
                                                }
                                }

                                break;
                        }
                }

                if (k == sizeof(basic))
                        // It can enable on basic skill, it must be a others skill
                        others += ({ sname[i] });
        }

        // let me combine all the skill in string array: sname
        sname = ({ });
        for (i = 0; i < sizeof(basic); i++)
        {
                sname += ({ basic[i] });
                if (lists[i]) sname += lists[i];
        }

        sname += others;

        // get the skill map
	map = ob->query_skill_map();
	if (mapp(map)) mapped = values(map);
	if (! mapped) mapped = ({});

	lrn = ob->query_learned();
	if (! mapp(lrn)) lrn = ([]);
	str += "\n\n";
	str += HIC "��" HIY "����������������������������������������������������" HIC "��\n" NOR;
 
       	for (i = 0; i < sizeof(sname); i++)
	{
		int percent;
                skillname = to_chinese(sname[i]);
                switch (strlen(skillname))
                {
                case 6:
                        skillname = sprintf("%c%c %c%c %c%c", skillname[0], skillname[1],
                                             skillname[2], skillname[3],
                                             skillname[4], skillname[5]);
                        break;
                case 4:
                        skillname = sprintf("%c%c    %c%c", skillname[0], skillname[1],
                                             skillname[2], skillname[3]);
                        break;
                }

                if (member_array(sname[i], valid_types) != -1)
                        skcolor = CYN;
                else
                        skcolor = WHT;

                if (! objectp(find_object(SKILL_D(sname[i]))) &&
                    ! objectp(load_object(SKILL_D(sname[i]))))
                {
                        write(HIR "Error(No such skill):" + sname[i] + "\n" NOR);
                        continue;
                }
                lvl = skl[sname[i]];
		percent = lrn[sname[i]] * 100 / ((lvl + 1) * (lvl + 1) + 1);
		if (percent > 100) percent = 100;
		str += sprintf("%s%s%s%-40s" NOR WHT " - %4d/%3d%%\n" NOR, 
                        skcolor,
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "��"),
			skillname + " (" + sname[i] + ")",
			lvl, percent);
	}

	str += HIC "��" HIY "����������������������������������������������������" HIC "��\n" NOR;
	me->start_more(str);
	return 1;
}

int filter_for_enable(string skill, string skill1)
{
        return (skill == skill1) || (SKILL_D(skill)->valid_enable(skill1));
}

int filter_for_main(string skill, string skill1)
{
        return (SKILL_D(skill)->main_skill() == skill1);
}

int filter_for_combine(string skill, string skill1)
{
        return (SKILL_D(skill1)->valid_enable(skill)) ||
               (SKILL_D(skill)->valid_combine(skill1)) ||
               (skill == skill1);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : skills | cha [<������> | <ĳ��>]

���ָ����������ѯ��ѧ���ļ��ܡ���Ҳ����ָ��һ������
��ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����Ҳ
���Բ�ѯĳ��ĳ��ܵ����������(skills taiji-shengong
of song)������ (skills literate of me)�������ַ�����ѯ
ʱ�����¼��������

�١������ѯ�ļ�����һ�ֻ����似����ͬʱ��������������
    �����似�Ļ�������  ���������书���ܡ�

�ڡ������ѯ�ļ�����һ���似�е�ĳЩ��ʽ·���������ѯ
    ����ʮ���ƣ����ǽ���ʮ�����е�������β�ȵȣ�����ʾ
    ���ѧ����֮��ص���ʽ·�����������Ѿ��������似
    �ڻ��ͨ������ͨ��������ʾ��

�ۡ������ѯ�ļ�����һ����ͨ���似������ʾ���Լ����Ļ�
    ���似�����Ϳ�����֮�������书��

ʹ�ø���������˽���ѧ�����书���ܡ���Ҳ�ѯ��ʱ����
Ҫָ������������������ֱ������<������>������

���ָ�skill

HELP);
    return 1;
}
