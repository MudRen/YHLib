#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
ɽ����ľï�ܣ�������䣬���ϸ������������ɽϪ��ˮ
���������紵��ҳ����������ͬһ�״���Ȼ���������������
LONG);
        set("exits", ([
  		"northeast" : __DIR__"qingshan1",
  		"west" : __DIR__"road6",
	]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");
        setup();
        replace_program(ROOM);
}

