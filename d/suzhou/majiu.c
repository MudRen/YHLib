#include <room.h>
inherit TRANS_ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����Ǳ���ֵ���ǣ����깩Ӧ���ʲ��ϡ�������紾��
����ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ��
��Ǭ������һֱ�ź򵽿�����·����������µ���ľ���϶���
һ����ľ��(paizi)������жѷ������Ѳ��ϡ�
LONG);
      set("outdoors", "suzhou");
      set("exits", ([
		"west" : __DIR__"kedian",
                "up"   : "/clone/shop/suzhou_shop",
      ]));
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
