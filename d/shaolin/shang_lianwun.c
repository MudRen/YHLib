inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�������̼ұ������һ�����䳡�������ĳ�����������ϸϸ
�Ļ����������ʺ����䡣���������Ӳݴ������������Ѿ��ķϺ�
��һ��ʱ���ˡ�
LONG);
	set("exits", ([
		"south"  : __DIR__"shang_houyuan",
	]));
	setup();
	replace_program(ROOM);
}
