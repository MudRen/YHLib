inherit ROOM;

void create()
{
	set("short", "��Ĺ�ڲ�");
	set("long", @LONG
�����ż�����ǰ�ߣ�Զ���ƺ�������֨֨�Ľ��������в�
�Ǻ����С����ڹ���̫����ֻ�ܿ���ģģ�����Ķ�����
LONG);
	set("exits", ([
		"south" : __DIR__"sec3",
		"north" : __DIR__"sec1"
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
