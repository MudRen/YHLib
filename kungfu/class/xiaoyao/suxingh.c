#include <ansi.h>
#include "xiaoyao.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_QUESTER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();

void create()
{
        set_name("���Ǻ�", ({"su xinghe", "su", "xinghe"}));
        set("gender", "����" );
        set("nickname", HIW "�ϱ�����" NOR);
        set("long", @LONG
���˾��Ǻųƴϱ����˵����Ǻӣ���˵������
�Ʊ磬����������Ϊ�����һλ���ߣ�������
�书Ҳ��������֪��
LONG );
        set("class", "scholar");
        set("age", 60);
        set("str", 29);
        set("con", 30);
        set("int", 45);
        set("dex", 37);
        set("combat_exp", 2000000);
        set("attitude", "peaceful");

        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 120);

        set_skill("force", 260);
        set_skill("xiaoyao-xinfa", 240);
        set_skill("xiaowuxiang", 260);
        set_skill("dodge", 240);
        set_skill("feiyan-zoubi", 240);
        set_skill("strike", 240);
        set_skill("panyang-zhang", 240);
        set_skill("liuyang-zhang", 240);
        set_skill("hand", 240);
        set_skill("qingyun-shou", 240);
        set_skill("zhemei-shou", 240);
        set_skill("parry", 240);
        set_skill("blade", 240);
        set_skill("ruyi-dao", 240);
        set_skill("literate", 280);
        set_skill("medical", 260);
        set_skill("xiaoyao-qixue", 260);
        set_skill("mathematics", 240);
        set_skill("qimen-wuxing", 240);
        set_skill("drawing",   240);
        set_skill("chuixiao-jifa", 240);
        set_skill("tanqin-jifa", 240);
        set_skill("chess", 280);
        set_skill("calligraphy", 240);
        set_skill("martial-cognize", 240);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("hand", "zhemei-shou");
        map_skill("strike", "liuyang-zhang");
        map_skill("parry", "zhemei-jian");
        map_skill("blade", "ruyi-dao");
        map_skill("medical", "xiaoyao-qixue");

        prepare_skill("hand", "zhemei-shou");
        prepare_skill("strike", "liuyang-zhang");

        set("no_teach", ([
                "zhemei-shou"   : "��ң��÷���˱����񹦣�ֻ���������˴��ڡ�",
                "liuyang-zhang" : "����ɽ����������ֻ������ң�����Ŵ������Ҳ�����ڡ�",
        ]));

        create_family("��ң��", 2, "���ŵ���");

        set("inquiry", ([
                "����׽Ӱ" : (: ask_skill1 :),
                "��������" : (: ask_skill2 :),
                "��������" : (: ask_skill3 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.zhe" :),
                (: perform_action, "hand.hai" :),
                (: perform_action, "strike.huan" :),
                (: perform_action, "strike.zhong" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
        }));

        set("coagents", ({
                ([ "startroom" : "/d/xiaoyao/shishi",
                   "id"        : "wuya zi" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "�������������˴��˱��Ž��أ�����"
                                "�������ڡ�" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "��������ʲô�ˣ����������ҷ���"
                                "��" NOR,
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}


void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 30)
        {
                command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ����ѧ"
                        "���϶��µ㹦�򣬱��˿���ң���ˣ�");
                return;
        }

	if ((int)ob->query("combat_exp") < 200000)
	{
		command("say �����ھ�����ǳ��������������书���ȶ���Ҫ����");
		return;
	}

        if (ob->query_skill("force", 1) < 100)
        {
                command("sigh");
                command("say ������ң�ɵ��书��Ҫ���ڹ�Ϊ���������Ȱ�"
                        "�����ڹ�ѧ��ʵ�ɡ�");
                return;
        }

        if (ob->query_skill("xiaoyao-xinfa", 1) < 100)
        {
                command("sigh");
                command("say �������ŵ������ķ���û��ѧ�ã�����ѧ����"
                        "���ϳ���ѧ��");
                return;
        }

        command("say �ðɣ��Ҿ��������ˣ����Ҫ���Ŭ������");
        command("recruit " + ob->query("id"));
}

int permit_pass(object me, string dir)
{
        if (! ::permit_pass(me, dir))
                return 0;

        if (me->query("family/master_id") == "wuya zi")
                return 1;

        if (me->query("combat_exp") < 300000)
        {
                command("say ���������ֲ�Ҫȥ����ú�ѧ������ң���书��");
                return 0;
        }

        if (me->query_skill("xiaoyao-xinfa", 1) < 120)
        {
                command("say ��������ң�ķ���ѧ���ã�����ʲô��");
                return 0;
        }

        command("sigh");
        command("say ȥ�ɣ�ȥ�ɣ���Ե���¾��ɡ�");
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/qingyun-shou/zhuo"))
                return "�Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("qingyun-shou", 1) < 1)
                return "���������ֶ�δ��ѧ�����������У�";

        if (me->query("gongxian") < 50)
                return "����������ң���£�ȴ������Ϊ���������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("qingyun-shou", 1) < 50)
                return "��������ֻ��δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "���˵�ͷ�����ֽ�$N" HIY "����"
                       "��ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY "��"
                       "���\n�ĵ�һЦ��������������\n" NOR, me,
                       this_object());

        command("nod");
        command("say �����ˣ�");
        tell_object(me, HIC "��ѧ���ˡ�����׽Ӱ����\n" NOR);

        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("qingyun-shou"))
                me->improve_skill("qingyun-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qingyun-shou/zhuo", 1);
        me->add("gongxian", -50);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/panyang-zhang/pan"))
                return "�Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("panyang-zhang", 1) < 1)
                return "���������ƶ�δ��ѧ�����������У�";

        if (me->query("gongxian") < 100)
                return "����������ң���£�ȴ������Ϊ���������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("panyang-zhang", 1) < 60)
                return "��������ƻ��δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��΢���˵�ͷ��˵�������Ҹ�����ʾ"
                      "һ�飬������ϸ�ˣ����漴\nһ����Х��˫�Ʒ׷ɹ�"
                      "������Ӱ���ص�����ʵ�ѱ棬ȫȫ����$N" HIY "ȫ��"
                      "��\n" NOR, me, this_object());

        command("nod");
        command("say ������˾��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��������¡���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("panyang-zhang"))
                me->improve_skill("panyang-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/panyang-zhang/pan", 1);
        me->add("gongxian", -100);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/ruyi-dao/ruyi"))
                return "�Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("ruyi-dao", 1) < 1)
                return "�������⵶����δ��ѧ�����������У�";

        if (me->query("gongxian") < 200)
                return "����������ң���£�ȴ������Ϊ���������Ȳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("ruyi-dao", 1) < 100)
                return "������⵶�����δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "���ͷ��΢Ц��ʾ���������ֽ�$N"
                       HIY "�е���ǰ��������$N" HIY "������\n���˰���"
                       "����ʱ���γ��������輸�£��ƺ���һ����Ϊ�����"
                       "������\n" NOR, me, this_object());

        command("smile");
        command("say ���кܼ򵥣�ֻ���Լ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("ruyi-dao"))
                me->improve_skill("ruyi-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/ruyi-dao/ruyi", 1);
        me->add("gongxian", -200);
        return 1;
}

void unconcious()
{
        die();
}
