inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @long
�����ǿ���������򵥣�ֻ�м��Ŵ�����ƣ���Ŀ�����Ъ
Ϣ�������￾�Ż�ů���ġ�
long);
        set("exits",([
		"east" : __DIR__"wlang01",
	]));

	set("no_fight",1);
	set("sleep_room",1);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
