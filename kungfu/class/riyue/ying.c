#include <ansi.h>
#include "riyue.h"

#define YUCHANG    "/clone/lonely/yuchang"

inherit NPC;
inherit F_MASTER;

void create()
{
        object ob;
        set_name("��ӯӯ", ({ "ren yingying", "ren", "yingying", "ying"}));
        set("nickname", HIW "ʥ��" NOR );
        set("title", "�������");
        set("long", @LONG
�����������̽���������֮Ů�����б��˳�
����ʥ�á�����ӯӯ��ֻ��������С�䣬����
���ɷ��ȴ���ü΢�壬�ƺ������ˡ�
LONG);
	set("gender", "Ů��" );
        set("class", "scholar");
        set("age", 19);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 3200);
        set("max_jing", 2000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 100);
        set("combat_exp", 1000000);
        set("score", 10000);

        set_skill("force", 160);
        set_skill("riyue-xinfa", 160);
        set_skill("tianhuan-shenjue", 80);
        set_skill("dodge", 160);
        set_skill("juechen-shenfa", 160);
        set_skill("dagger", 160);
        set_skill("jifeng-cixuefa", 160);
        set_skill("parry", 160);
        set_skill("strike", 140);
        set_skill("qingmang-zhang", 140);
        set_skill("throwing", 140);
        set_skill("heixue-shenzhen", 140);
        set_skill("martial-cognize", 150);
        set_skill("literate", 220);
        set_skill("tanqin-jifa", 240);
        set_skill("guangling-san", 220);
        set_skill("qingxin-pushan", 240);
        set_skill("xiaoao-jianghu", 220);

        map_skill("tanqin-jifa", "qingxin-pushan");
        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "riyue-xinfa");
        map_skill("strike", "qingmang-zhang");
        map_skill("dagger", "jifeng-cixuefa");
        map_skill("parry", "jifeng-cixuefa");
        map_skill("throwing", "heixue-shenzhen");

        prepare_skill("strike", "qingmang-zhang");

        set("no_teach", ([
                "tianhuan-shenjue" : "�����ڹ��Ҷ�ûѧ�ã���ô����ѽ��",
        ]));

        create_family("�������", 14, "ʥ��");

        set("inquiry", ([
                "��Ы����" : "������ȥ��ɣ�������ɡ�",
                "�����"   : "�������������ڡ���������",
                "�㳦��"   : "�����ҵ�������Ʒ�������������",
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "dagger.cang" :),
                (: perform_action, "throwing.luo" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
        setup();

        if (clonep())
        {
                ob = find_object(YUCHANG);
                if (! ob) ob = load_object(YUCHANG);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/d/heimuya/npc/obj/bishou");
                        ob->move(this_object());
                        ob->wield();
                }
        }
        carry_object("/d/city/npc/cloth/belt")->wear();
        carry_object("/d/city/npc/cloth/moon-dress")->wear();
        set_temp("handing", carry_object("/d/kunlun/obj/jwqin"));
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > 0)
        {
                command("heng");
                command("say ��������̴�������������ʿ�ύ���㻹���߰ɡ�");
                return;
        }

        if ((string)ob->query("gender") != "Ů��")
        {
                command("say �㻹��ȥ�ҽ��ڵ������˰ɡ�");
                return;
        }

        command("sigh");
        command("say �����Ժ�͸����Ұɡ�");
        command("recruit " + ob->query("id"));
        return;
}

void init()
{
        object ob;
        if (interactive(ob = this_player())
           && ! is_fighting()
           && random(10) < 3)
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }    
}

void greeting(object ob)
{ 
        if (! ob || environment(ob) != environment())
                return;
        command("play qingxin-pushan");
        return;
}
