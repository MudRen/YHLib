#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",HIR "С��������" NOR);
	set("long", @LONG
���ǡ������á���¼�ĵڶ�������С��(teddy)�ĳ����ң������
������С��һ����С�������Լ����ļ�飨explain)��
LONG
	);

	set("exits", ([ 
                      "out" : "/clone/megazine/room/mingren",
]));
          set("objects",([
                "/clone/megazine/room/mingren/teddylx":1,
]));
/*
          set("item_desc",([
                          "explain":HIR "�� ��  �� ���䵱�ɵ��Ĵ����ˡ���ȱ����-��˫��������ħ(bingo)��\n"
                                   HIR "�����ռ������ﲻ������ĸ��֣����ľ�����������������Խ�ء�\n" NOR,
]));
*/
	set ("no_fight",1);
        set("no_clean_up", 0);
     	setup();
}
