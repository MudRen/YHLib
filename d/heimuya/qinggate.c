#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����ô���");
        set("long", @LONG
��������������µ������������õĴ��ţ���ǰ�ڷ�����
��ʯʨ��������������š���������վ��������װ���ӣ�˫��
���Ÿֵ��������ע������Χ��һ�С�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
                "northdown" : __DIR__"guang",
                "south" : __DIR__"dating3",
        ]));
        set("objects", ([
                __DIR__"npc/dizi5" : 2,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if (objectp(present("riyue dizi", environment(me)))
           && dir == "south"
           && me->query("family/family_name") != "�������")
                return notify_fail(CYN "���µ��ӽ�����ס��˵������������"
                                   "���صأ����˲������ڡ�\n" NOR);

        return ::valid_leave(me, dir);
}
