#include <ansi.h>
#include "shang.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();

mixed  try_to_learn_waibagua();

void create()
{
        set_name("����̫", ({"shang laotai", "shang", "laotai"}));
        set("gender", "Ů��");
        set("title", "�̼ұ���������");
        set("age", 41);
        set("long", @LONG
����һλ��ĸߴ�ĸ��ˣ��������࣬������
���������ǡ����Ե����̽����ķ��ˣ�����Ů
ʱ������ɷ����ϴ���������ΪŮ�к��ܡ�
LONG);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 45);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 3600);
        set("max_qi", 3600);
        set("jing", 2800);
        set("max_jing", 2800);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 160);
        set("combat_exp", 2500000);
        set("score", 10000);

        set_skill("force", 160);
        set_skill("shangjia-neigong", 160);
        set_skill("parry", 160);
        set_skill("wai-bagua", 160);
        set_skill("dodge", 160);
        set_skill("bagua-bu", 160);
        set_skill("unarmed", 140);
        set_skill("tan-tui", 140);
        set_skill("strike", 160);
        set_skill("bagua-zhang", 160);
        set_skill("cuff", 160);
        set_skill("bagua-quan", 160);
        set_skill("sword", 140);
        set_skill("quemen-jian", 140);
        set_skill("blade", 180);
        set_skill("bagua-dao", 180);
        set_skill("shangjia-dao", 160);
        set_skill("throwing", 160);
        set_skill("jinbiao-jue", 160);
        set_skill("literate", 200);
        set_skill("martial-cognize", 160);

        map_skill("unarmed", "tan-tui");
        map_skill("dodge", "bagua-bu");
        map_skill("force", "shangjia-neigong");
        map_skill("strike", "bagua-zhang");
        map_skill("sword", "quemen-jian");
        map_skill("blade", "bagua-dao");
        map_skill("cuff", "bagua-quan");
        map_skill("parry", "wai-bagua");
        map_skill("throwing", "jinbiao-jue");

        prepare_skill("cuff", "bagua-quan");
        prepare_skill("strike", "bagua-zhang");

        set("no_teach", ([
                "bagua-dao" : "���Ե������ҷ�����Դ��ڡ�",
                "wai-bagua" : (: try_to_learn_waibagua :),
        ]));

        set("class", "fighter");

        create_family("�̼ұ�", 3, "��������");

        set("inquiry", ([
                "����ȭ"     : (: ask_skill1 :),
                "���Ķ�"     : (: ask_skill2 :),
                "Ϭţ����"   : (: ask_skill3 :),
                "��н���"   : (: ask_skill4 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.mang" :),
                (: perform_action, "strike.ding" :),
                (: perform_action, "cuff.gua" :),
                (: perform_action, "parry.zhen" :),
                (: perform_action, "throwing.huan" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        set_temp("handing", carry_object("/d/beijing/npc/obj/jinbiao"));
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->name(1) == "�̽���")
        {
                command("say ��ȡ���ɷ������������");
                return;
        }

        if (ob->name(1) == "����̫")
        {
                command("say ��ȡ���������ʲô��˼��");
                return;
        }

        if (ob->name(1) == "�̱���")
        {
                command("say ���������һ��������ֲ��У�");
                return;
        }

        if (ob->query("family/master_name") == "�̽���")
        {
                command("say ��Ȼ���Ѿ������ҷ��ѧ�գ���ӦŬ���Ͻ��������������ң�");
                return;
        }

        command("say �����ұ���������Ϊͽ�������պ������̼ұ�������Ϊ��");
        command("recruit " + ob->query("id"));

        if ((string)ob->query("class") != "fighter")
                ob->set("class", "fighter");
        return;
}

mixed try_to_learn_waibagua()
{
        object ob = this_player();

        if (ob->query("can_learn/shanglaotai/wai-bagua"))
                return 0;

        if (ob->query("combat_exp") > 100000)
        {
                command("say �������书������һ������Ҿ���������������񹦡�");
                ob->set("can_learn/shanglaotai/wai-bagua", 1);
                return 0;
        }

        return "���ʱ����̫ǳ��������ѧһЩ���Ź���ɡ�";
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/bagua-quan/gua"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("bagua-quan", 1) < 1)
                return "��������ȭ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 100)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -10000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

        if (me->query_skill("force") < 100)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("bagua-quan", 1) < 70)
                return "��İ���ȭ�������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ��˵�������Ҹ�����ʾһ��"
                       "����Ҫ����\n���ˡ���$n" HIY "�������䣬ͻȻ����һ�࣬˫��"
                       "��ʱ���³�\nȥ������ȴ������һ��������$N" HIY "��˫��бб"
                       "����ȥ��������\nΪ�����ʱ��$N" HIY "���˸����ֲ�����\n"
                       NOR, me, this_object());

        command("heng");
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
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("bagua-zhang", 1) < 1)
                return "���������Ʒ���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -20000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

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

        if (me->query("can_perform/tan-tui/wang"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("tan-tui", 1) < 1)
                return "����ʮ��·̶�ȶ�ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 350)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -25000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

        if (me->query_skill("force") < 150)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("tan-tui", 1) < 120)
                return "���ʮ��·̶�Ȼ����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "����һ��������������̶�ȱ�����������ǿ����ȴ��"
                       "\n��Ϊ�����Ĵ��֮һ����Ҳ�����Ķ���֮������˵����漴\n����"
                       "�����������������з�λ�����顱��һ����Ȼ�߳�����\nʱ��$N" HIY
                       "��ǰ������ľ���ߵ÷��顣\n" NOR, me, this_object());

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ�Ϭţ����ת�ػ�����\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("tan-tui"))
                me->improve_skill("tan-tui", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tan-tui/wang", 1);
        me->add("gongxian", -350);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/quemen-jian/can"))
                return "�Լ���ȥ��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�����̼ұ������������γ����ԣ�";

        if (me->query_skill("quemen-jian", 1) < 1)
                return "����ȱ�Ž�����ûѧ��̸ʲô���У�";

        if (me->query("gongxian") < 60)
                return "�������̼ұ���µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("shen") > -5000)
                return "�ߣ����������Ĵ�����֮ͽ������ѧ���������к��ã�";

        if (me->query_skill("force") < 120)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("quemen-jian", 1) < 80)
                return "���ȱ�Ž��������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��Цһ����Ҳ���𻰣�������$N" HIY "���нӹ���"
                       "��������\n����ʾ���У�$N" HIY "����ʽ��ӯ�鶯������޷�����"
                       "Ϊ���졣ʵ\n��ǰ��ν�ţ���ʱ��������\n" NOR, me,
                       this_object());

        command("say ��������������ʤ������ʾ����ɶ������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ���н�������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("quemen-jian"))
                me->improve_skill("quemen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/quemen-jian/can", 1);
        me->add("gongxian", -60);

        return 1;
}
