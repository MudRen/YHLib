inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
�������һ����ߵ�һ������С·��һ�Ծ����峺�Ľ�ˮ���а���
�಻�ϵ��һ�������ϼ������Ϯ�ˣ���������۷��ڻ�������衣
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"xiao2",
                "north" : __DIR__"jiang2",
        ]));

        setup();
        replace_program(ROOM);
}
