#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long", @LONG
ɽ·�е������Ȼ��ÿ���������ǰ������һƬ�ܴ�Ĺ㳡��һЩ��
�ư�ĵ������ش�������䣬�Եú�æµ���ڹ㳡����Χ�кܶ���ʯ���ķ�
�ӡ��������������Եøߴ���ΰ������ķ����в�ʱ��ӿ��������������
�仹�����Źķ��������
LONG    );
        set("exits", ([
                "south" : __DIR__"shanlu-2",
                "west" : __DIR__"lgfang",
                "east" : __DIR__"guajia",
                "northup" : __DIR__"wztang",
        ]));

        set("objects", ([
                __DIR__"npc/huiyi" : 1,
                __DIR__"npc/heiyi" : 2,
                CLASS_D("tiezhang") + "/fen" : 1,
        ]));

        set("valid_startroom", 1);
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");

        setup();

        "/clone/board/tiezhang_b"->foo();
}

int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();
        if(dir == "northup")
        {
                if ( (string)me->query("family/family_name") != "���ư�"
                   & objectp(present("feng yong", environment(me)))
                   & ! me->query("move_party/����ȡ����ư�", 1) )
                        return notify_fail(CYN "��������һ�Σ���Ȼ��ס�㣬����˵������λ" +
                                           RANK_D->query_respect(me) + CYN "���Ǳ�����ӣ�"
                                           "�ݵ��ڱ����Ҵ���\n" NOR);
        }
        return ::valid_leave(me, dir);
}
