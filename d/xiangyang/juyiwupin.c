inherit ROOM;

void create()
{
	set("short", "��Ʒ��");
	set("long", @LONG
���Ǿ���ݵĶѷŸ��ָ�����Ʒ�ķ��䡣
LONG );
	set("exits", ([
		"northwest" : __DIR__"juyihuayuan",
	]));
	setup();
	replace_program(ROOM);
}

