inherit ROOM;

void create()
{
        set("short", "��ͷ��");
        set("long", @LONG
һ��޴����ʯ����ȥ����һ����ͷ���Ŵ���Ѫ������
�������������ڲ�ľ���С�
LONG);
        set("objects", ([
                "/clone/quarry/laohu" : 1,
        ]));
        set("exits", ([
                "northdown" : __DIR__"wulaofeng",
                "southup"   : __DIR__"chaotiangong",
        ]));

        set("outdoors", "wudang");
        setup();
        replace_program(ROOM);
}
