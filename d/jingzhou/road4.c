#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
ɽ����ľï�ܣ�������䣬����羰������С����������
���ţ��������ҳ�ķ�϶���ս������γ���ʵİ�쵣������
�鲻�ɵĸ�������������С��ĸ�������ǰ��ȥ��
LONG);
        set("exits", ([
                "northeast" : __DIR__"road3",
                "westup" : __DIR__"qingshan2",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

