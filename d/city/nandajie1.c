inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ϴ���ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���
Ϊ���֡�Ц�����������������һƬ��������Ķ��䣬�㲻��
��Գ��������ʹ�ͣ������һ���������Ǹ����ֵĹ㳡����
����һ�ҵ��̣�ǽ��д��һ�����ġ������֣���ϸ��������
������ѹ�͵��ּۻ��۵���������������һƬ������������һ
��һʮ����Ǯ����ԭ�����Ƿ�Բǧ��֮������һ�Ҷĳ���
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"dangpu",
		"south" : __DIR__"nandajie2",
		"west"  : __DIR__"duchang",
		"north" : __DIR__"guangchang",
	]));
	set("objects", ([
		__DIR__"npc/hunhun" : 1,
		__DIR__"npc/liumang": 4,
		__DIR__"npc/liumangtou" : 1,
		"/clone/npc/xunbu" : 1,
	]));

	setup();
	replace_program(ROOM);
}

