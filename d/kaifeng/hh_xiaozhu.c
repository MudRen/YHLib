#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "��԰С��");
        set("long", @LONG
�����Ǻ컨���ܶ��԰�е�һ����ͤ����ͤ�����Ϊ��
�£��м����һ��ʯ�����������Ƚ��ر��ƺ����ƶ����ĺ�
�������Ͽ��ź�ʮ�ţ���ʮ�ŵ�һ�����̣��оֻ�δ��ȥ����
����������飬Ϧ������ʱƷ��̸�죬��������һ����¡�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"southdown" : __DIR__"hh_road",
	]));
        set("objects", ([
                CLASS_D("honghua") + "/yu" : 1,
        ]));
        set("item_desc",([
                "zhuo": WHT "\nһ�Źžɵ���ʯ��������֪�ܲ����ƿ���\n " NOR,
        ]));

        set("outdoors", "honghua");
        setup();
}

void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        int n;
        object me = this_player();

        if (! arg || arg != "zhuo")
                return 0;

        if (query("exits/down"))
                return notify_fail("ʯ���Ѿ����ƿ��ˣ��㻹����������\n");

        if (me->query("family/family_name") != "�컨��" &&
           objectp(present("yu yutong", environment(me))))
        {
                        write(CYN "����ͬüͷһ�壬�ȵ�������ʲô��"
                              "ͷ����Ȼ�����������\n" NOR);
                        return 1;
        }

        message_vision(HIY "$N" HIY "�ߵ�ʯ��ǰ������˫�ƣ�ʹ���ƶ�"
                       "ʯ�������㽫���ƿ���\n" NOR, me);

        if (me->query("max_neili") < 1000)
        {
               message_vision(HIR "�����֪$N" HIR "�������ã�������"
                              "�ľ��������ˣ�ʯ��������˿������\n" NOR, me);
               me->set("neili", 0);
               return 1;
        }

        message_vision(HIY "ʯ����Ȼ������������������һ�໺���ƿ���"
                        "����¶��һ���ڶ�������ڡ�\n" NOR, me);

        set("exits/down", __DIR__"hh_mishi");
        me->set("neili", 0);
        remove_call_out("close_passage");
        call_out("close_passage", 10);
        return 1;
}

void close_passage()
{
        object room;

        if (! query("exits/down")) return;
        message("vision", HIY "\nʯ������¡¡�������������ƻ�ԭ����\n" NOR,
                          this_object());
        delete("exits/down");
}

int valid_leave(object me, string dir)
{
        object yu;

        if (dir != "down"  ||
            ! objectp(yu = present("yu yutong", this_object())))
                return ::valid_leave(me, dir);

        return yu->permit_pass(me, dir);
}