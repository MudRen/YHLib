inherit ROOM;

void create()
{
	set("short", "��Ĺ�ڲ�");
	set("long", @LONG
�����ż�����ǰ�ߣ�Զ���ƺ�������֨֨�Ľ��������в�
�Ǻ����С����ڹ���̫����ֻ�ܿ���ģģ�����Ķ�����
LONG);  
	set("exits", ([
		"south" : __DIR__"sec2",
		"north" : __DIR__"tomb"
	]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
