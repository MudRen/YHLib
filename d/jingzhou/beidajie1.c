inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ
�Ҵң�����˶����ϱ���ȥ��������һ�����ֵĹ㳡��������
һ��������¡�Ŀ�ջ�����Ը��ص����ǽ���������������һ��
Ǯׯ�������������������Ľ���������
LONG);
        set("outdoors", "jingzhou");

	set("exits", ([
		"east" : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west" : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));
        set("objects", ([
                "/d/beijing/npc/girl1" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

