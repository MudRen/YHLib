#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_jiansuo();
mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();

#define JIANSUO    "/clone/lonely/jiansuo"

int try_to_learn_quan();

void create()
{
        object ob;
        set_name("�¼���", ({ "chen jialuo", "chen","jialuo" }));
        set("title", "�컨�����ܶ���");
        set("long", "��һ��ģ��ֱ�Ǹ������˼ҵ������ӵܣ���\n"
                    "������Ŀ�����ǣ����ۻ���������ҡ��һ\n"
                    "�����ȣ���ɷ���������ţ�����˹�ġ�\n"
                    "����ٲȻ�Ǹ���鹫�ӡ�\n");
        set("nickname", HIW "��������" NOR);
        set("gender", "����");
        set("class", "scholar");
        set("age", 22);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 5000);
        set("max_jing", 4000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 200);
        set("combat_exp", 4000000);
        set("score", 5000000);

        set_skill("force", 260);
        set_skill("zhanshen-xinjing", 260);
        set_skill("tianchi-neigong", 240);
        set_skill("honghua-xinfa", 240);
        set_skill("dodge", 260);
        set_skill("zhuangzi-wu", 260);
        set_skill("yanzi-chuanyun", 240);
        set_skill("parry", 240);
        set_skill("unarmed", 260);
        set_skill("baihua-cuoquan", 260);
        set_skill("claw", 260);
        set_skill("strike", 260);
        set_skill("cuff", 260);
        set_skill("blade", 220);
        set_skill("hanwang-qingdao", 220);
        set_skill("sword", 220);
        set_skill("sanfen-jianshu", 220);
        set_skill("whip", 240);
        set_skill("jiandun-zhusuo", 240);
        set_skill("martial-cognize", 250);
        set_skill("literate", 250);

        map_skill("dodge", "zhuangzi-wu");
        map_skill("force", "zhanshen-xinjing");
        map_skill("unarmed", "baihua-cuoquan");
        map_skill("parry", "baihua-cuoquan");
        map_skill("sword", "sanfen-jianshu");
        map_skill("whip", "jiandun-zhusuo");
        map_skill("blade", "hanwang-qingdao");

        prepare_skill("unarmed", "baihua-cuoquan");

        set("no_teach", ([
                "sanfen-jianshu"  : "�⽣�������ҳ��ɴ���������������ڣ������⴫��",
                "hanwang-qingdao" : "�ţ��⵶�������ķ������ѧȥ�ɣ��Ҳ�����ڡ�",
                "baihua-cuoquan"  : (: try_to_learn_quan :),
        ]));

        create_family("�컨��", 4, "���ܶ���");

        set("inquiry", ([
                "��������"   : (: ask_jiansuo :),
                "���־�"     : (: ask_skill1 :),
                "ǧͷ����"   : (: ask_skill2 :),
                "����"       : (: ask_skill3 :),
                "�ٻ�����"   : (: ask_skill4 :),
                "�ٻ�����"   : (: ask_skill5 :),
                "ս������" : (: ask_skill6 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luan" :),
                (: perform_action, "unarmed.yi" :),
                (: perform_action, "unarmed.hong" :),
                (: perform_action, "whip.qian" :),
                (: perform_action, "whip.fu" :),
                (: perform_action, "dodge.hua" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "recover" :),
        }) );

        setup();

        if (clonep())
        {
                ob = find_object(JIANSUO);
                if (! ob) ob = load_object(JIANSUO);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                }
        }

        carry_object("/d/city/npc/cloth/fu-cloth")->wear();
        carry_object("/d/city/npc/cloth/jade-belt")->wear();
        carry_object("/d/city/npc/cloth/scarf")->wear();
        add_money("gold", 2);
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < 65000)
        {
                command("say �Һ컨����Ϊ�����²���������������һ���޲�"
                        "������Ϊ�ء�");
                command("say �����ڵ��з��棬�ƺ������ò�����");
                return;
        }

        if ((int)me->query("combat_exp") < 400000)
        {
                command("say ��Ľ�������̫ǳ���Ҿ��������㣬������Ҳ��"
                        "������Ϊ��");
                return;
        }

        if ((int)me->query_skill("honghua-xinfa", 1) < 100)
        {
                command("say �㱾�ŵ��ڹ��ķ���δ��͸����θ���ϰ�����"
                        "��ѧ��");
                return;
        }

        if ((int)me->query("max_neili") < 2000)
        {
                command("say �ҵ��书ȫ��ǿ����ڹ�Ϊ���������ƺ�Ӧ�ö�"
                        "����������");
                return;
        }

        command("nod");
        command("say ��������������������ģ��������������ˣ������ұ������㡣");
        command("say ϣ�������պ�������£�Ϊ�Һ컨�ᷢ��׳��");
        command("recruit " + me->query("id"));
}

