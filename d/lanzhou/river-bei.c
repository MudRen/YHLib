#include <ansi.h>
inherit RIVER;

void create()
{
        set ("short", "�ƺӱ���");
        set ("long", @LONG
�������˻ƺ� (river)�İ��ߣ�ֻ����ɫ�ĺ�ˮ��ӿ����
����ȥ��������й���ĸ�׺ӡ����ƺӡ��㿴��һ�����ܣ���
�ò�Զ����һ��СС�Ķɿڣ��պ���һ�Ҷɴ��������Ѿ��м�
���ˣ��ϴ����������㣬������������Ժ������Ҫ�����ˡ�
LONG);
        set("arrive_room", "/d/lanzhou/river-nan");
        set("exits", ([
                "north" : "/d/huanghe/xiaojiaqiao",
        ]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu",
        }));
        set("outdoors", "lanzhou");
        setup();
        replace_program(RIVER);
}