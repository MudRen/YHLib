#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(NOR + CYN "��⬼�" NOR, ({ "ruanwei jia", "ruanwei", "jia" }));
        set_weight(8000);
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "��");
                set("long", NOR + CYN "
����һ�����������ף��ֿ��º������ۡ�������һ�������
��⬼ף�ֻ�����������ں�������������ȴ���Ǽ�Ӳʤ����
������Χ�������˵��̣������ޱȡ�\n" NOR);
                set("value", 100000);
                set("no_sell", "����ɶ���ڲ�����ġ�");
                set("material", "cloth");
                set("armor_prop/armor", 150);
                set("stable", 100);
        }
        setup();
}

mixed valid_damage(object ob, object me, int damage)
{
        if (! ob->query_temp("weapon")
           && ! ob->query_temp("secondary_weapon")
           && ! random(ob->query("score")) < 100000
           && random(50) == 1)
	{
                ob->receive_damage("qi", damage, me);
                ob->receive_wound("qi", damage * 2 / 3, me);

                return ([ "damage" : -damage,
                          "msg" : HIR "$N" HIR "һ�иմ���$n" HIR "���壬����"
                                  "����һ���ʹ����֮����æ���֡�\n" NOR ]);
	}
}
