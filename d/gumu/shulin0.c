#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
�������У���ֻ����������һ�ɵ������̣����ż����
���㣬�������������һȺ���ɫ���۷��������Է�����ȥ��
ֻ��һ��ʯ��(shibei)���ڵ��ۨ洦��������һ��յء�����
������ï�ܵ����֡�
LONG
        );
        set("outdoors", "quanzhen");
        set("item_desc", ([
                "shibei" : HIC
"
                        ���Ϲ�Ĺ��
                        ����ֹ����

\n" NOR,
        ]));
        set("exits", ([
                "southup" : __DIR__"shulin1",
                "north" : __DIR__"shulin4",
                "west"  : __DIR__"shulin5",
                "east"  : __DIR__"shulin6",
        ]));

        setup();
        replace_program(ROOM);
}
