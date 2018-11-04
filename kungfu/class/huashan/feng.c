inherit NPC;
inherit F_MASTER;

#include <ansi.h>

mapping po_type = ([ "�ƽ�ʽ" : ({ "sword" }),
                     "�Ƶ�ʽ" : ({ "blade" }),
                     "��ǹʽ" : ({ "staff" }),
                     "�Ʊ�ʽ" : ({ "hammer", "club", "dagger" }),
                     "����ʽ" : ({ "whip" }),
                     "����ʽ" : ({ "unarmed", "finger", "claw",
                                   "strike", "hand", "cuff" }),
                     "�Ƽ�ʽ" : ({ "throwing" }),
                     "����ʽ" : ({ "force" }), ]);

int check_skill(string skill);
mixed teach_lonely_sword();

void create()
{
        set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
        set("title", "��ɽ���ڳ���");
        set("nickname", HIW "��������" NOR);
        set("long", @LONG
����ǵ������𽭺��Ļ�ɽ���޷��������
�����ۣ��������������ֽ������ݳ���ü��
��һֱ������һ�ɵ�����������ɫ����Ȼ�Ե�
��Ľ���֮��һֱ����������
LONG);
        set("gender", "����");
        set("age", 68);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 6000);
        set("max_jing", 5000);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jiali", 200);
        set("combat_exp", 4000000);

        set_skill("force", 300);
        set_skill("zixia-shengong", 300);
        set_skill("huashan-xinfa", 280);
        set_skill("dodge", 300);
        set_skill("feiyan-huixiang", 300);
        set_skill("parry", 320);
        set_skill("sword", 320);
        set_skill("dugu-jiujian", 320);
        set_skill("strike", 280);
        set_skill("hunyuan-zhang", 280);
        set_skill("cuff", 280);
        set_skill("poyu-quan", 280);
        set_skill("literate", 280);
        set_skill("martial-cognize", 320); 

        map_skill("cuff", "poyu-quan");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");
        map_skill("strike", "hunyuan-zhang");

        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");

        create_family("��ɽ����", 0, "����");

        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.qi" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set("can_perform/dugu-jiujian", ({ "sword", "blade", "staff",
                                           "hammer", "club", "dagger",
                                           "whip", "unarmed", "finger",
                                           "claw", "strike", "hand",
                                           "cuff", "force", "throwing" }));

        set("no_teach", ([
                "dugu-jiujian" : (: teach_lonely_sword :),
        ]));
        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

mixed teach_lonely_sword()
{
        object me;

        me = this_player();
        if (me->query_skill("dugu-jiujian", 1) > 100)
        {
                if (me->query_temp("feng_has_told"))
                {
                        command("say ���Լ��ú����ɣ�");
                        return -1;
                }

                command("pat " + me->query("id"));
                command("say ���׽���Ҫ���Լ��������Ժ����Լ�������аɣ�");
                me->set_temp("feng_has_told", 1);
                return -1;
        }

        if (me->query_temp("learnd_lonely_sword"))
                return 0;

        me->set_temp("learnd_lonely_sword", 1);
        command("say �ܺã��ܺá����Ž������ڽ��⣬������ʽ��");
        command("say ����ѧϰ���в��ɾ�������ʽ��");
        return 0;
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name") == "��ɽ��"
           || ob->query("family/family_name") == "��ɽ����")
        {
                command("say �߿�����ɽ�ĵ�����һ�Ų�����");
                return;
        }

        command("say �Ҳ���ͽ������������ɡ�");
}

