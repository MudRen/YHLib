inherit ROOM;

void create()
{
	set("short", "��Ȫ��");
	set("long", @LONG
�㿴��һ����Ȫ�����������ǰ����������ð��������Ȫ
ˮ����Ȫ�䲻�󣬵�����ʹ���뵽��ȥ��һ�ݣ���˵��������
���β���
LONG);
        set("outdoors", "jingzhou");
	set("exits", ([
		"northup" : __DIR__"lydao2",
		"eastup" : __DIR__"lydao3",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

