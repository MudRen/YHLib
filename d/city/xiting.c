inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ŵ�����������֪�����鷿���鰸�����ҵط���
�������ƵĹż����������ע�����ǽ�Ϲ���һ���ܴ�ĵ�ͼ��
LONG);
	set("item_desc", ([
		"ditu" : "����һ�������������н��ĵ�ͼ�������и�����ɫ��ȦȦ��㡣\n",	
	]));
	set("exits", ([
		"east" : __DIR__"ymzhengting",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

