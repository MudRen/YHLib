#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������ں컨���ܶ��԰֮�µ�Сʯ�ݣ�ʯ��
�ڳ�����ù������Χ���ǿտ���ǽ������Ƕ�ż�յ�͵ƣ�ɢ��
��������ƵĹ��������Խ��ݵ�ʯ��(wall)�Ͽ���һЩͼ�Ρ�
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "up" : __DIR__"hh_xiaozhu",
        ]));
        set("item_desc",([
                "wall": WHT "\nʯ���Ͽ���һЩ������������ȭ"
                        "�����ҵ�С�ˣ��Ա߻���һЩע�͡�\n "
                        NOR,
        ]));

        setup();
}


void init()
{
        add_action("do_think", "think");
}

int do_think(string arg)
{
        object me;
        object weapon;
        me = this_player();

        if (! living(me)) return 0;

        if (! living(this_player()) || arg != "wall")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("unarmed", 1) < 50)
                return notify_fail("�㷢��ǽ�������ص�ȭ�����ڸ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query_skill("unarmed", 1) > 180)
                return notify_fail("�㷢��ǽ�������ص�ȭ�����ڷ�ǳ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query("jing") < 120)
                return notify_fail("�㾫���޷����С� \n");

        me->receive_damage("jing", 50 + random(60));

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", me->query("int"));

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ǽ�������ص�ȭ����"
                       "��������\n" NOR, me);
        write(HIC "��ԡ�����ȭ�š������µ�����\n" NOR);
        return 1;
}

