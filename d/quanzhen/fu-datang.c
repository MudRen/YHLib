#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���Ҵ���");
        set("long", @LONG
�����Ǻ�Ա��ҵĴ��ã������Ϲ���һ���ҡ����ڰڷ���
Щ�����������ӣ�����÷����յ��������ҳ��������÷����
�����Ҳ�����Ǹ�ӹ���ŵı��������ѡ�
LONG);
        set("exits", ([
                "east" : __DIR__"fu-ceting",
                "west" : __DIR__"fu-zhangfang",
                "north" : __DIR__"fu-xiaoyuan",
                "south" : __DIR__"fu-houyuan",
        ]));
        setup();
        replace_program(ROOM);
}
