inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������������µ��Ĵ��������õĴ����������ڷǳ��Ŀ�
��������ԶԶ��ȥ�������죬���Ʋ�ʳ�˼��̻�
LONG);
        set("exits", ([
                "north" : __DIR__"tiangate",
                "south" : __DIR__"tian1",
        ]));
        set("objects", ([
                "/d/shaolin/npc/shang1" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
