inherit NPC;

void create()
{
        set_name("����", ({ "su pu", "su", "pu" }));
        set("gender", "����");
        set("age", 23);
        set("long", "һ������Ĺ����������ˣ������˵�һ��ʿ��³�˵Ķ��ӡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("shen", 3000);
        set("str", 36);
        set("int", 20);
        set("con", 24);
        set("dex", 20);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 80);
        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_temp("apply/attack", 60);
        set_temp("apply/defense", 60);
        set_temp("apply/unarmed_damage", 60);
        set("inquiry", ([
            	"����" : "���������ţ���ô�ţ��������Ǿ�ˤˤ�ӡ�\n",
            	"������" : "̾����֪�����Ķ�ȥ�ˡ���ô������һֱû����������\n",
            	"������" : "�����˻����������ҵ����ƣ���ҽţ����ƥ�ļ�����\n",
        ]) );

        setup();
        carry_object(__DIR__"obj/duandao")->wield();
        carry_object(__DIR__"obj/ycloth")->wear();
}