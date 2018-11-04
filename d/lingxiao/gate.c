#include <ansi.h>;

inherit ROOM;

void close_bridge();
int do_open(string arg);

void create()
{
        set("short", "��������");
        set("long", 
"�����������ǵĳ��š���������������������֣������ڵ�
������¡��֮�ʳ��ж���ǰ����Ϯ���������˴������Ϊ�ֵ���
�������ȥ��ֻ����ͷ���������Ƿ������벻����������ѩɽ��
����ȴ����һ�����ȥ��������ǰ���ź��ĵ���(bridge)����
���ر��š������Ҫ����Ļ�������Ҫ���˿�(open)���С�
\n");

        set("outdoors", "lingxiao");
        set("exits", ([
                "eastup"  : __DIR__"walle1",
                "westup"  : __DIR__"wallw1",
                "north"  : __DIR__"iceroad1",
        ]));
        set("objects", ([
                CLASS_D("lingxiao") + "/wenwanfu" : 1,
                __DIR__"npc/dizi" : 3,
        ]));
        set("item_desc", ([
        	"bridge" : WHT "\n����һ�ż���ĵ��ţ����������ǵ�һ�����ߡ�\n" NOR,
        ]) );
        setup();
} 

void init()
{
        add_action("do_open", "open"); 
        add_action("do_close", "close");
} 

void close_bridge()
{
        object room;

        if (!( room = find_object(__DIR__"shanya")) )
                room = load_object(__DIR__"shanya");
        if (objectp(room))
        {
                delete("exits/south");
                message("vision", HIY "��λ����������ǰ�ѵ��Ź���������\n"
                                  NOR, this_object());
                room->delete("exits/north");
                message("vision", HIY "ֻ�����¸¸¸¡������������ֱ�����"
                                  "������\n" NOR, room);
        }
}

int do_close(string arg)
{
        if (! query("exits/south"))
                return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");

        if (!arg || (arg != "bridge" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIY "$N" HIY "��������������һ���֣���λ���ӵ��˵�"
                       "ͷ����ǰ�����ŵ�����ȥ��\n" NOR, this_player());

        remove_call_out("close_bridge");
        call_out("close_bridge", 2);

        return 1;
}

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("�����Ѿ��������ˡ�\n");

        if (! arg || (arg != "bridge" && arg != "south"))
                return notify_fail("��Ҫ��ʲô��\n");

        if (! ( room = find_object(__DIR__"shanya")) )
                room = load_object(__DIR__"shanya");
        if (objectp(room))
        {
                set("exits/south", __DIR__"shanya");
                message_vision(HIY "$N" HIY "���������Ӱѵ��ŷ���������\n" NOR, this_player());
                room->set("exits/north", __FILE__);
                message("vision", HIY "ֻ�����¸¸¸¡����������ű�����������\n" NOR, room);
                remove_call_out("close_bridge");
                call_out("close_bridge", 10);
        }

        return 1;
}

int valid_leave(object me, string dir)
{
    	object *inv;
        mapping myfam, mygen;
        int i;

        myfam = (mapping)me->query("family");

    	if ((! myfam || myfam["family_name"] != "������" ) && dir == "north")
        {
        	inv = all_inventory(me);
        	for( i = sizeof(inv)-1; i >= 0; i--)

            	if (inv[i]->query("weapon_prop") && inv[i]->query("skill_type") &&
               	   inv[i]->query("equipped"))

                if (objectp(present("wen wanfu", environment(me))))
                    	return notify_fail(CYN "���������һչ����ס���������������"
                                           "���Ĺ�أ�������ǲ���������С�\n");
    	}
    	return ::valid_leave(me, dir);
}