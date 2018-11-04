#include <ansi.h>
#include "riyue.h"

#define POYANG    "/clone/lonely/poyangfu"

inherit NPC;
inherit F_MASTER;

mixed ask_fu();
mixed ask_skill1();

void create()
{
	object ob;
        set_name("����", ({"fan song", "fan", "song"}));
        set("nickname", HIR "������ħ" NOR );
        set("title", "�������ǰ������");
        set("long", @LONG
������ħ��������������̵�ǰ�����ϣ��书
��ǿ��λ���ޱȡ���һ��ɨ�������������ˡ�
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
        
        set("max_qi", 5400);
        set("max_jing", 4000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 220);
        set("combat_exp", 3000000);
        set("score", 50000);

        set_skill("force", 260);
        set_skill("tianhuan-shenjue", 260);
        set_skill("riyue-xinfa", 220);
        set_skill("dodge", 220);
        set_skill("juechen-shenfa", 220);
        set_skill("cuff", 240);
        set_skill("zhenyu-quan", 240);
        set_skill("claw", 240);
        set_skill("poyue-zhao", 240);
        set_skill("parry", 240);
        set_skill("hammer", 260);
        set_skill("pangu-qishi", 260);
        set_skill("club", 220);
        set_skill("jinyuan-gun", 220);
        set_skill("martial-cognize", 240);
        set_skill("literate", 180);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "tianhuan-shenjue");
        map_skill("hammer", "pangu-qishi");
        map_skill("club", "jinyuan-gun");
        map_skill("parry", "pangu-qishi");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        create_family("�������", 7, "ǰ������");

        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("inquiry", ([
                "������" : (: ask_fu :),
                "����ٵ�" : (: ask_skill1 :),
        ]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "hammer.kai" :),
                (: perform_action, "cuff.tong" :),
                (: perform_action, "claw.duan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();

        if (clonep())
        {
                ob = find_object(POYANG);
                if (! ob) ob = load_object(POYANG);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("/d/heimuya/npc/obj/dafu");
                        ob->move(this_object());
                        ob->wield();
                }
        }
        carry_object("/d/heimuya/npc/obj/jinpao")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("say �߿����Ҳ���ͽ��");
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "�������")
        {
                command("killair");
                command("say ���ҹ����������Ϸ���ǰ˵�����ģ�");
                return -1;
        }

        if (ob->query("family/master_id") != "ren woxing")
        {
                command("sneer");
                command("say �㻹���䡣");
                return -1; 
        }

        if ((int)ob->query("shen") > -80000)
        {
                command("hmm");
                command("say �Ϸ���ƽ��ʹ�޵ľ����������ļ��ʼ���֮ͽ��");
                return -1;
        }

        if (skill != "hammer" && skill != "pangu-qishi")
        {
                command("hmm");
                command("say ��ֻ���������״��������������ʦ��ѧȥ��");
                return -1;
        }

        if (skill == "hammer" && ob->query_skill("hammer", 1) > 179)
        {
                command("say �㴸���������Ѿ���ͬ�����ˣ�ʣ�¾��Լ�ȥ���ɡ�");
                return -1;
        }

        if (ob->query("str") < 32)
        {
                command("say �����������Ϸ���Դ�����һ�׾�����");
                command("say ���ǹ�����������̫���ϧ������ϧ����");
                return -1;
        }

        if (! ob->query_temp("can_learn/fansong"))
        {
                command("haha");
                command("say �벻�����о�Ȼ���������������");
                command("say �����̹������˱����񼼣������Ҿʹ������㡣");
                ob->set_temp("can_learn/fansong", 1);
        }
        return 1;
}

mixed ask_fu()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�������")
                return "���ҹ�����";

        if (me->query("family/master_id") != "ren woxing")
                return "�㻹���䣡";

        if (me->query("shen") > -100000)
                return "�������Ĵ���������������ʲô�ã�";

        if (me->query_skill("pangu-qishi", 1) < 150)
                return "�����̹����ƶ�ûѧ�ã���������������к��ã�";

        ob = find_object(POYANG);
        if (! ob) ob = load_object(POYANG);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "���������ڲ�������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�������������Ѿ����ȥ�ˡ�";

                if (owner->query("family/family_name") == "�������")
                        return "�Ϸ��������������" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�Ϸ������������������" + owner->query("name") +
                               "֮�֣���ȥ����ȡ�����ɣ�";
        }
        ob->move(this_object());

        command("say ��Ȼ�������Ϸ�����������ȥ��");
        command("say ��������ɱ����������ʿ������զ��������̵����硣");
        command("give poyang fu to " + me->query("id"));

        ob = new("/d/heimuya/npc/obj/dafu");
        ob->move(this_object());
        ob->wield();
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/pangu-qishi/kai"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����������̵ģ�������ʲô�ң�";

        if (me->query_skill("pangu-qishi", 1) < 1)
                return "�����̹����ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1200)
                return "���ڽ���������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") > -120000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 300)
                return "����ڹ����������ߣ��������������Ұɡ�";

        if (me->query_skill("pangu-qishi", 1) < 180)
                return "����̹����ƻ����ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "΢΢���˵�ͷ��˵��������"
                     "���ˣ���˵��$n" HIY "һ���Ϻȣ����о޸���ɽ��Ρ�ţ�"
                     "Я�ſ���ٵ�֮���������£����ƻֺ�֮������ʱֻ����"
                     "Ȼһ�����죬$n" HIY "��ǰ��ɽ���ѱ�����һ���������"
                     "�ѷ죬����֮ǿ�����ν�Ǿ���أ�������ֱ��$N" HIY
                     "����Ŀ�ɿڴ���\n\n" NOR, me, this_object()); 

        command("nod2");
        command("say ��ʽ������ˣ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����ٵء���\n" NOR);
        if (me->can_improve_skill("hammer"))
                me->improve_skill("hammer", 1500000);
        if (me->can_improve_skill("pangu-qishi"))
                me->improve_skill("pangu-qishi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pangu-qishi/kai", 1);
        me->add("gongxian", -1200);

        return 1;
}
