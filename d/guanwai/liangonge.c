// liangonge.c ������

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�����Ƕ��������������������һЩ�����߳��õ�ľ�ˡ�
LONG );
        set("exits", ([
                "west" : __DIR__"liangong",
        ]));
        set("for_family", "�������");
        setup();
	replace_program(ROOM);
}
