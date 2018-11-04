#include <ansi.h>

inherit ROOM;
string look_bei();

void create()
{
	set("short", "�ҷظ�");
	set("long", @LONG
������һ���ҷظڣ����������˹��˸ߵĳ��ݣ���˵����
�����ֹ�����û�˸�����һ�����������ŵ��������ë��
��ǰ��������һ���·أ���������һ�鱮(bei)��
LONG);

	set("exits", ([
		"west" : __DIR__"luan",
        ]));

	set("item_desc", ([
                "bei" : (: look_bei :),
	]));

	setup();
}

string look_bei()
{
    return
    "\n"
 WHT "\n\n    ###################\n"
         "    ##               ##\n"
         "    ##           ��  ##\n"
         "    ##           Ů  ##\n"
         "    ##               ##\n"
         "    ##       " NOR + HIR "��" NOR + WHT "      ##\n"
         "    ##       " NOR + HIR "˪" NOR + WHT "      ##\n"
         "    ##       " NOR + HIR "��" NOR + WHT "      ##\n"
         "    ##               ##\n"
         "    ##       ֮      ##\n"
         "    ##       Ĺ      ##\n"
         "    ##               ##\n"
         "    ##   ��          ##\n"
         "    ##   ˼          ##\n"
         "    ##   ��          ##\n"
         "    ##   ��          ##\n"
         "    ##               ##\n"
         "    ###################\n\n" NOR;
    "\n";
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
        set("exits/enter", __DIR__"tomb");
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
