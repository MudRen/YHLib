inherit ROOM;

void create()
{
        set("short", "���۵�");
        set("long", @LONG
�����Ǳ����´��۵�������Ƕ���ɽ�����Ժ֮һ����
�۵��ڹ��Ž��Ӳӵķ�������������
LONG);
        set("objects", ([
                __DIR__"npc/guest" : 2,
        ]));

        set("exits", ([
                "out"   : __DIR__"bgs",
                "west"  : __DIR__"bgschanfang",
                "north" : __DIR__"cangjinglou",
        ]));
        setup();
        replace_program(ROOM);
}
