inherit ROOM;

void create()
{
	set("short", "��ˣ����");
	set("long", @LONG
�տ���һ�鳡�أ��м��м�����ǿ��׳�����������ű��ݡ��Ӽ���ħ
����������������������������ۿ�������Χ������Ⱥ���������٣�����
��Ů����ʱ�ķ���������̾����
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"south" : __DIR__"fengwei",
  		"east" : __DIR__"roudian",
	]));
        set("objects", ([
                "/d/beijing/npc/maiyi2" : 1,
                "/d/beijing/npc/maiyi1" : 1,
                "/d/beijing/npc/xianren" : 2,
                "/d/beijing/npc/boy2" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
