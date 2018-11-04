#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_me();

void create()
{
        set_name("������", ({ "yu lianzhou", "yu", "lianzhou" }));
        set("nickname", HIC "�䵱����" NOR);
        set("long", "������������Ķ����������ۡ���������\n"
                    "ʮ�꣬��Ŀ��࣬�������ء������䵱��\n"
                    "���������ڶ�������ȴ�����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 32);
        set("dex", 32);
        
        set("max_qi", 5800);
        set("max_jing", 4600);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 200);
        set("combat_exp", 1800000);
        set("score", 100000);

        set_skill("force", 250);
        set_skill("wudang-xinfa", 250);
        set_skill("taiji-shengong", 240);
        set_skill("dodge", 240);
        set_skill("tiyunzong", 240);
        set_skill("unarmed", 240);
        set_skill("taiji-quan", 220);
        set_skill("claw", 250);
        set_skill("huzhua-shou", 250);
        set_skill("strike", 240);
        set_skill("wudang-zhang", 240);
        set_skill("zhenshan-zhang", 240);
        set_skill("hand", 240);
        set_skill("paiyun-shou", 240);
        set_skill("parry", 240);
        set_skill("sword", 250);
        set_skill("wudang-jian", 250);
        set_skill("taiji-jian", 240);
        set_skill("taoism", 230);
        set_skill("literate", 200);
	set_skill("medical", 180);
	set_skill("wudang-yaoli", 180);
        set_skill("martial-cognize", 240);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        map_skill("strike", "zhenshan-zhang");
        map_skill("hand", "paiyun-shou");
        map_skill("claw", "huzhua-shou");
        map_skill("medical", "wudang-yaoli");

        prepare_skill("claw", "huzhua-shou");

        set("no_teach", ([
                "taiji-shengong" : "Ҫ��ѧϰ̫����������������̡�",
                "taiji-jian"     : "̫���������������״���",
                "taiji-quan"     : "̫��ȭ�����������״���",
        ]));

        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "������ץ" : (: ask_me :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "claw.juehu" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
        }) );

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 150);

        setup();

        carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 20000 )
        {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }

	if ((int)ob->query("combat_exp") < 150000)
	{
		command("say �����ھ�����ǳ��������������书���ȶ���Ҫ����");
		return;
	}

        if ((int)ob->query_skill("wudang-xinfa", 1) < 80)
        {
                command("say ���䵱����ע���ڹ��ķ�" + RANK_D->query_respect(ob)+
                        "�Ƿ�Ӧ�����䵱�ķ��϶��µ㹦��?");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 80)
        {
                command("say ϰ����Ϊ��ǿ���壬һζ�������ǲ���ȡ�ġ�");
                command("say �ҿ��㻹��Ҫ���������Է������������������"
                        "��ĵ����ķ���");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("say ϣ�����ܺú��ù����������䵱����");
        command("recruit " + ob->query("id"));
        if( (string)ob->query("class") != "taoist")
                ob->set("class", "taoist");
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/huzhua-shou/juehu"))
                return "��һ���㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("huzhua-shou", 1) < 1)
                return "������צ�����ֶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 100000)
                return "��һ��̫�����ޣ����������ȥ�ҿ��²����ģ�";

        if (me->query_skill("force") < 180)
                return "����ڹ�����Ϊ�����������������ɡ�";

        if (me->query_skill("huzhua-shou", 1) < 120)
                return "��Ļ�צ�����ֻ������ң������Լ�����ȥ�����ϰ�ɡ�";

        message_vision(HIY "$n" HIY "̾�˿�������$N" HIY "������"
                       "��˵�˼��仢צ������\n�ľ�Ҫ���������ã�"
                       "��̾��һ������\n" NOR, me, this_object());
        command("sigh");
        command("say ����Ǿ����ֵľ�Ҫ���ڣ��㶮�˶��٣�");
        command("say ������̫��ʹ���زУ����ʹ��ǰһ��Ҫ���ؿ��ǡ�");
        tell_object(me, HIC "��ѧ���ˡ�������ץ����\n" NOR);
        if (me->can_improve_skill("claw"))
                me->improve_skill("claw", 1500000);
        if (me->can_improve_skill("huzhua-shou"))
                me->improve_skill("huzhua-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/huzhua-shou/juehu", 1);
        me->add("gongxian", -400);

        return 1;
}
