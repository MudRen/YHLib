#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ�޷�");
        set("long",  @LONG
ܽ�ط��Ǻ�ɽ���֮һ��ÿ�������ʱ����ˮ���ڷ���
����ʯ�ϣ������޴�Ļ���������������������Ժ�еĶ�������
���Ը÷��ɴ˶�������ɽ�ɵ�ʯ�޽���Ҳ�ɴ˶���
LONG);

        set("exits", ([
                "westdown"   : __DIR__"liuyunping",
        ]));

        set("objects", ([
		__DIR__"npc/dizi1" : 2,
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

