#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ܽ�ط�");
        set("long",  @LONG
ܽ�ط��Ǻ�ɽ���֮һ����˵ܽ�ط����и�ɽ�������г�
����ܽ�ػ������겻л��ܽ�ط�Ҳ��˵����������˴�������
�ģ���ľ���̣����ﲻ��ף�ڷ�ߣ���ů���ˣ�ʵ���Ǹ��˼�
�ɾ���
LONG);

        set("exits", ([
                "southeast"   : __DIR__"shanlu13",
        ]));

        set("objects", ([
                CLASS_D("henshan") + "/liu" : 1,
                CLASS_D("riyue") + "/qu" : 1,
        ]));    

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

