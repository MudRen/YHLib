#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һ���ɾ������ȣ������濴ȥ���������͵���԰��
�ķ羰��ֻ�����ּ�ɽ��ʯ���滨��ݣ��������֮���ɡ���
����ƽ�����ȥ���鷿���ſ��м����ױ��ڰ��ء�
LONG);
        set("exits", ([
                "west"   :__DIR__"shufan",
                "east"   :__DIR__"xizoulang"
        ]));

        set("objects",([
                __DIR__"npc/qinbing" : 2,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" &&
           objectp(present("qin bing", environment(me))))
                return notify_fail(CYN "�ױ���ס��˵������ү�Ը��ˣ�û����"
                                   "�������κ��˲��ý�����š�\n" NOR);                
        return ::valid_leave(me, dir);
}
