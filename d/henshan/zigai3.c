inherit ROOM;

void create()
{
	set("short", "ˮ������");
	set("long", @LONG
�������ܿտ�������������ȴû����ô��ʪ��·������ȴ
û���ˡ�
LONG);

	set("exits", ([
	       "south" : __DIR__"zigai2",
	]));
	
	set("objects", ([
	       "/clone/beast/yanjingshe" : 2,
	]));
	
	setup();
	replace_program(ROOM);
}


