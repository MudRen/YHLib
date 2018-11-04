#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;

mixed ask_me();
mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();

void create()
{
	set_name("ɣ����", ({ "sang sanniang", "sang", "sanniang"}));
        set("title", "������������ó���");
        set("nickname", HIR "����ʹ��" NOR);
        set("long", @LONG
���������������������ɣ���ֻ��������
�Ź֣�����˿��΢Ц������ȴ�൱���㡣
LONG);
	set("gender", "Ů��" );
        set("class", "scholar");
        set("age", 41);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 5400);
        set("max_neili", 5400);
        set("jiali", 150);
        set("combat_exp", 2000000);
        set("score", 10000);

        set_skill("force", 180);
        set_skill("riyue-xinfa", 180);
        set_skill("tianhuan-shenjue", 180);
        set_skill("dodge", 200);
        set_skill("feiyan-zoubi", 200);
        set_skill("juechen-shenfa", 200);
        set_skill("dagger", 180);
        set_skill("jifeng-cixuefa", 180);
        set_skill("hand", 200);
        set_skill("lansha-shou", 200);
        set_skill("strike", 160);
        set_skill("qingmang-zhang", 160);
        set_skill("cuff", 140);
        set_skill("zhenyu-quan", 140);
        set_skill("claw", 140);
        set_skill("poyue-zhao", 140);
        set_skill("parry", 180);
        set_skill("throwing", 200);
        set_skill("heixue-shenzhen", 200);
        set_skill("martial-cognize", 180);
        set_skill("literate", 220);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "tianhuan-shenjue");
        map_skill("dagger", "jifeng-cixuefa");
        map_skill("hand", "lansha-shou");
        map_skill("parry", "lansha-shou");
        map_skill("strike", "qingmang-zhang");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");
        map_skill("throwing", "heixue-shenzhen");

        prepare_skill("hand", "lansha-shou");

        set("no_teach", ([
                "tianhuan-shenjue" : "�����ڹ��㻹��ȥ���������Ͻ���ɡ�",
        ]));

        create_family("�������", 13, "�����ó���");

        set("inquiry", ([
                "��Ѫ����" : (: ask_me :),
                "�Ƶ���ɰ" : (: ask_skill1 :),
                "�����岼" : (: ask_skill2 :),
                "��Ы����" : (: ask_skill3 :),
        ]));

        set("zhen_count", 3);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
                (: perform_action, "hand.po" :),
                (: perform_action, "throwing.luo" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();

        carry_object("/d/heimuya/npc/obj/jinpao")->wear();
        set_temp("handing", carry_object("/d/heimuya/npc/obj/shenzhen"));
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -15000)
        {
                command("sneer");
                command("say ��Ϊ�������ֱ������������������̣�");
                return;
        }

        if (ob->query("combat_exp") < 100000)
        {
                command("say �����ڽ�������̫ǳ����Ӧ�ö��߶��߶���");
                return;
        }

        if (ob->query_skill("tianhuan-shenjue", 1) < 50
           && ob->query_skill("riyue-xinfa", 1) < 50)
        {
                command("hmm");
                command("say ����ô��������������ڹ���ûѧ�ã�");
                return;
        }

        command("say �������š�������͸����Ұɡ�");
        command("say ��������ڹ���ڶ࣬���ٸ������¡�");
        command("recruit " + ob->query("id"));
        return;
}

mixed ask_me()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ҹ�������������ǰ���¡�";

        if ((int)me->query("shen") > -30000)
                return "���������Ĵ���������������ȥҲûʲô�á�";

        if ((int)me->query_skill("heixue-shenzhen", 1) < 140)
                return "���Ѫ������ַ��������ң�����������ȥҲûʲô�á�";

        if (query("zhen_count") < 1)
                return "���ֲ���������ģ������������ô�ࡣ";

        add("zhen_count", -1);
        ob = new("/d/heimuya/npc/obj/shenzhen");
        message_vision("$N�ó���ʮ��" WHT "��Ѫ����" NOR "(Heixue shenzhen)��$n��\n",
                       this_object(), me);
        ob->move(me, 1);
        return "������ĺ�Ѫ����������ȥ�ðɡ�";
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/lansha-shou/po"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("lansha-shou", 1) < 1)
                return "������ɰ�ֶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -20000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 150)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("lansha-shou", 1) < 100)
                return "�����ɰ�ֻ����ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "Ц��Ц��Ҳ���𻰣�ͻȻ"
                     "�����μ�ת���������ȣ���Ȼ�����ָ��$N" HIY "��ǰ"
                     "ץ�䣬$N" HIY "��״��ʧɫ����æ��Ų���㣬����Ȼ"
                     "������$n" HIY "��ָ���÷���$N" HIY "����ǰ��\n\n"
                     NOR, me, this_object()); 

        command("haha");
        command("say ��ʽ�ַ������������͵Ϯ�ٺ��ʲ�����");
        tell_object(me, HIC "��ѧ���ˡ��Ƶ���ɰ����\n" NOR);
        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("lansha-shou"))
                me->improve_skill("lansha-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/lansha-shou/po", 1);
        me->add("gongxian", -200);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/heixue-shenzhen/luo"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("heixue-shenzhen", 1) < 1)
                return "������Ѫ���붼ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -35000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 200)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("heixue-shenzhen", 1) < 140)
                return "��ĺ�Ѫ���뻹���ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "����һЦ����$N" HIY "������ǰ����"
                     "���ڶ�������˵��Щʲô�������������֣�ʮָ����"
                     "��һ��һ������������һ�ֺ��ر�İ������š�\n\n"
                     NOR, me, this_object()); 

        command("nod");
        command("say �ղ���˵��ȫ�Ǿ�Ҫ�����Ҫ������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ������岼����\n" NOR);
        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("heixue-shenzhen"))
                me->improve_skill("heixue-shenzhen", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/heixue-shenzhen/luo", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jifeng-cixuefa/cang"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("jifeng-cixuefa", 1) < 1)
                return "���������Ѩ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 200)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -15000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 120)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("dodge") < 120)
                return "����Ṧ���������ߣ��������������Ұɡ�";

        if (me->query_skill("jifeng-cixuefa", 1) < 100)
                return "��ļ����Ѩ�������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "���˵�ͷ���漴���$N"
                     HIY "�����нӹ�ذ�ף�һ��߳�ȣ������̳����У�ֻ"
                     "�������������������֮�����������������澫"
                     "���ޱȡ�\n\n" NOR, me, this_object()); 

        command("nod");
        command("say ���е�Ҫ�㲻��һ�����֣���ʵ�Ǻܼ򵥵���ʽ��");
        tell_object(me, HIC "��ѧ���ˡ���Ы���롹��\n" NOR);
        if (me->can_improve_skill("dagger"))
                me->improve_skill("dagger", 1500000);
        if (me->can_improve_skill("jifeng-cixuefa"))
                me->improve_skill("jifeng-cixuefa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jifeng-cixuefa/cang", 1);
        me->add("gongxian", -200);

        return 1;
}
