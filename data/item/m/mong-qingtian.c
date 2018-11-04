
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name(HIC "�����[2;37;0m" NOR, ({ "qingtian" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "��");
	set("long", HIW "����һ������ͨͨ�Ļ��ף�������Χɢ��������������������������"
                        "ʲôҲ�����塣\n" HIC
                        "����Ե�Ͽ���һ��С�֣���������������� ����(mong)\n" NOR);
	set("value", 1);
	set("point", 150);
	set("material", "tian jing");
	set("wear_msg", HIC "������ƿն��죬����������֮������ȴ������$N" HIC "�϶�Ϊһ��[2;37;0m\n" NOR);
	set("remove_msg", HIC "$N" HIC "���쳤Х������׶������죬ɲ�Ǽ���Χ������ɢ�������������"
                          "��ʧ����ʡ�[2;37;0m\n" NOR);
	if (! check_clone()) return;
	restore();
        set("armor_prop/dodge", 100);
	set("armor_prop/parry", 100);
        set("armor_prop/armor", apply_armor());
	setup();
}

string long() { return query("long") + item_long(); }


mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;  

        if ((int)me->query_skill("force", 1) < 260
           || (int)me->query("neili") < 500
           || ! living(me) || random(4) != 1)
                return;

        cost = damage / 2;

        if (cost > 300) cost = 300;

        ap = ob->query_skill("force") * 12 + ob->query("max_neili");
        dp = me->query_skill("force") * 12 + me->query("neili");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIR "$n" HIR "����һ̾������" HIC "�����" HIR "����"
                                            "���죬$N" HIR "ֻ����ͷһ����ࡣ��һ�о�Ȼ����ȥ��\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIM "ֻ��$n" HIM "����" HIC "�����" HIM "һ������"
                                            "��������" HIM "$N" HIM "��ֻ��ͷ��Ŀѣ����Ȼһ�д��ڿմ���\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$N" HIW "һ�д���$n" HIW "���پ���������������һ����ԭ����"
                                            "��" HIC "�����" HIW "�û������Ļ���\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIY "$n" HIY "����" HIC "�����" HIY "һ����������$N" HIY "��һ"
                                            "�б�������ε�ס���˲���$n" HIY "�ֺ���\n" NOR]);
                        break;
                }
                return result;
        }
}