inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
�������������¹󸾳���֮��������Ҳ��������Ҳң�֬
�ۺ�ɡ���Ϊ��������ʱ�У�һֱ�����������Ե�װ�硣����
�Ǹ��ܿ��˵�СŮ����������һ������ʱ���������������Ů
�˼���һ�𣬻�������������
LONG );
	set("exits", ([
		"down" : __DIR__"zahuopu",
	]));
	set("objects", ([
		__DIR__"npc/zeng": 1,
	]));
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}

