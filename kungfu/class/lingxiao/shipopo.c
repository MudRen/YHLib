#include <ansi.h>
#include "lingxiao.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("ʷ����", ({"shi popo", "shi", "popo"}));
        set("long", "����ѩɽ�������˰����ڵ����ӣ���˵����������\n"
                    "�ò��ϣ�ʮ��ǰ���𡰽���һ֦����ʷС��������\n"
                    "����ȴ�����˲�֪��\n");
        set("title", "�����ɿ�ɽ��ʦ");
        set("gender", "Ů��");
        set("age", 58);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 4200);
        set("max_jing", 3500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 200);
        set("combat_exp", 2000000);

        set("inquiry",([
                "���汩��" : (: ask_skill1 :),
        ]));

        set_skill("force", 220);
        set_skill("xueshan-neigong", 220);
        set_skill("wuwang-shengong", 180);
        set_skill("dodge", 220);
        set_skill("taxue-wuhen", 220);
        set_skill("cuff", 220);
        set_skill("lingxiao-quan", 220);
        set_skill("strike", 220);
        set_skill("piaoxu-zhang", 220);
        set_skill("sword", 200);
        set_skill("hanmei-jian", 200);
        set_skill("yunhe-jian", 200);
        set_skill("xueshan-jian", 200);
        set_skill("blade", 240);
        set_skill("jinwu-daofa", 240);
        set_skill("parry", 200);
        set_skill("literate", 200);
        set_skill("martial-cognize", 180);

        map_skill("force", "wuwang-shengong");
        map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "lingxiao-quan");
        map_skill("strike", "piaoxu-zhang");
        map_skill("sword", "xueshan-jian");
        map_skill("blade", "jinwu-daofa");
        map_skill("parry", "jinwu-daofa");

        prepare_skill("strike", "piaoxu-zhang");
        prepare_skill("cuff", "lingxiao-quan");

        create_family("������", 5, "���ŷ���");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.chi" :),
                (: perform_action, "cuff.jue" :),
                (: perform_action, "strike.piao" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();
        
        carry_object("/clone/weapon/chaidao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if (me->query("family/master_name") == "������" ||
           me->query("family/master_name") == "����")
        {
                command("say �٣����Ȼ�����Ϲ�С��Ϊʦ������������������������");
                return;
        }

        if ((int)me->query("shen") < 10000)
        {
                command("say ���书��������֮�ˣ����߿���");
                return;
        }

        if ((int)me->query("combat_exp") < 200000)
        {
                command("say �����ڽ�������̫ǳ�����Ƕ�������������ɡ�");
                return;
        }

        if ((int)me->query_skill("xueshan-neigong", 1) < 100)
        {
                command("say �㱾�ŵ��ڹ��ķ�̫���������֮���������ҡ�");
                return;
        }

        command("haha");
        command("say �����Ҿ������㣬����������������ձ���ʤ���Ǹ��Ϲ�");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/jinwu-daofa/chi"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ����ҹ�����";

        if (me->query_skill("jinwu-daofa", 1) < 1)
                return "�������ڵ�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "����ѩɽ����µµ��Ϊ���������ܷ��Ĵ��������";

        if (me->query_skill("force") < 150)
                return "����ڹ�����̫ǳ���������������ҡ�";

        if (me->query_skill("jinwu-daofa", 1) < 120)
                return "��Ľ��ڵ���������������Ȼ������˼���ҡ�";

        message_vision( HIY "$n" HIY "�����������н�������ز���Ҳ"
                       "�㲻��������\n����ѩɽ�������ƽ�֮������"
                       "�ɼ����ˡ�ѩɽ�ɽ�����\n��ʮ���У��ҽ�����"
                       "�书����ʤ��һ�ȴ����ʮ���С�\n������ʮ"
                       "����������ʮ���У����һ������ϸ�ˣ���˵\n"
                       "�Űγ�����񵶴��϶���ֱ���������ֵ�������"
                       "ʹ����\n֮ʱ�����Ծ���գ�����ֱ��������"
                       "���ֽ̽������\n������η����Է��ӶݵĿ�϶"
                       "��������������$N" HIY "��$N" HIY "��\n˼��"
                       "�Σ�����ʩΪ������Ծ�𣬰���лӵ�ֱ������"
                       "��\nһ������������������ߣ��������ǳ�ɳ��"
                       "��ܲ���\nҶ�����缤�����Ŷ��裬��Ȼ����"
                       "���ˡ�\n" NOR, me, this_object());
        command("heng");
        command("say ��һ�пɾ���ѩɽ���������Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����汩������\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("jinwu-daofa"))
                me->improve_skill("jinwu-daofa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jinwu-daofa/chi", 1);
        me->add("gongxian", -800);
        return 1;
}
