inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short", "÷��");
        set("long", @LONG
����һ��������÷������Ĵ�����������������ǵĴ��
�������ˡ����������÷�㣬����Ϊ����������÷�����߽�ȴ
�ŷ��֣�����ֻ�����ú�Χ�ֵİ�÷����������ı��衣��ʵ
��÷����ѩ���ѷֲ����ˡ�������������Ǿ䡸÷��ѷѩ����
�ף�ѩȴ��÷һ���㡹�Ļ�����˭Ҳ�������ˡ���÷��ѩ��˭
��˭�㣬�ֵó�����
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
                "south"  : __DIR__"iceroad3",
                "north"  : __DIR__"dadian",
                "west"  : __DIR__"meiroad2",
                "east"  : __DIR__"meiroad3",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
                __DIR__"obj/ban" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object me = this_player();
        object ob;

        if (arg == "mei hua" || arg == "meihua")
        {
                if (query("count") < -5)
                        return notify_fail("�����÷���Ѿ���ժ���ˡ�\n");

                ob = new(__DIR__"obj/mei");
                ob->move(me, 1);
                add("count", -1);

                message_vision("$N��·�Ե�����ժ��һ��" +
                               ob->query("name") + "��\n", me);
                return 1;
        } else
                return notify_fail("��Ҫժʲô��\n");
}
