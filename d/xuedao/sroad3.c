inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ǿ��������ĳ�ɽ���룬��ʯ��ᾡ�������ȥ���Ǵ�
����Ե�ˡ�������һ��ѩɽ�������ơ�·�����и�ѩ�ӡ�
LONG);
        set("exits", ([
                "east"      : __DIR__"sroad2",
                "southdown" : __DIR__"hollow",
                "north"     : __DIR__"sroad0",
                "westup"    : __DIR__"sroad4",
        ]));
        set("outdoors", "xuedao");
        setup();
}

