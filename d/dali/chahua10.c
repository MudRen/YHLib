inherit ROOM;

void create()
{
	set("short","�軨Է");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����
���Ǹ��еĲ軨Է��������Ʒ�Ͼ��ڴˣ��������Է�軨��
��ŭ�ţ�ʵ�ڲ�֪���ı��軨����Щ��
LONG);
	set("objects", ([
	   	__DIR__"obj/chahua2": 1,
	   	__DIR__"obj/chahua3": 1,
	   	__DIR__"obj/chahua6": 1,
	]));
	set("exits", ([
	    	"west"  : __DIR__"chahua7",
	]));
	setup();
	replace_program(ROOM);
}

