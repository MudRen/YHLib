inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
��ɽ��ɽ����ʯ����ģ���֮���޹Ķ���������ֻɽ����
�ĸ��ء�ɽ�ϲ��ɵδ䣬������ģ��羰�������ļ��紺����
����������Ϊ��������֮һ��
LONG );
	set("exits", ([
                "north"    : __DIR__"yongquan",
                "westdown" : __DIR__"shulin",
	]));
	set("objects", ([
                "/clone/quarry/hou" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

