inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
���߽������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ������
������һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����
Ҫ����������ƹʺ�ҥ�ԣ������Ǹ������ڡ�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));
	setup();
	replace_program(ROOM);
	"/clone/board/player_b"->foo();
}
