inherit ROOM;

void create()
{
	set("short","˾����");
	set("long",@LONG
�����Ǵ����˾���á�����������ı�ȴ�������鼮��
�������˰������������㹤�����ֲ��;�
LONG);
	set("objects", ([
	    	CLASS_D("duan") + "/ba" : 1,
	]));
	set("exits", ([
	   	"south"  : __DIR__"zonglichu",
	]));
	setup();
	replace_program(ROOM);
}

