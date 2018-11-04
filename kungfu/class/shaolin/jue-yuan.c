#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��Զ", ({ "jue yuan", "jue", "yuan" }));
	set("long", "һλ�������ء��뷢���׵���ɮ��ֻ����������һ\n"
                    "�Դ���Ͱ����֮Ѱ��ˮͰ�����������࣬��ɮ�˾�\n"
                    "�С����ϡ����ϣ��������˴ִ������������ʱ��\n"
                    "���ϵأ���ͣ�������졣��Դ���Ͱ����ֻ�±���\n"
                    "�������Ͱ��װ����ˮ���������Ǿ��ˡ�\n" );
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 32);
	set("int", 34);
	set("con", 31);
	set("dex", 30);
	set("max_qi", 8000);
	set("max_jing", 6000);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 300);
	set("combat_exp", 5000000);

	set_skill("force", 380);
	set_skill("jiuyang-shengong", 400);
	set_skill("shaolin-jiuyang", 180);
	set_skill("wudang-jiuyang", 180);
	set_skill("emei-jiuyang", 180);
	set_skill("dodge", 220);
	set_skill("shaolin-shenfa", 220);
	set_skill("unarmed", 380);
	set_skill("parry", 260);
        set_skill("martial-cognize", 300);
	set_skill("buddhism", 200);
	set_skill("literate", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "jiuyang-shengong");
	map_skill("parry", "jiuyang-shengong");

	prepare_skill("unarmed", "jiuyang-shengong");

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/dodge", 150);
        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 200);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.hun" :),
		(: perform_action, "unarmed.jiu" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
	}));

	create_family("������", 0, "����ɮ��"); 

	setup();

        carry_object("/d/shaolin/obj/xu-cloth")->wear();
}

void attempt_apprentice(object ob)
{
        message_vision(CYN "$N" CYN "ҡ��ҡͷ����$n" CYN "˵������ƶɮ�˴�"
                       "��֮��������ͽ����\n" NOR, this_object(), ob);
}

void init()
{
        object me;

        me = this_player();

        if (! interactive(me))
                return;

        if (living(this_object()) && present("lengjia jing", me))
        {
                command("yi");
                command("say ��λʩ����������ʧ�ġ���٤���������������ϣ�");
                command("say ����λʩ���и����㣬�����黹��ƶɮ��");
                return;
        }
}

int accept_object(object who, object ob)
{
        if (ob->query("id") == "lengjia jing")
        {
                destruct(ob);
                if (who->query("can_learn/jiuyang-shengong/kunlun"))
                {
                        if (who->query("can_learn/jiuyang-shengong/shaolin"))
                        {
                                command("say ��л����л��");
                                return 1;
                        } else
                        {
                                message_vision(CYN "$N" CYN "������ϲ�Ķ�$n" CYN "��"
                                               "��ʩ��լ���ʺ��պ���д�ɣ�ƶɮ��"
                                               "л�ˡ�\n" NOR, this_object(), who);
                                command("sigh");
                                command("say ��������֮��̰ͼ�ڴˣ�����Ϊ���Ȿ������"
                                        "�����ص�һ���书��");
                                command("say ʩ��Ϊ���Һ���ֱ��������������ƶɮ���ǿ�"
                                        "�Խ������书��һ���ִ������㡣");

                                who->set("can_learn/jiuyang-shengong/shaolin", 1);
                                tell_object(who, HIC "��Զͬ�⴫���㡸���־���������\n" NOR);

                                if (who->can_improve_skill("martial-cognize"))
                                        who->improve_skill("martial-cognize", 1500000);
                                return 1;
                        }
                }
                message_vision(CYN "$N" CYN "������ϲ�Ķ�$n" CYN "����ʩ��լ���ʺ�"
                               "�պ���д�ɣ�ƶɮ��л�ˡ�\n" NOR, this_object(), who);
                return 1;
        }
        return 0;
}

int recognize_apprentice(object who, string skill)
{
        if (! who->query("can_learn/jiuyang-shengong/shaolin"))
        {
                command("say ʩ�������ˣ�ƶɮ���µ�΢����̸��ָ�㡱���֡�");
                return -1;
        }

        if (skill != "shaolin-jiuyang")
        {
                command("say ����ν��֪����֣������򰲡��������书��ˡƶɮ���ܽ��ڡ�");
                return -1;
        }
        return 1;
}
