#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǵ����ԱߵĲ�����Ҳ�ǽӴ���Ҫ���˵ĵط�������
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ������ɽʯ
���辰��ǽ���Ϲ���һЩ�ֻ���
LONG);
        set("exits", ([
                "east" : __DIR__"guozhendian",
                "west" : __DIR__"huizhentang",
                "north" : __DIR__"shiweishi",
                "south" : __DIR__"datang2",
        ]));
        set("objects", ([
                CLASS_D("quanzhen") + "/li" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
