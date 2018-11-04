#include <weapon.h>
#include <ansi.h>

inherit SWORD;

string do_wield();
string do_unwield();

void create()
{
        set_name(HIY "���佣" NOR,({ "zhenwu jian", "jian", "sword", "zhenwu" }) );
        set_weight(1500);
        if (clonep())
                destruct(this_object());
        else {
                set("long", @LONG
����һ�����������ı����������䵱�����˳ִ˽�������ħ��ɨ��Ⱥ��
������С�����˽��޲��ĵ���ҡ��
LONG );
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", (: do_wield :));
                set("unwield_msg", (: do_unwield :));
                set("stable", 100);
        }
        init_sword(200);
        setup();
}

string do_wield()
{
        object me;

        me = this_player();
        if (me->query("shen") > 10000)
        {
                me->set_temp("apply/attack", me->query_skill("sword") / 4);
                me->set_temp("apply/defense", me->query_skill("parry") / 4);
                return HIC "$Nһ����Х����$n" HIC "�������ʣ���ʱ��ؼ������Ȼ��\n" NOR;
        } else
        if (me->query("shen") >= 0)
        {
                return HIC "$Nһ���֣���Ȼ��$n" HIC "�������С�\n" NOR;
        } else
        if (me->query("shen") > -10000)
        {
                me->set_temp("apply/attack", -me->query_skill("sword") / 5);
                me->set_temp("apply/defense", -me->query_skill("parry") / 5);
                return HIG "$Nսս����������һ��$n" HIG "��\n" NOR;
        } else
        {
                return HIG "$Nһ����Ц����ৡ���һ��������$n" HIG "��\n" NOR;
        }
}

string do_unwield()
{
        object me;

        me = this_player();
        me->delete_temp("apply/attack", me->query_skill("sword") / 4);
        me->delete_temp("apply/defense", me->query_skill("parry") / 4);
        if (me->query("shen") >= 0)
                return HIC "$Nһ���֣��������ʡ�\n" NOR;
        else
        if (me->query("shen") > -10000)
                return HIG "$N��$n" HIG "��ؽ��ʣ�Ĩ��Ĩͷ�ϵĺ���\n" NOR;
        else
                return HIG "$Nһɹ����$n" HIG "��ؽ��ʡ�\n" NOR;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->is_bad() || victim->is_good())
                return - damage_bonus / 2;

        if (me->is_not_good() || victim->is_not_bad())
                return 0;

        if (me->query_skill_mapped("sword") != "taiji-jian" ||
            me->query_skill("taiji-jian", 1) < 100)
                // only increase damage
                return damage_bonus / 2;

        switch (random(4))
        {
        case 0:
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIC "$N" HIC "��ǰһ�������е�" NOR + HIY "���佣" NOR
                       + HIC "�û�������ԲȦ����$n" HIC "��ȥ������ϸ��֮����"
                       "$n" HIC "���һ\n������֪��εֵ���ֻ���������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("sowrd");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                n = victim->query("eff_jing");
                n /= 2;
                victim->receive_damage("jing", n, me);
                victim->receive_wound("jing", n / 2, me);
                return random(2) ? HIY "$N" HIY "һ�����������е����佣����һ"
                                   "�����磬��ৡ���ɨ��$n" HIY "��ȥ��\n" NOR:
                                   HIY "$N" HIY "ͻȻ�����ȵ�����аħ�������"
                                   "�����������������佣" HIY "����һ����$n"
                                   HIY "��ʱ�����ۻ����ң�\n" NOR;
        }

        // double effect
        return damage_bonus;
}


