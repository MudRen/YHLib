#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�򶾿���");
        set("long", @LONG
�������嶾����������ĵط���ɽ������һ����Ȼ��ʯ��������
������Ŀ��������һ��ɽ�紵�������ŵ�һ����ζ����һ��������
�ڵĿ����ϸ������ڶ��ߴ�� 
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"wandu2",
                "north" : __DIR__"wdsl3",
        ]));
        set("objects", ([
                CLASS_D("wudu") + "/hehongyao" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "south")
        {
                if (me->query("family/master_name") != "������"
                & objectp(present("he hongyao", environment(me))))
                        return notify_fail(CYN "�κ�ҩ����һ�Σ���ס��ȵ���û��"
                                           "����׼��˭Ҳ���ý��뱾��ʥ�ء�\n"
                                           NOR);
        }
        return ::valid_leave(me, dir);
}
