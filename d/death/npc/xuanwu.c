inherit NPC;
#include <ansi.h>

void create()
{

        set_name(WHT "����" NOR,({"xuan wu", "xuan", "wu"}));

        set("race", "Ұ��");
        set("long", WHT "\n\nһֻ��ͷ�������Ȼ�����������֮һ�����䡣\n"
                        "��ȫ�����ļ׿Ǳ����š�\n" NOR);
        set("age", 10000);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "˫צ", "����", "���" }) );
        set("verbs", ({ "bite" }) );
        set("title", HIY "����" NOR);

        set("combat_exp", 8000000);
        set("max_neili", 25000);
        set("neili", 25000);
        set("max_jing", 20000);
        set("jing", 20000);
        set("max_qi", 30000);
        set("qi", 30000);
        set("jingli", 15000);
        set("max_jingli", 15000);

        set("str", 40);
        set("int", 40);
        set("con", 80);
        set("dex", 20);

        set_skill("unarmed", 600);
        set_skill("sword", 600);
        set_skill("parry", 600);
        set_skill("dodge", 600);
        set_skill("force", 1200);

        set("jiali", 100);

        set_temp("apply/attack", 50);
        set_temp("apply/unarmed_damage", 50);
        set_temp("apply/armor", 1000);

        set_weight(500000000);

        setup();
}

void init()
{
        object me,ob;

        if (interactive(me = this_player()))
        {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, me);
        }
        ::init();
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        ob->receive_wound("qi", 200 + random(200), me);
        me->set("neili", me->query("max_neili"));
        return WHT "����˫����̤���棬��ʱ�ض�ɽҡ��ɽ�����ѣ�"
               "�Ĵ���ɳ��ʯ���·���ض�Ҫ������һ�㡣\n" NOR;
}

void die()
{
        object me;
        object jiake;

        int exp, pot;

        exp = 3000 + random(200);
        pot = 500 + random(50);

        if( objectp(me = query_last_damage_from()) &&
            me->query("wang_get/���") &&
            userp(me) )
        {
                message_vision(HIC "$N" HIC "�������ʬ���ϳ�����һ������׿ǡ�\n", me);
                jiake = new("/d/death/obj/jiake");
                jiake->move(me);
                me->delete("wang_get/���", 1);
                me->delete("wang_get/����", 1);
                me->delete("wang_get/��Ƥ", 1);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                if (me->query("potential") > me->query_potential_limit()) 
                me->set("potential", me->query_potential_limit());

                tell_object(me, HIC "������նɱ�������䣬������" + chinese_number(exp)
                                + "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�\n" NOR);
        }
        ::die();
}
