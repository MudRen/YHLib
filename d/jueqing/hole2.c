inherit ROOM;

void create()
{
        set("short", "̶�׶���");
        set("long", @LONG
��̶ˮ�����������г�ʪ����ȳ����š�
LONG);
        set("exits", ([
               "southwest"   : __DIR__"hole1",
               "out"         : __DIR__"undertan",
        ]));

       /* set("objects", ([
 
        ]));
       */

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
