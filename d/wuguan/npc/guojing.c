#include <ansi.h>
inherit NPC;

inherit F_COAGENT;

void create()
{
        set_name("����", ({ "guo jing", "guo", "jing" }));
        set("nickname", HIY "����" NOR);
        set("title", "�����Ǵ�");
        set("gender", "����");
        set("age", 41);
        set("long", @LONG
�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ�
�������ǽ����߹֡�ȫ�������ڵ���������ؤ��
���߹��͡�����ͯ���ܲ�ͨ���˵�ͽ�ܣ��������
�书��������һ����ɫ���ۣ���̬���࣬�غ����
Ŀ��͸��һ���������˲��ɵò���һ������֮�顣
LONG);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 40);
        set("int", 14);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 8000);
        set("max_jing", 6000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 300);
        set("combat_exp", 4000000);
        set("score", 200000);
         
        set_skill("force", 320);
        set_skill("xiantian-gong", 320);
        set_skill("yijin-duangu", 320);
        set_skill("guoshi-xinfa", 280);
        set_skill("dodge", 300);
        set_skill("feiyan-zoubi", 280);
        set_skill("jinyan-gong", 300);
        set_skill("shexing-lifan", 300);
        set_skill("unarmed", 300);
        set_skill("changquan", 300);
        set_skill("strike", 320);
        set_skill("xianglong-zhang", 320);
        set_skill("sword", 280);
        set_skill("yuenv-jian", 280);
        set_skill("parry", 320);
        set_skill("literate", 120);
        set_skill("zuoyou-hubo", 400);
        set_skill("martial-cognize", 320);
        set_skill("craft-cognize", 280);

        map_skill("force", "yijin-duangu");
        map_skill("strike", "xianglong-zhang");
        map_skill("unarmed", "changquan");
        map_skill("sword", "yuenv-jian");
        map_skill("dodge", "shexing-lifan");
        map_skill("parry", "xianglong-zhang");

        prepare_skill("strike", "xianglong-zhang");

        set("chat_chance", 1);
        set("chat_msg", ({
                CYN "����̾�˿��������ɹű��ù��������£�һ�����ٳ���ơ�\n" NOR,
        }));

        set("inquiry", ([
                "�ܲ�ͨ" : "��������ܴ���ˣ������ڿɺã�",
                "����ͯ" : "�ܴ��һ��������û��������",
                "���߹�" : "ʦ�����˳ԣ�����ϲ���档�����棬����Ϊ���ҳԵġ�",
                "��ҩʦ" : "������̩ɽ���ˡ��������ĺ����������ײ���β�ġ�",
                "ŷ����" : "����϶����������λʦ����һ���������ˣ������������ݡ�",
                "����"   : "�ض����ҵİ��ޣ�������������",
                "�ض�"   : "�ض������ض��ˡ�������ô����",
                "��ܽ"   : "���Ů�����ֱ��ֲ�������",
                "����"   : "��������������Ⱳ���ֶ��򡣵�Ը���ܿ���һ����",
                "����²" : "�����ҵ�С���ӡ�",
                "���"   : "����ȷʵ�г�Ϣ��",
                "����"   : "����������а�ʦ֮�ꡣ",
                "�𴦻�" : "������屡���죬������ܡ�",
                "�����" : "�����Ҵ�ʦ����",
                "���"   : "�����Ҷ�ʦ����",
                "������" : "��������ʦ����",
                "��ϣ��" : "��������ʦ����",
                "�Ű���" : "��������ʦ����",
                "ȫ��" : "��������ʦ����",
                "��СӨ" : "��������ʦ����",
                "ؤ��"   : "ؤ��Ӣ�ۼ������ˣ�����������������ǡ�\n",
                "��ʦ"   : "�����ɹ���Χ��������������������ͽ����\n",
                "����"   : "���š������ȥ������ɣ�������㰲�ŵġ�",
                "����"   : "�������䳡���������ģ���ȥ�����ɡ�",
                "һ�ƴ�ʦ" : "���¶Դ�ʦ�����м���",
        ]));

        create_family("����", 1, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
		(: command("perform strike.fei twice") :),
		(: command("perform strike.hui twice") :),
		(: command("perform strike.zhen twice") :),
		(: command("perform strike.qu and strike.hui") :),
		(: command("perform strike.fei and strike.hui") :),
		(: command("perform strike.zhen and strike.hui") :),
		(: command("perform strike.zhen and strike.fei") :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set_temp("apply/damage", 300);
        set_temp("apply/unarmed_damage", 300);
        set_temp("apply/armor", 500);

        setup();

        if (! clonep(this_object()))
        {
                move("/d/wuguan/guofu_dating");
                message_vision(CYN "\n$N" CYN "���˹�����������"
                               "�ܣ�����̾�˿�����\n" NOR,
                               this_object());
                set("startroom", "/d/wuguan/guofu_dating");
        }
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
     	object ob;
     	::init();

     	if (interactive(ob = this_player())
           && userp(ob)
	   && ! ob->query_temp("mark/guofu_wait")
           && ! is_fighting())
	{
        	if (ob->query("mark/guofu_over"))
		{
            		command("hmm");
            		command("say �Ҳ���������ı��·�����ܻ������");
            		command("say ���壬���ģ���" + ob->name() + NOR + CYN "��ȥ��");
            		message_vision(HIC "\nֻ��$N" HIC "һ���֣���ʱ��������������"
                                       "λ���꣬��$n" HIC "���˳�ȥ��\n\n",
                                       this_object(), ob);
            		ob->move("/d/xiangyang/westjie1");
            		tell_room(environment(ob), HIC "\nֻ����λ�������" + ob->name() +
                                                   HIC "�ӹ����������˹�����\n" NOR, ({ ob }));
            	} else
        	if (ob->query("mark/guofu_out")
		   && (int)ob->query("combat_exp") < 100000)
		{
            		command("say �����ڵ��书�Ѿ���һ���ĵ����ˣ�Ӧ�ö��߶��߶���");
            		command("say �����Ǵ�������������������󡣶��壬���ģ��Ϳͣ�");
            		message_vision(HIC "\nֻ��$N" HIC "һ���֣���ʱ��������������"
                                       "λ���꣬��$n" HIC "���˳�ȥ��\n\n",
                                       this_object(), ob);
            		ob->move("/d/xiangyang/westjie1");
            		tell_room(environment(ob), HIC "\nֻ����λ��������" + ob->name() +
                                                   HIC "�ӹ����������˹�����\n" NOR, ({ ob }));
            	} else
        	if ((int)ob->query("combat_exp") > 100000)
		{
            		command("say ���ڹ��ѵ�ͷ���ɹ���Χ�����������������鷱�ࡣ");
            		command("say ˡ��ĳ���񣬻�����»�ȥ�����壬���ģ��Ϳͣ�");
            		message_vision(HIC "\nֻ��$N" HIC "һ���֣���ʱ��������������"
                                       "λ���꣬��$n" HIC "���˳�ȥ��\n\n",
                                       this_object(), ob);
            		ob->move("/d/xiangyang/westjie1");
            		tell_room(environment(ob), HIC "\nֻ����λ��������" + ob->name() +
                                                   HIC "�ӹ����������˹�����\n" NOR, ({ ob }));
            	} else
         	if ((int)ob->query_condition("killer"))
		{
            		command("sigh");
            		command("say ��ɱ�����֮�أ�������Ҳ�������㣬�㻹���߰ɡ�");
            		command("say ���壬���ģ��Ϳͣ�");
            		message_vision(HIC "\nֻ��$N" HIC "һ���֣���ʱ��������������"
                                       "λ���꣬��$n" HIC "���˳�ȥ��\n\n",
                                       this_object(), ob);
            		ob->move("/d/xiangyang/westjie1");
            		ob->set("mark/guofu_over", 1);
			ob->delete("mark/guofu_ok");
            		tell_room(environment(ob), HIC "\nֻ����λ�������" + ob->name() +
                                                   HIC "�ӹ����������˹�����\n" NOR, ({ ob }));
            	} else
                // ������ڣ������������������书
         	if (ob->query("mark/guofu_ok")                    //�� ȷ�ϱ������ڹ���
		   && (int)ob->query("mark/guofu_job") > 200      //�� ��������������������
		   && (int)ob->query("combat_exp") > 10000        //�� ȷ�Ͼ���ֵ��һ�������֮��
                   && (int)ob->query("combat_exp") < 20000
		   && ! ob->query_temp("job_name")                //�� ��ʱû����ȡ����
		   && ! ob->query("family/family_name")           //�� û�а�ʦ
		   && ! ob->query("can_learn/3skills/guojing")    //�� ��֤��ǰδ���������
		   && ! stringp(ob->query_skill_mapped("force"))) //�� û�м��������ڹ�
		{
	                command("look " + ob->query("id"));
            		command("yi");
                	command("whisper " + ob->query("id") + " �����ҹ����ڹ���Ҳ��"
                                "һ����ʱ��\n�ˣ���ô��һ��֮��Ҳû�У��Ժ��������߽�"
                                "���������š���\n�����ˣ��ӽ�������ÿ�쵽����������"
                                "�Ҵ����㼸��򵥵�\n�����书���ˡ�\n" NOR);
			ob->set("can_learn/3skills/guojing", 1);
            	}
         }
}

void attempt_apprentice(object ob)
{
        command("sigh");
        command("say �����ɹ���Χ��������������������ͽ����");
        return;
}

int recognize_apprentice(object ob, string skill)
{
        if (! ob->query("can_learn/3skills/guojing"))
        {
                command("say �����ɹ���Χ�������������������ڿΰ���");
                command("say ���㽫����ʦ֮����ʦ����Ȼ����㣬�����ļ���");
                return -1;
        }

        if (ob->query("combat_exp") > 20000)
        {
                command("say �㾭��Ҳ�����ˣ�Ӧ�ö��ȥ����������������������\n");
                return -1;
        }

        if (skill != "force"
           && skill != "guoshi-xinfa"
	   && skill != "dodge"
           && skill != "feiyan-zoubi"
           && skill != "unarmed"
           && skill != "changquan")
        {
                command("shake");
                command("say ����ഫ���㼸���Ϊ���������⼼�ܣ��������������ˡ�");
                command("say ����Ը���ѧ�����ķ��������߱ڡ�̫�泤ȭ��һЩ�������ܡ�\n");
                return -1;
        }

        if (! ob->query_temp("can_learn/guojing"))
        {
                command("nod2");
                command("say �����ڷܿ̿࣬�ұ㴫����һЩ���ܣ���Ҫ����Ǻ��ˡ�");
                ob->set_temp("can_learn/guojing", 1);
        }
        return 1;
}

void unconcious()
{
        die();
}
