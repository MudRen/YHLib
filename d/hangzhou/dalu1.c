#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�غ����");
        set("long", @LONG
·�Ķ�����һ��Сɽ��ɽ�������дУ�����������ɽ�ϱ���һ��
���������ĺõط�����ȴ��������ռΪ˽�С���·�򶫱����ϱ����졣
LONG);
        set("exits", ([
            	"north" : __DIR__"dadao2",
            	"south" : __DIR__"dadao3",
        ]));
        set("objects", ([
            	__DIR__"npc/tiao-fu": 1,
            	__DIR__"npc/honghua1" : 2,
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
