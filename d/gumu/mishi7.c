
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ�
���ĵƹ�����ǿ�ֱ淽��ǽ�����������ʯ���������ģ���
�ϵ����������������Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ
���ݡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"mishi8",
                "north" : __DIR__"mishi6",
                "south" : __FILE__,
                "west" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}
