#include <ansi.h>
#include "hu.h"

#define LENGYUE  "/clone/lonely/lengyuedao"
#define JUNDAO   "/clone/lonely/jundao"
#define QUANJING "/clone/lonely/book/hujia1"
#define DAOPU    "/clone/lonely/book/hujia2"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_baodao();
mixed ask_jundao();
mixed ask_quanjing();
mixed ask_daopu();

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

mixed  try_to_learn_baishengdao();
mixed  try_to_learn_hujiadao();
mixed  try_to_learn_sixiangbu();

void create()
{
        object ob;
        set_name("���", ({"hu fei", "hu", "fei"}));
        set("gender", "����");
        set("nickname", HIW "ѩɽ�ɺ�" NOR);
        set("age", 25);
        set("long", @LONG
�����Ǻ�һ��֮�Ӻ�쳣������书��ǿ�����
û���ڽ�����������š�ѩɽ�ɺ���������
һ����ɫ�������������һ�ѿ������ܾɵĵ���
������ף�����������һͷŨ����ȴ����衣
LONG);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 45);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 5200);
        set("max_qi", 5200);
        set("jing", 3500);
        set("max_jing", 3500);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 180);
        set("combat_exp", 4000000);
        set("score", 20000);

        set_skill("force", 240);
        set_skill("lengyue-shengong", 240);
        set_skill("blade", 260);
        set_skill("liuhe-dao", 260);
        set_skill("chuangwang-dao", 260);
        set_skill("baisheng-daofa", 260);
        set_skill("hujia-daofa", 260);
        set_skill("dodge", 260);
        set_skill("sixiang-bufa", 260);
        set_skill("parry", 240);
        set_skill("throwing", 260);
        set_skill("mantian-xing", 260);
        set_skill("strike", 240);
        set_skill("liuhe-zhang", 240);
        set_skill("chuncan-zhang", 240);
        set_skill("cuff", 240);
        set_skill("hua-quan", 240);
        set_skill("hujia-quan", 240);
        set_skill("literate", 180);
        set_skill("martial-cognize", 240);

        map_skill("force", "lengyue-shengong");
        map_skill("blade", "hujia-daofa");
        map_skill("dodge", "sixiang-bufa");
        map_skill("parry", "hujia-daofa");
        map_skill("throwing", "mantian-xing");
        map_skill("strike", "chuncan-zhang");
        map_skill("cuff", "hujia-quan");

        prepare_skill("strike", "chuncan-zhang");
        prepare_skill("cuff",   "hujia-quan");

        set("no_teach", ([
                "baisheng-daofa" : (: try_to_learn_baishengdao :),
                "hujia-daofa"    : (: try_to_learn_hujiadao :),
                "sixiang-bufa"   : (: try_to_learn_sixiangbu :),
        ]));

        create_family("�������", 7, "����");

        set("inquiry", ([
                "���±���"   : (: ask_baodao :),
                "��������"   : (: ask_jundao :),
                "����ȭ��"   : (: ask_quanjing :),
                "���ҵ���"   : (: ask_daopu :),
                "�������"   : (: ask_skill1 :),
                "��������Ͼ���" : (: ask_skill1 :),
                "��ȭ���"   : (: ask_skill2 :),
                "����̽��"   : (: ask_skill3 :),
                "�����Ը�"   : (: ask_skill4 :),
                "��������"   : (: ask_skill5 :),
                "�ǹ���˸"   : (: ask_skill6 :),
                "�۰�Ⱥɽ"   : (: ask_skill7 :),
                "������"     : (: ask_skill8 :),
                "������ӡ��" : (: ask_skill9 :),
                "ж��׶����" : (: ask_skill10 :),
                "�˷��ص���" : (: ask_skill11 :),
                "������"   : "����ֻ�����Լ�ȥ����",
                "��ɨǧ��"   : "�ף�����ʲô��������û��˵����",
                "Ԭ����"     : "���ˣ��������������ˡ�",
                "�ֻ�"       : "�ֻ���������ҷ�ɱ�������ɡ�",
                "�԰�ɽ"     : "�������簡�����������⿴���ء� ",
                "������"     : "��֪ʲôʱ�����ټ����������",
                "����"       : "��֪ʲôʱ�����ټ����������",
                "��һ��"     : "�ɶ�������һ�����ҵ��������Ҵ�û��������",
                "������"     : "������Ҳ��֪���������ֻ����������˵������Ҫȥ������",
                "���˷�"     : "���˷�ͼҸ����������ɳ�Ϊ֪�����ѣ�Ȼ���Ҹ�ȴ�������Ľ��¡�"
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
	        (: perform_action, "blade.xian" :),
	        (: perform_action, "blade.zhui" :),
	        (: perform_action, "blade.cang" :),
	        (: perform_action, "cuff.kuai" :),
	        (: perform_action, "strike.jian" :),
	        (: perform_action, "dodge.fei" :),
	        (: perform_action, "throwing.shan" :),
	        (: perform_action, "throwing.xing" :),
	        (: exert_function, "recover" :),
	        (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        if (clonep())
        {
                ob = find_object(LENGYUE);
                if (! ob) ob = load_object(LENGYUE);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = find_object(JUNDAO);
                        if (! ob) ob = load_object(JUNDAO);
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
        }

        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->name(1) == "��һ��")
        {
                command("say �Ҳ٣��������ҵ����Ӱ���");
                return;
        }

        if (ob->name(1) == "���")
        {
                command("say �����̵ģ���զҲ��������֣�");
                return;
        }

        if (ob->name(1) == "����" || ob->name(1) == "����")
        {
                command("say �����������֣������������Ҳ̫�����ˡ�");
                return;
        }

        command("recruit " + ob->query("id"));
        command("say �����ұ������㣬���Ǻ��һ�Ҫ��������������");
        return;
}

mixed try_to_learn_baishengdao()
{
        object ob = this_player();

        if (ob->query("can_learn/hufei/baisheng-daofa"))
                return 0;

        if (ob->query("combat_exp") > 100000)
        {
                command("say �������������ұ㴫�����ʤ������");
                ob->set("can_learn/hufei/baisheng-daofa", 1);
                return 0;
        }

        return "���ʱ����̫ǳ���һ����ȴ�����һЩ�򵥵ĵ�����";
}

mixed try_to_learn_hujiadao()
{
        object ob = this_player();

        if (ob->query("can_learn/hufei/hujia-daofa"))
                return 0;

        if (ob->query("combat_exp") > 400000)
        {
                command("say ��Ȼ������������裬�ҽ��ձ㴫������ҵ�����");
                ob->set("can_learn/hufei/hujia-daofa", 1);
                return 0;
        }

        return "���ʵս���鲻�㣬����������������ҵ�����";
}

mixed try_to_learn_sixiangbu()
{
        object ob = this_player();

        if (ob->query("can_learn/hufei/sixiang-bufa"))
                return 0;

        if (ob->query("combat_exp") > 50000)
        {
                command("say �������书�Ѿ�����һ���Ļ����������Ҿʹ������󲽷���");
                ob->set("can_learn/hufei/sixiang-bufa", 1);
                return 0;
        }

        return "���󲽷�������˵���ڼ���㻹���ȵ춨�û�����˵��";
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/hua-quan/juan"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("hua-quan", 1) < 1)
                return "����������ȭ��δ��ѧ�������������У�";

        if (me->query("gongxian") < 350)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 5000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 180)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("hua-quan", 1) < 120)
                return "���������ȭ���δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "���˵�ͷ��˵���������Ƚ��⻪ȭ����"
                       "���������㣬�������\n��ᡣ��˵�������$n" HIY
                       "���е�������������Ͼ��죬���ǵ�ͷ��\n��ȭ����"
                       "�ƿ绢������������չ��ͥ��վ��Τ���ױ�����ǰ��"
                       "�ѱ�\n���ź����š��������������������ƿ绢����"
                       "������Գ͵�Ұ���ͥ��\n�����Խ�����ש������$N" HIY
                       "��һ��ϸϸ׽���������㣬�������á�\n" NOR, me,
                       this_object());
        command("nod");
        command("say �����Ի�ȭ�����ŵ���ݲμ������˴�ᣬ�ǴΡ���");
        command("sigh");
        command("say ��������ȭ�����Ƴ���������ȷ�������ɵö໨������ϰ��");
        tell_object(me, HIC "��ѧ���ˡ���������Ͼ��졹��\n" NOR);

        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("hua-quan"))
                me->improve_skill("hua-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/hua-quan/juan", 1);
        me->add("gongxian", -350);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/hujia-quan/kuai"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("hujia-quan", 1) < 1)
                return "��������ȭ����δ��ѧ�������������У�";

        if (me->query("gongxian") < 100)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 2000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("hujia-quan", 1) < 80)
                return "��ĺ���ȭ�����δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��΢���˵�ͷ���������һ��������"
                       "����ǰ��ȭ�е���������\n���ף���ʱ����$N" HIY
                       "������ȭ����ʽ��Ϊ���\n" NOR, me,
                       this_object());
        command("nod");
        command("say ��������");
        tell_object(me, HIC "��ѧ���ˡ���ȭ��򡹡�\n" NOR);

        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("hujia-quan"))
                me->improve_skill("hujia-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/hujia-quan/kuai", 1);
        me->add("gongxian", -100);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/liuhe-zhang/tan"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("liuhe-zhang", 1) < 1)
                return "���������Ʒ���δ��ѧ�������������У�";

        if (me->query("gongxian") < 50)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 1500)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("liuhe-zhang", 1) < 60)
                return "��������Ʒ����δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "����һЦ��Ҳ���𻰣���Ȼ�䵥���"
                       "��̽��������$N" HIY "��ǰ���䡣\n$N" HIY "��ʱ"
                       "��ʧɫ����æ���Ծ�����ߣ�����Ȼ������$n" HIY
                       "�ĵ�����\n����$N" HIY "���ز���ࡣ\n" NOR, me,
                       this_object());

        if ((string)me->query("gender") == "Ů��")
        {
                command("ah");
                command("say ���ԡ��Բ�ס����������������Ů�ġ�");
        } else
                command("haha");

        command("say ��ʽ������ˣ��Լ���ȥ��ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����̽������\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("liuhe-zhang"))
                me->improve_skill("liuhe-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/liuhe-zhang/tan", 1);
        me->add("gongxian", -50);
        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/chuncan-zhang/jian"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("chuncan-zhang", 1) < 1)
                return "���������Ʒ���δ��ѧ�������������У�";

        if (me->query("gongxian") < 400)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 5000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 120)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("chuncan-zhang", 1) < 80)
                return "��Ĵ����Ʒ����δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "����ض�$N" HIY "���˵�ͷ��˵����"
                       "���ҽ����и�����ʾһ�飬�ɵ�\n������ˡ���˵��"
                       "ֻ��$n" HIY "ĬĬ�����������ƾ����²�������ʱ"
                       "˫\n������һ������������������㻤ס��\n" NOR,
                       me, this_object());

        command("nod");
        command("say ��������ǿ�е�ʱ��ܹ��ã������Һ����˷�һս��ȫ�������Ʒ���");
        tell_object(me, HIC "��ѧ���ˡ������Ը�����\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("chuncan-zhang"))
                me->improve_skill("chuncan-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/chuncan-zhang/jian", 1);
        me->add("gongxian", -400);
        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/sixiang-bufa/fei"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("sixiang-bufa", 1) < 1)
                return "�������󲽷���δ��ѧ����������ʲô��";

        if (me->query("gongxian") < 1000)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 12000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force", 1) < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1000)
                return "���������Ϊ��������������������";

        if (me->query_skill("dodge", 1) < 150)
                return "��Ļ����Ṧ�д���ߣ���ʱ��ѧ�������С�";

        if (me->query_dex() < 33)
                return "�����̫���������ϰ��";

        if (me->query_skill("sixiang-bufa", 1) < 150)
                return "������󲽷����δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ���ȵ�������"
                       "���ˡ����������䣬ֻ��$n" HIY "���\n������"
                       "�����һԾ�������ζ�ʱ���Ʈ������������׽"
                       "����$N" HIY "\nԽ��Խ�����棬�������Ը�̾��\n"
                       NOR, me, this_object());

        command("haha");
        command("say �ɿ������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ��������С���\n" NOR);

        if (me->can_improve_skill("dodge"))
                me->improve_skill("dodge", 1500000);
        if (me->can_improve_skill("sixiang-bufa"))
                me->improve_skill("sixiang-bufa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/sixiang-bufa/fei", 1);
        me->add("gongxian", -1000);
        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();

        if (me->query("can_perform/mantian-xing/shan"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("mantian-xing", 1) < 1)
                return "���������Ƕ�δ��ѧ�������������У�";

        if (me->query("gongxian") < 200)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 3000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("mantian-xing", 1) < 100)
                return "��������ǻ��δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "����һЦ����$N" HIY "������ǰ����"
                       "���ڶ���ϸ�����������ǰ�����\n�������Ҫ�㡣��"
                       "����������֣�ʮָ���ţ�һ��һ������������\nһ"
                       "�ֺ��ر�İ������š�\n" NOR, me, this_object());

        command("nod");
        command("say �ղŰ�˵���㶼��ס����");
        tell_object(me, HIC "��ѧ���ˡ��ǹ���˸����\n" NOR);

        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("mantian-xing"))
                me->improve_skill("mantian-xing", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/mantian-xing/shan", 1);
        me->add("gongxian", -200);
        return 1;
}

