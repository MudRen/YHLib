inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
���Ǿ���ȴ���ͨ����԰��һ���ؾ�֮·����·���Ի�
�ݴ������������ˡ�
LONG);
        set("exits", ([
               "east"   : __DIR__"huayuan",
               "west"   : __DIR__"dating",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
