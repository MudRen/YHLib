

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ�
���ĵƹ�����ǿ�ֱ淽��ǽ�����������ʯ���������ģ���
�ϵ����������������Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ
���š�
LONG
        );

        set("exits", ([
                "south" : __DIR__"mishi3",
                "north" : __FILE__,
                "west" : __FILE__,
                "east" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
