#include <ansi.h>
#include "wudu.h"

#define SHEYING     "/clone/lonely/sheying"
#define JINWUGOU    "/clone/lonely/jinwugou"
#define ZHUSUO      "/clone/lonely/zhusuo"
#define DUJING      "/clone/lonely/book/dujing3"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_gou();
mixed ask_suo();
mixed ask_she();
mixed ask_jing();

void create()
{
        object ob, ob2;
        set_name("������", ({ "he tieshou", "he", "tieshou" }));
        set("nickname", HIR "�嶾����" NOR);
        set("long",@LONG
��������һ��һ��ۺ�ɴȹ��Ц���绨����Ů��
�����ü���ѩ�ף�üĿ�续������һ˫���۵���
�㣬�ֽ��϶����������Ľ���˭���뵽������
�嶾�̵Ľ��������֣�������ʿ�������޲�����
�ľ���
LONG);
        set("title", "�嶾�̽���");
        set("gender", "Ů��");
        set("age", 25);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 5000);
        set("max_jing", 4000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 200);
        set("combat_exp", 2500000);
        set("score", 10000);

        set_skill("force", 260);
        set_skill("wudu-xinfa", 240);
        set_skill("xiuluo-yinshagong", 260);
        set_skill("dodge", 240);
        set_skill("jinshe-youshenbu", 240);
        set_skill("strike", 240);
        set_skill("tianchan-zhang", 240);
        set_skill("claw", 240);
        set_skill("wusheng-zhao", 240);
        set_skill("parry", 240);
        set_skill("sword", 260);
        set_skill("jinwu-goufa", 260);
        set_skill("whip", 260);
        set_skill("ruanhong-zhusuo", 260);
        set_skill("xiewei-bian", 260);
        set_skill("throwing", 240);
        set_skill("hansha-sheying", 240);
        set_skill("literate", 220);
        set_skill("poison", 300);
        set_skill("wudu-qishu", 300 );
        set_skill("martial-cognize", 240);

        map_skill("force", "xiuluo-yinshagong");
        map_skill("dodge", "jinshe-youshenbu");
        map_skill("strike", "tianchan-zhang");
        map_skill("claw", "wusheng-zhao");
        map_skill("throwing", "hansha-sheying");
        map_skill("parry", "jinwu-goufa");
        map_skill("sword", "jinwu-goufa");
        map_skill("whip", "ruanhong-zhusuo");
        map_skill("poison", "wudu-qishu");

        prepare_skill("claw", "wusheng-zhao");
        prepare_skill("strike", "tianchan-zhang");

        create_family("�嶾��", 11, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "whip.teng" :),
                (: perform_action, "whip.pan" :),
                (: perform_action, "whip.bohu" :),
                (: perform_action, "whip.suo" :),
                (: perform_action, "claw.lian" :),
                (: perform_action, "strike.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        set("inquiry", ([
                "���ڹ�"   : (: ask_gou :),
                "�������" : (: ask_suo :),
                "��ɳ��Ӱ" : (: ask_she :),
                "����"     : "����Ҫ������ƪ����ƪ������ƪ��",
                "��ƪ"     : "������ƪ��ȥ�������ҵĵ���Ҫ�ɡ�",
                "������ƪ" : "������ƪ��ȥ�������ҵĵ���Ҫ�ɡ�",
                "��ƪ"     : "������ƪ���볤�����У���ȥ����Ҫ�ɡ�",
                "������ƪ" : "������ƪ���볤�����У���ȥ����Ҫ�ɡ�",
                "��ƪ"     : (: ask_jing :),
                "������ƪ" : (: ask_jing :),
                "����"     : "��Ҫ��ʲô���У�",
                "����"     : "��Ҫ��ʲô������",
                "�򶾿�"   : "ֻ���ҵĵ��Ӳ��ܽ����򶾿ߡ�",
                "���߾�"   : "��һ����ȥ���볤��ѧ�ɡ�",
                "��ӥ��"   : (: ask_skill1 :),
                "������"   : (: ask_skill2 :),
                "������"   : (: ask_skill3 :),
                "�𹳶���" : (: ask_skill4 :),
                "��Ӱ��"   : (: ask_skill5 :),
        ]));

	if (clonep())
	{
                ob = find_object(ZHUSUO);
                ob2 = find_object(SHEYING);

                if (! ob) ob = load_object(ZHUSUO);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = find_object(JINWUGOU);
                        if (! ob) ob = load_object(JINWUGOU);
                        if (! environment(ob))
                        {
	                        ob->move(this_object());
        	                ob->wield();
                        } else
                        {
                        	ob = new("/clone/weapon/changbian");
                        	ob->move(this_object());
                       		ob->wield();
                        }
                }
                if (! ob2) ob2 = load_object(SHEYING);
                if (! environment(ob2))
                {
                        ob2->move(this_object());
                        ob2->wear();
                }
        }
        carry_object("/d/city/npc/cloth/moon-dress")->wear();
}

