#include <ansi.h>
#include "duan.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("������", ({ "chu wanli", "chu" }));
        set("title", "���������" );
        set("long", "���Ǵ�����Ĵ���֮һ��Ӣ�����ˡ�\n");
        set("gender", "����");
        set("age", 40);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 1800);
        set("max_jing", 1000);
        set("neili", 2200);
        set("max_neili", 2200);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 120);
        set_skill("duanshi-xinfa", 120);
        set_skill("dodge", 120);
        set_skill("tiannan-bu", 120);
        set_skill("cuff", 120);
        set_skill("jinyu-quan", 120);
        set_skill("strike", 120);
        set_skill("wuluo-zhang", 120);
        set_skill("whip", 140);
        set_skill("feifeng-bian", 140);
        set_skill("parry", 120);
        set_skill("literate", 80);
        set_skill("martial-cognize", 140);

        map_skill("force", "duanshi-xinfa");
        map_skill("dodge", "tiannan-bu");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("whip", "feifeng-bian");
        map_skill("parry", "feifeng-bian");

        prepare_skill("cuff", "jinyu-quan");
        prepare_skill("strike", "wuluo-zhang");

        set("coagents", ({
                ([ "startroom" : "/d/dali/neitang",
                   "id"        : "duan zhengchun", ]),
        }));

        set("guarder", ([
                "refuse_home" : CYN "$N" CYN "��ס$n" CYN "�����Բ�"
                                "����ү������˶μҾ�Ī������\n" NOR,
                "refuse_other": CYN "$N" CYN "һ����ס$n" CYN "����"
                                "���������˵ȣ��������ڡ�\n" NOR,
                "refuse_carry": CYN "$N" CYN "����Ц����$n" CYN "��"
                                "���ɷ񽫡��㱳���˷����ٽ�������\n" NOR,
        ]));

        create_family("���ϻ���", 15, "�ҳ�");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "whip.xi" :),
                (: perform_action, "cuff.man" :),
                (: perform_action, "strike.bian" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/d/dali/npc/obj/junfu")->wear();
        carry_object("/d/dali/npc/obj/diaogan")->wield();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("shake");
        command("say ���ӵ��º�����ˣ�ֻҪ���·Ը�����һ�����ǡ�");
        return;
}