inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�
�������ƣ��������ش�졣һֱ������ͨ��ĥ��̨�������塣 
LONG
);
        set("exits", ([ 
               "east"       : __DIR__"shanlu002",
               "west"       : __DIR__"shanlu5",         
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

