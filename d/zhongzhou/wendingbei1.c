inherit ROOM;

void create()
{
        set("short", "�Ķ�����");
        set("long", @LONG
���������Ķ����֣����Ľֵ������˲�������һ������
���Ķ�����һ����¥������ֲ�Զ�����滮ȭ�Ⱦ�����������
���������ڶ���Ҳ������ȥʹ��һ������������С� 
LONG);
	set("outdoors", "zhongzhou");

        set("exits", ([
                "east" : __DIR__"yinghao",
                "south" : __DIR__"shizhongxin",
                "west" : __DIR__"xiaoxiang",
                "north" : __DIR__"wendingbei2",
        ]));

        set("objects", ([
	        "/d/beijing/npc/xianren" : 1,
        	"/d/beijing/npc/kid1": 1,
        ]));

        setup();
        replace_program(ROOM);
}
