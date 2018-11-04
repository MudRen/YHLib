// peacock.c

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_NOCLONE;

void create()
{
        if( clonep() )
        {
		set_default_object(__FILE__);
        }

	set_name(HIR "������" NOR, ({ "huo qilin","qilin" }));
       set_weight(1);
       set("long",HIR  "һֻ�����룬��߻�������������ǧ������"
                   "�������ֳ���ɫ���⡣\n" NOR);
	set("gender", "����");
	set("age", 2000);
	set("attitude", "peaceful");
        set("rideable", 1);
	setup();
}

void kill_ob(object ob)
{
}

void receive_damage(string type, int amount, object from)
{
        return;
}

void unconcious()
{
        die();
}

void die()
{
        message_vision(HIC "$N" HIC "һ����ɫ���⣬����"
                       "������ʧ������\n" NOR, this_object());
        destruct(this_object());
}

void init()
{
        add_action("do_follow", "follow");
        add_action("do_ride", "ride");
        add_action("do_ride", "qi");
}

int do_follow(string arg)
{
        object me;
        
        if (arg != "me")
                return 0;

        me = this_player();
        if (me->query("id") != "wfoxd")
                return 0;

        message_vision("$N����$n�ĺ��档\n", this_object(), me);
        set_leader(me);
        return 1;
}

int do_ride(string arg)
{
        object me;

        me = this_player();
        if (me->query("id") != "wfoxd")
                return 0;

        if (! arg || ! id(arg))
                return 0;

        if (me->query_temp("is_riding"))
        {
                write("������������" + me->query_temp("is_riding")->name() +
                      "���ء�\n");
                return 1;
        }

        if (move(me))
        {
                message_vision(HIC "$N" HIC "Ѹ�ٵ�����$n"
                               HIC "���������Ǻ��ţ�$n"
                               HIC "һĨ��ɫ���⣬�ֳ����ƶ�䡣\n",
                               me, this_object());
                set_temp("is_rided_by", me);
                me->set_temp("is_riding", this_object());
        } else
        {
                write("�����ϴ��Ķ���̫���ˣ��޷�����ȥ��\n");
        }
        return 1;
}

int receive_summon(object me)
{
        object env;

        if (objectp(env = environment()) && env == environment(me))
        {
                write(name() + "�����������������ٻ��ˡ�\n");
                return 1;
        }

        if (env)
        {
                message_vision(HIC "$N" HIC "һ����ɫ���⣬����"
                               "������ʧ������\n" NOR, this_object());
        }

        move(environment(me));
        message_vision(HIY "���ֺ�����䣬һʱ���뵱�أ��������һֻ$N"
                       HIY "����ɫ���������\n", this_object());
        return 1;
}

int hide_anywhere(object me)
{
        if (me->query("id") != "wfoxd")
                return 0;

        message_vision(HIB "$N" HIB "����һչ��������ɫ���⣬"
                       "�����������ټ���\n", this_object());
        destruct(this_object());
        return 1;
}
