#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();

void create()
{
        set_name("�޳�����", ({"wuchen daozhang", "wuchen", "daozhang"}));
        set("title", "�컨�������");
        set("nickname", HIR "׷�������" NOR );
        set("gender", "����");
        set("age", 52);
        set("long", "�޳���������ʱ�켣���֣��ٸ���ƶ������\n"
                    "�������ް�������һ�������֣���������\n"
                    "���ˡ�ƾ����������һ��׷�����������\n"
                    "�����󱻺컨���ϵ�������ͤ��������˸�\n"
                    "�֡�\n");
        set("attitude", "peaceful");
        set("class", "taoist");
        set("shen_type", 1);
        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 5500);
        set("max_qi", 5500);
        set("jing", 4200);
        set("max_jing", 4200);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 180);
        set("combat_exp", 4000000);
        set("score", 1000000);

        set_skill("force", 240);
        set_skill("honghua-xinfa", 240);
        set_skill("tianchi-neigong", 240);
        set_skill("unarmed", 260);
        set_skill("lianhuan-mizongtui", 260);
        set_skill("dodge", 260);
        set_skill("yanzi-chuanyun", 240);
        set_skill("zhuihun-jian", 260);
        set_skill("parry", 240);
        set_skill("sword", 260);
        set_skill("taoism", 150);
        set_skill("martial-cognize", 220);
        set_skill("literate", 200);

        map_skill("force"  , "tianchi-neigong");
        map_skill("unarmed", "lianhuan-mizongtui");
        map_skill("dodge"  , "lianhuan-mizongtui");
        map_skill("parry"  , "zhuihun-jian");
        map_skill("sword"  , "zhuihun-jian");

        create_family("�컨��", 4, "����");

        set("inquiry", ([
                "��������" : (: ask_skill1 :),
                "׷�����" : (: ask_skill2 :),
                "����ɲ��" : (: ask_skill3 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhu" :),
                (: perform_action, "sword.zhui" :),
                (: perform_action, "unarmed.lian" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
    
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < 20000)
        {
                command("say ������������ˣ��Ҳ������㡣");
                return;
        }

        if ((int)me->query("combat_exp") < 350000)
        {
                command("say ��Ľ�������̫ǳ�����������㣬����Ҳ������Ϊ��");
                return;
        }

        if ((int)me->query_skill("honghua-xinfa", 1) < 80)
        {
                command("say ���ڹ�������̫���ȥ�ѱ��ŵ��ķ�������������");
                return;
        }

        if ((int)me->query_skill("sword", 1) < 80)
        {
                command("say ��Ľ�������������������δ��㾫��Ľ�����");
                return;
        }

        command("haha");
        command("say ��Ȼ��ˣ������Ժ�͸����Һ��ˡ�");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/lianhuan-mizongtui/lian"))
                return "���а������Ѿ��̸�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("lianhuan-mizongtui", 1) < 1)
                return "�������������ȶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 600)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 50000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("dodge") < 150)
                return "����Ṧ����㣬ѧ�������С�";

        if (me->query("max_neili") < 1800)
                return "���������Ϊ������ѧ�������С�";

        if (me->query_skill("lianhuan-mizongtui", 1) < 120)
                return "������������Ȼ����ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "��Ц��������$N" HIY "˵�������벻��"
                       "����ȷ���Ȼ���������\n�裬�����Ҵ��������ֺη�"
                       "����˵�գ�$n" HIY "�漴�ڿ����ƣ���\n������ʾ����"
                       "��\n" NOR, me, this_object());

        command("haha");
        command("say �Բ���֮��һ������Ҫʹ��ɱ�֣�˿����Ҫ���顣");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);

        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("lianhuan-mizongtui"))
                me->improve_skill("lianhuan-mizongtui", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/lianhuan-mizongtui/lian", 1);
        me->add("gongxian", -600);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhuihun-jian/zhui"))
                return "�Լ���ȥ��������Ҿ�����û�꣡";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("zhuihun-jian", 1) < 1)
                return "����׷���������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 35000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if (me->query_skill("force") < 120)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 800)
                return "���������Ϊ������ѧ�������С�";

        if (me->query_skill("zhuihun-jian", 1) < 100)
                return "���׷������������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "���˵�ͷ���ӻ�������ȡ����һ��"
                       "���ף�ָ������һ�ζ�\n$N" HIY "ϸ˵���ã�$N"
                       HIY "һ����һ�ߵ�ͷ��\n" NOR, me, this_object());

        command("nod");
        command("say ���������ڵĵ���֮�������Ƹ���ʵȴ����������");
        tell_object(me, HIC "��ѧ���ˡ�׷���������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("zhuihun-jian"))
                me->improve_skill("zhuihun-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhuihun-jian/zhui", 1);
        me->add("gongxian", -300);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhuihun-jian/zhu"))
                return "��˵���棬�Ͽ�ȥ�������Ժ���������Ϳ������ˡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("zhuihun-jian", 1) < 1)
                return "����׷���������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1200)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 80000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if (! me->query("can_perform/zhuihun-jian/zhui"))
                return "�������ɡ�׷��������ݻ�����������ͨ�����к������ɡ�";

        if (me->query_skill("force") < 200)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query("max_neili") < 1800)
                return "���������Ϊ������ѧ�������С�";

        if (me->query_skill("zhuihun-jian", 1) < 160)
                return "���׷������������ò����ң��Լ���ȥ���������ɣ�";

        message_vision( HIY "$n" HIY "������$N" HIY "��һ������漴��Ц��"
                        "�����޵�������������\n�����Ҵ������У���Ҫ��"
                        "���ˣ���$n" HIY "�������䣬�漴��һ��\n��Х����"
                        "�г���������ֹ���ų�����⻪������������ʱֻ��ʯ"
                        "м\n�ɽ���ֻ�����͡���һ����$N" HIY "�������ʯ"
                        "�������ѱ�$n" HIY "����\n�����������Ľ�â�ᴩ��"
                        "ש����������ڴֵĴ󶴣�ֱ����$N" HIY "Ŀ��\n��"
                        "��������˵����һ�仰��\n" NOR, me, this_object());

        command("haha");
        command("say ����������ƽ������Ҳ��֪����ɱ�˶��ټ��֮ͽ��");
        tell_object(me, HIC "��ѧ���ˡ�����ɲ�񡹡�\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("zhuihun-jian"))
                me->improve_skill("zhuihun-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhuihun-jian/zhu", 1);
        me->add("gongxian", -1200);
        return 1;
}

