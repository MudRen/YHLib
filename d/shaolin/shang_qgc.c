inherit ROOM;

void create()
{
	set("short", "ǰ�㳡");
	set("long", @LONG
�������̼ұ��ڵ�һ���㳡�������㳡��ɳʯ�������ɣ���
���ĸɾ����㳡�ı�����һ����ʯС��������ͨ���������̼ұ�
�����ڡ�
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_xiaojin1",
		"south"  : __DIR__"shang_men",
		"west"  : __DIR__"shang_lianwuw",
		"east"  : __DIR__"shang_lianwue",
	]));
        set("objects", ([
                __DIR__"npc/shang2" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
