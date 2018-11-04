#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("����", ({ "wang cheng", "wang", "cheng"}));
        set("title", "������̷�������");
        set("long", @LONG
����������̷����������ϣ�������İ��֣�
������Ц����ʵΪ��ʮ�ֺݶ���
LONG);
        set("gender", "����" );
        set("class", "scholar");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 4500);
        set("max_jing", 3500);
        set("neili", 3200);
        set("max_neili", 3200);
        set("jiali", 120);
        set("combat_exp", 500000);
        set("score", 10000);

        set_skill("force", 160);
        set_skill("riyue-xinfa", 160);
        set_skill("dodge", 150);
        set_skill("feiyan-zoubi", 150);
        set_skill("blade", 160);
        set_skill("danding-dao", 160);
        set_skill("parry", 150);
        set_skill("cuff", 150);
        set_skill("zhenyu-quan", 150);
        set_skill("claw", 150);
        set_skill("poyue-zhao", 150);
        set_skill("martial-cognize", 150);
        set_skill("literate", 160);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "riyue-xinfa");
        map_skill("blade", "danding-dao");
        map_skill("parry", "danding-dao");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        set("coagents", ({
                ([ "startroom" : "/d/heimuya/chengdedian",
                   "id"        : "ren woxing" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ü����"
                                "�Ҳ���������ô�����ģ����ľ����"
                                "�����ɽ���֮�أ�" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ����������ҷ�"
                                "�£�" NOR,
        ]));

        create_family("�������", 14, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.kou" :),
                (: perform_action, "cuff.tong" :),
                (: perform_action, "claw.duan" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/d/heimuya/npc/obj/jinpao")->wear();
        carry_object("clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

     	command("say �Ҳ���ͽ����ȥ�ҽ��ڵ����೤�Ϻ��ˡ�");
}
