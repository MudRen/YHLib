inherit ROOM;

void create()
{
	set("short", "ʯ·");
        set("long", @long
����һ���̵�ʮ��ƽ����ʯ��·��·�汻��ɨ�øɸɾ�����
�����ȥ�Ǹ���Բ�����������㣬�����Ǿ����ң����洫��
Щ������������������鷿�ˡ�
long);
        set("exits",([
		"north" : __DIR__"qianting",
		"south" : __DIR__"huayuan1",
		"west" : __DIR__"jingxiushi",
		"east" : __DIR__"shufang",
	]));

	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
