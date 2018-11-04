#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ʱ����", ({"shi wannian", "shi", "wannian"}));
        set("gender", "����");
        set("long", "���������ǵ���������ʱ���꣬���Ǽ̰��򽣡���\n"
                    "������书��ߡ�������ĵ��ӡ���ʱ���ڴ���\n"
                    "��������\n");
        set("age", 24);
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);

        set("max_qi", 1500);
        set("max_jing", 1200);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 120);
        set("combat_exp", 800000);

        set("chat_chance", 8);
        set("chat_msg", ({
        	CYN "ʱ����޺�˵�����Ϸ��Ӳ�֪������ô�ˣ����Լ���������Ū�����ϳ�����\n" NOR,
       		CYN "ʱ����ѽ�һ������Ȼ�������������⣬˭��������Ϸ��ӷų�����\n" NOR,
        }) );

        set_skill("force", 160);
        set_skill("xueshan-neigong", 160);
        set_skill("dodge", 160);
        set_skill("taxue-wuhen", 160);
        set_skill("cuff", 160);
        set_skill("lingxiao-quan", 160);
        set_skill("strike", 160);
        set_skill("piaoxu-zhang", 160);
        set_skill("sword", 180);
        set_skill("hanmei-jian", 180);
        set_skill("yunhe-jian", 180);
        set_skill("parry", 160);
        set_skill("literate", 120);
        set_skill("martial-cognize", 80);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "yunhe-jian");
        map_skill("parry", "hanmei-jian");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        create_family("������", 6, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chong" :),
                (: perform_action, "cuff.jue" :),
                (: perform_action, "strike.piao" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/clone/weapon/changjian")->wear();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �Ҳ���ͽ����ȥ��������ʦ�ֺ��ˡ�");
}

void init()
{ 
        object ob;
        ::init();

        ob = this_player();

      	if (ob->query("family/family_name") != "������")
        {
                command("heng");
                command("say ���Ȼ�Ҵ��뱾�ɽ��أ������ɣ�\n");
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        } else
        if (ob->query("family/master_name") == "������")
        {
                command("say ʦ�ֻ����ˣ���ȥ��ʦ��ɣ�����С�ĵ㡭��û׼���ַ����ˡ�");
        } else
        if (ob->query("family/master_name") == "����")
        {
                command("say ���ǰ�ʦ��ĵ��Ӱɣ���ү�Ӿ������棬���Ĳ�Խ��Խ����������");
        }
}
