inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǰ���ɽ���ӵ��������������м������䣬�������ҡ�
������������������գ����Բ��������˴����
LONG);
        set("exits",([
                "west" : __DIR__"liangong",
        ]));

        set("objects",([
                __DIR__"npc/trainer" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