mixed ask_skill7()
{
        object me;

        me = this_player();

        if (me->query("can_perform/chuangwang-dao/xiong"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("chuangwang-dao", 1) < 1)
                return "��������������δ��ѧ�������������У�";

        if (me->query("gongxian") < 50)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 500)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 60)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("chuangwang-dao", 1) < 40)
                return "��Ĵ����������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "Ц��Ц�����ֽ�$N" HIY "�е���ǰ"
                       "��������$N" HIY "�����ֹ��˰��졣Ȼ��\n�ְγ�"
                       "�����������£��ƺ���һ����Ϊ���͵ĵ�����\n"
                       NOR, me, this_object());

        command("nod");
        command("say ���������ڳ������ģ����ֶԿ�ȴ�����á�");
        tell_object(me, HIC "��ѧ���ˡ��۰�Ⱥɽ����\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("chuangwang-dao"))
                me->improve_skill("chuangwang-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/chuangwang-dao/xiong", 1);
        me->add("gongxian", -50);
        return 1;
}

mixed ask_skill8()
{
        object me;

        me = this_player();

        if (me->query("can_perform/liuhe-dao/shan"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("liuhe-dao", 1) < 1)
                return "�������ϵ�����δ��ѧ�������������У�";

        if (me->query("gongxian") < 200)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 3500)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("liuhe-dao", 1) < 80)
                return "������ϵ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "��$N" HIY "Ц��Ц���γ������嵶"
                       "�������У�˵�����������ϵ�����\nҪ��������չ"
                       "��Ĩ�������硢���������ƣ������ˡ���˵���ֻ"
                       "��\n$n" HIY "���иֵ����²�������������������"
                       "�ͻ��������任�����ַ�\nλ��������һ������"
                       "�������������ֱ�졣\n" NOR, me, this_object());

        command("nod");
        command("say ֻҪ�������������ϵķ�λ�����б㲻����ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("liuhe-dao"))
                me->improve_skill("liuhe-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/liuhe-dao/shan", 1);
        me->add("gongxian", -200);
        return 1;
}

