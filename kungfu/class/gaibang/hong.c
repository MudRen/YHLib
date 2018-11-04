#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

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

mixed ask_me();

#define YUZHU    "/clone/lonely/yuzhu"

int try_to_learn_ds();
int try_to_learn_db();

void create()
{
        object ob;
        set_name("���߹�", ({ "hong qigong", "hong", "qigong" }));
        set("long", @LONG
������ؤ���ʮ���ΰ������ųƾ�ָ��ؤ�ĺ�
�߹���ү�ӡ�ֻ������ü�԰ף�������������
���ѣ�ģ������������������Ŀ����磬�Ե�
������Ȼ����ŭ��������
LONG);
        set("nickname", HIW "��ؤ" NOR);
        set("gender", "����");
        set("class", "beggar");
        set("age", 75);
        set("attitude", "peaceful");

        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 6500);
        set("max_jing", 55000);
        set("neili", 7500);
        set("max_neili", 7500);
        set("jiali", 200);
        set("combat_exp", 4000000);
        set("score", 400000);
        set("shen_type", 1);

        set_skill("force", 340);
        set_skill("jiaohua-neigong", 320);
        set_skill("huntian-qigong", 340);
        set_skill("yijin-duangu", 320);
        set_skill("dodge", 320);
        set_skill("feiyan-zoubi", 320);
        set_skill("xiaoyaoyou", 320);
        set_skill("unarmed", 320);
        set_skill("changquan", 320);
        set_skill("jueming-tui", 320);
        set_skill("hand", 280);
        set_skill("chansi-shou", 280);
        set_skill("claw", 280);
        set_skill("suohou-gong", 280);
        set_skill("strike", 340);
        set_skill("xianglong-zhang", 340);
        set_skill("tongchui-zhang", 320);
        set_skill("liuhe-zhang", 320);
        set_skill("parry", 320);
        set_skill("staff", 340);
        set_skill("dagou-bang", 340);
        set_skill("jiaohua-bangfa", 320);
        set_skill("fengmo-zhang", 320);
        set_skill("fumo-zhang", 320);
        set_skill("throwing", 300);
        set_skill("pomie-jinzhen", 300);
        set_skill("begging", 300);
        set_skill("checking", 300);
        set_skill("literate", 240);
        set_skill("martial-cognize", 320);

        map_skill("throwing", "pomie-jinzhen");
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "changquan");
        map_skill("hand", "chansi-shou");
        map_skill("claw", "suohou-gong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");
        map_skill("strike", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

        set("no_teach", ([
                "xianglong-zhang" : (: try_to_learn_ds :),
                "dagou-bang"      : (: try_to_learn_db :),
        ]));

        create_family("ؤ��", 17, "����");

        set("inquiry", ([
                "������"   : (: ask_me :),
                "���ξ�"   : (: ask_skill1 :),
                "����ɽ�" : (: ask_skill2 :),
                "���־�"   : (: ask_skill3 :),
                "���־�"   : (: ask_skill4 :),
                "���־�"   : (: ask_skill5 :),
                "���־�"   : (: ask_skill6 :),
                "�����޹�" : (: ask_skill7 :),
                "˫��ȡˮ" : (: ask_skill8 :),
                "�𾪰���" : (: ask_skill9 :),
                "��������" : (: ask_skill10 :),
                "�����л�" : (: ask_skill11 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.qu" :),
                (: perform_action, "strike.zhen" :),
                (: perform_action, "strike.fei" :),
                (: perform_action, "dodge.xian" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.chuo" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.tian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
/*
        if (clonep())
        {
                ob = find_object(YUZHU);
                if (! ob) ob = load_object(YUZHU);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                }
        }*/
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;

        if (ob->query("combat_exp") < 400000)
        {
                command("hmm");
                command("say ��ľ�����ô����ܸ���ѧʲô��");
                return;
        }

        if (ob->query_str() < 40 && ob->query_int() < 40
           && ob->query_con() < 40 && ob->query_dex() < 40)
        {
                command("say ��˵���������Ҳ���У��Խ�Ҳ����⣬���ܺ���ѧʲô��");
                return;
        }

        if ((int)ob->query_skill("force") < 180)
        {
                command("hmm");
                command("say ����ڹ����̫���ˣ��Ⱥú������������ҡ�");
                return;
        }

        if ((int)ob->query("max_neili") < 2000)
        {
                command("hmm");
                command("say �����ǵ���������ѧ����ʲô�ϳ��书��");
                return;
        }
        command("say ����ƽʱ�ù�Ŭ���������Ͻл��������㡣");
        command("say �Ժ�ú��������ɱ���Ҷ�����");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
}

int recognize_apprentice(object me, string skill)
{
        if (! me->query("can_learn/hong/xianglong-zhang")
           && ! me->query("can_learn/hong/xiaoyaoyou"))
        {
                command("say ����˭���������ģ�Ҫ��ɶ��");
                return -1;
        }

        if ((me->query("can_learn/hong/xianglong-zhang")
           && skill != "xianglong-zhang"
           && skill != "strike")
           || (me->query("can_learn/hong/xiaoyaoyou")
           && skill != "xiaoyaoyou"
           && skill != "unarmed"))
        {
                command("say �Ͻл�����ʲô��ѧʲô���㲻ѧ�����ˡ�");
                return -1;
        }

        if ((skill == "strike"
           && me->query_skill("strike", 1) > 179)
           || (skill == "unarmed"
           && me->query_skill("unarmed", 1) > 179))
        {
                command("say ����Ϊֹ����Ĺ���Ҳ�����ˣ�ʣ�µ��Լ�ȥ����");
                return -1;
        }
        return 1;
}

int try_to_learn_db()
{
        object me;

        me = this_player();
        if (me->query("can_learn/hong/dagou-bang"))
                return 0;

        if (me->query("family/beggarlvl") < 7)
        {
                command("say Ҳ����������ʲô���֣���Ȼ��ѧ�򹷰�����");
                return -1;
        }

        if (me->query("shen") < 80000)
        {
                command("say ����������»����ò����������ȷ�����ʱ�����ܴ��㡣");
                return -1;
        }

        command("sigh");
        command("say ���״򹷰����������ഫ������ֻ���������ΰ���������ѧ��");
        command("say �������ڽ������ң���Ҳ���Ǳ�����֣�����ѧ֮�޷���");
        me->set("can_learn/hong/dagou-bang", 1);
        return 0;
}

int try_to_learn_ds()
{
        object me;
        object sob;
        int i;
        int flag;
        string *sub_skills;

        me = this_player();

        if (me->query("family/family_name") == query("family/family_name")
           && me->query("family/beggarlvl") < 9)
        {
                command("say ��Ҫѧ����ʮ���ƣ������������ﳤ����˵�ɣ�");
                return -1;
        }

        if (me->query("family/family_name") != query("family/family_name")
           && ! me->query("can_learn/hong/xianglong-zhang"))
        {
                command("say �����������ģ�һ�ߴ���ȥ��");
                return -1;
        }

        if (me->query("shen") < 80000)
        {
                command("say ����������»����ò������ҿɲ����Ĵ��������");
                return -1;
        }

        sob = find_object(SKILL_D("xianglong-zhang"));

        if (! sob)
                sob = load_object(SKILL_D("xianglong-zhang"));

        if (! sob->valid_learn(me))
                return 0;

        if (me->query_skill("xianglong-zhang", 1))
        {
                command("say �㲻���Ѿ�����ô���Լ��ú����ɡ�");
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
                        command("nod");
                        command("say �ҽ�ʮ��·�Ʒ��������㣬����ʱ"
                                "�գ������ڻ��ͨ��");
                }
                write(HIC "���" + to_chinese(sub_skills[i]) + "����"
                      "һЩ����\n" NOR);
        }

        if (! flag)
        {
                command("say ����˵�˴������ڻ��ͨ���������ֽ���");
                return -1;
        }

        command("say ���Ƚ���ʮ��·�Ʒ��ڻ��ͨ���϶�Ϊһ��˵�ɡ�");
        notify_fail("���Լ���ȥ�ú���ϰ�ɡ�\n");
        return -1;
}

mixed ask_skill1()
{
        object me;
        me = this_player();

        if (me->query("can_perform/xiaoyaoyou/xian"))
                return "�Ҳ����Ѿ��̹�����ô��";

        if (me->query("family/family_name") != "ؤ��"
           && ! me->query("can_learn/hong/xiaoyaoyou"))
                return "���������������ʶ��ô��";

        if (me->query_skill("xiaoyaoyou", 1) < 1)
                return "������ң��ȭ����ûѧ�������������У�";

        if (me->query("family/family_name") == "ؤ��"
           && me->query("gongxian") < 300)
                return "���ڰ���������Ϊ���������Ҵ������㣿��";

        if (me->query("shen") < 10000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 120)
                return "����ڹ�����㣬����ȥ������������";

        if (me->query_skill("xiaoyaoyou", 1) < 100)
                return "�����ң��ȭ�����δ��������ȥ������";

        message_sort(HIY "\n$n" HIY "���һ㶣��漴���ֽ�$N"
                     HIY "�е�����ǰ����$N" HIY "����������"
                     "����Щ����$N" HIY "���˰��죬ͻȻ�䲻"
                     "�ɻ��ĵ�һЦ��������������\n\n" NOR,
                     me, this_object());

        command("say �ھ����������ˣ��Լ���ȥ����ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����ξ�����\n" NOR);

        if (me->can_improve_skill("dodge"))
                me->improve_skill("dodge", 1500000);
        if (me->can_improve_skill("xiaoyaoyou"))
                me->improve_skill("xiaoyaoyou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiaoyaoyou/xian", 1);

        if (me->query("family/family_name") == "ؤ��")
                me->add("gongxian", -300);

        return 1;
}

mixed ask_skill2()
{
        object me;
        me = this_player();

        if (me->query("can_perform/pomie-jinzhen/du"))
                return "�Ҳ����Ѿ��̹�����ô��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "��ɶ����ʲôʱ��˵��Ҫ���㣿";

        if (me->query_skill("pomie-jinzhen", 1) < 1)
                return "����������붼ûѧ�������������У�";

        if (me->query("gongxian") < 300)
                return "���ڰ���������Ϊ���������Ҵ������㣿��";

        if (me->query("shen") < 10000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����㣬����ȥ������������";

        if (me->query_skill("pomie-jinzhen", 1) < 150)
                return "������������δ��������ȥ������";

        message_sort(HIY "\n$n" HIY "����һЦ����$N" HIY "������ǰ����"
                     "����$N" HIY "�����ֹ��˰��졣�����������֣�ʮָ"
                     "���ţ�һ��һ������������һ�ֺ��ر�İ������š�\n"
                     "\n" NOR, me, this_object());

        command("say ���еľ�Ҫ���ǳ���Ѹ�ݣ����в������Ǻ��ˣ�");
        tell_object(me, HIC "��ѧ���ˡ�����ɽ١���\n" NOR);

        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("pomie-jinzhen"))
                me->improve_skill("pomie-jinzhen", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pomie-jinzhen/du", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill3()
{
        object me;
        me = this_player();

        if (me->query("can_perform/dagou-bang/chan"))
                return "�Ҳ����Ѿ��̹�����ô��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "��ɶ����ʲôʱ��˵��Ҫ���㣿";

        if (me->query_skill("dagou-bang", 1) < 1)
                return "�����򹷰�����ûѧ�������������У�";

        if (me->query("gongxian") < 300)
                return "���ڰ���������Ϊ���������Ҵ������㣿��";

        if (me->query("shen") < 80000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬��ȥ���ߵ�������";

        if (me->query_skill("dagou-bang", 1) < 60)
                return "��Ĵ򹷰������δ�����ٻ�ȥ������";

        message_sort(HIY "\n$n" HIY "����$N" HIY "һ�ۣ�������ü����"
                     "�����������ϵĳ��������������$N" HIY "�����ɻ�"
                     "�䣬ȴֻ����ǰһ����â���������ܽ���$n" HIY "��"
                     "���İ�Ӱ���ܶ����ѣ��ٱ����˸���æ���ҡ�\n\n"
                     NOR, me, this_object());

        command("haha");
        command("say �򹷰���ʽ����ӯ�������ƣ������ⷽ��ö��¹���");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);

        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("dagou-bang"))
                me->improve_skill("dagou-bang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/dagou-bang/chan", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill4()
{
        object me;
        me = this_player();

        if (me->query("can_perform/dagou-bang/chuo"))
                return "�Ҳ����Ѿ��̹�����ô��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "��ɶ����ʲôʱ��˵��Ҫ���㣿";

        if (me->query_skill("dagou-bang", 1) < 1)
                return "�����򹷰�����ûѧ�������������У�";

        if (me->query("gongxian") < 600)
                return "���ڰ���������Ϊ���������Ҵ������㣿��";

        if (me->query("shen") < 80000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 160)
                return "����ڹ�����㣬��ȥ���ߵ�������";

        if (me->query_skill("dagou-bang", 1) < 100)
                return "��Ĵ򹷰������δ�����ٻ�ȥ������";

        message_sort(HIY "\n$n" HIY "����һЦ����$N" HIY "������ǰ����"
                     "����$N" HIY "�����ֹ��˰��졣����ְγ����������"
                     "�������Բ�����͵�ֱ�̶�������������һ�ֺܾ����"
                     "�ȷ���ѧ��$N" HIY "һ����һ�߲�ס�ĵ�ͷ��\n\n" NOR,
                     me, this_object());

        command("nod");
        command("say ���������Ƶвзϣ�ʹ��ʱ�ö�����⡣");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);

        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("dagou-bang"))
                me->improve_skill("dagou-bang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/dagou-bang/chuo", 1);
        me->add("gongxian", -600);

        return 1;
}

mixed ask_skill5()
{
        object me;
        me = this_player();

        if (me->query("can_perform/dagou-bang/feng"))
                return "�Ҳ����Ѿ��̹�����ô��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "��ɶ����ʲôʱ��˵��Ҫ���㣿";

        if (me->query_skill("dagou-bang", 1) < 1)
                return "�����򹷰�����ûѧ�������������У�";

        if (me->query("gongxian") < 1500)
                return "���ڰ���������Ϊ���������Ҵ������㣿��";

        if (me->query("shen") < 80000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 180)
                return "����ڹ�����㣬��ȥ���ߵ�������";

        if (me->query_skill("dagou-bang", 1) < 120)
                return "��Ĵ򹷰������δ�����ٻ�ȥ������";

        message_sort(HIY "\n$n" HIY "���һ㶣��漴���ֽ�$N"
                     HIY "�е�����ǰ����$N" HIY "����������"
                     "����Щ����$N" HIY "���˰��죬ͻȻ�䲻"
                     "�ɻ��ĵ�һЦ��������������\n\n" NOR,
                     me, this_object());

        command("nod");
        command("say ��ǿʱʹ�������㵱�Ա�����ȥ���ٶ�������");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);

        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("dagou-bang"))
                me->improve_skill("dagou-bang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/dagou-bang/feng", 1);
        me->add("gongxian", -1500);

        return 1;
}

mixed ask_skill6()
{
        object me;
        me = this_player();

        if (me->query("can_perform/dagou-bang/ban"))
                return "�Ҳ����Ѿ��̹�����ô��������ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "��ɶ����ʲôʱ��˵��Ҫ���㣿";

        if (me->query_skill("dagou-bang", 1) < 1)
                return "�����򹷰�����ûѧ�������������У�";

        if (me->query("gongxian") < 1800)
                return "���ڰ���������Ϊ���������Ҵ������㣿��";

        if (me->query("shen") < 100000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 240)
                return "����ڹ�����㣬��ȥ���ߵ�������";

        if (me->query_skill("dagou-bang", 1) < 180)
                return "��Ĵ򹷰������δ�����ٻ�ȥ������";

        message_sort(HIY "\n$n" HIY "����$N" HIY "һ�ۣ�������ü����"
                     "�����������ϵĳ��������������$N" HIY "�����ɻ�"
                     "�䣬ȴֻ����ǰһ����â���������ܽ���$n" HIY "��"
                     "���İ�Ӱ���ܶ����ѣ��ٱ����˸���æ���ҡ�\n\n"
                     NOR, me, this_object());

        command("haha");
        command("say ���еľ�Ҫ���ǳ�����ʤ������ȥ���Լ����ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);

        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("dagou-bang"))
                me->improve_skill("dagou-bang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/dagou-bang/ban", 1);
        me->add("gongxian", -1800);

        return 1;
}

mixed ask_skill7()
{
        object me;
        me = this_player();

        if (me->query("can_perform/dagou-bang/tian"))
                return "�Լ�ȥ���ɣ��ϲ����Ҹ�ʲô��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "��ɶ����ʲôʱ��˵��Ҫ���㣿";

        if (me->query_skill("dagou-bang", 1) < 1)
                return "�����򹷰�����ûѧ�������������У�";

        if (me->query("gongxian") < 2000)
                return "���ڰ���������Ϊ���������Ҵ������㣿��";

        if (me->query("shen") < 100000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query("family/beggarlvl") < 9)
                return "���ڰ��еı��ֻ��������ȳ�Ϊ������˵�ɡ�";

        if (! me->query("can_perform/dagou-bang/chan")
           || ! me->query("can_perform/dagou-bang/chuo")
           || ! me->query("can_perform/dagou-bang/feng")
           || ! me->query("can_perform/dagou-bang/ban"))
                return "��򹷰������ĸ��������˽�͸����ô��";

        if (me->query_skill("force") < 300)
                return "����ڹ�����㣬��ȥ���ߵ�������";

        if (me->query_skill("dagou-bang", 1) < 220)
                return "��Ĵ򹷰������δ�����ٻ�ȥ������";

        message_sort(HIY "\n$n" HIY "������$N" HIY "��һ�ᣬ����"
                     "���˵�ͷ�����ֳ��������ȣ����һ��������"
                     "�������������ǧ�ٸ����ƣ���������$N" HIY
                     "�����ھ���֮�У���ʽ���棬�����ױȣ�����̾"
                     "Ϊ��ֹ��\n\n" NOR, me, this_object());

        command("stuff");
        command("say �㵽������̶ȣ���Ҳûɶ�ý̵��ˣ��Լ������ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������޹�����\n" NOR);

        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("dagou-bang"))
                me->improve_skill("dagou-bang", 1500000);
        if (me->can_improve_skill("dagou-bang"))
                me->improve_skill("dagou-bang", 1500000);
        if (me->can_improve_skill("dagou-bang"))
                me->improve_skill("dagou-bang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/dagou-bang/tian", 1);
        me->add("gongxian", -2000);

        return 1;
}

mixed ask_skill8()
{
        object me;
        me = this_player();

        if (me->query("can_perform/xianglong-zhang/qu"))
                return "�Ҳ����Ѿ��̹�����ô��";

        if (me->query("family/family_name") != "ؤ��"
           && ! me->query("can_learn/hong/xianglong-zhang"))
                return "���������������ʶ��ô��";

        if (me->query_skill("xianglong-zhang", 1) < 1)
                return "��������ʮ���ƶ�ûѧ�������������У�";

        if (me->query("family/family_name") == "ؤ��"
           && me->query("gongxian") < 800)
                return "���ڰ���������Ϊ��������ʱ�����ܴ��㡣";

        if (me->query("shen") < 100000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 300)
                return "���ڹ�����㣬��ʱ���޷��������С�";

        if (me->query_skill("xianglong-zhang", 1) < 150)
                return "��Ľ���ʮ���ƻ��δ��������ȥ������";

        message_sort(HIY "\n$n" HIY "���˵�ͷ��ת��������$N" HIY "˵"
                     "�������Ҹ�����ʾһ�飬�����ˡ����������䣬����"
                     "$n" HIY "һ�����ȣ�ȫ���ھ��ŷ��������ұ۷�����"
                     "����һʱ����ֻ����Χ����ӿ�������ϳ���������$n"
                     HIY "������ӿȥ��\n\n" NOR, me, this_object());

        command("say ��ʽ������ˣ����Լ���ȥ����ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�˫��ȡˮ����\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("xianglong-zhang"))
                me->improve_skill("xianglong-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xianglong-zhang/qu", 1);

        if (me->query("family/family_name") == "ؤ��")
                me->add("gongxian", -800);

        return 1;
}

mixed ask_skill9()
{
        object me;
        me = this_player();

        if (me->query("can_perform/xianglong-zhang/zhen"))
                return "�Ҳ����Ѿ��̹�����ô��";

        if (me->query("family/family_name") != "ؤ��"
           && ! me->query("can_learn/hong/xianglong-zhang"))
                return "���������������ʶ��ô��";

        if (me->query_skill("xianglong-zhang", 1) < 1)
                return "��������ʮ���ƶ�ûѧ�������������У�";

        if (me->query("family/family_name") == "ؤ��"
           && me->query("gongxian") < 2000)
                return "���ڰ���������Ϊ��������ʱ�����ܴ��㡣";

        if (me->query("shen") < 100000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 300)
                return "���ڹ�����㣬��ʱ���޷��������С�";

        if (me->query_skill("xianglong-zhang", 1) < 150)
                return "��Ľ���ʮ���ƻ��δ��������ȥ������";

        message_sort(HIY "\n$n" HIY "���˵�ͷ��ת��������$N" HIY "˵"
                     "�������Ҹ�����ʾһ�飬�����ˡ����������䣬����"
                     "$n" HIY "һ�����ȣ�ȫ�������Ķ���˫����ɽ������"
                     "ѹ������ʱֻ�������ꡱһ�����죬$n" HIY "��ǰ��"
                     "����ڴֵ�����Ӧ��������ֱ����$N" HIY "Ŀ�ɿڴ�"
                     "������˵����������\n\n" NOR, me, this_object());

        command("sweat");
        command("say ��ʽ������ˣ����Լ���ȥ����ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��𾪰����\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("xianglong-zhang"))
                me->improve_skill("xianglong-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xianglong-zhang/zhen", 1);

        if (me->query("family/family_name") == "ؤ��")
                me->add("gongxian", -2000);

        return 1;
}

mixed ask_skill10()
{
        object me;
        me = this_player();

        if (me->query("can_perform/xianglong-zhang/fei"))
                return "�Ҳ����Ѿ��̹�����ô��";

        if (me->query("family/family_name") != "ؤ��"
           && ! me->query("can_learn/hong/xianglong-zhang"))
                return "���������������ʶ��ô��";

        if (me->query_skill("xianglong-zhang", 1) < 1)
                return "��������ʮ���ƶ�ûѧ�������������У�";

        if (me->query("family/family_name") == "ؤ��"
           && me->query("gongxian") < 3000)
                return "���ڰ���������Ϊ��������ʱ�����ܴ��㡣";

        if (me->query("shen") < 100000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force") < 300)
                return "���ڹ�����㣬��ʱ���޷��������С�";

        if (me->query_skill("xianglong-zhang", 1) < 150)
                return "��Ľ���ʮ���ƻ��δ��������ȥ������";

        message_sort(HIY "\n$n" HIY "��˼���ã����Ż������˵�ͷ����"
                     "�ֽ�$N" HIY "�������ԣ��������������á�����Ƭ"
                     "�̣�ȴ��$n" HIY "��������������������һ����"
                     "��˫����Ȼ����������һ�����������ھ���֮�ϣ���"
                     "�ƻֺ룬�����س���\n\n" NOR, me, this_object());

        command("nod");
        command("say ����������Ϊ���ף�����ȥ�����ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ��������졹��\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("xianglong-zhang"))
                me->improve_skill("xianglong-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xianglong-zhang/fei", 1);

        if (me->query("family/family_name") == "ؤ��")
                me->add("gongxian", -3000);

        return 1;
}

mixed ask_skill11()
{
        object me;
        me = this_player();

        if (me->query("can_perform/xianglong-zhang/hui"))
                return "�Ҳ����Ѿ��̹�����ô��";

        if (me->query("family/family_name") != "ؤ��"
           && ! me->query("can_learn/hong/xianglong-zhang"))
                return "���������������ʶ��ô��";

        if (me->query_skill("xianglong-zhang", 1) < 1)
                return "��������ʮ���ƶ�ûѧ�������������У�";

        if (me->query("family/family_name") == "ؤ��"
           && me->query("gongxian") < 3000)
                return "���ڰ���������Ϊ��������ʱ�����ܴ��㡣";

        if (me->query("shen") < 120000)
                return "������֮�����ò������ҿɲ����Ĵ������㡣";

        if (me->query_skill("force", 1) < 260)
                return "������ڹ�����㣬��ʱ���޷��������С�";

        if (me->query_skill("xianglong-zhang", 1) < 220)
                return "��Ľ���ʮ���ƻ��δ��������ȥ������";

        message_sort(HIY "\n$n" HIY "��˼���ã����Ż������˵�ͷ����"
                     "�ֽ�$N" HIY "�������ԣ��������������á�����Ƭ"
                     "�̣���Ȼ$n" HIY "���μ���������һ�������ֺ���һ��"
                     "������գ����ǽ���ʮ���ơ������лڡ� ����������֮"
                     "��˵���㵽������ɽ����֮������տ�ӿ��ȥ������ʯ"
                     "���쾪�������ޱȡ�\n\n" NOR, me, this_object());

        command("nod");
        command("say ����������Ϊ���ף�����ȥ�����ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ������лڡ���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("xianglong-zhang"))
                me->improve_skill("xianglong-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xianglong-zhang/hui", 1);

        if (me->query("family/family_name") == "ؤ��")
                me->add("gongxian", -3000);

        return 1;
}

mixed ask_me()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "ؤ��")
                return "������������һ��ȥ��";

        if (me->query("family/master_id") != query("id"))
                return "�٣���ƾ��Ҳ���������ȣ�";

        if (me->query_skill("dagou-bang", 1) < 150)
                return "���������İ���Ҳ���������ȣ�";

        if (me->query("shen") < 80000)
                return "������֮�����ò����������ܽ�ؤ�����ｻ���㣿";

        ob = find_object(YUZHU);
        if (! ob) ob = load_object(YUZHU);
        owner = environment(ob);

        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�����Ȳ���������������ô���������������ˣ�";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���������ڲ��������";

                if (owner->query("family/family_name") == "ؤ��")
                        return "������������ʱ����ͬ��" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���������������������" + owner->query("name") +
                               "���У���ȥ�����һ����ɡ�";
        }
        ob->move(this_object());
        command("give yuzhu zhang to " + me->query("id"));
        return "��������������ʱ��ȥ�ðɣ��ɱ����ؤ�ﶪ����";
}

int accept_object(object who, object ob)
{
        int lv;
        string by;
        object me;
        string hid;
        object hob;

        me = this_object();

        if (! ob->query("food_supply"))
        {
                command("say ����������ɶ��");
                return -1;
        }

        if (! intp(lv = ob->query("level"))
           || lv < 1
           || ! stringp(by = ob->query("by")))
        {
                command("say �ⶫ������ȥҲûɶ�ر�ģ����Ը����Űɡ�");
                return -1;
        }

        if (lv < 100)
        {
                message_vision(CYN "$N" CYN "������" + ob->name() +
                               CYN "����ü�����ⶫ���㻹���Ը�����"
                               "�ɡ�\n" NOR, me);
                return -1;
        }

        if (lv < 120)
        {
                message_vision(CYN "$N" CYN "������" + ob->name() +
                               CYN "����ζ�������ɻ�����΢Ƿ��ô"
                               "������\n" NOR, me);
                return -1;
        }

        message_vision(HIW "$N" HIW "������$n" HIW "������" + ob->name() +
                       HIW "�����˼��ڣ�ֱ����ͷ���������ޡ�\n" NOR, me, who);

        if (! who->id(by))
        {

                command("say ��ϧ��֪����˭���ģ��пտɵø�������������");
                return 1;
        }

        if (who->query("gender") != "Ů��")
        {
                command("say �벻����һ������ү������Ҳ�����ѵã��ѵá�");
                return 1;
        }

        if (who->query("family/family_name") == query("family/family_name"))
        {
                command("say �����������������治���Ժ�Ϳ�����չ��ˡ�");
                return 1;
        }

        if (who->query("can_learn/hong/xiaoyaoyou") >= 1)
        {
                command("pat " + who->query("id"));
                command("say �ָ��Ͻл�������ˣ���л����л��");
                return 1;
        }
        command("stuff");
        command("say �Ͻл�ûɶֵǮ�ģ��ʹ���һ��ȭ����Ϊ����ɡ�");

        tell_object(who, HIC "\n���߹�ͬ�⴫���㡸��ң��ȭ������\n" NOR);
        who->set("can_learn/hong/xiaoyaoyou", 1);
        who->improve_skill("martial-cognize", 1500000);

        if (lv >= 200)
        {
                message_vision(CYN "\n$N" CYN "��˼���ã��ֵ����벻"
                               "�����˻�Ѿͷ����Ȼ�����������������"
                               "ζ��\n" NOR, me, who);

                if (! stringp(hid = who->query("couple/id")))
                {
                        command("say ȴ��֪��������ż���û�У���Ҫ"
                                "�Ͻл�������ܣ�");
                        return 1;
                }

                if (! objectp(hob = find_player(hid)))
                {
                        command("sigh");
                        command("say ��ϧ����λ���ڣ������ҵ��ǿ���"
                                "�������ֹ��򡣰��ˣ����ˡ�");
                        return 1;
                }

                if (hob->query("family/family_name") == query("family/family_name"))
                {
                        command("say " + hob->name(1) + "��Ȣ������"
                                "�������ţ�Ҳ�����ˡ�");
                        return 1;
                }
                command("say ʲôʱ�����Ҳ������λ������Ҳ�����㶫����");

                tell_object(hob, HIC "\n���߹�ͬ�⴫���㡸����ʮ���ơ���\n" NOR);
                hob->set("can_learn/hong/xianglong-zhang", 1);
                hob->improve_skill("martial-cognize", 1500000);
        }
        destruct(ob);
        return 1;
}

void unconcious()
{
        die();
}
