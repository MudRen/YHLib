#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ȴ������аڷ���һ������ɫ�輸�����ܲ����ż���
���ӣ��α��Ͽ���Щ��ͼ�����䵥���˵㣬��Ҳ�Ե÷ǳ����£�
���ǵļ��軨ľɢ�����������㡣
LONG);

        set("objects", ([
              __DIR__"npc/dizi1"  :  2,
              __DIR__"npc/dizi2"  :  2,
        ])); 
        set("exits", ([
               "out"   : __DIR__"shanzhuang",
               "north" : __DIR__"neitang",
               "west"  : __DIR__"changlang1",
               "east"  : __DIR__"xiaojing",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

