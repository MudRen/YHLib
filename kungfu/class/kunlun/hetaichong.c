#include <ansi.h>
#include "kunlun.h"

#define TIEQIN    "/clone/lonely/tieqin"
#define JIANJING  "/clone/lonely/book/xunleijian"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_jian();
mixed ask_jing();

void create()
{
        object ob;
	set_name("��̫��", ({"he taichong", "he", "taichong"}));
        set("long", @LONG
���������ｭ���������ɵ��Ĵ�������������
��̫�塣��Ȼ��ʱ������Ѵ󣬵���Ȼ���ó�
������ʱ��Ӣ��������
LONG);
	set("nickname", WHT "��������" NOR);
	set("gender", "����");
	set("age", 43);
	set("attitude", "heroism");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
        set("max_qi", 5000);
        set("max_jing", 3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 150);
        set("combat_exp", 1600000);

        set_skill("force", 220);
        set_skill("kunlun-xinfa", 200);
        set_skill("liangyi-shengong", 220);
        set_skill("dodge", 200);
        set_skill("chuanyun-bu", 200);
        set_skill("hand", 200);
        set_skill("sanyin-shou", 200);
        set_skill("cuff", 200);
        set_skill("zhentian-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 220);
        set_skill("kunlun-jian", 220);
        set_skill("xunlei-jian", 220);
        set_skill("zhengliangyi-jian", 220);
        set_skill("throwing", 200);
        set_skill("kunlun-qifa", 200);
        set_skill("tanqin-jifa", 240);
        set_skill("tieqin-yin", 240);
        set_skill("literate", 220);
        set_skill("martial-cognize", 200);

        map_skill("force", "liangyi-shengong");
        map_skill("dodge", "chuanyun-bu");
        map_skill("parry", "zhengliangyi-jian");
        map_skill("sword", "kunlun-jian");
        map_skill("cuff", "zhentian-quan");
        map_skill("hand", "sanyin-shou");
        map_skill("throwing", "kunlun-qifa");
        map_skill("tanqin-jifa", "tieqin-yin");

        prepare_skill("strike", "kunlun-zhang");
        prepare_skill("cuff", "zhentian-quan");

        create_family("������", 4, "����");

        set("inquiry", ([
                "����"      : "��Ҫ��ʲô���У�",
                "����"      : "��Ҫ��ʲô������",
                "����"    : "�ţ�������ȥ����������̰ɡ�",
                "������ɫ"  : "�ţ�������ȥ����������̰ɡ�",
                "ʯ���쾪"  : (: ask_skill1 :),
                "���ǵ���"  : (: ask_skill2 :),
                "Ѹ��һ��"  : (: ask_skill3 :),
                "��������"  : (: ask_skill4 :),
                "��������"  : (: ask_skill5 :),
                "���ٽ�"    : (: ask_jian :),
                "����"      : (: ask_jing :),
                "Ѹ�׽���"  : (: ask_jing :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fanyin" :),
                (: perform_action, "throwing.liu" :),
                (: perform_action, "cuff.shi" :),
                (: perform_action, "hand.sun" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }) );

	setup();

        if (clonep())
        {
                ob = find_object(TIEQIN);
                if (! ob) ob = load_object(TIEQIN);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wield();
                } else
                {
                        ob = new("clone/weapon/changjian");
                        ob->move(this_object());
                        ob->wield();
                }
        }

        carry_object("clone/misc/cloth")->wear();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if (me->query("gender") == "Ů��")
        {
                command("say �Ҳ���Ůͽ�ܣ���ȥ���ҷ��˺��ˡ�");
                return;
        }

        if ((int)me->query("combat_exp") < 150000)
        {
                command("say ��Ľ�������̫ǳ�����Ƕ���������˵�ɡ�");
                return;
        }

        if ((int)me->query_skill("kunlun-xinfa", 1) < 80)
        {
		command("say ��Ա��ŵ��ڹ��ķ���֪��ǳ����ϰ�����������Ұɡ�");
		return;
	}

	command("say ��Ȼ��������ģ��ұ������㣬ϣ�����ܹ�������Ϊ��");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhentian-quan/shi"))
                return "�ף������㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("zhentian-quan", 1) < 1)
                return "��������ȭ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 100)
                return "��Ա����������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("zhentian-quan", 1) < 80)
                return "�������ȭ����Ϊ���������Լ���ȥ���������ɡ�";

        message_vision(HIY "$n" HIY "��΢���˵�ͷ��˵�����������"
                       "��ʾһ�飬���Ҫ�����ˡ�\n˵���ֻ��$n" HIY
                       "������ʽ�������ھ�����������һȭ�ӳ�����\n"
                       "ʱ$N" HIY "��Χ��Х���������Ƶ�������ʯ"
                       "���쾪��\n" NOR, me, this_object());
        command("nod");
        command("say ����ʯ���쾪��ʽ�������ӣ���ȥ�Լ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�ʯ���쾪����\n" NOR);

        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("zhentian-quan"))
                me->improve_skill("zhentian-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhentian-quan/shi", 1);
        me->add("gongxian", -100);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kunlun-qifa/liu"))
                return "�ף������㲻���Ѿ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("kunlun-qifa", 1) < 1)
                return "��������������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "��Ա����������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ���Ϊ��ô��ô������������ɣ�";

        if (me->query_skill("kunlun-qifa", 1) < 120)
                return "�������������Ϊ���������Լ���ȥ���������ɡ�";

        message_vision(HIY "$n" HIY "������$N" HIY "һ�ᣬ�ɿ���һ"
                       "����������ӻ�����æȫ�����¡�\n$n" HIY "��"
                       "�Ž�$N" HIY "�е���ǰ����$N" HIY "��������"
                       "�ֹ���Щ����$N" HIY "һ����\nһ�߲�ס�ĵ�ͷ"
                       "��������$n" HIY "�Ľ̵���������\n" NOR,
                       me, this_object());
        command("nod");
        command("say �������ǵ�������͵Ϯ�Ͱ�����˺���Ч����������ɣ�");
        tell_object(me, HIC "��ѧ���ˡ����ǵ�������\n" NOR);

        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("kunlun-qifa"))
                me->improve_skill("kunlun-qifa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kunlun-qifa/liu", 1);
        me->add("gongxian", -300);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xunlei-jian/xun"))
                return "�������Ѿ����͵ú�����ˣ�����ʲô�������Լ���ȥ����";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("xunlei-jian", 1) < 1)
                return "����Ѹ�׽�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "��Ա����������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 150)
                return "����ڹ�����㣬ѧ������һ�У�";

        if (me->query_skill("xunlei-jian", 1) < 100)
                return "���Ѹ�׽�����Ϊ���������Լ���ȥ���������ɡ�";

        message_vision(HIY "$n" HIY "���˵�ͷ�����ִ����������ȡ"
                       "��һ��������ָ������\nһ�ζ�$N" HIY "ϸ˵��"
                       "���ã�$N" HIY "һ����һ�ߵ�ͷ��\n" NOR, me,
                       this_object());
        command("nod");
        command("say �ղ�����˵�ı�����Ѹ��һ���ľ��裬���Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�Ѹ��һ������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("xunlei-jian"))
                me->improve_skill("xunlei-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xunlei-jian/xun", 1);
        me->add("gongxian", -50);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/kunlun-jian/fanyin"))
                return "�����Լ���ȥ�����ٸ��Ҿ������ݣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("kunlun-jian", 1) < 1)
                return "�������ؽ�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1000)
                return "��Ա����������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����㣬ѧ������һ�У�";

        if (me->query_skill("tanqin-jifa", 1) < 120)
                return "��ĵ��ټ������Ҳ�������, ѧ������һ�У�";

        if (me->query_skill("kunlun-jian", 1) < 130)
                return "������ؽ�����Ϊ���������Լ���ȥ���������ɡ�";

        message_vision(HIY "$n" HIY "������$N" HIY "���죬˵��������"
                       "Ȼ�㽣���ѳɣ��ҽ��ձ�\n�������аɡ����಻��"
                       "�ɵ��˶����ҳ�ȥ���������������\n�º�$n"
                       HIY "��������������ܣ�ȷ������û�˺���Ŵ�"
                       "\n�����³��һ����������������ʾ���С�$N" HIY
                       "ֻ�����о�����\n�ɣ�ʵ��ǰ��ν�š�\n" NOR, me,
                       this_object());
        command("nod");
        command("say ��������ȥ���Ҹ�Ƨ��֮���ڼ���ϰ����ǧ���й¶��ȥ��");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);

        if (me->can_improve_skill("tanqin-jifa"))
                me->improve_skill("tanqin-jifa", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("kunlun-jian"))
                me->improve_skill("kunlun-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/kunlun-jian/fanyin", 1);
        me->add("gongxian", -1000);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhengliangyi-jian/sui"))
                return "�Լ���ȥ�������ϸ��Ҿ������ݣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("zhengliangyi-jian", 1) < 1)
                return "���������ǽ�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "��Ա����������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 250)
                return "����ڹ�����㣬ѧ������һ�С�";

        if (me->query("max_neili") < 3000)
                return "���������Ϊ���㣬ѧ������һ�С�";

        if (me->query_skill("zhengliangyi-jian", 1) < 180)
                return "��������ǽ�����Ϊ���������Լ���ȥ���������ɡ�";

        message_vision(HIY "$n" HIY "üͷ΢΢һ�壬һ���֣�ʾ��������"
                       "��ȫ����ȥ����\n�������½�����º�$n" HIY "��"
                       "���Ļ��������ܣ�ȷ������\nû�˺���Ž�$N" HIY
                       "������ߣ�������$N" HIY "����ϸ˵���á�����\n��"
                       "��Ϻ�$n" HIY "�ֻ�����ҡ��ҡͷ�����ŵ�����һ"
                       "������\n��Ϊ���飬��Ϊ��ȫ��ƴ��һ����ʹ��ǰһ"
                       "��Ҫ���ؿ��ǡ�\n" NOR, me, this_object());
        command("sigh");
        command("say ���ˣ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��������ԡ���\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("zhengliangyi-jian"))
                me->improve_skill("zhengliangyi-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhengliangyi-jian/sui", 1);
        me->add("gongxian", -800);

        return 1;
}

