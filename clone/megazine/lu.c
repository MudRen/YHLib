#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIG "���ķ�ȹȿڡ�" HIY);
        set("long", 
@LONG                     
���ܵ����°�Χ�����ɽ��,�Ա��и�ʯ��д�š��ķ��--���������
�����֡����ϲ�ʱ�����Ĳ�ӥ����ʱʱ�̿�������������һ���˼������ĵط�,
����������ȴ�е��ޱȵ�˳������.ǰ���С·����������,��ֻ��ģ���Ŀ�
��һƬ�������м�����
LONG);
        set("exits", ([
             "north" : __DIR__"lu1",
             "back" : "/d/city/guangchang",
	]));
        set("objects", ([
             //"/d/baituo/npc/fox.c" : 1,
	]));
	replace_program(ROOM);
        setup ();     
}

