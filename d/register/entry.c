#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "��������Դ��" NOR);
       set("long", HIW @LONG

                    ��     ��     ��     Դ

    ֻ�������һ��续�����ⰻȻ��С����ˮ����Ӣ�ͷף���һ��ʫ��
���⡣�ӱ�������һ���ʯ��һλŮ����ױ�ع�����ʯ��ü���ƺ�����
˵�����İ�˼���Ա�һλ����Ӣ��ͦ�Σ���Ȼ��������ʯ���Ա���һ��
����(paizi)����Ҳ��Ӧ����ϸ������


LONG NOR );
        set("no_fight", 1);
        set("item_desc", ([
                "paizi" : WHT "����ע��(" NOR + HIY "register email" NOR +
                          WHT ")�ʼ���Ȼ������Էֱ�ȥ��ͬ�ĳ���ѡ���������Ʒ�ʡ�\n" NOR,
        ]));
        set("objects", ([
                __DIR__"npc/shuisheng" : 1,
                __DIR__"npc/diyun"     : 1,
        ]));
        set("exits", ([
                "east"  : __DIR__"roome",
                "south" : __DIR__"rooms",
                "west"  : __DIR__"roomw",
                "north" : __DIR__"roomn",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        if (! objectp(ob = present("shui sheng", this_object())))
        {
                ob = new(__DIR__"npc/shuisheng");
                ob->move(this_object());
        }

        if (! me->query("registered"))
        {
                message_vision(CYN "ˮ��������$N" CYN "˵������û��ע���أ�����ע��(" NOR +
                               HIY "register" NOR + CYN ")����ȥ����\n" NOR, me);

                if (me->query_temp("email"))
                        return notify_fail(HIR "�����ȷ������ĵ�ַ���;���(" NOR + HIY
                                           "decide" NOR + HIR ")�ɡ�\n" NOR);

                return notify_fail(HIY "�㻹����ע�᣿\n" NOR);
        }

        if (! objectp(ob = present("di yun", this_object())))
        {
                ob = new(__DIR__"npc/diyun");
                ob->move(this_object());
        }
        message_vision(CYN "���ƶ�$N" CYN "һ��ȭ����������·ȫ���Լ��ߣ������ߺã�\n" NOR, me);

        return 1;
}
