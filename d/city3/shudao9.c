#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������һ����ɽ��ɽ�����ٽ�һ���Ƕ��͵����£���ϸ��
ȥ����һЩʯ�ѿ�����ţ�����ȥ��ֻ���������к����м���
���ӡ�
LONG);
        set("exits", ([
  		"eastdown" :  __DIR__"shudao8",
  		"west" : __DIR__"baidicheng",
   	]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

