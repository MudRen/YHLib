inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǰ���ɽ���ӵ������⣬����ɽ���ӿ��Ե�����ȡ��
���õĸ����������������ɵ����ǲ���������ġ�
LONG);
        set("exits", ([
                "east" : __DIR__"yuanzi",
        ]));
        set("objects", ([
                __DIR__"npc/shiwei" : 1,
                __DIR__"obj/zheng" : 1,
                "/clone/weapon/gangzhang" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
