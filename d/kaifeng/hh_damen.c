inherit ROOM;

void create()
{
        set("short", "�컨�����");
        set("long", @LONG
������Ǻ컨���ܶ������ˣ�һ����ǽ���ߵĴ�լӳ����
�����ſڷ�����ͷʯʨ�ӣ��������ϡ������ŵ���í������
���⣬��ǰվ�ż����컨��ĵ��ӣ�������������ǰ���Ŷ�
��컨���������ࡣ��ϸ�Ĺ۲���ÿһ���������ˡ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"hh_lianwu1",
  		"south" : __DIR__"hh_qguangchang",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/yang" : 1,
                CLASS_D("honghua") + "/jiang" : 1,
                __DIR__"npc/honghua2" : 4,
        ]));
        set("outdoors", "honghua");

        setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir != "north" ||
            ! objectp(guard = present("yang chengxie", this_object())) &&
            ! objectp(guard = present("jiang sigen", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}
