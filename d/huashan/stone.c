//Room: stone �������������ĵط�
//Modify by Rcwiz for hero.cd

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","��ʯ��");
        set("long",@LONG
�����ǻ�ɽ�ٲ��µ�һ����Ȼ�޴�ʯͷ�ϣ���Χ�����ļ���ˮ������
ӿ�ĸ�ɽ��ˮ��hongshui����й�����Ĵ��������ϡ�
LONG);
        set("outdoors", "huashan");
        set("can_practice_xiantie-jian", 1);
        set("item_desc", ([
                "hongshui" : HIW "��ˮ��ӿ�ޱȣ���ֻ����ʱ�п��ܱ���ˮ�嵽ˮ�С�\n" NOR,
        ]));
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump()
{
        object me = this_player();

        if (me->is_busy() || me->is_fighting())
              return notify_fail("��æ������˵�ɣ�\n");

        message_vision(HIG "$N" HIG "���������ٲ� ����\n", me);

        me->move(__DIR__"shanhongpb");

        return 1;
}

