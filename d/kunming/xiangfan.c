#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "�᷿" );
        set("long", @LONG
һ�䲻����᷿����ʰ��ʮ�ָɾ��������Ǽ���ƽ�����
֮�ã�һ��С����͸��Щ�����ˣ��Ե�ʮ�ֵ����ġ�
LONG);
        set("no_fight", 1);
        set("sleep_room", 1);
        set("exits", ([
                "west"   :__DIR__"dongzoulang1",
        ]));
        set("objects", ([
                "/d/shaolin/npc/shang1" : 2,
        ]));
        setup();
        replace_program(ROOM);         
}
