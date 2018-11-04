#include <ansi.h>
#include "honghua.h"

#define HUILONGBI    "/clone/lonely/huilongbi"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_bi();
mixed ask_skill1();

void create()
{
        object ob;
        set_name("�԰�ɽ", ({"zhao banshan", "zhao", "banshan"}));
        set("title", "�컨��������");
        set("nickname", HIY "ǧ������" NOR );
        set("gender", "����");
        set("age", 48);
        set("long", "ֻ����һ�����ֵ�����Ц��������һ���ܴ�\n"
                    "��ĸо�����ԭ����������̫�������Ŵ��\n"
                    "�ӡ�����������������һ�ְ��������\n"
                    "̫����������ƥ�С������������ɢ֮��\n"
                    "Ͷ��컨�ᡣ�ܵñ��컨���ϵ�������ͤ��\n"
                    "ʶ��\n");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 150);
        set("combat_exp", 3000000);
        set("score", 10000);

        set_skill("force", 220);
        set_skill("honghua-xinfa", 220);
        set_skill("tianchi-neigong", 220);
        set_skill("unarmed", 220);
        set_skill("dodge", 220);
        set_skill("yanzi-chuanyun", 220);
        set_skill("taiji-jian", 220);
        set_skill("taiji-quan", 220);
        set_skill("parry", 220);
        set_skill("sword", 220);
        set_skill("throwing", 240);
        set_skill("huilong-bifa", 240);
        set_skill("martial-cognize", 200);
        set_skill("literate", 200);

        set("no_teach", ([
                "taiji-jian" : "�š����㻹��ѧ�������İɡ�",
                "taiji-quan" : "�š����㻹��ѧ�������İɡ�",
        ]));

        map_skill("force"   , "tianchi-neigong");
        map_skill("unarmed" , "taiji-quan");
        map_skill("dodge"   , "yanzi-chuanyun");
        map_skill("parry"   , "taiji-jian");
        map_skill("sword"   , "taiji-jian");
        map_skill("throwing", "huilong-bifa");

        create_family("�컨��", 4, "����");

        set("inquiry", ([
                "�����" : (: ask_bi :),
                "�Ʋ���" : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chan" :),
                (: perform_action, "throwing.cang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        if (clonep())
        {
                ob = find_object(HUILONGBI);
                if (! ob) ob = load_object(HUILONGBI);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        set_temp("handing", ob);
                } else
                {
                        set_temp("handing", carry_object("/d/beijing/npc/obj/jinbiao"));
                }
        }
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
    
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < 15000)
        {
                command("say ������֮������̫�٣���Ҫ���ע�⡣");
                return;
        }

        if ((int)me->query("combat_exp") < 200000)
        {
                command("say ��Ľ�������̫ǳ�������ȸ���������λ���������ɡ�");
                return;
        }

        if ((int)me->query_skill("honghua-xinfa", 1) < 80)
        {
                command("say ����ȥ�ѱ��ŵ��ķ��������������ҡ�");
                return;
        }

        command("smile");
        command("say ������������ģ��ұ���������ˡ�");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/huilong-bifa/cang"))
                return "�����Ҳ����紫�ڸ�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�ͱ������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("huilong-bifa", 1) < 1)
                return "��������起���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 600)
                return "���ڻ��������Ĺ��׻������������Ҳ�æ���㡣";

        if (me->query("shen") < 30000)
                return "�������������ò����������Ҳ��ܴ��㡣";

        if (me->query_skill("force") < 160)
                return "����ڹ�����㣬ѧ������һ�С�";

        if (me->query_skill("huilong-bifa", 1) < 120)
                return "��Ļ���起������ò����ң��Լ���ȥ���������ɣ�";

        message_vision(HIY "$n" HIY "����һЦ����$N" HIY "������ǰ����"
                       "���ڶ�������˵��Щʲô������������\n�֣�ʮָ"
                       "���ţ�һ��һ������������һ�ֺ��ر�İ������š�\n"
                       NOR, me, this_object());

        command("haha");
        command("say ����������Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��Ʋ�������\n" NOR);

        if (me->can_improve_skill("throwing"))
                me->improve_skill("throwing", 1500000);
        if (me->can_improve_skill("huilong-bifa"))
                me->improve_skill("huilong-bifa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/huilong-bifa/cang", 1);
        me->add("gongxian", -600);

        return 1;
}

mixed ask_bi()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "�컨��")
                return "�٣������������ģ��ҿɲ���ʶ�㡣";

        if (me->query("family/master_id") != "chen jialuo" &&
           me->query("family/master_id") != "wuchen daozhang" &&
           me->query("family/master_id") != "zhao banshan")
                return "�������ʦ��" + me->query("family/master_name") + CYN
                       "˵�ˣ�����̫�����㣬��Щ���Ӱɡ�";

        if (me->query_skill("huilong-bifa", 1) < 150)
                return "�������起����ɺ��������ң�����ȥ������";

        if (me->query("shen") < 30000)
                return "��ѽѽ�����⵹�������ģ�������ĵ���Ҳ����";

        if (present("huilong bi", me))
                return "�ҵĻ���赲�����������������Ϊ�λ��������������ˣ�";

        ob = present("huilong bi", this_object());

        if (! objectp(ob))
                return "�������ˣ���������ڲ����������С�";

        message_vision("$N�ó�" HIC "�����" NOR "(Huilong bi)��$n��\n",
                       this_object(), me);
        ob->move(me, 1);
        set_temp("handing", carry_object("/d/beijing/npc/obj/jinbiao"));

        return "��Ȼ����������֧����������ʱ��ȥ�ðɡ�";
}
