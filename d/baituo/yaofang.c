inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
���Ǽ�ҩ������ǽ����ֻ��ҩ���������������ӣ��ϱ�
��������ҩ�õ�ƿƿ�޹ޡ���ҩʦ��λС����������﷢��
��֪����ʲô�����������ɵĳ��ȡ�
LONG);
        set("exits", ([
                "north" : __DIR__"changlang",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoqing" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
