#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(CYN "���콣" NOR, ({ "yitian sword", "jian", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "�������������������������Ƶ����콣��\n�ഫ�õ����Կ�(duikan)���Եõ������������ؼ���\n" NOR);
                set("value", 100000);
                set("no_sell", "����������������\n");
                set("rigidity",8000);   
                set("material", "steel");
                set("wield_msg", HIW "ֻ����ಡ���һ���ƿ����죬�ų����µ�һ��������콣�ѱ�$N�������С�\n" NOR);
                set("unwield_msg", HIW "$N�����콣������䣬����ֽ����ų���â��\n"NOR);
        }
        init_sword(500);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("dex");
        victim->add("neili", -dam * 10);

        if (victim->query("neili") < 0) 
        victim->set("neili", 0); 

        return HIW "���콣Я���쬴̹Ƿ�����ֱֱ����$n��$nֻ�е�ȫ���������һ˿˿���Ž���ӿ����\n" NOR;
}

