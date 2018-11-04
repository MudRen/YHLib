// zhang.c ������

#include <ansi.h>
#include "wudang.h"

#define ZHENWU_SWORD    "/clone/lonely/zhenwu"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_jian();
mixed ask_jiuyang();
mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();
mixed ask_skill7();
mixed ask_skill8();
mixed ask_skill9();
mixed ask_skill10();
mixed ask_skill11();

int try_to_learn_jy();

void create()
{
        object ob;
	set_name("������", ({ "zhang sanfeng", "zhang", "sanfeng" }));
	set("nickname", HIW "̫������" NOR);
	set("long", "�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ������\n"
                    "�������ˡ�ֻ��������һ���ۻ�Ļ�ɫ���ۣ���\n"
                    "�ޱ߷�����ĸߴ��������꣬������⣬��ü\n"
                    "�԰ס�\n");
	set("gender", "����");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 31);
	set("int", 39);
	set("con", 40);
	set("dex", 32);
	
	set("max_qi", 10000);
	set("max_jing", 10000);
        set("max_jingli", 10000);
        set("jingli", 10000);
	set("max_neili", 12000);
	set("neili", 12000);
	set("jiali", 250);
	set("combat_exp", 5000000);
	set("score", 1200000);

	set_skill("force", 420);
        set_skill("taiji-shengong", 420);
        set_skill("wudang-jiuyang", 200);
	set_skill("wudang-xinfa", 400);
	set_skill("dodge", 420);
	set_skill("tiyunzong", 420);
	set_skill("unarmed", 420);
	set_skill("taiji-quan", 420);
	set_skill("xuangong-quan", 400);
	set_skill("strike", 400);
	set_skill("wudang-zhang", 400);
	set_skill("yitian-zhang", 400);
	set_skill("zhenshan-zhang", 400);
        set_skill("hand", 400);
        set_skill("paiyun-shou", 400);
        set_skill("claw", 400);
        set_skill("huzhua-shou", 400);
	set_skill("parry", 420);
	set_skill("sword", 420);
	set_skill("wudang-jian", 400);
	set_skill("shenmen-jian", 400);
	set_skill("rouyun-jian", 400);
	set_skill("raozhi-roujian", 400);
	set_skill("liangyi-jian", 400);
        set_skill("taiji-jian", 420);
	set_skill("blade", 400);
	set_skill("taiji-dao", 400);
	set_skill("xuanxu-dao", 400);
        set_skill("throwing", 400);
        set_skill("furong-jinzhen", 400);
	set_skill("taoism", 400);
	set_skill("literate", 280);
	set_skill("medical", 240);
	set_skill("wudang-yaoli", 240);
        set_skill("martial-cognize", 400);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("hand", "paiyun-shou");
	map_skill("claw", "huzhua-shou");
	map_skill("strike", "wudang-zhang");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("blade", "taiji-dao");
        map_skill("throwing"  , "furong-jinzhen");
        map_skill("medical", "wudang-yaoli");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");

        set("no_teach", ([
                "wudang-jiuyang" : (: try_to_learn_jy :),
        ]));

	create_family("�䵱��", 1, "��ɽ��ʦ");
	set("class", "taoist");

        set("inquiry", ([
                "���佣"     : (: ask_jian :),
                "��Զ"       : (: ask_jiuyang :),
                "�����澭"   : (: ask_jiuyang :),
                "������"   : (: ask_jiuyang :),
                "�䵱������" : (: ask_jiuyang :),
                "���쾢"     : (: ask_skill1 :),
                "���־�"     : (: ask_skill2 :),
                "���־�"     : (: ask_skill3 :),
                "���־�"     : (: ask_skill4 :),
                "ճ�־�"     : (: ask_skill5 :),
                "̫��ͼ"     : (: ask_skill6 :),
                "���־�"     : (: ask_skill7 :),
                "���־�"     : (: ask_skill8 :),
                "���־�"     : (: ask_skill9 :),
                "�����ת"   : (: ask_skill10 :),
                "�����а"   : (: ask_skill11 :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.jia" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "sword.zhuan" :),
		(: perform_action, "sword.zhenwu" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.yin" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
	}) );

	setup();

        if (clonep())
        {
                ob = find_object(ZHENWU_SWORD);
                if (! ob) ob = load_object(ZHENWU_SWORD);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/clone/weapon/changjian");
                        ob->move(this_object());
                        ob->wield();
                }
        }

	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

	if ((int)ob->query_skill("wudang-xinfa", 1) < 120)
	{
		command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ�����䵱�ķ��϶��µ㹦��");
		return;
	}

	if ((int)ob->query("shen") < 80000)
	{
		command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}

	if ((int)ob->query("combat_exp") < 500000)
	{
		command("say �����ھ�����ǳ��������������书���ȶ���Ҫ����");
		return;
	}

        if (ob->query_skill("taoism", 1) < 120)
	{
		command("say ���䵱���书ȫ�ӵ��������");
		command("say ��Ե����ķ������򻹲�����");
		command("say " + RANK_D->query_respect(ob) + "���Ƕ��о��о���ѧ�ķ��ɡ�");
		return;
	}

	if (ob->query_int() < 32)
	{
		command("say ���䵱���书���迿�Լ�����");
		command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}

	command("smile");
	command("say �벻���ϵ��ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
	command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-shengong/dian"))
                return "�Ҳ����Ѿ��̸�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-shengong", 1) < 1)
                return "����̫���񹦶�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 150000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-shengong", 1) < 100)
                return "���̫������Ϊ̫ǳ���������������ɡ�";

        if (me->query("max_neili") < 1500)
                return "���������Ϊ̫ǳ���������������ɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ�����һָ��������磬��Ȼ"
                     "����$N" HIY "��Ե���ִ���$N" HIY "��ʱֻ��$n" HIY
                     "������ԴԴ����������ӿ�룬ȫ��һ�����飬������"
                     "ʧɫ��\n\n" NOR, me, this_object());

        command("say �㶮����");
        tell_object(me, HIC "��ѧ���ˡ����쾢����Ծ�ϡ���\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("taiji-shengong"))
                me->improve_skill("taiji-shengong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-shengong/dian", 1);
        me->add("gongxian", -800);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-quan/zhen"))
                return "���Լ��������ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-quan", 1) < 1)
                return "����̫��ȭ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 100000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-quan", 1) < 150)
                return "���̫��ȭ��Ϊ̫ǳ���������������ɡ�";

        if (me->query("max_neili") < 1200)
                return "���������Ϊ̫ǳ���������������ɡ�";

        message_sort(HIY "\n$n" HIY"�����𻰣�����վ������������������"
                     "������ǰ����۰뻷������Գ����ƣ����Ʒ���������"
                     "������ȸβ�����ޡ��������ơ�����Ʊա�ʮ���֡���"
                     "����ɽ����һ��һʽ������ȥ����$n" HIY "ʹ���ϲ���"
                     "̽���ϲ���ȸβ�����޶���̫���������е�վ�ڵ�"
                     "�ء����$n" HIY "˫�ֺϱ�̫��Ȧ�������$N" HIY
                     "�ʵ���������ȭ���С����鶥�������ذα�����������"
                     "������׹�⡹�ľ��ϣ����������˶��٣���\n\n" NOR,
                     me, this_object());

        command("say �������У���������������һ������·ȭ����Ҫּ��");
        command("say ���������ˣ���ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("taiji-quan"))
                me->improve_skill("taiji-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-quan/zhen", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-quan/yin"))
                return "���Լ��������ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-quan", 1) < 1)
                return "����̫��ȭ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 100000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-quan", 1) < 150)
                return "���̫��ȭ��Ϊ̫ǳ���������������ɡ�";

        if (me->query("max_neili") < 1200)
                return "���������Ϊ̫ǳ���������������ɡ�";

        message_sort(HIY "\n$n" HIY"�����𻰣�����վ������������������"
                     "������ǰ����۰뻷������Գ����ƣ����Ʒ���������"
                     "������ȸβ�����ޡ��������ơ�����Ʊա�ʮ���֡���"
                     "����ɽ����һ��һʽ������ȥ����$n" HIY "ʹ���ϲ���"
                     "̽���ϲ���ȸβ�����޶���̫���������е�վ�ڵ�"
                     "�ء����$n" HIY "˫�ֺϱ�̫��Ȧ�������$N" HIY
                     "�ʵ���������ȭ���С����鶥�������ذα�����������"
                     "������׹�⡹�ľ��ϣ����������˶��٣���\n\n" NOR,
                     me, this_object());

        command("say ���ⲻ������̫��Բת����ʹ�ԶϾ���");
        command("say ���������ˣ���ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("taiji-quan"))
                me->improve_skill("taiji-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-quan/yin", 1);
        me->add("gongxian", -200);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-quan/ji"))
                return "���Լ��������ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-quan", 1) < 1)
                return "����̫��ȭ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 120000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-quan", 1) < 150)
                return "���̫��ȭ��Ϊ̫ǳ���������������ɡ�";

        if (me->query("max_neili") < 1200)
                return "���������Ϊ̫ǳ���������������ɡ�";

        message_sort(HIY "\n$n" HIY"�����𻰣�����վ������������������"
                     "������ǰ����۰뻷������Գ����ƣ����Ʒ���������"
                     "������ȸβ�����ޡ��������ơ�����Ʊա�ʮ���֡���"
                     "����ɽ����һ��һʽ������ȥ����$n" HIY "ʹ���ϲ���"
                     "̽���ϲ���ȸβ�����޶���̫���������е�վ�ڵ�"
                     "�ء����$n" HIY "˫�ֺϱ�̫��Ȧ�������$N" HIY
                     "�ʵ���������ȭ���С����鶥�������ذα�����������"
                     "������׹�⡹�ľ��ϣ����������˶��٣���\n\n" NOR,
                     me, this_object());

        command("say ���μǽ���������������������ʩ����");
        command("say ���������ˣ���ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("taiji-quan"))
                me->improve_skill("taiji-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-quan/ji", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-quan/zhan"))
                return "���Լ��������ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-quan", 1) < 1)
                return "����̫��ȭ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 500)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 140000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-quan", 1) < 150)
                return "���̫��ȭ��Ϊ̫ǳ���������������ɡ�";

        if (me->query("max_neili") < 1200)
                return "���������Ϊ̫ǳ���������������ɡ�";

        message_sort(HIY "\n$n" HIY"�����𻰣�����վ������������������"
                     "������ǰ����۰뻷������Գ����ƣ����Ʒ���������"
                     "������ȸβ�����ޡ��������ơ�����Ʊա�ʮ���֡���"
                     "����ɽ����һ��һʽ������ȥ����$n" HIY "ʹ���ϲ���"
                     "̽���ϲ���ȸβ�����޶���̫���������е�վ�ڵ�"
                     "�ء����$n" HIY "˫�ֺϱ�̫��Ȧ�������$N" HIY
                     "�ʵ���������ȭ���С����鶥�������ذα�����������"
                     "������׹�⡹�ľ��ϣ����������˶��٣���\n\n" NOR,
                     me, this_object());

        command("say ��ֻ�趮��̫��ͼԲת���ϡ������仯֮�⼴�ɡ�");
        command("say ���������ˣ���ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�ճ�־�����\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("taiji-quan"))
                me->improve_skill("taiji-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-quan/zhan", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-quan/tu") >= 10)
                return "��ѧ���㶼�Ѿ�ѧ�ˣ��Ժ�Ҫ�Ƽ����ã�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-quan", 1) < 1)
                return "����̫��ȭ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 3000)
                return "��Ϊ���䵱��Ч���������������Ҳ�æ���㡣";

        if (me->query("shen") < 250000)
                return "������������������û������࣬�Ҳ��ܷ��Ĵ�����У�";

        if (me->query_skill("taiji-quan", 1) < 250)
                return "���̫��ȭ���������ң�Ҫ��������";

        if (me->query_skill("taiji-shengong", 1) < 300)
                return "���̫���񹦻������ң��ú����аɣ�";

        if (me->query_skill("taoism", 1) < 300)
                return "��ĵ�ѧ�ķ��о��Ļ��������ף�Ҫ�¹����ѧ���ǣ�";

        if (me->query("max_jingli") < 1000)
                return "��ľ������ã����㴫����̫��ͼ��Ҳ�������á�";

        message_sort(HIY "\n$n" HIY "���ͷ��˫�����Ữ��һ��Ȧ�ӣ�����"
                     "�����޶������ֽ������¡�\n" NOR, me,
                     this_object());

        command("say �㿴���˶��٣�");

        if (me->query("potential") < me->query("learned_points") + 100)
        {
                write("�㿴�˰��죬û���о���ʲô��"
                      "�Ķ�����������Ǳ�ܻ�������\n");
                return 1;
        }

        me->add("learned_points", 100);

        if (me->add("can_perform/taiji-quan/tu", 1) < 10)
        {
                message_vision(HIY "$N" HIY "����ãã�ĵ���"
                               "��ͷ����˼���á�\n\n" NOR, me);
                tell_object(me, HIC "���̫��ͼ����һ������\n" NOR);
        } else
        {
                message_sort(HIY "$N" HIY "��¶Ц�ݣ�ϲ�������Ѿ�������"
                             "����ν���������ʵ���޷ֱ𰡣�$n" HIY "��"
                             "����Ц�������׾ͺã����׾ͺã��Ժ��������"
                             "ʹ�ã���ȥ�ɡ�\n\n", me, this_object());
                               
                tell_object(me, HIC "��ѧ���˵����ܼ���̫��ͼ����\n" NOR);
                if (me->can_improve_skill("taoism"))
                        me->improve_skill("taoism", 1500000);
                if (me->can_improve_skill("taoism"))
                        me->improve_skill("taoism", 1500000);
                if (me->can_improve_skill("taoism"))
                        me->improve_skill("taoism", 1500000);
                if (me->can_improve_skill("force"))
                        me->improve_skill("force", 1500000);
                if (me->can_improve_skill("force"))
                        me->improve_skill("force", 1500000);
                if (me->can_improve_skill("force"))
                        me->improve_skill("force", 1500000);
                if (me->can_improve_skill("taiji-shengong"))
                        me->improve_skill("taiji-shengong", 1500000);
                if (me->can_improve_skill("taiji-shengong"))
                        me->improve_skill("taiji-shengong", 1500000);
                if (me->can_improve_skill("taiji-shengong"))
                        me->improve_skill("taiji-shengong", 1500000);
                if (me->can_improve_skill("unarmed"))
                        me->improve_skill("unarmed", 1500000);
                if (me->can_improve_skill("unarmed"))
                        me->improve_skill("unarmed", 1500000);
                if (me->can_improve_skill("unarmed"))
                        me->improve_skill("unarmed", 1500000);
                if (me->can_improve_skill("taiji-quan"))
                        me->improve_skill("taiji-quan", 1500000);
                if (me->can_improve_skill("taiji-quan"))
                        me->improve_skill("taiji-quan", 1500000);
                if (me->can_improve_skill("taiji-quan"))
                        me->improve_skill("taiji-quan", 1500000);
	        me->improve_skill("martial-cognize", 1500000);
        	me->add("gongxian", -3000);
        }
        return 1;
}

