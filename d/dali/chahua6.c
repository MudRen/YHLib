inherit ROOM;

void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����
վ�ڲ軨԰�У������Ǵ��̵Ĺ�ľ�������ŵ��Ǳ��������
�ĺ���һ���峹��СϪ�������������С�����м���һ��
���޵Ĳ軨��
LONG);
	set("objects", ([
	   	__DIR__"obj/chahua5" : 1,
	]));
	set("outdoors", "dali");
	set("exits", ([
	    	"south"  : __DIR__"chahua3",
	    	"north"  : __DIR__"chahua7",
	]));
	setup();
	replace_program(ROOM);
}

