#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
������һ����԰�е�Сͤ�ӣ�������������ɫ���㡣����
����һ���������轣ͼ����
LONG);

        set("exits", ([
                "south" : __DIR__"huating1",
                "west" : __DIR__"huayuan3",
        ]));

        set("item_desc", ([
                "tu": HIY "\n��ֻ��ͼ����Ů�ֳָֹ�����Ц��������㱼���"
                      "�ƺ���������\n������������������������ƺ�������"
                      "ĳ�ְ��ء�\n\n" NOR,
        ]));
        setup();
}

void init()
{
        add_action("do_think", "think");
}

int do_think(string arg)
{
        object me = this_player();
        int add;

        if (me->query("special_skill/clever"))
                add = me->query_int() * 4;
        else
                add = me->query_int() * 3;

        if (! living(me) || arg != "tu")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("sword", 1) < 30)
                return notify_fail("��Ļ���������򲻹����޷�����ͼ��"
                                   "�ϵĽ�����\n");

        if ((int)me->query_skill("jinwu-goufa", 1) < 30)
                return notify_fail("�㷢��ͼ�������صĽ���������£���"
                                   "��һʱ������ᡣ\n");

        if ((int)me->query_skill("jinwu-goufa", 1) > 150)
                return notify_fail("�㷢��ͼ�������صĽ������ڷ�ǳ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query("jing") < 25)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        me->receive_damage("jing", 20);

        if (me->can_improve_skill("jinwu-goufa"))
                me->improve_skill("jinwu-goufa", add);

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ͼ�������صĽ�����"
                       "��������\n" NOR, me);
        write(HIC "��ԡ����ڹ����������µ�����\n" NOR);
        return 1;
}
