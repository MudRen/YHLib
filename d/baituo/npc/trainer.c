inherit NPC;

void create()
{
        set_name("����", ({ "jiao lian", "jiao", "lian" }));
        set("gender", "����" );
        set("age", 25);
        set("long", "���Ǹ��Ͱ����׵Ľ�����\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 23);
        set("int", 23);
        set("con", 22);
        set("dex", 20);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 30000);
        set("score", 20000);

        set_skill("force", 60);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
        set_skill("parry", 60);
        set_skill("staff",60);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (ob->query("born_family") != "ŷ������")
        {
                command("shake");
                command("say �������ļһ��Ȼ��������ɽ���ң�");
                return;
        }

        command("say �Ǻǣ��Ҳ���ͽ��ȥ��ŷ��ׯ���ɡ�\n");
        return;
}

int accept_fight(object ob)
{
        if (ob->query("born_family") != "ŷ������")
        {
                command("shake");
                command("say �������ļһ��Ȼ��������ɽ���ң�");
                return 0;
        }

        command("say ������㻹���Լ�ȥ��ϰ�ɡ�");
        return 1;
}
