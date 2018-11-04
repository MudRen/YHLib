#include <ansi.h> 
inherit ROOM;

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG
�����ĳ�����������ϸϸ�Ļ����������ʺ����䡣�����м����ھֵ���ʦ
�������䡣�����һλ�ܼҴ��������ڱ����ֹۿ�������ʱ����ǰȥָ��
һ�������ر��Ϲ��ż�����ɳ��(shadai)����֪��ʲô�ô���
LONG);

        set("item_desc", ([
                "shadai" : WHT "�������ص�ɳ�����������Ŵ��(jida)����\n" NOR,
        ]));

        set("exits", ([
                "out"   : __DIR__"gate",
                "north" : __DIR__"front_yard2",
                "east"  : __DIR__"majuan",
                "west"  : __DIR__"zhangfang",
        ]));

        setup();
}

void init()
{
  	add_action("do_jida", "jida");
}

int do_jida(string arg)
{
        object me;
        object weapon;
        me = this_player();

        if (! living(me) || arg != "shadai")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ�š�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail(WHT "��������б�����ɳ����ȥ�����ꡱ��һ��ɳ��Ӧ"
                                   "�����ƣ������ɳ����һ�ء�\n" NOR);

        if ((int)me->query_skill("cuff", 1) < 30
           || (int)me->query_skill("strike", 1) < 30)
                return notify_fail("�������죬�ֶ�������ˣ��ɻ���ʲô��ûѧ������"
                                   "����ȭ�Ƶȼ�̫�͵�Ե�ʡ�\n");

        if ((int)me->query_skill("cuff", 1) >= 120
           && (int)me->query_skill("strike", 1) >= 120)
                return notify_fail("�����ɳ��������һ��������������Ѿ����������ʲ"
                                   "ô�ˡ�\n");

        if ((int)me->query("qi") < 40)
                return notify_fail("�������۵ø첲��̧�������ˣ�����Ϣһ����ɡ�\n");

        me->receive_damage("qi", 30);

        if (me->can_improve_skill("cuff")
           && (int)me->query_skill("cuff", 1) < 120)
                me->improve_skill("cuff", me->query("con") * 2);

        if (me->can_improve_skill("strike")
           && (int)me->query_skill("strike", 1) < 120)
                me->improve_skill("strike", me->query("con") * 2);

        me->start_busy(random(2));
        message_vision(WHT "\n$N" WHT "վ������һ��һȭ����ɳ������������\n" NOR, me);
        write(HIC "���ڻ�������������˲��١�����ȭ�������������Ʒ��������š�\n" NOR);
        return 1;
}
