inherit ROOM;

void create()
{
	set("short", "���۲�");
	set("long", @LONG
����������·���ǰ��ĵ�һ֧ͽ���۾ӵĵط����˵ؽ�
ƫԶ������Ҳ��������һƬ����������ƺ�������ɽ��ˮ
�㣬ɣ���ܲ�������һƬСƽԭ������Щũ����˼�ɣ
���࣬��˿������񸾶��÷�˿֯�顣
LONG);
	set("objects", ([
	   	__DIR__"npc/bshangfan" : 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
                "west"   : __DIR__"banshan",
                "east"   : __DIR__"yangcanfang",
                "south"  : __DIR__"xingyunhu",
                "north"  : __DIR__"nongtian5",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

