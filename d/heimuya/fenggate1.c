#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ����Ϊ�������ּ�С���ϣ���������ɭɭ������
�֡����ϲ�Զ��ɵ�����������µ�һ���÷����õĴ��ţ���
�ﲻʱ�з����õĵ����߶���
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
                "north" : __DIR__"linjxd2",
                "south" : __DIR__"fenggate",
        ]));
        set("objects", ([
                __DIR__"npc/dizi3" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
