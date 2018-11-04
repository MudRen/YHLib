// feng-buping.c  �ⲻƽ

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>

void create()
{
        set_name("�ⲻƽ", ({ "feng buping", "feng" }) );
        set("gender", "����");
        set("class", "swordsman");
        set("title", "��ɽ���ڵ�ʮ��������");
        set("age", 45);
        set("long", "�ⲻƽ�ǻ�ɽ���ڵ�һ���֣���������һ�Żƽ�������Ƥ��\n");
        set("attitude", "peaceful");
        set("str", 28);
        set("int", 32);
        set("con", 31);
        set("dex", 29);

        set("max_qi", 6300);
        set("max_jing", 2400);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

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

        set("inquiry", ([
                "����"     : "�ҽ��ڽ������棬����ѧ���ž��У�\n",
                "����"     : "�ҽ��ڽ������棬����ѧ���ž��У�\n",
                "����"     : "�Ҿ��ǽ��ڴ��ˣ�\n",
                "���콣" : "����ѧ�Ļ��������ҳ�ʦ�ܰɣ�\n",
        ]));

        set_temp("apply/attack", 220);
        set_temp("apply/defense", 220);
        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 200);

        create_family("��ɽ��", 13, "����");

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int accept_ask(object me, string topic)
{
        if (me->query("family/family_name") != "��ɽ��")
                return 0;

        switch (topic)
        {
        case "������ӿ" :
                if (me->query("max_neili") > 2000 || me->query_skill("force") > 205)
                {
                      command("shake");
                      command("say �ҽ����Խ���Ϊ������Ϊ�Σ�����ڹ���Ϊ������������;���ٲ����������ڽ�����");
                      return 1;
                }
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/kuangfeng-jian/yong",
                           "name"    : "������ӿ ",
                           "sk1"     : "kuangfeng-jian",
                           "lv1"     : 140,
                           "sk2"     : "dodge",
                           "lv2"     : 140, ]));
                break;

        case "�����������ɽ�" :
                if (me->query("max_neili") > 2000 || me->query_skill("force") > 205)
                {
                      command("shake");
                      command("say �ҽ����Խ���Ϊ������Ϊ�Σ�����ڹ���Ϊ������������;���ٲ����������ڽ�����");
                      return 1;
                }
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/huashan-jian/xian",
                           "name"    : "�����������ɽ�",
                           "sk1"     : "huashan-jian",
                           "lv1"     : 160,
                           "sk2"     : "dodge",
                           "lv2"     : 160, ]));
                break;

        default:
                return 0;
        }
}

void attempt_apprentice(object ob)
{
        command("say �ҴӲ���ͽ�ܣ�");
        return;
}
