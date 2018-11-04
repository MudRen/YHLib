// cheng-buyou.c  �ɲ���
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

mixed learn_kuangfeng();

void create()
{
        set_name("�ɲ���", ({ "cheng buyou", "cheng" }) );
        set("gender", "����");
        set("class", "swordsman");
        set("title", "��ɽ���ڵ�ʮ��������");
        set("age", 41);
        set("long", "һ���׾���Ƥ�İ��ӣ�����ȴ�쳣������\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("int", 24);
        set("con", 23);
        set("dex", 27);

        set("max_qi", 5800);
        set("max_jing", 2400);
        set("neili", 6600);
        set("max_neili", 6600);
        set("jiali", 120);

        set("combat_exp", 3000000);
        set("shen_type", -1);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.long" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "strike.piao" :),
                (: perform_action, "cuff.song" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("unarmed", 240);
        set_skill("cuff", 240);
        set_skill("strike", 240);
        set_skill("huashan-zhang", 240);
        set_skill("sword", 280);
        set_skill("force", 200);
        set_skill("parry", 280);
        set_skill("dodge", 240);
        set_skill("literate", 150);
        set_skill("huashan-jian", 280);
        set_skill("huashan-xinfa", 200);
        set_skill("huashan-quan", 200);
        set_skill("huashan-shenfa", 240);

        map_skill("sword", "huashan-jian");
        map_skill("parry", "huashan-jian");
        map_skill("force", "huashan-xinfa");
        map_skill("cuff", "huashan-quan");
        map_skill("dodge", "huashan-shenfa");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");

        create_family("��ɽ��", 13, "����");

        set("inquiry", ([
                "����Ⱥ"         : "�ߣ����°ܽ������Գ�ʲô���ӽ���\n",  
                "�����������ɽ�" : "�������ѧ�Ļ��������ҷ�ʦ�硣\n",
                "����"           : "�Ҿ��ǻ�ɽ���ڴ��ˣ�\n",
                "���콣"       : (: learn_kuangfeng :),
        ]));
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �Ϸ�Ӳ���ͽ��");
}

int accept_ask(object me, string topic)
{
        if (me->query("family/family_name") != "��ɽ��")
                return 0;

        switch (topic)
        {
        case "�������" :
                if (me->query("max_neili") > 2000 || me->query_skill("force") > 205)
                {
                      command("shake");
                      command("say �ҽ����Խ���Ϊ������Ϊ�Σ�����ڹ���Ϊ������������;���ٲ����������ڽ�����");
                      return 1;
                }
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-jian/long",
                           "name"    : "�������",
                           "sk1"     : "huashan-jian",
                           "lv1"     : 150,
                           "force"   : 150, ]));
                break;

        case "��ɨ��Ҷ" :
                if (me->query("max_neili") > 2000 || me->query_skill("force") > 205)
                {
                      command("shake");
                      command("say �ҽ����Խ���Ϊ������Ϊ�Σ�����ڹ���Ϊ������������;���ٲ����������ڽ�����");
                      return 1;
                }
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/kuangfeng-jian/sao",
                           "name"    : "��ɨ��Ҷ",
                           "sk1"     : "kuangfeng-jian",
                           "lv1"     : 100,
                           "sk2"     : "dodge",
                           "lv2"     : 100, ]));
                break;

        default:
                return 0;
        }
}

mixed learn_kuangfeng()
{
        object me = this_player();
        int lv;

        if (me->query("family/family_name") != "��ɽ��")
                return "���Һ��޹ϸ𣬺γ����ԣ�\n";

        if (me->query_skill("kuangfeng-jian", 1))
              return "�Ҹý̵Ķ��Ѿ������ˣ�ʣ�µľͿ����ڼ���ϰ�ˣ�\n";

        if (me->query("max_neili") > 2000 || me->query_skill("force") > 205)
        {
              command("shake");
              command("say �ҽ����Խ���Ϊ������Ϊ�Σ�����ڹ���Ϊ������������;���ٲ����������ڽ�����");
              command("say �㻹����ذɣ�");
              return 1;
        }

        if (me->query_skill("sword", 1) < 120)
              return "�����������Ϊ���㣬�޷�ѧϰ���콣��\n";

        if (me->query_skill("dodge") < 180)
              return "���Ṧ��Ϊ���㣬�޷�ѧϰ���콣��\n";
 
        command("nod");
        command("say ��Ȼ�����Ϸ�ͽ����콣�����㣬��ɿ����ˣ�");
        message_vision(HIC "$N" HIC "�������콣����ͷ��β��$n" HIC "��ʾ��һ�飡\n" NOR,
                       this_object(), me);
        command("haha");
        tell_object(me, HIG "��ѧ���ˡ����콣����\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("dodge"))
                me->improve_skill("dodge", 1500000);
        me->improve_skill("martial-cognize", 1500000);

        command("say ����˶��پͿ���������ˣ�ʣ�µľͿ����Լ���ȥ��ϰ��");

        lv = me->query("int");
        if (lv <= 30)
               me->set_skill("kuangfeng-jian", lv);
        else
               me->set_skill("kuangfeng-jian", 30 + (lv - 30) * 2);
        
        return 1;
       
}

void unconcious()
{
        die();
}