// Room: /d/mingjiao/huangtulu2.c
// Date: Java 97/04/9

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������ï�������е�һ������С·�����ּ��ܣ����涼��������
�ĸо����װ׵ı�ѩ����ҫ�ۡ�������һ��ɽ����Σ��֮�ߣ�ǰ����
һ��С����
LONG );
	set("exits", ([
		"east"  : __DIR__"huangtulu1",
		"enter" : __DIR__"shandong",
	]));
	set("outdoors", "mingjiao");
        set("objects", ([
                __DIR__"npc/menwei1" : 4,
        ])); 
	setup();
}

int valid_leave(object me, string dir)
{
        me = this_player();

        if (dir == "enter" && 
            objectp(present("da han", environment(me))))
         	return notify_fail("����ס��˵���˴�������"
				   "�صأ�ֻ�н����������ڡ�\n");
        return ::valid_leave(me, dir);
}
