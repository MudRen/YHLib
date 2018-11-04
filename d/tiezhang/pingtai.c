#include <ansi.h>

inherit ROOM;
string look_ditu();

void create()
{
        set("short", "ɽ��ƽ̨");
        set("long", @LONG
������ɽ���һ��ƽ�ء�ɽ�������￪ʼ��֧����������ǰ����������
�����Ƶ�ɽ�壬������ָ��������ɽ��֮���ɴ˶��á������ͬ����ɽ����
Ĵָ��֮��ΰ��ʳָ��֮�վ�����ָ��֮���ʣ�������֮������Сָ��֮��
�����������ɫ������ʤ������ƽ̨һ��Ĵ�ʯ�ϣ�����һ����ͼ(map)��
LONG );
        set("item_desc", ([ 
                "map" : (: look_ditu :),
        ]));

        set("exits", ([ 
                "westup" : __DIR__"shanlu-5",
                "northeast" : __DIR__"shangu-1",
                "eastup" : __DIR__"sslu-1",
                "southdown" : __DIR__"shanlu-4",
                "northwest" : __DIR__"hclu",
                "northup" : __DIR__"shanlu-6",
        ]));

        set("objects", ([ 
                __DIR__"npc/huiyi" : 3,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        
}

string look_ditu()
{
    return
    "\n"
  WHT "\n\n\n    ################################\n"
            "    ##                            ##\n"
            "    ##           ��ָ��           ##\n"
            "    ##             ��             ##\n"
            "    ##     ������  ��  ʳָ��     ##\n"
            "    ##        ��   ��   ��        ##\n"
            "    ##          �� �� ��          ##\n"
            "    ##  Сָ�塪��ƽ̨����Ĵָ��  ##\n"
            "    ##                            ##\n"
            "    ################################\n\n\n\n\n" NOR;
    "\n";
}
