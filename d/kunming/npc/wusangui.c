#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "wu sangui", "wu" }));
        set("age", 58);
        set("title", HIY "ƽ����" NOR);
        set("gender", "����");
        set("long", "����Ǵ����������������ص�ƽ����������\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("dex", 30);
        set("max_neili", 500);
        set("neili", 500);
        set("max_jing", 600);
        set("max_qi", 1200);
        set("combat_exp", 3000000);
        set("shen_type", -1);

        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("hammer", 120);
        set_skill("gun", 120);
        set_skill("force", 120);
        map_skill("hammer", "gun");

        set_temp("apply/attack", 300);
        set_temp("apply/defense", 300);
        set_temp("apply/damage", 300);
        set_temp("apply/armor", 300);

        setup();
        carry_object(__DIR__"obj/huoqiang")->wield();
        carry_object("/d/beijing/npc/obj/goldcloth2")->wear();
}

void init()
{
        object ob;

        ::init();

        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        string startroom;

        if (! objectp(ob) || environment(ob) != environment()) return;

        if (stringp(startroom = query("startroom")) &&
            find_object(startroom) == environment())
        {
                say(CYN "������ȵ�����ʲô�ˣ���Ȼ���ô�����������\n\n" NOR +
                    HIR "ֻ�����������һ̧�����á��䡱��һ����һ�Ż����ǹ�ڴܳ���\n" NOR);
                tell_object(ob, HIR "���ܲ�����ֻ���ؿ�һ����ۣ���Ѫ��ӿ������\n" NOR);
                ob->receive_wound("qi", 90);
        } else
                say(CYN "����������㣬ĥ��ĥ����\n" NOR);
}

void unconcious()
{
        die();
}

