#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
������һ��Ƨ��������С·�ϣ���������ɭɭ�����֡�ֻ
������ǰ�󣬵�����������ǵص������֡���ʮ�ɸߵĴ�����
����һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ��������ڵ�
˿��Ҳ�ޡ���˵���ﾭ�������˳�û�����ɾ�����
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "south"     : __DIR__"tufeiwo2",
                "northdown" : __DIR__"wdroad10",
        ]));
        set("objects", ([
                __DIR__"npc/tufei2" : 2
        ]));
        setup();
        replace_program(ROOM);
}
