#include <ansi.h>
inherit RIVER;

void create()
{
        set ("short", "����̲");
        set ("long", @LONG
ֻ��һƬ��̲��ɽʯ�����Ѫ��ˮ���ļ��������������
����̲������Ľ� (river)�ϻ����ż���С����Ҫ�������Ҫ
���⼸��С���ˡ�
LONG);
        set("arrive_room", "/d/heimuya/changtan");
        set("exits", ([
                "southup" : __DIR__"shidao2",
        ]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu",
        }));
        set("outdoors", "heimuya");
        setup();
        replace_program(RIVER);
}