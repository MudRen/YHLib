#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY "TEST���Ĵ��ƽ��" NOR, ({ "test" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", WHT "\n
������������������������������������������
��                                      ��
��    " HIY "��ʱ���ߣ�������" HIR "IQ" HIY "������һ��" NOR + WHT "    ��
��                                      ��
��" HIY "setnew" NOR + WHT " ��   �趨��ʼ״̬��            ��
��" HIY "body" NOR + WHT "   ��   ״̬�ָ���Ǳ�����������ޡ���
��" HIY "money" NOR + WHT "  ��   �õ�һ���ƽ�            ��
��" HIY "shen + | -" NOR + WHT "���õ�һ��������Ǹ���    ��
��                                      ��
��   " HIR "������˾���׻�ʵҵ�ɷݿ������޹�˾" NOR + WHT " ��
��  " CYN "�������������ƾ��������127��88888��" WHT "��
��                                      ��
������������������������������������������
\n" NOR);
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/int", 10000);
        }
        setup();
}

void init()
{
        add_action("do_full1", "setnew");
        add_action("do_full2", "body");
        add_action("do_full3", "money");
        add_action("do_full4", "shen");
}

int do_full1(string str)
{
      object me = this_player();
      me->set("combat_exp", 500000);
      me->set("gongxian", 10000);
      me->set("weiwang", 10000);
      me->set("score", 10000);
      me->set("mud_age", 10000);
      me->set("max_neili", 2000);
      me->set("max_jingli", 2000);
      me->set_skill("literate", 200);
      me->save();
      tell_object(me, HIC "״̬�綨��ɣ�����ٴ�ʹ�ô��������ָ�����״̬��\n" NOR);
      return 1;
}

int do_full2(string str)
{
        object ob = this_player();
        mapping my;

        if (ob->is_fighting())
                return notify_fail("���֣����ڴ��Ү����ˣ��å�ò��ã�\n");

        my = ob->query_entire_dbase();
        my["jing"]   = my["eff_jing"]   = my["max_jing"];
        my["jingli"] = my["eff_jingli"] = my["max_jingli"];
        my["qi"]     = my["eff_qi"]     = my["max_qi"];
        my["neili"]  = my["max_neili"];
        my["food"]   = ob->max_food_capacity();
        my["water"]  = ob->max_water_capacity();

        ob->set("potential", ob->query_potential_limit());
        tell_object(ob, HIC "״̬�Ѿ��ָ���\n" NOR);
        return 1;
}

int do_full3(string str)
{
        object ob, me = this_player();

        ob = new("/clone/money/gold");
        ob -> move(me, 1);
        tell_object(me, HIC "������һ���ƽ�\n" NOR);
        return 1;
}

int do_full4(string arg)
{
      object me = this_player();

      if (! arg || (arg != "+" && arg != "-"))
		return notify_fail("\n��Ҫ�����Ǹ���\n");

      if (arg == "+")
	      me->add("shen", 10000);
      else
	      me->add("shen", -10000);

      tell_object(me, HIC "����趨��ɡ�\n" NOR);
      return 1;
}
