#include <weapon.h>
#include <ansi.h>

inherit BLADE;

string do_wield();
string do_unwield();

void create()
{
        set_name(GRN "�̲���¶��" NOR, ({ "xianglu dao", "lvbo", "xianglu", "dao" }));
        set_weight(2500);
        if (clonep())
                destruct(this_object());
        else {
                set("long", GRN "һ������ɫ�Ĺ�ͷ��������ɢ����һ���ȳ�����"
                            "�����˼�����Ż��\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "ʲô�������ó����ó��������ߣ�");
                set("material", "steel");
                set("wield_msg", (: do_wield :));
                set("unwield_msg", GRN "$N" GRN "Ĩ��Ĩ�������������յ��̲�"
                            "��¶���ջء�\n" NOR);
                set("stable", 100);
        }
        init_blade(80);
        setup();
}

string do_wield()
{
        object me = this_player();

        // �������ϴ�ı��̵���(biyan-dao)�߲��ܵ�������
        if (me->query_skill("biyan-dao") < 1 && me->query_skill("poison") < 120)
        {
                me->affect_by("lb_poison", ([
                        "level" : 150,
                        "id"    : "wu laoda",
                        "duration" : 5 + random(5)
                ]));
        	remove_call_out("poison");
        	call_out("poison", 6, me);
                return HIB "$N" HIB "�������ͷ������֪���������У�ȴ����������"
                       "Ȼ���ף��׹�������\n\n" NOR;
        } else
        if (me->query_skill("biyan-dao") < 1 && me->query_skill("poison") > 180)
        {
                return GRN "$N" GRN "�������ͷ������֪���������У�ȴ����������"
                       "Ȼ���ף��׹�������\n" HIY "�Һ�$N" HIY "��ͨ����˲����"
                       "�����������̲��綾��֮�����Ρ�\n\n" NOR;
        } else
        if (me->query_skill("biyan-dao") < 1 && me->query_skill("poison") > 120)
        {
                me->affect_by("lb_poison", ([
                        "level" : 100,
                        "id"    : "wu laoda",
                        "duration" : 3 + random(3)
                ]));
        	remove_call_out("poison");
        	call_out("poison", 18, me);
                return HIB "$N" HIB "�������ͷ������֪���������У�ȴ����������"
                       "Ȼ���ף��׹�������\n" HIC "�Һ�$N" HIC "֪��������æ����"
                       "���죬�����ײŻ����˲��ֶ��ԡ�\n\n" NOR;
        } else
        {
                return GRN "$N" GRN "����һ����������Ȼ���˱��̹������Ĺ�ͷ����\n" NOR;
        }
}

void poison(object me)
{
        object weapon;

        if (objectp(weapon = me->query_temp("weapon"))
           && weapon->query("id") == "xianglu dao"
           && me->query_skill("poison") < 180)
	{
	        message_vision(HIB "\n$N" HIB "���ֲ��ɵ�һ����ԭ���̲���¶����"
                               "��綾�����뼡����\n" NOR, me);
                me->affect_by("lb_poison", ([
                        "level" : 300,
                        "id"    : "wu laoda",
                        "duration" : 10 + random(10)
                ]));
	       	remove_call_out("poison");
       		call_out("poison", 12, me);
	}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill("blade") < 150)
                return damage_bonus / 2;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 10 + 2);
                return GRN "$N" GRN "�̲���¶��������ն������һ������â��$n"
                       GRN "ֻ��һ�������˱Ƕ��������Ҵ��⣬��\n�����������"
                       "�мܶ�ʱɢ�ҡ�\n" NOR;
        case 1:
                n = me->query_skill("blade");
                victim->affect_by("lb_poison", ([
                        "level" : me->query("jiali") + random(me->query("jiali")),
                        "id"    : me->query("id"),
                        "duration" : n / 70 + random(n / 30)
                ]));
                return GRN "$N" GRN "�̲���¶��������ն������һ������â��$n"
                       GRN "ֻ��һ�������˱Ƕ�����΢һ���죬��\nʱ����������"
                       "������\n" NOR;
        }
        return damage_bonus;
}

