inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ���������������������������ֹ�������ɫ��ʯ
�ӣ�������ͷ���졣����������ֵ��ϴ���ˡ������м���
С������ˣ����������г��΢�紵����ʹ����ȴ�˽����ϵ���
�����
LONG);
        set("outdoors", "jingzhou");
        set("objects", ([
                "/d/beijing/npc/kid1" : 2,
        ]));
	set("exits", ([
		"eastup" : __DIR__"nandajie2",
		"west" : __DIR__"lydao3",
	]));

	setup();
	replace_program(ROOM);
}

