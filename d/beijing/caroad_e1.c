#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���ֵĶ�����������Ͻ��ǵĽ�ͨҪ������������ʯ���
������ͷ���죬·���и���������ֻ������������̽ͷ����
�������˲��ϣ�������ʢ�������Զ��������������ԶԶ��
��������һ�¶¸ߴ��ʵ�Ĺų�ǽ�������������찲�Ź㳡�ˡ�
�����Ǿ�����Ϊ�������ֵ���������֡�
LONG);
       set("exits", ([
                "east" : __DIR__"caroad_e2",
                "west" : __DIR__"cagc_e",
                "north" : __DIR__"wang_1",
        ]));
        set("objects", ([
                __DIR__"npc/girl4" : 1,
                __DIR__"npc/jumin1" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
