#include <ansi.h>
#include "lingxiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();

void create()
{
        set_name("����", ({"bai wanjian", "bai", "wanjian"}));
        set("nickname", HIW "��������" NOR);
        set("long", "������ѩɽ���������������������ڵĳ��ӣ���\n"
                    "��ʦ�ֵܾ��ԡ��������У������־�Ȼ�е�����\n"
                    "�����������֮�ߡ�\n");
        set("gender", "����");
        set("age", 34);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3800);
        set("max_jing", 3000);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 180);
        set("combat_exp", 1000000);

        set("inquiry",([
                "�佣��"   : (: ask_skill1 :),
                "�����ܾ�" : (: ask_skill2 :),
                "����Ʈ��" : (: ask_skill3 :),
                "�׳����" : (: ask_skill4 :),
                "���ѩ��" : (: ask_skill5 :),
                "ѩ������" : (: ask_skill6 :),
        ]));

        set_skill("force", 200);
        set_skill("xueshan-neigong", 200);
        set_skill("dodge", 200);
        set_skill("taxue-wuhen", 200);
        set_skill("cuff", 180);
        set_skill("lingxiao-quan", 180);
        set_skill("strike", 180);
        set_skill("piaoxu-zhang", 180);
        set_skill("sword", 220);
        set_skill("hanmei-jian", 220);
        set_skill("yunhe-jian", 220);
        set_skill("xueshan-jian", 220);
        set_skill("parry", 200);
        set_skill("literate", 200);
        set_skill("martial-cognize", 150);

        map_skill("force", "xueshan-neigong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "xueshan-jian");
        map_skill("parry", "yunhe-jian");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        create_family("������", 6, "���ŵ���");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.chu" :),
                (: perform_action, "cuff.jue" :),
                (: perform_action, "strike.piao" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < 3000)
        {
                command("say ѧ�������������ʵ�����һ������ù���");
                return;
        }

        if ((int)me->query("combat_exp") < 150000)
        {
                command("say �����ڽ�������̫ǳ�����Ƕ�������������ɡ�");
                return;
        }

        if ((int)me->query_skill("xueshan-neigong", 1) < 80)
        {
                command("say �㱾�ŵ��ڹ��ķ�̫���������֮���������ҡ�");
                return;
        }

        if ((int)me->query_skill("sword", 1) < 80)
        {
                command("say ��Ľ�������ʵ����̫���ȥ������������");
                return;
        }

        command("say �ܺã��ܺá�");
        command("say ���������ģ������ұ�����Ϊͽ��ϣ���պ�����һ����Ϊ��");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/hanmei-jian/leng"))
                return "�Լ���ȥ������������������¸�û�꣡";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���´Ӻζ���������������ѩɽ�ɾ�����ʲô��˼��";

        if (me->query_skill("hanmei-jian", 1) < 1)
                return "������÷������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 50)
                return "����ڹ�����ʵ��̫���ȥ����������";

        if (me->query_skill("hanmei-jian", 1) < 40)
                return "���㺮÷��������������Ҳ����˼�����ҡ�";

        message_vision(HIY "$n" HIY "��΢���˵�ͷ����$N" HIY "����"
                        "��ǰ��������$N" HIY "����ϸ˵\n���ã�ʱ��"
                        "ʱ�������ݻ����У�$N" HIY "һ����һ�ߵ�ͷ"
                        "��\n" NOR, me, this_object());
        command("nod");
        command("say ���кܼ򵥣�����ȥ����˵����ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��佣������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("hanmei-jian"))
                me->improve_skill("hanmei-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/hanmei-jian/leng", 1);
        me->add("gongxian", -50);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/lingxiao-quan/jue"))
                return "�Լ���ȥ�������ϸ��Ҿ������ݣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����޹ʴ�����ѩɽ�ɵľ�����ʲô��˼��";

        if (me->query_skill("lingxiao-quan", 1) < 1)
                return "��������ȭ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 100)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����ʵ��̫���ȥ����������";

        if (me->query_skill("lingxiao-quan", 1) < 60)
                return "��������ȭ������������Ҳ����˼�����ҡ�";

        message_vision(HIY "$n" HIY "������$N" HIY "һ����Ȼ��΢΢һ"
                       "Ц��ʾ�������ֽ�$N" HIY "\n������ǰ��������"
                       "$N" HIY "����ϸ˵���ã�ʱ��ʱ�����ֱȳ���\nʽ"
                       "ȭ���еľ���֮����$N" HIY "һ����һ�ߵ�ͷ��\n"
                       NOR, me, this_object());
        command("nod");
        command("say ���в����ѣ�ֻ���мǡ��������������ּ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������ܾ�����\n" NOR);

        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("lingxiao-quan"))
                me->improve_skill("lingxiao-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/lingxiao-quan/jue", 1);
        me->add("gongxian", -100);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();
        if (me->query("can_perform/piaoxu-zhang/piao"))
                return "�Լ���ȥ������������������¸�û�꣡";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����޹ʴ�����ѩɽ�ɵľ�����ʲô��˼��";

        if (me->query_skill("piaoxu-zhang", 1) < 1)
                return "����Ʈ���Ʒ���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����ʵ��̫���ȥ����������";

        if (me->query_skill("piaoxu-zhang", 1) < 80)
                return "����Ʈ���Ʒ�����������Ҳ����˼�����ҡ�";

        message_vision(HIY "$n" HIY "��΢���˵�ͷ��˵�������Ҹ�����ʾ"
                      "һ�飬�ɵ���\n��ϸ�ˣ����漴һ����Х��˫�Ʒ׷�"
                      "�������Ӱ���ص���\n��ʵ�ѱ棬ȫȫ����$N" HIY
                      "ȫ��\n" NOR, me, this_object());
        command("nod");
        command("say �ղ�������ʾ��ȫ�����еľ���������ȥ�����������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ�����Ʈ�㡹��\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("piaoxu-zhang"))
                me->improve_skill("piaoxu-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/piaoxu-zhang/piao", 1);
        me->add("gongxian", -150);
        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();
        if (me->query("can_perform/yunhe-jian/chong"))
                return "�Լ���ȥ�������ϸ��Ҿ������ݣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "��������������ѩɽ�ɾ�����ʲô��˼��";

        if (me->query_skill("yunhe-jian", 1) < 1)
                return "�����ƺ��߽���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����ʵ��̫���ȥ����������";

        if (me->query_skill("yunhe-jian", 1) < 100)
                return "�����ƺ��߽�����������Ҳ����˼�����ҡ�";

        message_vision(HIY "$n" HIY "���˵�ͷ�����ִ����������ȡ"
                       "��һ��������ָ\n������һ�ζ�$N" HIY "ϸ˵��"
                       "���ã�$N" HIY "һ����һ�ߵ�ͷ��\n" NOR, me,
                       this_object());
        command("nod");
        command("say ���кܼ򵥣�����ȥ����˵����ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��׳��������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("yunhe-jian"))
                me->improve_skill("yunhe-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yunhe-jian/chong", 1);
        me->add("gongxian", -200);
        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();
        if (me->query("can_perform/xueshan-jian/hui"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҿ�������";

        if (me->query_skill("xueshan-jian", 1) < 1)
                return "����ѩɽ������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 500)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����̫ǳ���ò�����һ�У�";

        if (me->query_skill("xueshan-jian", 1) < 30)
                return "��ѩɽ������δ�����þ��û�������С�";

        message_vision(HIY "$n" HIY "΢΢һЦ�����˵�ͷ��˵�ű���$N" HIY
                        "����������˵��\n����Ҫ��һ��˵��һ�߱Ȼ���Щʲ"
                       "ô���������ã�ֻ��$N" HIY "\n���ĵ�һЦ���ƺ���"
                       "��ʲô�µĸ���\n" NOR, me, this_object());
        command("smile");
        command("say ��һ�п��Ƹ��ӣ�ʵȴ��࣬�Լ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����ѩ�衹��\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("xueshan-jian"))
                me->improve_skill("xueshan-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xueshan-jian/hui", 1);
        me->add("gongxian", -500);
        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();
        if (me->query("can_perform/xueshan-jian/chu"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҿ�������";

        if (me->query_skill("xueshan-jian", 1) < 1)
                return "����ѩɽ������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1000)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����̫ǳ���ò�����һ�У�";

        if (me->query_skill("xueshan-jian", 1) < 140)
                return "��ѩɽ������δ�����þ��û�������С�";

        message_vision(HIY "$n" HIY "΢΢һЦ����$N" HIY "�޵�������"
                       "�������������������\n�裬����ʹ������С���"
                        "˵��$n" HIY "�γ��佣��������ס\n��������ʱ"
                       "ֻ������������������ʵ��ʵ�����飬���⽣\n��"
                        "���ã������̳���$N" HIY "ֻ����ǰ����һ����"
                       "�����漴ľм\n�׷ɣ���ǰ�ĺ��������Ͼ���Ȼӡ"
                       "���������ۣ�������ʢ\n����÷��һ�㣬����ϸ��"
                       "Ҳ������ˡ�\n" NOR, me, this_object());
        command("haha");
        command("say ��һ�б���ѩ������������ȥ������ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�ѩ����������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("xueshan-jian"))
                me->improve_skill("xueshan-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xueshan-jian/chu", 1);
        me->add("gongxian", -1000);
        return 1;
}

void unconcious()
{
        die();
}
