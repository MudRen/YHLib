inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
���Ǿ���ȵ��鷿��������������ذڷ��Ÿ����鼮����
��������һ�����л��Ƶ�������һ�ž��µ�ľ�Ρ�
LONG);
        set("exits", ([
               "east"    : __DIR__"changlang1",
               "north"   : __DIR__"huohuanshi",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
