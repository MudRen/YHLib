inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ컨���ܶ��ڵ������������൱�Ŀ�����������
��ǽ���������˸������˵��漣��ֻ��һλ��ʮ����ĺ���վ
�����У��������ͣ�������Ȼ�𾴡����Ա�վ�ż����컨���
�ڣ�������������ǰ����һ���컨���������ࡣ
LONG);
        set("exits", ([
  		"west" : __DIR__"hh_zoulang4",
  		"east" : __DIR__"hh_zoulang5",
  		"north" : __DIR__"hh_houting",
  		"south" : __DIR__"hh_qianting",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/wen" : 1,
                __DIR__"npc/honghua1" : 4,
        ]));
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
        "/clone/board/honghua_b"->foo();
}

int valid_leave(object me, string dir)
{
        object wen;

        if (dir != "east" &&
            dir != "west" &&
            dir != "north" ||
            ! objectp(wen = present("wen tailai", this_object())))
                return ::valid_leave(me, dir);

        return wen->permit_pass(me, dir);
}
