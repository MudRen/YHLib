inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ
��֬��֮�������ݣ�����������ͨ�����������ޡ�
LONG);
        set("exits", ([
                "northeast" : "/d/city/ximenroad",
                "southwest" : __DIR__"road2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "city");

        setup();
        replace_program(ROOM);
}

