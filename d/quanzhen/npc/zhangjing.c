#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("�ƾ�����", ({ "zhangjing daozhang", "zhangjing", "daozhang" }));
        set("long", @LONG
��λ��ȫ������ƹܾ���ĵ���������ǰ�ǳ�
������һ��˽�ӵķ��ӣ���Ϊ��Ľ������Ű�
����ȫ�����¡������Ͼ���Ϊ������ˣ�����
�ĸ������ò��Σ���Ҳ�������⣬���԰�����
�ĵ��ж������ˡ�
LONG);

        set("gender", "����");
        set("age", 36);
        set("class", "taoist");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 18);
        set("int", 18);
        set("con", 20);
        set("dex", 21);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 350);
        set("max_jing", 350);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 0);

        set("combat_exp", 20000);
        set("score", 15000);

        set_skill("force", 40);
        set_skill("quanzhen-xinfa", 40);
        set_skill("sword", 40);
        set_skill("quanzhen-jian",40);
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 40);
        set_skill("parry", 50);
        set_skill("unarmed",50);
        set_skill("strike",50);
        set_skill("haotian-zhang", 50);
        set_skill("literate",100);
        set_skill("taoism",80);

        map_skill("force", "quanzhen-xinfa");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 4, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" : "��ȫ��������µ����������ڡ�\n",
                "���¾�" : (: ask_me :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/grayrobe")->wear();

}

string ask_me()
{
        mapping fam;
        object ob;

        if (! (fam = this_player()->query("family"))
           || fam["family_name"] != "ȫ���")
                return "�����뱾�̺��޹ϸ����⻰�ɽ���Ū�������ˡ�";

        if (query("book_count") < 1)
                return "�������ˣ����¾��Ѿ�����ȡ���ˡ�";

        add("book_count", -1);
        ob = new(__DIR__"obj/daodejing-i");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾�������ȥ�ú��ж��������ĵط����������ҡ�";

}
