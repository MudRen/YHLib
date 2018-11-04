#include <ansi.h> 

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
���������˷���鷿����������������Ķѷ��Ÿ����鼮��
�鷿����������һ�Ű�̨����̨�ϰ��ż���̯������ᣬ��
�߻���δȼ���������ƺ����˷ﳣ����������ҹ����ǽ����
�����ż���ͼ(tu)�������ǳ������˷ﱾ�˵��ֱʡ�
LONG);
	set("exits", ([
  		"north" : __DIR__"miaojia_houting",
	]));
	set("no_clean_up", 0);
        set("item_desc", ([
                "tu" : HIC "\nֻ��ͼ���л���һЩ���ڴ򶷵�С�ˣ�����"
                       "���Ʒ��йء�\n" NOR,
        ]) );
	setup();
}

void init()
{
        add_action("do_think", "think");
        add_action("do_canwu", "canwu");
}

int do_think(string arg)
{
        object me;
        object weapon;
        me = this_player();

        if ( ! living(me)) return 0;

        if ( ! living(this_player()) || arg != "tu" )
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("strike", 1) < 30 ||
           (int)me->query_skill("chongtian-zhang", 1) < 30)
                return notify_fail("�㷢��ͼ�������ص��Ʒ����ڸ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query_skill("strike", 1) > 149 &&
           (int)me->query_skill("chongtian-zhang", 1) > 149)
                return notify_fail("�㷢��ͼ�������ص��Ʒ����ڷ�ǳ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query("jing") < 50)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        me->receive_damage("jing", 30);

        if ((int)me->query_skill("strike", 1) < 150 &&
           me->can_improve_skill("strike"))
                me->improve_skill("strike", me->query("int") * 3 / 2);

        if ((int)me->query_skill("chongtian-zhang", 1) < 150 &&
           me->can_improve_skill("chongtian-zhang"))
                me->improve_skill("chongtian-zhang", me->query("int") * 3 / 2);

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ͼ�������ص��Ʒ���"
                       "��������\n" NOR, me);
        write(HIC "��ԡ������Ʒ����͡��׺׳����ơ������µ�����\n" NOR);
        return 1;
}

int do_canwu(string arg)
{
        object me = this_player();
        object ob;
        object ob1;

        if (arg != "wall" && arg != "shu")
                return notify_fail("��Ҫ����ʲô��\n");

        if ((int)me->query("can_perform/panlong-zhao/tan"))
                return notify_fail(WHT "�����ַ��İ�̨�ϵ��鼮��������"
                                   "���Ѿ�ûʲô����ֵ���о��ˡ�\n" NOR);

        if (! (int)me->query_skill("panlong-zhao"))
                return notify_fail(WHT "�����ַ��İ�̨�ϵ��鼮��������"
                                   "�������صĶ���������ϰ����ѧûʲô"
                                   "�ϸ𣬲��򲻳�ʲô��\n" NOR);

        if ((int)me->query_skill("panlong-zhao", 1) < 130)
                return notify_fail(WHT "�����ַ��İ�̨�ϵ��鼮��������"
                                   "�������ص�צ�����Ǿ����ȴ��̫��"
                                   "��£��Լ�һʱ�޷�����\n" NOR);

        if (me->is_busy())
                return notify_fail("���������ڲ����С�\n");

        if (me->query("potential") < me->query("learned_points") + 10) 
                return notify_fail("���Ǳ�ܲ����ˣ����򲻳�ʲô��\n");

        if ((int)me->query("jing") < 30)
                return notify_fail("��̫ƣ���ˣ���Ϣһ�°ɡ�\n");

        if (random(20) < 18)
        {
                me->receive_damage("jing", 25);
                me->add("learned_points", 10);
                me->start_busy(2);
                message_vision(WHT "$N" WHT "��ϸ������̨�ϵ�����鼮"
                               "���Ķ�����ÿ��ϸ�ڡ�\n" NOR, me);
                tell_object(me, HIY "���Խ������צ���˸������⣬��"
                               "�����һ���Ĳ���\n" NOR);
                return 1;
        } else
        { 
                me->receive_damage("jing", 25);
                me->add("learned_points", 10);
                me->start_busy(2);
                message_vision(WHT "$N" WHT "��ϸ������̨�ϵ�����鼮"
                               "���Ķ�����ÿ��ϸ�ڡ�\n" NOR, me);

                tell_object(me, HIY "�������ã���Ȼ����˫Ŀһ��������"
                                "���������м���Խ����\n��צ������̽צ"
                                "�������İ��أ�\n" NOR + HIC "��ѧ����"
                                "������̽צ����\n" NOR);
                if (me->can_improve_skill("claw"))
                        me->improve_skill("claw", 1500000);
                if (me->can_improve_skill("claw"))
                        me->improve_skill("claw", 1500000);
                if (me->can_improve_skill("claw"))
                        me->improve_skill("claw", 1500000);
                if (me->can_improve_skill("panlong-zhao"))
                        me->improve_skill("panlong-zhao", 1500000);
                if (me->can_improve_skill("panlong-zhao"))
                        me->improve_skill("panlong-zhao", 1500000);
                if (me->can_improve_skill("panlong-zhao"))
                        me->improve_skill("panlong-zhao", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->set("can_perform/panlong-zhao/tan", 1);
        }

        return 1;
}

