inherit ROOM;

void create ()
{
	set ("short", "ɽ·");
	set ("long", @LONG
����һ�����������ɽ·����Ϊ����ɽ�ȼ���ɽ�����Ƚ�
Զ�����������ǿ�����·�������˺ܶ࣬·�������Զ���и�
Сͤ�ӹ�����Ъ�ţ����߲�Զ������ɽ��ڡ�
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"north" : "/d/songshan/taishique",
		"east" : "/d/shaolin/maowu",
		"eastup" : __DIR__"shanlu1",
	]));

	setup();
        replace_program(ROOM);
}
