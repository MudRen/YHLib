inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ����ϳ�
�ţ�����ͨ�������ģ�������һ�ҹ˿��ڶ�Ĳ�ݣ����̾���
��ʿ������̸��˵�ء�����һ�������¥������������Ц����
������������������Ժ��
LONG );
        set("outdoors", "city");
	set("exits", ([
		"east"  : __DIR__"lichunyuan",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"chaguan",
		"north" : __DIR__"nandajie1",
	]));
        set("objects", ([
                CLASS_D("shaolin") + "/tuoboseng" : 1,
        ]));
	setup();
        replace_program(ROOM);
}
