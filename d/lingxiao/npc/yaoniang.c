inherit NPC;

void create()
{
        set_name("���", ({ "yao niang", "yao", "niang" }) );
        set("gender", "Ů��" );
        set("long", "����ǰ����ڵ���̣��ܵð����ڳ��š�\n");
        set("age", 17);
        set("max_qi", 800);
        set("max_jing", 500);
        set("combat_exp", 10000);

        set("str", 16);
        set("con", 24);
        set("dex", 30);
        set("int", 27);

        set("attitude", "friendly");
        set("inquiry", ([
            	"������" : "��ү�Ӳ�֪Ϊʲô�����Լ��ص������˵��˼ʲô����",
            	"����"   : "û��үͬ�⣬���ǽ���ȥ�ġ�",
        ]) );

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}



