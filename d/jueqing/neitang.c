inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������ýϴ���Ҫ��һЩ�����ܳ������࣬��������
�ڷ��ż��軨ľ���������硣�ɼ������Ǹ�����֮�ˡ�
LONG);
        set("exits", ([
               "south"  : __DIR__"dating",
               "north"  : __DIR__"changlang2",
               "west"   : __DIR__"chufang",
               "east"   : __DIR__"pianting",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

