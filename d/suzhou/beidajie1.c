inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ
�Ҵң�����˶����ϱ���ȥ��������һ�����ֵ�ͤ�ӡ�������
��һ��Ϸ԰�ӣ���ʱ�����к��������Ը��ص����ǽ���������
�ڶ�����һ���͵ꡣ������һ����ǡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"kedian",
		"west" : __DIR__"xiyuan",
		"north"     : __DIR__"beidajie2",
		"south"     : __DIR__"canlangting",
	]));
	setup();
	replace_program(ROOM);
}

