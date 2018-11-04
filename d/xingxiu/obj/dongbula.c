#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name(YEL "������" NOR, ({ "dongbula" , "dong", "bula" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL "����һ��ά�����������������������������(play)����\n" NOR);
                set("value", 1000);
        }
}

void init()
{
        add_action("do_play", "play");
}

int do_play(string arg)
{
        object me = this_player();

        if (! id(arg))
                return notify_fail("��Ҫ����ʲô��\n");

        if (this_object() != me->query_temp("handing"))
                return notify_fail("�����Ѷ������������С�\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        me->start_busy(1);
        switch(random(3))
	{
                case 0:
        		message_sort(HIC "$N" HIC "���𶬲���������س���������ң"
                                     "Զ�ĵط�����λ�ù�����Ǿ���������ձ������"
                                     "Ҫ���������������\n\n" NOR, me);

                        break;
                case 1:
        		message_sort(HIC "$N" HIC "���𶬲��������ֵس����������"
                                     "��ʯͷԲ��Ӳ����ϴ�����ඣ�����ǵĹ������"
                                     "�����ֻ�۾���Ư����\n\n" NOR, me);

                        break;
                case 2:
        		message_sort(HIC "$N" HIC "���𶬲��������˵س��������̲"
                                     "�ϵ�һ����Ȫ��ɽ�ϵ�һ��ѩ�����籩������Զ��"
                                     "ͣ����ʱ���ܼ������Ц����\n\n" NOR, me);
                        break;
        }
        return 1;
}

