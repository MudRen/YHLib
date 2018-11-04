inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#include <ansi.h>
#include "gumu.h"

int ask_xinjing();

void create()
{
        set_name("�ֳ�Ӣ", ({"lin chaoying", "lin", "chaoying" }));
        set("gender", "Ů��");
        set("age", 42);
        set("long", @LONG
�����ǹ�Ĺ�ɵĿ�ɽ��ʦ�ֳ�Ӣ����Ȼ�Ѿ���
��ʮ���ˣ���֮ȴ����ͬ��ʮ��ͷ����������
ȫ���������������һ�Գ��İ��£�ֻ��ϧ��
Ե�޷ݣ�ֻ�ö��������Ĺ���ľӡ�
LONG);

        set("attitude", "friendly");

        set("str", 30);
        set("int", 38);
        set("con", 34);
        set("dex", 34);
        set("shen_type", 1);

        set("qi", 6500);
        set("max_qi", 6500);
        set("jing", 3400);
        set("max_jing", 3400);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 120);

        set("combat_exp", 4000000);
        set_skill("force", 320);
        set_skill("suxin-jue", 320);
        set_skill("yunv-xinjing", 320);        
        set_skill("sword", 320);
        set_skill("yunv-jian", 320);
        set_skill("suxin-jian", 320);
        set_skill("dodge", 320);
        set_skill("yunv-shenfa", 320);
        set_skill("parry", 320);
        set_skill("unarmed",320);
        set_skill("meinv-quan", 320);
        set_skill("strike", 320);
        set_skill("tianluo-diwang", 320);
        set_skill("whip", 320);
        set_skill("yinsuo-jinling", 320);
        set_skill("literate", 300);
        set_skill("taoism", 300);
        set_skill("throwing", 320);
        set_skill("yufeng-zhen", 320);

        map_skill("force", "yunv-xinjing");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");
        map_skill("strike", "tianluo-diwang");

        prepare_skill("unarmed", "meinv-quan");
        prepare_skill("strike", "tianluo-diwang");

        create_family("��Ĺ��", 1, "��ɽ��ʦ");

        set("inquiry", ([
                "������"     :  "�󵨺�С�ӣ�Ҳ��ֱ��������ʦ֮����\n",
                "������ʦ"   :  "������ȫ��̵��ƽ̣��Ժš������ˡ���\n",
                "��Ĺ��"     :  "�ǰ������������һ�ִ��µĹ�Ĺ��\n",
                "�����"     :  "�����û�У������ҡ�\n", 
                "��Ů�ľ�"   :  ( : ask_xinjing() :),
        ]));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.feng" :),
                (: perform_action, "sword.kai" :),
                (: perform_action, "unarmed.you" :),
                (: perform_action, "strike.wang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/qingyi")->wear();

}
void attempt_apprentice(object ob)
{
        object me = this_player();

        if (! permit_recruit(ob) )
                return;

        if (me->query("family/master_name") == "��Ī��")
        {
                command("sneer");
                command("say ���ֳ�Ӣ�ɲ�������ͽ��ͽ�ܡ�");
                return;
        }

        if (ob->query_int() < 35) {
                command("say �ҹ�Ĺ�ɵĹ����һ�����֣�������ʲ�����");
                return;
        }

        if ((int)ob->query_skill("yunv-xinjing", 1) < 120 ) {
                command("say ��Ů�ľ��˱��ž�ѧ����������ⷽ������ϰ��");
                return;
        }

        command("say �ðɣ�����Ҳ���������ˣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}
int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "����" :
        case "����" :
        case "����" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "��������" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/suxin-jian/lian",
                           "name"    : "��������",
                           "sk1"     : "suxin-jian",
                           "lv1"     : 120,
                           "dodge"   : 100,
                           "gongxian": 600, ]));
                break;

        case "�����" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yinsuo-jinling/feng",
                           "name"    : "�����",
                           "sk1"     : "yinsuo-jinling",
                           "lv1"     : 140,
                           "force"   : 180,
                           "gongxian": 700, ]));
                break;

        case "����ٵ�" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/yinsuo-jinling/kai",
                           "name"    : "����ٵ�",
                           "sk1"     : "yinsuo-jinling",
                           "lv1"     : 130,
                           "force"   : 180,
                           "gongxian": 800, ]));
                break;
        default:
                return 0;
        }
}

int ask_xinjing()
{
        object me = this_player();
        string msg;

        if (me->query("family/master_name") != "�ֳ�Ӣ")
        {
               command("say ��Ů�ľ��Ŀھ���ֻ���ڸ��ҵĵ��ӡ�\n");
               return 1;      
        }
        if (me->query("can_learn/yunv-xinjing/wall"))
        {
               command("say ��Ů�ľ��Ŀھ��Ҳ����Ѿ����ڸ�������\n");
               return 1;           
        }

        if (me->query_skill("yunv-xinjing", 1) < 180)
        {
               command("say ����Ů�ľ�����Ϊ�����������ڲ��ܴ��ڸ���ھ���\n");
               return 1;      
        }

        command("nod");
        msg = HIC"�ֳ�Ӣ˵�������ðɣ������Ҿͽ���Ů�ľ��Ŀھ����ڸ��㣬��ɼǺ��ˣ���";
        msg += HIY"\n�ֳ�Ӣ�����ĵؽ���Ů�ľ��Ŀھ����ڸ�$N��\n" NOR;
   
        message_vision(msg, me);

        me->set("can_learn/yunv-xinjing/wall", 1);

        return 1;      

}

void unconcious()
{
        die();
}

