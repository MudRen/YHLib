inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
����һ�Ҽ�Ϊ��ͨ�ľ�¥��ƽ�������Щ�׾ƣ����ӣ���
������������˶��������㶫�������ˣ�Ҳ��Щ�˽е㻨��
�ף��е���ţ�����������ѵġ�
LONG);
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));
	setup();
	replace_program(ROOM);
}

