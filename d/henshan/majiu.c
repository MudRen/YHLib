#include <room.h>
inherit TRANS_ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���Ǻ������ϵ���ǣ����깩Ӧ���ʲ��ϡ�����������ϡ
��������Ҳ���١���������Գ����������ĳ��У��������
�µ���ľ���϶���һ����ľ��(paizi)�� ����жѷ������Ѳ�
�ϣ�������һ����ۡ�
LONG);
        set("outdoors", "henshan");
        set("no_fight", 1);

        set("objects", ([
                "/clone/horse/zaohongma": 1,
                "/clone/horse/huangbiaoma": 1,
                "/clone/horse/ziliuma": 1,
                "/clone/npc/mafu": 1,
        ]));

        set("exits",([
               "north" : __DIR__"hengyang11",
                "up"   : "/clone/shop/hengyang_shop",
        ]));

        setup();
        replace_program(TRANS_ROOM);
}

