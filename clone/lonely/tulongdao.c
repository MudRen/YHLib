#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(NOR + CYN "������" NOR, ({ "tulong dao", "tulong", "dao", "blade" }) );
        set_weight(32000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", NOR + CYN "����Ǻų���������������������ĳ�����"
                            "�ĵ���������һ�ٶ��֮�ء�\n�ഫ���в��п����Ĵ�"
                            "���ܡ�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "�ҵ��졭�㡭��֪������ɶô������Ҳ����������");
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "һ����Ц���ӱ������Ǳ��ųơ�"
                                 HIR "��������" HIY "�������������߸߾���\n" NOR);
                set("unwield_msg", HIY "$N" HIY "����һЦ��������������ر���\n" NOR);
                set("stable", 100);
        }
        init_blade(250);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("jing", me->query("str") * 2, me);
        victim->receive_wound("jing", me->query("str") * 2, me);
        return HIM "�������д��Ŵ̶����ƿ�������һ�������磬��ʱ��$n"
               HIM "ֻ�е��������ҡ�\n" NOR;
}

