inherit ROOM;

void create()
{
        set("short", "���׶���ԭ");
        set("long", @LONG
������ɽ���壬���������׶���ԭ�������������죬���
��������һ�����硣�����ѩ���ڣ����ⰻȻ������ѩ��ֱ��
������Ϫ���������Ұ������ɽ��ϰϰ������������ˮ��ɽ
������, �������Ҳ���ŵ�����Ļ��㡣
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
            "southdown" : __DIR__"huijiang2",
        ]));

        set("objects", ([
                "clone/quarry/lang"  : 1,
        ]));

        set("quarrys", ([
                "gou"   : 100000,
                "lang"  : 80000,
                "lang2" : 50000,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
