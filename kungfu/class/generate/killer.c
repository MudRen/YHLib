// killer.c
// ɱ�֡��� ultra_quest �ı����������

#include <ansi.h>
inherit CLASS_D("generate") + "/chinese";

void create()
{
        mapping my;

        ::create();
        set("gender", "����" );
        set("age", 30 + random(30));
        set("long", "����һ�������ˡ�");
        set("attitude", "friendly");
        set("scale", 150);
        set_temp("apply/armor", 30);
        set_temp("apply/damage", 20);
        set_temp("born_time", time());

        setup();
        if (clonep()) keep_heart_beat();
}

void set_from_me(object me)
{
        int exp;
        mapping my;

        NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me));
        my = query_entire_dbase();

        if (my["max_qi"] > 6000)
                my["max_qi"] = 6000;

        if (my["max_jing"] < my["max_qi"] / 2)
                my["max_jing"] = my["max_qi"] / 2;

        if (my["max_jing"] > 3000)
                my["max_jing"] = 3000;

        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];

        exp = me->query("combat_exp") * 12 / 10;

        if (exp > query("combat_exp"))
                set("combat_exp", exp);

        my["jiali"] = query_skill("force") / 2;
}

int accept_fight(object ob)
{
        command("say �ҿ�û��Ȥ�����棬����ҹ�����");
        return 0;
}

int accept_hit(object ob)
{
        message_vision(HIW "$N" HIW "��ɫһ�䣬����һ��ɱ����ŭ"
                       "�ȵ�����һ��" + RANK_D->query_rude(ob) +
                       "�����ɣ�\n" NOR, this_object());
        kill_ob(ob);
        return 1;
}

int accept_kill(object ob)
{
        if (! living(this_object()))
                return 1;

        return accept_hit(ob);
}

int accept_ansuan(object ob)
{
        return notify_fail("���˾����Ժøߣ����������֡�\n");
}

int accept_touxi(object ob)
{
        return notify_fail("���˾����Ժøߣ����������֡�\n");
}

void unconcious()
{
        die();
}
