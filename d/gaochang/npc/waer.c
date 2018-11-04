#include <ansi.h>
inherit NPC;

int ask_back();

void create()
{
        set_name("�߶�����", ({ "waer laqi", "waer", "laqi" }));
        set("gender", "����");
        set("age", 45);
        set("long", @LONG
������װ��Ū����߶����롣ֻ�������ݿ��£�
���ڳ��ڲ������⣬Ƥ���Ұס�
LONG);

        set("combat_exp", 50000);
        set("shen_type", -1);
        set("max_qi", 800);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 10);

        set_skill("force", 120);
        set_skill("whip", 120);
        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);

        set("inquiry", ([
                "��ȥ"     : (: ask_back :),
                "����"     : "�߲��Թ�һ�����У���һ����������ס�ġ�\n",
                "������"   : "����һ���ù��Ҳ��֪��ʱ�����ټ�������\n",
                "�߲��Թ�" : "�߲��Թ�һ�����У���һ����������ס�ġ�\n",
        ]));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 300);

        setup();
        carry_object(__DIR__"obj/liuxingchui")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me;
        ::init();

        if (interactive(me = this_player()) && ! is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{
        if (! me || environment(me) != environment()) return;

        if (present("map", me))
        {
                message("vision", HIR "�߶�����ȵ�����Ȼ�ҵ���������Ұ����������"
                        "�ɣ�\n" NOR, environment());
                kill_ob(me);
        } else
                command("sneer " + me->query("id"));
        return;
}

int ask_back()
{
        object ob;
        object me = this_player();

        if (! me->query_temp("marks/back"))
        {
                say(CYN "�߶�������Ц�����ðɣ�����������ȥ���´��ٽ����ͱ����"
                        "�������ˡ�\n" NOR);
                message_vision(HIY "ֻ���߶���������$N" HIY "�����Թ��ڶ��˼���Ȧ"
                        "�ӣ��첽������\n" NOR, me);
                me->move("/d/gaochang/entrance");
                tell_object(me, HIC "\n������߶����������˸߲��Թ��⡣\n" NOR);
                me->set_temp("marks/back", 1);
                return 1;
        } else
        {
                say(CYN "�߶�������Ц���������������ܣ���������һ���Ӱɣ�\n" NOR);
                return 1;
        }
        return 1;
}

void unconcious()
{
        die();
}

