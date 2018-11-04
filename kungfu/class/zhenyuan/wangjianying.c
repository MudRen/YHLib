#include <ansi.h>
#include "zhenyuan.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();

void create()
{
	set_name("����Ӣ", ({ "wang jianying", "wang", "jianying" }));
        set("long", @LONG
������Զ�ھ�����ͷ��ά��Ĵ���ӣ�����ȥ��
�����棬������������̬��������֪���������
���������ף�ٲȻ���ǵ��������ŵ�һ���֣���
�������ŵļ̳��ˡ�
LONG );
	set("title", "���������ŵ�һ����");
  	set("gender", "����");
  	set("age", 48);
	set("class", "fighter");
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 3200);
        set("max_jing", 3200);
        set("neili", 3600);
        set("max_neili", 3600);
        set("jiali", 150);
        set("combat_exp", 2500000);

  	set_skill("parry", 160);
  	set_skill("wai-bagua", 160);
  	set_skill("force", 180);
  	set_skill("nei-bagua", 180);
  	set_skill("bagua-xinfa", 160);
  	set_skill("dodge", 160);
  	set_skill("bagua-bu", 160);
  	set_skill("blade", 180);
  	set_skill("bagua-dao", 180);
  	set_skill("kuimang-dao", 160);
  	set_skill("strike", 160);
  	set_skill("bagua-zhang", 160);
  	set_skill("bazhen-zhang", 160);
  	set_skill("cuff", 160);
  	set_skill("bagua-quan", 160);
  	set_skill("throwing", 160);
  	set_skill("bagua-biao", 160);
  	set_skill("literate", 140);
  	set_skill("martial-cognize", 160);

        set("no_teach", ([
                "nei-bagua" : "�ڰ����񹦱������Ҹ������Դ��ڡ�",
                "bagua-dao" : "���Ե��������������Ҹ������Խ��ڡ�",
        ]));

	map_skill("blade", "bagua-dao");
	map_skill("dodge", "bagua-bu");
	map_skill("force", "nei-bagua");
	map_skill("strike", "bagua-zhang");
	map_skill("cuff", "bagua-quan");
	map_skill("parry", "wai-bagua");
	map_skill("throwing", "bagua-biao");

        prepare_skill("cuff", "bagua-quan");
        prepare_skill("strike", "bagua-zhang");

  	create_family("������", 2, "����");

        set("inquiry", ([
                "���м���" : (: ask_skill1 :),
                "��������" : (: ask_skill2 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "blade.mang" :),
                (: perform_action, "cuff.gua" :),
                (: perform_action, "strike.ding" :),
                (: perform_action, "strike.jia" :),
                (: perform_action, "parry.zhen" :),
                (: perform_action, "throwing.zhi" :),
                (: perform_action, "throwing.xian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

  	setup();

        carry_object("/clone/weapon/gangdao")->wield();
  	carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/beijing/npc/obj/jinbiao"));

}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

	if (me->query("combat_exp") < 100000)
    	{
      		command("say ��Ľ�������̫���ˣ��������ھ�������������һ��ʱ��ɣ�");
      		return;
    	}

        if (me->query_skill("bagua-xinfa", 1) < 80)
        {
                command("say �㱾�ŵ��ڹ���Ϊ̫�����������˵�ɡ�");
                return;
        }

  	command("nod");
  	command("say ��Ȼ��ˣ��Ҿ������㡣");
        command("recruit " + me->query("id"));
        if ((string)me->query("class") != "fighter")
                me->set("class", "fighter");
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-zhang/jia"))
                return "��˵���Ҷ�˵���ˣ�����ʲô�����׾��Լ���ȥ����";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("bagua-zhang", 1) < 1)
                return "���������ƶ�ûѧ��̸ʲô���У�";

        if (me->query_skill("bagua-biao", 1) < 1)
                return "���������ڶ�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 400)
                return "��Ϊ�ھֳ�����������������ʱ��æ���㡣";

        if (me->query_skill("bagua-zhang", 1) < 120)
                return "��İ����ƻ����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("bagua-biao", 1) < 120)
                return "��İ����ڻ����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 150)
                return "�ţ�������ƶ��Ѿ�����ˣ������м��ڹ�����ǻ�������ɰ�������á�";

        message_vision(HIY "$n" HIY "���˵�ͷ�����ֽ�$N" HIY "�е���ߣ��ڶ�������"
                       "�����˰�\n�죬��ʱ��ʱ����ֱȻ����¡�$N" HIY "һ����һ�߲�"
                       "ס�ĵ�ͷ��\n�ǣ��ƺ���$n" HIY "�Ľ̵����и���\n" NOR, me,
                       this_object());

        command("nod");
        command("say ��˵���Ҷ�˵�ˣ����Լ���ȥ��ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����м��ڡ���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("bagua-zhang"))
                me->improve_skill("bagua-zhang", 1500000);
        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("bagua-biao"))
                me->improve_skill("bagua-biao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bagua-zhang/jia", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-biao/xian"))
                return "�ţ����в����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("bagua-zhang", 1) < 1)
                return "���������ƶ�ûѧ��̸ʲô���У�";

        if (me->query_skill("bagua-biao", 1) < 1)
                return "���������ڶ�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 400)
                return "��Ϊ�ھֳ�����������������ʱ��æ���㡣";

        if (me->query_skill("bagua-zhang", 1) < 120)
                return "��İ����ƻ����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("bagua-biao", 1) < 120)
                return "��İ����ڻ����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 200)
                return "�ţ�������ƶ��Ѿ�����ˣ������м��ڹ�����ǻ�������ɰ�������á�";

        message_vision(HIY "$n" HIY "����$N" HIY "���죬����ĵ��˵�ͷ����$N" HIY
                       "˵��������Ȼ��\n������ģ��Ҿ͸�����ʾһ�飬��ɿ���ϸ�ˣ�"
                       "�����û���\n���䣬��ʱ��$n" HIY "��״ܳ�һ����⣬ֱ��$N"
                       HIY "��ȥ��$N" HIY "��\n״���������ܣ���ɲ�Ǽ�ֻ��$n" HIY
                       "����һ�Σ�һ˫����\n�Ѵ���$N" HIY "��ǰ��$N" HIY "��ʱ����"
                       "���������춼˵����������\n" NOR, me, this_object());

        command("haha");
        command("say ���н̸����ˣ����м������������ӽ��£�ǧ���ȥ���ǹٸ���");
        tell_object(me, HIC "��ѧ���ˡ��������ơ���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("bagua-zhang"))
                me->improve_skill("bagua-zhang", 1500000);
        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("bagua-biao"))
                me->improve_skill("bagua-biao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bagua-biao/xian", 1);
        me->add("gongxian", -400);

        return 1;
}