#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǵ����µ����������ǽ��������ŷ��洫����
���£���������𻨱���ׯ�ϡ�
LONG );
        set("exits", ([
                "northup" : __DIR__"zoulang2",
                "east"    : __DIR__"dadian",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/samu" : 1,
                __DIR__"npc/xiang-ke" : 3,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((! myfam || myfam["family_name"] != "������")
           && dir=="northup"
           && objectp(present ("samu huofo", environment(me)))) 
                return notify_fail(CYN "��ľ���˵������Ǵ�����"
                                   "���ӣ��������ڡ�\n" NOR);

        return ::valid_leave(me,dir);
}
