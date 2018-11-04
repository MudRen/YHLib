#include <ansi.h>
#include "zhenyuan.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_GUARDER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();

void create()
{
	set_name("������", ({ "wang jianjie", "wang", "jianjie" }));
        set("long", @LONG
������Զ�ھ�����ͷ��ά��ĵڶ������ӣ��ӳ�
��ҵ������һ������ŵĺ��书�������ھ����
�������������ܹܣ�����ȥ������������������
ʵ����ŭ������
LONG );
	set("title", "�����ŵڶ�������");
  	set("gender", "����");
  	set("age", 45);
	set("class", "fighter");
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 3500);
        set("max_jing", 3500);
        set("neili", 3200);
        set("max_neili", 3200);
        set("jiali", 130);
        set("combat_exp", 1500000);

        set_skill("parry", 160);
        set_skill("wai-bagua", 160);
        set_skill("force", 160);
        set_skill("nei-bagua", 160);
        set_skill("bagua-xinfa", 140);
        set_skill("dodge", 140);
        set_skill("bagua-bu", 140);
        set_skill("blade", 160);
        set_skill("bagua-dao", 160);
        set_skill("kuimang-dao", 160);
        set_skill("strike", 160);
        set_skill("bagua-zhang", 140);
        set_skill("bazhen-zhang", 160);
        set_skill("cuff", 140);
        set_skill("bagua-quan", 140);
        set_skill("throwing", 140);
        set_skill("bagua-biao", 140);
        set_skill("literate", 160);
  	set_skill("martial-cognize", 140);

        set("no_teach", ([
                "wai-bagua" : "�����������񹦡��㻹�����ҵ������Ҹ������ˡ�",
                "nei-bagua" : "�ҵ�˵���ˣ��ڰ����񹦲�����㴫�ڣ���ֱ�����ҵ����ˡ�",
                "bagua-dao" : "���Ե��������������Ҹ������Խ��ڡ�",
        ]));

	map_skill("blade", "bagua-dao");
	map_skill("unarmed", "bazhen-zhang");
	map_skill("dodge", "bagua-bu");
	map_skill("force", "nei-bagua");
	map_skill("strike", "bagua-zhang");
	map_skill("cuff", "bagua-quan");
	map_skill("parry", "wai-bagua");
	map_skill("throwing", "bagua-biao");

	prepare_skill("strike", "bazhen-zhang");

        set("inquiry", ([
                "����ȭ"   : (: ask_skill1 :),
                "���Ķ�"   : (: ask_skill2 :),
                "��������" : (: ask_skill3 :),
        ]));

        set("coagents", ({
                ([ "startroom" : "/d/beijing/shufang",
                   "id"        : "wang weiyang" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "�Ҳ���������ô�����ģ�����������"
                                "���뿪�������ݹ������飡" NOR,
                "refuse_carry": CYN "$N" CYN "����$n" CYN "��üһ"
                                "�����ȵ����㱳�ϱ�����ʲô������"
                                "��������" NOR,
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "blade.mang" :),
                (: perform_action, "strike.yin" :),
                (: perform_action, "parry.zhen" :),
                (: perform_action, "throwing.zhi" :),
                (: perform_action, "throwing.xian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

  	create_family("������", 2, "����");

  	setup();

  	carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/beijing/npc/obj/jinbiao"));
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

	if (me->query("combat_exp") < 20000)
    	{
      		command("say ��Ľ�������̫���ˣ��������ھ�������������һ��ʱ��ɣ�");
      		return;
    	}

  	command("nod");
  	command("say ��Ȼ��ˣ��Ҿ������㡣��ƽʱҲҪ��Ϊ�ھֳ�����");
        command("recruit " + me->query("id"));
        if ((string)me->query("class") != "fighter")
                me->set("class", "fighter");
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-quan/gua"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("bagua-quan", 1) < 1)
                return "��������ȭ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 100)
                return "��Ϊ�ھֳ�����������������ʱ��æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("bagua-quan", 1) < 70)
                return "��İ���ȭ�������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ��˵�������Ҹ�����ʾһ��"
                       "����Ҫ����\n���ˡ���$n" HIY "�������䣬ͻȻ����һ�࣬˫��"
                       "��ʱ���³�\nȥ������ȴ������һ��������$N" HIY "��˫��бб"
                       "����ȥ��������\nΪ�����ʱ��$N" HIY "���˸����ֲ�����\n"
                       NOR, me, this_object());

        command("haha");
        command("say �㿴�����˶��٣�");
        tell_object(me, HIC "��ѧ���ˡ�����ȭ����\n" NOR);

        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("bagua-quan"))
                me->improve_skill("bagua-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bagua-quan/gua", 1);
        me->add("gongxian", -100);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-zhang/ding"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("bagua-zhang", 1) < 1)
                return "���������Ʒ���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "��Ϊ�ھֳ�����������������ʱ��æ���㡣";

        if (me->query_skill("force") < 120)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("bagua-zhang", 1) < 80)
                return "��İ����Ʒ������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "üͷ΢΢һ�壬���´�����$N" HIY "һ���������"
                       "�ֽ�$N" HIY "��\n�����ԣ��ڶ������������˰��죬ʱ��ʱ��̽��"
                       "���ֱȻ���\n����ʽ��$N" HIY "������Цһ�����ƺ���������\n"
                       NOR, me, this_object());

        command("nod");
        command("say ���п��Թ��в��������Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����Ķ�����\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("bagua-zhang"))
                me->improve_skill("bagua-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bagua-zhang/ding", 1);
        me->add("gongxian", -150);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kuimang-dao/pan"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("kuimang-dao", 1) < 1)
                return "��������������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "��Ϊ�ھֳ�����������������ʱ��æ���㡣";

        if (me->query_skill("force") < 60)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("kuimang-dao", 1) < 40)
                return "����������������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "Ц��Ц�����ֽ�$N" HIY "�е���ǰ��������$N" HIY
                       "�����ֹ��˰�\n�졣Ȼ���ְγ�������ת���£�б�ö������ƺ���"
                       "һ����Ϊ\n���صĵ�����\n" NOR, me, this_object()); 

        command("nod");
        command("say ���кܼ򵥣��Լ���ϰ���С�");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("kuimang-dao"))
                me->improve_skill("kuimang-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kuimang-dao/pan", 1);
        me->add("gongxian", -50);

        return 1;
}

void unconcious()
{
        die();
}
