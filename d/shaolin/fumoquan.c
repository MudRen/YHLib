#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��շ�ħȦ");
	set("long", @LONG
���ô������������ϸ����˸�������һ�˵Ĵ󶴣��и���
��¶����ɫɮ��һ�ǣ��ƺ�ס�����ˡ�������һƬ���ƺ����
�Ĵ���ͺͺ�ģ��ƺ������ܴ����������´�ݲ�����
LONG );
	set("exits", ([
		"out" : __DIR__"qyping",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/du-nan" : 1,
		CLASS_D("shaolin") + "/du-e" : 1,
		CLASS_D("shaolin") + "/du-jie" : 1,
	]));
	setup();
}

void init()
{	
	mapping mine;
        object me;
        object ob1, ob2, ob3;

        me = this_player();
	mine = this_player()->query("family");

        if (me->query_temp("valid_in_fumoquan"))
		return;

        if (mapp(mine) &&
	    mine["family_name"] == "������" &&
            mine["generation"] <= 36)
        {
                me->set_temp("valid_in_fumoquan", 1);
                return;
        }

	if (! objectp(ob1 = present("du nan", this_object()))
           || ! living(ob1)
           || ! objectp(ob2 = present("du e", this_object()))
           || ! living(ob2)
           || ! objectp(ob3 = present("du jie", this_object()))
           || ! living(ob3)
           || ! interactive(me))
        {
                me->set_temp("valid_in_fumoquan", 2);
                return;
        }

        if (ultrap(me))
        {
                message_sort(WHT "\n������λ��ɮ��˿�������򶨲�������"
                             "����֪��$N�ĵ�����\n\n" NOR, me);
                CHANNEL_D->do_channel(this_object(), "rumor", "����ʦ" +
                                      me->name(1) + "�����շ�ħȦ��");
                me->set_temp("valid_in_fumoquan", 1);
                return;
        }

        message_sort(HIR "\nͻȻ�侢���ݺᣬ��������������������͵ع�"
                     "����˲���������һ�����Եı��У��糤ì����˰�"
                     "�����������ֱ���$N��ͷ���أ�������Ҫ�����̶�����"
                     "$NһƳ�䣬����������ɮ�־���������֮�У���ȫ����"
                     "����$N������$N��������������֮�̺����Ͻ�ħ�󷨵�"
                     "��շ�ħȦ��\n" NOR, me);

	if (mapp(mine) &&
            mine["family_name"] == "������" &&
            this_player()->query("combat_exp") < 100000 )
        {
	        message_vision(HIR "\nͻȻ$N" HIR "��һ����ɽ������ľ�"
                               "�����У���ʱ���˳�ȥ��\n\n" NOR, me);
                me->move("/d/shaolin/qyping");
        }

        message_vision(WHT "\n��Ȼ�䡸쬡���һ����һ����$N"
                       WHT "���״���Ȼӿ����\n" NOR, me);

        COMBAT_D->do_attack(ob1, me, query_temp("weapon"));
        COMBAT_D->do_attack(ob1, me, query_temp("weapon"));
        COMBAT_D->do_attack(ob1, me, query_temp("weapon"));

        message_vision(WHT "\n�������ƿ�����������һ����$N"
                       WHT "�����״�Ϯ����\n" NOR, me);

        COMBAT_D->do_attack(ob2, me, query_temp("weapon"));
        COMBAT_D->do_attack(ob2, me, query_temp("weapon"));
        COMBAT_D->do_attack(ob2, me, query_temp("weapon"));

        message_vision(WHT "\n���ֻ��һ����" HIW "�ҷ�ȱ�" NOR +
                       WHT "���������������$N" WHT "����\n" NOR, me);

        COMBAT_D->do_attack(ob3, me, query_temp("weapon"));
        COMBAT_D->do_attack(ob3, me, query_temp("weapon"));
        COMBAT_D->do_attack(ob3, me, query_temp("weapon"));

        if (me->query("qi") < 0)
        {

                if (mapp(mine) && mine["family_name"] == "������")
                {
                        me->unconcious();
                        me->set_temp("valid_in_fumoquan", 2);
                } else
                {
                        me->set_temp("die_reason", "ǿ����շ�ħȦ��ͽȻ��������");
                        me->die();
                }
                return;
        }

        me->set_temp("valid_in_fumoquan", 1);
        message_vision(WHT "\n��ʱ��λ��ɮ�ջر��ӣ�����һ����\n\n" NOR, me);
        CHANNEL_D->do_channel(this_object(), "rumor",
                              (mapp(mine) ? mine["family_name"] : "") +
                              me->name(1) + "�����շ�ħȦ��");
}

int valid_leave(object me, string dir)
{
        me->delete_temp("valid_in_fumoquan");
	return ::valid_leave(me, dir);
}

