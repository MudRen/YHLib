inherit ROOM;

void create()
{
        set("short", "С��ͬ");
        set("long", @LONG
������һ��С��ͬ�����ڰ�������Ҳ�ǻ谵������������
�����˺�ͬ�ľ�ͷ����һ���Ž����š�
LONG);
	set("outdoors", "zhongzhou");
        set("exits", ([
                "north"     : __DIR__"liwu",
                "southwest" : __DIR__"hutong1",
        ]));
        set("objects", ([
                "/d/beijing/npc/dipi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

