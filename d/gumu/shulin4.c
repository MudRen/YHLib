
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
                "north"  : __DIR__"kongdi",
                "south"  : __DIR__"shulin0",
                "east"   : __DIR__"shulin6",
                "west"   : __DIR__"shulin5",
        ]));

        setup();
        replace_program(ROOM);
}
