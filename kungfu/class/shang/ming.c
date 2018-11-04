#include <ansi.h>
#include "shang.h"

#define BAGUADAO    "/clone/lonely/baguadao"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_dao();

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();
mixed ask_skill7();
mixed give_letter();


void create()
{
        object ob;
        set_name("�̽���", ({"shang jianming", "shang", "jianming"}));
        set("gender", "����");
        set("title", "�̼ұ�����");
        set("nickname", YEL "���Ե�" NOR);
        set("age", 45);
        set("long", @LONG
�������ų�������ĸߴ���࣬���Ŷ��룬��
�����࣬ģ����Ϊ���ϡ�������ɽ���������
�ұ������α��������Ե����̽������ഫ����
��˫�����书�˵ã��ڽ����Ϻ�����֡�
LONG);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 45);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 3300);
        set("max_jing", 3300);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 180);
        set("combat_exp", 3800000);
        set("score", 10000);

        set_skill("force", 240);
        set_skill("nei-bagua", 240);
        set_skill("shangjia-neigong", 220);
        set_skill("parry", 220);
        set_skill("wai-bagua", 220);
        set_skill("dodge", 200);
        set_skill("bagua-bu", 200);
        set_skill("unarmed", 200);
        set_skill("tan-tui", 200);
        set_skill("strike", 240);
        set_skill("bagua-zhang", 240);
        set_skill("bazhen-zhang", 220);
        set_skill("cuff", 200);
        set_skill("bagua-quan", 200);
        set_skill("baisheng-quan", 200);
        set_skill("sword", 200);
        set_skill("quemen-jian", 200);
        set_skill("blade", 240);
        set_skill("bagua-dao", 240);
        set_skill("shangjia-dao", 220);
        set_skill("throwing", 200);
        set_skill("jinbiao-jue", 200);
        set_skill("literate", 240);
        set_skill("martial-cognize", 220);

        map_skill("unarmed", "tan-tui");
        map_skill("dodge", "bagua-bu");
        map_skill("force", "nei-bagua");
        map_skill("strike", "bagua-zhang");
        map_skill("sword", "quemen-jian");
        map_skill("blade", "bagua-dao");
        map_skill("cuff", "bagua-quan");
        map_skill("parry", "wai-bagua");
        map_skill("throwing", "jinbiao-jue");

        prepare_skill("cuff", "bagua-quan");
        prepare_skill("strike", "bagua-zhang");

        set("class", "fighter");

        create_family("�̼ұ�", 3, "����");

        set("inquiry", ([
                "�Ͻ���Ե�" : (: ask_dao :),
                "������"     : (: ask_skill1 :),
                "�������"   : (: ask_skill2 :),
                "��������"   : (: ask_skill3 :),
                "������ӡ"   : (: ask_skill4 :),
                "��â����"   : (: ask_skill5 :),
                "������â"   : (: ask_skill6 :),
                "ɱ���޻�"   : (: ask_skill7 :),
                "�쵶����"   : (: give_letter :),
                "��һ��"     : "Ŷ����˵���˵��������˵ã���ϧ��û��������",
                "���˷�"     : "�ߣ��������˾�Ȼ�Һų������޵У�����һ��Ҫȥ��ᡣ"
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.mang" :),
                (: perform_action, "blade.sha" :),
                (: perform_action, "strike.ding" :),
                (: perform_action, "cuff.gua" :),
                (: perform_action, "parry.zhen" :),
                (: perform_action, "throwing.huan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
/*
        if (clonep())
        {
                ob = find_object(BAGUADAO);
                if (! ob) ob = load_object(BAGUADAO);
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
*/
        carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/beijing/npc/obj/jinbiao"));
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->name(1) == "�̽���")
        {
                command("say �����̵ģ���ô��Ҳȡ������֣�");
                return;
        }

        if (ob->name(1) == "����̫")
        {
                command("say �Ҳ٣���ȡ���������ʲô��˼��");
                return;
        }

        if (ob->name(1) == "�̱���")
        {
                command("say ���������һ��������ֲ��У�");
                return;
        }

        if (ob->query("combat_exp") < 300000)
        {
                command("say �����ڽ�������̫ǳ�����������������ɡ�");
                return;
        }

        if ((int)ob->query("shen") > -30000)
        {
                command("sneer");
                command("say �㵹��ѧ����ʼ������ˡ�");
                return;
        }

        if (ob->query_skill("shangjia-neigong", 1) < 100)
        {
                command("hmm");
                command("say ����������������ڹ���û�޺ã���ôѧϰ�ϳ���ѧ��");
                return;
        }

        command("nod2");
        command("say ������������ģ������ұ�����Ϊͽ��");
        command("say �պ����̼ұ���������������ȫ�����ˡ�");
        command("recruit " + ob->query("id"));

        if ((string)ob->query("class") != "fighter")
                ob->set("class", "fighter");
        return;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/wai-bagua/zhen"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("wai-bagua", 1) < 1)
                return "��������Զ�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 100)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -5000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

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

        if (me->query("can_perform/baisheng-quan/kai"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("baisheng-quan", 1) < 1)
                return "������ʤ��ȭ��ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 300)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -20000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

        if (me->query_skill("force") < 140)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("baisheng-quan", 1) < 100)
                return "��İ�ʤ��ȭ�����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ�����������������ˣ����漴"
                       "��������\n�ƣ���ʾȭ�С���ʱֻ��$n" HIY "������ĺ��ƣ�����"
                       "ת��Ϊ\n���������������ɹ��֣���������һ�����ӳ�����ƽ��"
                       "��\n����$N" HIY "��ȥ��������Ϊ���\n" NOR, me,
                       this_object());

        command("sneer");
        command("say ���϶��ܹ��������У�Ҳ����ϸ����");
        command("say ���в������ӣ��Լ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������������\n" NOR);

        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("baisheng-quan"))
                me->improve_skill("baisheng-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/baisheng-quan/kai", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jinbiao-jue/huan"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("jinbiao-jue", 1) < 1)
                return "�������ھ���ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 300)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -15000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

        if (me->query_skill("force") < 140)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("jinbiao-jue", 1) < 100)
                return "��Ľ��ھ������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "������ǰ�������ڶ�������˵��Щ"
                       "ʲô�������\n������֣�ʮָ���ţ�һ��һ����ɷ�����"
                       "��������һ��\n���ر�İ������š�\n" NOR, me,
                       this_object());

        command("nod");
        command("say �ղ�����˵����ɶ������ˣ�ʣ�µľ��ǿ��Լ������ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);

        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("jinbiao-jue"))
                me->improve_skill("jinbiao-jue", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jinbiao-jue/huan", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bazhen-zhang/yin"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("bazhen-zhang", 1) < 1)
                return "������������ƶ�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 500)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -20000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

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
        command("say ���������ƾ���Ƿ�����Ҫ�ڼ���ϰ��");
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

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/shangjia-dao/juan"))
                return "�Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("shangjia-dao", 1) < 1)
                return "�����̼ҵ�����ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 80)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -1000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

        if (me->query_skill("shangjia-dao", 1) < 50)
                return "����̼ҵ��������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 80)
                return "�ţ�����ڹ����������ߣ��������������Ұɡ�";

        message_vision(HIY "$n" HIY "Ц��Ц�����ֽ�$N" HIY "�е���ǰ��������$N" HIY
                       "�����ֹ��˰�\n�졣Ȼ���ְγ�������ת���£�б�ö������ƺ���"
                       "һ����Ϊ\n���صĵ�����\n" NOR, me, this_object()); 
        command("nod");
        command("say ���кܼ򵥣��Լ���ϰ���С�");
        tell_object(me, HIC "��ѧ���ˡ���â������\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("shangjia-dao"))
                me->improve_skill("shangjia-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/shangjia-dao/juan", 1);
        me->add("gongxian", -80);

        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-dao/mang"))
                return "�Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("bagua-dao", 1) < 1)
                return "�������Ե�����ûѧ��̸ʲô���У�";

        if (me->query_skill("wai-bagua", 1) < 1)
                return "����������񹦶�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 1000)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -50000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

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

mixed ask_skill7()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-dao/sha"))
                return "�������Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("bagua-dao", 1) < 1)
                return "�������Ե�����ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 1800)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -80000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

        if (me->query_skill("bagua-dao", 1) < 180)
                return "��İ��Ե��������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 250)
                return "�ţ�����ڹ����������ߣ��������������Ұɡ�";

        message_vision(HIY "$n" HIY "������$N" HIY "���죬��̾һ����˵��������һ"
                       "�С�ɱ����\n�ڡ������Ҵ����Ը����˷����ã�����Ȼ��ĵ���"
                       "�Ѵ�˾�\n�磬�����Ҿʹ������С���˵�꣬�����ֽ�$N" HIY
                       "�������ԣ���\n����$P" HIY "����ϸ˵���á�\n" NOR, me,
                       this_object());
        command("sigh");
        command("say ��һ�еľ��Ͼ������޷��ˣ�����һ����");
        command("say Ҫ���Ҷ������ˣ��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�ɱ���޻ڡ���\n" NOR);

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
        me->set("can_perform/bagua-dao/sha", 1);
        me->add("gongxian", -1800);

        return 1;
}

