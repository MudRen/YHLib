inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
������һ����������Ĵ�ٵ��������������ݵ����ɵ�����
�����ǿ�㣬����ݵ���ʮ���ۡ�
LONG);
	set("exits", ([
		"west"  : __DIR__"shang_road1",
		"east"  : __DIR__"shang_road3",
	]));
	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}