void init()
{
        add_action("do_show", "show");
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

        if ((int)ob->query("shen") > -50000)
        {
                command("say ���������Ĵ���������Ǹɲ��ɴ��µģ�");
                return;
        }

        if ((int)ob->query("combat_exp") < 350000)
        {
                command("say �����ھ�����ǳ��������������书��������ȥ�����㾭��ɡ�");
                return;
        }

        if ((int)ob->query_skill("wudu-xinfa", 1) < 120)
        {
                command("say ����嶾�ķ���ѧ�Ĳ�������");
                return;
        }

        if ((int)ob->query_skill("wudu-qishu", 1) < 120)
        {
                command("say ��ѱ��ŵ�ʩ����ѧ����͸���������Ұɡ�");
                return;
        }

        command("say �ðɣ���Ȼ��˱���������������ͽ�ܡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", "�嶾�̳���");
        return;
}

mixed ask_gou()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_good())
        {
                if (me->query("family/family_name") == "�嶾��")
                        message_vision(CYN "$N" CYN "���һ������$n" CYN "����"
                                       "������Ϊ���嶾�̵��ӣ�����ѧ����ʼ���"
                                       "���ˣ���Ȼ����������Ҫ�𹳣���\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��Цһ������$n" CYN "˵��"
                                       "��������ʲô�ˣ���Ȼ��������ǰ�������"
                                       "����\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "�嶾��")
                return "�㲻�������嶾�̵ģ���������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ����ý��ڹ�������ȥ��ֻ�����Ҷ�����";

        if (me->query("shen") > -35000)
                return "�������Ĵ���������㲻��Ҳ�ա�";

        if (me->query_skill("jinwu-goufa", 1) < 120)
                return "�������ڹ�����ûѧ�ã������ý�Ҳ�ǰ״";

        ob = find_object(JINWUGOU);
        if (! ob) ob = load_object(JINWUGOU);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ţ����ڹ����ڲ���������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�������Ѿ��ѽ��ڹ������ͬ��ʦ�ֵ���ȥ�ˡ�";

                if (owner->query("family/family_name") == "�嶾��")
                        return "���ڹ�������ʱ����ͬ��ʦ�ֵ�" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���ŵĽ��ڹ���������" + owner->query("name") +
                               "���У���ȥ�����������ɣ�";
        }

        ob->move(this_object());

        ob = new("clone/weapon/changbian");
        ob->move(this_object());
        ob->wield();

        message_vision(CYN "$N" CYN "΢΢һЦ��������������ڹ����"
                       "��ȥ������Щ������ʿ�������嶾�̵���������\n" NOR,
                       this_object(), me);
        command("give jinwu gou to " + me->query("id"));
        return 1;
}

mixed ask_suo()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_good())
        {
                if (me->query("family/family_name") == "�嶾��")
                        message_vision(CYN "$N" CYN "���һ������$n" CYN "����"
                                       "������Ϊ���嶾�̵��ӣ�����ѧ����ʼ���"
                                       "���ˣ���Ȼ����������Ҫ�����������\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��Цһ������$n" CYN "˵��"
                                       "��������ʲô�ˣ���Ȼ��������ǰ�������"
                                       "����\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "�嶾��")
                return "�㲻�������嶾�̵ģ���������ʲô��";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ������������������ȥ��ֻ�����Ҷ�����";

        if (me->query("shen") > -35000)
                return "�������Ĵ������������㲻��Ҳ�ա�";

        if (me->query_skill("ruanhong-zhusuo", 1) < 150)
                return "�������������ûѧ�ã�����������Ҳ�ǰ״";

        ob = find_object(ZHUSUO);
        if (! ob) ob = load_object(ZHUSUO);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ţ�����������ڲ���������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�������Ѿ���������������ͬ��ʦ�ֵ���ȥ�ˡ�";

                if (owner->query("family/family_name") == "�嶾��")
                        return "�������������ʱ����ͬ��ʦ�ֵ�" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���ŵ����������������" + owner->query("name") +
                               "���У���ȥ�����������ɣ�";
        }

        ob->move(this_object());

        ob = new("/clone/weapon/changbian");
        ob->move(this_object());
        ob->wield();

        message_vision(CYN "$N" CYN "΢΢һЦ���������������������"
                       "��ȥ������Щ������ʿ�������嶾�̵���������\n" NOR,
                       this_object(), me);
        command("give ruanhong zhusuo to " + me->query("id"));
        return 1;
}

