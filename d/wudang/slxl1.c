inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
����ɽ�������е�С·�����߳�������ĺ�������ֻ�ܿ�
��һ����ա�·���е�ʿ�ڷ�������������ͨ�����������
�߿ɻش����
LONG);
        set("outdoors", "wudang");
        set("exits", ([
                "west" : __DIR__"slxl2",
                "east" : __DIR__"wdroad10",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
