inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�
ׯ��Χ��һ������أ����д�����ų�һ�������֣�������
Щ���ڸ�����ũ�ˣ���·��̰��·Ҳ�ɴ���䴩����
LONG);
        set("outdoors", "guiyun");
	set("exits", ([
		"northeast"  : __DIR__"shulin5",
		"west"       : __DIR__"yixing",
	]));
	set("objects", ([
		"/clone/quarry/niao" : 1,
	]));
	setup();
        replace_program(ROOM);
}
