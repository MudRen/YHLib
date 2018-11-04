#include <ansi.h>

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        set_name("����", ({ "a da", "a", "da" }));
        set("long", @LONG
�˱��񽣷����ױ���ؤ���Ĵ���֮�ף�����
֮��������������ֻ����������죬��������
�߰����ֱ�һ�㣬����ϵ��������š�ʮ��
��ǰ��˵����Ⱦ�ز���������ʱ���˶�����ϧ��
������������������
LONG);
        set("title", "ؤ���Ĵ���֮��");
        set("nickname", WHT "�˱���" NOR);
        set("gender", "����");
        set("age", 68);
        set("attitude", "peaceful");
        set("class", "beggar");

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);        
        set("max_qi", 5800);
        set("max_jing", 5800);
        set("neili", 6200);
        set("max_neili", 6200);
        set("jiali", 250);
        set("combat_exp", 3500000);
        set("score", 500000);
        set("shen_type", -1);

        set_skill("force", 300);
        set_skill("jiaohua-neigong", 280);
        set_skill("huntian-qigong", 300);
        set_skill("dodge", 280);
        set_skill("feiyan-zoubi", 280);
        set_skill("sword", 300);
        set_skill("guanri-jian", 300);
        set_skill("pichen-jian", 300);
        set_skill("parry", 280);
        set_skill("unarmed", 280);
        set_skill("changquan", 280);
        set_skill("staff", 280);
        set_skill("jiaohua-bangfa", 280);
        set_skill("dagou-bang", 280);
        set_skill("strike", 280);
        set_skill("xianglong-zhang", 280);
        set_skill("begging", 200);
        set_skill("checking", 200);
        set_skill("martial-cognize", 300);

        map_skill("force", "huntian-qigong");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("sword", "guanri-jian");
        map_skill("parry", "guanri-jian");
        map_skill("unarmed", "changquan");
        map_skill("staff", "dagou-bang");
        map_skill("strike", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

        set("inquiry", ([
                "������" : (: ask_skill1 :),
                "������" : (: ask_skill2 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fen" :),
                (: perform_action, "sword.guan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        create_family("ؤ��", 17, "����");

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/b/yitian/npc/obj/jian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say �߿����Ҳ���ͽ��");
}

int accept_fight(object ob)
{
        command("sneer");
        command("say ������");
        return 0;
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "ؤ��")
        {
                command("hmm");
                command("say ������");
                return -1;
        }

        if (ob->query("family/master_id") != "ma dayuan"
           && ob->query("family/master_id") != "hong qigong"
           && ob->query("family/beggarlvl") < 7)
        {
                command("sneer");
                command("say �㻹���䡣\n");
                return -1; 
        }

        if (skill != "sword"
           && skill != "guanri-jian"
           && skill != "pichen-jian")
        {
                command("hmm");
                command("say ��ֻ�����ֽ���������ѧ�͹��ɡ�");
                return -1;
        }

        if (skill == "sword" && ob->query_skill("sword", 1) > 179)
        {
                command("say ���ˣ�ʣ�µ��Լ�ȥ����");
                return -1;
        }

        if (! ob->query_temp("can_learn/ada"))
        {
                command("sigh");
                command("say Ҳ�գ�Ҳ�ա�");
                command("say ��ٳ��͹������׽���������ƽ��ѧ���ʹ�������ˡ�");
                ob->set_temp("can_learn/ada", 1);
        }
        return 1;
}

mixed ask_skill1()
{
        object me;
        me = this_player();

        if (me->query("can_perform/pichen-jian/ao"))
                return "�Լ�ȥ����ɣ�����Ϊ֮��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ҹ�����";

        if (me->query("family/master_id") != "ma dayuan"
           && me->query("family/master_id") != "hong qigong"
           && me->query("family/beggarlvl") < 7)
                return "��ʲôʱ��˵��Ҫ���㣿";

        if (me->query_skill("pichen-jian", 1) < 1)
                return "��ѧ���ٳ������𣿲�ѧ�������С�";

        if (me->query("gongxian") < 300)
                return "���ڰ��ں�����Ϊ���ԣ��������˲�ֵ����������";

        if (me->query_skill("pichen-jian", 1) < 100)
                return "��ıٳ������������ң�Ҫ��������";

        message_sort(HIY "\n$n" HIY "һ����̾��ҡͷ������Ҳ�գ�Ҳ"
                     "�գ����������˵��㽫$N" HIY "�е�һ�Ե�Ƨ"
                     "������������$N" HIY "���ߵ����ֹ��˰��죬��"
                     "ʱ����ָ�����������Ȼ���ʾ���У���ʾȫΪ�ٳ�"
                     "�������еľ�΢Ҫ�裬$N" HIY "�����������"
                     "\n\n" NOR, me, this_object());

        command("sigh");
        command("say ��ú�Ŭ���ɣ������ҡ�������");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("pichen-jian"))
                me->improve_skill("pichen-jian", 1500000);

        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pichen-jian/ao", 1);
        me->add("gongxian", -300);
        return 1;
}

mixed ask_skill2()
{
        object me;
        me = this_player();

        if (me->query("can_perform/guanri-jian/fen"))
                return "�Լ�ȥ����ɣ�����Ϊ֮��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ҹ�����";

        if (me->query("family/master_id") != "ma dayuan"
           && me->query("family/master_id") != "hong qigong"
           && me->query("family/beggarlvl") < 7)
                return "��ʲôʱ��˵��Ҫ���㣿";

        if (me->query_skill("guanri-jian", 1) < 1)
                return "��ѧ�����ս����𣿲�ѧ�������С�";

        if (me->query("gongxian") < 1200)
                return "���ڰ��ں�����Ϊ���ԣ��������˲�ֵ����������";

        if (me->query_skill("guanri-jian", 1) < 150)
                return "��Ĺ��ս����������ң�Ҫ��������";

        if ((int)me->query("max_neili") < 2000)
                return "��������Ϊ������ѧ������һ�С�";

        message_sort(HIY "\n$n" HIY "һ����̾��ҡͷ������Ҳ�գ�Ҳ"
                     "�գ����������˵��㽫$N" HIY "�е�һ�Ե�Ƨ"
                     "������������$N" HIY "���ߵ����ֹ��˰��죬��"
                     "ʱ����ָ�����������Ȼ���ʾ���У���ʾȫΪ�ٳ�"
                     "�������еľ�΢Ҫ�裬$N" HIY "�����������"
                     "\n\n" NOR, me, this_object());

        command("sigh");
        command("say ��ú�Ŭ���ɣ������ҡ�������");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("guanri-jian"))
                me->improve_skill("guanri-jian", 1500000);

        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/guanri-jian/fen", 1);
        me->add("gongxian", -1200);
        return 1;
}
