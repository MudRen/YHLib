inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
�����ͨ�����չ����������Ĵ��š��������Ҹ���һͷ
ʯ������գ��ߴ��������࣬��๾�צ���񿥷Ƿ����ƺ���ʱ
Ҫ�ڿն�ȥ��
LONG);
        set("outdoors", "lingjiu");
        set("exits", ([
                "north" : __DIR__"dating",
                "south" : __DIR__"dadao2",
        ]));
        set("objects",([
                CLASS_D("lingjiu") + "/meijian" : 1,
                CLASS_D("lingjiu") + "/lanjian" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object guarder;

        if (dir != "north")
                return 1;

        if (objectp(guarder = present("mei jian", environment(me))))
                return guarder->permit_pass(me, dir);

        if (objectp(guarder = present("lan jian", environment(me))))
                return guarder->permit_pass(me, dir);

        return 1;
}
