#include <ansi.h>
#include "kunlun.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({"wei siniang", "wei", "siniang"}));
	set("long", "�������ɵ�������ӣ�������������ķ�������\n"
                    "��Ͷ�����ŵ�����֮�⡣\n");
        set("nickname", HIY "��������" NOR);
	set("gender", "Ů��");
	set("age", 38);
	set("attitude", "heroism");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
        set("max_qi", 2000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 1000000);

        set_skill("force", 130);
        set_skill("kunlun-xinfa", 130);
        set_skill("dodge", 130);
        set_skill("chuanyun-bu", 130);
        set_skill("hand", 140);
        set_skill("sanyin-shou", 140);
        set_skill("cuff", 140);
        set_skill("zhentian-quan", 140);
        set_skill("parry", 140);
        set_skill("sword", 130);
        set_skill("xunlei-jian", 130);
        set_skill("throwing", 140);
        set_skill("kunlun-qifa", 140);
        set_skill("literate", 140);
        set_skill("liangyi-shengong", 130);
        set_skill("zhengliangyi-jian", 130);
        set_skill("martial-cognize", 120);

        set("no_teach", ([
                "liangyi-shengong"  : "������������������Դ��ڡ�",
                "zhengliangyi-jian"  : "�����ǽ����˱����񹦣���Ҫ���������Դ��ڡ�",
        ]));

        map_skill("force", "liangyi-shengong");
        map_skill("dodge", "chuanyun-bu");
        map_skill("parry", "xunlei-jian");
        map_skill("sword", "zhengliangyi-jian");
        map_skill("cuff", "zhentian-quan");
        map_skill("hand", "sanyin-shou");
        map_skill("throwing", "kunlun-qifa");

        prepare_skill("strike", "kunlun-zhang");
        prepare_skill("cuff", "zhentian-quan");

	create_family("������", 5, "����");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.shi" :),
                (: perform_action, "sword.xun" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }) );

	setup();
        carry_object("/d/kunlun/obj/sword")->wield();
        carry_object("/d/kunlun/obj/pao3")->wear();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if (me->query("gender") != "Ů��")
        {
                command("say ʦ����׼�����е��ӣ���ȥ����ʦ��ȥ�ɡ�");
                return;
        }

        if ((int)me->query("combat_exp") < 10000)
        {
                command("say ��Ľ�������ʵ��̫ǳ�����Ƕ���������˵�ɡ�");
                return;
        }

        if ((int)me->query_skill("kunlun-xinfa", 1) < 30)
        {
                command("say ��Ա��ŵ��ڹ��ķ���֪��ǳ����ϰ�����������Ұɡ�");
                return;
        }

        command("say ��Ȼ" + RANK_D->query_respect(me) + "��ôŬ�����Ҿ�������ɡ�");
        command("recruit " + me->query("id"));
}
