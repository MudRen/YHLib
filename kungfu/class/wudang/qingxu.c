inherit NPC;

string ask_me();

void create()
{
        set_name("�������", ({ "qingxu daozhang", "qingxu" }));
        set("long", "�����������۵ĵ�������������������\n"
                    "ʮ���꣬���ܸ���۵����¡�ר��������\n"
                    "���ر��ɵĸ��ֵ���");
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 22);
        set("con", 22);
        set("dex", 22);
        
        set("max_qi", 1800);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 30);

        set("combat_exp", 300000);
        set("score", 10000);

        set_skill("force", 100);
        set_skill("wudang-xinfa", 100);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 80);
        set_skill("strike", 100);
        set_skill("wudang-zhang", 100);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("wudang-jian", 80);
        set_skill("taoism", 100);
        set_skill("literate", 80);
        set_skill("martial-cognize", 60);

        map_skill("force", "wudang-xinfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");
        map_skill("strike", "wudang-zhang");

        prepare_skill("strike", "wudang-zhang");

        create_family("�䵱��", 3, "����");
        set("class", "taoist");

        set("inquiry", ([
        	"���¾�" : (: ask_me :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.sheng" :),
		(: exert_function, "recover" :),
	}) );
                                
        set("book_count", 1);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}


string ask_me()
{
        mapping fam; 
        object ob;

        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "�䵱��")
        {
                return RANK_D->query_respect(this_player()) + 
                       "�뱾��������������֪�˻��Ӻ�̸��";
        }

        if (query("book_count") < 1)
                return "�������ˣ����ɵĵ����澭���ڴ˴���";

        add("book_count", -1);
        ob = new("/clone/book/daodejing-ii");
        message_vision("$N�ó����¾����¾�(jing)��$n��\n",
                       this_object(), this_player());
        ob->move(this_player(), 1);
        return "�ðɣ��Ȿ�����¾������û�ȥ�ú����С�";
}
