inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ����ȵķ����Ϲ���һ������Сͭ�壬�����
�з�����ද����������
LONG);
        set("exits", ([
                "north" : __DIR__"huayuan",
                "south" : __DIR__"liangong",
        ]));
        set("objects", ([
                __DIR__"npc/guanjia" : 1,
        ]));
        set("outdoors", "baituo");
        setup();
        replace_program(ROOM);
}
