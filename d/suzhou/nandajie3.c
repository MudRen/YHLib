inherit BUILD_ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣����ͨ����
�ϴ�ֵ����ĵضΣ�����������������������԰�������棬��
���ݳǵ��ϳ��š���ν�������ã������պ������Ե�ȷ����
�������������������˼丣�ء�
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"east"  : __DIR__"chaguan",
		"west"  : __DIR__"shuyuan",
		"north" : __DIR__"nandajie1",
		"south" : __DIR__"nandajie2",
	]));
        set("max_room", 5);
	setup();
}

