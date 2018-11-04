#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
	set_name("�ֲ�", ({ "jia bu", "jia", "bu"}));
        set("title", "������������ó���");
        set("nickname", YEL "����ʹ��" NOR);
        set("long", @LONG
����������������ó��ϼֲ���ֻ����������
��������̫��Ѩ�߸߹��𣬱������һöö��
���Ƶģ������������ࡣ
LONG);
	set("gender", "����" );
        set("class", "scholar");
        set("age", 39);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 4800);
        set("max_jing", 3500);
        set("neili", 5600);
        set("max_neili", 5600);
        set("jiali", 180);
        set("combat_exp", 2500000);
        set("score", 10000);

        set_skill("force", 220);
        set_skill("riyue-xinfa", 220);
        set_skill("tianhuan-shenjue", 220);
        set_skill("dodge", 240);
        set_skill("feiyan-zoubi", 240);
        set_skill("juechen-shenfa", 240);
        set_skill("dagger", 240);
        set_skill("jifeng-cixuefa", 240);
        set_skill("canghong-bifa", 240);
        set_skill("claw", 200);
        set_skill("da-qinna", 180);
        set_skill("xiao-qinna", 180);
        set_skill("strike", 200);
        set_skill("qingmang-zhang", 200);
        set_skill("parry", 240);
        set_skill("martial-cognize", 180);
        set_skill("literate", 220);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "tianhuan-shenjue");
        map_skill("dagger", "canghong-bifa");
        map_skill("claw", "da-qinna");
        map_skill("parry", "canghong-bifa");
        map_skill("strike", "qingmang-zhang");

        prepare_skill("claw", "xiao-qinna");

        create_family("�������", 13, "�����ó���");

        set("inquiry", ([
                "����һ��" : (: ask_skill1 :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
                (: perform_action, "dagger.jing" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

        setup();

        carry_object("/d/heimuya/npc/obj/jinpao")->wear();
        carry_object("/d/meizhuang/obj/panguanbi")->wield();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -25000)
        {
                command("hmm");
                command("say �Ҵ�����������������ʿ�����������ɣ�");
                return;
        }

        if (ob->query("combat_exp") < 200000)
        {
                command("say �����ڽ�������̫ǳ����Ӧ�ö��߶��߶���");
                return;
        }

        if (ob->query_skill("dagger", 1) < 80)
        {
                command("en");
                command("say �������е����Ǵ�Ѩ��������ʮ��·�Ժ�ʷ�������˫��");
                command("say ���ȻҪ���ҵĵ��ӣ���Ӧ���ڶ̱���������¹���");
                return;
        }

        if (ob->query_skill("tianhuan-shenjue", 1) < 80
           && ob->query_skill("riyue-xinfa", 1) < 80)
        {
                command("hmm");
                command("say ����������������ڹ���û�޺ã���ôѧϰ�ϳ���ѧ��");
                return;
        }

        command("nod2");
        command("say �����Ժ�͸����Һ��ˡ�");
        command("say �������񷱶࣬��Ī���˹�ء�");
        command("recruit " + ob->query("id"));
        return;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/canghong-bifa/jing"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("canghong-bifa", 1) < 1)
                return "�����Ժ�ʷ���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -30000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 150)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("canghong-bifa", 1) < 100)
                return "��ĲԺ�ʷ������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "����һЦ��˵���������������ӿ�"
                     "��Ҳ�������Ϸ�ʹ������С�$n" HIY "˵��㽫$N" HIY
                     "������ǰ�����ֹ���˵�˰��졣\n\n" NOR, me,
                     this_object());

        command("nod");
        command("say �ղ�����˵�ı�����ʷ��ľ�Ҫ���������˶��٣�");
        tell_object(me, HIC "��ѧ���ˡ�����һ�ʡ���\n" NOR);
        if (me->can_improve_skill("dagger"))
                me->improve_skill("dagger", 1500000);
        if (me->can_improve_skill("canghong-bifa"))
                me->improve_skill("canghong-bifa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/canghong-bifa/jing", 1);
        me->add("gongxian", -400);

        return 1;
}