mixed ask_skill7()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-jian/chan"))
                return "���Լ��������ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-jian", 1) < 1)
                return "����̫��������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 80000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-jian", 1) < 80)
                return "���̫�������������ң�Ҫ��������";

        message_sort(HIY "\n$n" HIY "΢΢Ц��Ц�����һָ����ָ��������"
                     "ʼ��������ʾ���С���������һֱ����ʮ��ʽ��ָ���롹"
                     "��˫��ͬʱ��Բ�����ɵ���ʮ��ʽ���ֽ���ԭ����ֱ��һ"
                     "�׽�����ʾ��ϣ�$n" HIY "�����$N" HIY "�ʵ�������"
                     "̫�������еĽ��⣬���������˶��٣���\n\n" NOR, me,
                     this_object());

        command("haha");
        command("say ��ֻ���ס�����޶������಻����ɡ�");
        command("say ���������ˣ���ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("taiji-jian"))
                me->improve_skill("taiji-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-jian/chan", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill8()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-jian/sui"))
                return "���Լ��������ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-jian", 1) < 1)
                return "����̫��������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 80000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-jian", 1) < 60)
                return "���̫�������������ң�Ҫ��������";

        message_sort(HIY "\n$n" HIY "΢΢Ц��Ц�����һָ����ָ��������"
                     "ʼ��������ʾ���С���������һֱ����ʮ��ʽ��ָ���롹"
                     "��˫��ͬʱ��Բ�����ɵ���ʮ��ʽ���ֽ���ԭ����ֱ��һ"
                     "�׽�����ʾ��ϣ�$n" HIY "�����$N" HIY "�ʵ�������"
                     "̫�������еĽ��⣬���������˶��٣���\n\n" NOR, me,
                     this_object());

        command("haha");
        command("say �������Ķ��������Ķ��գ�����Բת���⡣");
        command("say ���������ˣ���ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("taiji-jian"))
                me->improve_skill("taiji-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-jian/sui", 1);
        me->add("gongxian", -200);

        return 1;
}

