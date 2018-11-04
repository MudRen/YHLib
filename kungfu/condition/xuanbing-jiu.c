// xuanbing-jiu.c
// by vin

#include <ansi.h>
inherit F_CLEAN_UP;

string chinese_name() { return "�����̻�ƶ���"; }

int dispel(object me, object ob, int duration)
{
        int f, n, lvl;
        f = me->query_skill_mapped("force");
        lvl = me->query_skill("force");

        if (me != ob)
        {
                tell_object(ob, "��ֻ��" + me->name() + "������ʹ���Ⱥ�������"
                                "�����ܵø�Ϊ���ң���ʱ��ǰһ�ڡ�\n");

                tell_object(me, "����ͼ����" + ob->name() + "�ⶾ��ȴ���ֶԷ�"
                                "�Ⱥ����������������������ɴ󾪣���æס�֡�\n");

                if (living(ob))
                        ob->unconcious();

                return -1;
        }

        if (me->query_skill_mapped("force") != "luohan-fumogong")
        {
                tell_object(me, HIB "�����ȫ�����" HIW "����" NOR +
                                HIB "������" HIR "����" NOR + HIB "��"
                                "ȫȻ�޷�����Ϣ���ۡ�\n" NOR);
                return -1;
        }

        if (me->query_skill("luohan-fumogong", 1) < 180)
        {
                tell_object(me, HIB "�㷢�������" + to_chinese(f) +
                                HIB "��Ϊ���㣬���Խ����ڵ���������"
                                "�������͡�\n");
                return -1;
        }

        n = me->query_condition("xuanbing-jiu") - lvl / 15;

        tell_object(me, "��ĬĬ������" + to_chinese(f) + "��������"
                        "������������\n");

        if (n < 1)
        {
                me->clear_condition("xuanbing-jiu");

                if (me->can_improve_skill("force"))
                        me->improve_skill("force", 3000);

                if (me->can_improve_skill("luohan-fumogong"))
                        me->improve_skill("luohan-fumogong", 3000);

                if (me->add("can_perform/luohan-fumogong/jiu", 1 + random(5)) < 100)
                {
                        tell_object(me, HIC "\nͻȻ���㷢����������������"
                                        "���������ڣ�˵������������á�\n"
                                        "\n" NOR);
                } else
                {
                        me->set("skybook/item/xuanbingjiu", 1);
                        tell_object(me, HIW "\n�㷢����������������������"
                                        "���ڣ���ʹ���ڹ��ﵽ��һ��ǰ��δ"
                                        "�еľ��硣\n\n" HIC "����޺���ħ"
                                        "�������µ�����\n" NOR);
                        tell_object(me, HIC "��ѧ���ˡ�" HIW "��" HIR "��"
                                        HIW "������" HIC "����\n" NOR);
                        if (me->can_improve_skill("force"))
                                me->improve_skill("force", 1500000);
                        if (me->can_improve_skill("force"))
                                me->improve_skill("force", 1500000);
                        if (me->can_improve_skill("force"))
                                me->improve_skill("force", 1500000);
                        if (me->can_improve_skill("luohan-fumogong"))
                                me->improve_skill("luohan-fumogong", 1500000);
                        if (me->can_improve_skill("luohan-fumogong"))
                                me->improve_skill("luohan-fumogong", 1500000);
                        if (me->can_improve_skill("luohan-fumogong"))
                                me->improve_skill("luohan-fumogong", 1500000);
                        me->improve_skill("martial-cognize", 1500000);
                        me->improve_skill("martial-cognize", 1500000);
                        me->improve_skill("martial-cognize", 1500000);
                        tell_object(me, "\n");
                }
        } else
                me->apply_condition("xuanbing-jiu", n);

        return 1;
}

int update_condition(object me, int duration)
{
	int limit;

	if (! living(me) && (me->query("eff_qi") < 20
           || me->query("eff_jing") < 10))
        {
                me->set_temp("̰�������̻�ƣ���Ϣ���Ҷ���");
		me->die();
		return 0;
	} else
        {
                me->receive_wound("qi", 20);
                me->receive_wound("jing", 10);

                if (me->query("max_neili"))
                        me->add("max_neili", -1);

                switch (random(3))
                {
                case 0:
                        tell_object(me, HIR "ͻȻ����ֻ�����ﴦ������գ�ȫ��"
                                        "�����ĵ�������Ҫ���ѿ�һ�㡣\n" NOR);
                        message("vision", HIR "����" + me->name() + HIR "�뷢"
                                "����ȫ��ɢ���Ź���������˻����ɤ���Һ���\n"
                                NOR, environment(me), me);
                        break;

                case 1:
                        tell_object(me, HIW "��ʱ��ֻ����ͬ����������������"
                                        "˲���α�ȫ��˵���������ܡ�\n" NOR);
                        message("vision", HIW "����" + me->name() + HIW "ɢ��"
                                "��˿˿������ȫ�����¾�Ȼ��������һ�㱡����\n"
                                NOR, environment(me), me);
                        break;

                default:
                        tell_object(me, HIB "��ֻ�����ﴦ���������໥�ִ�����"
                                        "��" HIW "����" NOR + HIB "������" HIR
                                        "����" NOR + HIB "���಻���ԡ�\n" NOR);
                        message("vision", HIB "ͻȻ" + me->name() + HIB "һ��"
                                "��Х������Ť���ò����������ڵ��ϲ�ס������\n"
                                NOR, environment(me), me);
                        break;
                }
	}

        if (me->query("max_neili") < 1)
                me->set("max_neili", 0);

	me->apply_condition("xuanbing-jiu", duration - 1);

	if (! duration)
                return 0;

	return 1;
}
