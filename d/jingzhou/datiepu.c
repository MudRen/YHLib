inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯�������
�յ�һƬͨ�죬��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ���������
����δ�깤�Ĳ˵���������������ذ�ס����׵��һλ����
��ͷ�󺹻�����������ר����־���ڴ�����
LONG);
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
        set("objects", ([
                 __DIR__"npc/smith": 1,
	]));
	setup();
	replace_program(ROOM);
}

