#include <ansi.h>
#include "zhenyuan.h"

#define HOUBEI    "/clone/lonely/houbeidao"
#define LETTER    "/clone/special/sjmletter"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_dao();

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();

void create()
{
        object ob;
	set_name("��ά��", ({ "wang weiyang", "wang", "weiyang", "wei", "yang"}));
	set("nickname", HIY "�����˷" NOR);
	set("title", "��Զ�ھ�����ͷ");
  	set("gender", "����");
        set("long", @LONG
��λ������Զ�ھֵĴ�ʼ�ˣ��С������˷��֮
�Ƶ���ά��������о仰�У�������������Ī
�����������������ָ�ľ������������������
�棬��������͸��������̫��Ѩ΢΢͹�𣬱�֪
���ǰ������еĶ�����֡��������������Ѿ���
�����ھ��������ˣ�һ����˼��������Լ�����
����Ϊ�ϡ�
LONG );
  	set("age", 68);
	set("class", "fighter");
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 5200);
        set("max_jing", 4000);
        set("neili", 5800);
        set("max_neili", 5800);
        set("jiali", 200);
        set("combat_exp", 3500000);

  	set_skill("force", 260);
  	set_skill("nei-bagua", 260);
  	set_skill("bagua-xinfa", 240);
  	set_skill("parry", 260);
  	set_skill("wai-bagua", 260);
  	set_skill("dodge", 240);
  	set_skill("bagua-bu", 240);
  	set_skill("unarmed", 240);
  	set_skill("youshen-zhang", 240);
  	set_skill("strike", 240);
  	set_skill("bagua-zhang", 240);
  	set_skill("bazhen-zhang", 240);
  	set_skill("cuff", 240);
  	set_skill("bagua-quan", 240);
  	set_skill("yanqing-quan", 240);
  	set_skill("blade", 260);
  	set_skill("bagua-dao", 260);
  	set_skill("kuimang-dao", 240);
  	set_skill("throwing", 240);
  	set_skill("bagua-biao", 240);
  	set_skill("literate", 220);
  	set_skill("martial-cognize", 240);

	map_skill("unarmed", "youshen-zhang");
	map_skill("dodge", "bagua-bu");
	map_skill("force", "nei-bagua");
	map_skill("strike", "bazhen-zhang");
	map_skill("blade", "bagua-dao");
	map_skill("cuff", "bagua-quan");
	map_skill("parry", "wai-bagua");
	map_skill("throwing", "bagua-biao");

	prepare_skill("unarmed", "youshen-zhang");
        set("class", "fighter");

  	create_family("������", 1, "����");

        set("inquiry", ([
                "���Ͻ�" : (: ask_dao :),
                "������"     : (: ask_skill1 :),
                "������ӡ"   : (: ask_skill2 :),
                "Ǭ��һ��"   : (: ask_skill3 :),
                "����������" : (: ask_skill4 :),
                "������â"   : (: ask_skill5 :),
                "�쵶����"   : (: ask_skill6 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.mang" :),
                (: perform_action, "blade.tian" :),
                (: perform_action, "unarmed.fan" :),
                (: perform_action, "parry.zhen" :),
                (: perform_action, "throwing.zhi" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

  	setup();

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        if (clonep())
        {
                ob = find_object(HOUBEI);
                if (! ob) ob = load_object(HOUBEI);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/clone/weapon/gangdao");
                        ob->move(this_object());
                        ob->wield();
                }
        }

  	carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/beijing/npc/obj/jinbiao"));
}

int accept_fight(object me)
{
  	command("say ��λ" + RANK_D->query_respect(me) +
                "���㲻���ҵĶ��֣��ҿ������������˰ɣ�\n");
  	return 0;
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if (me->query_int() < 35 && me->query_con() < 35)
        {
                command("hmm");
                command("say ������������Ϊ���ֲ����飬����������ʲô�ã�");
                return;
        }

        if (me->query("combat_exp") < 320000)
        {
                command("say ��Ľ�������̫���ˣ�����ͽ���Ǽ����£��ȹ���������˵�ɣ�");
                return;
        }

        if (me->query_skill("bagua-xinfa", 1) < 100)
        {
                command("say �㱾�ŵ��ڹ���Ϊ̫���ˣ��ٻ�ȥ�����ɡ�");
                return;
        }

        command("haha");
  	command("say �ܺã�ϣ������Ŭ�����ú�ѧϰ�����书�����ս������ŷ�����");
        command("recruit " + me->query("id"));

        if ((string)me->query("class") != "fighter")
                me->set("class", "fighter");
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/wai-bagua/zhen"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("wai-bagua", 1) < 1)
                return "��������Զ�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 100)
                return "�����ھ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("wai-bagua", 1) < 60)
                return "�������Ի����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "΢΢һЦ������Ҳ���𻰣�ֻ��������֣������"
                       "��\n$N" HIY "�ؿڡ�����$N" HIY "�ɻ�䣬ȴ��$n" HIY "�ƾ�"
                       "���£�$N" HIY "��ʱȫ��\nһ�������������������޲�����"
                       "��������ʧɫ��\n" NOR, me, this_object());

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ������𡹡�\n" NOR);

        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("wai-bagua"))
                me->improve_skill("wai-bagua", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/wai-bagua/zhen", 1);
        me->add("gongxian", -100);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bazhen-zhang/yin"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("bazhen-zhang", 1) < 1)
                return "������������ƶ�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 500)
                return "�����ھ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 180)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("bazhen-zhang", 1) < 130)
                return "��İ�������ƻ����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "Ц��Ц����$N" HIY "��ͷʾ���������������"
                       "�ģ�����ȫ\n������һ�ƣ�Я������֮�Ʒ�����$N" HIY "��ǰ"
                       "��һ����ͭ��¯\n���䣬��ʱֻ����Ȼһ�����죬��¯�ڵ����"
                       "��$n" HIY "����\n���������Ĵ������������������������ɢ"
                       "��$N" HIY "��ŷ���\n������ͭ��¯�ϻ�ȻǶ��һ˫��ӡ��\n"
                       NOR, me, this_object());

        command("ke");
        command("nod");
        command("say �������������Ұ����ž�ѧ����Ҫ�ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�������ӡ����\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("bazhen-zhang"))
                me->improve_skill("bazhen-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bazhen-zhang/yin", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-biao/zhi"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("bagua-biao", 1) < 1)
                return "���������ھ���ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 800)
                return "�����ھ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("bagua-biao", 1) < 120)
                return "��İ����ھ������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "������ǰ�������ڶ�������˵��Щ"
                       "ʲô�������\n������֣�ʮָ���ţ�һ��һ����ɷ�����"
                       "��������һ��\n���ر�İ������š�\n" NOR, me,
                       this_object());

        command("nod");
        command("say �ղ�����˵����ɶ������ˣ�ʣ�µľ��ǿ��Լ������ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�Ǭ��һ������\n" NOR);

        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("bagua-biao"))
                me->improve_skill("bagua-biao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bagua-biao/zhi", 1);
        me->add("gongxian", -800);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/youshen-zhang/fan"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("youshen-zhang", 1) < 1)
                return "������������ƶ�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 500)
                return "�����ھ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 160)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("youshen-zhang", 1) < 120)
                return "�����������ƻ����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��Ц��������$N" HIY "˵��������Ȼ���������"
                       "���������\n���裬�ҽ��ձ㴫�������Ʒ��ľ��衣��˵���ֻ"
                       "��$n" HIY "\n��̤�����ķ�֮λ��������ȫ�����߲�����˫����"
                       "����Ķ�\n������ʱ��Ӱ��$N" HIY "�ķ������������֣�$N" HIY
                       "�е���������Ӱ\n֮�£���Ȼ�����������ܳ�ͨ��\n" NOR, me,
                       this_object());

        command("haha");
        command("say ���е�Ҫ�費������һ�����֣����������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����������ơ���\n" NOR);

        if (me->can_improve_skill("dodge"))
                me->improve_skill("dodge", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("youshen-zhang"))
                me->improve_skill("youshen-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/youshen-zhang/fan", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-dao/mang"))
                return "�Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query_skill("bagua-dao", 1) < 1)
                return "�������Ե�����ûѧ��̸ʲô���У�";

        if (me->query_skill("wai-bagua", 1) < 1)
                return "����������񹦶�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 1000)
                return "�����ھ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("bagua-dao", 1) < 140)
                return "��İ��Ե��������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("wai-bagua", 1) < 140)
                return "���������񹦻����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 200)
                return "�ţ�����ڹ����������ߣ��������������Ұɡ�";

        message_vision(HIY "$n" HIY "����һЦ����$N" HIY "���������ֹ��˼��䣬"
                       "�漴��������\n�������հ����ķ�֮λ�Ȼ���ʾ��$N" HIY "��"
                       "һ�Գ�Ĭ���ֱ��\n��ʾ������ͻȻ�۾�һ�����ƺ�����ѧ"
                       "���������µ�ͻ�ơ�\n" NOR,
                       me, this_object());
        command("smile");
        command("say ����ǵ�â��Ҫ�������Լ������ڼ���ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������â����\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("bagua-dao"))
                me->improve_skill("bagua-dao", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("wai-bagua"))
                me->improve_skill("wai-bagua", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bagua-dao/mang", 1);
        me->add("gongxian", -1000);

        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-dao/tian"))
                return "�㲻���Ѿ�ѧ��������ô���ָ������ˣ�";

        if (me->query("family/family_name") != query("family/family_name")
            && me->query("family/family_name") != "�̼ұ�")
                return RANK_D->query_respect(me) + "�ͱ��ھ������������γ����ԣ�";

        if (me->query("family/family_name") == "�̼ұ�")
                return "����Ȼ���̼ұ��ĵ��ӣ���û����ʦ��ͬ����Ҳ���ܴ������У�";

        if (me->query_skill("bagua-dao", 1) < 1)
                return "�������Ե�����ûѧ��̸ʲô���У�";

        if (me->query_skill("wai-bagua", 1) < 1)
                return "����������񹦶�ûѧ��̸ʲô���У�";

        if (me->query_skill("nei-bagua", 1) < 1)
                return "�����ڰ����񹦶�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 2400)
                return "�����ھ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("bagua-dao", 1) < 200)
                return "��İ��Ե��������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("wai-bagua", 1) < 200)
                return "���������񹦻����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("nei-bagua", 1) < 200)
                return "����ڰ����񹦻����ò����ң��Լ���ȥ���������ɣ�";

        if ((int)me->query("max_neili") < 3200)
                return "���������Ϊ���㣬ʩչ�������У��������������������������Ұɡ�";

        message_vision(HIY "$n" HIY "΢Ц�ŵ��˵�ͷ����$N" HIY "�����������Ұ���"
                       "������Ҳ��\n�ó������ˣ���֪����Ϊ�����ԡ��𣿡�$N" HIY
                       "��Ҳ���룬���\n����������������Ǭ���ؾ���������㡢��"
                       "���𡢷�����\n��������Ӷҡ�������롢���̾��ޡ���$n" HIY
                       "������Ϊ��\n��Ц������������ֻ֪��һ����֪�������ν��"
                       "���ԡ���\n��������һ�������֡���$N" HIY "���˺�һ�ᣬ"
                       "ĬĬ˼����һ��\n����ͻȻ˫Ŀһ�����е�����ʦ������������"
                       "����ʲô����\n���ġ����ԡ��ˣ���$n" HIY "��Ц��������ֻ"
                       "Ҫ�����������\n����ô����Ƶ�������Ѿ�ѧ���ˡ���\n" NOR,
                       me, this_object());

        command("haha");
        tell_object(me, HIC "��ѧ���ˡ��쵶���ơ���\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("nei-bagua"))
                me->improve_skill("nei-bagua", 1500000);
        if (me->can_improve_skill("nei-bagua"))
                me->improve_skill("nei-bagua", 1500000);
        if (me->can_improve_skill("nei-bagua"))
                me->improve_skill("nei-bagua", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("wai-bagua"))
                me->improve_skill("wai-bagua", 1500000);
        if (me->can_improve_skill("wai-bagua"))
                me->improve_skill("wai-bagua", 1500000);
        if (me->can_improve_skill("wai-bagua"))
                me->improve_skill("wai-bagua", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("bagua-dao"))
                me->improve_skill("bagua-dao", 1500000);
        if (me->can_improve_skill("bagua-dao"))
                me->improve_skill("bagua-dao", 1500000);
        if (me->can_improve_skill("bagua-dao"))
                me->improve_skill("bagua-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bagua-dao/tian", 1);
        me->add("gongxian", -2400);

        return 1;
}

mixed ask_dao()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "������")
                return "���Ͻ���Ե����Ұ����ŵ����������������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ����ú��Ͻ𵶣�������˰ɡ�";

        if (me->query_skill("bagua-dao", 1) < 120)
                return "�㻹����ȥ��������İ��Ե����ɡ�";

        ob = find_object(HOUBEI);
        if (! ob) ob = load_object(HOUBEI);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ף����Ͻ����ڲ���������������ô�����������ң�";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�������Ѿ��Ѻ��Ͻ𵶽��ȥ�ˡ�";

                if (owner->query("family/family_name") == "������")
                        return "���Ͻ�����ʱ����ͬ��ʦ��" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���ŵĺ��Ͻ�����������" + owner->query("name") +
                               "���У���Ҫ�þ�ȥ����������ɣ�";
        }

        ob->move(this_object());
        message_vision(CYN "$N" CYN "΢΢Ц��������Ȼ��������������Ͻ����"
                       "��ȥ�ðɣ����߽���ʱ�����������ǵ����磡��\n" NOR,
                       this_object(), me);
        command("give houbei dao to " + me->query("id"));
        return 1;
}

int accept_object(object me, object ob)
{
        if (base_name(ob) != HOUBEI
            && base_name(ob) != LETTER)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (base_name(ob) == LETTER)
        {
                if (me->query("can_perform/bagua-dao/tian"))
                {
                     command("shake");
                     command("shit");
                     return 1;
                }
                command("nod");
                command("haha");
                command("say �ã��ã���Ȼ�������Ҿʹ������С��쵶���ơ���"); 
                message_sort(HIY "\n$n" HIY "΢Ц�ŵ��˵�ͷ����$N" HIY "��������"
                             "��֪����Ϊ�����ԡ��𣿡�$N" HIY "��Ҳ���룬��ڴ��"
                             "�������������Ǭ���ؾ���������㡢�ƾ��𡢷����ӿ���"
                             "����Ӷҡ�������롢���̾��ޡ���$n" HIY "������Ϊ����"
                             "��Ц������������ֻ֪��һ����֪�������ν�����ԡ�����"
                             "������һ�������֡���$N" HIY "���˺�һ�ᣬĬĬ˼����"
                             "һ�仰��ͻȻ˫Ŀһ�����е�����ʦ����������������ʲô"
                             "�������ġ����ԡ��ˣ���$n" HIY "��Ц��������ֻҪ����"
                             "�����������ô����Ƶ�������Ѿ�ѧ���ˡ���\n" NOR,
                             me, this_object());

        command("haha");
        tell_object(me, HIC "��ѧ���ˡ��쵶���ơ���\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("nei-bagua"))
                me->improve_skill("nei-bagua", 1500000);
        if (me->can_improve_skill("nei-bagua"))
                me->improve_skill("nei-bagua", 1500000);
        if (me->can_improve_skill("nei-bagua"))
                me->improve_skill("nei-bagua", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("wai-bagua"))
                me->improve_skill("wai-bagua", 1500000);
        if (me->can_improve_skill("wai-bagua"))
                me->improve_skill("wai-bagua", 1500000);
        if (me->can_improve_skill("wai-bagua"))
                me->improve_skill("wai-bagua", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("bagua-dao"))
                me->improve_skill("bagua-dao", 1500000);
        if (me->can_improve_skill("bagua-dao"))
                me->improve_skill("bagua-dao", 1500000);
        if (me->can_improve_skill("bagua-dao"))
                me->improve_skill("bagua-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/bagua-dao/tian", 1);

        return 1;

        }
        
        else
        {
            if (me->query("family/master_id") != query("id"))
                    command("say ��л��λ" + RANK_D->query_respect(me) + "�����Ͻ𵶽��ء�");
            else
                    command("say �ܺã��ܺã�");
                    destruct(ob);
        }
        return 1;
}
