
#include <ansi.h>
inherit ROOM;

int do_ci(string arg);
int do_zhan(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ�
���ĵƹ�����ǿ�ֱ淽��ǽ�����������ʯ���������ģ���
�ϵ����������������Դ����ҳ�һ˿��϶�����������ͣ�ͻȻ
�䷢��ǽ���ƺ��м���ש (brick)�߸�͹������Χ��ש�ܲ�
��г��
LONG
        );

        set("exits", ([
                "up" : __DIR__"hanshuitan",
        ]));

        set("item_desc", ([
        "brick": HIC "\n������ͨ����ש����������ʲô�ر�ġ�\n" NOR,
        ]) );

        setup();
}

void init()
{
        add_action("do_ci", "ci");
        add_action("do_zhan", "zhan");
}


int do_ci(string arg)
{
        object me=this_player();
        object weapon;

        if( !arg || arg != "brick" ) {
                return notify_fail("��Ҫ��ʲô��\n");
        }

        if (!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("Ҫ��ǽ���üһ���²��аɣ�\n");

        message_vision(HIG "\n$N" HIG "�γ����У�����ש�����ȥ��ֻ���ÿտ���������ש"
                       "����һͷ�·��ǿյġ�\n", this_player());

        me->set_temp("tmarks/ש",1);
        return 1;
}

int do_zhan(string arg)
{
        object me=this_player();

        if( !arg || arg != "brick" || me->query_temp("tmarks/ש",1) < 1) {
                return notify_fail("��Ҫճסʲô��\n");
        }

        message_sort(HIC "\n$N" HIC "˫�ֽ�����ש��ʹ����ճ���־�����������"
                     "�ؽ������שճ�˳��������ûճ������ש��ǽ���Ͼ��ֳ���"
                     "һ���󶴡�\n" NOR,this_player());

        set("exits/down",__DIR__"houting");

        remove_call_out("close");
        call_out("close", 5, this_object());

        me->set_temp("tmarks/ש",0);
        return 1;

}

void close(object room)
{
        message("vision", NOR + WHT"\n������һ������������¼�����ש����"
                "��ǽ�ϵĶ���ס�ˡ�\n" NOR, room);

        room->delete("exits/down");
}

