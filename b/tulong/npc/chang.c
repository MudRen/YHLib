#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "chang jinpeng", "chang", "jinpeng" }));
        set("long", @LONG
�������ӥ����ȸ̳��̳����������ֻ������
ʮ������ͣ��������ϵļ��ⰼ��͹͹���̸�
��ڣ������书�˵á�
LONG);
        set("title", "��ӥ��");
        set("nickname", HIR "��ȸ̳��" NOR);
        set("attitude", "heroism");
        set("age", 50);
        set("str", 60);
        set("int", 35);
        set("con", 35);
        set("dex", 35);
        
        set("max_qi", 3500);
        set("max_jing", 3500);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 10000);

        set_skill("force", 200);
        set_skill("riyue-xinfa", 200);
        set_skill("dodge", 180);
        set_skill("feiyan-zoubi", 180);
        set_skill("hammer", 180);
        set_skill("pangu-qishi", 180);
        set_skill("parry", 180);
        set_skill("cuff", 180);
        set_skill("zhenyu-quan", 180);
        set_skill("claw", 180);
        set_skill("poyue-zhao", 180);
        set_skill("martial-cognize", 180);
        set_skill("literate", 100);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "riyue-xinfa");
        map_skill("hammer", "pangu-qishi");
        map_skill("parry", "pangu-qishi");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        create_family("��ӥ��", 2, "̳��");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.kai" :),
                (: exert_function, "recover" :),
                CYN "�������ȵ��������������֣�\n" NOR,
                CYN "�������ȵ���������������\n" NOR,
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object(__DIR__"obj/jiaofu")->wear();
        carry_object(__DIR__"obj/hammer")->wield();
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬����ֻ���᳡���ѹ"
                           "ѹ�ļ������ˣ��������������\n");
}

void init()
{
        add_action("do_compare", "compare");
        add_action("do_get", "get");
}

int do_get(string arg)
{
        object obj = this_object();
        string what, where;

        if (! arg)
                return 0;

        if (sscanf(arg, "%s from %s", what, where) != 2)
                return 0;

        if (where == "ding")
        {
                message_vision(CYN "$N��$n" CYN "���һ�����󵨣����Ҵ�"
                               "�������⣡\n" NOR, obj, this_player());

                message_vision(CYN "$N��$n" CYN "�ȵ���ȥ���ɡ�\n" NOR,
                               obj, this_player());
                obj->kill_ob(this_player());
                this_player()->kill_ob(obj);
                return 1;
        }
        return 0;
}

int do_compare()
{
        object obj = this_object();

        message_vision(CYN "$N��$n" CYN "���һ������ʲô�ȣ�ȥ���ɣ�\n"
                       NOR, obj, this_player());
        obj->kill_ob(this_player());
        this_player()->kill_ob(obj);
        return 1;
}

int accept_fight(object me)
{
        object obj = this_object();
        command("say �����̵ģ�Ҫ����������������⣡\n");
        this_player()->kill_ob(obj);
        kill_ob(me);
        return 1;
}

int accept_hit(object me)
{
        object obj = this_object();
        command("say �����̵ģ�Ҫ����������������⣡\n");
        this_player()->kill_ob(obj);
        kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        object obj = this_object();
        command("say �����̵ģ�Ҫ����������������⣡\n");
        this_player()->kill_ob(obj);
        kill_ob(me);
        return 1;
}
