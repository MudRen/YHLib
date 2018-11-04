#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("������", ({ "cheng lingsu", "cheng" }));
        set("gender", "Ů��");
        set("age", 24);
        set("long", @long
������ȥ˫ü��������֪����ʲô���£�������òƽƽ���������ڡ�
�����С�����Ŵֲ�������
long);
        set("attitude", "peaceful");
        set("str", 22);
        set("int", 35);
        set("con", 31);
        set("dex", 27);
        set("chat_chance", 10);
        set("chat_msg", ({
                "�����ذ�����̾�˿�����\n",
        }));

        set("qi", 2500);
        set("max_qi", 2500);
        set("jing", 1200);
        set("max_jing", 1200);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 40);
        set("combat_exp", 400000);
     
        set_skill("force", 150);
        set_skill("poison", 270);
        set_skill("dispel-poison", 270);
	set_skill("medical", 270);
	set_skill("yaowang-miaoshu", 270);

        set("inquiry",([
                "���":     "��...��...\n",
                "Ԭ����":   "��...��������ʲô��\n"
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object me, string skill)
{
        if (me->query("family/family_name") != "ҩ����")
        {
                command("say ����˭������ʲô��");
                return -1;
        }

        if (skill != "poison" && skill != "dispel-poison" &&
	    skill != "medical" && skill != "yaowang-miaoshu")
        {
                command("say ��ֻ�ᶾ����ҽ��������Ҿ�û���ӽ�������");
                return -1;
        }

        if ((int)me->query("shen") < 0)
        {
                command("sigh");
                command("say ����������а·���ҿɲ��ܽ��㶾����");
                return -1;
        }

        if (! me->query_temp("can_learn/cheng/poison"))
        {
                me->set_temp("can_learn/cheng/poison", 1);
                command("say ���ں���������ϣ��Ҿͽ���һ�㱾�°ɣ����Ҫ����Ϊ֮��");
                return 1;
        }

        return 1;
}
