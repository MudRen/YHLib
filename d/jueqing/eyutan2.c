#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����̶��");
        set("long", @LONG
����̶�к�ˮ�̹ǣ�����ף�̶��ˮ������������ë��
�Ȼ������Ҫ�뿪����ֻ����(swim)�ذ���(bank)��
LONG);
        set("objects", ([
                "/clone/quarry/eyu" : 1 + random(6),
        ]));

        set("no_clean_up", 0);
        setup();
}

void init()
{       
        add_action("do_swim", ({ "swim", "you" }));
}

int do_swim(string arg)
{
        object me = this_player();
        object ob;

        if (! arg || arg != "bank" )
                return notify_fail("��Ҫ���Ķ��Σ�\n");

        if (! ob = find_object(__DIR__"eyutan1"))
                ob = load_object(__DIR__"eyutan1");

        if (me->is_busy())
                return notify_fail("��������æ���أ�\n");

        if (me->is_fighting())
                return notify_fail("�㻹���Ȱ�����ǰ����һ�������˵��\n");

        tell_object(me, HIY "��ʹ�����������򰶱���ȥ��\n" NOR);
        tell_room(ob, HIC + me->name() + "����������\n" NOR, me);
        me->move(ob);

        return 1;
}
