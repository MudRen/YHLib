//tianweitang.c
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��΢��");
        set("long", @LONG
����������̵���΢�ã�������������Զ������Ұ�������ǰ�üӥ
���Ķ��Ӻͽ������޼ɵľ˾ˡ����ڳ��������ݻ�����Ȼ������������
�����ڽ��������������Ǹ�ִ���У��ƺ������ܶ����ʿ��
LONG );
        set("exits", ([
                "east"      : __DIR__"tianshitang",
                "west"      : __DIR__"ziweitang",
                "southdown" : __DIR__"zhandao2",
                "north"     : __DIR__"square",
        ]));
        set("objects",([
             __DIR__"npc/yinyewang":1,
             __DIR__"npc/yinwufu":1,
        ]));
        setup();

        replace_program(ROOM);
}