mixed ask_she()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->is_good())
        {
                if (me->query("family/family_name") == "�嶾��")
                        message_vision(CYN "$N" CYN "���һ������$n" CYN "����"
                                       "������Ϊ���嶾�̵��ӣ�����ѧ����ʼ���"
                                       "���ˣ���Ȼ����������Ҫ��ɳ��Ӱ����\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "��Цһ������$n" CYN "˵��"
                                       "��������ʲô�ˣ���Ȼ��������ǰ�������"
                                       "����\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "�嶾��")
                return "�㲻�������嶾�̵ģ���������ʲô��";

        if (me->query("shen") > -10000)
                return "�������Ĵ������⺬ɳ��Ӱ�㲻��Ҳ�ա�";

        if (me->query_skill("hansha-sheying", 1) < 50)
                return "�����Ű����ַ�̫��ò��û����˼�����";

        ob = find_object(SHEYING);
        if (! ob) ob = load_object(SHEYING);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�ţ���ɳ��Ӱ���ڲ���������������";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��ɳ��Ӱ���ڲ��������";

                if (owner->query("family/family_name") == "�嶾��")
                        return "��ɳ��Ӱ������ʱ����ͬ��" + owner->query("name") +
                               "���ã���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "�ҵĺ�ɳ��Ӱ��������" + owner->query("name") +
                               "���У���ȥ�����������ɣ�";
        }
        ob->move(this_object());

        message_vision(CYN "$N" CYN "΢΢һЦ��������ɳ��Ӱ����ȥ�ɣ������ǳ�����"
                       "���嶾�̵�������\n" NOR, this_object(), me);
        command("give hansha sheying to " + me->query("id"));
        command("whisper " + me->query("id") + " �⺬ɳ��Ӱ��Ķ��������ˣ�������"
                "(show)�������Ҹ���װ��");
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/ruanhong-zhusuo/panying"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("ruanhong-zhusuo", 1) < 1)
                return "�������������ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 300)
                return "���ڽ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") > -30000)
                return "�Ĵ����������Զ�ɲ��˴����������㲻ѧҲ�գ�";

        if (me->query_skill("ruanhong-zhusuo", 1) < 130)
                return "���������������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ��������ȡ�³�������������һ������"
                     "ʱ��Ӱ���أ���ȫ����$N" HIY "�����ܣ�ֱ����$N" HIY "Ŀ�ɿ�"
                     "����\n\n" NOR, me, this_object()); 

        command("nod");
        command("say ��һ�б����������������ӥ������ɿ������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ���ӥ������\n" NOR);

        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("ruanhong-zhusuo"))
                me->improve_skill("ruanhong-zhusuo", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/ruanhong-zhusuo/panying", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/ruanhong-zhusuo/bohu"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("ruanhong-zhusuo", 1) < 1)
                return "�������������ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 1300)
                return "���ڽ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") > -50000)
                return "�Ĵ����������Զ�ɲ��˴����������㲻ѧҲ�գ�";

        if (me->query_skill("ruanhong-zhusuo", 1) < 160)
                return "���������������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ�����������������㴫�����У����"
                     "�����ˣ���$n" HIY "˵�գ�������ȡ�³�����һ�����ȣ����г�"
                     "�����裬�����Ӱ��ʱ��������СȦ������ǵ�����$N" HIY "��"
                     "\n\n" NOR, me, this_object());

        command("nod");
        command("say ��һ�б������������������������ɿ������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("ruanhong-zhusuo"))
                me->improve_skill("ruanhong-zhusuo", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/ruanhong-zhusuo/bohu", 1);
        me->add("gongxian", -1300);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/ruanhong-zhusuo/suolong"))
                return "�㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("ruanhong-zhusuo", 1) < 1)
                return "�������������ûѧ����̸���ԣ�";

        if (me->query("shen") > -80000)
                return "�Ĵ����������Զ�ɲ��˴����������㲻ѧҲ�գ�";

        if (me->query("gongxian") < 1500)
                return "���ڽ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query_skill("ruanhong-zhusuo", 1) < 160)
                return "���������������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "����ص��˵�ͷ����������Ȼ����"
                     "�����ģ���������ٴ������У���˵��$n" HIY "�������֣�$N"
                     HIY "��æ����ǰȥ��ֻ��$n" HIY "������$N" HIY "˵��Щ����"
                     "�������г���һ������ʱ�ó������Ӱ����������ͨ�죬������"
                     "Ӱһ��������˷�ϯ���ȥ��\n\n" NOR, me, this_object());

        command("sweat");
        command("nod");
        command("say ��һ�б��������������������������ȥ���ڼ���ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("ruanhong-zhusuo"))
                me->improve_skill("ruanhong-zhusuo", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/ruanhong-zhusuo/suolong", 1);
        me->add("gongxian", -1500);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();
        if (me->query("can_perform/jinwu-goufa/duo"))
                return "�������Ѿ��̹����ˣ������Լ���ȥ�����ϰ�ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("jinwu-goufa", 1) < 1)
                return "�������ڹ�����ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 1300)
                return "���ڽ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") > -80000)
                return "�ߣ��������Ĵ������ܸɳ�ʲô�£������㲻ѧҲ�գ�";

        if (me->query_skill("jinwu-goufa", 1) < 160)
                return "��Ľ��ڹ��������ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "΢΢���˵�ͷ����$N" HIY "��������˵��Щ��"
                     "��һ��˵��һ�߱Ȼ���Щʲô�������㣬�������á���\n\n"
                     NOR, me, this_object());

        command("say �ղ���Щ�������еĿھ���������Ҫ�죬���Ҫ�����ˡ�");
        command("nod");
        command("say ���н𹳶��ǱȽ����������Լ�������Ҫ����о���");
        tell_object(me, HIC "��ѧ���ˡ��𹳶��ǡ���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("jinwu-goufa"))
                me->improve_skill("jinwu-goufa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jinwu-goufa/duo", 1);
        me->add("gongxian", -1300);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();
        if (me->query("can_perform/hansha-sheying/zhen"))
                return "�����Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("hansha-sheying", 1) < 1)
                return "������ɳ��Ӱ��ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 300)
                return "���ڽ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") > -80000)
                return "�ߣ��������Ĵ������ܸɳ�ʲô�£������㲻ѧҲ�գ�";

        if (me->query_skill("hansha-sheying", 1) < 120)
                return "��ĺ�ɳ��Ӱ�����ò����ң��Լ���ȥ���������ɣ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ�����ֽ�$N" HIY "�е���ǰ����$N"
                     HIY "���������ֹ���Щ����$N" HIY "���˰��죬ͻȻ�䲻�ɻ�"
                     "�ĵ�һЦ��������������\n\n" NOR, me, this_object());

        command("nod");
        command("say ���в������ӣ���������͵Ϯ�Ͱ������ȴ����Ч����������ɣ�");
        tell_object(me, HIC "��ѧ���ˡ���Ӱ�롹��\n" NOR);
        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("hansha-sheying"))
                me->improve_skill("hansha-sheying", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/hansha-sheying/zhen", 1);
        me->add("gongxian", -300);
        return 1;
}

