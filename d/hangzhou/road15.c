#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ˣ����У���˽Σ�����������ϲ�������������
�������������߸���һ��������ϱ��������ɽ��ɽ·���������Ǿ�
���¡�
LONG);
        set("exits", ([
            	"north" : __DIR__"road14",
            	"south" : __DIR__"yuhuangsj",
            	"west"      : __DIR__"road16",
            	"east"      : __DIR__"jingcisi",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
