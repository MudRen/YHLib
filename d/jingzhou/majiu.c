#include <room.h>
inherit TRANS_ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
���ǿ͵�����ǣ����깩Ӧ�����ʵĲ��ϡ����ݳ����
���ӣ�����ǻ����ǣ����Ǻ����տ���������ι�����㣬��
ϴˢ�ø�Ǭ������һֱ�ź򵽿�����·����������µ���ľ��
�϶���һ����ľ�� (paizi)������жѷ������Ѳ��ϡ�
LONG);
        set("outdoors", "jinzhou");
        set("no_fight", 1);
        set("objects", ([
              "/clone/horse/zaohongma": 1,
              "/clone/horse/huangbiaoma": 1,
              "/clone/horse/ziliuma": 1,
              "/clone/npc/mafu": 1,
        ]));
        set("exits",([
                "west" : __DIR__"kedian",
                "up"   : "/clone/shop/jingzhou_shop",
        ]));
        setup();
        replace_program(TRANS_ROOM);
}
