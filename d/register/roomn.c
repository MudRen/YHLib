#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", NOR + WHT "����Դé�ݡ�" NOR);
        set("long", WHT @LONG

                    ��     Դ     é     ��

    ��������Դ�����һ��Сé�ݣ����ڼ���û���κγ��裬�򵥵ĳ�
�����ϡ���������һλ̹��¶��Ĵ󺺣�������ơ���������ǣ���
���������ֻ������һ��ͷ��


LONG NOR );
        set("no_fight", 1);
        set("objects", ([
                __DIR__"npc/li" : 1,
        ]));
        set("exits", ([
                "south"  : __DIR__"entry",
                "out"   : __DIR__"yanluodian",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        if (! objectp(ob = present("li zicheng", this_object())))
        {
                ob = new(__DIR__"npc/li");
                ob->move(this_object());
        }

        ob->check_leave(me, dir);
        return ::valid_leave(me, dir);
}
