#include <ansi.h>
inherit NPC;

void create()
{
        set_name("Ԫ�㲨", ({ "yuan guangbo", "yuan", "guangbo" }));
        set("long", @LONG
����Ǻ�ɳ�ɵ��ܶ���Ԫ�㲨��ֻ����Ŀ����
�磬��ı뺴����ΰ֮����
LONG);
        set("attitude", "heroism");
        set("title", "��ɳ���ܶ���");
        set("age", 35);

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
                CYN ")һЩ�Һ�ɳ��ľ�����" NOR);
        return 0;
}

int accept_hit(object who)
{
        command("say �Ҳ���������ֻ�����(" HIY "compare" NOR +
                CYN ")һЩ�Һ�ɳ��ľ�����" NOR);
        return 0;
}

int accept_kill(object who)
{
        command("say ��ô������������ͷǵ�Ҫ���ײ��ɣ�");
        return notify_fail("ɲ�Ǽ�����û��ǲ�Ҫ�������Ϊ�á�\n");
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬����ֻ���᳡���ѹѹ�ļ�����"
                           "�ˣ��������������\n");
}

void init()
{
        add_action("do_get", "get");
        add_action("begin", "compare");
}

int begin()
{
        object me = this_player();

        if (objectp(present("chang jinpeng", environment())))
                return 0;

        if (me->query_condition("duyan"))
                return notify_fail("���������ڱ����أ��ż�ʲô��\n");

        command("sneer");
        command("say �Һ�ɳ��ľ������Ƕ��κ��ˣ�������Ҹ���"
                "һ�룬��Σ�");

        message_vision(HIW "$N" HIW "������װ�������붾�Σ�$N"
                       HIW "��$n" HIW "����һ�롣\n" NOR,
                       this_object(), me);

        me->set_temp("compare", 1);
        set("anti", me);

        me->apply_condition("duyan", random(4) + 3);
        this_object()->apply_condition("duyan", 50);
        return 1;
}

void die()
{
        if (objectp(query("anti")))
        {
                command("say ������������");
                message_vision(HIR "\n$N" HIR "˻����ɤ�Ӹɺ���������˫��"
                               "���׵����ڵأ������³�Щ��ĭ������Ҳû����"
                               "��\n" NOR, this_object());
                query("anti")->set_temp("win_yuan", 1);
                query("anti")->delete_temp("compare");
        }
        ::die();
}

void unconcious()
{
        if (objectp(query("anti")))
        {
                command("say ������������");
                message_vision(HIR "\n$N" HIR "˻����ɤ�Ӹɺ���������˫��"
                               "���׵����ڵأ������³�Щ��ĭ������Ҳû����"
                               "��\n" NOR, this_object());
                query("anti")->set_temp("win_yuan", 1);
                query("anti")->delete_temp("compare");
        }
        ::die();
}

int do_get(string arg)
{
        object obj, env, ding;
        string what, where;

        if (! arg)
                return 0;

        if (objectp(obj = present("chang jinpeng", environment(this_object()))))
                return 0;

        if (sscanf(arg, "%s from %s", what, where) != 2)
                return 0;

        obj = this_object();

        if (where == "ding")
        {
                message_vision(CYN "$N" CYN "�ȵ����޳�С��������ס�֡���ƾ"
                               "ʲô�ô˱�����\n" NOR, obj,this_player());
                message_vision(CYN "$N" CYN "�����˵����Ҫ�ô˵����ȱ�(" HIY
                               "compare" NOR + CYN ")Ӯ������˵��\n" NOR,
                               obj, this_player());
                this_player()->delete_temp("compare");
                return 1;
        }
        return 0;
}

