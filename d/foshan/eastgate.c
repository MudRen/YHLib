inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ƿ�ɽ��Ķ��š��������ߣ����þ�Ҫ�뿪��ɽȥ��
�����ˡ�����һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG);
	set("outdoors", "foshan");
	set("exits", ([
	    "east" : __DIR__"road8",
	    "west" : __DIR__"street5",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

