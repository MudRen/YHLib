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
	    "north" : __DIR__"guibingshi1",
	    "west" : __DIR__"zoulang1",
	    "east" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

