inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ϡ�Ժ����һ����ˮ��������ʯ��ʯ�ߣ���
Ȼ�̾ᡣ�������ʯ����Ѫ����Ȼ�������������ڴ������С�
LONG);
	set("exits", ([
	        "south"  : __DIR__"street1",
	]));
	setup();
	replace_program(ROOM);
}

