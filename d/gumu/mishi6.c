
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ�
���ĵƹ�����ǿ�ֱ淽��ǽ�����������ʯ���������ģ���
�ϵ����������������Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ
����
LONG
        );

        set("exits", ([
                "east" : __FILE__,
                "north" : __DIR__"mishi3",
                "south" : __DIR__"mishi7",
                "west" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
