inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��ط��Ǹ���أ����ܸ�ɽ���������·��겻�֣�ǧ����
֮�����������ã�ʵ�Ǻ������ţ���·ֻ����ذ׹ǣ���ǹ
��ꪣ������Ҷ������е�·Ҳ�����Թ��������ۻ����ҡ�
LONG);
        set("outdoors", "gaochang");

	set("exits", ([
		"east" : __DIR__"feixu2",
		"north" : __DIR__"shanjiao",
	]));

	setup();
	replace_program(ROOM);
}
