#include <ansi.h>
#include "xiaoyao.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

string ask_me();

void create()
{
	set_name("����", ({ "gou du", "gou", "du" }));
	set("long", "������ȥҲ�Ǽ�ʮ������ˣ�ȴ�Ǵ�Ȼһ��\n"
                    "����ӵ�ģ����\n");
	set("title", "��ң�ɺ��Ȱ���");
	set("nickname", WHT "���" NOR);
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);

	set("inquiry", ([
		"����" : (:ask_me:),
	]) );

	set("max_qi", 1800);
	set("max_jing", 1800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 60);
	set("combat_exp", 300000);

        set_skill("force", 120);
        set_skill("xiaoyao-xinfa", 120);
        set_skill("dodge", 100);
        set_skill("feiyan-zoubi", 100);
        set_skill("strike", 100);
        set_skill("panyang-zhang", 100);
        set_skill("hand", 100);
        set_skill("qingyun-shou", 100);
        set_skill("parry", 100);
        set_skill("blade", 80);
        set_skill("ruyi-dao", 80);
        set_skill("literate", 220);
        set_skill("martial-cognize", 80);

	map_skill("force", "xiaoyao-xinfa");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("hand", "qingyun-shou");
	map_skill("strike", "panyang-zhang");
	map_skill("parry", "panyang-zhang");
	map_skill("blade", "ruyi-dao");

        prepare_skill("hand", "qingyun-shou");
        prepare_skill("strike", "panyang-zhang");

        set("coagents", ({
                ([ "startroom" : "/d/xiaoyao/muwu1",
                   "id"        : "kang guangling" ]),
                ([ "startroom" : "/d/xiaoyao/muwu2",
                   "id"        : "xue muhua" ]),
        }));

	create_family("��ң��", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.zhuo" :),
                (: perform_action, "strike.pan" :),
                (: exert_function, "recover" :),
        }));

	set("book_count", 1);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 26)
        {
                command("say ��������ͷ��̫�����ϡ���ô�ܹ���ң��");
                return;
        }

        command("say ���ã����ã�");
        command("say ��ͽ��Զ�����������ֺ���");
        command("recruit " + ob->query("id"));
}

string ask_me()
{
	object me, ob, book;

	ob = this_player(); 
        me = this_object();

        if (ob->query("family/family_name") != "��ң��")
                return "������Ҫ��";

	if (ob->query("family/master_id") == "wuya zi" ||
           ob->query("family/master_id") == "su xinghe")
	{
		call_other("/clone/book/lbook4", "???");
                book = find_object("/clone/book/lbook4");
                if (! objectp(book) || environment(book))
                        return "�������ˣ��Ǳ���������Ѿ����͸������ˡ�";

		command("say ��Ҫ�Ȿ����ô����ֻ����ȥ���ǡ�");
		message_vision(HIY "$N" HIY "�ӻ����ͳ�һ�����飬���˸�$n"
                               HIY "��\n" NOR, me, ob);
	        book->move(ob, 1);
		return "�Ȿ���ǧ��Ҫ������˰�������һ��Ͳ������ˡ�\n";
	}

        if (query("book_count") < 1)
                return "��������ͷû��ʲô���ˡ�";

        add("book_count", -1);
	command("say �����������û���ˣ����������ɸ��ִ����ֵ������顣");
	command("say ��Ȼ����ô��ѧ���ҾͰ����͸���ɡ�");
	message_vision(HIY "$N" HIY "���䵹�����˰��죬�ҳ�һ�����飬���˸�$n"
                       HIY "��\n" NOR, me, ob);
	if (random(2) == 1)
                book = new("/clone/book/strike_book");
	else
                book = new("/clone/book/book-paper");
	book->move(ob, 1);

	return "�Ȿ���ǧ��Ҫ������˰�������һ��Ͳ������ˡ�\n";
}
