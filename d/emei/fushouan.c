inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������ˮ���ϣ���һ���������Ե�ɮ�˽���ġ���ǰ
�о������������أ����������ڴ����������۾���ʫ����ӽ��
̾��֪Ϧ�ա��������꺣���������ٲ���ߴ�ʮ���ɡ�
LONG);
        set("objects", ([
                CLASS_D("emei") + "/zhen" : 1,
                __DIR__"npc/girldizi" : 1,
        ]));
        set("exits", ([
                "enter" : __DIR__"lingwenge",
                "north" : __DIR__"shenshuian",
        ]));
        set("outdoors", "emei");
        setup();
        replace_program(ROOM);
}
