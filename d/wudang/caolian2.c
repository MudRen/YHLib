#include <room.h>

inherit ROOM;

void create()
{
      	set("short", "���������");
      	set("long", @LONG
��������˴󵶳�����ɳ�����ȵȣ����䵱�����ճ�����
�ĵط���
LONG );

      	set("exits", ([
            	"south"   : __DIR__"caolianfang",
      	]));
      	set("for_family", "�䵱��");
      	setup();
      	replace_program(ROOM);
}
