inherit ROOM;

void create()
{
	set("short", "������Ժɽ��");
	set("long", @LONG
��ɽ�������ų� "����" �������Ǳ��Ƿ�̴��£�������
��ȴ�ѳ�Ϊ��ɽ�������˵�ס�������Ͽ��Ե������̨��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao6",
		"northup"   : __DIR__"chanyuan",
		"westup"    : __DIR__"fengchantai",
	]));

	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

