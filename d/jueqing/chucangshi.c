inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǿ���ȵĴ����ң�����ѷ���һЩ���
LONG);
        set("exits", ([
               "west"   : __DIR__"houtang",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

