#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("��ΰ��", ({ "qin weibang", "qin", "weibang"}));
        set("title", "���������������");
        set("long", @LONG
���������������������ΰ���ʮ�������
���ѱ����Ϊ��������ν���Ͳ�С��
LONG);
	set("gender", "����" );
        set("class", "scholar");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 3400);
        set("max_jing", 2200);
        set("neili", 3600);
        set("max_neili", 3600);
        set("jiali", 120);
        set("combat_exp", 1500000);
        set("score", 10000);

        set_skill("force", 160);
        set_skill("riyue-xinfa", 160);
        set_skill("dodge", 150);
        set_skill("feiyan-zoubi", 150);
        set_skill("blade", 160);
        set_skill("danding-dao", 160);
        set_skill("parry", 150);
        set_skill("cuff", 150);
        set_skill("zhenyu-quan", 150);
        set_skill("claw", 150);
        set_skill("poyue-zhao", 150);
        set_skill("martial-cognize", 150);
        set_skill("literate", 160);

        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "riyue-xinfa");
        map_skill("blade", "danding-dao");
        map_skill("parry", "danding-dao");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        create_family("�������", 14, "����");

        set("inquiry", ([
                "�������" : (: ask_skill1 :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "blade.kou" :),
                (: perform_action, "cuff.tong" :),
                (: perform_action, "claw.duan" :),
		(: exert_function, "recover" :),
	}) );
        setup();

        carry_object("/d/heimuya/npc/obj/jinpao")->wear();
        carry_object("clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > 0)
        {
                command("heng");
                command("say ��������̴�������������ʿ�ύ������ҹ�����");
                return;
        }

        if ((string)ob->query("gender") == "Ů��")
        {
                command("sneer");
                command("say ���ڹ�����ϣ���ְλδ��������˽��Ůͽ��");
                return;
        }

        command("nod2");
        command("say ����͸����Ұɣ����֮��ĸ��ֹ�ؿ�Ҫ��ע�⡣");
        command("recruit " + ob->query("id"));
        return;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/danding-dao/kou"))
                return "�������Ѿ��̹����ˣ��Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("danding-dao", 1) < 1)
                return "�������ֵ�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 80)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -8000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 100)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("danding-dao", 1) < 80)
                return "��ĵ��ֵ��������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ����$N" HIY "������ߣ��ڶ�"
                     "�Ե���ϸ˵���ã�$N" HIY "���󲻽����ĵ�һЦ��������"
                     "������\n\n" NOR, me, this_object());

        command("nod");
        command("say ���кܼ򵥣��Լ���ϰ���С�");
        tell_object(me, HIC "��ѧ���ˡ�������ۡ���\n" NOR);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("danding-dao"))
                me->improve_skill("danding-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/danding-dao/kou", 1);
        me->add("gongxian", -100);

        return 1;
}
