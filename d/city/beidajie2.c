inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣����������
������ͨ����⡣�ֵ��ϱ��Եúܷ�æ��������һ������Ĵ�
¥�󣬹��š�̫���ŷ硹���������Ŷ�������һ�����ҡ�����
¥�����ֲ�������������������ѧʿ���ֱʡ�������������
���㴹�����Ρ�������һ�����ӵ����������ƣ��Ǿ�����
��ѧ��֮������ͬ�����������ˡ�
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"zuixianlou",
		"south" : __DIR__"beidajie1",
		"west"  : __DIR__"wumiao",
		"north" : __DIR__"beimen",
	]));
	setup();
	replace_program(ROOM);
}

