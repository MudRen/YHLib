#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR "��ָ��" NOR);
        set("long", @LONG
�����������ɽ����߷塪����ָ�塣����ɽ��̫�ߣ��嶥�Դ��д���
�Ļ�ѩ����ѩ������������������£�����һƬҫ�۵����⡣��ĿԶ������
�������ﾰɫ�����۵ף���Ϫ����Ϫ�������������ɽ�»���������Զ����
����ɫ�����ߣ����������Ĵ󽭡����佭��
LONG    );

        set("exits", ([
                "southdown" : __DIR__"shanlu-9",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
