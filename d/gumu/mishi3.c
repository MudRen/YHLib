
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ�
���ĵƹ�����ǿ�ֱ淽��ǽ�����������ʯ���������ģ���
�ϵ����������������Դ����ҳ�һ˿��϶��ǽ�Ϻ������һЩ
ͼ�Ρ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"mishi4",
                "north" : __DIR__"mishi5",
                "south" : __DIR__"mishi6",
                "west" : __DIR__"mishi2",
        ]));

        setup();
        replace_program(ROOM);
}
