inherit NPC;

void create()
{
        set_name("��Ӣ", ({ "cheng ying", "cheng", "ying" }));
        set("gender", "Ů��" );
        set("age",18);
        set("long", "��Ӣ�ǻ�ҩʦ��С�����Ĺ�Ů���ɻ�ҩʦ����\n"
                    "�̵���һ�����˳ƾ�������ַ�������һ���\n"
                    "����ʳ����������\n");
        set("per", 30);
        set("class", "scholar");
        set("combat_exp", 10000);

        set_skill("unarmed", 50);
        set_skill("luoying-shenzhang", 50);
        set_skill("dodge", 50);
        set_skill("anying-fuxiang", 50);
        set_skill("force", 50);
        map_skill("dodge", "anying-fuxiang");
        map_skill("unarmed","luoying-zhang");

        create_family("�һ���", 3, "����");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
