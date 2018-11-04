#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "������¶" NOR, ({ "tianxiang yulu", "tianxiang", "yulu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ƿ");
                set("long", HIG "������ɽ��ǧ��������֥Ϊĸ�����ϵ�"
                            "��ȡ���վ��»���\n" NOR);
                set("value", 30000);
        }
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me = this_player();

        string mapsk;
        int na, un;
        mapping my = me->query_entire_dbase();

        na = query("name");
        un = query("unit");

        if (! arg || ! id(arg))
                return notify_fail("��Ҫ��ʲô������\n");

        if (me->is_busy())
                return notify_fail("��ʲô��С�ı�ҭ���ˡ�\n");

        if ((int)me->query_condition("pill_drug") > 0)
        {
                write("�����������Ϣδ���������������ܸе������嵴����"
                      "��óȻ��ʳ��\n");
                return 1;
        }

        me->apply_condition("pill_drug", 4000);

        message_vision(HIY "$N" HIY "����һ" + un + na + HIY "����ɫһ�䣬��"
                       "����������ࡣ\n" NOR, me);

        mapsk = me->query_skill_mapped("dodge");

        if (me->can_improve_skill("dodge")
           || (stringp(mapsk) && me->can_improve_skill(mapsk)))
	{
        	if (me->can_improve_skill("dodge"))
                	me->improve_skill("dodge", 20000);

        	if (stringp(mapsk) && me->can_improve_skill(mapsk))
                	me->improve_skill(mapsk, 20000);

        	tell_object(me, HIG "��ֻ����������ƮƮ���ɣ����ƻ��������һ�㡣\n" NOR);
	} else
        	tell_object(me, HIY "��е���̨��һ������������õ�����ȫ�Ĳ��䡣\n" NOR);

        me->improve_jingli(100 + random(101));

        if (me->query("jingli") < me->query("max_jingli"))
                my["jingli"]  = my["max_jingli"];

        me->start_busy(random(8) + 8);
        destruct(this_object());
        return 1;
}

int query_autoload()
{
        return 1;
}