int check_skill(string skill)
{
        if (skill != "sword" && skill != "dugu-jiujian")
        {
                command("say ��ֻ������������ѧ��ѧ������ѧ�����ˡ�");
                return -1;
        }
        return 1;
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("can_learn/feng/dugu-jiujian"))
                return check_skill(skill);

        if (ob->query("can_learn/feng/sword")
           && skill != "dugu-jiujian")
        {
                if (skill == "sword")
                        return 1;

                command("say �������������ǿ������㣬�ٸ������£�");
                return -1;
        }

        if (ob->query_temp("have_asked_feng"))
        {
                command("say ���������");
                return -1;
        }

        if (ob->query("character") == "���ռ�թ"
           || ob->query("character") == "�ĺ�����")
        {
                command("heng");
                command("say �������ľ͸��ҹ���");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        if (ob->query("character") == "��������")
        {
                command("hmm");
                command("say �����Բ���������ȴ���ʺ���ϰ���׽�����");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        if (ob->query("shen") < -10000
           || ob->query("shen") > 10000
           || ob->query("weiwang") > 10000)
        {
                command("say �ҷ�ĳ�Ӳ��ͳ�����ʿ�򽻵������߰ɡ�");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        if (ob->query("int") < 30)
        {
                command("sneer");
                command("say �������ͷ�죬߯���˵㣬�߰ɡ�");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        if (ob->query("int") < 35)
        {
                command("look " + ob->query("id"));
                command("say �㵹�ǲ��㱿���е�С���������������ǲ��Զ����");
                ob->set_temp("have_asked_feng", 1);
                return -1;
        }

        if (ob->query_skill("sword", 1) < 100)
        {
                command("say �����䲻��������ĶԽ��������Ҳδ��̫���ˡ�");
                return -1;
        }

        if (ob->query("int") < 39)
        {
                if (skill == "sword")
                {
                        command("say �ðɣ��Ҿͽ���һ����ڽ�����֪ʶ��");
                        ob->set("can_learn/feng/sword", 1);
                        return 1;
                }

                if (skill != "dugu-jiujian")
                {
                        command("say ��ֻ�ὣ����Ҫѧ�����ı����ұ��ʦ��ȥ�ɣ�");
                        return -1;
                }

                command("sigh");
                command("say ���������Ǵ�����������¾Ž����ǲ�֮��Զ��");
                return -1;
        }

        if (check_skill(skill) == -1)
                return -1;

        message_sort(HIW "\n$N" HIW "���˵�ͷ����$n" HIW "˵��������"
                     "�ã����á���Ȼ�Ҳ���ͽ��������������ʵ�ڲ���"
                     "�ʹ���һ�㽣���ɡ����׶��¾Ž�����Ϊ���ƣ�����"
                     "�����ܾ�ʽ�������ƽ�ʽ���Ƶ�ʽ����ǹʽ���Ʊ�ʽ"
                     "������ʽ������ʽ���Ƽ�ʽ������ʽ�����һһ�ֽ�"
                     "����������\n" NOR, this_object(), ob);

        tell_object(ob, HIC "\n������ͬ�⴫���㡸���¾Ž�����\n" NOR);
        ob->set("can_learn/feng/dugu-jiujian", 1);
        ob->improve_skill("martial-cognize", 1500000);
        return 1;
}

int accept_ask(object me, string topic)
{
        string *learned, *try_to;

        if (! topic || undefinedp(try_to = po_type[topic]))
                return 0;

        if (! (int)me->query_skill("dugu-jiujian", 1))
        {
                command("say �����¾Ž�ô���������������");
                return 1;
        }

        learned = me->query("can_perform/dugu-jiujian");
        if (! arrayp(learned))
                learned = ({ });
        if (member_array(try_to[0], learned) != -1)
        {
                command("say �㲻���Ѿ�ѧ��" + topic + "��ô��");
                return 1;
        }

        command("say �ðɣ�" + topic + "��Ҫ����Ҫ����ϸ�ˡ�");
        if (me->query("potential") - me->query("learned_points") < 10)
        {
                me->set("learned_points", me->query("potential"));
                tell_object(me, HIG "�����˷�����Ľ̵����ľ���ã����"
                                "����Ǳ�ܲ����ˡ�\n" NOR);
                return 1;
        }

        me->add("learned_points", 10);
        if (random(2))
        {
                write(HIY "�����˷�����Ľ̵��������ĵá�\n" NOR);
                return 1;
        }

        learned -= try_to;
        learned += try_to;
        me->set("can_perform/dugu-jiujian", learned);
        tell_object(me, HIC "��ѧ���˶��¾Ž�֮��" + topic + "����\n");
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("dugu-jiujian"))
                me->improve_skill("dugu-jiujian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        return 1;
}
