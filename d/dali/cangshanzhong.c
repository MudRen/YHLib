inherit ROOM;

void create()
{
	set("short","��ɽ�в�");
	set("long",@LONG
�������ڲ�ɽ�в���ɽ�ߣ��˼���μ��գ�����ɽ����
�ƣ��м�һ����᫲�ƽ��ɽ·��·����Զһ������Ա���ƫ
��������������¡¡ˮ��ңң���ţ�������گ������ˮ����
·�������������������ıؾ�֮;��ʱ�п��̹������ɴ�
���ϴ�Խ��ɽ�ɵ��¹سǣ����治Զ���ǳ���ɽ��ɽ�ڡ�
LONG);
	set("outdoors", "dali");
	set("exits", ([
                "north"     : __DIR__"jianchuan",
                "southwest" : __DIR__"cangshanlu1",
                "southeast" : __DIR__"xiaguan",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

