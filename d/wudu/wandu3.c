#include <ansi.h> 
inherit ROOM;

string* npcs = ({
        "/clone/worm/xixuezhu",
        "/clone/worm/renmianzhu",
        "/clone/worm/tianwu",
        "/clone/worm/jiuweixie",
        "/clone/worm/shishixie",
        "/clone/worm/tieguxie",
        "/clone/worm/heiguafu",
        "/clone/worm/jinxianwugong",
});

void create()
{
        set("short", RED "�򶾿�" NOR);
        set("long", @LONG
������ɽ���ڲ���֧���������Ѿ�û��һ˿�����ˣ��ڶ�����ʲ
ôҲ�������������ұ�(wall)�Ϻ������ż��겻֪����С�ݡ����Դ�
��һ�����С���������
LONG);
        set("item_desc", ([
                "wall" : WHT "һ���ұڣ�����ͻ��Щʯ���ƺ�����˳������ȥ��\n" NOR,
        ]));
        set("exits", ([
                "north" : __DIR__"wandu2",
        ]));

        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));
    

        setup();
}

void init()
{
       add_action("do_climb", "climb");
}
int do_climb(string arg)
{
       
        object me = this_player();
        object ob; 

        if( (!arg) ||!((arg == "wall") || (arg == "�ұ�")))
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIC "$N" HIC "�����ұ���ͻ����ʯ����ѵ�������ȥ��\n\n" NOR,me);
        ob = load_object(__DIR__"dongxue");
        ob = find_object(__DIR__"dongxue");
        message("vision", HIC + me->query("name") + HIC "����������������\n" NOR, ob);

        me->move(__DIR__"dongxue");
        return 1;
}

