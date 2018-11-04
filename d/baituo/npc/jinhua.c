#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��", ({ "jin hua", "jin", "hua" }));
        set("gender", "Ů��" );
        set("age", 24);
        set("long", "һ������ò���Ĺ��\n");
        set("shen_type", 1);
        set("combat_exp", 800);
        set("str", 18);
        set("dex", 18);
        set("con", 18);
        set("int", 18);
        set("gold_times", 1);
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "�𻨿����ţ��ҵ�����ô��ô��Ӵ��\n" NOR,
                CYN "��Ĩ�����᣺��ѽ���Һ�����ѽ��\n" NOR,
                CYN "��̾����˵������֪���������ܷ��ټ������\n" NOR
        }));

        set("inquiry",([
                "����"   : "��֪������������������������ҿ�����",
                "�廨Ь" : "�������廨Ь�𣿿���ҿ�����",
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ob = this_player();

        ::init();
        if (interactive(ob) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        say(CYN "�𻨵�����λ" + RANK_D->query_respect(ob) +
            CYN "�������ǰ���ɽׯ����Ӷ�ˡ����������Ϣ��\n" NOR);
}

int accept_object(object who, object ob)
{
        object obn;

        if (! who || environment(who) != environment())
		return 0;

        if (! objectp(ob))
		return 0;

        if (! present(ob, who))
                return notify_fail("��û�����������\n");

        if ((string)ob->query("id") != "xiuhua xie")
                return notify_fail(CYN "��˵�������������������\n" NOR);

        if (query("gold_times") < 1)
                return notify_fail(CYN "��˵�������Ѿ����廨Ь�ˡ�\n" NOR);

        write (CYN "\n��˫�������廨Ь���������µ��������"
               "����Ů������\n" NOR);

        message_sort(CYN "\n��Ĩ�˰����ᣬ������˼������λ" +
                     RANK_D->query_respect(who) + CYN "��Ц��"
                     "����ʵ��ûʲô���������㣬������֪��ɽ��"
                     "ͷ�и�Ǯ����ڴ��¡�����Ͱ�������㡣\n"
                     NOR, who);

        message_sort(HIY "\n$N" HIY "��𻨴Ӵ��°����һֻǮ"
                     "�䣬�Ȳ������ش�һ�������澹Ȼ����һ��"
                     "�Ѱ�����$N" HIY "���������ذѰ���װ����"
                     "���\n\n" NOR, who);

        obn = new("/clone/money/silver");
        obn->set_amount(20);
        obn->move(who, 1);

        set("gold_times", 0);
        destruct(ob);
        return 1;
}

void unconcious()
{
        die();
}
