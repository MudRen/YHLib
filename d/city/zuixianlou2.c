inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ
ϲ��������߳Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�
������վ��¥��������ֻ�����Ŀ�������������һ�غ�ˮ����
�������������ǳ�ɽ���룬��������Կ�������ȫ���İ�¹��
Ժ�ĺ�ͥ��ϲ������ڶ��ߴ��á�
LONG );
	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/guidao" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"zuixianlou",
		"up" : __DIR__"zuixianlou3",
		"east": __DIR__"zxlpath",
	]));
	setup();
	replace_program(ROOM);
}
