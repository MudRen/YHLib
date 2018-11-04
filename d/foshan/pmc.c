#include <ansi.h>
#include <command.h>

inherit ROOM;

int do_look(string arg); 

void create()
{
    set("short", "Ӣ�ۻ�ݺ���");
    set("long", @LONG
Ӣ�ۻ�����Ƿ�ɽ������ϰ��졹�����ϵļ�ҵ��������
����ˣ���������������ͷ�ġ�����Ӣ�ۻ������Χ�ź�ѹѹ
��һ��Ⱥ�ˣ��������Ը��ص�֪���̼֡��������������ã�Ϭ
����Ŀ���ƺ�Ҫ�����͸һ�㡣��ǽ���ŵ����� (paizi)����
д�Ŵ˴��������Ĺ���һ��Ҫ�úÿ�����
LONG);
        set("no_fight", 1);
        set("no_sleep", 1);

        set("exits", ([
                "north" : __DIR__"pm_restroom",
        ]));

        setup();
        "/adm/npc/feng"->come_here();
}

void init()
{
        object me = this_player();

        if (wiz_level(me) >= 3
           && ! me->query_temp("to_pmc"))
        {
                tell_object(me, WHT "\n����������Ķ�������˵������ʦ��"
                                "���ֲ�(" HIY "board" NOR + WHT ")������"
                                "������˼ҿ��Կ�����\n\n" NOR);
                me->set_temp("to_pmc", 1);
        }
        add_action("do_look", "look");
}

int do_look(string arg)
{ 
        object me = this_player();

        if (arg != "paizi" && arg != "board")
                return 0;

        if (arg == "paizi")
                return HELP_CMD->main(me, "pm1");
        else
                return HELP_CMD->main(me, "pm2");
}
