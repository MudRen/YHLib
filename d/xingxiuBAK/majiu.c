#include <room.h>
inherit TRANS_ROOM;

void create()
{
        set("short","���");
        set("long",@LONG
���Ǳ���С�����ǣ����깩Ӧ���ʲ��ϡ�����ش��Ὦ
������Ӷ��ÿͣ�������Զ�����������ֵܿ���������ǻ��
��ǣ����Ǻ����տ���������ι�����㣬�����������ˬˬֱ
�ź򵽿�����·�����ľ�����ſ���ľ�� (paizi)������ж�
�������Ѳ��ϣ�������һ����ۡ�
LONG);
        set("outdoors", "xingxiu");
        set("exits",([
                "south"      : __DIR__"beijiang",
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
