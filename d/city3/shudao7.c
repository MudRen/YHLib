#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ջ��");
        set("long", @LONG
�Թ����ƣ�����ѣ����������죬�غ����޹ִ�ʫ�����
���д��·�����������ν�����ޱȣ�һ�������ϵĽ�ˮ��һ
�����絶�а���ͱڣ���������·���ߣ�ֻ���ͱ�����һЩʯ
�ѣ������ʵǶ��ϣ��򶫣�ȴ��ҡҡ�λε�ջ���� 
LONG);
        set("exits", ([
                "east" : __DIR__"shudao6",
                "westup" : __DIR__"shudao8",
        ]));
        set("objects", ([
                "/d/beijing/npc/tangzi" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

