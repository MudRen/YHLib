#include <weapon.h>
#include <ansi.h>

inherit PIN;

string do_wield();
string do_unwield();

void create()
{
        set_name(HIR "������" NOR, ({ "kuihua zhen", "kuihua", "zhen", "pin" }));
        set_weight(30);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", HIR "һ��Ѫ��ɫ��ϸ�룬Ҳ��֪������ʲô�������ɡ�\n" NOR);
                set("value", 800000);
                set("no_sell", "������ˣ���Ȼ����Ҳ���ó��֡�");
                set("material", "silver");
                set("wield_msg", (: do_wield :));
                set("unwield_msg", (: do_unwield :));
                set("stable", 100);
        }
        init_pin(160);
        setup();
}

string do_wield()
{
        object me = this_player();
        int lvl;

        lvl = me->query_skill("pixie-jian", 1) + me->query_skill("kuihua-mogong", 1);

        me->set_temp("apply/attack", lvl / 2);
        me->set_temp("apply/dodge", lvl / 2);
        return HIR "$N" HIR "����һ��������һ��Ѫ��ɫ��ϸ�롣\n" NOR;
}

string do_unwield()
{
        object me = this_player();
        int lvl;

        lvl = me->query_skill("pixie-jian", 1) + me->query_skill("kuihua-mogong", 1);

        me->delete_temp("apply/attack", lvl / 2);
        me->delete_temp("apply/dodge", lvl / 2);
        return HIR "$N" HIR "һ����Ц�������˿����롣\n" NOR;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill("sword") < 250)
                return damage_bonus / 2;

        if (me->query_skill_mapped("sword") != "pixie-jian" &&
            me->query_skill_mapped("sword") != "kuihua-mogong")
                return damage_bonus / 2;

        switch (random(4))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 16 + 2);
                return random(2) ? HIR "ֻ��$N" HIR "��֦�Ͱڣ��ó�������Ӱ��$n"
                                   HIR "�мܶ�ʱɢ�ң���������������\n" NOR:

                                   HIR "$N" HIR "һ����Ц����������һ��������"
                                   "�䣬$n" HIR "��ʱ��������ȫ�����飡\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return random(2) ? HIR "$n" HIR "ֻ����ǰ���Ծ�����������ȣ���"
                                   "���ؿ�һ���ʹ������������Ѫ��\n" NOR:

                                   HIR "$N" HIR "����һ�Σ��Ѳ�������Ӱ��ȴ��$n"
                                   HIR "һ���ҽУ������뾹�������֣�\n" NOR;

        case 2:
                return HIR "$N" HIR "����Ʈ��������һ�غ�â����Ծ����$n"
                       HIR "��ʱֻ���ۻ����ң��޴��мܣ�\n" NOR;

        case 3:
                return HIR "ֻ��$N" HIR "����Ｒ����ǰ��˲������$n" HIR
                       "��ǰ����Ц���������漴Ծ����\n" NOR;
        }
        return damage_bonus;
}
