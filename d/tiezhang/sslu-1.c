inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
������һ������ʯ�̳ɵ�С·�ϡ�����ɽ�Ƶͻ��������˴��̵�ë��
����΢�紵�������Ա�����һƬɳɳ����
LONG    );
        set("exits", ([
                "eastup" : __DIR__"sslu-2.c",
                "westdown" : __DIR__"pingtai",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();
        replace_program(ROOM);
}
