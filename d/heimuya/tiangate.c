#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����ô���");
        set("long", @LONG
������������µ��Ĵ��������õĴ��ţ���ǰ�ڷ�������
ʯʨ��������������š���������վ��������װŮ�ӣ����ֳ�
�ų��ޣ������ע������Χ��һ�С�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            	"south" : __DIR__"dating4",
            	"north" : __DIR__"tianroad2",
        ]));
        set("objects", ([
                __DIR__"npc/dizi6" : 2,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if (objectp(present("riyue dizi", environment(me)))
           && dir == "south"
           && me->query("family/family_name")
           && me->query("family/family_name") != "�������")
                return notify_fail(CYN "���µ��ӽ�����ס��˵������������"
                                   "���صأ����˲������ڡ�\n" NOR);

        return ::valid_leave(me, dir);
}
