#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "\n\n                ��     ��     ʥ     ��" NOR);
        set("long", HIY "\n\n"
"������ش����ţ����˽�����һ���տ��Ĵ���ӳ���������\n"
"������ؾ��Ǵ�˵�е�����ʥ���ˡ��������ĵذ��̨�׾�\n"
"ȫΪ�׽����������еƻ�Իͣ����ȵ���Ϣ��ʹ����͸������\n"
"�������Դ��ŵ�һ���������ߵĸ�̨�Ͽ��š�����ʥ��ĸ�\n"
"���֣���̨���ķ�����ӵ����һλ��ʮ�����ҵ�����߸߶�����\n\n" NOR
);

        set("exits", ([
                "down" : "/d/city/guangchang",
                "up"   : "/d/beijing/tiananmen",
                "west" : "/d/wizard/guest_room",
                "east" : "/d/city/kedian",
        ]));

set("no_fight", 1);
        set("valid_startroom", 1);
        set("sleep_room", 1);

        setup();
}

