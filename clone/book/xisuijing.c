// xisuijing.c ϴ�辭

inherit ITEM;

#include <ansi.h>

int do_study(string);

string* skill = ({
        "whip",
        "finger",
        "hand",
        "cuff",
        "claw",
        "strike",
});

void create()
{
        set_name(YEL "ϴ�辭" NOR, ({ "xisui jing" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long","�Ȿ��ֽͲ�������������ѧ�伮���Ǵ�Ħ������ھ������׽һ��
��������ľ����伮��\n");
                set("value", 10);
                set("no_sell", 1);
                set("material", "paper");
        }
}

void init()
{
        add_action("do_study","canwu");
}

int do_study(string arg)
{
        object where;
        object ob = this_object();
        object me = this_player();
        int cost, exp;
        int i;

        where = environment(me);
        if (! arg || ! id(arg))
                return notify_fail("��Ҫ����ʲô��\n");

        if ((string)where->query("short") != "��ĦԺ��¥")
                return notify_fail("ϴ�辭ֻ���ڴ�ĦԺ�����\n");

        if (me->query_skill("literate", 1) < 100)
        {
                write("���ֽͲ������ȥ������ʲô����������\n");
                return 1;
        }

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (me->is_fighting())
                return notify_fail("���޷���ս����ר�������ж���֪��\n");

        exp = (int)me->query("combat_exp");
        if (exp < 300000)
        {
                write("���ʵս���鲻�㣬���ܲ���ϴ�辭��\n");
                return 1;
        }

        if (me->query("neili") < 100)
                return notify_fail("�������������㣬�޷�����"
                                   "ϴ�辭��ע�������ϳ��书��\n");

        me->add("neili", -10 - random(10));

        cost = 50 + random(50);
        if (me->query("jing") > cost)
        {
                for (i = sizeof(skill); i > 0; i--)
                {
                        if (me->query_skill(skill[i-1], 1) < 180 &&
                            me->query_skill(skill[i-1], 1) >= 100 &&
                            me->can_improve_skill(skill[i-1]))
                        {
                                me->improve_skill(skill[i-1], 5 + random(30));
                        }
                }
                write(sprintf("�����ϴ�辭�ϵľ��ģ��ƺ��е��ĵá�\n"));
                me->receive_damage("jing", cost);
        } else
        {
                me->set("jing", 0);
                write("�����ڹ���ƣ�룬�޷�ר����������ϴ�辭��\n");
        }
        return 1;
}

