#include <ansi.h>
inherit QUARRY;

void create()
{
        set_name(NOR + WHT "��Գ" NOR, ({ "bai yuan", "bai", "yuan" }));
        set("long", WHT @LONG
����һֻ���Գ����ֵ��Ǵ��������ܹ��ŵ�
���󸯳�֮����ԭ����Գ����ŧѪģ��������
һ���󴯡�ģ�����ǿ��������������������
���Խ���ҽ��(heal)һ����
LONG NOR);
        set("no_auto_kill", 1);

        set("age", 65);
        set("str", 22);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 2500);
        set("combat_exp", 300000);

        set("power", 50);
        set("bag_count", 1);

        set_temp("apply/parry", 200);
        set_temp("apply/dodge", 200);
        set_temp("apply/attack", 180);
        set_temp("apply/defense", 180);
        set_temp("apply/unarmed_damage", 220);
        set_temp("apply/armor", 220);

        setup();

        if (random(3) == 1)
                set_temp("handing", carry_object("/d/emei/obj/pantao"));
}

void init()
{
	add_action("do_lifeheal", "heal");
}

int do_lifeheal(string arg)
{
        object weapon, bag;
        object me = this_player();

        if (arg != "bai yuan" && arg != "bai" && arg != "yuan")
        {
            	write("��Ҫ��ʲô��\n");
            	return 1;
        }

        if (query("bag_count") < 1)
        {
        	write("���Գһ����������������ҽ�Ρ�\n");
        	return 1;
        }

        if (me->query_skill("medical", 1) < 100)
        {
     	       write("��������ҽ����ûѧ�ã���̸ʲôҽ�Ρ�\n");
               return 1;
        }

        if (! present("fish bone", me))
        {
     	       write("������ҽ�����߲������޷�ҽ�Ρ�\n");
               return 1;
        }

        if (! objectp(weapon = me->query_temp("weapon"))
           || ((string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade"
           && (string)weapon->query("skill_type") != "dagger"))
                return notify_fail("�㻹���Ҹ������������װ"
                                   "�Ϻ����������ɡ�\n");

        message_sort(HIC "\n$N" HIC "��ұ߼��϶˵ķ�"
                     "�ߣ���б���п���������ĸ�Ƥ��ֻ��"
                     "�������ﾹ����һ���Ͳ�������$N" HIC
                     "���Ͳ�������һ�ߣ���������룬����"
                     "��Ƥ�ϴ���һ����С�ף��ٽ���Ƥ˺��"
                     "ϸ˿������С�״�ᣬ��ǿ����Գ�ĸ�"
                     "����ã��ڴ��ڷ��ϲ�ҩ��\n" NOR, me);

        GIFT_D->delay_gift_bonus(me, ([ "temp"    : "can_learn/jiuyang-shengong/kunlun",
                                        "prompt"  : "��ͨ��ҽ�ΰ�Գ�ľ���",
                                        "exp"     : random(3000) + 2000,
                                        "pot"     : random(500) + 500,
                                        "score"   : random(100) + 100, ]));

        if (present("pan tao", this_object()))
        {
                message_vision(CYN "\n��Գ֨֨֨��������������"
                               "��������ˮ����Ĵ���ң�������"
                               "�ᡣ\n" NOR, this_object());

                command("give pan tao to " + me->query("id"));
        }

        add("bag_count", -1);
        bag = new("/d/mingjiao/obj/bag");
        bag->move(environment(me));

        return 1;
}

void unconcious()
{
        this_object()->die();
}

