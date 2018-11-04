#include <ansi.h>;
#include "etc.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_me();

void create()
{
        set_name("������", ({ "zuo zimu", "zuo", "zimu"}));
        set("gender", "����");
        set("title", "�������ɶ�������");
        set("age", 54);
        set("long", @LONG
������������ɶ������������£�ֻ������ʮ
������ͣ�������������������硣��������
��һ����������ؽ�����ʵ�˵á�
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 3800);
        set("max_qi", 3800);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 120);
        set("combat_exp", 2000000);

        set_skill("force", 180);
        set_skill("wuliang-xinfa", 180);
        set_skill("dahai-wuliang", 180);
        set_skill("dodge", 180);
        set_skill("feiyan-zoubi", 180);
        set_skill("sword", 180);
        set_skill("wuliang-jian", 180);
        set_skill("unarmed", 160);
        set_skill("liuhe-quan", 160);
        set_skill("claw", 160);
        set_skill("da-qinna", 160);
        set_skill("parry", 180);
        set_skill("martial-cognize", 160);
        set_skill("literate", 160);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "dahai-wuliang");
        map_skill("sword", "wuliang-jian");
        map_skill("parry", "wuliang-jian");
        map_skill("unarmed", "liuhe-quan");
        map_skill("claw", "da-qinna");

        prepare_skill("claw", "da-qinna");

        set("inquiry", ([
                "Ǭ������" : (: ask_me :),
                "������"   : "�����������չ��µ�����������ȫ���������",
                "����"     : "�����������չ��µ�����������ȫ���������",
        ]));

        create_family("��������", 22, "��������");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qian" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���չ�")
        {
                command("say �����ز���ʶ����̸���ϡ�ָ�̡����֣�");
                return -1;
        }

        if (ob->query("family/master_id") != "xuzhu zi")
        {
                command("en");
                command("say ������㻹��ȥ����ʦ��ѧ���ˡ�");
                return -1; 

        }

        if (skill != "wuliang-jian" && skill != "sword")
        {
                command("say ��ֻ������һЩ���������֪ʶ�����²�ѧ�����ˡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/zuozimu"))
        {
                command("say ��Ȼ�������������Ե��ˣ���Ҳ�͹�����������ˡ�");
                ob->set_temp("can_learn/zuozimu", 1);
        }
        return 1;
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/wuliang-jian/qian"))
                return "���²����Ѿ�������������";

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "��������")
                return "�����ز���ʶ����֪���´˻���ʲô��˼��";

        if (me->query_skill("wuliang-jian", 1) < 1)
                return "����������������δ��ѧϰ����̸���п��ԣ�";

        if (me->query("family/family_name") == "���չ�" &&
           me->query("gongxian") < 300)
                return "�����������������ô������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬���������С�";

        if (me->query_skill("wuliang-jian", 1) < 100)
                return "��������������δ�������������С�";

        message_vision(HIY "$n" HIY "���˵�ͷ���γ���������ĳ�"
                       "�����ֱ�һ�񣬵���\n����$N" HIY "����"
                       "�ৡ������Ľ������Ľ�һ���ǳɣ�ȥ�Ƽ�\n"
                       "�죬ȫȻ����$N" HIY "������ҪѨ��\n" NOR,
                       me, this_object());
        command("nod");
        command("say ���������������ľ��裬�Ժ��Ҫ�ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�Ǭ����������\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("wuliang-jian"))
                me->improve_skill("wuliang-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/wuliang-jian/qian", 1);
        if (me->query("family/family_name") == "���չ�")
                me->add("gongxian", -300);
        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("nod2");
        command("say �����Ժ�͸����Һ��ˡ�");
        command("recruit " + ob->query("id"));
}

void unconcious()
{
        die();
}
