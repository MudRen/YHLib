inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
���뽭�����ǲ�����ɽ���������Ĺȣ����ղ�����⡣��
��ɽ�ж������޳�û�޳�����·������һ��������ŵ�һ����
���˱Ƕ�����
LONG);
	set("exits", ([
		"northwest" : "/d/henshan/hsroad2",
		"eastup"    : __DIR__"fzroad6",
	]));
        set("objects", ([
		"/clone/quarry/laohu" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}

