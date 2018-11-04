#include <ansi.h>
inherit ROOM;

#define QIANGPU   "/clone/lonely/book/zhongping"

void create()
{
        set("short", "ѩɽɽ��");
        set("long", @LONG
һ�����ɽ�ȣ�Ⱥɽ���ƣ�ɽ����ȫ�ǰ������Ļ�ѩ��ɽ
���Ϸ�������ɽ���������м���˵����ʲô���ֵĹ���������
��һЩ���߰��������(mash)�Ѱ������
LONG );
        set("exits", ([
                "enter"    : __DIR__"shandong1",
                "eastdown" : __DIR__"wangyougu",
                "northup"  : __DIR__"sroad7",
        ]));
        set("outdoors", "xuedao");
        setup();
}

void init()
{
        object ob;

        ob = find_object(QIANGPU);
        if (! ob) ob = load_object(QIANGPU);

        if (! environment(ob))
        {
                set("item_desc", ([
                        "mash": HIR "\n����һЩ���߰�������飬ɢ����������ĵ�"
                                "��ζ���㶨����\nȥ�������о�Ȼ�б�" NOR + CYN
                                "����ƽǹ�ס�" HIR "(zhongping qiangpu)" HIR "��"
                                "\n\n" NOR,

                        "zhongping qiangpu" : CYN "���Ǳ���������ᣬ��Ƥ������"
                                              "��д�С���ƽǹ�����ĸ����֡�\n" NOR,

                        "zhongping" : CYN "���Ǳ���������ᣬ��Ƥ��������д�С�"
                                      "��ƽǹ�����ĸ����֡�\n" NOR,

                        "qiangpu"   : CYN "���Ǳ���������ᣬ��Ƥ��������д�С�"
                                      "��ƽǹ�����ĸ����֡�\n" NOR,

                ]));
                add_action("do_get", "get");
        } else
        {
                set("item_desc", ([
                        "mash": HIR "\n����һЩ���߰�������飬ɢ����������ĵ�"
                                "��ζ��\n" NOR,
                ]));
        }
        add_action("do_enter", "enter");
}

int do_get(string arg)
{
        object me, ob;

        me = this_player();
        ob = find_object(QIANGPU);
        if (! ob) ob = load_object(QIANGPU);

        if (environment(ob)) return 0;

        if (! arg || arg == "" ) return 0;

        if (arg == "zhongping qiangpu from mash"
           || arg == "zhongping from mash"
           || arg == "qiangpu from mash"
           || arg == "book from mash"
           || arg == "all from mash"
           || arg == "pu from mash")
        {
                ob->move(me, 1);
                message_vision(HIY "\n$N" HIY "�������з���һ������ƽǹ������\n"
                               "\n" NOR, me);

                set("item_desc", ([
                        "mash": HIR "\n����һЩ���߰�������飬ɢ����������ĵ�"
                                "��ζ��\n" NOR,
                ]));
                return 1;
        }
        return 0;
}

int do_enter(string arg)
{
        object me;

        me = this_player();

        if (arg != "mash")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->query("family/family_name") != "Ѫ����")
                return notify_fail(HIR "\n�㷭��һ����Щ���飬ֻ��һ��"
                                   "Ѫ������ӿ������ֱ��Ż�¡�\n" NOR);

        message("vision", HIY "\n" + me->name() + HIY "�ߵ�һ�߲�֪����"
                          "�������ظ�Щʲô��ͻȻ�˾Ͳ����ˡ�\n\n" NOR,
                          this_object(), ({ me }));

        tell_object(me, HIY "\n����������ƿ���Щ���飬Խ����ȥ��ֱ����"
                        "�ܵ������ݶ�ȥ��\n\n" NOR);
        me->move("/d/city/xdmidao1");
        return 1;
}
