inherit NPC;
#include <ansi.h>

void create()
{

        set_name(HIR "��ȸ" NOR,({"zhu que", "zhu", "que", "bird"}));

        set("race", "Ұ��");
        set("long", HIR "\n\nһֻ��������ԡ���ˣ���������֮һ����ȸ��\n"
                        "��ȫ����ëѪ���ƻ������������һ�Ż��档\n" NOR);
        set("age", 10000);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "˫צ", "����", "���" }) );
        set("verbs", ({ "bite" }) );
        set("title", HIY "����" NOR);

        set("combat_exp", 8000000);
        set("max_neili", 15000);
        set("neili", 15000);
        set("max_jing", 10000);
        set("jing", 10000);
        set("max_qi", 13000);
        set("qi", 13000);
        set("jingli", 10000);
        set("max_jingli", 10000);

        set("str", 30);
        set("int", 30);
        set("con", 20);
        set("dex", 80);

        set_skill("unarmed", 1000);
        set_skill("sword", 1000);
        set_skill("parry", 1000);
        set_skill("dodge", 1000);
        set_skill("force", 400);

        set("jiali", 150);

        set_temp("apply/attack", 300);
        set_temp("apply/unarmed_damage", 300);
        set_temp("apply/armor", 50);

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
        return HIY "��ȸ˫צ�ó�������⣬ɲ�Ǽ���������������"
               "������ǧ���������������������ִ�ء�\n" NOR;
}

void die()
{
        object me;
        object yumao;

        int exp, pot;

        exp = 3000 + random(200);
        pot = 500 + random(50);

        if( objectp(me = query_last_damage_from()) &&
            me->query("wang_get/����") &&
            userp(me) )
        {
                message_vision(HIC "$N" HIC "����ȸ��ʬ���ϰ�����һ����ë��\n", me);
                yumao = new("/d/death/obj/yumao");
                yumao->move(me);
                me->delete("wang_get/����", 1);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                if (me->query("potential") > me->query_potential_limit()) 
                me->set("potential", me->query_potential_limit());

                tell_object(me, HIC "������նɱ������ȸ��������" + chinese_number(exp)
                                + "�㾭���" + chinese_number(pot) + "��Ǳ�ܡ�\n" NOR);
        }
        ::die();
}