mixed ask_skill9()
{
        object me;

        me = this_player();

        if (me->query("can_perform/hujia-daofa/xian"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("hujia-daofa", 1) < 1)
                return "�������ҵ�����δ��ѧ�������������У�";

        if (me->query("gongxian") < 900)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 15000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 160)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("hujia-daofa", 1) < 120)
                return "��ĺ��ҵ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "�γ������嵶���������С���$N" HIY "Ц"
                       "�������ұ������й��㣬��\n����εֵ�����˵��$n" HIY
                       "�Ѻ������������������$N" HIY "��˫�ַ���\n������"
                       "���ѣ�������$N" HIY "�ƽ���$N" HIY "��״������Ȼʧ"
                       "Ц���ĵ�������Ҳ\n�Ƶ����ǵ�������˻�����ô�ƵС�"
                       "������Ҳ�����ԣ�����ǰ����\nһ�У�����ʱֻ��$n" HIY
                       "����һ�䣬�й�ֱ����$N" HIY "��������Ȼȫ����\n����"
                       "$N" HIY "��æ�����ұܣ���$n" HIY "�ĵ���ʼ�ղ���$N"
                       HIY "��ǰ��硣\n" NOR, me, this_object());

        command("haha");
        command("say �������������ƿ�ĵ��ƣ������˱���Ҫ�㡣");
        command("say �����Ҵ����˷ﴦ֪�����������������治ǳ��");
        tell_object(me, HIC "��ѧ���ˡ�������ӡ�ơ���\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("hujia-daofa"))
                me->improve_skill("hujia-daofa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/hujia-daofa/xian", 1);
        me->add("gongxian", -900);
        return 1;
}

