// xuanhuang.c �������䵤

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "�������䵤" NOR, ({ "xuanhuang dan", "xuanhuang", "dan" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIM "һ�����з��Ƶľ����浤���������񻰰�Ĺ�Ч����\n"
                                "˵����֮����ƽ����ʮ��Ĺ�������������֮������\n"
                                "���������ҩ��\n" NOR);
                set("value", 100000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        string mapsk;
        int effect;
        int neili;

        log_file("static/using", sprintf("%s(%s) eat �������䵤 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        effect = 0;

        if (me->query("skybook/item/xuanhuang"))
        {
	        message_vision(HIR "$N" HIR "һ������������һ���������䵤��ȴ��$P"
                               HIR "һ�����������һ����Ѫ������㵹��\n" NOR, me);

                me->set_temp("die_reason", "̰���������䵤�����Ū��ȫ���������"
                                           "����");
                me->die(); 
        } else
	{
        	message_vision(HIW "$N" HIW "һ������������һ���������䵤��ֻ��$P"
                               HIW "����һ�������϶�ð����������\n" NOR, me);

        	me->add("combat_exp", 100000 + random(50000));
        	me->add("potential", 10000);

        	mapsk = me->query_skill_mapped("force");
        	if (me->can_improve_skill("force"))
                	me->improve_skill("force", 1500000);
        	if (stringp(mapsk) && me->can_improve_skill(mapsk))
                	me->improve_skill(mapsk, 1500000);

        	mapsk = me->query_skill_mapped("parry");
        	if (me->can_improve_skill("parry"))
                	me->improve_skill("parry", 1500000);
        	if (stringp(mapsk) && me->can_improve_skill(mapsk))
                	me->improve_skill(mapsk, 1500000);

        	mapsk = me->query_skill_mapped("dodge");
        	if (me->can_improve_skill("dodge"))
                	me->improve_skill("dodge", 1500000);
        	if (stringp(mapsk) && me->can_improve_skill(mapsk))
                	me->improve_skill(mapsk, 1500000);

        	me->improve_neili(500);
        	me->set("skybook/item/xuanhuang", 1);
	}
        destruct(this_object());
        return 1;
}

int query_autoload()
{
        return 1;
}