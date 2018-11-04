#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include "fight.h"

mixed ask_skill1();
mixed ask_skill2();

void create()                                                                   
{
        set_name("����", ({ "li sheng", "li", "sheng" }));
        set("gender", "����");
        set("long", "����λ���Ը�ֱ����������ؤ��˴����ӡ�\n");
        set("title", "ؤ��˴�����");
        set("nickname", HIW "��������" NOR);
        set("age", 42);
        set("attitude", "peaceful");
        set("class", "beggar");

        set("str", 32);
        set("int", 32);
        set("con", 32);
        set("dex", 32);
        set("max_qi", 2400);
        set("max_jing", 1600);
        set("neili", 2200);
        set("max_neili", 2200);
        set("jiali", 180);
        set("combat_exp", 1200000);
        set("shen_type", 1);

        set_skill("force", 160);
        set_skill("huntian-qigong", 140);
        set_skill("jiaohua-neigong", 160);
        set_skill("dodge", 160);
        set_skill("feiyan-zoubi", 160);
        set_skill("staff", 140);
        set_skill("jiaohua-bangfa", 140);
        set_skill("unarmed", 140);
        set_skill("changquan", 140);
        set_skill("jueming-tui", 140);
        set_skill("strike", 160);
        set_skill("shenlong-baiwei", 160);
        set_skill("tongchui-zhang", 160);
        set_skill("parry", 160);
        set_skill("begging", 200);
        set_skill("checking", 200);
        set_skill("literate", 140);
        set_skill("martial-cognize", 160);

        map_skill("force", "huntian-qigong");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("staff", "jiaohua-bangfa");
        map_skill("strike", "shenlong-baiwei");
        map_skill("unarmed", "jueming-tui");
        map_skill("parry", "shenlong-baiwei");

        prepare_skill("strike", "shenlong-baiwei");

        set("no_teach/shenlong-baiwei", "�����Ʒ������ɰ�������"
                                        "�˼����ͣ��������״��ڡ�");
        set("no_teach/huntian-qigong",  "���ڹ�������Ҳδ������"
                                        "�죬�һ��ǽ�����İɡ�");

        create_family("ؤ��", 19, "����");

        set("coagents", ({
                ([ "startroom" : "/d/gaibang/undertre",
                   "id"        : "liang zhanglao" ]),
                ([ "startroom" : "/d/gaibang/undertre",
                   "id"        : "jian zhanglao" ]),
        }));

        set("inquiry", ([
                "�嶡��ɽ" : (: ask_skill1 :),
                "����һ��" : (: ask_skill2 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/gaibang/npc/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;

        if (ob->query("shen") < 0)
        {
                command("say ����Ϊؤ����ӣ���Ȼ�������£�");
                return;
        }
        command("nod");
        command("say �ұ�����Ϊͽ���պ�ɵ��������壬Ī����ؤ��������");
        command("recruit " + ob->query("id"));

        if (ob->query("class") != "beggar")
                ob->set("class", "beggar");

        if (lvl > 0)
        {
                ob->set("family/beggarlvl", lvl);
                ob->set("title", title);
        }
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/tongchui-zhang/kai"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("tongchui-zhang", 1) < 1)
                return "����ͭ���Ʒ���ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 100)
                return "��������ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 1000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("tongchui-zhang", 1) < 80)
                return "���ͭ���Ʒ���򻹲�����������ȥ���ߵ������ɡ�";

        if (me->query_skill("force") < 90)
                return "�����ڵ��ڹ���Ϊ���㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ���ӻ�������ȡ����һ��"
                     "С���ӣ�ָ�����е�һ�ζ�$N" HIY "ϸ˵���ã�$N"
                     HIY "һ����һ�ߵ�ͷ��\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say ��ʽ�ܼ򵥣����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��嶡��ɽ����\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("tongchui-zhang"))
                me->improve_skill("tongchui-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tongchui-zhang/kai", 1);
        me->add("gongxian", -100);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jueming-tui/jue"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("jueming-tui", 1) < 1)
                return "���������ȷ���ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "��������ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 3000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("jueming-tui", 1) < 80)
                return "��ľ����ȷ���򻹲�����������ȥ���ߵ������ɡ�";

        if (me->query_skill("force") < 100)
                return "�����ڵ��ڹ���Ϊ���㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "����һЦ�����ֽ�$N" HIY "�е���"
                     "��ǰ����$N" HIY "���������ֹ���Щ����$N" HIY "��"
                     "�˰��죬ͻȻ�䲻�ɻ��ĵ�һЦ��������������\n\n"
                     NOR, me, this_object());

        command("nod");
        command("say ���е�Ҫ����ǳ������ᣬ������ʤ��");
        tell_object(me, HIC "��ѧ���ˡ�����һ�ߡ���\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("jueming-tui"))
                me->improve_skill("jueming-tui", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jueming-tui/jue", 1);
        me->add("gongxian", -150);

        return 1;
}