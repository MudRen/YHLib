#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG "���ķ��С·��" HIY);
        set("long", @LONG                     
���ܵ����������㿿£��һ��,��ӥ�����Ѿ����������.
�������Ѿ�����Ũ�����ֵ����֣���ֻ�ܿĿ���������ǰ��ȥ��
LONG);
         set("exits", ([
             "north" : __DIR__"men",
             "south" : __DIR__"lu",
	]));
        set("objects", ([
             "/clone/beast/jinshe.c" : 1,
             //"/d/baituo/npc/fox.c" : 1,

	]));

    setup ();     
	replace_program(ROOM);
}

