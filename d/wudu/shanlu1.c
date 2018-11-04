#include <ansi.h>
inherit ROOM;

string look_bei();

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
һ�����ѵ�С·����ɽ����ǰ���죬������Ũ�ܵ����֣�������
��᫲�ƽ��ɽ·��ǰ����ǿ��µĺ�ɭ���ˡ��Ա��ƺ���һ��ɽҰС
�꣬·����һ��ʯ��(bei)��
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"milin1",
                "west" : __DIR__"xiaodian",
                "north" : __DIR__"road3",
        ]));

        set("item_desc",([
                "bei" : (: look_bei :),
        ]));

        setup();
}

string look_bei()
{
    return
    "\n"
              WHT "          ####################################\n"
                  "          ####                            ####\n"
                  "          ####        ǰ����ɭ��ɽ����    ####\n"
                  "          ####    �ܣ�����֮�ڲ�������    ####\n"  
                  "          ####    �л��ǳ�û���У�����    ####\n"  
                  "          ####    ����˼�����У�          ####\n"  
                  "          ####                            ####\n"  
                  "          ####################################\n\n" NOR;
    "\n";
}
