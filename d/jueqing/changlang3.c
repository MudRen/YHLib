inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����������úͺ��õĳ��ȣ��䲻����ľ����Ҳ���ŵ���
���Ļ��㡣
LONG);
        set("exits", ([
               "north"   : __DIR__"changlang4",
               "south"   : __DIR__"changlang2",
               "east"   : __DIR__"xiangfang2",
               "west"   : __DIR__"xiangfang1",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
