#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "��¥" );
        set("long", @LONG
����һ����¥���м�������һ���ӣ�����̵������ġ���
�ִ�����������������ô�ߣ�������������ǧ���֪������
����ô����ȥ�ģ��ӵ���������һ��ľ�����������������õġ� 
LONG);
        
        set("exits", ([
                "down"    :__DIR__"jinrilou",
        ]));
        set("objects", ([
                "/d/hangzhou/npc/seng" : 1,
        ]));                       

        setup();
        replace_program(ROOM);       
}