//Room: huiwenge.c

#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short", "���ĸ�");
        set ("long", 
"����һ����֡����������һ���ŵ�����������������ط���\n"
"һЩ���ᣬ���ڻ������ż��軨���ݲݣ�������䣬�������£�������\n"
"����Ŀ�������Ϳ��Կ���һ�����:\n"
HIB"         ��ɽ�о���Ϊ·\n"NOR
HIB"         ѧ�����Ŀ�����\n\n"NOR
        );
        set("exits", 
        ([ //sizeof() == 1
                "west" : __DIR__"yongtai-dadao3",
        ]));
        set("objects", 
        ([ //sizeof() == 1
        	__DIR__"npc/shuchi" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