mixed ask_skill10()
{
        object me;

        me = this_player();

        if (me->query("can_perform/hujia-daofa/zhui"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("hujia-daofa", 1) < 1)
                return "�������ҵ�����δ��ѧ�������������У�";

        if (me->query("gongxian") < 1300)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 22000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("hujia-daofa", 1) < 140)
                return "��ĺ��ҵ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "΢΢��ף������𻰣������������"
                       "��������������ʹ������\n�����е�һʽ������ж��"
                       "�����Ʒ�бб����һ����Ȧ������������\n��������"
                       "����;ȴ��Ȼ���һ�С�����׶�������Ƽ�����ת��"
                       "����\n�����д�����$N" HIY "�������˫Ŀ��Ȼ"
                       "һ�����ƺ�������ʲô��\n" NOR,
                       me, this_object());

        command("nod2");
        command("say ���еľ�Ҫ������ж�����˵ķ������ٸ�������һ����");
        command("say ���š�����̫����������ǧ��������Ϊ��������");
        tell_object(me, HIC "��ѧ���ˡ�ж��׶���ơ���\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("hujia-daofa"))
                me->improve_skill("hujia-daofa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/hujia-daofa/zhui", 1);
        me->add("gongxian", -1300);
        return 1;
}

mixed ask_skill11()
{
        object me;

        me = this_player();

        if (me->query("can_perform/hujia-daofa/cang"))
                return "�������Ѿ��̹������𣿻���˵ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ��ǰ����ҵģ�����������ʲô��";

        if (me->query_skill("hujia-daofa", 1) < 1)
                return "�������ҵ�����δ��ѧ�������������У�";

        if (me->query("gongxian") < 2200)
                return "�����Һ���µµ��Ϊ���������Ȳ�æ���㡣";

        if (me->query("shen") < 30000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 250)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("hujia-daofa", 1) < 180)
                return "��ĺ��ҵ������δ�������ö���ϰ��ϰ��";

        message_vision(HIY "$n" HIY "������$N" HIY "���죬�����ص���"
                       "��ͷ����Ϊ����������벻������\n��ĵ�������"
                       "������裬����ʱ�գ���ص�����Ϊʦ�������Ҿ�"
                       "��\n�����װ˷��ص��ƣ�ϣ���պ����ܹ�������Ϊ"
                       "����$n" HIY "���˶٣���\n���Ŷ�$N" HIY "˵��"
                       "�����Һ��ҵ���֮���������������������������"
                       "֪\n�����ۿͣ������Կͷ�������ʤ���ϣ���ʤ��"
                       "�������ҵ������õ�\n�Ĳ��������ʡ������顢��"
                       "�ȵ��ƾ�Զǿ��һ�㵶����չ��Ĩ������\n�硢��"
                       "�����ȵ��ơ�����˷��ص��Ƶı仯ȴ�ֲ�ֹ�ڴ�"
                       "��������\n������˵�������������㣬��������"
                       "�������á���\n" NOR, me, this_object());

        command("nod");
        command("say �ղ�����˵��ȫ��Ҫ�㣬���μ����ġ�");
        command("say ��������һ��Ҫ�ڼ���ϰ�����ܽ������õô��졣");
        tell_object(me, HIC "��ѧ���ˡ��˷��ص��ơ���\n" NOR);

        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("dodge"))
                me->improve_skill("dodge", 1500000);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("hujia-daofa"))
                me->improve_skill("hujia-daofa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/hujia-daofa/cang", 1);
        me->add("gongxian", -2200);
        return 1;
}

