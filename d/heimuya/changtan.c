#include <ansi.h>
inherit RIVER;

void create()
{
        set("short", "��̲");
        set("long", @LONG
��Ƭ��̲��ʱ�����½̽��ڳ˴�������̲ͷ����һ������
�̵����ġ�����Ľ� (river)�ϻ��ż���������̵�С������
���Ĵ�ֻ�ܶ࣬���ǲ�û�д���������ͣ����Ҫ���԰�ֻ�п�
���½��Լ��Ĵ�ֻ�ˡ�
LONG);
        set("arrive_room", "/d/heimuya/xingxingtan");
        set("exits", ([
                "westup"   : __DIR__"shandao1",
        ]));
        set("objects", ([
                __DIR__"npc/huang" : 1,
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

