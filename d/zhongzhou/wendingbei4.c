inherit ROOM;

void create()
{
	set("short", "�Ķ�����");
	set("long", @LONG
�������ݳ��Ķ����֣����������ݱ������Ѳ�Զ��������
������û������Ӱ���ֵ��Ķ�����һ����լ��Ժ���ſڹ��ŵ�
���Ϻ�Ȼ�������ׯ�������֡�������һ������ƽ����
LONG);
	set("exits", ([
  		"south" : __DIR__"wendingbei3",
  		"east"  : __DIR__"miaojia_men",
  		"west"  : __DIR__"congwu",
  		"north" : __DIR__"beimen",
	]));

	set("no_clean_up", 0);
	set("outdoors", "zhongzhou");
	set("objects", ([
  		"/d/beijing/npc/tangzi" : 1,
	]));

	setup();
	replace_program(ROOM);
}
