#include <ansi.h>
#include <room.h>
inherit ROOM;

void check_trigger();
void close_passage();
void reset();

void create()
{
        set("short", HIB "���ֻ�˾��" NOR);
        set("long", HIB @LONG

                    ��         ��         ˾

    �ֻ�˾�ں���ɭɭ����ʯ����ĵ������ǻҳ��������಼Χᣣ�Χ�
���ý���˿������Щ��ֵ�ͼ����������һ����ʯ���� (table)��������
�����������������Ӻܾ�û��ɨ���ˡ�

LONG NOR );

        set("item_desc", ([
                "table" : WHT "һ����ʯ�Ƴɵ������������м���"
                          "�ѷ죬�������Ѹ�������ܾ��ˡ�\n" NOR,
        ]));

        set("exits", ([
                "out" : __DIR__"lunhuisi_road1",
        ]));

        create_door("out", YEL "ͭ��" NOR, "enter", DOOR_CLOSED);
        setup();
}

void init()
{
        add_action("do_turn", "turn");
        add_action("do_say", "say");
        add_action("do_move", "move");
        add_action("do_move", "push");
        add_action("do_move", "pull");
}

int do_move(string arg)
{
        string dir;

        if( ! arg || arg == "" ) return 0;

        if( arg == "table" )
        {
                write(HIY "\n���þ���ȫ���������ƶ�ʯ���������������ڵ���"
                      "����һ�㣬��˿������\n" NOR);
                return 1;
        }
}

void check_trigger()
{
        object room;

        if( (int)query("zuo") == 3
        && (int)query("you") == 3
        && ! query("exits/down") )
        {
                message("vision", WHT "\nʯ����Ȼ����������һ���춯����"
                                  "һ�໺���ƿ���ʯ���»�Ȼ¶��һ����"
                                  "�����Ľ��ݡ�\n" NOR, this_object() );
                set("exits/down", __DIR__"diyin_road1");
                delete("zuo");
                delete("you");
                remove_call_out("close_passage");
                call_out("close_passage", 10);
        }
}

void close_passage()
{
        object room;

        if( ! query("exits/down") ) return;
        message("vision", WHT "\nʯ����Ȼ����������һ���춯���������ƻ�"
                          "ԭ���������µĽ��ݸ��˸���ʵ��\n" NOR,
                          this_object() );
        delete("exits/down");
}


int do_turn(string arg)
{
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg == "lunpan" && (int)query("poem_said") == 1 )
        {
                write(HIC "�����Ŵ������̣���������������ת����\n" NOR);
                return 1;
        }

        if( sscanf(arg, "lunpan %s", dir) == 1 && (int)query("poem_said") == 1 )
        {
                if( dir == "left" )
                {
                        message_vision(HIW "$N" HIW "����������ת����һȦ"
                                       "������Ȼ�����������������죬������"
                                       "ת�˻�ԭλ��\n" NOR, this_player());
                        add("zuo", 1);
                        check_trigger();
                        return 1;
                }
                if( dir == "right" )
                {
                        message_vision(HIR "$N" HIR "����������ת����һȦ"
                                       "������Ȼ�����������������죬������"
                                       "ת�˻�ԭλ��\n" NOR, this_player());
                        add("you", 1);
                        check_trigger();
                        return 1;
                }
           else {
                        write(HIC "��Ҫ�����������ĸ�����ת����\n" NOR);
                        return 1;
                }
        }
}

int do_say(string arg)
{
        string dir;

        if( ! arg || arg == "" ) return 0;

        if( arg == "��ر���ʱ" && (int)query("poem_said") != 1 )
        {
                message_vision(HIW "\nֻ��$N" HIW "��Ȼ�����ȵ�������ر�"
                               "��ʱ����\n" NOR + HIR "\n$N" HIR "������"
                               "�䣬����ͻȻ����¡¡���ζ��˼��¡���ʯ����"
                               "����ʯм��ʱ���䣬¶����һ��ʯ�̡�\n\n"
                               NOR, this_player());
                this_object()->recreate();
                set("poem_said", 1);
                return 1;
        }

        if( arg == "��ر���ʱ" && (int)query("poem_said") == 1 )
        {
                write(HIC "\n����Ŵ���һ���ͺȣ�������˾�ڻص��˺�һ������š�\n" NOR);
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("zuo");
        delete("you");
}

void recreate()
{
        set("short", HIB "���ֻ�˾��" NOR);
        set("long", HIB @LONG

                    ��         ��         ˾

    �ֻ�˾�ں���ɭɭ����ʯ����ĵ������ǻҳ��������಼Χᣣ�Χ�
���ý���˿������Щ��ֵ�ͼ����������һ����ʯ���� (table)��������
����Ѿ����䣬¶���ڲ���һ��ʯ������(lunpan)��

LONG NOR );

        set("item_desc", ([
                "table" : WHT "һ����ʯ�Ƴɵ������������м���"
                          "�ѷ죬���ı���Ѿ������ˡ�\n" NOR,
                "lunpan": WHT "һ��ʯ�Ƶ����̣��������ǻ��ƣ���"
                          "������ת����\n" NOR,
        ]));

        set("exits", ([
                "out" : __DIR__"lunhuisi_road1",
        ]));

        create_door("out", YEL "ͭ��" NOR, "enter", DOOR_CLOSED);
        setup();
}
