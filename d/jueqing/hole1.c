inherit ROOM;

void create()
{
        set("short", "̶�׶���");
        set("long", @LONG
��̶ˮ�����������г�ʪ����ȳ����š�
LONG);
        set("exits", ([
               "out"         : __DIR__"eyutan3",
               "northeast"   : __DIR__"hole2",
        ]));

       /* set("objects", ([
 
        ]));
       */

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
