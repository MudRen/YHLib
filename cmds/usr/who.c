// who.c
// From ES2
// Update by Doing Lu

#include <ansi.h>
#include <net/dns.h>
#include <getconfig.h>

inherit F_CLEAN_UP;

#define PREFIX(ob)    (ob->is_chatter() ? HIC "~" : interactive(ob) ? (query_idle(ob) > 120 ? HIG "*" NOR : " ") : stringp(ob->query("doing")) ? HIY "@" NOR : HIR "#" NOR)

int sort_user(object,object);
int sort_user_by_name(object, object, int d);
int help();

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string name, str, *option;
        object *list, *ob, ob1;
	int i, j, ppl_cnt;
        int opt_interactive;
        int opt_long, opt_wiz, opt_party;
        int opt_chatter, opt_player;
        int opt_male, opt_female, opt_sort;
        int opt_family, opt_number;
        int opt_master;
        int opt_closed;
        object vob;
        string who_name;
	string who_id;
        string league_name;

        vob = me;
        opt_chatter = 1;
        opt_player = 1;
        who_name = 0;

        if (time() - me->query_temp("scan_time") < 10 &&
            ! wizardp(me))
                return notify_fail("�ȵȣ�ϵͳ�����С���\n");

        if (arg)
        {
                option = explode(arg, " ");
                i = sizeof(option);
                while (i--)
                        switch (option[i])
                        {
                                case "-h": return help();
                                case "-l": opt_long = 1;        break;
                                case "-w": opt_wiz = 1;         break;
                                case "-p": opt_party = 1;       break;
                                case "-fam": opt_family = 1;    break;
                                case "-f": opt_female = 1;      break;
                                case "-m": opt_male = 1;        break;
                                case "-c": opt_chatter = 1; opt_player = 0;     break;
                                case "-r": opt_player = 1; opt_chatter = 0;     break;
                                case "-u": opt_master = 1;      break;
                                case "-i":
                                case "-s": opt_sort = 1;        break;
                                case "-S": opt_sort = -1;       break;
                                case "-n": opt_number = 1;      break;
                                case "-@": opt_closed = 1;      break;
                                case "-!": opt_interactive = 1; break;
                                default:
                                        if (wizardp(me) &&
                                            option[i][0] == '@')
                                        {
                                                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
                                                                    me, opt_long);
                                                write("��·ѶϢ���ͳ������Ժ�\n");
                                                return 1;
                                        }

                                        if (i > 0 && option[i - 1] == "is")
                                        {
                                                who_name = option[i];
                                                i--;
                                                break;
                                        }

					if (! me) break;
                                        if (environment(me))
						ob1 = present(option[i], environment(me));
                                        if (! ob1 || ! me->visible(ob1))
						ob1 = find_player(option[i]);
                                        if (! ob1 || ! me->visible(ob1))
						ob1 = find_living(option[i]);
                                        if (! ob1 || ! me->visible(ob1))
						return notify_fail("û�������һ��������\nָ���ʽ : who [-h] [-l] [-w] [-p] [-fam] [-m] [-f] [<ID>]\n");
                                        if (! ob1->query("family/family_name"))
                                                return notify_fail(ob1->name(1) + "���ڻ�û�м����κ�һ�����ɡ�\n");

                                        me = ob1;
					opt_family = 1;
                        }
        }

        if (opt_male && opt_female)
        {
                write("���� -f �� -m ����ͬʱʹ�á�\n");
                return 1;
        }

        if (opt_long && me && (vob == this_player()) && ! wizardp(me) && ! remote)
        {
                if ((int)me->query("jing") < 5)
                        return notify_fail("��ľ���̫���ˣ�û�а취��֪��"
                                           "����ҵ���ϸ���ϡ�\n");

                me->receive_damage("jing", 5);
        }

        if (opt_player) ob = users(); else ob = ({ });
        if (opt_chatter && sizeof(MESSAGE_D->query_connection()))
                ob += filter_array(values(MESSAGE_D->query_connection()),
                                   (: objectp :));

        if (opt_party)
        {
                if (! me->query("league/league_name"))
                        return notify_fail("�����ڻ�û�м����κ�һ�����ɡ�\n");
               	ob = filter_array(ob, (: $1->query("league/league_name") ==
                        $2->query("league/league_name") :), me);
        }

        if (opt_family)
        {
                if (! me->query("family/family_name"))
                        return notify_fail("�����ڻ�û�м����κ�һ�����ɡ�\n");
               	ob = filter_array(ob, (: $1->query("family/family_name") ==
                        $2->query("family/family_name") :), me);
        }

        if (opt_male)
               	ob = filter_array(ob, (: $1->query("gender") == "����" :));

        if (opt_female)
               	ob = filter_array(ob, (: $1->query("gender") == "Ů��" :));

        if (who_name)
        {
                str = WHT + NAME_D->who_is(who_name) + "\n" NOR;
                ob = filter_array(ob, (: $1->name(1) == $(who_name) :));
        } else
                str = "";

        if (opt_wiz)
                ob = filter_array(ob, (: wizardp :));

	if (objectp(vob))
		ob = filter_array(ob, (: $(vob)->visible($1) :));
        else
		ob = filter_array(ob, (: $1->query("env/invisible") :));

        if (opt_master)
                ob = filter_array(ob, (: ultrap :));

        if (opt_closed)
                ob = filter_array(ob, (: ! interactive($1) && $1->query("doing") :));

        if (opt_interactive)
                ob = filter_array(ob, (: interactive($1) :));

        if (! sizeof(ob))
        {
                str += "��̶������û�з�����������ҡ�\n";
                if (remote) return str;
                write(str);
                return 1;
        }

        me->set_temp("scan_time", time());

        str += HIG "��" + LOCAL_MUD_NAME() + HIG "��" + NOR WHT + "  Ŀǰ�����е�";
        if (opt_party)
        {
                if (me->query("league/league_name"))
                        str += HIR + " (" + me->query("league/league_name") + ") " + NOR WHT;
                else    str += HIC + " (�ް���) " + NOR WHT;
        } else
        if (opt_family)
        {
                if (me->query("family/family_name"))
                        str += HIR + " (" + me->query("family/family_name") + ") " + NOR WHT;
                else    str += HIC + " (������) " + NOR WHT;
        }

        if (! who_name)
                who_name = "";
        else
                who_name = "(" + who_name + ")";

        if (opt_closed)
                str += "�����е�";

        if (opt_wiz)
                str += (opt_female ? "Ů��" : opt_male ? "����" : "") +
                       "��ʦ" + who_name + "�У�";
        else
                if (opt_long) str += (opt_female ? "Ů��" : opt_male ? "����" : "") +
                                     (opt_master ? "����ʦ" : "���") + who_name + "�У�";
                else str += (opt_female ? "Ů��" : opt_male ? "����" : "") +
                            (opt_master ? "����ʦ" : "���") + who_name + "�У�";

        if (opt_number)
        {
                str += chinese_number(sizeof(ob)) + " �ˡ�\n";
                if (remote) return str;
                write(str);
                return 1;
        }

        str += NOR"\n"HIC"��" + HIY"��������������������������������������������������������������������������"HIC"��\n"NOR;

        if (opt_sort)
                list = sort_array(ob, (: sort_user_by_name :), opt_sort);
        else
        {
                // Why I sort the array use too many variable ?
                // Only optimize for speed :)
                // The normal_ob store the ob without family
                // the wiz_ob story the wizards
                // the mapping familys story all the others
                // & why I create generation ? becuase I want
                // to sort the player in one family by the
                // generation, but I won't directly sort them
                // use function:query, it too slow.
                mapping familys = ([ ]);
                mapping generation = ([ ]);
                object *normal_ob = ({ }), *wiz_ob = ({ });
                mapping db;
                mapping fam;
                string fam_name;
                object cob;
                mixed val;
                
                for (i = 0; i < sizeof(ob); i++)
                {
                        cob = ob[i];
                        if (wizardp(cob))
                        {
                                wiz_ob += ({ cob });
                                continue;
                        }

                        db = cob->query_entire_dbase();
                        if (! mapp(fam = db["family"]) ||
                            ! stringp(fam_name = fam["family_name"]))
                        {
                                normal_ob += ({ cob });
                                continue;
                        }

                        if (! arrayp(familys[fam_name]))
                                familys[fam_name] = ({ cob });
                        else
                                familys[fam_name] += ({ cob });
                        generation[cob] = fam["generation"];
                }

                list = ({ });
                for (i = 0; i < sizeof(val = values(familys)); i++)
                        list += sort_array(val[i], (: $(generation)[$1] -
                                                      $(generation)[$2] :));
                list = wiz_ob + list + normal_ob;
        }

        ppl_cnt = 0;
        if (opt_long)
        {
                i = sizeof(list);
                while (i--)
                {
                        // Skip those users in login limbo.

                        league_name = list[i]->query("league/league_name");
                        ppl_cnt++;
                        str = sprintf("%s%12s%s%s\n",
                                str,
                                RANK_D->query_rank(list[i]),
                                PREFIX(list[i]),
                                stringp(league_name) ? HIG + "��" + league_name + "��" + 
                                NOR + list[i]->short(1) : list[i]->short(1));
                }
        } else
        {
                i = sizeof(list);
                while (i--)
                {
                        // Skip those users in login limbo.
			who_id = list[i]->query("id");
			if (! stringp(who_id))
				who_id = "#" + geteuid(list[i]);
                        name = sprintf("%s%s%-10s(%-12s",
                                        PREFIX(list[i]),
                                        wizardp(list[i]) ? HIM : list[i]->query("gender") == "Ů��" ? HIC : NOR WHT,
                                        list[i]->name(1),
                                        capitalize(who_id)+")");

                        str = sprintf("%s%s%s", str, name,
                                      ppl_cnt%3==2?"\n": HIY"��");
                        ppl_cnt++;
                }
                if (ppl_cnt % 3) str += "\n";
        }

        str += HIC"��"+HIY"��������������������������������������������������������������������������"HIC"��\n"NOR;
        str = sprintf("%s���� %s λʹ���������У�ϵͳ������%s\n "
                      HIG "*" NOR " ��ʾ�����У�" HIC "~" NOR " ��ʾ�����У�"
                      HIR "#" NOR " ��ʾ�����У�"HIY"@" NOR" ��ʾ���������С�\n",
                      str, CHINESE_D->chinese_number(ppl_cnt),
                      query_load_average());

        if (remote) return str;
        me->start_more(str);
        return 1;
}

