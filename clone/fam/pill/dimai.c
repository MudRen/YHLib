#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIM "����ѪȪ" NOR, ({ "dimai xuequan", "dimai", "xuequan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIM "����һ��ɢ����Ѫɫ����ľ��壬���亱�С�\n" NOR);
                set("value", 30000);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        string mapsk;
        int na, un;
        mapping my = me->query_entire_dbase();

        na = query("name");
        un = query("unit");

        if ((int)me->query_condition("pill_drug") > 0)
        {
                write("�����������Ϣδ���������������ܸе������嵴����"
                      "��óȻ��ʳ��\n");
                return 1;
        }

        me->apply_condition("pill_drug", 4000);

        message_vision(HIY "$N" HIY "����һ" + un + na + HIY "����ɫһ�䣬��"
                       "����������ࡣ\n" NOR, me);

        mapsk = me->query_skill_mapped("force");

        if (me->can_improve_skill("force")
           || (stringp(mapsk) && me->can_improve_skill(mapsk)))
	{
        	if (me->can_improve_skill("force"))
                	me->improve_skill("force", 20000);

        	if (stringp(mapsk) && me->can_improve_skill(mapsk))
                	me->improve_skill(mapsk, 20000);

        	tell_object(me, HIR "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
	} else
        	tell_object(me, HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);

        me->improve_neili(100 + random(101));

        if (me->query("neili") < me->query("max_neili"))
	        my["neili"]  = my["max_neili"];

        me->start_busy(random(8) + 8);
        destruct(this_object());
        return 1;
}

int query_autoload()
{
        return 1;
}

