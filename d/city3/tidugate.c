#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ᶽ����");
	set("long", @LONG
������ᶽ���š�Ρ����ΰ�ĳ�ǽ�ϣ��ɶ��ᶽ�������
��ʮ�����ۣ����ƻԻ͡������ױ��������ԡ�
LONG);
        set("outdoors", "chengdu");
	set("exits", ([
	    "south" : __DIR__"guangchang",
	    "north" : __DIR__"tidufu",
	]));
	set("objects", ([
	    __DIR__"npc/qinbing" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
        object bing;

        bing = present("qin bing", environment(me));
        if (dir != "north" || ! objectp(bing) || ! living(bing))
                return ::valid_leave(me, dir);

        if (me->query("weiwang") >= 10000)
        {
                message_vision(CYN "$N" CYN "Ц����" + RANK_D->query_respect(me) +
                               "�������������ȥ����ͨ����\n" NOR, bing, me);
                return ::valid_leave(me, dir);
        }

        if (me->query("special_skill/trick"))
        {
                message_vision(CYN "$N" CYN "����$n" CYN "���˹�����������ס��ȴ"
                               "��$n" CYN "һ���Ϻȣ�����ɢ����\n$N" CYN "���ɵ�"
                               "����һ����ڨڨ�Ĳ���˵����\n" NOR, bing, me);
                return ::valid_leave(me, dir);
        }

	return notify_fail(CYN "�ױ���ǰ��ס�㣬����˵������λ" +
                           RANK_D->query_respect(me) + "��ذɡ���ү�����͡�\n" NOR);
}
