#include <ansi.h>

inherit ROOM;

string look_ge();

void create()
{
        set("short", "������");
        set("long", @LONG
���ô˴����������������������������������ֻ����Զ
����һ¶��ͤ��(ting ge)��ӳ�ڴ���֮�¡�
LONG);

        set("item_desc",([
                "ting ge" : (: look_ge :),
                "ting"    : (: look_ge :),
                "ge"      : (: look_ge :),
        ]));

        set("exits", ([
               "south"  : __DIR__"huayuan",
               "east"   : __DIR__"zhulin4",
        ]));

        set("objects", ([
              CLASS_D("jueqing") + "/zhi" : 1,
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

string look_ge()
{
        return HIC "\n����ͤ����ӳ�ڴ���֮�£�֮������һ���ң����飺"
               HIG "\n\n"
        "\t\t��������������        \n"
        "\t\t��������������        \n"
        "\t\t����      ����        \n"
        "\t\t����" NOR + MAG "���� " HIG " ����\n" HIG    
        "\t\t������ �� ����        \n" HIG 
        "\t\t����" NOR + MAG "���� " HIG " ����\n" HIG    
        "\t\t������ �� ����        \n" HIG
        "\t\t����" NOR + MAG "���� " HIG " ����\n" HIG
        "\t\t����      ����\n"     
        "\t\t��������������\n" HIG
        "\t\t��������������\n\n" NOR;

}
