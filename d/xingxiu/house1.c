inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ǰ�����ҵĿ������������Ų�˹��̺��ľ���ϰ�����
ԭ�Ĵ�����
LONG);
        set("exits", ([ 
            	"west" : __DIR__"house",
        ]));
        set("objects", ([
                __DIR__"npc/afanti": 1
        ]));
        set("outdoors", "xingxiu");

        setup();
        replace_program(ROOM);
}

