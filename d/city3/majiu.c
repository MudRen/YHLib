#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short", "���");
      set("long", @LONG
���ǳɶ��ǵ���ǣ����깩Ӧ���ʲ��ϡ��ɶ���紾����
���ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�
Ǭ������һֱ�ź򵽿�����·����������µ���ľ���϶��ſ�
��ľ��(paizi)������жѷ������Ѳ��ϡ�
LONG);
      set("outdoors", "chengdu");
      set("no_fight", 1);
      set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
      ]));
      set("exits", ([
                "west" : __DIR__"kedian",
                "up"   : "/clone/shop/chengdu_shop",
      ]));
      setup();
      replace_program(TRANS_ROOM);
}

