#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�黨��");
        set("long", @LONG
ǰ����һƬ�������ɵ�԰�βݵ�(caodi)��һ���������ǵ�
�����˱Ƕ�����������ܲ���Χ�����黨�����۴��Ǹ���λ
���������а˾��ɵ��������黨�������书��ǿ��Ҳ������һ
Ծ��������ȻԾ����·Ҳ�����ܡ�
        ====�˴��ȴ����䡣��������====
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "westdown" : __DIR__"shanyao",
        ]));

        set("objects", ([
                __DIR__"npc/dizi1" : 1,
                __DIR__"npc/dizi2" : 1,
        ]));  

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