mixed ask_jian()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "������")
                return "�����������ģ���������������£�";

        if (me->query("family/master_id") != "he zudao" &&
            me->query("family/master_id") != "ban shuxian" &&
            me->query("family/master_id") != "he taichong")
                return "�ߣ��㻹û���ʸ�ʹ���ҵı�����";

        if (me->query_skill("kunlun-jian", 1) < 150)
                return "��������ҹ���ȥ���������������������£�";

        if (me->query_skill("tanqin-jifa", 1) < 100)
                return "�����ٶ������ã�����ʲô���ٽ���";

        if (present("tieqin jian", me))
                return "�ҵ����ٽ����ڲ�������������";

        ob = present("tieqin jian", this_object());

        if (! objectp(ob))
                return "�������ˣ����ٽ����ڲ��������";

        message_vision("$N�ó�" WHT "���ٽ�" NOR "(tieqin jian)��$n��\n",
                       this_object(), me);
        ob->move(me, 1);

        ob = new("clone/weapon/changjian");
        ob->move(this_object());
        ob->wield();

        return "��������ٽ����������ȥ�ɣ��������������������ɵ����硣";
}

mixed ask_jing()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        if (me->query("family/family_name") != "������")
                return "�����������ģ���������������£�";

        if (me->query_skill("xunlei-jian", 1) > 120)
                return "���Ѹ�׽����Ѿ�������ز���û��Ҫ��ȥ�ζ������ˡ�";

        if (me->query_skill("sword", 1) < 30)
                return "��Ľ�����ô������������������ߵ������ɡ�";

        ob = find_object(JIANJING);
        if (! ob) ob = load_object(JIANJING);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "�Ҳ����Ѿ��ѽ������������ѵ���Ū���ˣ�";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "��������һ�����Ǳ���Ѹ�׽������Ѿ�����ͬ��ʦ����ȥ�ˡ�";

                if (owner->query("family/family_name") == "������")
                        return "�Ǳ���Ѹ�׽�������������ͬ��" + owner->query("name") +
                               "���У���Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���������ã�����Ϊ�˵����ء���˵��������" +
                               owner->query("name") + "���У���ȥ�������ˣ����ؽ�����";
        }

        ob->move(this_object());
        message_vision(CYN "$N" CYN "˵������Ȼ��ˣ��Ȿ��Ѹ�׽����������ұ�"
                       "�����㣬�ɱ�Ū���ˡ�\n" NOR, this_object(), me);
        command("give xunlei jianjing to " + me->query("id"));
        return 1;
}

void unconcious()
{
        die();
}
