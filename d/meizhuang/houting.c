#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�ɽ÷ׯ�ĺ������������൱�Ŀ����������ܵ�ǽ����
�����˸������˵��漣����������һ�����߼��ݵĺ������ߣ�������
ü��Ŀ�㣬ֻ����ɫ���ף��ƺ���һ�߽�ʬģ��������һ��֮�£���
�б�е�һ�����⡣����������һ�����ȡ�
LONG
        );
        set("exits", ([
            "south" : __DIR__"zoulang3",
        ]));

        set("objects", ([
                CLASS_D("meizhuang") + "/heibai" : 1,
        ]));

        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
        "/clone/board/meizhuang_b"->foo();
        replace_program(ROOM);
}
