inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����ǹص���ĺ����жѷ����㡢������ǽ�ϵ�
ᣲ����������µġ�
LONG);
	set("exits", ([
		"north" : __DIR__"houmen",
		"south" : __DIR__"guanmiao",
	]));

	setup();
	replace_program(ROOM);
}

