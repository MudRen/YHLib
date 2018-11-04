#include <ansi.h>
#include "miao.h"

#define TENGLONG  "/clone/lonely/tenglongjian"
#define JIANPUA   "/clone/lonely/book/miaojia1"
#define JIANPUB   "/clone/lonely/book/miaojia2"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_jian();
mixed ask_jianpu1();
mixed ask_jianpu2();

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

mixed  try_to_learn_miaojiajian();
mixed  try_to_learn_tianlongjian();
mixed  try_to_learn_chongtianzhang();

void create()
{
        object ob;
        set_name("���˷�", ({ "miao renfeng", "miao", "renfeng" }));
        set("gender", "����");
        set("nickname", YEL "�����" NOR);
        set("title", "��������޵���");
        set("age", 48);
        set("long", @LONG
�����Ǻųƴ�������޵��ֵġ����������
�ֻ������ɫ͸�ƣ��ƺ�������һ�㵭����
��ֽ������ĸߴ���࣬��֫�޳���ȴ��ȫȻ
����ƪ�������˳��档
LONG );
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 32);
        set("int", 31);
        set("con", 33);
        set("dex", 31);

        set("qi", 5500);
        set("max_qi", 5500);
        set("jing", 4000);
        set("max_jing", 4000);
        set("neili", 6800);
        set("max_neili", 6800);
        set("jiali", 200);
        set("combat_exp", 4500000);
        set("score", 20000);

        set_skill("force", 260);
        set_skill("miaojia-neigong", 260);
        set_skill("dodge", 240);
        set_skill("chaoyang-fengwu", 240);
        set_skill("sword", 260);
        set_skill("suqin-beijian", 260);
        set_skill("baxian-jian", 260);
        set_skill("tianlong-jian", 260);
        set_skill("miaojia-jian", 260);
        set_skill("blade", 240);
        set_skill("hujia-daofa", 240);
        set_skill("strike", 260);
        set_skill("miaojia-zhang", 260);
        set_skill("chongtian-zhang", 260);
        set_skill("claw", 260);
        set_skill("panlong-zhao", 260);
        set_skill("da-qinna", 240);
        set_skill("xiao-qinna", 240);
        set_skill("unarmed", 240);
        set_skill("pobei-tui", 240);
        set_skill("parry", 260);
        set_skill("literate", 240);
        set_skill("martial-cognize", 260);

        map_skill("force", "miaojia-neigong");
        map_skill("dodge", "chaoyang-fengwu");
        map_skill("sword", "miaojia-jian");
        map_skill("blade", "hujia-daofa");
        map_skill("parry", "tianlong-jian");
        map_skill("strike", "chongtian-zhang");
        map_skill("claw", "panlong-zhao");
        map_skill("unarmed", "pobei-tui");

        prepare_skill("claw", "panlong-zhao");
        prepare_skill("strike", "chongtian-zhang");

        set("no_teach", ([
                "miaojia-jian"    : (: try_to_learn_miaojiajian :),
                "tianlong-jian"   : (: try_to_learn_tianlongjian :),
                "chongtian-zhang" : (: try_to_learn_chongtianzhang :),
                "hujia-daofa"     : "���ҵ��������ҵ���Ӻ����ִ�ϰ�ã������⴫��",
        ]));

        create_family("��ԭ���", 6, "����");

        set("inquiry", ([
                "������"   : (: ask_jian :),
                "�����ϲ�" : (: ask_jianpu1 :),
                "�ϲ�"     : (: ask_jianpu1 :),
                "�����²�" : (: ask_jianpu2 :),
                "�²�"     : (: ask_jianpu2 :),
                "������"   : (: ask_skill1 :),
                "����Ϊ��" : (: ask_skill2 :),
                "��չ����" : (: ask_skill3 :),
                "������"   : (: ask_skill4 :),
                "���ǵ�Ԫ" : (: ask_skill5 :),
                "����˫׶" : (: ask_skill6 :),
                "�Ʊ�ժ��" : (: ask_skill7 :),
                "��������" : (: ask_skill8 :),
                "����ǧ��" : (: ask_skill9 :),
                "���Ǹ���" : (: ask_skill10 :),
                "����̽צ" : "����̫���ݶ��������Ѳ��ã���������Ȥ�ɵ����鷿���з������",
                "��ҽ���" : "�����ʽ����ϲỹ�ǽ����²᣿",
                "���ҵ���" : "���ҵ��������ҵ���Ӻ����ִ�ϰ�ã����澫���ޱȡ�",
                "��һ��"   : "���������˼��˶���ɱ�������������ź�������",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
	        (: perform_action, "sword.zhai" :),
	        (: perform_action, "sword.zhu" :),
	        (: perform_action, "sword.jian" :),
	        (: perform_action, "sword.gan" :),
	        (: perform_action, "strike.zhan" :),
	        (: perform_action, "claw.tan" :),
	        (: exert_function, "recover" :),
	        (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        if (clonep())
        {
                ob = find_object(TENGLONG);
                if (! ob) ob = load_object(TENGLONG);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("clone/weapon/changjian");
                        ob->move(this_object());
                        ob->wield();
                }
        }

        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->name(1) == "���˷�")
        {
                command("hmm");
                command("say ����ôҲȡ������֣�");
                return;
        }

        if (ob->name(1) == "������")
        {
                command("hmm");
                command("say ��Ͳ��ܻ���������֣�");
                return;
        }

        if (ob->name(1) == "����" || ob->name(1) == "������")
        {
                command("hmm");
                command("say �㰲��Ҫ���������ǲ��ǣ�");
                return;
        }

        command("sigh");
        command("recruit " + ob->query("id"));
        command("say �ұ��Ѵ��㲻��ͽ�ܣ��������������硢�����ҵķ�������ƽϢ��");
        command("say �������洫��ʮ������ҽ������Ҵ�ʧ����δ��̫����Т��");
        return;
}

mixed try_to_learn_miaojiajian()
{
        object ob = this_player();

        if (ob->query("can_learn/miao/miaojia-jian"))
                return 0;

        if (ob->query("combat_exp") > 400000)
        {
                command("say ��Ȼ�������ܴ�˵ز����Ҿʹ�����ҽ�����");
                ob->set("can_learn/miao/miaojia-jian", 1);
                return 0;
        }

        return "���ʱ����̫ǳ���һ����ȴ�����Щ�򵥵Ľ�����";
}

mixed try_to_learn_tianlongjian()
{
        object ob = this_player();

        if (ob->query("can_learn/miao/tianlong-jian"))
                return 0;

        if (ob->query("combat_exp") > 120000)
        {
                command("say ������������Ϊʦ�ʹ�������������");
                ob->set("can_learn/miao/tianlong-jian", 1);
                return 0;
        }

        return "��������������˵������£������ȴ�û�����˵�ɡ�";
}

mixed try_to_learn_chongtianzhang()
{
        object ob = this_player();

        if (ob->query("can_learn/miao/chongtian-zhang"))
                return 0;

        if (ob->query("combat_exp") > 100000)
        {
                command("say �������书�Ѿ�����һ���Ļ����������Ҿʹ���׺׳����ơ�");
                ob->set("can_learn/miao/chongtian-zhang", 1);
                return 0;
        }

        return "���װ׺׳����ƹ��ڷ��ӣ��һ����Ƚ���Щ�򵥵��书�ɡ�";
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/miaojia-zhang/dan"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("miaojia-zhang", 1) < 1)
                return "��������Ʒ���δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 2000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 50)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 200)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("miaojia-zhang", 1) < 40)
                return "�������Ʒ����δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "΢΢���˵�ͷ�����ֽ�$N" HIY "������"
                       "�ߣ��ڶ��Ե���ϸ\n˵���ã�$N" HIY "������ĵ�һЦ"
                       "��������������\n" NOR, me, this_object());

        command("nod");
        command("say �ղ���˵�Ķ����μ����ġ�");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("miaojia-zhang"))
                me->improve_skill("miaojia-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/miaojia-zhang/dan", 1);
        me->add("gongxian", -50);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/pobei-tui/kai"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("pobei-tui", 1) < 1)
                return "�����Ʊ��ȶ�δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 8000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1000)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("pobei-tui", 1) < 100)
                return "����Ʊ��Ȼ��δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "����һ������������������Ϊ����Ҳ"
                       "�����ã�ֻ��\n�汲�ǹ���̧�������������ˡ�����"
                       "�����������������\n�����з�λ�����顱��һ����"
                       "Ȼ�߳�����ʱ��$N" HIY "��ǰ����\n��ľ���ߵ÷�"
                       "�顣\n" NOR, me, this_object());

        command("heng");
        command("say �������˶��ѣ���������Ϊ��ʵ����̫��������");
        command("say ���Լ���ȥ��ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����Ϊ������\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("pobei-tui"))
                me->improve_skill("pobei-tui", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pobei-tui/kai", 1);
        me->add("gongxian", -200);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/chongtian-zhang/zhan"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("chongtian-zhang", 1) < 1)
                return "�����׺׳����ƶ�δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 350)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 12000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1500)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("chongtian-zhang", 1) < 120)
                return "��İ׺׳����ƻ��δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "���˵�ͷ���漴�������ƣ�˫�����ţ���"
                       "Ե΢΢��\n��������һչ��������$N" HIY "��ǰ��˫��"
                       "����������£�����\n�׺׳����ơ���չ���ݡ���������"
                       "���ж�ʱ�����һ���\n����ƿ�����\n" NOR, me,
                       this_object());

        command("nod");
        command("say �������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ���չ���ݡ���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("chongtian-zhang"))
                me->improve_skill("chongtian-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/chongtian-zhang/zhan", 1);
        me->add("gongxian", -350);
        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/suqin-beijian/can"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("suqin-beijian", 1) < 1)
                return "�������ر�����δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 3000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 80)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1000)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("suqin-beijian", 1) < 60)
                return "������ر������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "���˵�ͷ���ӻ�������ȡ����һ����"
                       "�ף�ָ������\n��һ�ζ�$N" HIY "�����˰��죬$N"
                       HIY "һ����һ�ߵ�ͷ��\n" NOR, me, this_object());

        command("nod");
        command("say ���Լ���ȥ��ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("suqin-beijian"))
                me->improve_skill("suqin-beijian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/suqin-beijian/can", 1);
        me->add("gongxian", -50);
        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/baxian-jian/dian"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("baxian-jian", 1) < 1)
                return "�������ɽ�����δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 10000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1000)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("baxian-jian", 1) < 100)
                return "��İ��ɽ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "̾�˿�����ת�����һָ����$N" HIY
                       "�ؿ�֮�ϣ�$N" HIY "��ʱ\nȫ��һ�飬��������"
                       "ֻ������ԴԴ��к�����Ʋ����Լ�\n����һ�㣬����"
                       "��ʧɫ��\n" NOR, me, this_object());

        command("nod");
        command("say �㶮��ô��");
        tell_object(me, HIC "��ѧ���ˡ����ǵ�Ԫ����\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("baxian-jian"))
                me->improve_skill("baxian-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/baxian-jian/dian", 1);
        me->add("gongxian", -300);
        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tianlong-jian/zhui"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("tianlong-jian", 1) < 1)
                return "��������������δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 15000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1500)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("tianlong-jian", 1) < 120)
                return "��������������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ��˵����������"
                       "ϸ�ˣ���˵�������\n$n" HIY "һ����Х���γ�����"
                       "�佣������ת��������׶����\n���ʱ����һ������"
                       "��Ѹ�װ㹥��һ�����漴$n" HIY "�齣\n��ת������"
                       "���ϣ�����һ������ʱ������һ������������\n�꾢"
                       "���ֹ����˵ڶ�����\n" NOR, me, this_object());

        command("nod");
        command("say ����̫���ݶ���ƽʱ��������ʹ�á�");
        tell_object(me, HIC "��ѧ���ˡ�����˫׶����\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("tianlong-jian"))
                me->improve_skill("tianlong-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tianlong-jian/zhui", 1);
        me->add("gongxian", -800);
        return 1;
}

mixed ask_skill7()
{
        object me;

        me = this_player();

        if (me->query("can_perform/miaojia-jian/zhai"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("miaojia-jian", 1) < 1)
                return "������ҽ�����δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 13000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 120)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 800)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("miaojia-jian", 1) < 100)
                return "�����ҽ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ�����ִ�����"
                       "����һ�����ӣ�������\n��ʾ���С�$N" HIY "ֻ��"
                       "$n" HIY "�������ţ����²�����˲ʱ֮��\n������"
                       "���ֽ��ƣ�����֮�������ǰ��δ�š�\n" NOR,
                       me, this_object());

        command("nod");
        command("say ���п��Ƹ��ӣ���ʵ��������������ȥ���Լ����ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��Ʊ�ժ�¡���\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("miaojia-jian"))
                me->improve_skill("miaojia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/miaojia-jian/zhai", 1);
        me->add("gongxian", -400);
        return 1;
}

mixed ask_skill8()
{
        object me;

        me = this_player();

        if (me->query("can_perform/miaojia-jian/zhu"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("miaojia-jian", 1) < 1)
                return "������ҽ�����δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 600)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 15000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1200)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("miaojia-jian", 1) < 120)
                return "�����ҽ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��$N" HIY "Ц��Ц���漴������֣�"
                       "��ʳ��ָ��£������\n���������͡���һ���յ����"
                       "����ʱ�ƿ�֮�����죬һ��\n������ָ��ŷ�����$N"
                       HIY "���Ե�ľ����͸��һ��С�ס�\n" NOR, me,
                       this_object());

        command("nod");
        command("say ���в�������Խ���ý���������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ��������项��\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("miaojia-jian"))
                me->improve_skill("miaojia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/miaojia-jian/zhu", 1);
        me->add("gongxian", -600);
        return 1;
}

mixed ask_skill9()
{
        object me;

        me = this_player();

        if (me->query("can_perform/miaojia-jian/qian"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("miaojia-jian", 1) < 1)
                return "������ҽ�����δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 1000)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 18000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 220)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1800)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("miaojia-jian", 1) < 160)
                return "�����ҽ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��̾һ��������Ҳ���𻰣���$N" HIY
                       "���ӹ��佣������\nʮ������ҽ�����ʩ������ʱ��"
                       "����ˣ���â�ݺᣬ����\n��ֹ��ֻ��$n" HIY "��"
                       "ʩ����ʮ���ƽ�������һ�ƣ�������\n����һ���ǳ�"
                       "�������κ�������$N" HIY "ֻ����Ŀ�ɿڴ���\n"
                       NOR, me, this_object());

        command("nod");
        command("say ���Լ���ȥ��ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����ǧ���\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("miaojia-jian"))
                me->improve_skill("miaojia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/miaojia-jian/qian", 1);
        me->add("gongxian", -1000);
        return 1;
}

mixed ask_skill10()
{
        object me;

        me = this_player();

        if (me->query("can_perform/miaojia-jian/gan"))
                return "�Լ���ȥ��������˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����߿���";

        if (me->query_skill("miaojia-jian", 1) < 1)
                return "������ҽ�����δѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 2200)
                return "���������������Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 35000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 280)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 3000)
                return "���������Ϊ���㣬ѧ�������С�";

        if (me->query_skill("miaojia-jian", 1) < 200)
                return "�����ҽ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "������$N" HIY "���죬�����ص���"
                       "��ͷ�����°γ�������\n�����������ߣ��׹����"
                       "�����ش���ɽ��Ρ�ţ����鴦��\n����޼�����"
                       "֮������������Ѳ⡣�赽������$n" HIY "\nһ��"
                       "��ȣ������佣��Ȼ�������������һ�����ǣ�ֱ"
                       "û\n��������$N" HIY "�����ǽ���С�\n" NOR,
                       me, this_object());

        command("nod");
        command("say ����������ҽ����ľ��裬��Ҫ�ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ����Ǹ��¡���\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("miaojia-jian"))
                me->improve_skill("miaojia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/miaojia-jian/gan", 1);
        me->add("gongxian", -2200);
        return 1;
}

mixed ask_jian()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "��ԭ���")
                return "�����߿���";

        if (me->query("family/master_id") != query("id"))
                return "���ֲ����ҵĵ��ӣ���������Щʲô��";

        if (me->query("shen") < 20000)
                return "������������ˣ����������Ҳ��ܸ��㡣";

        if (me->query_skill("sword", 1) < 150)
                return "�㽣����û���ã����������������к��ã�";

        ob = find_object(TENGLONG);
        if (! ob) ob = load_object(TENGLONG);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "���������ڲ�����������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���������ڲ��������";

                if (owner->query("family/family_name") == "��ԭ���")
                        return "������������ʱ�����ֵ�" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�ҵ�����������������" + owner->query("name") +
                               "���У���ȥ�����һ����ɣ�";
        }
        ob->move(this_object());

        ob = new("/clone/weapon/changjian");
        ob->move(this_object());
        ob->wield();

        message_vision(CYN "$N" CYN "���˵�ͷ����������������������ȥ�ɣ���Ī����Ϊ��������\n" NOR,
                       this_object(), me);
        command("give tenglong jian to " + me->query("id"));
        return 1;
}

mixed ask_jianpu1()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "��ԭ���")
                return "�����߿���";

        if (me->query("family/master_id") != query("id"))
                return "���ֲ����ҵĵ��ӣ���������Щʲô��";

        if (me->query("shen") < 15000)
                return "�㲻�����������ˣ��⽣���Ҳ��ܸ��㡣";

        if (me->query("combat_exp") < 10000)
                return "�����ھ���̫ǳ���Ȿ���׶�����˵��������ˡ�";

        if (me->query_skill("suqin-beijian", 1) > 119)
                return "��Ľ��������Ѿ�����ʵ�ˣ��⽣�׻����������ǰɡ�";

        ob = find_object(JIANPUA);
        if (! ob) ob = load_object(JIANPUA);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "����ҵļҴ����ײ������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š��������ڲ��������";

                if (owner->query("family/family_name") == "��ԭ���")
                        return "��ҽ���������ʱ�����ֵ�" + owner->query("name") +
                               "ȡȥ���ˣ���Ҫ����ȥ�����ɡ�";
                else
                        return "������ҵļҴ���������������" + owner->query("name") +
                               "���У���ȥ����������ɣ�";
        }
        ob->move(this_object());
        message_vision(CYN "$N" CYN "��ͷ�����Ȿ���������ȥ���ɣ���Ҫ��ϸ�Ķ���\n" NOR,
                       this_object(), me);
        command("give miaojia jianpu to " + me->query("id"));
        return 1;
}