mixed ask_skill9()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-jian/jia"))
                return "���Լ��������ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-jian", 1) < 1)
                return "����̫��������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 600)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 100000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-jian", 1) < 150)
                return "���̫�������������ң�Ҫ��������";

        message_sort(HIY "\n$n" HIY "΢΢Ц��Ц�����һָ����ָ��������"
                     "ʼ��������ʾ���С���������һֱ����ʮ��ʽ��ָ���롹"
                     "��˫��ͬʱ��Բ�����ɵ���ʮ��ʽ���ֽ���ԭ����ֱ��һ"
                     "�׽�����ʾ��ϣ�$n" HIY "�����$N" HIY "�ʵ�������"
                     "̫�������еĽ��⣬���������˶��٣���\n\n" NOR, me,
                     this_object());

        command("haha");
        command("say ����������������ǧ���֮Ϊ̫����");
        command("say ���������ˣ���ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("taiji-jian"))
                me->improve_skill("taiji-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-jian/jia", 1);
        me->add("gongxian", -600);

        return 1;
}

mixed ask_skill10()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-jian/zhuan"))
                return "���Լ��������ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-jian", 1) < 1)
                return "����̫��������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 120000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-jian", 1) < 160)
                return "���̫�������������ң�Ҫ��������";

        message_sort(HIY "\n$n" HIY "΢΢Ц��Ц�����һָ����ָ��������"
                     "ʼ��������ʾ���С���������һֱ����ʮ��ʽ��ָ���롹"
                     "��˫��ͬʱ��Բ�����ɵ���ʮ��ʽ���ֽ���ԭ����ֱ��һ"
                     "�׽�����ʾ��ϣ�$n" HIY "�����$N" HIY "�ʵ�������"
                     "̫�������еĽ��⣬���������˶��٣���\n\n" NOR, me,
                     this_object());

        command("haha");
        command("say ���޾�������Ԧ����");
        command("say ���������ˣ���ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������ת����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("taiji-jian"))
                me->improve_skill("taiji-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-jian/zhuan", 1);
        me->add("gongxian", -800);

        return 1;
}

