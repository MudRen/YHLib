inherit ROOM;

void create()
{
	set("short","˾����");
	set("long",@LONG
�����Ǵ����˾���á�������ǿ�Σ�������ެ������
���߽���������˾���Ͷ�֮��������ެ���Ѵ����Ѿã�ÿÿ
ǿ��в�ȣ������ò��ر���������
LONG);
	set("objects", ([
	    	CLASS_D("duan") + "/fan" : 1,
	]));
	set("exits", ([
	    	"west"  : __DIR__"zonglichu",
	]));
	setup();
	replace_program(ROOM);
}

