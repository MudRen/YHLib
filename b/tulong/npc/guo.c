#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ȭ", ({ "guo sanquan", "guo", "sanquan" }));
        set("long", @LONG
������ȭ�������˹���ȭ����ĸߴ�˫�ۼ�
���ʵ��һ����֪������Һ��֡�
LONG);
        set("title", "��ȭ��������");
        set("attitude", "heroism");
        set("age", 56);
        set("str", 60);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 3500);
        set("max_jing", 3500);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 300);
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

        set_temp("apply/armor", 200);
        set_temp("apply/attack", 200);
        set_temp("apply/unarmed_damage", 1500);

        setup();

        carry_object("/d/beijing/npc/obj/cloth6")->wear();
}

void init()
{
        add_action("do_get", "get");
        add_action("do_compare", "compare");
}

int accept_fight(object who)
{
        command("say �Ҳ���������ֻ�����(" HIY "compare" NOR +
                CYN ")һЩȭ���ϵĹ���" NOR);
        return 0;
}

int accept_hit(object who)
{
        command("say �Ҳ���������ֻ�����(" HIY "compare" NOR +
                CYN ")һЩȭ���ϵĹ���" NOR);
        return 0;
}

int accept_kill(object who)
{
        command("say ��ô������������ͷǵ�Ҫ���ײ��ɣ�");
        return notify_fail("��ʱ������û��ǲ�Ҫ�������Ϊ�á�\n");
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬����ֻ���᳡���ѹ"
                           "ѹ�ļ������ˣ��������������\n");
}

int begin(object me)
{
        string msg;
        object ob = this_object();

        command("sneer");
        command("say �������粻����֮Σ���������ڸ���֮�֣�");
        command("say ����ȭ�ž���������ʹ�����Ϲ����ȳ�����ȭ��˵��");

        message_vision(HIC "\n$N" HIC "�ȵ����ˣ������һȭ������"
                       HIR "�߽�Ϲ�" HIC "����\n" NOR, ob);

        this_object()->add_temp("apply/attack", 100);
        this_object()->add_temp("apply/unarmed_damage", 100);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));

        message_vision(HIC "\n$N" HIC "�ȵ����ã��ٿ�����ڶ�ȭ��"
                       HIR "��ɽ��ʯ" HIC "����\n" NOR, ob);

        this_object()->add_temp("apply/attack", 100);
        this_object()->add_temp("apply/unarmed_damage", 100);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));

        message_vision(HIC "\n$N" HIC "�ȵ�������ȭ���ˣ���ʽ������"
                       HIY "��ɨǧ����ֱ������" HIC "����\n" NOR, ob);

        this_object()->add_temp("apply/attack", 300);
        this_object()->add_temp("apply/unarmed_damage", 300);
        COMBAT_D->do_attack(ob, me, query_temp("weapon"));

        // �趨�س�ʼ״̬
        this_object()->set_temp("apply/attack", 200);
        this_object()->set_temp("apply/unarmed_damage", 1500);

        set("anti", me);
        me->set_temp("compare", 1);

        if (me->query("max_neili") > 3000)
                die();

        return 1;
}

void die()
{
        if (objectp(query("anti")))
        {
                message_vision(HIR "\n$N" HIR "һȭ�˶������Ļ�����$n"
                               HIR "��С���������С����������\n������$N"
                               HIR "��ȭʱ������ʯ����֪����ѿ�����"
                               "Ѫ��\n" NOR, this_object(), query("anti"));
                query("anti")->set_temp("win_guo", 1);
                query("anti")->delete_temp("compare");
        }
        ::die();
}

int do_get(string arg)
{
        object obj = this_object();
        string what, where;

        if (! arg)
                return 0;

        if (objectp(obj = present("mai jing", environment())))
                return 0;

        if (sscanf(arg, "%s from %s", what, where) != 2)
                return 0;

        if (where == "ding")
        {
                message_vision(CYN "$N" CYN "����һ����\n" NOR, obj);
                message_vision(CYN "$N" CYN "˵����Ҫ��õ���������"
                               "������ȭ��\n" NOR, obj);
                this_player()->delete_temp("compare");
                return 1;
        }
        return 0;
}

int do_compare()
{
        object me = this_player();

        if (objectp(present("mai jing", environment())))
                return 0;

        begin(me);
        return 1;
}
