inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·�Զ����������ƽ�ƽ�������м�ͷ��ӥ�ڵ͵͵�����
���裬�·����˵��������·������Сʯ�ӣ������ԵĹ�
ľԽ��Խ�٣������ƻ����������Ҹ��ط���Ϣһ�¡�
LONG);
        set("outdoors", "gaochang");
	set("exits", ([
  		"north" : "/d/gaochang/shulin1",
  		"westdown" : __DIR__"shamo1",
  		"eastdown" : __DIR__"caoyuan6",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (! userp(me) && dir == "north")
                return notify_fail("�߲��ԌmNPC�����ֹ��\n");
        return ::valid_leave(me, dir);
}
