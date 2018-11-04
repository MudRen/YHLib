
#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
        set("short", "Ĺ��");
        set("long", @LONG
���߹��˲ݵأ���ǰͻȻ��һƬ�����أ�ͻأ��������һ
����Ĺ��Ĺ������ʯͷ�Ѿ��ವ�ˣ����ĳ�����������Ĺ��Ĺ
ǰû��������Ҳû���κεı�ǣ���֪������ǰ����λ������
����ĹѨ��Ĺ�ſڱ�һ��Ĵ�ʯͷ(shi)��յ�˿����͸��
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "north" : __DIR__"caodi",
                "west"  : __DIR__"huangshalin",
        ]));

        set("item_desc", ([
               "shi": HIC "���ǿ��ʯ���²���������£��������š�" NOR + YEL"����ʯ" HIC 
                      "�������֡�\n" NOR,
        ]) );

        set("objects", ([
               __DIR__"npc/sun" :  1,
        ]));

        setup();
}

void init()
{
        add_action("do_move", "move");
}


int do_move(string arg)
{
        object me=this_player();

        if( !arg || arg != "shi" ) {
                return notify_fail("��Ҫ�ƶ�ʲô��\n");
        }

        message_vision(HIC "$N" HIC "վ��ʯǰ��˫�Ʒ����ƶ���ʯ��ֻ���þ�ʯ"
                       "֨֨��������\n�������ȥ���ֳ�һ���Ż�����\n" NOR, 
                       this_player());
        set("exits/south", __DIR__"qianting");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
        message("vision", HIW "\nֻ����ʯ��֨֨�ػص�ԭ�ء�\n" NOR, room);
        room->delete("exits/south");
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir != "south"
           || ! objectp(guard = present("sun popo", this_object()))
           || ! me->query("family"))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}
