inherit ROOM;

void create()
{
        set("short", "�����ɽ��");
        set("long", @LONG
�����Ǿ����ɽ���£���������Ϫ�����٣���ľ���ʣ���
��ɽ���������ɫ�������ġ� 
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "northup"   : __DIR__"shulin1",
               "southdown" : "/d/xiangyang/shanlu1",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
