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
        set("arrive_room", "/d/heimuya/dukou2");
        set("exits", ([
                "north" : __DIR__"road4",
        ]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu",
	}));

    	set("no_clean_up", 0);
    	set("outdoors", "heimuya");
        setup();
        replace_program(RIVER);
}