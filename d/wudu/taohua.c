#include <ansi.h> 

inherit ROOM;

void create()
{
        set("short", HIM "�һ���" NOR);
        set("long", @LONG
��������ɽ��е�Ͽ���У�ɽ��ɽ��ȫ���ޱߵ�Ұ������һ��ɽ
�紵������Ӣ�ͷס����������µ��һ�����֦���ѻ��ڵ��ϣ�������
��������ġ��ս������ˣ�Զ����ɽ��֮���ƺ�Ʈ����һ������Խ
��ԽŨ��
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"wdsl1",
                "northwest" : __DIR__"xiao3",
        ]));

        setup();
}

int valid_leave (object who, string dir)
{
        if (dir == "northwest")
                return ::valid_leave(who, dir);
        else
        {
                if (userp(who)
                   && (string)who->query("family/family_name") != "�嶾��")
                {
                        if (! (present("xingjun san", who))
                           && who->query("max_neili") < 1000)
                        {
                                message_vision (HIM "ֻ��һ��Ũ��������Ϯ������$N"
                                                HIM "��ʱ����ͷ�ؽ��ᡣ\n" NOR, who);
                                who->receive_damage("qi", 50);
                                remove_call_out ("fall_down");
                                call_out ("fall_down", 1, who, environment(who));
                                who->start_busy(1, 1);
                                return notify_fail(HIR "�����ס�����˼��£�����ͻȻ"
                                                   "һ��\n\n" NOR);
                        } 
                }
        	return 1;
        }
}

void fall_down (object who, object where)
{
        who->move(where);
        this_player()->unconcious();
}

void fall_down1 (object who, object where)
{
        this_player()->unconcious();
}

