inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ���������������������������ֹ�������ɫ��ʯ
�ӣ����ϱ���ͷ���졣���������ֵ�����֣��ϱ�Զ���м���
��ͯ����ˣ�������Ǹߴ�ľ��ݳ�ǽ��
LONG);
        set("outdoors", "jingzhou");
        set("objects", ([
                "/d/beijing/npc/kid1" : 1,
        ]));
	set("exits", ([
		"north" : __DIR__"xidajie2",
		"south" : __DIR__"lydao2",
	]));

	setup();
	replace_program(ROOM);
}

