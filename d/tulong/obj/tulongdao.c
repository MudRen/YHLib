#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(CYN "������" NOR, ({ "tulong blade" , "blade" ,"dao", "tulong" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY "����Ǻų���������������������ĳ������ĵ���������һ�ٶ��֮�ء�\n�ഫ���в��п����Ĵ����ܡ�\n" NOR);
                set("value", 100000);
                set("no_sell", "����������������\n");
                set("rigidity",8000);   
                set("material", "steel");
                set("wield_msg", HIY "$Nһ����Ц���ӱ������Ǳ��ųơ�"NOR+HIR"��������"NOR+HIY"�������������߸߾���\n" NOR);
                set("unwield_msg", HIY "$N����һЦ��������������ر���\n"NOR);
        }
        init_blade(500);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("str");
        victim->receive_damage("jing",dam * 2);
        return HIM "�������д��Ŵ̶����ƿ�������һ�������磬$nֻ�е��������ң���ǿ�����ֵ���\n" NOR;
}

void init()
{
        add_action("do_open","duikan");
}

int do_open(string arg, object me)
{
        object pai,ob;
        if(arg != "yitian sword" || !ob = present("yitian sword", environment(this_object()))) 
        {
                return notify_fail("��Ҫ��ʲô��\n");
        }
   else if (this_player()->query("jiali") <= 160)
        return notify_fail(WHT "\n��������������׼���콣�����Ŀ�����ȥ��"NOR+HIR"\n\nֻ�����ꡱ��һ�����죬�ɽ���������ǡ�\n" NOR);
        {
                pai = new("/d/tulong/obj/duan1");
                pai->move(this_player());
                pai = new("/d/tulong/obj/duan2");
                pai->move(this_player());
                pai = new("/d/tulong/obj/zhenjing");
                pai->move(this_player());
                pai = new("/d/tulong/obj/miji");
                pai->move(this_player());
                pai = new("/d/tulong/obj/yishu");
                pai->move(this_player());
                message_vision(WHT "\n$N������������׼���콣�����Ŀ�����ȥ��\n\n"NOR+HIW"ֻ��һ�����죬$N�ֱ�һ�������������콣�Ѿ����ˡ��㷢�ֵ����о�Ȼ�в��ż����\n"NOR,this_player());
                destruct (ob);
                destruct(this_object());
                return 1;
        }
}

