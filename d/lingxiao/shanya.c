#include <ansi.h>
inherit ROOM;

int do_open(string arg);

void create()
{
        set("short", "ɽ��");
        set("long",
"ӳ�����������֮��ģ���һ��Ρ��֮���Ĵ�ǡ�ֻ����ǽ
�������ɣ�ǽͷǽԫѩ��һƬ�����Ǳ�ѩ����ǽ����������ͷ��
������ͷ����һ���������չ�Ĵ��죬��¥����д����������

            " WHT "��������������������������������
            ��                            ��
            ��" NOR + HIW "     ��      ��      ��" NOR + WHT "     ��
            ��                            ��
            ��������������������������������" NOR "

����ǰ��һ�ź��ĵ���(bridge)�������ر��š������Ҫ����
�Ļ�������Ҫ���˿�(open)���С�\n");

        set("outdoors", "lingxiao");
        set("exits", ([
            	"east"  : __DIR__"cityout",
            	"west"  : __DIR__"cityout1",
            	"down"  : __DIR__"bingti",
        ]));

        set("item_desc", ([
        	"bridge" : WHT "\n����һ�ż���ĵ��ţ����������ǵ�һ�����ߡ�\n" NOR,
        ]) );
        setup();
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me=this_player();

        if (! arg || arg != "bridge" )
                return notify_fail("��Ҫ���\n");

        message_vision(HIY "\n$N" HIY "�������������һ����������"
                       "ѽ����\n" NOR, this_player());

        message_vision(HIY "ֻ���ó�������˵�������������ˣ��ŵ���"
                       "�ɡ���\n\n" NOR + HIC "ֻ���á�����������"
                       "��Ƭ�̣����Ż������£�¶��һ�����������ĳ�"
                       "������\n" NOR, this_player());

        set("exits/north", __DIR__"gate");
        remove_call_out("close");
        call_out("close", 10, this_object());

        return 1;
}

void close(object room)
{
        message("vision", HIY "ֻ�����¸¸¸¡������������ֱ�����"
                          "������\n" NOR, room);
        room->delete("exits/north");
}

