inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�
�������ƣ��������ش�졣̧ͷֻ����Զ����һ��ͤ�ӡ�
LONG);
        set("exits", ([
               "southeast" : __DIR__"shanlu3",
               "northup"   : __DIR__"banshan",
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

