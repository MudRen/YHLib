inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
���Ǻ�������һ��ƫƧ��С�ƽʱ������������ֻ����
��С������������֪��ͨ��δ���
LONG);
        set("outdoors", "henshan");

	set("exits", ([
	        "south"  : __DIR__"xiaoxiang2",
	        "north"  : __DIR__"hengyang2",
	]));

	setup();
	replace_program(ROOM);
}

