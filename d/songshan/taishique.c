
inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
��ɽ�ųƷ��⣬�ֳƳ�ɽ��Ϊ�����е���������̫������
��ɽ������ɡ������ʱ��֮Ϊ���Ըߡ���ȡ��ʫ��������ά
�ߣ��������졹��������֮Ϊ����С���졣�׸����࣬�����
������̫�����ǡ����֣�׭�Ĺ��ӣ��Ծ���������������ȥ��
��ɽ�����µ�·������һ��������������ˣ�������һС�ݡ�
LONG );
	set("exits", ([
		"north" : __DIR__"tianzhongge",
		"east"  : "/d/shaolin/ruzhou",
		"west"  : "/d/shaolin/shijie1",
                "south" : "/d/kaifeng/shanlu2",
	]));
	set("outdoors", "songshan");
	setup();
	replace_program(ROOM);
}

