#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "a da", "a", "da" }));
        set("long", "�˱��񽣷�������ؤ���Ĵ���֮�ף�����\n"
                    "֮��������������ֻ����������죬������\n"
                    "���߰����ֱ�һ�㣬����ϵ��������š�\n"
                    "ʮ����ǰ��˵����Ⱦ�ز���������ʱ���˶�\n"
                    "����ϧ��������������������\n");
        set("title", "ؤ���Ĵ���֮��");
        set("nickname", HIW "�˱���" NOR);
        set("gender", "����");
        set("age", 68);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("per", 20);
        set("str", 45);
        set("int", 45);
        set("con", 45);
        set("dex", 45);
        
        set("max_qi", 6000);
        set("max_jing", 2000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 150);
        set("combat_exp", 2000000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("literate", 200);
        set_skill("begging", 200);
        set_skill("checking", 200);
        set_skill("force", 280);
        set_skill("dodge", 260);
        set_skill("unarmed", 260);
        set_skill("parry", 280);
        set_skill("strike", 260);
        set_skill("sword", 280);
        set_skill("feiyan-zoubi", 260);
        set_skill("huntian-qigong", 280);
        set_skill("kuangfeng-jian", 280);
        set_skill("dragon-strike", 260);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "huntian-qigong");
        map_skill("strike", "dragon-strike");
        map_skill("parry", "kuangfeng-jian");
        map_skill("sword", "kuangfeng-jian");

        prepare_skill("strike", "dragon-strike");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("begin","bi");
}

int accept_fight(object who)
{
        command("say û�����ķԸ��Ҳ�����֡�");
        return 0;
}

int accept_hit(object who)
{
        command("say û�����ķԸ��Ҳ�����֡�");
        return 0;
}

int accept_kill(object who)
{
        command("say û�����ķԸ��Ҳ�����֣�ɱ����Ҳһ����");
        return notify_fail("ɲ�Ǽ���ֻ�����²����֡�\n");
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬����ֻ��¥����Ӱ��"
                           "�����������������\n");
}

int begin()
{
        object weapon, env, shelf, sword;
        object me = this_player();
        object obj = this_object();
        env = environment(this_object());
        shelf = present("shelf", env);
        sword = present("yitian jian", shelf);

        if (objectp(present("a er", environment())))
        return 0;

        if (! me->query_temp("win_aer"))
        {
                command("heng");
                command("say ������˭��Ϊ�θղŲ���ս���������û�����ˡ�");
                return notify_fail("���������󲢲�����������\n");
        }

        if (! objectp(weapon = me->query_temp("weapon")))
        {
                command("say ��ֻ����ȱ�������");
                return notify_fail("���������󲢲�����������\n");
        }

        if (sword)
        {
                command("nod");
                command("bow");

                message_vision(CYN "ͻȻ�����ȵ��������ţ��������콣��$n" CYN
                               "������\n" NOR, obj, this_player());

                message_vision(CYN "����΢΢���˵�ͷ����������������\n\n" NOR,
                               obj, this_player());

                message_vision(CYN "��������ǰ��������" NOR + RED "��ľ����"
                               NOR + CYN "��һ�ģ��Ǻų����µ�һ�����" NOR +
                               WHT "���콣" NOR + CYN "��ʱ���Ծ�𣬷��簢��"
                               "���С�\n\n" NOR, obj, this_player());

                message_vision(HIW "ֻ����ಡ���һ���ƿ����죬�ų����µ�һ��"
                               "�������콣�ѱ������������С�\n\n" NOR, this_object(),
                               this_player());

                sword->move(this_object());
                sword->wield();

                command("say �����ˡ�");

                message_vision(HIR "��������һ����Х���������콣��â��ʱ������"
                               "������ˢˢˢˢ��������������$n" HIR "����Ҫ����"
                               "����ȥ��\n��֮�죬����֮��������ȷ����������"
                               "\n\n" NOR, this_object(),this_player());
        }

        call_out("do_unwield",3);
        me->set_temp("bi",1);
        set("anti",me);
        obj->kill_ob(this_player());
        this_player()->kill_ob(obj);
        return 1;
}

void unconcious()
{
        object ob;
        object me = this_player();

        if (objectp(query("anti")))
        {
                message_vision(HIR "\n$n" HIR "���������������е����������б�"
                               "�����������������е����콣����Ȧס������ٸв���"
                               "����Ҫ������\n����ֻ���ؿ�һ�������$n" HIR "��"
                               "�����Ѿ����ض��롣\n\n" NOR, this_object(),
                               query("anti"));

                message_vision(HIR "$n" HIR "���Ʋ����ˣ�����������������������"
                               "��ȫ����������������ϡ�\n\n" NOR, this_object(),
                               query("anti"));

                message_vision(CYN "\n����һ��������ʱ�Ұף�̾�˿�����˵������"
                               "�ܺã������콣�����ȥ�ɣ���\n" NOR,
                               this_object());

                message_vision(CYN "��������$n" CYN "��ȻһЦ���漴������������"
                               "������˵������¹�������������������ˡ���\n" NOR,
                               this_object(), query("anti"));

                message_vision(HIR "ֻ�������������������Ӱ���໥ʹ�˸����񣬶�"
                               "����˵������$n" HIR "ֱ�˹�������\n" NOR,
                               this_object(), query("anti"));

                query("anti")->delete_temp("bi");
                query("anti")->delete_temp("win_he");
                query("anti")->delete_temp("win_asan");
                query("anti")->delete_temp("win_aer");

                ob = new("/d/tulong/yitian/npc/hebiweng");
                ob->move("/d/tulong/yitian/was_lou4");
                if (objectp(ob)) ob->kill_ob(query("anti"));

                ob = new("/d/tulong/yitian/npc/luzhangke");
                ob->move("/d/tulong/yitian/was_lou4");
                if (objectp(ob)) ob->kill_ob(query("anti"));

                ob = present("zhao min");
                if (objectp(ob)) destruct(ob);

        }
        ::die();
}
