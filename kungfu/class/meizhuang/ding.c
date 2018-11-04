#include <ansi.h>
#include "meizhuang.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

mixed ask_skill1();

void create()
{
        set_name("����", ({"ding jian","ding",}));
        set("long",
                "���������ӽ��������һ�ֵ罣���ᣬ������÷ׯ�����ˡ�\n"
        );
        set("gender", "����");
        set("nickname", HIY "һ�ֵ罣" NOR);
        set("title", "÷ׯ�ʹ�");
        set("attitude", "friendly");

        set("age", 30);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 3000);
        set("max_jing", 2700);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 50);
        set("combat_exp", 500000);

        set_skill("force", 120);
        set_skill("wuzheng-xinfa", 120);
        set_skill("sword", 140);
        set_skill("jidian-jian", 140);
        set_skill("dodge", 140);
        set_skill("feiyan-zoubi", 140);
        set_skill("parry", 120);
        set_skill("strike", 120);
        set_skill("qingmang-zhang", 120);
        set_skill("literate", 100);
        set_skill("martial-cognize", 120);

        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "jidian-jian");
        map_skill("sword", "jidian-jian");
        map_skill("strike", "qingmang-zhang");

        prepare_skill("strike", "qingmang-zhang");

        set("coagents", ({
                ([ "startroom" : "/d/meizhuang/houting",
                   "id"        : "hei baizi" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ü����"
                                "����վס����ɽ÷ׯ��������߶���"
                                "����" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ�" NOR,
        ]));

        create_family("÷ׯ", 2, "�ʹ�");

        set("inquiry", ([
                "����"        : "��Ҫ��ʲô���У�",
                "����"        : "��Ҫ��ʲô������",
                "�������"    : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.dian" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/d/city/npc/obj/cloth")->wear();
        carry_object("/d/city/npc/obj/changjian")->wield();
        carry_object("/d/meizhuang/obj/yaoshi");
}

void attempt_apprentice(object me)
{
        string purename, name, new_name;

        if (! permit_recruit(me))
                return;

        if ( me->query("family/family_name") &&
             me->query("family/family_name") == "�������" &&
             me->query("family/master_name") == "��������" )
        {
                command("ah");
                command("say ԭ���Ƕ��������ĵ��ӣ��˻ᣬ�˻ᣡ");
                command("say ����·�ͬС�ɣ��������������㻹��ȥ�Ҽ�λׯ���ɡ�");
                me->set("move_party/������̡�÷ׯ", 1);
                return;
        }

        if ((int)me->query("shen") > 1000)
        {
                command("heng");
                command("say ���ǹ�ɽ÷ׯ�������ʽ����£�Ҳ���ύ������������֮ʿ��");
                return;
        }

        if ((int)me->query("shen") < -1000)
        {
                command("heng");
                command("say ���ǹ�ɽ÷ׯ�������ʽ����£�������ύ��������֮�ˡ�");
                return;
        }

        command("say �ðɣ���Ȼ���������䣬�Ҿ������㡣");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jidian-jian/dian"))
                return "�̵ܽ����Ѿ��������ˡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("jidian-jian", 1) < 1)
                return "�������罣����ûѧ����̸���ԣ�";

        if (me->query("gongxian") < 50)
                return "��Ա�ׯ�������Ĺ��ײ�������һ������ʱ�����ܴ��㡣";

        if (me->query_skill("jidian-jian", 1) < 100)
                return "��ļ��罣�������ò����ң��Լ���ȥ���������ɣ�";

        if (me->query_skill("force") < 150)
                return "����ڹ�����в���������ѧ�������еġ�";

        message_vision(HIY "$n" HIY "���˵�ͷ��˵�����⼲�罣���ĵ��"
                       "������ʵ����������ʹ������ʩ��\n�������������"
                       "��ʾһ�飬��ɿ����ˡ�$n" HIY "˵�����г���һ"
                       "���������׽�\n��ʩչ��������ʱ֮�䣬���Ҷ��ǵ�"
                       "�⣬ҫ����Ŀ��$N" HIY "����˫Ŀһ������ʱ\n��"
                       "������\n" NOR, me, this_object());
        command("nod");
        command("say ������ʵ�ܼ򵥣���΢���������ʩչ�ˡ�");
        tell_object(me, HIC "��ѧ���ˡ�������䡹��\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("jidian-jian"))
                me->improve_skill("jidian-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jidian-jian/dian", 1);
        me->add("gongxian", -50);

        return 1;
}
