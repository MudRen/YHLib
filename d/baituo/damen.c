inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������µİ���ɽׯ�Ĵ��š�ֻ���������ϵ�����
���ۼ���أ���֪�����Ŷ����ܹ��ɽ�����Ѫ�����Գ�ׯ��
�ĸ������Թ���ǰ���Ҹ�����һֻ����ׯ�ϵ�ʯʨ�ӡ�
LONG);
        set("outdoors", "baituo");

        set("exits", ([
                "north" : __DIR__"yuanzi",
                "southdown" : __DIR__"shijie",
        ]));

        set("objects", ([
                __DIR__"npc/menwei" : 2,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        object guarder;

        if (objectp(guarder = present("men wei", this_object()))
           && dir == "north")
                return guarder->permit_pass(me, dir);

        return 1;
}
