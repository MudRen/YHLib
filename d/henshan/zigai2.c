inherit ROOM;

void create()
{
	set("short", "ˮ������");
	set("long", @LONG
�������ܿտ�������������ȴû����ô��ʪ��
LONG);
	set("exits",([
	       "south" : __DIR__"inhole2",
	]));
	
	set("objects",([
	       "/clone/beast/yanjingshe" : 2,
	]));
	
	setup();
	
}

void init()
{
       object me = this_player();

       if (present("fire", me))
              	set("exits/north", __DIR__"zigai3");
	
	return ;
}


