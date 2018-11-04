#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�Ŵ�ɽ", ({ "zhang cuishan", "zhang" }));  
        set("nickname", WHT "��������" NOR);
        set("long", @LONG
�����������������ӡ��䵱����֮�е��Ŵ�
ɽ����һ���ɸɾ����İ�ɫ���ۡ�
LONG);
        set("gender", "����");
        set("age",31);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 35);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 150);
        set("combat_exp", 1400000);
        set("score", 60000);

        set_skill("force", 220);
        set_skill("wudang-xinfa", 220);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 220);
        set_skill("tiyunzong", 220);
        set_skill("unarmed", 200);
        set_skill("taiji-quan", 180);
        set_skill("strike", 220);
        set_skill("yitian-zhang", 220);
        set_skill("wudang-zhang", 200);
        set_skill("hand", 200);
        set_skill("paiyun-shou", 200);
        set_skill("parry", 200);
        set_skill("sword", 220);
        set_skill("wudang-jian", 220);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 180);
        set_skill("martial-cognize", 200);

        set("no_teach", ([
                "taiji-shengong" : "Ҫ��ѧϰ̫����������������̡�",
                "taiji-jian"     : "̫���������������״���",
                "taiji-quan"     : "̫��ȭ�����������״���",
        ]));

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        map_skill("strike", "yitian-zhang");

        prepare_skill("strike", "yitian-zhang");

        create_family("�䵱��", 2, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zheng" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }));

        setup();

        carry_object("/d/wudang/obj/whiterobe")->wear();
}

int accept_fight(object who)
{
        command("say ���ǲ�������ܵģ�");
        return 0;
}

int accept_hit(object who)
{
        command("say ���ǲ�������ܵģ�");
        return 0;
}

int accept_kill(object who)
{
        command("say ��ô��Ҫ����ô������������ɲ����㣡");
        return notify_fail("ɲ�Ǽ�����û��ǲ�Ҫ�������Ϊ�á�\n");
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬����ֻ���᳡���ѹѹ�ļ�����"
                           "�ˣ��������������\n");
}

void receive_damage(string type)
{
        return;
}

void receive_wound(string type)
{
        return;
}

int begin(object me)
{
        if (me->query_temp("compare"))
                return notify_fail("���ںͱ��˱����أ���ʲô����\n");

        me->set_temp("compare", 1);

        command("say �����书��ǿ������ִ�������ȥ��ȴ������"
                "����һ���˵�������");

        remove_call_out("compare1");
        call_out("compare1", 3, me);
        me->set_temp("bizhang", 1);
        return 1;
}

void compare1(object me)
{
        if (me->query("family/family_name") != query("family/family_name"))
                message_vision(CYN "\n$N" CYN "��Ц�������ʸ�����˭"
                               "��ƾʲô���ҷ���ʩ�������������"
                               "���ԡ�\n" NOR, me);
        else
                message_vision(CYN "\n$N" CYN "����������Ȼ����ͬ��"
                               "�䵱�����������˲���֮��ҿ�����"
                               "������\n\n" NOR, me);

        remove_call_out("compare2");
        call_out("compare2", 3, me);
}

void compare2(object me)
{
        command("say �Ҳ������ܣ�ֻ�Ǳ�д�����֡�");
        message_vision(HIR "\n�Ŵ�ɽ˵�Ż����ߵ�����ɽ��ǰһ�´�ʯ��"
                       "ǰ���͵���˫��һ�ţ��������\n" NOR,
                       this_object());
        remove_call_out("compare3");
        call_out("compare3", 4, me);
}

void compare3(object me)
{
        message_vision(HIR "\n�Ŵ�ɽ�����������࣬����ʹ���������ݡ���"
                       "�����ҽ���ɽ��һ���������ɡ�\n\nֻ���������й�"
                       "�ʿ�׼ʯ�棬�����ͼ�������д��һ����" HIY "��"
                       HIR "���֡�\n" NOR, this_object());

        remove_call_out("compare4");
        call_out("compare4", 4, me);
}

void compare4(object me)
{
        message_vision(HIR "\n�Ŵ�ɽһ����д�꣬���ӱ�Ҫ���£�ͻȻ����"
                       "�ӳ����������գ�ٿ��һ����סʯ�ڡ�\n\n��ʱ����"
                       "���÷�϶֧ס���ӵ����������ָ�����д�˸���" HIY
                       "��" HIR "���֡�\n" NOR, this_object());

        remove_call_out("compare5");
        call_out("compare5", 4, me);
}

void compare5(object me)
{
        message_vision(HIR "\n�Ŵ�ɽ������д�գ�������д����" HIY "��"
                       HIR "���ֺ͡�" HIY "��" HIR "���֣�����ʯм�׷�"
                       "���¡�\n\n�ּ������������ڣ�������������������"
                       "���ʮ����һ��д�ϡ�\n" NOR, this_object());

        remove_call_out("compare6");
        call_out("compare6", 4, me);
}

void compare6(object me)
{
        message_vision(HIR "\n��һ��ʯ�ڿ��飬���������ʫ�ƣ�\n\n"
                       HIW "\t\tƮ�����꾪�쪣��仨��ѩ��ãã��\n\n"
                       "\t\t������ڲ�ͣ�֣�һ�����ִ��綷��\n\n"
                       "\t\t�л����Ź��񾪣�ʱʱֻ�������ߡ�\n\n"
                       "\t\t���������羪�ף�״ͬ�����๥ս��\n\n" NOR,
                       this_object());

        remove_call_out("compare7");
        call_out("compare7", 4, me);
}

