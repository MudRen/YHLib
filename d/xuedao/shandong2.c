inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
ɽ�����ѩ��£�ɼ���ѩ�ѣ�����ʱ������ɨ����ѩ����
ǰ����ͱ�������ԼԼ��һ��ɽ�����ϱ����Զ����±ڣ�����
����һ���ͱڣ��ǳ���Ҫ��
LONG);
        set("exits", ([
                "enter" : __DIR__"shandong3",
                "west"  : __DIR__"sroad9",
        ]));
        set("objects", ([
                CLASS_D("xuedao") + "/baoxiang" : 1,
        ]));
        set("outdoors", "xuedao");
        setup();
}

int valid_leave(object me, string dir)
{
        object guarder;

        if (dir == "west" ||
            ! objectp(guarder = present("bao xiang", this_object())) ||
            ! living(guarder))
                return ::valid_leave(me, dir);

        return guarder->permit_pass(me, dir);
}
