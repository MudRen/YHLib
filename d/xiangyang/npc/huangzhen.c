inherit NPC;
inherit F_BANKER;

#include <ansi.h>

int do_join(string arg);
int do_unjoin(string arg);
int do_yao();
int do_decide();

void create()
{
        set_name("����", ({ "huang zhen", "zhen", "huang" }));
        set("long", @LONG
����������Գ������Ŀ��Ŵ���ӣ�Ҳ����
��Ǯׯ���ϰ壬�����������á�
LONG);
        set("nickname", HIY "ͭ��������" NOR);
        set("gender", "����");
        set("age", 59);
        set("attitude", "peaceful");
        set("per", 21);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 30);

        set("max_qi", 3500);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 300);
        set("jiali", 200);

        set("combat_exp", 500000);
        set("shen_type", 1);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("strike", 140);
        set_skill("cuff", 140);
        set_skill("sword", 140);
        set_skill("force", 140);
        set_skill("parry", 140);
        set_skill("dodge", 140);
        set_skill("literate", 60);

        set_skill("huashan-sword", 140);
        set_skill("huashan-xinfa", 140);
        set_skill("poyu-quan", 140);
        set_skill("hunyuan-zhang", 140);
        set_skill("feiyan-huixiang", 140);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "huashan-xinfa");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("dodge", "feiyan-huixiang");

        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");

        set("inquiry", ([
                "���"     : "����������Լ���(" HIY "join" NOR +
                             CYN ")��ҵЭ�ᡣ\n" NOR,
                "����"     : "����������Լ���(" HIY "join" NOR +
                             CYN ")��ҵЭ�ᡣ\n" NOR,
                "��ҵЭ��" : "����������Լ���(" HIY "join" NOR +
                             CYN ")��ҵЭ�ᡣ\n" NOR,
        ]));

        create_family("��ɽ��", 21, "����");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        add_action("do_join", "join");
        add_action("do_decide", "decide");
        add_action("do_yao", "yao");
        add_action("do_unjoin", "unjoin");
        delete_temp("busy");
}

int do_join(string arg)
{
        object me = this_player();

        if (! arg || arg != "��ҵЭ��")
                return notify_fail(CYN "����һ�㣬˵������Ҫ����ʲô����"
                                   "��������ҵЭ�ᡣ\n" NOR);

        if (me->query("is_vendor"))
                return notify_fail(CYN "����������ü��˵�����㲻���Ѿ���"
                                   "����ҵЭ����ô��\n" NOR);

        if (me->query("bad_vendor"))
                return notify_fail(CYN "������Цһ����˵������Ȼ���Ѿ���"
                                   "������ҵЭ�ᣬ�ֻ���������\n" NOR);

        tell_object(me, CYN "\n������˵�ͷ��˵��������Ĵ���(" HIY "dec"
                        "ide" NOR + CYN ")������ҵЭ��ô���ɿ�������ˣ�"
                        "\n" NOR);
        me->set_temp("want_join", 1);
        return 1;
}

int do_unjoin(string arg)
{
        object me = this_player();

        if (! arg || arg != "��ҵЭ��")
                return notify_fail(CYN "����������ü��˵�������������ʲ"
                                   "ô��˵�����岻���ġ�\n" NOR);

        if (! me->query("is_vendor"))
                return notify_fail(CYN "������Цһ����û���㡣\n" NOR);

        tell_object(me, CYN "\n����̾�˿�����˵�������������ҵЭ�ᣬ�Ժ�"
                        "�ɲ��ܷ��ڡ��������(" HIY "decide" NOR + CYN ")"
                        "��ô��ô��\n" NOR);
        me->set_temp("want_tuoli", 1);
        return 1;
}

int do_decide()
{
	object ob, me;
        me = this_player();

        if (me->query_temp("want_join"))
        {
                message_vision(HIC "$N" HIC "����$n" HIC "΢Ц���������"
                               "��Ǯ������֮��Ժ�úøɰɡ�\n" NOR,
                               this_object(), me);

                me->set("is_vendor", 1);
                me->delete_temp("want_join");

                ob = new("/clone/misc/shang-ling");
                ob->move(this_object());
                command("give shang ling to " + me->query("id"));
                return 1;
        } else
        if (me->query_temp("want_tuoli"))
        {
                message_vision(HIC "$N" CYN "����$n" HIC "���ͷ���˸���"
                               "־���Ӵ��Ժ��������޹ϸ�\n" NOR,
                               this_object(), me);

                me->delete("is_vendor");
                me->set("bad_vendor", 1);
                me->delete_temp("want_tuoli");

                if (objectp(ob = present("shang ling", me)));
                {
                        message_vision(HIR "$N" HIR "��$n" HIR "��" NOR +
                                       ob->name(1) + HIR "ע���ˡ�\n" NOR,
                                       this_object(), me);
                        destruct(ob);
                }
                return 1;
         }

         return notify_fail(CYN "����������һ�ۣ�������ü��û���㡣\n" NOR);
}

int do_yao()
{
        object ob, me = this_player();

        if (me->query("bad_vendor"))
                return notify_fail(CYN "���治�ͷ������߿����߿������ֻ�"
                                   "��������\n" NOR);

        if (! me->query("is_vendor"))
                return notify_fail(CYN "����������һ�ۣ�û���㡣\n" NOR);

        if (present("shang ling", me))
                return notify_fail(CYN "����������ü�����ҵ��죬�����ⶼ"
                                   "Ҫƭ����Ȼ�Ǽ��̵��ϡ�\n" NOR);

        if (me->query_temp("shang-ling"))
                return notify_fail(CYN "������ü�����ղ��Ҳ��ǲŸ�����һ"
                                   "��ô����ô���Ū���ˣ�\n" NOR);

        if (SHOP_D->is_owner(me->query("id")))
                return notify_fail(CYN "����΢Ц���������ڲ����Ѿ�������"
                                   "ô����Ҫ������\n" NOR);

        ob = new("/clone/misc/shang-ling");
        ob->move(this_object());
        me->set_temp("shang-ling", 1);
        command("give shang ling to " + me->query("id"));
        command("say �Է��ļһ��Լ����ܺã������������ҡ�");
        return 1;
}
