#include <ansi.h>
inherit RIVER;

void create()
{
        set("short", "��ˮ����");
        set("long", @LONG
��ˮ����Ҳ���൱���֣��Ա����ɿ�������һ����ֱ�Ĺ�
��ֱͨ�������˵���紾�ӣ�·�Լ������������������Ҷ���
����ġ��ơ���ӭ��Ʈ�εΪ׳�ۡ�Ҳ�в���С����·��
������ѱ棬ȴҲ����ʢ����ȴ��
LONG);
        set("arrive_room", "/d/shaolin/hanshui1");
        set("exits", ([
                "north" : __DIR__"nanyang",
        ]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

        set("objects", ([
                __DIR__"npc/chuanfu1" : 1,
        ]));

        set("outdoors", "nanyang");
        setup();
        replace_program(RIVER);
}