int try_to_learn_quan()
{
        object me;
        object sob;
        int i;
        int flag;
        string *sub_skills;

        me = this_player();

        if (! me->query("can_learn/chen/baihua-cuoquan") &&
            me->query("family/master_id") != query("id"))
        {
                command("say �����Ϊ�ҵĵ��Ӻ���˵�ɡ�");
                return -1;
        }

        if (me->query("shen") < 100000)
        {
                command("heng");
                command("say ���Ǻ컨���ڽ��������ߣ����ľ��ǡ����塱���֡�");
                command("say �����ⶼ���ˣ�������θҴ������㣿");
                return -1;
        }

        sob = find_object(SKILL_D("baihua-cuoquan"));
        if (! sob) sob = load_object(SKILL_D("baihua-cuoquan"));
        if (! sob->valid_learn(me))
                return 0;
        if (me->query_skill("baihua-cuoquan", 1))
        {
                command("say �ף��㲻���Ѿ�����ô���Լ���ȥ�ú����ɡ�");
                return -1;
        }

        sub_skills = keys(sob->query_sub_skills());
        flag = 0;
        for (i = 0; i < sizeof(sub_skills); i++)
        {
                if (me->query_skill(sub_skills[i], 1) >= 10)
                        continue;
                me->set_skill(sub_skills[i], 10);
                if (! flag)
                {
                        flag = 1;
                        command("say ���������ڽ����װٻ���ȭ�������㣬"
                                "��ȥ��Ҫ�ú���ϰ�����ձ����ڻ��ͨ��");
                }
                write(HIC "���" + to_chinese(sub_skills[i]) + "����һ"
                      "Щ����\n" NOR);
        }

        if (! flag)
        {
                command("say �ţ��Ҳ��ǽ�����ȥ���Լ���ϰ��");
                command("say �����ڻ��֮ͨ���������Ұɡ�");
                return -1;
        }

        command("say ���Լ���ȥ��ϰ�ɣ��Ҽ����߽�����һ��������Ϊ�أ�");
        notify_fail("���Լ���ȥ�ú���ϰ�ɡ�\n");
        return -1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jiandun-zhusuo/fu"))
                return "�����Ҳ�����ʹ��ڸ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("jiandun-zhusuo", 1) < 1)
                return "��������������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 60000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if ((int)me->query("max_neili") < 600)
                return "���������Ϊ������ѧ�������С�";

        if (me->query_skill("jiandun-zhusuo", 1) < 50)
                return "��Ľ������������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "����"
                       "��ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY "\n��"
                       "����ĵ�һЦ��������������\n" NOR, me,
                       this_object());

        command("nod");
        command("say ���кܼ򵥣���΢������ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);

        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("jiandun-zhusuo"))
                me->improve_skill("jiandun-zhusuo", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jiandun-zhusuo/fu", 1);
        me->add("gongxian", -200);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jiandun-zhusuo/qian"))
                return "�����Ҳ�����ʹ��ڸ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("jiandun-zhusuo", 1) < 1)
                return "��������������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1200)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 100000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if (me->query_skill("force") < 180)
                return "���������Ϊ������ѧ�������С�";

        if (me->query_skill("jiandun-zhusuo", 1) < 120)
                return "��Ľ������������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "����ص��˵�ͷ����������"
                       "Ȼ��������ģ�����\n�ұ㴫����С���$n" HIY "��"
                       "�����֣�$N" HIY "��æ����ǰȥ��ֻ��\n$n" HIY "��"
                       "����$N" HIY "˵��Щ�����������г���һ������ʱ��"
                       "����\n���Ӱ����������ͨ�죬������Ӱ������˷���"
                       "���ȥ��\n" NOR, me, this_object());

        command("smile");
        command("say ��������ע���󲿵���������ȥ�����ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�ǧͷ��������\n" NOR);

        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("jiandun-zhusuo"))
                me->improve_skill("jiandun-zhusuo", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jiandun-zhusuo/qian", 1);
        me->add("gongxian", -1200);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhuangzi-wu/hua"))
                return "�����Ҳ����Ѿ��̸�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("zhuangzi-wu", 1) < 1)
                return "����ׯ���趼ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1000)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 100000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if ((int)me->query_dex() < 32)
                return "������鶯�Բ��㣬ѧ�������С�";

        if ((int)me->query("max_neili") < 2000)
                return "���������Ϊ������ѧ�������С�";

        if (me->query_skill("zhuangzi-wu", 1) < 150)
                return "���ׯ���軹���ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "΢΢һЦ����$N" HIY "��ͷ����"
                       "��������д����裬������\n�У����к��ѣ���"
                       "˵���漴һ����Х������һչ���貽����\n����"
                       "��ˮ���ʵ�����㣬�ٶȱ���쳣���ݡ�$N" HIY
                       "���������\n����貽��������̾���ѡ�\n" NOR,
                       me, this_object());

        command("smile");
        command("say ����ׯ���������������ʩչ��Ч�����ѡ�");
        tell_object(me, HIC "��ѧ���ˡ���������\n" NOR);

        if (me->can_improve_skill("dodge"))
                me->improve_skill("dodge", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("zhuangzi-wu"))
                me->improve_skill("zhuangzi-wu", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhuangzi-wu/hua", 1);
        me->add("gongxian", -1000);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/baihua-cuoquan/luan"))
                return "�����Ҳ����Ѿ��̸�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("baihua-cuoquan", 1) < 1)
                return "�����ٻ���ȭ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 80000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if ((int)me->query("max_neili") < 2000)
                return "���������Ϊ������ѧ�������С�";

        if (me->query_skill("baihua-cuoquan", 1) < 120)
                return "��İٻ���ȭ�����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "���˵�ͷ��˵�������Ҹ�"
                       "����ʾһ�飬��Ҫ��ϸ\n�����ˡ���˵��ֻ��$n" HIY
                       "�ٲ�����˫�ƽ��������Ʒ�\nȭӰ���ص�������"
                       "ʵ�ѱ档\n" NOR, me, this_object());

        command("smile");
        command("say ��һ�б��ǰٻ����ң����Կ�������ϲ�ȭ����");
        tell_object(me, HIC "��ѧ���ˡ��ٻ����ҡ���\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("baihua-cuoquan"))
                me->improve_skill("baihua-cuoquan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/baihua-cuoquan/luan", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/baihua-cuoquan/yi"))
                return "�����Ҳ����Ѿ��̸�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("baihua-cuoquan", 1) < 1)
                return "�����ٻ���ȭ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1000)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 100000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if ((int)me->query("max_neili") < 3000)
                return "���������Ϊ������ѧ�������С�";

        if ((int)me->query_skill("force") < 280)
                return "����ڹ���Ϊ������ѧ�������С�";

        if (me->query_skill("baihua-cuoquan", 1) < 150)
                return "��İٻ���ȭ�����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "΢΢һЦ��˵��������"
                       "���ˣ���ֻ��$n" HIY "����\n���䣬�漴���һ"
                       "����˫�Ʒ׷ɣ��������м���ӥצ������\n�ֲ�ȭ"
                       "���������ơ�����ȥ�����ƣ��ջ�ʱ����̫��ȭ��"
                       "��\n���ӳ£����޹��ɣ�����ǵ��������������"
                       "�ֺ룬������\n�ȡ�ֻ����$N" HIY "����������"
                       "��֪���롣\n" NOR, me, this_object());

        command("smile");
        command("say ��ٻ����׵ľ������һ�������֣�����ȥ���������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��ٻ����ס���\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("baihua-cuoquan"))
                me->improve_skill("baihua-cuoquan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/baihua-cuoquan/yi", 1);
        me->add("gongxian", -1000);

        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();

        if (me->query("can_perform/baihua-cuoquan/hong"))
                return "���ѽ�ȭ�������������㣬����ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("baihua-cuoquan", 1) < 1)
                return "�����ٻ���ȭ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 2500)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 150000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if ((int)me->query("max_neili") < 5000)
                return "���������Ϊ������ѧ�������С�";

        if (me->query_skill("baihua-cuoquan", 1) < 250)
                return "��İٻ���ȭ�����ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("zhanshen-xinjing", 1) < 250)
                return "���ս���ľ���Ϊ�������Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��$N" HIY "΢΢һЦ��̾��������"
                       "��������Ƿ���ȷ������\n�̳�����ȭ�������Ƚ�"
                       "�ܾ�˵�������ա�����֮ʱ��������\n����������"
                       "Ŀ�ӣ���ֹ֪�������У�������������ȴ����\n"
                       "���ϣ������Ȼ������$N" HIY "����������ã����"
                       "������ʦ������\n�����ǡ�ׯ�ӡ����Ҷ��⡭����"
                       "$n" HIY "Ц�����������Ҳ��\n���Ļ��ɣ�����"
                       "���ؾ���ȴ�����ڴˡ���˵�����ų���\n������"
                       "��Ϊ�٣�������΢����Ȼ�ѽ⣬����ί�أ��ᵶ��"
                       "����\nΪ֮�Ĺˣ�Ϊ֮�����־���������ã�����"
                       "������\n" NOR, me, this_object());

        command("smile");
        command("say �Ȿ����������������ȭ�������մ������㣬�������Ϊ֮��");
        tell_object(me, HIC "��ѧ���ˡ�ս����������\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("baihua-cuoquan"))
                me->improve_skill("baihua-cuoquan", 1500000);
        if (me->can_improve_skill("baihua-cuoquan"))
                me->improve_skill("baihua-cuoquan", 1500000);
        if (me->can_improve_skill("baihua-cuoquan"))
                me->improve_skill("baihua-cuoquan", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("zhanshen-xinjing"))
                me->improve_skill("zhanshen-xinjing", 1500000);
        if (me->can_improve_skill("zhanshen-xinjing"))
                me->improve_skill("zhanshen-xinjing", 1500000);
        if (me->can_improve_skill("zhanshen-xinjing"))
                me->improve_skill("zhanshen-xinjing", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/baihua-cuoquan/hong", 1);
        me->add("gongxian", -2500);

        return 1;
}

mixed ask_jiansuo()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_bad())
        {
                if (me->query("family/family_name") == "�컨��")
                        message_vision(CYN "$N" CYN "���һ������$n" CYN "����"
                                       "������Ϊ��˲��ܣ���Ȼ����������Ҫ����"
                                       "��������\n" NOR, this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��Цһ������$n" CYN "˵��"
                                       "������һ�����֮ͽ������̰ͼ�ҵ�������"
                                       "������\n" NOR, this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "�컨��")
                return "���ֲ������Ǻ컨����ֵܣ���������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ��������⽣��������";

        if (me->query("shen") < 80000)
                return "�������������û��������⽣�������Ҳ��̸ܽ��㡣";

        if (me->query_skill("jiandun-zhusuo", 1) < 120)
                return "��������������ûѧ�ã�������Ҳ�ǰ״";

        ob = find_object(JIANSUO);
        if (! ob) ob = load_object(JIANSUO);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�����������ڲ�������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ���������������Ѿ����ȥ�ˡ�";

                if (owner->query("family/family_name") == "�컨��")
                        return "�����������������Ǻ컨���" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�ҵĽ�����������������" + owner->query("name") +
                               "֮�֣���ȥ����ȡ�����ɣ�";
        }

        ob->move(this_object());
        message_vision(CYN "$N" CYN "΢΢һЦ���������⽣���������"
                       "��ȥ���������������壬�ͼ���񡣡�\n" NOR,
                       this_object(), me);
        command("give jiandun zhusuo to " + me->query("id"));
        return 1;
}
