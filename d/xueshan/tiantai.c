inherit ROOM;

void create()
{
        set("short", "��̨");
        set("long", @LONG
�����Ǵ����µĸߴ������߿ɼ���ΰ�Ĵ�ѩɽ���ϱ߿���
��������羵��ʥ����
LONG);
        set("exits", ([
                "west" : __DIR__"chanshi",
        ]));

        set("objects", ([
                CLASS_D("xueshan") + "/huodu" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
