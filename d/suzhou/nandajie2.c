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
		"east"  : __DIR__"tingyu",
		"west"  : __DIR__"liuyuan",
		"north" : __DIR__"nandajie3",
		"south" : __DIR__"nanmen",
	]));
        set("max_room", 5);
	setup();
}

