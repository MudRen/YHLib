#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", NOR + WHT "����Դ���ݡ�" NOR);
        set("long", WHT @LONG

                    ��     Դ     ��     ��

    ��������Դ�����һ��С���ݣ������������£������쳣�����ݵ�
����������һλ���������Ĵ󺺣�˫Ŀ�������䣬����������������
�ĵ�������������һЦ��


LONG NOR );
        set("no_fight", 1);
        set("objects", ([
                __DIR__"npc/lu" : 1,
        ]));
        set("exits", ([
                "west"  : __DIR__"entry",
                "out"   : __DIR__"yanluodian",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        if (! objectp(ob = present("lu tianshu", this_object())))
        {
                ob = new(__DIR__"npc/lu");
                ob->move(this_object());
        }

        ob->check_leave(me, dir);
        return ::valid_leave(me, dir);
}
