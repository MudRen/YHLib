#include <ansi.h> 
inherit ROOM;

int exercise_improve();
	
void create()
{
        set("short", "������");
	set("long", @LONG
����������ɽͯ�������ڹ��ĵط�������������һ��ǧ��
���� (ice)������ð��˿˿������������˺������ˣ��㲻��
�ô���һ��������
LONG);
        set("exits", ([
		"east" : __DIR__"changl13",
        ]));

	set("item_desc", ([
	        "ice" : HIW "\n����һ�������ɽ֮�۵�ǧ"
                        "���������溮�ޱȡ�\n\n" NOR,
	]));

        set("exercise_improve", (: exercise_improve :));

	setup();
        replace_program(ROOM);
}

int exercise_improve()
{
        object me;

        me = this_player();

        if (me->query_skill("bahuang-gong", 1) >= 10)
        {
                if (random(5) == 0)
                        tell_object(me, HIW "\n�����ð˻�����Ω�Ҷ���"
                                        "���������������й���\n");
                return me->query_skill("force") / 10;
        }

        tell_object(me, HIW "\n�㶳������ֱ�����������ϢҲ��һ����Ļ�"
                        "�ҡ�\n" NOR);
        return -20;
}
