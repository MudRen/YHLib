#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ɽ��");
        set("long", @LONG
�˴��������(peak)ɽ�ţ���������������ͨ��ѩ�ף�Ө
�ⴿ�������񽳵�ֻҪ�ҵ�СС��һ�������Ȼ�������֮
�����ˣ���֪���ﾹ������һ������ɽ�塣̧ͷ������ֻ����
�����������Ǿ������㲻��������̾����֮�档
LONG);
        set("outdoors", "gaochang");
        set("item_desc", ([
                "peak" : HIW "���͵İ���ɽ���ϲ�������ۼ��������ƺ�"
                         "��������ȥ��\n" NOR,
        ]));

        set("exits", ([
                "south" : __DIR__"pendi",
	]));
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();

        if (! arg || arg != "up")
		return notify_fail("��Ҫ���ĸ���������\n");

        message("vision", HIW "ֻ��" + me->name() + HIW "սս����������"
                          "������ȥ��\n" NOR, environment(me), ({me}));

        me->move(__DIR__"shenfeng");
        tell_object(me, HIW "\n����˺ô󾢣�������������壬�۵���ֱ��"
                          "������\n\n" NOR);
        message("vision", HIW "ֻ��" + me->name() + HIW "�������������"
                          "������\n", environment(me), ({me}));
        return 1;
}
