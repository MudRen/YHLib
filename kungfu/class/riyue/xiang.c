#include <ansi.h>
#include "riyue.h"

#define CHILONG    "/clone/lonely/chilongsuo"
#define XINGLV     "/clone/item/xiaoao/xinglvtu"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_bian();
mixed ask_skill1();
mixed ask_skill2();

void create()
{
	object ob1, ob2;
        set_name("������", ({ "xiang wentian", "xiang", "wentian"}));
        set("nickname", HIR "��������" NOR );
        set("title", "������̹�����ʹ");
        set("long", @LONG 
������������̵Ĺ�����ʹ�����죬Ϊ�˼�Ϊ
��ˬ��ֻ�����׷��Բԣ�˫Ŀ�������䣬�ڹ�
���Ǿ�����
LONG);
        set("gender", "����");
        set("class", "scholar");
        set("age", 61);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 5800);
        set("max_jing", 4000);
        set("neili", 7600);
        set("max_neili", 7600);
        set("jiali", 200);
        set("combat_exp", 3000000);
        set("score", 50000);

        set_skill("force", 280);
        set_skill("xixing-xiaofa", 280);
        set_skill("tianhuan-shenjue", 280);
        set_skill("riyue-xinfa", 260);
        set_skill("dodge", 260);
        set_skill("feiyan-zoubi", 260);
        set_skill("juechen-shenfa", 260);
        set_skill("strike", 240);
        set_skill("qingmang-zhang", 240);
        set_skill("cuff", 260);
        set_skill("zhenyu-quan", 260);
        set_skill("claw", 260);
        set_skill("poyue-zhao", 260);
        set_skill("parry", 280);
        set_skill("whip", 280);
        set_skill("panlong-suo", 280);
        set_skill("blade", 260);
        set_skill("danding-dao", 260);
        set_skill("throwing", 240);
        set_skill("heixue-shenzhen", 240);
        set_skill("martial-cognize", 260);
        set_skill("literate", 240);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "xixing-xiaofa");
        map_skill("strike", "qingmang-zhang");
        map_skill("whip", "panlong-suo");
        map_skill("parry", "panlong-suo");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");
        map_skill("blade", "danding-dao");
        map_skill("throwing", "heixue-shenzhen");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        set("no_teach", ([
                "xixing-xiaofa" : "�ⶫ�������Լ�������ģ��ó�ȥδ����Ц�󷽡�",
        ]));

        create_family("�������", 13, "������ʹ");

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("inquiry", ([
                "��������" : (: ask_bian :),
                "�ƹǲ���" : (: ask_skill1 :),
                "������ɱ" : (: ask_skill2 :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "whip.chan" :),
		(: perform_action, "whip.sha" :),
                (: perform_action, "cuff.tong" :),
                (: perform_action, "claw.duan" :),
                (: perform_action, "throwing.luo" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();

        if (clonep())
        {
                ob1 = find_object(XINGLV);
                if (! ob1) ob1 = load_object(XINGLV);
                if (! environment(ob1)) ob1->move(this_object());

                ob2 = find_object(CHILONG);
                if (! ob2) ob2 = load_object(CHILONG);
                if (! environment(ob2))
                {
                        ob2->move(this_object());
                        ob2->wield();
                } else
                {
                        ob2 = new("/clone/weapon/changbian");
                        ob2->move(this_object());
                        ob2->wield();
                }
        }
        carry_object("/d/heimuya/npc/obj/jinpao")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -50000)
        {
                command("killair");
                command("say ����������α���ӣ��ٲ������ұ����㣡");
                return;
        }

        if (ob->query("combat_exp") < 300000)
        {
                command("say �����ڽ�������̫ǳ��Ӧ�ö��߶��߶���");
                return;
        }

	if (ob->query_int() < 30)
	{
		command("sneer");
		command("say ƾ�������������ʲô��");
		return;
	}

        if (ob->query_skill("tianhuan-shenjue", 1) < 140
           && ob->query_skill("riyue-xinfa", 1) < 140)
        {
                command("hmm");
                command("say ����������������ڹ���û�޺ã���ôѧϰ�ϳ���ѧ��");
                return;
        }

        command("haha");
        command("say ������Ҳ���������ˣ������Ϸ������Ϊͽ��");
        command("say �������һͳ������ǧ���ҵ����ȫ�������ˡ�");
        command("recruit " + ob->query("id"));
        return;
}

mixed ask_bian()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�������")
                return "���ҹ����������Ϸ���ǰ���£�";

        if (me->query("family/master_id") != "ren woxing"
           && me->query("family/master_id") != "xiang wentian")
                return "�ߣ��ڽ��п��»��ֲ�����˵����";

        if (me->query("shen") > -100000)
                return "�������Ĵ�����ɲ��˴��£��������㲻��Ҳ�ա�";

        if (me->query_skill("panlong-suo", 1) < 140)
                return "����������������ûѧ�ã���������������к��ã�";

        ob = find_object(CHILONG);
        if (! ob) ob = load_object(CHILONG);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ţ������������ڲ�������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ���������������Ѿ����ȥ�ˡ�";

                if (owner->query("family/family_name") == "�������")
                        return "�Ϸ�ĳ�������������" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�Ϸ�ĳ�����������������" + owner->query("name") +
                               "֮�֣���ȥ����ȡ�����ɣ�";
        }
        ob->move(this_object());

        command("nod");
        command("say ����ȥ�ðɡ�");
        command("give chilong jinsuo to " + me->query("id"));

        ob = new("/clone/weapon/changbian");
        ob->move(this_object());
        ob->wield();
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/panlong-suo/chan"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("panlong-suo", 1) < 1)
                return "����������������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 500)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -120000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 180)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("panlong-suo", 1) < 120)
                return "������������������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ���漴�㽫$N" HIY "�������"
                     "���ڶ��Ե���ϸ˵���ã�$N" HIY "������ĵ�һЦ������"
                     "��������\n\n" NOR, me, this_object()); 

        command("nod2");
        command("say �ղ���˵��ȫ�Ǵ��еľ�Ҫ����Ҫ�����ˡ�");
        tell_object(me, HIC "��ѧ���ˡ��ƹǲ��꡹��\n" NOR);
        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("panlong-suo"))
                me->improve_skill("panlong-suo", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/panlong-suo/chan", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/panlong-suo/sha"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("panlong-suo", 1) < 1)
                return "����������������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1500)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -160000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 220)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("panlong-suo", 1) < 180)
                return "������������������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "����ص��˵�ͷ����������"
                     "Ȼ������Ϊ���̳����������Ϸ�㴫����У��ɿ����ˡ�"
                     "��˵��$n" HIY "�������֣�$N" HIY "��æӭ��ǰȥ��ֻ"
                     "��$n" HIY "������$N" HIY "˵��Щ�����������г���һ"
                     "������ʱ�ó������Ӱ����������ͨ�죬������Ӱ������"
                     "�˷������ȥ��\n\n" NOR, me, this_object()); 

        command("nod2");
        command("say ��ʽ������ˣ��ܷ�����Ϳ����Լ��ˡ�");
        tell_object(me, HIC "��ѧ���ˡ�������ɱ����\n" NOR);
        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("panlong-suo"))
                me->improve_skill("panlong-suo", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/panlong-suo/sha", 1);
        me->add("gongxian", -1500);

        return 1;
}

void unconcious()
{
        die();
}
