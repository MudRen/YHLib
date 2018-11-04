#include <ansi.h>
#include "lingxiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        set_name("������", ({"bai zizai", "bai", "zizai"}));
        set("nickname", HIY "��������" NOR);
        set("long", "�����������ǳ�����ѩɽ���ɵ������ˣ������˳���\n"
                    "�������İ����ڡ��ഫ������ʱ�ɷ���ҩ���������\n"
                    "����������ϰ����ԣ�����Ϊ�����书��һ��\n");
        set("gender", "����");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 5500);
        set("max_jing", 5000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 200);
        set("combat_exp", 3500000);

        set("inquiry",([
                "���ѩ��" : "����������������ɣ��ò������鷳�Ϸ�",
                "ѩ������" : "����������������ɣ��ò������鷳�Ϸ�",
                "�������" : (: ask_skill1 :),
                "������"   : (: ask_skill2 :),
                "�񵹹��������" : (: ask_skill2 :),
        ]));

        set_skill("force", 300);
        set_skill("xueshan-neigong", 280);
        set_skill("wuwang-shengong", 300);
        set_skill("dodge", 260);
        set_skill("taxue-wuhen", 260);
        set_skill("cuff", 260);
        set_skill("lingxiao-quan", 260);
        set_skill("strike", 260);
        set_skill("piaoxu-zhang", 260);
        set_skill("sword", 280);
        set_skill("hanmei-jian", 280);
        set_skill("yunhe-jian", 280);
        set_skill("xueshan-jian", 280);
        set_skill("shangqing-jian", 280);
        set_skill("parry", 260);
        set_skill("literate", 250);
        set_skill("martial-cognize", 250);

        set("no_teach", ([
                "shangqing-jian" : "�Ϸ��������彣�����ǵ�������ϴ���������������ڣ������⴫��\n"
                "�������ֵ����⽣���䲻����ѩɽ���������Ҳ�ľ�����������ׯׯ��ʯ�����ҽ��ã���"
                "�ɴ���˽�����",
        ]));

        map_skill("force", "wuwang-shengong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "xueshan-jian");
        map_skill("parry", "shangqing-jian");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        create_family("������", 5, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hui" :),
                (: perform_action, "sword.chu" :),
                (: perform_action, "sword.feng" :),
                (: perform_action, "cuff.san" :),
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

        if ((int)me->query("shen") < 10000)
        {
                command("heng");
                command("say ���������������˳Ƶ������˾��ӣ���������Ϊͽ��");
                return;
        }

        if ((int)me->query("combat_exp") < 400000)
        {
                command("heng");
                command("say ��Ľ�������̫ǳ������ݵ��Ϸ�Ϊʦ��Ҳ��������Ϊ��");
                return;
        }

        if ((int)me->query_skill("xueshan-neigong", 1) < 120)
        {
                command("hmm");
                command("say �㱾���ڹ������������ȻҲ����˼�����Ϸ�");
                return;
        }

        if ((int)me->query_skill("xueshan-jian", 1) < 120)
        {
                command("say ��ԩ����ѩɽ�ɴ�����ô�ã���Ȼ����ѩɽ������û���á�");
                command("say ���Ǳ��������ɷ�Ϸ�Ҳ��");
                return;
        }

        command("say ��������");
        command("say �������ã������Ϸ���ո��ˣ���������ɣ�");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/xueshan-jian/feng"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҿ�������";

        if (me->query_skill("xueshan-jian", 1) < 1)
                return "����ѩɽ������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 2000)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 250)
                return "����ڹ�����̫ǳ���ò�����һ�У�";

        if (me->query_skill("xueshan-jian", 1) < 160)
                return "��ѩɽ������δ�����þ��û�������С�";

        message_vision( HIY "$n" HIY "����һЦ����$N" HIY "�޵���������"
                        "�����治�����Ϸ��ͽ\n�ܡ������Ϸ���ˣ�������"
                       "�У���Ҫ�����ˣ���$n" HIY "��������\n�漴һ����Х"
                        "�����г���������ֹ���ų�����⻪������������\nʱ"
                       "ʯм�ɽ���ֻ�����������͡�������$N" HIY "�������"
                       "ʯ�αھ��ѱ�\n$n" HIY "���г����������Ľ�â�ᴩ��"
                       "������һ�˸ߣ���߿����\n�죬ֱ����$N" HIY "Ŀ��"
                       "�ڴ���\n" NOR, me, this_object());
        command("haha");
        command("say �ղ�������ʾ��ȫ�����еľ������ڣ�����ȥ�������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("xueshan-jian"))
                me->improve_skill("xueshan-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xueshan-jian/feng", 1);
        me->add("gongxian", -2000);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/lingxiao-quan/san"))
                return "�Լ���ȥ�������ϸ��Ҿ������ݣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҿ�������";

        if (me->query_skill("lingxiao-quan", 1) < 1)
                return "��������ȭ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1500)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 250)
                return "����ڹ�����ʵ��̫���ȥ����������";

        if (me->query_skill("lingxiao-quan", 1) < 180)
                return "��������ȭ������������Ҳ����˼�����ҡ�";

        message_vision(HIY "$n" HIY "����$N" HIY "����һЦ���������ã��ã�"
                       "�ã���������Ҵ����\n�С���$N" HIY "������������"
                       "ǰ������$n" HIY "˵�����������ţ�����ô\n���֣���"
                       "ס��ĺ󾱣���ˤ��һ�����������һ̽����Ȼ�Ѿ�\n"
                       "ס��$N" HIY "�󾱡���һ�³��ּȿ죬��λ���棬$N"
                       HIY "��αܵã�ֻ����\n��������������ó��棬����һ"
                       "ץ֮�£����ӱ��ڿն��𣬵���\n�˵��ϡ�$n" HIY "һ"
                       "Ц�������漴̽��������ץס$N" HIY "�ؿڣ�˳��һ\n"
                       "˦���ٴν�$N" HIY "ˤ������ʱȴ��$n" HIY "�������"
                       "��ȥ��ɲ�Ǽ�ѿ�\nҪ���ص�$N" HIY "�ָ�����һ�ӡ�\n"
                       NOR, me, this_object());
        command("haha");
        command("say ʦ����һ����һץ��һ���������У��ų��񵹹����������");
        command("say ����������ȥ�����������պ��������");
        tell_object(me, HIC "��ѧ���ˡ��񵹹������������\n" NOR);

        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("lingxiao-quan"))
                me->improve_skill("lingxiao-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/lingxiao-quan/san", 1);
        me->add("gongxian", -1500);
        return 1;
}

