#include <ansi.h>
#include "wudu.h"

#define DUJING  "/clone/lonely/book/dujing2"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_me();

void create()
{
        set_name("���ư�", ({ "qi yunao", "qi", "yunao" }));
        set("nickname", HIB "���¶�ؤ" NOR);
        set("long", @LONG
�������嶾�̵ĳ��ϣ��˳ƽ��¶�ؤ������
�������ǽ�����ͬ��ʦ�֣��ڽ���һ�����
���裬��Ȩ��������������Ŀ��࣬��Ŀ��
������һ����ʽ��£�̫��Ѩ�߸߷���
LONG);
        set("title","�嶾�̳���");
        set("gender", "����");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 4500);
        set("max_jing", 4000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 120);
        set("combat_exp", 1800000);
        set("score", 10000);

        set_skill("force", 220);
        set_skill("wudu-xinfa", 220);
        set_skill("xiuluo-yinshagong", 180);
        set_skill("dodge", 180);
        set_skill("jinshe-youshenbu", 180);
        set_skill("strike", 200);
        set_skill("tianchan-zhang", 200);
        set_skill("claw", 200);
        set_skill("wusheng-zhao", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("jinwu-goufa", 180);
        set_skill("whip", 180);
        set_skill("xiewei-bian", 180);
        set_skill("ruanhong-zhusuo", 180);
        set_skill("throwing", 180);
        set_skill("literate", 100);
        set_skill("poison", 250);
        set_skill("wudu-qishu", 250 );
        set_skill("martial-cognize", 200);

        set("no_teach", ([
                "xiuluo-yinshagong" : "Ҫѧ������ɷ�����Ǽ���ȥ��",
                "ruanhong-zhusuo"   : "���书�����Ǽ��˴��ڵģ�Ҫѧ������ȥ��",
        ]));

        map_skill("force", "xiuluo-yinshagong");
        map_skill("dodge", "jinshe-youshenbu");
        map_skill("strike", "tianchan-zhang");
        map_skill("claw", "wusheng-zhao");
        map_skill("parry", "wusheng-zhao");
        map_skill("sword", "jinwu-goufa");
        map_skill("whip", "ruanhong-zhusuo");
        map_skill("poison", "wudu-qishu");
        prepare_skill("strike", "tianchan-zhang");
        prepare_skill("claw", "wusheng-zhao");

        create_family("�嶾��", 11, "����");

        set("inquiry", ([
                "����"     : "����Ҫ������ƪ����ƪ������ƪ��",
                "��ƪ"     :   "�����������ƪ��ȥ�������ҵĵ���Ҫ�ɡ�",
                "������ƪ" : "�����������ƪ��ȥ�������ҵĵ���Ҫ�ɡ�",
                "��ƪ"     : (: ask_me :),
                "������ƪ" : (: ask_me :),
                "��ƪ"     : "������ƪ�ڽ��������ȥ����Ҫ�ɡ�",
                "������ƪ" : "������ƪ�ڽ��������ȥ����Ҫ�ɡ�",
                "���߾�"   : (: ask_skill1 :),
                "�����"   : (: ask_skill2 :),
                "��������" : (: ask_skill3 :),
        ]));

        set("jinshe_count", 1);
        set("chat_chance", 2);
        set("chat_msg",({
                CYN "���ư�ŭ��������������ȥ�����������������ഴ�µĻ�ҵ"
                "��Ҫ�����������ˡ�\n" NOR,
                CYN "���ư�������������������ҵ������������Ķ�ʥ�������֮"
                "λ�����ҵ��ˡ�\n" NOR,
                CYN "���ư������������������Ӧ������ȥ���������أ�\n" NOR,
        }));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "claw.lian" :),
                (: perform_action, "strike.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/unarmed_damage", 200);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/wudu/npc/obj/jinyi")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -1000)
        {
                command("say ��Խ����Խ���������������Եס�");
                return;
        }
        if ((int)ob->query("shen") > -15000)
        {
                command("say ���Ĵ��������ǲ�������ģ�");
                return;
        }
        if ((int)ob->query("combat_exp") < 150000)
        {
                command("say �㻹����ȥ�����㾭��ɡ�");
                return;
        }
        if ((int)ob->query_skill("wudu-xinfa", 1) < 80)
        {
                command("say ����嶾�ķ���ѧ�Ĳ�������");
                return;
        }
        if ((int)ob->query_skill("wudu-qishu", 1) < 80)
        {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ���Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }

       command("nod");
       command("say ��������");
       command("recruit " + ob->query("id"));
       ob->set("title", "�嶾�̻���");
       return;
}

