#include <ansi.h>
#include "lingjiu.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();
mixed ask_skill7();
mixed ask_skill8();

void create()
{
        set_name("������", ({ "xuzhu zi", "xuzhu", "xu", "zhu", "zi" }));
        set("long", @LONG
�������翷����չ����ţ����������ӡ�����
����ԼĪ��ʮ�����꣬����Ũü���ۣ�����
���ӱ�ƽ��������ò��Ϊ��ª����һ������
���µĳ��ۣ���ʹ�����Լ��־���
LONG );
        set("title", "��翷����չ�����");
        set("gender", "����");
        set("age", 26);
        set("nickname", HIM "����" NOR);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 35);
        set("int", 15);
        set("con", 35);
        set("dex", 35);

        set("qi", 6000);
        set("max_qi", 6000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 200);
        set("combat_exp", 3500000);

        set_skill("force", 320);
        set_skill("shaolin-xinfa", 100);
        set_skill("xiaowuxiang", 280);
        set_skill("beiming-shengong", 280);
        set_skill("bahuang-gong", 320);
        set_skill("lingjiu-xinfa", 240);
        set_skill("dodge", 260);
        set_skill("yueying-wubu", 260);
        set_skill("shaolin-shenfa", 100);
        set_skill("parry", 260);
        set_skill("hand", 260);
        set_skill("zhemei-shou", 260);
        set_skill("strike", 280);
	set_skill("piaomiao-zhang", 240);
        set_skill("liuyang-zhang", 280);
        set_skill("cuff", 100);
        set_skill("luohan-quan", 100);
        set_skill("unarmed", 220);
        set_skill("shaolin-quan", 100);
        set_skill("sword", 240);
        set_skill("tianyu-qijian", 240);
        set_skill("throwing", 240);
        set_skill("buddhism", 120);
        set_skill("literate", 100);
        set_skill("martial-cognize", 280);

        set("no_teach", ([
                "shaolin-xinfa"    : "���⡭�ⶫ���Ҷ�ûѧ�á�",
                "xiaowuxiang"      : "����������ʦ��ע�������ڵģ�������ô�̸��㣿",
                "beiming-shengong" : "����������ʦ��ע�������ڵģ�������ô�̸��㣿",
                "shaolin-shenfa"   : "��������š��һ��ǽ��㱾�ŵ��Ṧ���ˡ�",
        ]));

        map_skill("force", "bahuang-gong");
        map_skill("dodge", "yueying-wubu");
        map_skill("strike", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("cuff", "luohan-quan");
        map_skill("unarmed", "shaolin-quan");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianyu-qijian");
        map_skill("throwing", "liuyang-zhang");

        prepare_skill("hand", "zhemei-shou");
        prepare_skill("strike", "liuyang-zhang");        

        create_family("���չ�", 2, "����");

        set("inquiry", ([
                "������" : (: ask_skill1 :),
                "�ý���" : (: ask_skill2 :),
                "�۽���" : (: ask_skill3 :),
                "��÷ʽ" : (: ask_skill4 :),
                "��Ԩʽ" : (: ask_skill5 :),
                "������" : (: ask_skill6 :),
                "���ʽ" : (: ask_skill7 :),
                "�����" : (: ask_skill8 :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "hand.zhe" :),
		(: perform_action, "hand.hai" :),
		(: perform_action, "strike.huan" :),
		(: perform_action, "strike.zhong" :),
		(: perform_action, "strike.po" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
	}));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/lingjiu/obj/changpao")->wear();
        add_money("silver", 50);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 0)
        {
                command("say ��λʩ������������λ���������ƺ�а��̫�ء�");
                command("say ����������֮���������Ұɡ�");
                return;
        }

        if ((int)ob->query_skill("lingjiu-xinfa", 1) < 100) 
        {
                command("say ������������ķ���Ӧ�����Ǳ��������ڹ��Ļ�����");
                command("say ������š��㻹�ǻ�ȥ�����ɡ�");
                return;
        }

        if ((int)ob->query("max_neili") < 1200) 
        {
                command("say �����չ��������¶�һ�����书�ò���ȫ��������");
                command("say СɮȰ������������Ȱ�㻹���ٻ�ȥ�����ɡ�");
                return;
        }

        if ((int)ob->query("combat_exp") < 300000)
        {
                command("say ��������㾭�鲻�㣬����ȥ����һ����˵�ɡ�");
                return;
        }

        command("nod");
        command("say ����Сɮ�����¾������㣬�Ժ���Ҫ�������¡�");
        command("say ���⣬�Ժ��������������µĴ�ʦ����ǧ���ܺ�����Ϊ�ѡ�");
        command("recruit " + ob->query("id"));

        if ((string)ob->query("class") != "dancer")
                ob->set("class", "dancer");
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tianyu-qijian/shan"))
                return "�ҡ��Һ����Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���Ǹ���������������չ����˰ɣ�";

        if (me->query_skill("tianyu-qijian", 1) < 1)
                return "�㡭�����������������潣��ûѧ�ɣ���ѧ�������У�";

        if (me->query("gongxian") < 100)
                return "����������ȻͶ�����������չ����£����ǡ�������ٰ��������°ɡ�";

        if (me->query_skill("force") < 100)
                return "���š�����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("tianyu-qijian", 1) < 60)
                return "���š���������潣�������ö��¹���������";

        message_vision(HIY "$n" HIY "���˵�ͷ���ӻ�������ȡ����һ��"
                       "���ף�ָ�����е�һ�ζ�\n$N" HIY "��ڲ��ɵ�"
                       "ϸ˵���ã�$N" HIY "һ����һ�ߵ�ͷ��\n" NOR,
                       me, this_object());

        command("nod");
        command("say ���еı仯�ܷ�������Ҫ�����ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("tianyu-qijian"))
                me->improve_skill("tianyu-qijian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tianyu-qijian/shan", 1);
        me->add("gongxian", -100);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tianyu-qijian/huan"))
                return "�ҡ��Һ����Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���Ǹ���������������չ����˰ɣ�";

        if (me->query_skill("tianyu-qijian", 1) < 1)
                return "�㡭�����������������潣��ûѧ�ɣ���ѧ�������У�";

        if (me->query("gongxian") < 300)
                return "����������ȻͶ�����������չ����£����ǡ�������ٰ��������°ɡ�";

        if (me->query_skill("force") < 160)
                return "���š�����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("tianyu-qijian", 1) < 120)
                return "���š���������潣�������ö��¹���������";

        message_vision(HIY "$n" HIY "Ц��Ц��������$N" HIY "���нӹ�"
                       "��������������ʾ���У�$N" HIY "����\nʽ������"
                       "������ӯ�鶯��ʵ��ǰ��ν�ţ���ʱ��������\n"
                       NOR, me, this_object());

        command("nod");
        command("say  ���š����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��ý�������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("tianyu-qijian"))
                me->improve_skill("tianyu-qijian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tianyu-qijian/huan", 1);
        me->add("gongxian", -300);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tianyu-qijian/ju"))
                return "�㡭������������㲻���Ѿ�ѧ������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���Ǹ���������������չ����˰ɣ�";

        if (me->query_skill("tianyu-qijian", 1) < 1)
                return "�㡭�����������������潣��ûѧ�ɣ���ѧ�������У�";

        if (me->query("gongxian") < 400)
                return "����������ȻͶ�����������չ����£����ǡ�������ٰ��������°ɡ�";

        if (me->query_skill("force") < 180)
                return "���š�����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("tianyu-qijian", 1) < 130)
                return "���š���������潣�������ö��¹���������";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "���нӹ�"
                       "��������������һ���������㻯��\nһ���ʺ磬"
                       "���⽣����Ϊһ�ߣ��⻪ѣĿ��������$N" HIY
                       "���ܡ�\n" NOR, me, this_object());

        command("nod");
        command("say �ܽ����Ҷ����������ˣ��������ʣ�µľͿ����Լ��ˡ�");
        tell_object(me, HIC "��ѧ���ˡ��۽�������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("tianyu-qijian"))
                me->improve_skill("tianyu-qijian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tianyu-qijian/ju", 1);
        me->add("gongxian", -400);
        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhemei-shou/zhe"))
                return "�㡭����������Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���Ǹ���������������չ����˰ɣ�";

        if (me->query_skill("zhemei-shou", 1) < 1)
                return "�㡭��������������ң��÷�ֶ�ûѧ�ɣ���ѧ�������У�";

        if (me->query("gongxian") < 300)
                return "����������ȻͶ�����������չ����£����ǡ�������ٰ��������°ɡ�";

        if (me->query_skill("force") < 120)
                return "���š�����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("zhemei-shou", 1) < 80)
                return "���š������ң��÷�ֻ������ö��¹���������";

        message_vision(HIY "$n" HIY "���˿�$N" HIY "��΢΢һЦ������"
                       "һ����Х������ң��÷������\n��Ϊһʽ������"
                       "����ӳ�����������ʵʵ��ɷ�Ǿ��ֱ����$N"
                       HIY "��\n�����ң�Ŀ�ɿڴ���\n" NOR, me,
                       this_object());

        command("nod");
        command("say ��ʽ�㶼�����ˣ��⡭ʣ�µľͿ����Լ��ˡ�");
        tell_object(me, HIC "��ѧ���ˡ���÷ʽ����\n" NOR);

        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("zhemei-shou"))
                me->improve_skill("zhemei-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhemei-shou/zhe", 1);
        me->add("gongxian", -300);
        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhemei-shou/hai"))
                return "�㡭����������Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���Ǹ���������������չ����˰ɣ�";

        if (me->query_skill("zhemei-shou", 1) < 1)
                return "�㡭��������������ң��÷�ֶ�ûѧ�ɣ���ѧ�������У�";

        if (me->query("gongxian") < 800)
                return "����������ȻͶ�����������չ����£����ǡ�������ٰ��������°ɡ�";

        if (me->query_skill("force") < 200)
                return "���š�����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("zhemei-shou", 1) < 130)
                return "���š������ң��÷�ֻ������ö��¹���������";

        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ������Ҳ����"
                       "������������һ�Ӷ������ֳ���\n�磬���ƶ�ʱ��"
                       "����������Ӱ������ʵʵ�����ص��������Ǽ�����"
                       "\nס$N" HIY "����Ѩ����$n" HIY "����Ӱȴֻ��"
                       "һմ������δ��$N" HIY "���������\n֮�����"
                       "��ֻ���á��޿ɱ��⡱�������ݡ�\n" NOR, me,
                       this_object());

        command("nod2");
        command("say ���б��纣֮��嫣�Ԩ֮�������Ҫ�ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ���Ԩʽ����\n" NOR);

        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("zhemei-shou"))
                me->improve_skill("zhemei-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhemei-shou/hai", 1);
        me->add("gongxian", -800);
        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();

        if (me->query("can_perform/liuyang-zhang/zhong"))
                return "�㡭����������Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���Ǹ���������������չ����˰ɣ�";

        if (me->query_skill("liuyang-zhang", 1) < 1)
                return "�㡭��������������ɽ�����ƶ�ûѧ�ɣ���ѧ�������У�";

        if (me->query("gongxian") < 600)
                return "����������ȻͶ�����������չ����£����ǡ�������ٰ��������°ɡ�";

        if (me->query_skill("force") < 200)
                return "���š�����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("liuyang-zhang", 1) < 150)
                return "���š������ɽ�����ƻ������ö��¹���������";

        message_vision(HIY "$n" HIY "���˿�$N" HIY "��΢�����ɣ�����"
                       "�ŵ��˵�ͷ����$N" HIY "������ߣ���\n���Ե���"
                       "ϸ˵���ã�$N" HIY "������ĵ�һЦ������������"
                       "��\n" NOR, me, this_object());

        command("buddhi");
        command("say �⡭���������ý���ƽʱ�ɲ��ܺ���ʹ�á�");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("liuyang-zhang"))
                me->improve_skill("liuyang-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/liuyang-zhang/zhong", 1);
        me->add("gongxian", -600);
        return 1;
}

