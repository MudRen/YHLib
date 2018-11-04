#include <ansi.h>
#include "lingjiu.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
	set_name("�ս�", ({ "ju jian", "ju", "jian"}));
        set("long", @LONG
÷�����������񽣡��ս��Ľ��ñ�����翷���
һ�����˵ĺ��ӡ�����������������ɽͯ�ѿ�
�к��������¡�ֻ������ò毺ã�����������
������ᣬ������ס�
LONG );
	set("gender", "Ů��");
	set("age", 18);
	set("attitude", "peaceful");
	set("str", 23);
	set("int", 27);
	set("con", 25);
	set("dex", 24);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 40);

	set("combat_exp", 500000);
	set("score", 3000);
	set_skill("force", 100);
	set_skill("lingjiu-xinfa", 100);
	set_skill("dodge", 80);
	set_skill("yueying-wubu", 80);
	set_skill("parry", 80);
	set_skill("strike", 80);
	set_skill("piaomiao-zhang", 80);
	set_skill("sword", 80);
 	set_skill("tianyu-qijian", 80);
        set_skill("literate", 120);
        set_skill("martial-cognize", 60);

	map_skill("force", "lingjiu-xinfa");
	map_skill("strike","piaomiao-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike", "piaomiao-zhang");

        set("coagents", ({
                ([ "startroom" : "/d/lingjiu/dating",
                   "id"        : "xuzhu zi" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��Ц����"
                                "ʲô�ˣ���Ȼ�����������չ��Ҵ���"
                                NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ���ι"
                                "�������ǰ��˰ᵽ����ȥѽ��" NOR,
        ]));

	create_family("���չ�", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ju" :),
                (: perform_action, "sword.shan" :),
                (: perform_action, "sword.huan" :),
        }));

	setup();

	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 15);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((string)ob->query("gender") == "����")
        {
                command("consider");
                command("say �ҿ��㻹��ȥ�����°ɣ������������춼�ڻ��");
                return;
        }

        if ((string)ob->query("gender") != "Ů��")
        {
                command("@@");
                command("say ��λ�������ҿ��㻹�ǸϽ��ع��ź���ϰɡ�");
                return;
        }

        command("xixi");
        command("say ��Ȼ�������������������°ɣ��Ժ��Ҿ�����ʦ���ˡ�");
        command("recruit " + ob->query("id"));

        if ((string)ob->query("class") != "dancer")
                ob->set("class", "dancer");
}
