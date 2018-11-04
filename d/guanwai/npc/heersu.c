#include <ansi.h>
inherit KNOWER;

string ask_me();

void create()
{
	set_name("�ն���", ({ "he ersu", "he", "ersu", "heersu" }));
	set("long", "����һ���ϲοͣ�����һƶ��ϴ��\n");
	set("title", WHT "�ο�" NOR);
	set("age", 65);
        set("combat_exp", 300);
        set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
        set("attitude", "friendly");
        set("inquiry", ([
		"�˲�" : (: ask_me :),
		"ɽ��" : (: ask_me :),
        ]));

        if (random(10) > 5)
                set("count", 1);

        setup();
	carry_object("/d/city/obj/cloth")->wear();
	carry_object("/d/quanzhen/npc/obj/stick")->wield();
}

string ask_me()
{
        object me = this_player();

        if (query("count") < 1)
        {
                return "�ٺ٣����´������ɣ�����������Ҳû����\n";
        } else
        if (me->query_temp("tmark/��"))
        {
                return "�㵽�״�������Щʲô��\n";
        } else
        {
                me->set_temp("tmark/��", 1);
                return "������������˿���ɽ�Σ��������Ƚ�Ǯ��\n";
        }
}

int accept_object(object who, object ob)
{
        object obj;

        if (! ob->query("money_id"))
        {
                write(CYN "�ն��ղ����˵��������������ʲô��\n" NOR);
                return 0;
        }

        if (query("count") < 1)
        {
                write(CYN "�ն���ҡͷ��������´ΰɣ�����������Ҳû����\n" NOR);
                return 0;
        }

        if (! who->query_temp("tmark/��"))
        {
                write(CYN "�ն����ɻ�������ֲ�����ؤ��û�¸���Ǯ������\n" NOR);
                return 0;
        }

        if (ob->value() < 100000)
        {
                write(CYN "�ն�����Ц�����ٺ٣�������ô��Ǯ�ģ�\n" NOR);
                return 0;
        }

        obj = new("/clone/fam/pill/renshen1");
        obj->move(this_object());

        add("count", -1);
        command("give bainian renshen to " + who->query("id"));
        write(CYN "�ն���˵������Ȼ��������ۣ���������˲ξ͸����ɡ�\n" NOR);
        return 1;
}
