inherit ROOM;

void create()
{
	set("short", "��ʯ");
	set("long", @LONG
��ɽ������һ���ʯ����ʯ�������������ʯ���ഫ����
��ɮ�����ڴ���ʯ�ľ���������ʯ��Ϣ����ʯ�����������ģ�
����ơ�����ʯ���������С�������Ц��Ե���Ĵ�˵��������
��ԧ��ʯ��������ʯ��ʵϵ��ӿɽ���
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"east"     : __DIR__"shijianshi",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	setup();
	replace_program(ROOM);
}

