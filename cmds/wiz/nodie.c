#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	mapping my;
 
        if (! SECURITY_D->valid_grant(me, "(wizard)"))
                return 0;

	seteuid(getuid(me));
 
	if(! arg)
		ob = me;
	else
        {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
        }

        if (! ob || ! userp(ob))
                return notify_fail("��ҪΪ˭��������������\n");
 
        if (ob->query_temp("guard_death") >= 1)
                return notify_fail("Ŀ���Ѿ�����������������Ҫ�ָ�����"
                                   "ʹ�� full ָ�\n");

        if (ob != me)
        {
	        if (wiz_level(me) < wiz_level("(wizard)"))
		        return notify_fail("��û��Ȩ��Ϊ" + ob->name() +
                                           "��������������\n");

                message_system(sprintf("%s(%s)Ϊ%s(%s)����������������\n",
                                       me->name(1), me->query("id"),
                                       ob->name(1), ob->query("id")));
        }

	my = ob->query_entire_dbase();
        my["jing"]   = my["eff_jing"]   = my["max_jing"];
        my["jingli"] = my["eff_jingli"] = my["max_jingli"];
        my["qi"]     = my["eff_qi"]     = my["max_qi"];
        my["neili"]  = my["max_neili"];
        my["food"]   = ob->max_food_capacity();
        my["water"]  = ob->max_water_capacity();

        if (me == ob)
	{
                message_vision(HIY "$N" HIY "��¶�黨֮ɫ����������"
                               "�дʣ�˵�����Ĵ��鰲�͡�\n" NOR, me);
		me->clear_condition();
                me->set_temp("guard_death", 1);
        } else
        {
                message_vision(HIY "$N" HIY "��¶�黨֮ɫ��˵������"
                               "���鰲�͡��������ḧ��$n" HIY "��ͷ"
                               "����\n" NOR, me, ob);
                if (! living(ob)) ob->revive();
		ob->clear_condition();
                ob->set_temp("guard_death", 1);
		log_file("static/nodie", sprintf("%s %s Ϊ %s(%s) ����������������\n",
					 log_time(), log_id(me),
				         ob->name(1), ob->query("id")));
        }
	return 1;
}
 
int help()
{
	write(@HELP
ָ���ʽ : nodie <��������>
 
���ָ����Ը�������������������
 
HELP);
        return 1;
}
