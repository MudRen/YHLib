// xisuidan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "ϴ�赤" NOR, ({ "xisui dan", "dan", "xisuidan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�źڲ�����ĵ�ҩ����֪����ʲô�á�\n");
                set("value", 10000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("gift/xisuidan") >= 5)
        {
                message_vision("$NͻȻ����һ������ޱȵ���ƨ��\n", me);
                tell_object(me, "����ô���ǳԻ��˶��ӡ�\n");
        } else
        if (random(5) == 0)
        {
                tell_object(me, "��������ú���ûʲô���á�\n");
        } else
        {
                message("vision", "���ƺ�����" + me->name() + "�Ĺ�ͷ���������졣\n",
                                  environment(me), ({ me }));
                tell_object(me, HIY "�����Ĺ�����ʱ�������������ͣ���ɰ����Ż��ˣ�"
                                "����һ�����ͣ���������ƺ���Ǹ�����ˡ�\n" NOR);
                me->add("con", 1);
        }

        me->add("gift/xisuidan", 1);
        destruct(this_object());
        return 1;
}

