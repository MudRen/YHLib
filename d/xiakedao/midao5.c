#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����ͨ��");
        set("long", @LONG
����һ��ʯ�ң���Լ���Ըо��������Ǳ������Ӳ��ʯ�ڡ�
���Ϻͽ��䶼�ǻҳ�����źþ�û�������ˡ�
LONG);
        set("exits", ([
               "east" : __DIR__"midao4",
               "out"  : __DIR__"neiting",
        ]));
        setup();
}

int valid_leave(object me,string dir)
{
        if (dir == "out")
                tell_object(me, WHT "\n���߳�������ͨ��������"
                                "�س���������֮�С�\n\n" NOR);

        return ::valid_leave(me,dir);
}
