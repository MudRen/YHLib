#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "׺����");
        set("long", @LONG
�����ճ���ױ���ĵط�������һ�ź�ľ��ױ̨��������
�����һ������ͭ������ױ̨��ɢ����һЩ��֬���ۡ�̨��
���Ŷ����һ����ɻ��ң�����������ˮ�������İ׾ա�
LONG);
        set("exits", ([
                "west" : __DIR__"changl14",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
