#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "�᷿");
        set("long", @LONG
����һ����������᷿�����浽�����Ǹ��ִ��СС�����ӡ���
��֮��Ķ�������ʱ���ܿ����ж��������������ϴ��������Ĵ����ߡ�
һ�����Ű��ӵİ׺�������������æ���ҵĸ������ǰ���ιʳ��æ��
��æ���ҡ�
LONG);
        set("exits", ([
                "east" : __DIR__"nanyuan",
        ]));
        set("objects", ([
                __DIR__"npc/oldman": 1,
        ]));
        setup();
}
