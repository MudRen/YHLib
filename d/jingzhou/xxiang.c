inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ�������ֺڵ����ӣ�ɢ����һ������ˮ��ζ����ʳ
�﷢ù��ζ���������ֳ���
LONG);
        set("outdoors", "jingzhou");
	set("exits", ([
		"south" : __DIR__"xxend",
		"north" : __DIR__"dongdajie2",
	]));

	setup();
	replace_program(ROOM);
}

