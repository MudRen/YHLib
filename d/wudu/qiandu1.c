#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "ǧ������");
        set("long", @LONG
�������嶾����������ĵط���ɽ������һ����Ȼ��ʯ��������
������Ŀ��������һ��ɽ�紵�������ŵ�һ����ζ������վ�ż���
�嶾�̵��ӡ� 
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"wdsl4",
                "north" : __DIR__"qiandu2",
        ]));
        set("objects", ([
                  __DIR__"npc/dizi": 4,
        ]));
    

        setup();
}

int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();

        if (dir == "north")
        {
                if ((string)me->query("family/family_name") != "�嶾��"
                & objectp(present("di zi", environment(me))))
                        return notify_fail(CYN "�嶾�̵��Ӻ�Ȼ��ס�㣬�����ȵ�����λ" +
                        RANK_D->query_respect(me) + "��ͷ���Ե����ʲô��\n" NOR);
        }
        return ::valid_leave(me, dir);
}
