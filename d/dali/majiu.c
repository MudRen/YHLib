#include <room.h>
inherit TRANS_ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
���Ǿ�Ӫ���ϵ���ǣ����깩Ӧ���ʲ��ϡ��˵���紾��
����ֻҪ������������Ǿͻ����ǣ����Ǻ����տ���������
ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·����
�������µ���ľ���϶��ſ���ľ��(paizi)��
LONG);
        set("exits",([
                "east" : __DIR__"bingying",
                "up"   : "/clone/shop/dali_shop",
        ]));

        set("outdoors", "dali");
        set("no_fight", 1);
        set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
        ]));
        setup();
        replace_program(TRANS_ROOM);
}
