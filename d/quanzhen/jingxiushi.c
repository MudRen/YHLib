#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ��̵��Ӿ��޲������ķ��䣬�����С������
ʰ�ĸɸɾ��������ζ��ڷŵ��������룬����һ�����������
LONG);
        set("exits", ([
                "east" : __DIR__"houshan",
                "south" : __DIR__"diziju",
                "west" : __DIR__"houtang3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen") + "/liu" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;
        object ob;

        if (! (fam = me->query("family"))
           || fam["family_name"] != "ȫ���")
        {
                if ((ob = present("liu chuxuan", environment(me)))
                   && living(ob)
                   && dir == "east")
                        return notify_fail(CYN "������������ס����������Ǳ�"
                                           "����ʦ����֮�أ���ֹ����\n" NOR);
        }
        return ::valid_leave(me, dir);
}
