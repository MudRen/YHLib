#include <ansi.h>
inherit ROOM;

void create()
{
      	set("short", "�⽣��");
      	set("long", @LONG
���������м���ʢ�����䵱�⽣�ң����½⽣��ˮ������
�ˡ�������ʿ���˶��Ծ��⽣����ʾ���䵱�ɵ��𾴡�ǧ����
�����������⡣
LONG);
      	set("objects", ([
           	CLASS_D("wudang") + "/shan": 1,
      	]));
      	set("outdoors", "wudang");
      	set("exits", ([
          	"eastdown"  : __DIR__"slxl2",
          	"westup"    : __DIR__"slxl3",
      	]));
      	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;

        me = this_player();
        if ((me->query_temp("weapon")
           || me->query_temp("secondary_weapon"))
           && dir == "westup"
           && objectp(present("zhang cuishan", environment(me))))
        {
            message_vision(CYN "\n�Ŵ�ɽ�ȵ�����ɫ�˵ȣ����⽣�Ҷ���⽣��ǧ��"
                               "�����������⣡\n" NOR, me);
            return notify_fail(HIC "�������䵱ɽ�棬����Ӳ����ֻ������һ����\n"
                               NOR);
        }
        return ::valid_leave(me, dir);
}

