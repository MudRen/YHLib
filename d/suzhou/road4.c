inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������
������ҴҶ��������������һЩС��̯���ƺ���һ�����С�
����������ݳ��ˡ�������ͨ��ɽ�¡�
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"north" : __DIR__"hanshansi",
		"east"  : __DIR__"road3",
		"west"  : "/d/zhongzhou/dongmeng",
	]));
	setup();
}
