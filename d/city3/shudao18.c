#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����������������µ�����ϣ��������ٹ���Զ���͵���
���ˣ�����ʼ�����ն�������
LONG);
        set("exits", ([
                "west" :  __DIR__"shudao19",
                "eastdown" : __DIR__"shudao17",
        ]));
        
        set("no_clean_up", 0);
        set("outdoors", "chengdu");
        setup();
	replace_program(ROOM);
}

