#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������ٸг��ȸ�ʢ��ֻ�������Ǽ����������ʯ�ҡ�
ʯ���������һ��һ�˶�ߵĻ�¯(huo lu)�������ֹ����ڰ�
�Ѳ�̿������������ಲ������ֻ��һ��ţͷ�̿㣬ȫ���
���졣
LONG);
        set("exits", ([
               "south"   : __DIR__"shufang",
               "west"    : __DIR__"zhulin3",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
