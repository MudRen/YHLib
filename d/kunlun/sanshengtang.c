inherit ROOM;

void create()
{
        set("short", "��ʥ��");
        set("long", @long
����ɽ��ʥ���ˡ�������ʥ�������������ԭΪ��������
�ԣ�������������������������׳������Զ������������
�����ɾ������£��Ӵ���·����Ӣ�۵ĵط�����������ʥ��Ҳ
ֻ�����ٰ��������ˡ�
long);
        set("exits",([
                "west" : __DIR__"jiuqulang1",
                "northdown" : __DIR__"lang2",
                "north" : __DIR__"liangong",
                "northwest" : __DIR__"jiuqulang2",
        ]));

        set("objects",([
                CLASS_D("kunlun") + "/banshuxian" : 1,
        ]));

        set("valid_startroom", 1);
        setup();
        "/clone/board/kunlun_b"->foo();
}

int valid_leave(object me, string dir)
{
        object ban;

        if (dir != "north" ||
            ! objectp(ban = present("ban shuxian", this_object())))
                return ::valid_leave(me, dir);

        return ban->permit_pass(me, dir);
}

