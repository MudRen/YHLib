#include <room.h>
inherit TRANS_ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
��������������Ψһһ�ҳ����С���ɻ�Ǯ����������
���ط�ȥ���ܽ�Լ����������������Ϊ�����ˡ�������������
֯�����Ĵ��Ѽ����ǲ��ϣ���������Ӧ������ṩ�Ƴ�����
�͸��ַ��ǲ��ϡ������¶��ſ�ľ��(paizi)��
LONG);
        set("outdoors", "xiangyang");
        set("exits", ([
                "south"  : __DIR__"northroad2",
                "up"     : "/clone/shop/xiangyang_shop",
        ]));
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
