#include <ansi.h>
#include "kunlun.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

mixed ask_skill1();
mixed ask_skill2();

void create()
{
	set_name("�����", ({ "ban shuxian", "ban", "shuxian" }));
	set("title", "���������ŷ���");
        set("long", @LONG
�����������ɵ��Ĵ���������������̫��ķ�
�˰���浡�ֻ������ĸߴ�ͷ�����ף�˫Ŀ
������ü�ļ����ɷ����
LONG);
	set("gender", "Ů��");
	set("age", 46);
	set("attitude", "heroism");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
        set("max_qi", 4800);
        set("max_jing", 2800);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 130);
        set("combat_exp", 1500000);

        set_skill("force", 210);
        set_skill("kunlun-xinfa", 200);
        set_skill("liangyi-shengong", 210);
        set_skill("dodge", 180);
        set_skill("chuanyun-bu", 180);
        set_skill("hand", 210);
        set_skill("sanyin-shou", 210);
        set_skill("cuff", 210);
        set_skill("zhentian-quan", 210);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("kunlun-jian", 200);
        set_skill("xunlei-jian", 200);
        set_skill("zhengliangyi-jian", 200);
        set_skill("throwing", 180);
        set_skill("kunlun-qifa", 180);
        set_skill("tanqin-jifa", 160);
        set_skill("qiuyue-lai", 160);
        set_skill("literate", 220);
        set_skill("martial-cognize", 200);

        map_skill("force", "liangyi-shengong");
        map_skill("dodge", "chuanyun-bu");
        map_skill("parry", "kunlun-jian");
        map_skill("sword", "zhengliangyi-jian");
        map_skill("cuff", "zhentian-quan");
        map_skill("hand", "sanyin-shou");
        map_skill("throwing", "kunlun-qifa");
        map_skill("tanqin-jifa", "qiuyue-lai");

        prepare_skill("strike", "kunlun-zhang");
        prepare_skill("cuff", "zhentian-quan");

        set("coagents", ({
                ([ "startroom" : "/d/kunlun/tieqinju",
                   "id"        : "he taichong" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "�����վס�����������������ɵ���"
                                "������߶��ط���" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ����ҷ�������" NOR,
        ]));

        create_family("������", 4, "���ŷ���");

        set("inquiry", ([
                "����"      : "��Ҫ��ʲô���У�",
                "����"      : "��Ҫ��ʲô������",
                "ʯ���쾪"  : "�����������ɷ�ѧȥ���������ҡ�",
                "���ǵ���"  : "�����������ɷ�ѧȥ���������ҡ�",
                "Ѹ��һ��"  : "�����������ɷ�ѧȥ���������ҡ�",
                "��������"  : "�����������ɷ�ѧȥ���������ҡ�",
                "��������"  : "�����������ɷ�ѧȥ���������ҡ�",
                "����"    : (: ask_skill1 :),
                "������ɫ"  : (: ask_skill2 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.wu" :),
                (: perform_action, "throwing.liu" :),
                (: perform_action, "cuff.shi" :),
                (: perform_action, "hand.sun" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),

        }) );

	setup();

        carry_object("clone/weapon/changjian")->wield();
        carry_object("clone/misc/cloth")->wear();
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if (me->query("gender") != "Ů��")
        {
                command("say �ҿ���������Щ�����˾ͷ�������ҹ�����");
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

	command("say �ðɣ��Ժ���͸��Ұɣ�����ð���ѧ�գ�����������");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/sanyin-shou/sun"))
                return "�Լ���ȥ�������ϸ��Ҿ������ݣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("sanyin-shou", 1) < 1)
                return "���������ֶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "��Ա����������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����㣬ѧ������һ�У�";

        if (me->query_skill("sanyin-shou", 1) < 140)
                return "�����������Ϊ���������Լ���ȥ���������ɡ�";

        message_vision(HIY "$n" HIY "΢΢һЦ����$N" HIY "˵������"
                       "���ˡ�˵�굥�������\n����ǰ�Ĳ輸�����Ű�"
                       "��������$N" HIY "������䣬�輸ͻȻ\n������"
                       "�ѣ������ꡱһ����Ϊ���ء�\n" NOR, me,
                       this_object());
        command("smile");
        command("say ���б����������������ӣ�ֻ���ס������˸ա����ֽԿɡ�");
        tell_object(me, HIC "��ѧ���ˡ���������\n" NOR);

        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("sanyin-shou"))
                me->improve_skill("sanyin-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/sanyin-shou/sun", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/zhengliangyi-jian/wu"))
                return "�Լ���ȥ�������ϸ��Ҿ������ݣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("zhengliangyi-jian", 1) < 1)
                return "���������ǽ�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1200)
                return "��Ա����������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 220)
                return "����ڹ�����㣬ѧ������һ�С�";

        if (me->query_skill("dodge") < 220)
                return "����Ṧ����㣬ѧ������һ�С�";

        if (me->query_dex() < 45)
                return "�����ʵ��̫�ѧ������һ�С�";

        if (me->query_skill("zhengliangyi-jian", 1) < 160)
                return "��������ǽ�����Ϊ���������Լ���ȥ���������ɡ�";

        message_vision(HIY "$n" HIY "üͷ΢΢һ�壬һ���֣�ʾ����������"
                       "ȫ����ȥ��\n�����������ɵ���½�����º�$n" HIY
                       "�����Ļ�������\n���ܣ����$N" HIY "������ߣ�"
                       "������$N" HIY "����ϸ˵���á�\n" NOR, me,
                       this_object());
        command("nod");
        command("say �ղ�����˵���㶼���������Լ���ȥ���ɣ�");
        tell_object(me, HIC "��ѧ���ˡ�������ɫ����\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("zhengliangyi-jian"))
                me->improve_skill("zhengliangyi-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/zhengliangyi-jian/wu", 1);
        me->add("gongxian", -1200);

        return 1;
}

