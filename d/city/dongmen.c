inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕ����ţ��������Ϸ����š����š�����������֣���
ǽ�����ż��Źٸ���ʾ(gaoshi)���ٱ��Ǿ����ע���Ź�����
�ˣ������С��Ϊ�һ����ֱ����ʯ���������������졣
�����ǽ��⣬��Լ�ɼ�һƬһ���޼ʵ����֣�����Ī�⡣����
�ǳ��������һƬïʢ�������֡�
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/taishan/yidao",
		"north" : __DIR__"ml1",
		"south" : __DIR__"jiaowai1",
		"west" : __DIR__"dongdajie2",
	]));
	set("objects", ([
                "/d/beijing/npc/ducha" : 1,
		__DIR__"npc/bing" : 4,
                "/clone/npc/walker" : 1,
	]));

	setup();
        replace_program(ROOM);
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}

