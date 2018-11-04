#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "����֮ͫ" NOR, ({ "dragon eye", "dragon", "eye" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "���h�г��������飬�ƺ����Է��á�\n" NOR);
                set("unit", "�w");
                set("value", 500000);
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
                write("�����������Ϣδ���������������ܸе���"
                      "���嵴������óȻ��ʳ��\n");
                return 1;
        }

        me->apply_condition("pill_drug", 3000);

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

                tell_object(me, HIM "��ֻ��һ��ů��ɢ��ȫ��˵������������á�\n" NOR);
        } else
                tell_object(me, HIY "��ֻ��һ������ӿ�ϣ���Ϣ�õ�����ȫ�Ĳ��䡣\n" NOR);

        if (me->query("neili") < me->query("max_neili"))
                my["neili"]  = my["max_neili"];

        me->start_busy(random(3) + 3);
        destruct(this_object());
        return 1;
}
