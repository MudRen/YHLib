
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ�
���ĵƹ�����ǿ�ֱ淽��ǽ�����������ʯ���������ģ���
�ϵ����������������Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ
ʫ�䡣
LONG
        );

        set("exits", ([
                "west" : __DIR__"mishi3",
                "east" : __FILE__,
                "north" : __FILE__,
                "south" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
