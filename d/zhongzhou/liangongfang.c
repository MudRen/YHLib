inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������ϷԺ����Ա�������������ڵ������ź��ĵ�̺
�м�����Ա�������������������������һ������ǰ�����
���������ġ��㿴�����ǲ���Ҳ�붯�����ӹǣ�����
LONG);

        set("exits", ([
                "north" : __DIR__"xiyuan",
        ]));
        set("objects", ([
                "/d/beijing/npc/xizi1" : 1,
                "/d/beijing/npc/xizi3" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

