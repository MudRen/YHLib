inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡��
�������Ų��ٲݰС�ʮ����ɮ��������ϰ���ա�������һ����
ɮ����
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang3",
		"west" : __DIR__"wuchang",
		"east" : __DIR__"luohan5",
		"north" : __DIR__"zoulang7",
	]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}

