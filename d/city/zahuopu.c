inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ
�ճ���Ʒ�����ƹ������������һֻ�����ϣ��к��Ź������ˡ�
��˵˽������Ҳ��һЩ���صĶ�����
LONG );
	set("exits", ([
		"north" : __DIR__"dongdajie1",
		"up"    : __DIR__"garments",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));
	setup();
	replace_program(ROOM);
}

