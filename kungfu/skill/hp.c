// hp cmds (Mon  09-04-95)
// Update by Doing
 
#include <ansi.h>
 
inherit F_CLEAN_UP;

string status_color(int current, int max);
 
int main(object me, string arg)
{
	object ob;
	mapping my;

        string sp;
        int craze;
        int pro;
 
	seteuid(getuid(me));
 
	if (! arg)
		ob = me;
	else
        if (wizardp(me))
        {
		ob = present(arg, environment(me));
		if (! ob) ob = find_player(arg);
		if (! ob) ob = find_living(arg);
                if (! ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
 
	my = ob->query_entire_dbase();

        if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
                return notify_fail("��û�г����ţ��쿴ʲô��\n");

        sp  = sprintf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n");
        sp += sprintf(HIC"�� �� �� �� %s%5d/ %5d %s(%3d%%)" HIC "    �� �� �� �� %s%5d / %5d (+%d)\n",
		status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
		status_color(my["eff_jing"], my["max_jing"]),	my["eff_jing"] * 100 / my["max_jing"],
		status_color(my["jingli"], my["max_jingli"]),	my["jingli"], my["max_jingli"],
		my["jiajing"] );
        sp += sprintf(HIC"�� �� Ѫ �� %s%5d/ %5d %s(%3d%%)" HIC "    �� �� �� �� %s%5d / %5d (+%d)\n",
		status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
		status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"],
		status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],
		my["jiali"] );
        sp += sprintf(HIW"�� ʳ �� �� %s%5d/ %5d      " HIW "     �� Ǳ �� ��  %s%d\n",
                status_color(my["food"], ob->max_food_capacity()),
                my["food"], ob->max_food_capacity(),
	        (int)ob->query("potential")>=(int)ob->query_potential_limit()?HIM:HIY,
                (int)ob->query("potential") - (int)ob->query("learned_points"));
        sp += sprintf(HIW"�� �� ˮ �� %s%5d/ %5d      " HIW "     �� �� �� ��  %s%d\n",
                status_color(my["water"], ob->max_water_capacity()),
                my["water"], ob->max_water_capacity(),
                HIM,
                my["combat_exp"] );

        if (craze = me->query_craze())
        {
                if (me->is_most_craze())
                        sp += HIR "�� �� " BLINK "ŭ" NOR HIR " ��  " +
                              sprintf("%-22s", me->query("character") == "��������" ? "�������"
                                                                                    : "ŭ������");
                else
                        sp += sprintf(HIR "�� �� ŭ �� %5d/ %5d (+%-3d)    ",
                                      craze, me->query_max_craze(),
                                      me->query("jianu"));
        } else
        {
                sp += HIC "�� ƽ �� ��  ������������������    ";
        }

        sp += sprintf(HIM "�� �� �� ��  " HIY "%d\n", my["magic_points"] - my["magic_learned"]);

        sp += sprintf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);
        tell_object(me, sp);
	return 1;
}
 
string status_color(int current, int max)
{
	int percent;
 
	if (max>0 ) percent = current * 100 / max;
	else percent = 100;
	if (percent > 100) return HIC;
	if (percent >= 90) return HIG;
	if (percent >= 60) return HIY;
	if (percent >= 30) return YEL;
	if (percent >= 10) return HIR;
	return RED;
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ��(��)��ָ������(������)�ľ�, ��, ����ֵ��
 
see also : score
HELP );
    return 1;
}
