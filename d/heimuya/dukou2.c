#include <ansi.h>
inherit RIVER;

void create()
{
        set ("short", "���Ŷɿ�");
        set ("long", @LONG
�ɿ�ǰ������ӿ���ȵĻƺ� (river)�ˡ�������������ɳ
���£�������������ɴ������������ڲ����д��У���Ϊ��
�ա����˻ƺӣ����������ˡ�
LONG);
        set("arrive_room", "/d/heimuya/dukou1");
        set("exits", ([
                "southwest" : "/d/huanghe/huanghe_1",
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