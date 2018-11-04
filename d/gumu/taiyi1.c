
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "̫�ҳ�");
        set("long", @LONG
����ǰ����һ��ɽ�����������������̫�ҳ�(chi)����
˵Ϊ���챦��������ɣ��������ܸ߷廷�У�����̲�������
ɽ��ˮӰ���羰ʮ��������
LONG);
        set("outdoors", "quanzhen");
        set("item_desc", ([
                "chi" : HIG "\n����һ���ܴ��ɽ������̲���������ˮ��\n"
                            "�����ף������̲�ס����(jump)��ȥ����һ����\n" NOR,
        ]));
        set("exits", ([
                "southup"   : __DIR__"shandao3",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));

        setup();
}
void init()
{
        add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me = this_player(); 

        if( !arg || arg != "chi")
        {
                write("����������ѽ? \n");
                return 1;
        }

        message_vision(HIC "\n$N "HIC "��̫�ҳ�����ȥ��\n", me);
        me->move("/d/gumu/taiyi2");
        message_vision(HIW "\n$N" HIC "������̫�ҳ�������\n", me);
        return 1;
}