mixed ask_skill11()
{
        object me;

        me = this_player();
        if (me->query("can_perform/taiji-jian/zhenwu"))
                return "�Լ��úö���ϰ�ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������䵱�ɵ��ˣ��γ����ԣ�";

        if (me->query_skill("taiji-jian", 1) < 1)
                return "����̫��������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 2000)
                return "��Ϊ���䵱��Ч�����������������Ȳ�æ���㡣";

        if (me->query("shen") < 120000)
                return "������������������Ļ��ܲ������Ҳ��ܴ�����У�";

        if (me->query_skill("taiji-jian", 1) < 180)
                return "���̫�������������ң�Ҫ��������";

        message_sort(HIY "\n$n" HIY "΢΢��ף����ּ���һ����֦��$N" HIY
                     HIY "ɨ����$N" HIY "������ƽ�����棬������Ϊ�ɻ�"
                     "ֻ������һ������Ȼֻ��$n" HIY "���ƴ�䣬���ȷǷ�"
                     "���仯���$N" HIY "���һ�������Ҳ�����\n\n" NOR,
                     me, this_object());

        command("haha");
        command("say ��������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ������а����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("taiji-jian"))
                me->improve_skill("taiji-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/taiji-jian/zhenwu", 1);
        me->add("gongxian", -2000);

        return 1;
}

mixed ask_jian()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_bad())
        {
                if (me->query("family/family_name") == "�䵱��")
                        message_vision(CYN "$N" CYN "��ŭ����$n" CYN "����������Ϊ�䵱���ӣ�"
                                       "��������ħ�������������ת����\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��ŭ����$n" CYN "�ȵ�������һ��аħ��"
                                       "������Ȼ�ҿ������佣����\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "�䵱��")
                return "���佣�������䵱����֮�������������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ��������佣���㻹����ذɡ�";

        if (me->query("shen") < 60000)
                return "������������������ò������Ҳ��ܰ����佣�����㡣";

        ob = find_object(ZHENWU_SWORD);
        if (! ob) ob = load_object(ZHENWU_SWORD);
	owner = environment(ob);
        while (owner)
	{
                if (owner->is_character() || ! environment(owner))
                        break;
		owner = environment(owner);
	}

        if (owner == me)
                return "���佣�������������ô����ô�����������أ�";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���Ѿ������佣�Ѿ����ȥ�ˡ�";

                if (owner->query("family/master_id") == query("id"))
                        return "���佣������" + owner->query("name") +
                               "���У���Ҫ���þ�ȥ�����ɡ�";
                else
                        return "���佣��������" + owner->query("name") +
                               "���У���ȥ�����һ����ɡ�";
        }

        ob->move(this_object());
        message_vision(CYN "$N" CYN "���ͷ�������ã����������佣Ҫ����һЩ��"
		       "����������飡��\n" NOR, this_object(), me);
        command("give zhenwu jian to " + me->query("id"));
        return 1;
}

