#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����־", ({ "chang bozhi", "chang", "bozhi" }));
        set("title", "�컨��������");
        set("nickname", HIR "���޳�" NOR);
        set("long", "������ָ����ݣ���ɫ���ƣ��۾���������\n"
                    "������һ�����룬üëбб�ĵ�����������\n"
                    "�����ǿɲ�����������ɻ��µ��˵�ͽ�ܡ�\n"
                    "��ɳ�ƵĹ��򣬽����������ܵС��ڰ��޳�\n"
                    "���ֵ��Ǵ�����������������һ��ٸ���ƶ��\n"
                    "�����ĺ���������˵�������������š�\n");
        set("gender", "����");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 120);
        set("combat_exp", 1000000);
        set("score", 10000);

        set_skill("force", 140);
        set_skill("honghua-xinfa", 140);
        set_skill("qingcheng-neigong", 140);
        set_skill("strike", 160);
        set_skill("heisha-zhang", 160);
        set_skill("dodge", 160);
        set_skill("yanzi-chuanyun", 160);
        set_skill("sword", 140);
        set_skill("songfeng-jian", 140);
        set_skill("parry", 160);
        set_skill("martial-cognize", 120);
        set_skill("literate", 140);

        map_skill("force"  , "qingcheng-neigong");
        map_skill("sword"  , "songfeng-jian");
        map_skill("strike" , "heisha-zhang");
        map_skill("dodge"  , "yanzi-chuanyun");
        map_skill("parry"  , "heisha-zhang");

        prepare_skill("strike", "heisha-zhang");

        set("no_teach", ([
                "qingcheng-neigong" : "���ڹ�û��ɶ���ã�������Ӻ������Ʒ������ˡ�",
        ]));

        create_family("�컨��", 4, "����");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.cui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < 5000)
        {
                command("say ������������ˣ��Ҳ������㡣");
                return;
        }

        if ((int)me->query_skill("honghua-xinfa", 1) < 50)
        {
                command("say ��ѱ��ŵ��ķ�������������");
                return;
        }

        command("heihei");
        command("say �Ժ���͸������Ӱɡ�");
        command("recruit " + me->query("id"));
}
