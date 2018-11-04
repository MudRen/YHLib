#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��", ({ "mai jing", "mai", "jing" }));
        set("long", @LONG
����Ǿ޾�������󾨣�ֻ��������߳ߣ���
�澡�����룬��ò�������͡�
LONG);
        set("attitude", "heroism");
        set("title", "�޾������");
        set("age", 47);

        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 2800);
        set("max_neili", 3000);
        set("jiali", 150);
        set("combat_exp", 1200000);
        set("score", 10000);
 
        set_skill("unarmed", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("force", 300);

        setup();
        carry_object("/d/beijing/npc/obj/cloth6")->wear();
}

int accept_fight(object who)
{
        command("say �Ҳ���������ֻ�����(" HIY "compare" NOR +
                CYN ")һЩˮ�Ϲ���" NOR);
        return 0;
}

int accept_hit(object who)
{
        command("say �Ҳ���������ֻ�����(" HIY "compare" NOR +
                CYN ")һЩˮ�Ϲ���" NOR);
        return 0;
}

int accept_kill(object who)
{
        command("say ��ô������������ͷǵ�Ҫ���ײ��ɣ�");
        return notify_fail("ɲ�Ǽ�����û��ǲ�Ҫ�������Ϊ�á�\n");
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬����ֻ���᳡���ѹѹ�ļ�"
                           "�����ˣ��������������\n");
}

void init()
{
        add_action("do_get", "get");
        add_action("begin", "compare");
}

int begin()
{
        object me = this_player();

        if (objectp(present("yuan guangbo", environment()))) 
                return 0;

        if (me->query_condition("nishui"))
                return notify_fail("���������ڱ����أ��ż�ʲô��\n");

        command("say �Ҿ޾���ľ���������ʹ��ˮ�Ϲ���");
        command("say ������Ҹ���ʪ����죬����һ��ˮ�Ϲ�����Σ�");

        message_vision(HIW "$n" HIW "��$N" HIW "��ȡʪ�࣬���Ͽڱǡ�\n"
                       NOR, this_object(), me);

        me->set_temp("compare", 1);
        set("anti", me);

        me->apply_condition("nishui", random(4) + 3);
        this_object()->apply_condition("nishui", 50);
        call_out("guo", 6, me);
        return 1;
}

void die()
{
        if (objectp(query("anti")))
        {
                message_vision(HIR "\n$N" HIR "���������£�һ����û"
                               "���ϣ����ڵ���һ�������ˡ�\n" NOR,
                               this_object());
                query("anti")->set_temp("win_mai", 1);
                query("anti")->delete_temp("compare");
                query("anti")->apply_condition("nishui", 0);
        }
        ::die();
}

void unconcious()
{
        if (objectp(query("anti")))
        {
                message_vision(HIR "\n$N" HIR "���������£�һ����û"
                               "���ϣ����ڵ���һ�������ˡ�\n" NOR,
                               this_object());
                query("anti")->set_temp("win_mai", 1);
                query("anti")->delete_temp("compare");
                query("anti")->apply_condition("nishui", 0);
        }
        ::die();
}

void guo(object me)
{
        if (objectp(present("guo sanquan", environment())))
                present("guo sanquan", environment())->begin(me);
}

int do_get(string arg)
{
        object obj, env, ding;
        string what, where;

        if (! arg)
                return 0;

        if (objectp(obj = present("yuan guangbo", environment())))
                return 0;

        if (sscanf(arg, "%s from %s", what, where) != 2)
                return 0;

        obj = this_object();

        if (where == "ding")
        {
                message_vision(CYN "$N" CYN "��ɫ������λӢ�����ˡ�\n" NOR, obj);
                message_vision(CYN "$N" CYN "˵�������������˲���֮����Ҫ�ô�"
                               "��������ȹ�(" HIY "compare" NOR + CYN ")����"
                               "��ء�\n" NOR, obj);
                this_player()->delete_temp("compare");
                return 1;
        }
        return 0;
}
