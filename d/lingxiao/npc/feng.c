#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({"feng wanli", "feng", "wanli"}));
        set("nickname", HIR "�������" NOR);
        set("long", "���������ǵ��������ӷ�����ǵ�����������\n"
                    "��Ϊ������͵�����佣������Ѹ�ݣ�����\n"
                    "���һ���˵��˸������������š�����֪Ϊ\n"
                    "�Σ�������һֻ�ֱ�,����ȫ�Ƿ�ŭ�ں�֮ɫ��\n");
        set("gender", "����");
        set("age", 34);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 4200);
        set("max_jing", 3500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 220);
        set("combat_exp", 1200000);

        set_skill("force", 220);
        set_skill("xueshan-neigong", 220);
        set_skill("dodge", 220);
        set_skill("taxue-wuhen", 220);
        set_skill("cuff", 200);
        set_skill("lingxiao-quan", 200);
        set_skill("strike", 200);
        set_skill("piaoxu-zhang", 200);
        set_skill("sword", 240);
        set_skill("hanmei-jian", 240);
        set_skill("yunhe-jian", 240);
        set_skill("xueshan-jian", 240);
        set_skill("parry", 220);
        set_skill("literate", 200);
        set_skill("martial-cognize", 200);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "xueshan-jian");
        map_skill("parry", "yunhe-jian");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        create_family("������", 6, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.chu" :),
                (: perform_action, "cuff.jue" :),
                (: perform_action, "strike.piao" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �Ҳ���ͽ������ҹ�����");
}

int accept_fight(object who)
{
        command("say ����Ϊ������һ�۱���۸������ҹ�����");
        return 0;
}

int accept_hit(object me)
{
        object obj = this_object();
        command("say �޳�֮ͽ������Ϊ������һ�۱��������׸�����ɣ�\n");
        this_player()->kill_ob(obj);
        kill_ob(me);
        return 1;
}