mixed ask_baodao()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�������")
                return "�����������ģ�������������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "���ֲ����ҵĵ��ӣ���������Щʲô��";

        if (me->query("shen") < 10000)
                return "�㲻�����������ˣ��ⱦ���Ҳ��ܸ��㡣";

        if (me->query_skill("hujia-daofa", 1) < 150)
                return "�㻹������������Ѻ��ҵ���������˵�ɡ�";

        ob = find_object(LENGYUE);
        if (! ob) ob = load_object(LENGYUE);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "���̵ģ���������ˣ����ı������ǽ���������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š����±������ڲ��������";

                if (owner->query("family/family_name") == "�������")
                        return "���±���������ʱ�����ֵ�" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�������±�������������" + owner->query("name") +
                               "���У���ȥ�����һ����ɣ�";
        }
        ob->move(this_object());

        ob = new("/clone/weapon/gangdao");
        ob->move(this_object());
        ob->wield();

        message_vision(CYN "$N" CYN "��Ц�����������ã���������������ȥ�ðɡ�\n" NOR,
                       this_object(), me);
        command("give lengyue baodao to " + me->query("id"));
        return 1;
}

mixed ask_jundao()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�������")
                return "�����������ģ�������������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "���ֲ����ҵĵ��ӣ���������Щʲô��";

        if (me->query("shen") < 10000)
                return "�㲻�����������ˣ�������Ҳ��ܸ��㡣";

        if (me->query_skill("blade", 1) < 120)
                return "������������ʹ����ô���ô���������";

        ob = find_object(JUNDAO);
        if (! ob) ob = load_object(JUNDAO);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�����Ǳ���������������������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š������������ڲ��������";

                if (owner->query("family/family_name") == "�������")
                        return "��������������ʱ�����ֵ�" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���Ĵ�����������������" + owner->query("name") +
                               "���У���ȥ�����һ����ɣ�";
        }
        ob->move(this_object());

        ob = new("/clone/weapon/gangdao");
        ob->move(this_object());
        ob->wield();

        message_vision(CYN "$N" CYN "���˵�ͷ������������С���г�Ϣ��������"
                       "�������ȥ�ðɡ�\n" NOR, this_object(), me);
        command("give chuangwang jundao to " + me->query("id"));
        return 1;
}

