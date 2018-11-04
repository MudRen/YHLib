#include <ansi.h>
#include "wudang.h"

#define WUDANG    "/clone/lonely/book/wudang"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_COAGENT;

mixed ask_book1();
mixed ask_book2();
mixed ask_skill();

void create()
{
        set_name("��Զ��", ({ "song yuanqiao", "song", "yuanqiao" }));
        set("nickname", HIC "�䵱����" NOR);
        set("long", "������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
                    "��һ���ɸɾ����Ļ�ɫ���ۡ�������ݳ�����\n"
                    "����⡣�񵭳�ͣ���Ĭ���ԡ�\n");
        set("gender", "����");
        set("age", 61);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 31);
        set("int", 27);
        set("con", 32);
        set("dex", 30);
        
        set("max_qi", 6000);
        set("max_jing", 5000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 200);
        set("combat_exp", 2000000);
        set("score", 100000);

        set_skill("force", 260);
        set_skill("wudang-xinfa", 260);
        set_skill("taiji-shengong", 240);
        set_skill("dodge", 240);
        set_skill("tiyunzong", 240);
        set_skill("unarmed", 240);
        set_skill("taiji-quan", 220);
        set_skill("strike", 240);
        set_skill("wudang-zhang", 240);
        set_skill("zhenshan-zhang", 240);
        set_skill("hand", 240);
        set_skill("paiyun-shou", 240);
        set_skill("parry", 240);
        set_skill("sword", 260);
        set_skill("wudang-jian", 260);
        set_skill("shenmen-jian", 260);
        set_skill("taiji-jian", 240);
        set_skill("taoism", 240);
        set_skill("literate", 220);
        set_skill("martial-cognize", 240);
        set_skill("medical", 200);
        set_skill("wudang-yaoli", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        map_skill("strike", "zhenshan-zhang");
        map_skill("hand", "paiyun-shou");
        map_skill("medical", "wudang-yaoli");

        prepare_skill("unarmed", "taiji-quan");
        prepare_skill("strike", "wudang-zhang");

        set("no_teach", ([
                "taiji-shengong" : "Ҫ��ѧϰ̫����������������̡�",
                "taiji-jian"     : "̫���������������״���",
                "taiji-quan"     : "̫��ȭ�����������״���",
        ]));

        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                "�䵱ҩ��"   : (: ask_book1 :),
                "̫��ʮ��ʽ" : (: ask_book2 :),
                "���Ŵ�"     : (: ask_skill :),
        ]));

        set("book_count", 1);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.zhenwu" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.jia" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "sword.zhuan" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.yin" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
	}) );

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 150);

        set("coagents", ({
                ([ "startroom" : "/d/wudang/houyuan",
                   "id"        : "yu lianzhou" ]),
        }));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 25000)
        {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }

	if ((int)ob->query("combat_exp") < 300000)
	{
		command("say �����ھ�����ǳ��������������书���ȶ���Ҫ����");
		return;
	}

        if ((int)ob->query_skill("wudang-xinfa", 1) < 100)
        {
                command("say ���䵱����ע���ڹ��ķ�" + RANK_D->query_respect(ob)+
                        "�Ƿ�Ӧ�����䵱�ķ��϶��µ㹦��?");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 100)
        {
                command("say ϰ����Ϊ��ǿ���壬һζ�������ǲ���ȡ�ġ�");
                command("say �ҿ��㻹��Ҫ���������Է������������������"
                        "��ĵ����ķ���");
                return;
        }

        command("say �ðɣ��Ҿ��������ˡ�");
        command("say ϣ������ȫ�����������ķ�������������裡");
        command("recruit " + ob->query("id"));
        if ((string)ob->query("class") != "taoist")
                ob->set("class", "taoist");
}

mixed ask_skill()
{
        object me;

        me = this_player();
        if (me->query("can_perform/shenmen-jian/ci"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("shenmen-jian", 1) < 1)
                return "��������ʮ������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 30000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("force") < 160)
                return "����ڹ�����Ϊ�����������������ɡ�";

        if (me->query_skill("shenmen-jian", 1) < 120)
                return "�������ʮ�����������ң�Ҫ��������";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "����������"
                       "���˼��䣬�ְγ����䳤\n�������������������"
                       "Ȼ���͵�бб�̳�����ʽ���ӣ�����\n��㻪����"
                       "�ԡ�\n" NOR, me, this_object());
        command("nod");
        command("say ��������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ����Ŵ̡���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("shenmen-jian"))
                me->improve_skill("shenmen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/shenmen-jian/ci", 1);
        me->add("gongxian", -200);

        return 1;
}

mixed ask_book1()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�䵱��")
                return "���ֲ������䵱�ɵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query("shen") < 10000)
                return "�������������ò������Ȿ���һ����ܸ��㡣";

        if ((int)me->query_skill("wudang-yaoli", 1) < 50)
                return "����䵱ҩ����˽�̫ǳ�����ǹ���ʱ����˵�ɡ�";

        ob = find_object(WUDANG);
        if (! ob) ob = load_object(WUDANG);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Ǳ�ҩ�������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š��䵱ҩ�����ڲ��������";

                if (owner->query("family/family_name") == "�䵱��")
                        return "����������ʱ����ͬ��" + owner->query("name") +
                               "�ڿ�����Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�䵱ҩ������������" + owner->query("name") +
                               "���У���ȥ�������ذɡ�";
        }
        ob->move(this_object());
        command("say �Ȿ�䵱ҩ�������ȥ���ɣ���Ҫ�����ж���");
        command("give wudang yaoli to " + me->query("id"));
        return 1;
}

mixed ask_book2()
{
        object ob;
        
        if (this_player()->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(this_player()) + 
                       "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

        add("book_count", -1);
        ob = new("/clone/book/force_book");
        message_vision("$N�ó�̫��ʮ��ʽ(shu)��$n��\n",
                       this_object(), this_player());
        ob->move(this_player(), 1);
        return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}

