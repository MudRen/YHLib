
inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
�������У���ֻ����������һ�ɵ������̣����ż����
���㣬�������������һȺ���ɫ���۷��������Է�����ȥ��
�������Ĩ��߾���ï�ܵ����֡�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west"   : __DIR__"shulin0",
                "north"  : __DIR__"shulin4",
                "south"  : __FILE__,
                "east"   : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
