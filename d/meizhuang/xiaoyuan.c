inherit ROOM;

void create()
{
        set("short", "����СԺ");
        set("long", @LONG
�����¶��ţ�����һ���������ǳ���ͨ��СС��Ժ�䣬��������
�橣���������ʯ��������̦���Ե�ƽ���������С�����ͨ������ʯ
��֮ǰ����ǰ�ݺ��߰������ز�ø�ͦ���ڵ��������������ġ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"yuedong",
                "enter" : __DIR__"xiaowu",
        ]));

        set("objects", ([
                __DIR__"npc/shi" : 1,
        ]));

        set("outdoors", "meizhuang");

        setup();
}

int valid_leave(object me, string dir)
{
        object shi;

        if (dir != "enter" ||
            ! objectp(shi = present("shi lingwei", this_object())))
                return ::valid_leave(me, dir);

        return shi->permit_pass(me, dir);
}
