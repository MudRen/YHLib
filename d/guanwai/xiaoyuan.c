inherit ROOM;

void create()
{
        set("short", "СԺ��");
        set("long", @LONG
����ɽ�����ǰ��һ��СԺ�ӣ�������һ��С�ݣ���Ժ��
��һ���������ڴ�ɨ��
LONG);
        set("exits", ([
                "south" : __DIR__"baihe",
                "north" : __DIR__"xiaowu",
        ]));
        set("objects", ([
                CLASS_D("hu") + "/pingsi" : 1,
        ]));
        set("outdoor", "guanwai");
        setup();
}

int valid_leave(object me, string dir)
{
        object guarder;

        if (objectp(guarder = present("ping si", this_object()))
           && dir == "north")
                return guarder->permit_pass(me, dir);

        return 1;
}
