#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(CYN "������" NOR, ({ "jingzhong yue" , "blade" ,"dao", "yue", "jingzhong" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", CYN "һ���ĳ������ĵ������ش�ٽ����ɢ�����ںڵĹ���\n" NOR);
                set("value", 100000);
                set("rigidity", 8000);   
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "һ����Ц���ӱ����������¸߸߾���\n" NOR);
                set("unwield_msg", HIY "$N" HIY "����һЦ���������²�ر���\n"NOR);
        }
        init_blade(200);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("str");
        victim->receive_damage("jing", dam);
        return HIY "�����»���һ�����ȵĻ�â��$n" HIY "ֻ�е�������顣\n" NOR;
}

