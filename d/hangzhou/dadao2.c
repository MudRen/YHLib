#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�غ����");
        set("long", @LONG
һ�������Ĵ����ȴ����ϡ�١�ԭ��������·ס�ŵĶ��Ǵ�ٹ�
�ˡ������羰����֮����ȴ�Ե�һƬ��ɪ����������Ϻͱ����졣
LONG);
        set("exits", ([
            "north"     : __DIR__"dadao1",
            "south" : __DIR__"dalu1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}