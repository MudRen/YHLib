#include <room.h>
inherit ROOM;

void create()
{
      set("short", "��ݲ�����");
      set("long", @LONG
���������ʯ���������󵶳�����ɳ�����ȵȣ����м���
���������ľ�ˣ�����ݵ����ճ������ĵط���
LONG);

      set("exits", ([
          	"down" : __DIR__"wuguan",
      ]));

      set("objects", ([
          	"/clone/npc/tong-ren" : 1,
      ]));

      setup();
      replace_program(ROOM);
}
