// renwoxing.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_bijian();

void create()
{
        set_name("������", ({ "ren woxing", "ren","woxing" }));
        set("title", HIR "����������ν���" NOR);
        set("long", "���������������ν��������С�ֻ��\n"
                    "��һ�ų��������ף���ɫѩ�ף����ް�\n"
                    "��Ѫɫ����üĿ���㣬������ߣ�һͷ\n"
                    "�ڷ���������һϮ������\n");
        set("gender", "����");
        set("class", "scholar");
        set("age", 55);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        
        set("max_qi", 8000);
        set("max_jing", 6000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 500);
        set("combat_exp", 4000000);
        set("score", 50000);

        set_temp("apply/attack", 1000);

        set_skill("literate", 250);
        set_skill("force", 400);
        set_skill("dodge", 360);
        set_skill("unarmed", 360);
        set_skill("parry", 360);
        set_skill("sword", 360);
        set_skill("changquan", 360);
        set_skill("xixing-dafa", 400);
        set_skill("lingxu-bu", 360);
        set_skill("damo-jian", 360);
        set_skill("taiji-jian", 360);
        set_skill("huifeng-jian", 360);
        set_skill("taishan-sword", 360);
        set_skill("hengshan-jian", 360);
        set_skill("hengshan-sword", 360);
        set_skill("huashan-sword", 360);
        set_skill("songshan-sword", 360);

        map_skill("dodge", "lingxu-bu");
        map_skill("force", "xixing-dafa");
        map_skill("unarmed", "changquan");
        map_skill("sword", "damo-jian");
        map_skill("parry", "taiji-jian");

        set("inquiry", ([
                "�Ƚ�" :  (: ask_bijian :),
                "����" :  (: ask_bijian :),
                "��ľ��" : "Ҫ�ú�ľ��Ϸ����ȿ�����Ľ�����\n",
        ]) );
        setup();
        carry_object("/d/wudang/obj/bluecloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

int ask_bijian()
{
        object weapon, obj;
        object me = this_player(), ob = this_object();

        if (me->query_temp("want_bijian")) 
        {
                command("say ��������ô��ô��ˬ�죿Ҫ�Ⱦ͸Ͻ���ʼ�ɣ�");
                        return 1;
        }

        if (me->query("skybook/xiaoao/bijian")) 
        {
                command("say �����Ѿ����Թ��ˣ�û��Ҫ��սһ����");
                        return 1;
        }

        if (me->query_temp("bijian_fail")) 
        {
                command("say ���Ѿ����ˣ��ٱ���ȥҲûʲô�����");
                        return 1;
        }

        if (me->query("combat_exp") < 1500000)
        {
                command("heng");
                command("say �㻹������ұȽ���");
                        return 1;
        }

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
        {
                command("say �㲻�ý��һ������ʲô��");
                        return 1;
        }

        message_vision(CYN "$N" CYN "����˵�������������Ұݼ�"
                       "����ǰ�����������ָ�̡�\n$n" CYN "Ц��"
                       "�����ÿ������������Ҽ�į���ɶ�л������"
                       "\n" NOR, me, ob );

        message_vision(CYN "$N" CYN "΢Ц�������ң�������ǰ����"
                       "�̣�\n$n" CYN "���˵�ͷ��˵������ֻ��"
                       "������Ľ�����������Ĺ��У���˵����Ҳδ"
                       "����ʤ�����㡣\n" NOR, me, ob);
        tell_object(me, HIR "��Ը���(accept)�����п�ʼ�Ƚ���\n" NOR);
        me->set_temp("want_bijian", 1);
        add_action("do_accept", "accept");
        return 1;
}

int do_accept()
{
        int eff;
        object weapon, obj;
        object me = this_player(), ob = this_object();
        eff = me->query("max_qi") / 3;

        if (me->query_temp("want_bijian"))
        {
	        if (! objectp(weapon = me->query_temp("weapon")) ||
  	           (string)weapon->query("skill_type") != "sword")
  	        {
        	        command("say �����̵ģ���ѽ�ȡ������ʲô��˼��");
                        return 1;
  	        }

                say (CYN "\n�����й���һЦ��˵�������ҾͿ�ʼ�����ˡ�\n" NOR + HIW
                     "\nֻ��������˵������һչ��һ����������������������\n" NOR,
                     me, ob);

                say (HIW "\n�����д��һ���������ˣ������һ���������ɴ�Ħ����"
                         "��\n" NOR);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                if ((int)me->query("qi") < eff || ! present(me, environment()))
                {
                        say(CYN "������̾�˿�����˵������һ�С�\n" NOR);
                        me->delete_temp("want_bijian", 1);
                        me->set_temp("bijian_fail", 1);
                        return 1;
                }

                command("enable sword taiji-jian");
                say(HIW "\n�����д��һ�����ڶ��У��䵱��̫��������\n" NOR);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                if ((int)me->query("qi") < eff || ! present(me, environment()))
                {
                        say(CYN "������̾�˿�����˵���������С�\n" NOR);
                        me->delete_temp("want_bijian", 1);
                        me->set_temp("bijian_fail", 1);
                        return 1;
                }

                command("enable sword huifeng-jian");
                say(HIW "\n�����д��һ���������У������ɻط����������\n" NOR);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                if ((int)me->query("qi") < eff || ! present(me, environment()))
                {
                        say(CYN "������̾�˿�����˵���������С�\n" NOR);
                        me->delete_temp("want_bijian", 1);
                        me->set_temp("bijian_fail", 1);
                        return 1;
                }

                command("enable sword songshan-sword");
                say(HIW "\n�����д��һ���������У���ɽ����֮����������\n" NOR);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                if ((int)me->query("qi") < eff || ! present(me, environment()))
                {
                        say(CYN "������̾�˿�����˵���������С�\n" NOR);
                        me->delete_temp("want_bijian", 1);
                        me->set_temp("bijian_fail", 1);
                        return 1;
                }

                command("enable sword taishan-sword");
                say(HIW "\n�����д��һ���������У�̩ɽ��ʮ���̽�����\n" NOR);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                if ((int)me->query("qi") < eff || ! present(me, environment()))
                {
                        say(CYN "������̾�˿�����˵���������С�\n" NOR);
                        me->delete_temp("want_bijian", 1);
                        me->set_temp("bijian_fail", 1);
                        return 1;
                }

                command("enable sword huashan-sword");
                say(HIW "\n�����д��һ���������У���ɽ���ڶ����������ɽ���\n" NOR);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                if ((int)me->query("qi") < eff || ! present(me, environment()))
                {
                        say(CYN "������̾�˿�����˵���������С�\n" NOR);
                        me->delete_temp("want_bijian", 1);
                        me->set_temp("bijian_fail", 1);
                        return 1;
                }

                command("enable sword hengshan-sword");
                say(HIW "\n�����д��һ���������У���ɽ����֮һ������㣡\n" NOR);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                if ((int)me->query("qi") < eff || ! present(me, environment()))
                {
                        say(CYN "������̾�˿�����˵���������С�\n" NOR);
                        me->delete_temp("want_bijian", 1);
                        me->set_temp("bijian_fail", 1);
                        return 1;
                }

                command("enable sword hengshan-jian");
                say(HIW "\n�����д��һ����С���ˣ��������һ���˺�ɽ���򻨽�����\n" NOR);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"));
                if ((int)me->query("qi") < eff || ! present(me, environment()))
                {
                        say(CYN "������̾�˿�����˵��������û���ڰ��С�\n" NOR);
                        me->delete_temp("want_bijian", 1);
                        me->set_temp("bijian_fail", 1);
                        return 1;
                }

                obj = new("/d/heimuya/obj/heimu-ling");
                obj->move(me);
                say(CYN "\n�����й�����Ц˵�������¹�Ȼ���ճ�Ⱥ������������·������\n\n" NOR);

                message_vision(HIR "˵��������һ����Х��ľ��ٿ��������$N" HIR "����б��"
                               "�̳����Ƶ����ս��ص�����\n�����������ȣ����Ʒ���һ�㡣��"
                               "��Խ��������Ҳ��Խ�졣$N" HIR "����ÿһ���Ϻ�\n������˫"
                               "���������죬�ķ����ҡ�ͻȻ֮�䣬������ʯ���쾪��һ����Х"
                               "��$N" HIR "\n�����˵�һ�죬���Ķ������ƣ�����һ����ѣ����"
                               "ʱ���²�֪���赹�ڵء���\n" NOR, me, ob );
                me->delete_temp("want_bijian", 1);
                me->set("skybook/xiaoao/bijian", 1);
                me->unconcious();
        }
        return 1;
}
