inherit ROOM;

void create()
{
	set("short", "С·");
        set("long", @LONG
������һ����ɽ��С·��С·�����ֳ�һ�������ɽ·��
Χ���Ǽž���������ɽ�������ѣ����������˳�û�ڴˡ�
LONG);
	set("outdoors", "baituo");
	set("exits", ([
		"north"     : __DIR__"dongkou",
		"southwest" : __DIR__"xiaolu3",
	]));
	set("objects", ([
		__DIR__"npc/shanzei2" : 1,
	]));
	setup();
	replace_program(ROOM);
}
