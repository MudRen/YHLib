#include <room.h>
inherit TRANS_ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
�����Ƿ�ɽ�����ǣ����깩Ӧ���ʲ��ϡ���ɽ��紾��
����ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ��
��Ǭ������һֱ�ź򵽿�����·����������µ���ľ���϶���
һ����ľ��(paizi)������жѷ������Ѳ��ϡ�
LONG);
      set("exits",([
		"north" : __DIR__"yingxionglou",
                "up"    : "/clone/shop/foshan_shop",
      ]));
      set("outdoors", "foshan");
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
