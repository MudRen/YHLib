#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǵ����µĶ�����������̬�����ʮ���޺�����
������⣬����ׯ�ϡ�
LONG );
        set("exits", ([
                "northup" : __DIR__"zoulang1",
                "west"    : __DIR__"dadian",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/jiamu" : 1,
                __DIR__"npc/xiang-ke"       : 3,
        ]));
        setup();

}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((! myfam || myfam["family_name"] != "������")
           && dir=="northup"
           && objectp(present ("jiamu huofo", environment(me))))
                return notify_fail(CYN "��ľ���˵�������Ǵ����µ�"
                                   "�ӣ��������ڡ�\n" NOR);

        return ::valid_leave(me, dir);
}
