// challenge.c

#include <ansi.h>
#include <command.h>

inherit NPC;

object with_ob = 0;

void competition_with(object ob)
{
        NPC_D->set_from_me(this_object(), ob);
        with_ob = ob;
        command("yun powerup");
        ::competition_with(ob);
}

varargs int receive_damage(string type, int damage, object who)
{
        if (! objectp(with_ob) || objectp(who) && who != with_ob)
                return 0;

        return ::receive_damage(type, damage, who);
}

int accept_fight(object ob)
{
        if (query_competitor() == ob)
                return 1;

        if (ob->is_fightint())
                return notify_fail("�˼����ڱ����أ�����ô���ֲ�̫�׵��ɣ�\n");

        if (query("finished"))
                return notify_fail("�˼Ҹձ����䣬����ȥ�����ʲô��\n");

        return ACCEPT_CMD->main(ob);
}

int accept_hit(object ob)
{
        if (query_competitor() == ob)
                return 1;

        return accept_fight(ob);
}

int accept_kill(object ob)
{
        if (is_killing(ob->query("id")))
                return 1;

        return notify_fail("�ҿ����ֶ���ԭ�������������㻹�Ǳ����ˡ�\n");
}

int accept_touxi(object ob)
{
        if (is_killing(ob->query("id")))
                return notify_fail("�������ڽ����أ�͵Ϯʲô��");

        return notify_fail("�ҿ����ֶ���ԭ�������������㻹�Ǳ����ˡ�\n");
}

void lost()
{
        object ob;
        object story;
        string msg;
        int expi, poti, weiwangi, scorei;

        if (! objectp(ob = query_competitor()))
                return;

        if (! objectp(story = STORY_D->query_running_story()))
                return;

        story->stop_story();
        msg = query("chat_lost");
        if (! msg) msg = "���д�����ô����ô���ܻ�������";
        command("chat " + msg);
        CHANNEL_D->do_channel(this_object(), "rumor",
                "��˵" + ob->name() + "�����" + name() + "����������ԭ���ֵ����ϡ�");
        scorei = random(query("combat_exp") / 500) + 10;
        weiwangi = random(query("combat_exp") / 200) + 10;
        expi = random(NPC_D->check_level(this_object()) * 1000) + 10;
        poti = random(200) + 50;
        ob->add("score", 50 + scorei);
        ob->add("weiwang", weiwangi);
        ob->add("combat_exp", expi);
        ob->add("potential", poti);
        tell_object(ob, sprintf(HIC "������%s�㾭�顢%s��Ǳ�ܣ�����"
                                "����%s��������%s�㽭��������\n" NOR,
                        chinese_number(expi),
                        chinese_number(poti),
                        chinese_number(weiwangi),
                        chinese_number(scorei)));
        set("finished", 1);
        call_out("destruct", 0, this_object());
        ::lost();
}

void win()
{
        object ob;
        object story;
        string msg;

        if (! objectp(ob = query_competitor()))
                return;

        if (! objectp(story = STORY_D->query_running_story()))
                return;

        story->stop_story();
        ob->add("weiwang", -ob->query("weiwang") / 25);
        command("chat* haha");
        msg = query("chat_win");
        if (! msg) msg = "��ԭ���֣�����һ����";
        command("chat " + msg);
        CHANNEL_D->do_channel(this_object(), "rumor",
                "��˵" + ob->name() + "�����" + name() + "����������ԭ���ֵ����档");
        set("finished", 1);
        call_out("destruct", 0, this_object());
        ::win();
}
