inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ�����������ȣ�ͨ��������˵����ҡ�����ľ���ϻ�
���л�����棬�����Щ��ʱ�˵��ֻ���ÿ���߰˲�������
һ����̨���������̴�ͭ�������γ�����֮����һ��
LONG);
	set("exits", ([
	    	"east" : __DIR__"eastroom1",
	    	"north" : __DIR__"zoulang6",
	    	"south" : __DIR__"zoulang2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

