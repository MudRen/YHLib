#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����㳡");
        set("long", @LONG
�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档
���ֺ��е��˳������������������������������ݡ���
��һ�ô�����(tree)�̸���ڣ��ݴ�����ǧ������䣬������
���е���ʷ��֤�����ɵײ���һ���ܴ������ (dong)�� ���
�Կ������������Ը��ص��������������������������У�һ��
�������󣬶��߲�ʱ�ش������ʵĶ����������������������
���ˣ�һƬ�ྲ��
LONG);
        set("no_sleep_room",1);
        set("outdoors", "city");
        set("item_desc", ([
                "dong" : WHT "\n����һ���ڲ����еĴ󶴣����治֪��"
                         "��Щʲô�Ź֡�\n" NOR,
                "tree" : GRN "\n����һ�þ޴���ϵĴ�������֦Ҷ�ǳ�"
                         "��ï�ܡ�\n" NOR,
        ]));

        set("exits", ([
                "east" : __DIR__"dongdajie1",
                "south" : __DIR__"nandajie1",
                "west" : __DIR__"xidajie1",
                "north" : __DIR__"beidajie1",
        ]));

        set("objects", ([
                "/d/taishan/npc/jian-ke" : 1,
                "/d/beijing/npc/haoke1" : 1,
        ]));
        setup();
        "/clone/fam/notice"->foo();
        "/d/city/npc/liapo"->come_here();

}

void init()
{
        object me = this_player();
        if (me->query("special_skill/emperor"))
        {
             me->delete("special_skill/emperor");
             log_file("static/emperor", sprintf("%s(%s) eat ɾ���������� at %s.\n",
                      me->name(1), me->query("id"), ctime(time())));

             
        }
        add_action("do_enter", "enter");
        add_action("do_climb", "climb");
}

int do_enter(string arg)
{
        object me;
        me = this_player();

        if (! arg || arg == "")
        	return 0;

        if (arg == "dong")
        {
                if (me->is_busy())
                {
                        return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
                        return 1; 
                }

                message("vision", HIC + me->name() + HIC "һ������������"
                                  "�˽�ȥ��\n" NOR, environment(me), ({me}));

                me->move("/d/gaibang/inhole");
                message("vision", HIC + me->name() + HIC "�Ӷ������˽���"
                                  "��\n" NOR, environment(me), ({me}));
                return 1;
        }
}

int do_climb(string arg)
{
        object me;
        me = this_player();

        if (! arg || arg == "")
        	return 0;

        if (arg == "tree")
        {
                if (me->is_busy())
                {
                        return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
                        return 1; 
                }

                message_vision(HIC "$N" HIC "����������֦辣���������������ȥ��\n"
                               NOR, me);

                me->move(__DIR__"tree");
                message("vision", HIC + me->name() + HIC "������Ĺ㳡������������\n"
                                  NOR, environment(me), ({me}));
                return 1;
        }
}
