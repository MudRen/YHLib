inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�ͨ����������ң����ﾲ���ĵģ�û��ʲô
����������������������ɽ�����������գ�����������������
ֻ����һ��������
LONG);
        set("no_fight", 1);
        set("exits", ([
               "south" : __DIR__"guofu_dating",
               "north" : __DIR__"guofu_huayuan",
        ]));
        set("objects", ([
           	__DIR__"npc/yahuan" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
