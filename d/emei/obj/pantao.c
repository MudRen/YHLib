#include <ansi.h>
inherit ITEM;

void create()
{
  	set_name(HIR "���" NOR, ({"pan tao", "pan", "tao"}));
  	set_weight(150);
  	if (clonep())
    		set_default_object(__FILE__);
  	else {
    		set("long", HIR "һ�����ɫ�Ĵ���ң���ɢ�����˱ǵ����㡣\n" NOR);
    		set("value", 3000);
                set("only_do_effect", 1);
    		set("unit", "��");
  	}
  	setup();
}

int do_effect(object me)
{
        string force;
        int neili_limit;

        neili_limit = me->query_neili_limit();

        message_vision(HIR "\n$N" HIR "�����ڽ����е���ҽ������£�һ������ʱ��"
                       "��ͨ�졣\n\n" NOR, me);
        me->start_busy(random(5) + 5);

  	if (me->query("max_neili") < neili_limit)
       	{
               	me->add("max_neili", 30 + random(30));
               	if (me->query("max_neili") > neili_limit)
                       	me->set("max_neili", neili_limit);
               	me->set("neili", me->query("max_neili"));
       	}
        force = me->query_skill_mapped("force");
       	if (me->can_improve_skill("force"))
               	me->improve_skill("force", 10000);
       	if (stringp(force) && me->can_improve_skill(force))
               	me->improve_skill(force, 10000);

        destruct(this_object());
        return 1;
}

