#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ����ɽ��ɽ´��̧ͷ������ɽ�ϻ�ѩ���������չ�
��ӳ����˸���ԡ�ɽ���ƺ���ã��ѩ�����������⽻���ڰ�����
��ѩ֮�䣬�����ܿ�����һ������ɽ����·����һ��ľ��(sign)��
LONG );

        set("item_desc", ([
        	"sign": HIW "\n\n    ��  ��  ��  ��  һ  ��  ë\n\n" NOR "\n"
        ]) );
        set("exits",([
                "southeast"  : "/d/xuedao/sroad1",
                "westup"  : __DIR__"sroad1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
        ]));
        set("outdoors", "lingxiao");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

