inherit ROOM;

void create()
{
	set("short", "�䶨��");
	set("long", @LONG
������̨�ķ�֧¬¹�����������θ����������������䶨���⻹
ϽԪı��»�����򡣴��򲻴�����ɽ����������Եø������ġ�
¬¹���˵���¥��ɢ�ֲ��������С�
LONG);
	set("outdoors", "dali");
	set("exits", ([
                "north"     : __DIR__"zhulou1",
                "northeast" : __DIR__"zhulin",
                "west"      : __DIR__"qingzhulin",
                "south"     : __DIR__"nongtian1",
	]));
        set("objects", ([
                __DIR__"npc/guniang": 1,
                "/clone/npc/walker" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