void compare7(object me)
{
        message_vision(HIR "\n�Ŵ�ɽд����" HIY "��" HIR "���ֵ����һ"
                       "�ʣ�������ʯ����һ�ţ����������������������ԡ�"
                       "\n" NOR, this_object());

        message_vision(CYN "\n$N" CYN "������ʯ���������д��֣�������"
                       "�ã�û��������\n" NOR, me);
        remove_call_out("shu");
        call_out("shu", 6, me);
}

void shu(object me)
{
        message_vision(CYN "\n$N" CYN "̾�˿�����˵������д����������"
                       "���ˡ����ʸ����кηԸ���\n"NOR, me);
        me->delete_temp("bizhang");
        me->set_temp("shu", 1);
        remove_call_out("end");
        call_out("end", 5, me);
}

void end(object me)
{
        object ding, dao;
        object obj = present("yin susu");

        command("say ������ʤ�ˣ���������һ���˵������������߰ɡ�");

        me->delete_temp("compare");
        ding = present("ding", environment());
        dao = present("tulong dao", ding);

        if (objectp(dao))
        {
                GIFT_D->delay_gift_bonus(me, ([ "temp"    : "skybook/tulong/tulongdao",
                                                "prompt"  : "��ͨ��ȡ���������ľ���",
                                                "rumor"   : "������ɽ�����ܸ�·Ӣ"
                                                            "�����������������",
                                                "exp"     : random(15000) + 10000,
                                                "pot"     : random(1000) + 1000,
                                                "mar"     : random(1000) + 1000,
                                                "score"   : random(5000) + 3000,
                                                "weiwang" : random(5000) + 3000, ]));
                tell_object(me, HIM "\n��õ�������������\n" NOR);
                me->set_temp("have_tulongdao");
                dao->move(me, 1);
        }
        message_vision(HIC "\n$N" HIC "��$n" HIC "�������ϴ����﷫��ȥ"
                       "��\n\n" NOR, me, this_object());

        if (objectp(obj))
                obj->move("/b/tulong/boat");

        this_object()->move("/b/tulong/boat");
        me->move("/b/tulong/boat");

        remove_call_out("storm");
        call_out("storm", random(30), me);
}

void storm(object me)
{
        message_vision(HIB "\nͻȻ֮�䣬$N" HIB "����һ�࣬���˼�"
                       "��ת��ֻ���ü����Х��\n���˺��֮������"
                       "��ǧ�ٸ�����ͬʱϮ����\n" NOR, this_object());
        remove_call_out("storm2");
        call_out("storm2", 4, me);
}

void storm2(object me)
{
        message_vision(HIB "\n�ŵ��²հ嶷Ȼ�������ȥ�����еĺ�ˮ"
                       "�����⵹к��\n�����ÿ���Х�����ܾ��Ǻ�ˮ"
                       "��\n" NOR, this_object());
        remove_call_out("storm3");
        call_out("storm3", 4, me);
}

void storm3(object me)
{
        message_vision(HIB "\n������������ɢ����¶����ҹ֮�⡣\n\n"
                       "������������Ʈ����\n" NOR, this_object());
        remove_call_out("storm4");
        call_out("storm4", 4, me);
}

void storm4(object me)
{
        message_vision(HIB "\n������������Ʈ����\n" NOR,
                       this_object());
        remove_call_out("storm5");
        call_out("storm5", 4, me);
}

void storm5(object me)
{
        message_vision(HIB "\n������������Ʈ����\n" NOR,
                       this_object());
        remove_call_out("storm6");
        call_out("storm6", 4, me);
}

void storm6(object me)
{
        message_vision(HIB "\n������������Ʈ����\n" NOR,
                       this_object());
        remove_call_out("arrive");
        call_out("arrive", 4, me);
}

void arrive(object me)
{
        object obj = present("yin susu");

        if (objectp(obj))
                obj->move("/b/tulong/boat3");

        message_vision(HIY "\nֻ��������һ�������ⷽʻ���������ص�"
                       "��ԭ�ˡ�\n\n" NOR, this_object());

        this_object()->move("/b/tulong/boat3");
        me->move("/b/tulong/boat3");

        message_vision(CYN "\n�Ŵ�ɽ��ȭ˵�������Ǿʹ˱����������ڡ�"
                       "\n\n" NOR, me, this_object());
}

void init()
{
       add_action("do_get", "get");
}

int do_get(string arg)
{
        object obj, env, ding;
        string what, where;

        env = environment(this_player());

        if (env->short() != "�ﵶ�����᳡")
                return 0;

        if (! arg)
                return 0;

        if (sscanf(arg, "%s from %s", what, where) != 2)
                return 0;

        if (objectp(present("mai jing", environment()))
           || objectp(present("guo sanquan",environment())))
              return 0;

        if (where == "ding")
        {
                message_vision(CYN "$N" CYN "˵���������䵱�Ŵ�"
                               "ɽ�����������ˣ�\n" NOR, this_object());
                this_player()->delete_temp("bizhang");
                begin(this_player());
                return 1;
        }
        return 0;
}

int attempt_apprentice(object ob)
{
        command("say ������û����ͽ��");
        return 0;
}