int accept_object(object who, object ob)
{
        object obn;

        if (! who || environment(who) != environment() ) return 0;
        if (! objectp(ob) ) return 0;
        if (! present(ob, who))
                return notify_fail("��û�����������\n");

        if ( (string)ob->query("id") != "longxian xiang")
                return notify_fail(CYN "���ư�ҡͷ������Щ���ö���������"
                                   "ʲô�ã�\n" NOR);

        message_vision(CYN "���ư����������㣬��ϲ�����⡭�⡭����������"
                       "������̫���ˡ�\n" NOR, who);

        if (query("jinshe_count") < 1)
        {
              	command("sigh");
              	command("say �����Ҹ�л���ʲô�ģ�����ͷʵ���ò�����������");
              	return 1;
	} else
	{
        	obn = new("/d/wudu/obj/jinsheduye");
        	obn->move(who);
        	add("jinshe_count", -1);
                command("say �����ϲ��ܰ�����Ķ���������һƿ���߶�Һ���͸���ɡ�");
        	message_vision("$N�ó�" YEL "���߶�Һ" NOR "(jinshe duye)��$n��\n",
                               this_object(), who);
              	return 1;
	}
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/xiewei-bian/tengshe"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������嶾�̵��ˣ��γ����ԣ�";

        if (me->query_skill("xiewei-bian", 1) < 1)
                return "����Ыβ�޶�ûѧ������ʲô���п��ԡ�";

        if (me->query("shen") > -20000)
                return "���������Ĵ���������ѧ������Ҳ�ɲ��˴��£�";

        if (me->query("gongxian") < 100)
                return "���ڽ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query_skill("xiewei-bian", 1) < 100)
                return "���Ыβ�޻������ң�Ҫ��������";

        message_vision(HIY "$n" HIY "���˵�ͷ����$N" HIY "��������"
                       "�ֹ��˼��䣬�ְγ����䳤\n�������һ������"
                       "��Ȼ��˳��һ�����޶��͵İεض�����\n���"
                       "��һ�㣬��Ϊ���\n" NOR, me,
                       this_object());
        command("nod");
        command("say ���кܼ򵥣���ȥ��������ɣ�");
        tell_object(me, HIC "��ѧ���ˡ����߾�����\n" NOR);
        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("xiewei-bian"))
                me->improve_skill("xiewei-bian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiewei-bian/tengshe", 1);
        me->add("gongxian", -100);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/tianchan-zhang/chan"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������嶾�̵��ˣ��γ����ԣ�";

        if (me->query_skill("tianchan-zhang", 1) < 1)
                return "��������Ʒ���ûѧ����̸���ԣ�";

        if (me->query("shen") > -35000)
                return "���������Ĵ���������ѧ������Ҳ�ɲ��˴��£�";

        if (me->query("gongxian") < 200)
                return "���ڽ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ���򲻹������������У�";

        if (me->query_skill("tianchan-zhang", 1) < 120)
                return "�������Ʒ��������ң�Ҫ��������";

        message_vision(HIY "$n" HIY "΢΢һЦ������ʾ��$N" HIY "������"
                       "ǰ��Ȼ����$N" HIY "��������\n�ֹ��˰��죬$N" HIY
                       "ֱ����ü����Ц��һ����һ�ߵ�ͷ��\n" NOR,
                       me, this_object());

        command("grin");
        command("say �����жԸ���Щ����ǿ�ĵ��ˡ��١����о��ܣ���������");
        tell_object(me, HIC "��ѧ���ˡ�����ơ���\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("tianchan-zhang"))
                me->improve_skill("tianchan-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tianchan-zhang/chan", 1);
        me->add("gongxian", -200);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();
        if (me->query("can_perform/wusheng-zhao/lian"))
                return "�Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "���������嶾�̵��ˣ��γ����ԣ�";

        if (me->query_skill("wusheng-zhao", 1) < 1)
                return "������ʥ��צ��ûѧ����̸���ԣ�";

        if (me->query("shen") > -40000)
                return "���������Ĵ���������ѧ������Ҳ�ɲ��˴��£�";

        if (me->query("gongxian") < 300)
                return "���ڽ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ���򲻹������������У�";

        if (me->query_skill("wusheng-zhao", 1) < 120)
                return "�����ʥ��צ�������ң�Ҫ��������";

        message_vision(HIY "$n" HIY "΢΢һЦ����Ȼ̽����ָ���ֳ���磬ץ"
                       "��$N" HIY "��$N" HIY "��\n�ɵô�ʧɫ����æ��Ծ��"
                       "������$n" HIY "��ָ���Ǵ�����$N" HIY "\n�ļ��ϡ�\n"
                       NOR, me, this_object());
        command("say �㶮����");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);
        if (me->can_improve_skill("claw"))
                me->improve_skill("claw", 1500000);
        if (me->can_improve_skill("wusheng-zhao"))
                me->improve_skill("wusheng-zhao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/wusheng-zhao/lian", 1);
        me->add("gongxian", -300);
        return 1;
}

mixed ask_me()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�嶾��")
                return "�����������ģ�������������ʲô��";

        if (me->query("shen") > -10000)
                return "������ô��ģ���ɱ�˶����᣿";

        if (me->query("combat_exp") < 100000)
                return "�����ھ���̫ǳ������æ��ȥ�Ķ�������";

        if (me->query_skill("poison", 1) > 119)
                return "���ö��������Ѿ���ǳ�ˣ��ⶾ������Ҳ�ա�";

        ob = find_object(DUJING);
        if (! ob) ob = load_object(DUJING);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "������������ô����ô�����������ˣ�";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š�������ƪ���ڲ��������";

                if (owner->query("family/family_name") == "�嶾��")
                        return "������������ͬ��" + owner->query("name") +
                               "�ڿ���ȥ�����ɡ�";
                else
                        return "�ҽ̵Ķ���������" + owner->query("name") +
                               "�����У���ȥ����������ɣ�";
        }
        ob->move(this_object());
        message_vision(CYN "$N" CYN "��ͷ��������ȥ���ɣ����в���֮��"
                       "���������ҡ�\n" NOR, this_object(), me);
        command("give du jing2 to " + me->query("id"));
        return 1;
}