#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", NOR + WHT "����Դ�߷���" NOR);
        set("long", WHT @LONG

                    ��     Դ     ��     ��

    ��������Դ�ϲ��һ��С�߷����߷��ڲ��õķǳ����ʣ�ֻ��һ��
С������������Ŀ��������ϣ���ҡ�������ȣ��������֮����������
��֮������Ц�����Ŀ����������


LONG NOR );
        set("no_fight", 1);
        set("objects", ([
                __DIR__"npc/wei" : 1,
        ]));
        set("exits", ([
                "north"  : __DIR__"entry",
                "out"   : __DIR__"yanluodian",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        if (! objectp(ob = present("wei xiaobao", this_object())))
        {
                ob = new(__DIR__"npc/wei");
                ob->move(this_object());
        }

        ob->check_leave(me, dir);
        return ::valid_leave(me, dir);
}
