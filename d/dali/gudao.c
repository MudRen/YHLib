inherit ROOM;

void create()
{
	set("short", "�ŵ�");
	set("long", @LONG
һ��ʯ��ŵ���������ľ�Դ䣬ɽ��ƽ����������һ��
�޼ʵ���˫���ɴ�ɭ�֡����������һƬ��ΰ������һ����
���ĺ�ǽ������Խ��ǽͷ�ɼ�һ����¥���������Ǵ�����
ʤ�廪¥��
LONG);
	set("outdoors", "dali");
	set("exits", ([
                "enter" : __DIR__"dating",
                "west"  : __DIR__"shanlu6",
                "east"  : __DIR__"luyuxi",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

