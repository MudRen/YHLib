inherit ROOM;

void create()
{
	set("short", "��ڤ��");
	set("long", @LONG
���������ڤ���ˣ�ֻ�����ܰ�ѩ���ǣ�Զ��Ⱥɽȴ�Ǵ�
��һƬ����Ŀ������������Զ����ڤ���д������ˣ�ż�к���
����֮��С�������Ծ������������û��Ⱥɽ֮�䡣
LONG );
	set("exits", ([
		"southdown"    : __DIR__"shanlu4",
	]));

        set("objects", ([
                "/kungfu/class/xuanming/bai" : 1,
        ]));

	set("outdoors", "xuanming");
	setup();
	replace_program(ROOM);
}
