inherit ROOM;

void create()
{
	set("short", "���Ŵ���");
	set("long", @LONG
��������������µ����ŵĴ��š����Ž���ʮ��Ρ�룬��
ǽ�����µ�ͭ�����Ž����رգ��������ŵ���һ���ſ������
���ƿ����ǲ��ý�ȥ�ˡ�
LONG);
        set("outdoors", "chengdu");
	set("no_fight",1);
	set("exits", ([
		"north"  : __DIR__"northroad2",
	]));
	set("objects", ([
		__DIR__"npc/tangdun" : 1,
	]));
	setup();
        replace_program(ROOM);
}
