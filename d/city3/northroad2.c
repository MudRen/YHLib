inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ������ֺ�ᶫ�������򱱱ߣ��ǳ��ǵı��š���
�� "������" �����ɽ�����Ǵ������ȥ������ص���������
��ȴ�������Ҵң�С�������޲��������伣����Ϊ�ϱ�һ��
��ɫ����Ľ��������������������ŷ�ɫ��Ĵ������š�
LONG);
        set("outdoors", "chengdu");
	set("exits", ([
	    "east"   : __DIR__"northroad3",
	    "west"   : __DIR__"northroad1",
	    "south"  : __DIR__"tanggate",
	    "north"  : __DIR__"northgate",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();
	if (dir == "south")
	return notify_fail("��һ̧�㣬���ֵ����ж���æ�����˻ء�\n");
	else  return 1;
}
