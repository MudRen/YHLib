inherit ROOM;

void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����
վ�ڲ軨԰�У�������ǧ�죬���涷�������ش�ˬ��������
��һ��Сʯ���ʣ��ʺ��������У���ҷˮ�棬���Ǻ�����
��һ����������
LONG);
	set("objects", ([
	   	__DIR__"obj/chahua1": 1,
	   	__DIR__"npc/huanu": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"west"  : __DIR__"chahua1",
	    	"northeast"  : __DIR__"chahua3",
	    	"southeast"  : __DIR__"chahua4",
	]));
	setup();
	replace_program(ROOM);
}

