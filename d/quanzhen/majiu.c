#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
�����书�����ǣ���Ϊƽʱ�������˲��࣬�Ե���Щ��
�ɡ���������µ���ľ���϶���һ����ľ�� (paizi)�����ж�
�������Ѳ��ϣ�������һ����ۡ�
LONG);
      set("outdoors", "wugong");
      set("no_fight", 1);
      set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
                "south" : __DIR__"kedian1",
      ]));
      setup();
      replace_program(TRANS_ROOM);
}

