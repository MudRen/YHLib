inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������̼ұ��ĺ������ڣ������൱�Ŀ����������ܵ�ǽ
���������˸������˵��漣��
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_zoulang1",
		"south"  : __DIR__"shang_dating",
		"west"  : __DIR__"shang_xiangw",
		"east"  : __DIR__"shang_xiange",
	]));
	setup();
	replace_program(ROOM);
}
