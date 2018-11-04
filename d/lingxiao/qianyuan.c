inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short", "ǰԺ");
        set("long", @LONG 
�����������ǵ�ǰԺ���������Ӵ󶼾�ס�ڴ˺�������
��һ�����˺�Χ�ֵ�ī÷��������ڣ���ζ�ҷ�������Ĵ�Ժ
���ɽ����͸��ī÷�Ļ������£���ѩ����ӳ��һ������ߡ�
һֻѩ���������������裬�ڰ���ӳ��������Ȥ�� 
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"south"  : __DIR__"dadian",
            	"west"  : __DIR__"huajing", 
            	"north"  : __DIR__"zhongting",
        ]));
        set("objects", ([
                "/clone/quarry/he2" : 1,
                __DIR__"obj/ban" : 1,
        ]));
        set("no_clean_up", 0);
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
