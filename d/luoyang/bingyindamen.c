inherit ROOM;

void create()
{
	set("short", "��Ӫ����");
	set("long", @LONG
����վ�ڱ�Ӫ���ſڣ������һ�ż�ª��Ӫ�������Կ��������Ʒ���
�ٱ����ڲ�������ʱ�ش����ź������ϰ����ǲ������ڴ˹ۿ��ģ������
�Ͽ��߿���
LONG);
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("exits", ([
  		"north" : __DIR__"bingyin",
  		"south" : __DIR__"wroad4",
	]));
        set("objects", ([
                "/d/kaifeng/npc/guanbing" : 2,
        ]));
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (! wizardp(me) && objectp(present("guan bing", environment(me))) && 
                dir == "north")
                return notify_fail("�ٱ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}