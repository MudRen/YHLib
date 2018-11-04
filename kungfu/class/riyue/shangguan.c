#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();

void create()
{
	set_name("�Ϲ���", ({ "shangguan yun", "shangguan", "yun"}));
        set("title", "������̰׻��ó���");
        set("nickname", WHT "����" NOR);
        set("long", @LONG
����������̰׻��ó����Ϲ��ơ��ڽ����˳�
������Ϊ�˼��乢ֱ���书�ָ�ǿ��
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
        set("max_qi", 5200);
        set("max_jing", 3400);
        set("neili", 5800);
        set("max_neili", 5800);
        set("jiali", 160);
        set("combat_exp", 2500000);
        set("score", 10000);

        set_skill("force", 240);
        set_skill("tianhuan-shenjue", 240);
        set_skill("riyue-xinfa", 220);
        set_skill("dodge", 220);
        set_skill("juechen-shenfa", 240);
        set_skill("feiyan-zoubi", 220);
        set_skill("blade", 240);
        set_skill("danding-dao", 240);
        set_skill("shiying-lianhuan", 240);
        set_skill("strike", 180);
        set_skill("qingmang-zhang", 180);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("zhenyu-quan", 200);
        set_skill("claw", 200);
        set_skill("poyue-zhao", 200);
        set_skill("martial-cognize", 220);
        set_skill("literate", 140);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "tianhuan-shenjue");
        map_skill("blade", "shiying-lianhuan");
        map_skill("parry", "shiying-lianhuan");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");
        map_skill("strike", "qingmang-zhang");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        create_family("�������", 13, "�׻��ó���");

        set("inquiry", ([
                "�޺�ɱ" : (: ask_skill1 :),
                "��������" : (: ask_skill2 :),
                "�ٹ�����" : (: ask_skill3 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.sha" :),
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

        if ((int)ob->query("shen") > -30000)
        {
                command("killair");
                command("say ����������α���ӣ��ٲ������ұ����㣡");
                return;
        }

        if (ob->query("combat_exp") < 200000)
        {
                command("say �����ڽ�������̫ǳ��Ӧ�ö��߶��߶���");
                return;
        }

        if (ob->query_skill("blade", 1) < 80)
        {
                command("hmm");
                command("say �����õ��ģ�����ϰ���·�߲��ԣ����Խ��ڡ�");
                return;
        }

        if (ob->query_skill("tianhuan-shenjue", 1) < 80
           && ob->query_skill("riyue-xinfa", 1) < 80)
        {
                command("hmm");
                command("say ����������������ڹ���û�޺ã���ôѧϰ�ϳ���ѧ��");
                return;
        }

        command("haha");
        command("say ��������Ϊ��̳����������Ҿͳ�ȫ�㡣");
        command("say �������һͳ������ǧ���ҵ����ȫ�������ˡ�");
        command("recruit " + ob->query("id"));
        return;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/shiying-lianhuan/sha"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("shiying-lianhuan", 1) < 1)
                return "����߱ӥ��������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 600)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -40000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 200)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("shiying-lianhuan", 1) < 150)
                return "���߱ӥ�����������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "Ц��Ц�����ֽ�$N" HIY "�е���ǰ����"
                     "����$N" HIY "�����ֹ��˰��졣Ȼ���ְγ�������ת����"
                     "��б�ö������ƺ���һ����Ϊ���صĵ�����\n\n" NOR, me,
                     this_object()); 

        command("nod2");
        command("say �������𣿿����˾��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��޺�ɱ����\n" NOR);
        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("shiying-lianhuan"))
                me->improve_skill("shiying-lianhuan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/shiying-lianhuan/sha", 1);
        me->add("gongxian", -600);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/poyue-zhao/duan"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("poyue-zhao", 1) < 1)
                return "����������צ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 100)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -10000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 100)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("poyue-zhao", 1) < 80)
                return "���������צ�����ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "����$N" HIY "����ĵ��˵�ͷ��Ц����"
                     "�����������Ϸ�����ƽʱ����Ŭ�������վʹ������"
                     "�����ƺ��ˡ���˵���ֻ��$n" HIY "����һչ��˫צ����"
                     "���ϣ���ʱ��צӰ����������ʵ�ѱ磬������Ϊ���"
                     "\n\n" NOR, me, this_object()); 

        command("nod");
        command("say ���е���ʽ�������ӣ�����ȥ�����ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);
        if (me->can_improve_skill("claw"))
                me->improve_skill("claw", 1500000);
        if (me->can_improve_skill("poyue-zhao"))
                me->improve_skill("poyue-zhao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/poyue-zhao/duan", 1);
        me->add("gongxian", -100);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhenyu-quan/tong"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("zhenyu-quan", 1) < 1)
                return "��������ȭ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -12000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 120)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("zhenyu-quan", 1) < 80)
                return "�������ȭ�������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ������ʾ��$N" HIY "������ǰ"
                     "��Ȼ������$N" HIY "�����������ֹ����˰��죬$N" HIY
                     "ֱ����ü����Ц��һ����һ�߲�ס�ص�ͷ��\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say �Ը���Щ������ʿ��һ������Ҫ������ʹ��ɱ�֡�");
        tell_object(me, HIC "��ѧ���ˡ��ٹ����ޡ���\n" NOR);
        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("zhenyu-quan"))
                me->improve_skill("zhenyu-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhenyu-quan/tong", 1);
        me->add("gongxian", -150);

        return 1;
}
