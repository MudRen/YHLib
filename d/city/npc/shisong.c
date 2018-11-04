#include <ansi.h>
inherit NPC;

#define HEILONG    "/clone/lonely/heilongbian"
#define LING       "/clone/lonely/item/tongjiling"

void create()
{
        object ob;
        set_name("ʷ��", ({ "shi song", "shi", "song" }));
        set("gender", "����");
        set("long", "����һ����׳���ӣ�����ģ��������Χһ�����ޡ�\n");
        set("nickname", WHT "������" NOR);
        set("title", "Ѳ������");
        set("age", 35);
        set("str", 25);
        set("dex", 20);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 50);
        set("combat_exp", 300000);
        set("shen_type", -1);
        set("attitude", "peaceful");

        set_skill("force", 120);
        set_skill("bagua-xinfa", 120);
        set_skill("whip", 120);
        set_skill("yunlong-bian", 120);
        set_skill("cuff", 100);
        set_skill("bagua-quan", 100);
        set_skill("dodge", 100);
        set_skill("feiyan-zoubi", 100);
        set_skill("parry", 100);
        set_skill("literate", 80);
        set_skill("martial-cognize", 80);

        map_skill("force", "bagua-xinfa");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("cuff", "bagua-quan");
        map_skill("whip", "yunlong-bian");
        map_skill("parry", "yunlong-bian");

        prepare_skill("cuff", "bagua-quan");

        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 50);
        set_temp("apply/unarmed_damage", 50);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.gua" :),
                (: perform_action, "whip.chan" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "éʮ��" : "˭���Ҹɵ����������һ������ǰ���ƽ���",
                "���־�" : "���ܵ������ְɣ�",
        ]));

        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "ʷ��˵�������º�����ʷ�ɣ������ٱ����������ػᷴ����\n" NOR,
                CYN "ʷ��˵�������ٱ��������£����ڱ�������һȭ����һͷ��ţ��\n" NOR,
        }));

        setup();

        if (clonep())
        {
                ob = find_object(HEILONG);
                if (! ob) ob = load_object(HEILONG);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/clone/weapon/changbian");
                        ob->move(this_object());
                        ob->wield();
                }
        }

        carry_object("/d/beijing/npc/obj/guanfu3")->wear();
        add_money("silver", 20);
}

void init()
{
        object me, ob;
        ::init();

        ob = this_player();
        me = this_object();

        if (ob->query("id") == "mao shiba")
        {
                command("say éʮ��������������������ڴ������ˣ�");
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }

        if (interactive(ob)
	   && ! environment(ob)->query("no_fight")
           && (ob->query("combat_exp") > 150000)
           && (ob->query("family/family_name") == "��ػ�"))
        {
                command("say �������ػᷴ�����������ɣ�");
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }
}

int accept_object(object me, object ob)
{
        int exp, pot, sc;

        exp = 500 + random(300);
        pot = 100 + random(50);
        sc = random(10);

        if (base_name(ob) != LING)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (me->query("combat_exp") > 10000)
        {
                if (! (int)me->query("skybook/luding/shi"))
                {
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
                        me->add("score", sc);
                        tell_object(me, HIW "\n\n��ɹ��İ���ʷ��Ū����ͨ���\n" NOR +
                                        HIC "ͨ����ε�������������" + chinese_number(exp) +
                                        "�㾭�顢" + chinese_number(pot) + "��Ǳ���Լ�" +
                                        chinese_number(sc) + "�㽭��������\n\n" NOR);
                        me->set("skybook/luding/shi", 1);
                        me->set("can_learn/yunlong-bian/shi", 1);
                }
                command("haha");
                command("say �������é�Ĵ���ɵ��ˣ��������лл���ˡ�");
                command("say ������һ�������޷��������Ը�⣬�ҵ��ǿ��Դ������֡�\n");
        } else
        {
                command("nod " + me->query("id"));
                command("say ����������ϧ�㽭������̫ǳ��Ҫ�����ɽ���㶫����");
        }
        destruct(ob);
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if (! me->query("can_learn/yunlong-bian/shi"))
        {
                command("say ���̵ģ�������ô��");
                return -1;
        }

        if (skill != "yunlong-bian")
        {
                command("say �����ֵľ�ֻ�����ױ޷����㲻ѧ�����ˡ�");
                return -1;
        }
        return 1;
}

int accept_fight(object me)
{
        command("say û��Ȥ��");
        return 0;
}

int accept_hit(object me)
{
        command("say �����̵ģ������㶼���ǣ�");
        kill_ob(me);
        return 1;
}