int accept_object(object me, object ob)
{
        int r;
        if (r = ::accept_object(me, ob))
                return r;

        if (base_name(ob) != ZHENWU_SWORD)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (me->query("family/master_id") != query("id"))
                command("say ��л��λ" + RANK_D->query_respect(me) + "�����佣���ء�");
        else
                command("say �ܺã��ܺã�");
        destruct(ob);
        return 1;
}

mixed ask_jiuyang()
{
        object ob;
        object me;
        me = this_player();

        if (me->query("can_learn/jiuyang-shengong/wudang")) 
                return "�ϵ��Ѿ���Ӧ�������䵱�������ˣ�����ô����ô���£�";

        if (! me->query("can_learn/jiuyang-shengong/kunlun"))
                return "���ա������澭������ʦ����Զ��ʦ���ж�ʧ������Ҳ��֪������η���";

        if (! me->query("can_learn/jiuyang-shengong/shaolin"))
                return "���������ʱ�ܹ�׷�ء������澭������Զ��ʦҲ���������ѡ�";

        message_vision(CYN "\n��������ϸ������$N" CYN "��һ��Ŀ�ⶸȻһ����\n\n" NOR, me);

        command("say �㲻���ǵ��껹�;������Զ��ʦ֮����");
        command("say ��ν���������л������������ϵ�����ͨ��һ�㣬���ѻ�Ϊ�䵱��������");
        command("say ������²��������ϵ����ǿ��Խ����׾������������㡣");

        tell_object(me, HIC "������ͬ�⴫���㡸�䵱����������\n" NOR);

        if (me->can_improve_skill("martial-cognize"))
	        me->improve_skill("martial-cognize", 1500000);

        me->set("can_learn/jiuyang-shengong/wudang", 1);
        return 1;
}

