#include <room.h>
inherit TRANS_ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
�����ų�����ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ���
���ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�
Ǭ������һֱ�ź򵽿�����·����������µ���ľ���϶��ſ�
��ľ��(paizi)������жѷ������Ѳ��ϡ�
LONG);
      set("exits",([
		"south" : __DIR__"rongcheng",
                "up"    : "/clone/shop/fuzhou_shop",
      ]));
      set("outdoors", "fuzhou");
      set("no_fight", 1);
      set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
      ]));
      setup();
      replace_program(TRANS_ROOM);
}
