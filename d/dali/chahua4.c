inherit ROOM;

void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����
վ�ڲ軨԰�У�������һƬ�������ٵĺ��档���Ű�������
֮�£��м���軨���������ˣ�����԰�����Ĳ軨Χ�У���
��Ȼ��Ⱥ��
LONG);
	set("objects", ([
	   	__DIR__"obj/chahua4": 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"northeast"  : __DIR__"chahua5",
	    	"northwest"  : __DIR__"chahua2",
	]));
	setup();
	replace_program(ROOM);
}

