#include <ansi.h>

inherit ROOM;

void close_passage();
string look_bei();

void create()
{
    set("short", HIR "������" NOR);
        set("long", @LONG
���·�ϵľ����ͻĲݣ������ڵ�������ָɽ������ķ嶥����������
�ش����֮�У�����������ɽ���赲����˷��ƺ�С������������һƬ����
֮�С��嶥�����������ĻĲݣ���ʯ��ᾣ�һƬ������ɫ����ɽ�嶥������
�к�Ȼ������һ����ʯ���͵ķ�Ĺ����Ĺ��ǰ������һ��һ�˶�ߵĻ�����
��Ĺ��(bei)��
LONG    );
        set("exits", ([
                "southdown" : __DIR__"hclu-4",
        ]));

        set("item_desc",([
                "bei" : (: look_bei :),
        ]));

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");
        setup();
}

void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object me;
        me = this_player();

        if (! arg || arg != "bei") 
                return notify_fail("��Ҫ��ʲô��\n");

        if ((int)me->query_str() < 30)
                return notify_fail("�㽫���̵ľ��������ˣ��ɻ����޷���ʯ���ƿ���\n");

        if ((int)me->query_skill("force", 1) < 100 )
                return notify_fail("�����˰��죬����ʯ��������˿������\n");

        write(HIY "������������������˿�������Ĺ�������������ƿ�������¶��"
              "һ���ڶ�������ڡ�\n" NOR);
        message("vision", HIR + me->name() + HIR "˫����������Ĺ�����Ի�����"
                          "��������¶��һ���ڶ�������ڡ�\n" NOR , environment(me), ({me}) );
        set("exits/enter", __DIR__"shijie-1");
        remove_call_out("close_passage");
        call_out("close_passage", 10);
        return 1;
}

void close_passage()
{
        object room;

        if (! query("exits/enter"))
		return;
        message("vision", HIR "Ĺ������¡¡�������������ƻ�ԭ����\n" NOR, this_object() );
        delete("exits/enter");
}

string look_bei()
{
    return
    "\n"
 WHT "\n\n    ###################\n"
         "    ##               ##\n"
         "    ##           ��  ##\n"
         "    ##           ��  ##\n"
         "    ##           ��  ##\n"
         "    ##" NOR + HIR "       ��" NOR + WHT "  ��  ##\n"
         "    ##           ʮ  ##\n"
         "    ##" NOR + HIR "       ��" NOR + WHT "  ��  ##\n"
         "    ##           ��  ##\n"
         "    ##" NOR + HIR "       ��" NOR + WHT "  ��  ##\n"
         "    ##           ��  ##\n"
         "    ##   ��" NOR + HIR "  ��" NOR + WHT "      ##\n"
         "    ##   Ф          ##\n"
         "    ##   ��          ##\n"
         "    ##   ��  ֮      ##\n"
         "    ##   ��  Ĺ      ##\n"
         "    ##   ǧ          ##\n"
         "    ##   ��          ##\n"
         "    ##   ��          ##\n"
         "    ##   ��          ##\n"
         "    ##               ##\n"
         "    ###################\n\n" NOR;
    "\n";
}
