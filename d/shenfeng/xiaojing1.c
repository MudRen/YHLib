inherit ROOM;

#include "langqun.h"

void create()
{
        set("short", "С��");
        set("long", @LONG
������·��֪���ж������������ߣ���Щ�ط����ݱ��˻�
�ߣ���Щ�ط���ȫ��ɳ����������������һ��ļž���ֻ�з�
�������ҵ�ɳɳ֮����ż��һ�����Ǻ������ȷ�Ʈ�����ʡ�
LONG);
        set("exits", ([ 
                "south" : __DIR__"bridge2",
                "north" : __DIR__"shibi",
        ]));

        set("quarrys", ([
                "lang2" : 200000,
                "lang"  : 100000,
        ]));

        setup();
}
