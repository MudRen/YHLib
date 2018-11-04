#include <ansi.h>
#include "wudu.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("ɳǧ��", ({ "sha qianli", "sha", "qianli" }));
        set("nickname", HIR "����" NOR);
        set("long",@LONG
�������嶾�̵Ļ�������ɳǧ���Ŀ��࣬��
�������ڽ���ת����ļ���ڣ����ڵ����ǵ���
�Ź���
LONG);
        set("title","�嶾�̻�������");
        set("gender", "����");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 40);
        set("combat_exp", 200000);
        set("score", 5000);

        set_skill("force", 80);
        set_skill("wudu-xinfa", 80);
        set_skill("dodge", 80);
        set_skill("jinshe-youshenbu", 80);
        set_skill("strike", 80);
        set_skill("tianchan-zhang", 80);
        set_skill("claw", 80);
        set_skill("wusheng-zhao", 80);
        set_skill("parry", 80);
        set_skill("literate", 50);
        set_skill("poison", 80);
        set_skill("wudu-qishu", 80 );
        set_skill("martial-cognize", 60);

        map_skill("force", "wudu-xinfa");
        map_skill("dodge", "jinshe-youshenbu");
        map_skill("strike", "tianchan-zhang");
        map_skill("claw", "wusheng-zhao");
        map_skill("parry", "wusheng-zhao");
        map_skill("poison", "wudu-qishu");

        prepare_skill("strike", "tianchan-zhang");
        prepare_skill("claw", "wusheng-zhao");

        set("coagents", ({
                ([ "startroom" : "/d/wudu/dating",
                   "id"        : "qi yunao" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "����һ�Σ�����$n" CYN
                                "��ǰ������˵�����Ǳ��̵��ӣ����ý�"
                                "�뱾�̽��ء�" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ�����ҷ�������"
                                NOR,
        ]));

        create_family("�嶾��", 13, "��������");

        setup();

        carry_object("/d/wudu/npc/obj/ganggou")->wield();
        carry_object("/d/city/obj/cloth")->wear();

        add_money("silver",30);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -1000)
        {
                command("say �ҽ̵��ӹ�����������������α����");
                return;
        }
        command("recruit " + ob->query("id"));
        ob->set("title", "�嶾�̽���");
        return;
}
