#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short", "���");
      set("long", @LONG
���������ݿ͵�����ǣ����깩Ӧ���ʲ��ϡ��������
���ӣ�����ǻ����ǣ����Ǻ����տ���������ι�����㣬��
ϴˢ�ø�Ǭ������һֱ�ź򵽿�����·����������µ���ľ��
�϶���һ����ľ�� (paizi)������жѷ������Ѳ��ϡ�
LONG);
      set("outdoors", "city");
      set("no_fight", 1);
      set("objects", ([
              "/clone/horse/zaohongma": 1,
              "/clone/horse/huangbiaoma": 1,
              "/clone/horse/ziliuma": 1,
              "/clone/npc/mafu": 1,
      ]));
      set("exits",([
              "west" : __DIR__"zuixianlou",
              "up"   : "/clone/shop/yangzhou_shop",
      ]));
      setup();
      replace_program(TRANS_ROOM);
}
