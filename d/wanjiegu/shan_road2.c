inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ��ɽ��С·������ɽ�������������ľ�����紵��
����ɳɳ��������·����������Ӳݣ��������������߶���
LONG);
        set("outdoors", "wanjiegu");
        set("exits", ([
            "westdown" : __DIR__"shan_road3",
            "eastdown" : __DIR__"shan_road1",
        ]));
        setup();
        replace_program(ROOM);
}
