inherit ROOM;

void create()
{
	set("short", "��ʥ��");
	set("long", @LONG
�ഫ����ү�Ӿ�������������ܲ���������ϯ֮λ���ܲ�
˵����˭���ܵ����˭��Ϊ�󡣹ع���Ӧ�󣬴��ܲ��ܵ���
�ڴ�У���ռ�ҵ���긡��ֱܲ�����˵������ƫҪ֮�ˣ�����
��һվ���ع�Ҳ�͵�ǰ��ȥ�ˡ���Щ�����ҿ��������
�����ƣ����겻�ϣ�������������ﲻ����Ҳ��֪�ض�ү�ڵ�
���������Ƕ�Ӣ�۵����
LONG);
	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" :__DIR__"houdian",
	]));
        set("objects", ([
                "/d/beijing/npc/xiangke" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

