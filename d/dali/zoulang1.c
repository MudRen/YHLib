inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
����һ�����������ȣ�ͨ��������˵����ҡ���������
��¥��ëձ�Ѿ����ɴ��ף�����ľ���ϻ���л�����棬��
����Щ��ʱ�˵��ֻ���ÿ���߰˲�������һ����̨��������
�̴�ͭ�������γ�����֮����һ��
LONG);
	set("exits", ([
	    	"down" : __DIR__"louti",
	    	"west" : __DIR__"zoulang2",
	    	"east" : __DIR__"zoulang3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

