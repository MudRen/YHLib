#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
����һ����ԭ������֮����̵����������������ɽ����
����������º�����һ���������������ԭ��������ͨ������
������һ����ɳ�ѻ��γɵ�ɽ(mount)��
LONG );

        set("exits", ([
                "southeast" : __DIR__"silk2",
		"west" : __DIR__"silk4",
        ]));

        set("objects", ([
                "/d/hangzhou/honghua/huo" :1,
        ]));

        set("item_desc", ([
                "mount" : HIY "\n����һ����ɳ�ѻ��γɵ�ɽ��΢�紵����ɳɽ������"
                          "�˵�������\n�㲻������Ȼ�����﷢�����Ե���̾��\n" NOR,
        ]));
        set("outdoors", "xiyu");

        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me;
        me = this_player();

        if (! arg || arg == "" ) return 0;

        if (arg == "mount")
	{
                message("vision", HIY + me->name() + HIY "�ԳԿԳ���ɳɽ����"
                        "ȥ��\n" NOR, environment(me), ({me}));

                me->move("/d/xingxiu/shashan");

                message("vision", HIY + me->name() + HIY "��ɳɽ������������"
                        "ճ��һ��ɳ�ӡ�\n", environment(me), me );
                return 1;
        }
}

