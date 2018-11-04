#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "zhao min", "min", "zhao" }));
        set("title", HIY "��Ԫ��������" NOR);
        set("long", @LONG
��������ϼ����ɫ������ʮ������֮�У�����
������Ӣ�������ֺ�̬��ͬʱӺ�ݻ�������
һ������֮�£�������Ȼ�𾴣����ұ��ӡ�
LONG);
        set("gender", "Ů��");
        set("age", 19);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 30);
        set("str", 15);
        set("int", 25);
        set("con", 25);
        set("dex", 30);

        set("max_qi", 500);
        set("max_jing", 200);
        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 50);
        set("combat_exp", 60000);
        set("score", 20000);

        set_skill("force", 80);
        set_skill("dodge", 80);
        set_skill("unarmed", 80);
        set_skill("sword", 80);
        set_skill("liangyi-jian", 80);
        set_skill("huifeng-jian", 80);
        set_skill("taiji-shengong", 90);
        set_skill("changquan", 80);
        set_skill("lingxu-bu", 80);
        map_skill("dodge", "lingxu-bu");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
        map_skill("unarmed", "changquan");

        set("inquiry", ([
                "���޼�" : "�Ź���Զ�����أ���֪�������ɺã����䴺�������к��£�",
                "���콣" : "����Ϊ�����������ô������Ҫ��",
        ]));

        setup();
        carry_object("/d/city/npc/cloth/moon-dress")->wear();
}

void fight_ob(object ob)
{
        object me = this_object();
        object where = environment(me);
        object guard1, guard2, guard3;

        guard1 = present("a da", where);
        guard2 = present("zhao yishang", where);
        guard3 = present("qian erbai", where);

        if (is_fighting(ob))
                return;

        if (guard1 && ! guard1->is_fighting())
        {
                message_vision(CYN "$N" CYN "��ߵ���������\n" NOR,
                               guard1);
                guard1->kill_ob(ob);
        }

        if (guard2 && ! guard2->is_fighting())
        {
                message_vision(CYN "$N" CYN "��ŭ���ȵ�����������"
                               "���֣���Ȼ�ܵ���������Ұ��\n" NOR,
                               guard2);
                guard2->kill_ob(ob);
        }

        if (guard3 && ! guard3->is_fighting())
        {
                message_vision(CYN "$N" CYN "�ȵ������Ӳ�������"
                               "\n" NOR, guard3);
                guard3->kill_ob(ob);
        }
        ::fight_ob(ob);
}

int accept_fight(object ob)
{
        command("say û��Ȥ��");
        return 0;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        return 1;
}

int accept_touxi(object ob)
{
        return 1;
}

void unconcious()
{
        die();
}

void die()
{
        message_vision(HIW "\n����΢΢һЦ��ҡ��ҡͷ��ͻȻ������������"
                       "Х������������\n�������������Ӱ����΢���ۻ���"
                       "��æ������������Ӧ��ȴֻ\n����Ӱ���Σ��ع���֮"
                       "�����ﻹ����������Ӱ��\n\n" NOR, this_object());
        destruct(this_object());
}
