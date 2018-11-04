#include <ansi.h>

inherit NPC;
inherit F_GUARDER;

mixed ask_me();

void create()
{
        set_name("ƽ��", ({ "ping si", "ping", "si" }));
        set("gender", "����");
        set("age", 65);
        set("title", "������Ӷ");
        set("long", "���Ǻ������Ĺ��������ۡ�\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 4000);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("combat_exp", 150000);

        set_skill("force", 40);
        set_skill("blade", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("unarmed", 40);

        create_family("�������", 0, "��Ӷ");

        set("inquiry",([
        	"�ֻ�"   : "�ֻ����ߡ����������",
                "��һ��" : "�ǡ������������ˣ�����",
                "���˷�" : "������ɲ��ǻ��ˡ�",
                "�԰�ɽ" : "�����Ҽ����˵Ľ�������û��˵�ġ�",
                "����"   : (: ask_me :),
                "����"   : (: ask_me :),
                "��ȥ"   : (: ask_me :),
        ]));
        set("coagents", ({
                ([ "startroom" : "/d/guanwai/xiaowu",
                   "id"        : "hu fei" ]),
        }));

        setup();
        set("startroom", "/d/guanwai/xiaoyuan");
        carry_object("/clone/cloth/cloth")->wear();
}

mixed ask_me()
{
        object ob, me;
        me = this_player();

        if ((string)me->query("family/family_name") != "�������")
                return "���Լ�û����ô��";

        if (find_object(query("startroom")) != environment())
                return "�����ﻹ���£�����Լ��߻�ȥ�ɡ�";

        command("nod");
        command("say Ҫ��ȥ����ô�����ҽм�����������һ�̰ɡ�");

        message_sort(HIC "\nƽ�ĳ�Զ��һ���֣���ʱ�����ο͸�����ʻ��"
                     "������ƽ��Ц�����Ҽ�С����Ҫ���ذ���£����˾���"
                     "���������͡����ο�������æ��Ц�Ŵ�Ӧ��$N" HIC "��"
                     "״��æ������У�ֻ��һ�����ı��죬��������ȥ"
                     "��\n\n" NOR, me);

        ob = load_object("/d/beijing/majiu");
        ob = find_object("/d/beijing/majiu");
        me->move("/d/beijing/majiu");

        message("vision", HIC "\nԶ��һ������ʻ����������һ��" +
                          me->query("name") + HIC "���������˳�"
                          "����\n\n" NOR, environment(me), ({me}));

        tell_object(me, CYN "\n�ο�Ц������λ" + RANK_D->query_respect(me) +
                        CYN "�Ѿ����ˣ����³��ɡ�\n�ο�˵������Ҫ"
                        "�������Щ���飬�������" HIC "���" NOR +
                        CYN "�Ļ����һ������������㡣\n\n" NOR);
        return 1;

}
