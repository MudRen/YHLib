#include <ansi.h> 
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "xi");
}

void create()
{
        set_name(CYN "ħ������" NOR, ({"mozun sheli", "sheli"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", CYN "һ����Բ�İ�ɫ���壬ͨ��͸��������Ǵ�˵\n"
                            "�е�ħ����������ħ���������ഫ�����̲���\n"
                            "�ޱȾ޴���������书��ǿ�߿�����ȡ(xi)��\n"
                            "�е���������ǿ������\n" NOR);
                set("value", 1000000);
        }
        setup();
}

int do_eat(string arg)
{
        object ob;
        object me = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        if( me->is_busy() )
                return notify_fail("��������æ���ء�\n");

        if( me->query("power/ħ������") )
                return notify_fail("���Ѿ���ȡ��һ���ˣ����²����ٴξ��������ĳ����\n");

        message_vision (HIY "\n$N" HIY "��˫�ֽ�����סħ��������"
                        "ֻ��һ�ɹ�â����͸�����������Կ�����"
                        "�������߼䱼���ܶ���\n" NOR, me);
        me->start_busy(60);
        remove_call_out("xiqu1");
        call_out("xiqu1", 5, me);
        return 1;
}

void xiqu1(string arg)
{
        object ob;
        object me = this_player();

        message_vision(HIB "\nֻ��һ�ɹ�â��ħ������������$N" HIB
                       "�����ӡ���\n" NOR, me);
        remove_call_out("xiqu2");
        call_out("xiqu2", 4, me);
}

void xiqu2(string arg)
{
        object ob;
        object me = this_player();

        message_vision(HIY "\n�������һ�ɹ�â��$N" HIY "����"
                       "��������������ħ����������\n" NOR, me);
        remove_call_out("xiqu3");
        call_out("xiqu3", 4, me);
}

void xiqu3(string arg)
{
        object ob;
        object me = this_player();

        message_vision(HIR "\n����һ���������һ�ɹ�â��ħ������"
                       "������������������$N" HIR "�����塭��\n"
                       NOR, me);
        remove_call_out("xiqu4");
        call_out("xiqu4", 4, me);
}

void xiqu4(string arg)
{
        object ob;
        object me = this_player();

        message_vision(MAG "\n�漴�ּ�һ�ɹ�â��$N" MAG "������"
                       "ת��ħ����������\n" NOR, me);
        remove_call_out("xiqu5");
        call_out("xiqu5", 4, me);
}

void xiqu5(string arg)
{
        object ob;
        object me = this_player();

        message_vision(HIM "\nɲ�Ǽ�⻪���ǣ���â�ִ�ħ������"
                       "������$N" HIM "�����塭��\n" NOR, me);
        remove_call_out("xiqu6");
        call_out("xiqu6", 4, me);
}

void xiqu6(string arg)
{
        object ob;
        object me = this_player();

        message_vision(HIW "\nֻ��$N" HIW "������ͬʱ������"
                        "��ҫ�۵Ĺ⻪��ɲ�Ǽ�������ȣ�����"
                        "���ڣ��·�����ض��챻�ս�һ�㡭��\n" NOR, me);
        remove_call_out("xiqu7");
        call_out("xiqu7", 2, me);
}

void xiqu7(string arg)
{
        object ob;
        object me = this_player();
        int exp, pot, li1, li2, max;

        exp = 30000 + random(10000);
        pot = 5000 + random(3000);
        li1 = 300 + random(100);
        li2 = 300 + random(100);

        if ( me->query("max_neili") > 5000
          && me->query("max_jingli") > 1200
          && me->query("combat_exp") > 2000000
          && (int)me->query_skill("force") > 330
          && me->query("power/���ϱ�") )
        {
                message_vision(HIW "\n�⻪���ˣ��̼�$N" HIW "ȫ��Ө"
                               "��͸����������ʯ�����ƺ��Ѻ�ħ������"
                               "��Ϊһ���ˡ�\n\n" NOR, me);

                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("max_neili", li1);
                me->add("max_jingli", li2);
                if (me->query("potential") > me->query_potential_limit()) 
                me->set("potential", me->query_potential_limit());

                tell_object(me, HIY "��е�ħ�������е�����ԴԴ��������"
                                "������ĵ����ʱ��һ��˵�����������\n"
                                NOR);

                max = me->query("max_qi");
                me->set("eff_qi", max);
                me->set("qi", max);
                max = me->query("max_jing");
                me->set("eff_jing", max);
                me->set("jing", max);
                me->set("neili", me->query("max_neili"));
                me->set("jingli", me->query("max_jingli"));

                max = me->max_food_capacity();
                me->set("food", max);
                max = me->max_water_capacity();  
                me->set("water", max);
                me->clear_condition();
                me->set("power/ħ������", 1);

                tell_object(me, HIC "������" + chinese_number(exp) +
                                "�㾭�顢" + chinese_number(pot) + "��"
                                "Ǳ�ܡ�" + chinese_number(li1) + "����"
                                "��������" + chinese_number(li2) + "��"
                                "��\n������\n" NOR);
        } else
        {
                message_vision(HIR "\nֻ��$N" HIR "һ���ҽУ����ܲ�ס��"
                               "���ĳ������ʱȫ��������ϣ���Ѫ���磬��"
                               "�屻ը�˸����顣\n" NOR, me);
                me->set_temp("die_reason", "��ͼ��ȡħ�����������ȫ��������϶�����");
                me->die(); 
        }
        message_vision (WHT "\nħ�������ϵĹ⻪�������ţ������һ"
                        "�ѷ�ĩ��\n" NOR, me);
        destruct(this_object());
        return 0;
}

