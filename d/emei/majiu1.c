#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���ǲ���ߵ���ǣ����깩Ӧ���ʲ��ϡ�����ǻ����ǣ
����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ
�ź򵽿�����·������жѷ������Ѳ���������һ����ۡ���
�������µ���ľ���϶���һ����ľ��(paizi)��
LONG);
      set("outdoors", "emei");
      set("exits",([
              "east"    : __DIR__"caopeng",
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
