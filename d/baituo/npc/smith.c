
inherit "/inherit/char/smith.c";

void create()
{
        set_name("����", ({ "tie jiang", "tie", "jiang", "smith" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);

        set("gender", "����" );
        set("age", 33);
        set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

        set("combat_exp", 400);
	set("attitude", "friendly");
        set("vendor_goods",({
                   "/clone/weapon/changjian",
                   "/clone/weapon/tudao",
                   "/clone/weapon/tiegun",
                   "/clone/weapon/gangdao",
                   "/clone/cloth/tiejia",
        }));

        set("inquiry", ([
                "����" : (: ask_me :),
                "job"  : (: ask_me :),
        ]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}