int try_to_learn_jy()
{
        object me = this_player();

        if (! me->query("can_learn/jiuyang-shengong/wudang"))
        {
                if (me->query("family/master_id") != query("id"))
                {
	                command("say �䵱���������Ǿ����񹦵ķ�֧������"
                                "��ʱ��ʦ����Զ��ʦ���ڡ�");
	                command("say ��������ƶ���ز���ʶ����̸���ϡ�ָ��"
                                "�����֣�");
        	        return -1;
                } else
                {
	                command("say �䵱���������Ǿ����񹦵ķ�֧������"
                                "��ʱ��ʦ����Զ��ʦ���ڡ�");
	                command("say ��Ȼ���书�������������Ķ�����������"
                                "���ֵ��书���������ҵĵ���Ҳ�����ڡ�");
	                return -1;
                }
        }

        if (me->query_skill("wudang-jiuyang") > 180)
        {
                command("say ����䵱������������Ϊ����ˣ��Ժ�����Լ��о��ɡ�");
                return -1;
        }

        if (me->query("shen") < 0)
        {
                command("say �ϵ��������Ĵ������������������аħ������֮�");
                command("say ����Ĺ����º��������ϵ��Ұɡ�");
                return -1;
        }
        return 0;
}

int recognize_apprentice(object me, string skill)
{
        if (! me->query("can_learn/jiuyang-shengong/wudang"))
        {
                if (me->query("family/master_id") != query("id"))
                {
	                command("say �䵱���������Ǿ����񹦵ķ�֧������"
                                "��ʱ��ʦ����Զ��ʦ���ڡ�");
	                command("say ��������ƶ���ز���ʶ����̸���ϡ�ָ��"
                                "�����֣�");
        	        return -1;
                } else
                {
	                command("say �䵱���������Ǿ����񹦵ķ�֧������"
                                "��ʱ��ʦ����Զ��ʦ���ڡ�");
	                command("say ��Ȼ���书�������������Ķ�����������"
                                "���ֵ��书���������ҵĵ���Ҳ�����ڡ�");
	                return -1;
                }
        }

        if (skill != "wudang-jiuyang")
        {
                command("say ��ѧ�Ӷ�����Ҳ�����ã��㻹��ר��ѧϰ�䵱�������ɡ�");
                return -1;
        }
        return 1;
}

void unconcious()
{
        die();
}