mixed ask_quanjing()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�������")
                return "�����������ģ�������������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "���ֲ����ҵĵ��ӣ���������Щʲô��";

        if (me->query("shen") < 10000)
                return "�㲻�����������ˣ���ȭ���Ҳ��ܸ��㡣";

        if (me->query("combat_exp") < 10000)
                return "�����ھ���̫ǳ������æ��ȥ�Ķ�ȭ����";

        if (me->query_skill("hujia-quan", 1) > 119)
                return "�����ȭ���������Ѿ���ǳ�ˣ��Ǳ�ȭ�������������Ƕ��ɡ�";

        ob = find_object(QUANJING);
        if (! ob) ob = load_object(QUANJING);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Һ��ҵļҴ�ȭ���������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š�����ȭ�����ڲ��������";

                if (owner->query("family/family_name") == "�������")
                        return "����ȭ��������ʱ�����ֵ�" + owner->query("name") +
                               "ȡȥ���ˣ���Ҫ����ȥ�����ɡ�";
                else
                        return "���Ǻ��ҵļҴ�ȭ������������" + owner->query("name") +
                               "���У���ȥ����������ɣ�";
        }
        ob->move(this_object());
        message_vision(CYN "$N" CYN "��ͷ�������š��Ȿȭ�������ȥ�ɣ���Ҫ�����ж���\n" NOR,
                       this_object(), me);
        command("give hujia quanjing to " + me->query("id"));
        return 1;
}

mixed ask_daopu()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�������")
                return "�����������ģ�������������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "���ֲ����ҵĵ��ӣ���������Щʲô��";

        if (me->query("shen") < 15000)
                return "�㲻�����������ˣ��⵶���Ҳ��ܸ��㡣";

        if (me->query("combat_exp") < 50000)
                return "�����ھ���̫ǳ���Ȿ���׶�����˵��������ˡ�";

        if (me->query_skill("blade", 1) > 179)
                return "�㵶���������ѳƵ����ǵǷ��켫�ˣ����׻����������Ƕ��ɡ�";

        ob = find_object(DAOPU);
        if (! ob) ob = load_object(DAOPU);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Һ��ҵļҵ��׾��������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š����ҵ������ڲ��������";

                if (owner->query("family/family_name") == "�������")
                        return "���ҵ���������ʱ�����ֵ�" + owner->query("name") +
                               "ȡȥ���ˣ���Ҫ����ȥ�����ɡ�";
                else
                        return "���Ǻ��ҵļҴ���������������" + owner->query("name") +
                               "���У���ȥ����������ɣ�";
        }
        ob->move(this_object());
        message_vision(CYN "$N" CYN "��ͷ�����Ȿ���ҵ��������ȥ���ɣ��в���"
                       "֮�����������ҡ�\n" NOR, this_object(), me);
        command("give hujia daopu to " + me->query("id"));
        return 1;
}

void unconcious()
{
        die();
}
