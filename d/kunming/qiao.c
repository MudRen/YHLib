#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ľ��");
        set("long", @LONG
������һ����ľ�ţ�Ҳ��֪��ʲôʱ��������ģ�������
��ҡҡ�λεģ�����Σ�ա������Ҫ���ӵĻ�����ֻ�������
����������ȥ��ֻ������������һ����ȥ���϶�û����
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"qiao2", 
                "north"  :__DIR__"road5",
        ]));
        setup();
        replace_program(ROOM);
}