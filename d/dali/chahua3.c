inherit ROOM;

void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����
�����ڲ軨԰�У�������ܵĶ������涷���Ĳ軨�����ϰ�
��һ������ԵĲ軨��΢���ˮ�洵����ҡҷ��涡�
LONG);
	set("objects", ([
	   	__DIR__"obj/chahua8": 1,
	   	__DIR__"obj/chahua9": 1,
	   	__DIR__"obj/chahua10": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"southwest"  : __DIR__"chahua2",
	    	"north"      : __DIR__"chahua6",
	    	"southeast"  : __DIR__"chahua5",
	]));
	setup();
	replace_program(ROOM);
}

