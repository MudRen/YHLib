inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
�̼ұ��㳡�����һ����ʯ������С������������ǰ���̼�
���Ĵ������ڡ���ʱ���̼ұ������˹����ڴˡ�
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_xiaojin2",
		"south"  : __DIR__"shang_qgc",
	]));
	setup();
	replace_program(ROOM);
}
