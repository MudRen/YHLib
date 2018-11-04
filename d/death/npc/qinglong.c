inherit NPC;
#include <ansi.h>

void create()
{

        set_name(GRN "����" NOR,({"qing long", "qing", "long", "dragon"}));

        set("race", "Ұ��");
        set("long", GRN "\n\nһ��������ʮ�ɵ���������������֮һ������\n"
                        "�Ƽ���������צ���������������һ�\n" NOR);
        set("age", 10000);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "��β" }) );
        set("verbs", ({ "bite" }) );
        set("title", HIY "����" NOR);

        set("combat_exp", 10000000);
        set("max_neili", 20000);
        set("neili", 20000);
        set("max_jing", 20000);
        set("jing", 20000);
        set("max_qi", 25000);
        set("qi", 25000);
        set("jingli", 20000);
        set("max_jingli", 20000);

        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);

        set_skill("unarmed", 800);
        set_skill("sword", 800);
        set_skill("parry", 800);
        set_skill("dodge", 800);
        set_skill("force", 800);

        set("jiali", 100);

        set_temp("apply/attack", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 100);

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
        return HIR "�������һ���һ�����̶�ڶ�ʱ����һƬ�𺣣�̶ˮ���ڣ���"
               "��������ض�Ҫ��������һ�㡣\n" NOR;
}

void die()
{
        object me;
        object jin, dan;

        int exp, pot;

        exp = 3000 + random(200);
        pot = 500 + random(50);

        jin = new("/d/death/obj/longjin");
        dan = new("/d/death/obj/longdan");

        if( objectp(me = query_last_damage_from()) &&
            me->query("wang_get/����") &&
            me->query("wang_get/����") &&
            userp(me) )
        {
                message_vision(HIC "$N" HIC "��������ʬ���ϳ�����һ�������"
                               "һֻ������\n", me);
                jin->move(me);
                dan->move(me);
                me->delete("wang_get/����", 1);
                me->delete("wang_get/����", 1);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                if (me->query("potential") > me->query_potential_limit()) 
                me->set("potential", me->query_potential_limit());

                tell_object(me, HIC "������նɱ����������������" + chinese_number(exp)
                                + "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�\n" NOR);
        }

        if( objectp(me = query_last_damage_from()) &&
            me->query("wang_get/����") &&
            userp(me) )
        {
                message_vision(HIC "$N" HIC "��������ʬ���ϳ�����һֻ������\n", me);
                dan->move(me);
                me->delete("wang_get/����", 1);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                if (me->query("potential") > me->query_potential_limit()) 
                me->set("potential", me->query_potential_limit());

                tell_object(me, HIC "������նɱ����������������" + chinese_number(exp)
                                + "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�\n" NOR);
        }

        if( objectp(me = query_last_damage_from()) &&
            me->query("wang_get/����") &&
            userp(me) )
        {
                message_vision(HIC "$N" HIC "��������ʬ���ϳ�����һ�����\n", me);
                jin->move(me);
                me->delete("wang_get/����", 1);
        }

        ::die();
}
