inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
�����ں�ɽɽ·�ϣ�����ɽ����䣬�������ϪȪ���٣�
�������ƣ��������ش�졣������ɽ��·��������������ˮ�졣
LONG);
        set("exits", ([ 
               "west"    : __DIR__"shanlu11",
               "eastup"  : __DIR__"shuiliandong",
        ]));

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