int sort_user_by_name(object ob1, object ob2, int d)
{
        mapping f1, f2;
        string  s1, s2;
        int i;

	if (wizardp(ob1) && ! wizardp(ob2)) return -1;
	if (wizardp(ob2) && ! wizardp(ob1)) return 1;
	if (wizardp(ob1) && wizardp(ob2))
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);

        return strcmp(ob2->query("id"), ob1->query("id")) * d;
}

int help()
{
        write("
ָ���ʽ : who [-h] [-l] [-w] [-p] [-c] [-fam] [-f] [-m] [-s] [-S] [<ID>] [-n] [is <��������>]

���ָ������г����������ϵ���Ҽ���ȼ���

-h   �г�������Ļ��
-l   ѡ���г��ϳ���ѶϢ��
-p   ֻ�г�ͬ���ɵ���ҡ�
-fam ֻ�г�ͬ���ɵ���ҡ�
-w   ֻ�г��������е���ʦ��
-c   ֻ�г������������ҡ�
-m   ֻ�г������е�������ҡ�
-f   ֻ�г������е�Ů����ҡ�
-u   ֻ�г������еĴ���ʦ�ǡ�
-!   ֻ�г��������������ߵ����
-@   ֻ�г�����������������������ҡ�
-s   ����ID��ĸ�����������е����
-S   ����ID��ĸ�����������е����
-n   ֻ�г���ǰ���ϲ�����������ҵ���Ŀ��
<ID> �г�<ID>��������������ɵ���ҡ�
is   ���ʹ�������ѡ�����Ҫ������ҵ��������֡�

"HIG"*"NOR" ��ʾ"HIG"����"NOR"�У�"HIC "~"NOR" ��ʾ�����У�"
HIR"#"NOR" ��ʾ"HIR"����"NOR"�У�"HIY"@"NOR" ��ʾ"HIY"��������"NOR"�С�

���ָ� finger
");
        return 1;
}
