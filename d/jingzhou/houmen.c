inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǹص���ĺ��ţ�������ȥ����Զ����һ��Сɽ�¡�
LONG);
	set("exits", ([
		"south" : __DIR__"houdian",
		"northup" :__DIR__"xiaoshan",
	]));

	setup();
	replace_program(ROOM);
}