int accept_object(object me, object ob)
{
        int r;
        if (r = ::accept_object(me, ob))
                return r;

        if (base_name(ob) != JINWUGOU
        && base_name(ob) != ZHUSUO)
        {
                command("say ��������ֶ�����ʲô��");
                return 0;
        }

        if (me->query("family/master_id") != query("id"))
                command("say ��л��λ" + RANK_D->query_respect(me) + "�����ű��ｻ�ء�");
        else
                command("say �ܺã��ܺã�");
        destruct(ob);
        return 1;
}

mixed ask_jing()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "�嶾��")
                return "����˭������ʶ��ô��";

        if (me->query("shen") > -30000)
                return "�������ĳ���ô�ã���ȥѧ��������";

        if (me->query("combat_exp") < 150000)
                return "�����ھ���̫ǳ������æ��ȥ�Ķ�������";

        if (me->query_skill("wudu-qishu", 1) > 149)
                return "��Ա��ŵĶ����Ѿ�ͨ���ñȽ�͸���ˣ������Լ����о��ɡ�";

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
        command("give du jing3 to " + me->query("id"));
        return 1;
}

int do_show(string arg)
{
        object ob;
        object me;
        int n;

        if (! arg)
                return notify_fail("��Ҫ����ʲô������\n");

        me = this_player();

        if (! objectp(ob = present(arg, me)))
                return notify_fail("������û�����ֶ�����\n");

        if (me->query("family/family_name") != "�嶾��")
                return notify_fail(CYN "����������������һ�ۣ�û���㡣\n" NOR);

        if ((string)ob->query("id") != "hansha sheying")
                return notify_fail(CYN "������������üͷ��˵��������ҿ����"
                                   "���\n" NOR);

        if (ob->query("equipped"))
                return notify_fail(CYN "������˵�����㲻�Ѻ�ɳ��Ӱ����������"
                                   "����ô����װ�룿\n" NOR);

        if (ob->query("zhen") > 5)
                return notify_fail(CYN "������˵������ɳ��Ӱ��Ķ�������һ��"
                                   "����������Ϲ��ʲô��\n" NOR);

        message_vision(HIC "\n������΢΢һЦ����$N" HIC "���нӹ���ɳ��Ӱ����"
                       "�ᲦŪ���£��ֻ�����$N" HIC "��\n\n" NOR, me);

        command("say ���ˣ���ɳ��Ӱ��Ķ����Ѿ������ˡ�");
        ob->set("zhen", 10);
        return 1;
}

void unconcious()
{
        die();
}