mixed ask_jianpu2()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "��ԭ���")
                return "�����߿���";

        if (me->query("family/master_id") != query("id"))
                return "���ֲ����ҵĵ��ӣ���������Щʲô��";

        if (me->query("shen") < 50000)
                return "�㲻�����������ˣ��⽣���Ҳ��ܸ��㡣";

        if (me->query("combat_exp") < 300000)
                return "�����ھ���̫ǳ���Ȿ���׶�����˵��������ˡ�";

        if (me->query_skill("sword", 1) > 199)
                return "��Ľ���������������ǵǷ��켫�ˣ��⽣�׻����������ǰɡ�";

        ob = find_object(JIANPUB);
        if (! ob) ob = load_object(JIANPUB);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "����ҵļҴ����ײ������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š��������ڲ��������";

                if (owner->query("family/family_name") == "��ԭ���")
                        return "��ҽ���������ʱ�����ֵ�" + owner->query("name") +
                               "ȡȥ���ˣ���Ҫ����ȥ�����ɡ�";
                else
                        return "������ҵļҴ���������������" + owner->query("name") +
                               "���У���ȥ����������ɣ�";
        }
        ob->move(this_object());
        message_vision(CYN "$N" CYN "������$N" CYN "���ã��������������ҽ��⽣�׽����㣬�ɱ�"
                       "�������֮�֡�\n" NOR, this_object(), me);
        command("give miaojia jianpu to " + me->query("id"));
        return 1;
}

void unconcious()
{
        die();
}
