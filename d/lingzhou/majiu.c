#include <room.h>
inherit TRANS_ROOM;

void create()
{
        set("short","���");
        set("long",@LONG
���ǳ������ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�
����ֻҪס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬
��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�
������һ����ۡ���������µ���ľ���϶���һ����ľ��(paizi)��
LONG);
        set("outdoors", "lingzhou");
        set("exits",([
                "west"      : __DIR__"chema",
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
