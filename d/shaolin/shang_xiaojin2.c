inherit ROOM;

void create()
{
	set("short", "��ʯС��");
	set("long", @LONG
�̼ұ��㳡�����һ����ʯ������С������������ǰ���̼�
���Ĵ������ڡ���ʱ���̼ұ������˹����ڴˡ�
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_dating",
		"south"  : __DIR__"shang_xiaojin1",
	]));
        set("objects", ([
                __DIR__"npc/shang1" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
