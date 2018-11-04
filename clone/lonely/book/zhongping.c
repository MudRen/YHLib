#include <ansi.h>
 
inherit ITEM;

void create()
{
        set_name(CYN "����ƽǹ�ס�" NOR, ({ "zhongping qiangpu", "zhongping", "qiangpu",
                                            "pu", "book" }));
        set_weight(500);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", CYN "����һ����������ᣬ��Ƥ��������д�С���ƽ"
                            "ǹ�����ĸ����֡�\n" NOR);
                set("value", 1);
                set("no_sell", "���⡭����ɶ��");
                set("material", "paper");
                set("skill", ([
                        "name" : "zhongping-qiang",
                        "exp_required" : 100000,
                        "jing_cost"  : 100,
                        "difficulty" : 40,
                        "max_skill"  : 149,
                        "min_skill"  : 0
                ]));
        }
}

void init()
{
        add_action("do_yanjiu", "yanjiu");
        add_action("do_yanjiu", "research");
}

int do_yanjiu(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        string pfm, book;
        int lv;

        if (! arg)
        {
                write("�о���ƽǹ��ָ���ʽ��research|yanjiu <����> from <��ƽǹ��>\n");
                return 1;
        }

        if (sscanf(arg, "%s from %s", pfm, book) != 2)
        {
                write("�о���ƽǹ��ָ���ʽ��research|yanjiu <����> from <��ƽǹ��>\n");
                return 1;
        }

        if (me->is_busy())
        {
                write("��������æ���ء�\n");
                return 1;
        }

        if (me->is_fighting())
        {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (where->query("no_fight") && me->query("doing") != "scheme")
        {
                write("���޷������ﾲ�������ж�ǹ�ס�\n");
                return 1;
        }

        if (! me->query_skill("literate", 1))
        {
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if (! id(book))
        {
                write("��Ҫ�о�ʲô��\n");
                return 1;
        }

        if (pfm != "ding")
        {
                write("ǹ���ϲ�û�м��������о��ľ��С�\n");
                return 1;
        }

        if ((int)me->query("combat_exp") < 100000)
        {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        if ((int)me->query("jing") < 100)
        {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }

        if (me->query("potential") < me->query("learned_points") + 10) 
        {
                write("���Ǳ�ܲ����ˣ��о�����ʲô��\n");
                return 1;
        }

        // ��ƽǹ�����ж����߷�
        if (pfm == "ding")
        {
                if ((int)me->query("can_perform/zhongping-qiang/ding"))
                {
                        write("���Ѿ�ѧ�������У����о�Ҳû�á�\n");
                        return 1;
                }

                if (! (int)me->query_skill("zhongping-qiang"))
                {
                        write("���о��˰��죬����ǹ�������صľ���������޹�ϵ��\n");
                        return 1;
                }

                if ((int)me->query_skill("zhongping-qiang", 1) < 120)
                {
                        write("�㷢��ǹ���ϼ��صľ��й�����£�һʱ�������ס�\n");
                        return 1;
                }

                if (random(20) < 18)
                {
                        message_vision(HIR "$N" HIR "��ϸ���ж�ǹ���ϼ��صľ��У���"
                                       "������\n" NOR, me);
                        tell_object(me, HIY "�����ƽǹ�����˸������⣬�������һ"
                                       "�����о���\n" NOR);
                } else
                { 
                        message_vision(HIR "$N" HIR "��ϸ���ж�ǹ���ϼ��صľ��У���"
                                       "������\n" NOR, me);
                        tell_object(me, HIY "�������ã���Ȼ����˫Ŀһ��������������"
                                        "ǹ���������ص���ƽǹ�������������߷����İ�"
                                        "�أ�\n" NOR + HIC "��ѧ���ˡ������߷�����\n" NOR);

                        if (me->can_improve_skill("club"))
                                me->improve_skill("club", 1500000);
                        if (me->can_improve_skill("zhongping-qiang"))
                                me->improve_skill("zhongping-qiang", 1500000);
                        me->improve_skill("martial-cognize", 1500000);
                        me->set("can_perform/zhongping-qiang/ding", 1);
                }
                me->receive_damage("jing", 80);
                me->add("learned_points", 10);
                me->start_busy(2);
                return 1;
        }
}
