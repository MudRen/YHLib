#include <ansi.h>
#include "shang.h"

inherit NPC;
inherit F_GUARDER;

void create()
{
        set_name("�̱���", ({"shang baozhen", "shang", "baozhen"}));
        set("gender", "����");
        set("title", "�̼ұ�����");
        set("age", 17);
        set("long", @LONG
������̼ұ��������̱���ֻ�������Ż�����
��Ȼһ�����ҹ��ӵ�ģ����
LONG);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 120);
        set("combat_exp", 500000);
        set("score", 10000);

        set_skill("force", 120);
        set_skill("shangjia-neigong", 120);
        set_skill("parry", 100);
        set_skill("wai-bagua", 100);
        set_skill("dodge", 100);
        set_skill("bagua-bu", 100);
        set_skill("unarmed", 100);
        set_skill("tan-tui", 100);
        set_skill("strike", 100);
        set_skill("bagua-zhang", 100);
        set_skill("cuff", 100);
        set_skill("bagua-quan", 100);
        set_skill("blade", 120);
        set_skill("bagua-dao", 120);
        set_skill("shangjia-dao", 120);
        set_skill("throwing", 100);
        set_skill("jinbiao-jue", 100);
        set_skill("literate", 100);
        set_skill("martial-cognize", 80);

        map_skill("unarmed", "tan-tui");
        map_skill("dodge", "bagua-bu");
        map_skill("force", "shangjia-neigong");
        map_skill("strike", "bagua-zhang");
        map_skill("sword", "quemen-jian");
        map_skill("blade", "bagua-dao");
        map_skill("cuff", "bagua-quan");
        map_skill("parry", "wai-bagua");
        map_skill("throwing", "jinbiao-jue");

        prepare_skill("cuff", "bagua-quan");
        prepare_skill("strike", "bagua-zhang");

        set("class", "fighter");

        set("coagents", ({
                ([ "startroom" : "/d/shaolin/shang_dating",
                   "id"        : "shang jianming" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "�����վס�������̼ұ������ɵ���"
                                "������߶��ط���" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ����ҷ�������" NOR,
        ]));

        create_family("�̼ұ�", 4, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.mang" :),
                (: perform_action, "strike.ding" :),
                (: perform_action, "cuff.gua" :),
                (: perform_action, "parry.zhen" :),
                (: perform_action, "throwing.huan" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/beijing/npc/obj/jinbiao"));
}

void attempt_apprentice(object ob)
{
        command("shake");
        command("say ��ȥ���ҵ����������׺��ˣ����Լ����书��û�����ء�");
}
