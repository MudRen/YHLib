inherit ROOM;

void create()
{
        set("short", "��ɽͤ");
        set("long", @LONG
���ڵ��˰�ɽͤ�������뵽ף�ڷ����۸̻߳����г̣���
ǡ����һ��֮����·��Сͤ��Ȼ�Ѽ��žã�����Ϊ����������
����ꡣ
LONG);

        set("exits", ([
               "southdown"  : __DIR__"shanlu4",
               "northwest"    : __DIR__"shanlu002",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "henshan");

        setup();
        replace_program(ROOM);
}

