inherit ROOM;

void create()
{
	set("short", "���ɴ���");
	set("long", @LONG
������ɽ�Ļ��£������˰�ʯȥ�����������޳�һ������״��
ƽ̨����ӷֱ��ڸ���ƽ̨�ϣ��������ӣ�������ʯ��Χǽ������
��·Ҳ��ʯͷ�̳ɡ�
LONG);
	set("outdoors", "dali");
	set("exits", ([
                "west"  : __DIR__"wunong",
                "east"  : __DIR__"caopo",
                "north" : __DIR__"wuyiminju1",
                "south" : __DIR__"wuyiminju2",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

