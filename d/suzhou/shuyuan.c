inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλ�Ϸ�����
��̫ʦ���Ͻ�ѧ��������������������ѧ��ѧ����һ�Ź��ⰻ
Ȼ���鰸��������ǰ�棬���ϰ��ż��������˵���װ�鼮��
LONG );
	set("exits", ([
		"east" : __DIR__"nandajie3",
	]));
	set("objects", ([
		__DIR__"npc/jiaoxi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