mixed ask_dao()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_good())
        {
                if (me->query("family/family_name") == "�̼ұ�")
                        message_vision(CYN "$N" CYN "���һ������$n" CYN "����"
                                       "������Ϊ�ҵĵ��ӣ�����ѧ����ʼ�������"
                                       "����Ȼ����������Ҫ��������\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��Цһ������$n" CYN "˵��"
                                       "����ʲô��������Ȼ��������ǰ��������\n"
                                       NOR, this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "�̼ұ�")
                return "��������Ұ�֣���Ȼ�ҿ����ҵı�����";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ���������Ե��������ȥ������";

        if (me->query("shen") > -50000)
                return "�����������Ĵ�����֮�����⵶�㲻��Ҳ�ա�";

        if (me->query_skill("bagua-dao", 1) < 150)
                return "�������Ե�����ûѧ�ã����㱦������Ҳ�ǰ״";

        ob = find_object(BAGUADAO);
        if (! ob) ob = load_object(BAGUADAO);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ţ��ҵİ��Ե����ڲ���������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�����ҵİ��Ե����ڲ��������С�";

                if (owner->query("family/family_name") == "�̼ұ�")
                        return "�Ͻ���Ե����������ֵ�" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�ҵ��Ͻ���Ե���������" + owner->query("name") +
                               "���У���ȥ�����������ɣ�";
        }

        ob->move(this_object());

        ob = new("/clone/weapon/gangdao");
        ob->move(this_object());
        ob->wield();

        message_vision(CYN "$N" CYN "��Цһ����������������Ͻ���Ե�"
                       "�����ȥ���ڽ����϶������̼ұ������磡��\n" NOR,
                       this_object(), me);
        command("give bagua dao to " + me->query("id"));
        return 1;
}

