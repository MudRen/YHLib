#include <ansi.h>
inherit NPC;

string ask_pai();
void create()
{
        set_name("����ѧ",({"cheng zixue", "cheng"}));
        set("long", "����ѧ��ѩɽ���������������������ڵ�ʦ�ܡ�\n");
        set("gender", "����");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3800);
        set("max_jing", 3000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 180);
        set("combat_exp", 1000000);

        set("inquiry", ([
             	"����"   : (:ask_pai:),
                "������" : (:ask_pai:),
        ]) );

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
        set_skill("literate", 220);
        set_skill("martial-cognize", 180);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "xueshan-jian");
        map_skill("parry", "yunhe-jian");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        create_family("������", 5, "ǰ��");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.chu" :),
                (: perform_action, "sword.feng" :),
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
        command("say �Ϸ���ͽ����ȥ������Щͽ���ɡ�");
}

string ask_pai()
{
        object me,ob;
        me=this_player(); 


        if (me->query("family/master_id") == "bai zizai")
        {
                command("say ��Ȼ�ǳ����ĵ��ӣ��Ϸ���ͽ����Ƹ��㡣\n");
                message_vision(HIC "����ѧ�ó�һ�����ƣ�����$N"
                               HIC "��\n\n" NOR, me);
                ob = new("/d/lingxiao/obj/yupai");
                ob->move(me);
                return "�������ߡ�\n";
        }
        if (me->query("family/master_id") == "bai wanjian")
        {
                command("say ���Ȼ�ǰ��򽣵ĵ��ӣ���ȥҲ�޷���");
                message_vision(HIC "����ѧ�ó�һ�����ƣ�����$N"
                               HIC "��\n\n" NOR, me);
                ob=new("/d/lingxiao/obj/yupai");
                ob->move(me);
                return "�����˱����ر���������ʧ��\n";
        }
        command("say ����ʲô��ݣ�Ҳ��ȥ����ү�ӣ�");
        message_vision(HIY "����ѧת����ȥ��������$N"
                       HIY "��\n\n" NOR, me);

        return "�㻹����ȥŬ�������ɡ�\n";
}

