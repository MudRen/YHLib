#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����ɾ�");
        set("long", @LONG
����ö�������ǰ���Ǹ����Ž��صĴ�ȣ��컨��������
����ӳ�������̤�����������ϸ�ݣ������ŵ��������ĵĻ�
�㣬���ݼ�أ��ʹ���֦������õ����������Ķ�Ѩ�󣬾�
��������һ�����츣�ء��������ߴ���һɽ��(dong)��
LONG);
        set("outdoors", "mingjiao");
        set("exits", ([
                "west"  : __DIR__"gudi5",
                "south" : __DIR__"gudi4",
        ]));
        set("item_desc", ([
                "dong": WHT "����һ����֪��ǳ��ɽ����\n" NOR,
        ]));

        set("objects", ([
                "/clone/quarry/yang2" : 2,
        ]));

        setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me = this_player();

        if (! arg || arg != "dong")
        {
                write("�����ʲôѽ?\n");
                return 1;
        }
        message_vision(HIY "$N" HIY "������һ��������������"
                       "������������\n" NOR, me);
        me->move(__DIR__"gudi2");
        return 1;
}
