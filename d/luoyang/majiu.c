#include <room.h>
inherit TRANS_ROOM;

void create()
{
        set("short","���");
        set("long",@LONG
���ǿ͵�����ǣ����깩Ӧ���ʲ��ϡ����������¹ų�
��ʷ�ƾá���紾�ӣ�����ǻ����ǣ����Ǻ����տ�������
��ι�����㣬��ϴˢ�ø�Ǭ��������������µ���ľ���϶���
����ľ�� (paizi)������жѷ������Ѳ��ϡ�
LONG);
        set("outdoors", "luoyang");
        set("no_fight", 1);
        set("objects", ([
              "/clone/horse/zaohongma": 1,
              "/clone/horse/huangbiaoma": 1,
              "/clone/horse/ziliuma": 1,
              "/clone/npc/mafu": 1,
        ]));
        set("exits",([
                "west" : __DIR__"kezhan",
                "up"   : "/clone/shop/luoyang_shop",
        ]));
        setup();
        replace_program(TRANS_ROOM);
}
