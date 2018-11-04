#include <weapon.h>
#include <music.h>
#include <ansi.h>

inherit SWORD;
inherit MI_QIN;

void create()
{
        set_name(HIW "��������" NOR,({ "baiyu yaoqin", "baiyu", "yaoqin", "qin" }) );
        set_weight(9000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIW "����һ��ͨ�嶼���ϵȰ�����ƶ������٣��ǳ��Ļ���������\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "�ӱ��󻺻�ȡ��һ�߰������٣������"
                                 "�ϱ������С�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "΢΢һЦ�������еİ�������������"
                                 "�����ŵ�����\n" NOR);
                set("stable", 100);
        }
        init_sword(120);
        setup();
}

void init()
{
        add_action("play_qin", "play");
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "qixian-wuxingjian" ||
            me->query_skill("qixian-wuxingjian", 1) < 100)
                return damage_bonus / 2;

        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIW "$N" HIW "���һ�������о���һ�����������ɶ�ʱһ�䣬$n" HIW "��"
                       "ʱ����ͷ��Ŀѣ���޷���ս��\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return HIW "$N" HIW "һ����ߣ����ַ�����������������ʱ������ü����ޱȣ�"
                       "��������һ������$n" HIW "��\n" NOR;
        }
        return damage_bonus;
}
