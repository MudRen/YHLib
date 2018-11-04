#include <ansi.h>;
#include "etc.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_me();

void create()
{
        set_name("׿����", ({ "zhuo bufan", "zhuo", "bufan"}));
        set("gender", "����");
        set("title", "һ�ֻ۽�������");
        set("nickname", HIY "����" NOR);
        set("age", 37);
        set("long", @LONG
��ʮ����ǰ��һ�ֻ۽�������ʦͽ��ͯ��ɱ��
���⣬��ʱ׿�������ڸ������������ѣ��Ӵ�
��Ҳ���һ�ȥ���ӵ�����ɽ�л�Ƨ����֮�ؿ�
�н����������е���ǰ��������������һ����
��������������ʮ���꣬���ڽ�����ɣ�����
�����޵С�
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 2200);
        set("max_jing", 2200);
        set("neili", 4800);
        set("max_neili", 4800);
        set("jiali", 150);
        set("combat_exp", 2200000);

        set_skill("force", 220);
        set_skill("zixia-shengong", 220);
        set_skill("sword", 240);
        set_skill("zhougong-jian", 240);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("strike", 180);
        set_skill("liuyang-zhang", 180);
        set_skill("parry", 220);
        set_skill("martial-cognize", 220);
        set_skill("literate", 180);

        map_skill("force", "zixia-shengong");
        map_skill("sword", "zhougong-jian");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "zhougong-jian");
        map_skill("strike", "liuyang-zhang");

        prepare_skill("strike", "liuyang-zhang");

        set("inquiry", ([
                "��â"     : (: ask_me :),
                "�ܹ���"   : "�������µ�һ������",
                "����"     : "�ۿ��֣���Ȼ�������������ӵ�һ���������۽�����������ҡ�",
                "��ɽͯ��" : "��ɱ����һ�ֻ۽�������ʦͽ���ҿ��������磡",
                "����"     : "�����������չ��µ�����������ȫ���������",
                "������"   : "�����������չ��µ�����������ȫ���������",
                "����"     : "�ҵ��ܹ���������˫������������û�ڶ����ܹ��й���",
        ]));

        create_family("һ�ֻ۽���", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���չ�")
        {
                command("killair");
                command("say ����ʲô����������ϰ�Ҿ���Ľ�����");
                return -1;
        }

        if (ob->query("family/master_id") != "xuzhu zi")
        {
                command("hmm");
                command("say ���������չ�����ֲ�����˵����");
                return -1; 

        }

        if (skill != "zhougong-jian" && skill != "sword")
        {
                command("hmm");
                command("say �����书�Ҳ����ڡ�");
                return -1;
        }

        if (skill == "sword" && ob->query_skill("sword", 1) > 179)
        {
                command("hmm");
                command("say ���ˣ�ʣ�µĽ����Լ�ȥ�о���");
                return -1;
        }

        if (! ob->query_temp("can_learn/zhuobufan"))
        {
                command("nod2");
                command("say ��Ȼ�����Ȥ�����������ĵ��ӣ��Ҿͽ��������ܹ�����");
                ob->set_temp("can_learn/zhuobufan", 1);
        }
        return 1;
}

mixed ask_me()
{
        object me;

        me = this_player();
        if (me->query("can_perform/zhougong-jian/mang"))
                return "���Ѿ�˵�ù����ˣ�����Ҿ������ݡ�";

        if (me->query("family/family_name") != "���չ�" &&
           me->query("family/family_name") != "һ�ֻ۽���")
                return "�ߣ���֪�����⻰��ʲô��˼��";

        if (me->query_skill("zhougong-jian", 1) < 1)
                return "���ܹ�����δ����������̸ʲô���С�";

        if (me->query("family/family_name") == "���չ�" &&
           me->query("gongxian") < 1000)
                return "����������ô������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 200)
                return "����ڹ���������������ʲô������";

        if ((int)me->query("max_neili", 1) < 2200)
                return "���������������������ʲô������";

        if (me->query_skill("zhougong-jian", 1) < 140)
                return "����ܹ�����򻹲��Զ���ٻ�ȥ������";

        message_vision(HIY "$n" HIY "�����𻰣��γ������彣������һ"
                       "ͦ��������ͻȻ��\n��������²�������â������"
                       "������磬һչ���߷緶��$N" HIY "\n��Ŀ���"
                       "ʱһ�����ƺ�������ʲô��\n" NOR, me,
                       this_object());
        command("hmm");
        command("say ������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ���â����\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("zhougong-jian"))
                me->improve_skill("zhougong-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhougong-jian/mang", 1);
        if (me->query("family/family_name") == "���չ�")
                me->add("gongxian", -1000);
        return 1;
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("smile");
        command("say ���ã����ã�");
        command("say ��һ�ֻ۽���������ͽ�������Ϸ�������㡣");
        command("recruit " + ob->query("id"));
}

void unconcious()
{
        die();
}