mixed ask_skill7()
{
        object me;

        me = this_player();

        if (me->query("can_perform/liuyang-zhang/huan"))
                return "�㡭����������Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���Ǹ���������������չ����˰ɣ�";

        if (me->query_skill("liuyang-zhang", 1) < 1)
                return "�㡭��������������ɽ�����ƶ�ûѧ�ɣ���ѧ�������У�";

        if (me->query("gongxian") < 1000)
                return "����������ȻͶ�����������չ����£����ǡ�������ٰ��������°ɡ�";

        if (me->query_skill("force") < 200)
                return "���š�����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("liuyang-zhang", 1) < 130)
                return "���š������ɽ�����ƻ������ö��¹���������";

        message_vision(HIY "$n" HIY "΢΢һЦ�����������һ�ƣ�����"
                       "��$N" HIY "�����֮�ϣ�$N" HIY "����\n���죬"
                       "��ʱֻ��$n" HIY "����ԴԴ��������ӿ���룬��"
                       "������ע����\n�ڣ�ȫ���ƿ�Ҫը�ѿ���������"
                       "����ʧɫ��\n" NOR, me, this_object()); 

        command("say �㶮����");
        tell_object(me, HIC "��ѧ���ˡ����ʽ����\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("liuyang-zhang"))
                me->improve_skill("liuyang-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/liuyang-zhang/huan", 1);
        me->add("gongxian", -1000);
        return 1;
}

mixed ask_skill8()
{
        object me;

        me = this_player();

        if (me->query("can_perform/liuyang-zhang/po"))
                return "�㡭���Լ���ȥ��ϰ�ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���Ǹ���������������չ����˰ɣ�";

        if (me->query_skill("liuyang-zhang", 1) < 1)
                return "�㡭��������������ɽ�����ƶ�ûѧ�ɣ���ѧ�������У�";

        if (me->query("gongxian") < 2200)
                return "����������ȻͶ�����������չ����£����ǡ�������ٰ��������°ɡ�";

        if ((int)me->query_skill("bahuang-gong", 1) < 220)
                return "���š���İ˻�����Ψ�Ҷ��𹦻���㣬ѧ�������С�";

        if (me->query_skill("liuyang-zhang", 1) < 220)
                return "���š������ɽ�����ƻ������ö��¹���������";

        if (me->query("max_neili") < 3500)
                return "���������Ϊ�������������С��š����Ƚ����ѡ�";

        message_vision(HIY "$n" HIY "��$N" HIY "΢΢һЦ��ģ����Ϊ��"
                       "��˵�������������������ʾ\nһ�飬�ܷ�����"
                       "��ȫ����������ˡ����������䣬ֻ��$n" HIY "��"
                       "��\n�ھ������μ�ת�����������ŷ���������֮��"
                       "�͡���Ȼ֮�䣬����\nһ����Ȼ���䣬��ʱ������"
                       "�𣬳�ɳ�������������ã�����������\nɢ��$N"
                       HIY "����ʱ�ŷ���$n" HIY "��ǰ��ʯש���ѱ�����"
                       "����һ��������\n�ɣ���Լ�߳ߵ��ѷ죬�Ʒ�֮��"
                       "�棬���澪��أ�������\n" NOR, me,
                       this_object());

        command("buddhi");
        command("say ���������Ҵ�ʯ����ϰ�ã������ͯ����ǰ������");
        command("say �����������е�����̫��ǿʢ����ĩ����ʹ�á�");
        tell_object(me, HIC "��ѧ���ˡ����������\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("liuyang-zhang"))
                me->improve_skill("liuyang-zhang", 1500000);
        if (me->can_improve_skill("liuyang-zhang"))
                me->improve_skill("liuyang-zhang", 1500000);
        if (me->can_improve_skill("liuyang-zhang"))
                me->improve_skill("liuyang-zhang", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("bahuang-gong"))
                me->improve_skill("bahuang-gong", 1500000);
        if (me->can_improve_skill("bahuang-gong"))
                me->improve_skill("bahuang-gong", 1500000);
        if (me->can_improve_skill("bahuang-gong"))
                me->improve_skill("bahuang-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/liuyang-zhang/po", 1);
        me->add("gongxian", -2200);
        return 1;
}

void unconcious()
{
        die();
}
