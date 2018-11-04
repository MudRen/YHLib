inherit NPC;
#include <ansi.h>

void create()
{

        set_name(HIW "�׻�" NOR,({"bai hu", "bai", "hu", "tiger"}));

        set("race", "Ұ��");
        set("long", HIW "\n\nһֻ��������ľ����ͻ�����������֮һ�İ׻���\n"
                        "��ȫ��ëƤ�����Ͼ�����Ǹ߹�\n" NOR);
        set("age", 10000);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "��β" }) );
        set("verbs", ({ "bite" }) );
        set("title", HIY "����" NOR);

        set("combat_exp", 8000000);
        set("max_neili", 18000);
        set("neili", 18000);
        set("max_jing", 18000);
        set("jing", 18000);
        set("max_qi", 22000);
        set("qi", 22000);
        set("jingli", 18000);
        set("max_jingli", 18000);

        set("str", 45);
        set("int", 45);
        set("con", 45);
        set("dex", 45);

        set_skill("unarmed", 800);
        set_skill("sword", 800);
        set_skill("parry", 800);
        set_skill("dodge", 800);
        set_skill("force", 800);

        set("jiali", 100);

        set_temp("apply/attack", 150);
        set_temp("apply/unarmed_damage", 150);
        set_temp("apply/armor", 150);

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
        return HIW "�׻����һ�ź�����ɲʱ�������ųߣ����ܱ�ѩ"
               "�׷ɣ��ƺ���������Ҫ����סһ�㡣\n" NOR;
}

void die()
{
        object me;
        object gu, pi;

        int exp, pot;

        exp = 3000 + random(200);
        pot = 500 + random(50);

        gu = new("/d/death/obj/hugu");
        pi = new("/d/death/obj/hupi");

        if( objectp(me = query_last_damage_from()) &&
            me->query("wang_get/����") &&
            me->query("wang_get/��Ƥ") &&
            userp(me) )
        {
                message_vision(HIC "$N" HIC "�Ӱ׻���ʬ���ϳ�����һ�Ű׻�"
                               "Ƥ��һ�����ǡ�\n", me);
                gu->move(me);
                pi->move(me);
                me->delete("wang_get/����", 1);
                me->delete("wang_get/��Ƥ", 1);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                if (me->query("potential") > me->query_potential_limit()) 
                me->set("potential", me->query_potential_limit());

                tell_object(me, HIC "������նɱ���ް׻���������" + chinese_number(exp)
                                + "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�\n" NOR);
        }

        if( objectp(me = query_last_damage_from()) &&
            me->query("wang_get/����") &&
            userp(me) )
        {
                message_vision(HIC "$N" HIC "�Ӱ׻���ʬ���ϳ�����һ�����ǡ�\n", me);
                gu->move(me);
                me->delete("wang_get/����", 1);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                if (me->query("potential") > me->query_potential_limit()) 
                me->set("potential", me->query_potential_limit());

                tell_object(me, HIC "������նɱ���ް׻���������" + chinese_number(exp)
                                + "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�\n" NOR);
        }

        if( objectp(me = query_last_damage_from()) &&
            me->query("wang_get/��Ƥ") &&
            userp(me) )
        {
                message_vision(HIC "$N" HIC "�Ӱ׻���ʬ���ϳ�����һ�Ű׻�Ƥ��\n", me);
                pi->move(me);
                me->delete("wang_get/��Ƥ", 1);
        }

        ::die();
}
