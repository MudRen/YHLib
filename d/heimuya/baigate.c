#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�׻��ô���");
        set("long", @LONG
������������µڶ����ð׻��õĴ��ţ���ǰ�ڷ�������
ʯʨ��������������š���������վ��������װ���ӣ�˫����
�Ÿֵ��������ע������Χ��һ�С�
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
                "west" : __DIR__"dating2",
                "east" : __DIR__"baigate1",
        ]));
        set("objects", ([
                __DIR__"npc/dizi4" : 2,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if (objectp(present("riyue dizi", environment(me)))
           && dir == "west"
           && me->query("family/family_name") != "�������")
                return notify_fail(CYN "���µ��ӽ�����ס��˵������������"
                                   "���صأ����˲������ڡ�\n" NOR);

        return ::valid_leave(me, dir);
}