mixed give_letter()
{
        object letter, me;


        me = this_player();

        if (me->query("can_perform/bagua-dao/tian"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";      

        if (me->query_skill("bagua-dao", 1) < 1)
                return "�������Ե�����ûѧ��̸ʲô���У�";

        if (me->query_skill("wai-bagua", 1) < 1)
                return "����������񹦶�ûѧ��̸ʲô���У�";

        if (me->query_skill("nei-bagua", 1) < 1)
                return "�����ڰ����񹦶�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 2200)
                return "�����ھ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("bagua-dao", 1) < 200)
                return "��İ��Ե��������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("wai-bagua", 1) < 200)
                return "���������񹦻����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("nei-bagua", 1) < 200)
                return "����ڰ����񹦻����ò����ң��Լ���ȥ���������ɣ�";

        if ((int)me->query("max_neili") < 3200)
                return "���������Ϊ���㣬ʩչ�������У��������������������������Ұɡ�";

        if (present("sjm letter", me))
                return "�쵽��Զ�ھ�����ʦ��ȥ�ɣ�";

        command("nod");
        command("say �ţ���������ѧ���滹�������裬���Ҷ��������̼ұ������˲��ٹ��ס�");
        command("haha");
        command("say �����Ҿ�����һ�⣬���͵���Զ�ھ�����ͷ��ά�ﴦ�����Իᴫ�������");

        "/clone/special/sjmletter"->move(me);
        write(HIC "��õ�һ�����ţ�\n" NOR);
        me->add("gongxian", -2200);
        return "��ȥ��Զ�ھ�����ʦ���ɣ�";
      
}

void unconcious()
{
        die();
}
