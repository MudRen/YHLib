#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_skill1();

void create()
{
        set_name("���Ԫ", ({ "ma dayuan", "ma", "dayuan" }));
        set("long", @LONG
����һ����ʮ����ľ�׳���ӣ���Ŀ��࣬˫
Ŀ��硣���˾���ؤ�︱�������Ԫ��
LONG);
        set("nickname", CYN "��צ����" NOR);
        set("title", "ؤ�︱����");
        set("gender", "����");
        set("age", 48);
        set("attitude", "peaceful");
        set("class", "beggar");

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 4500);
        set("max_jing", 3500);
        set("neili", 4800);
        set("max_neili", 4800);
        set("jiali", 220);
        set("combat_exp", 2500000);
        set("score", 500000);
        set("shen_type", 1);
        
        set_skill("force", 240);
        set_skill("jiaohua-neigong", 220);
        set_skill("huntian-qigong", 240);
        set_skill("dodge", 240);
        set_skill("feiyan-zoubi", 240);
        set_skill("unarmed", 200);
        set_skill("changquan", 200);
        set_skill("jueming-tui", 200);
        set_skill("claw", 240);
        set_skill("da-qinna", 220);
        set_skill("xiao-qinna", 220);
        set_skill("suohou-gong", 240);
        set_skill("strike", 200);
        set_skill("tongchui-zhang", 200);
        set_skill("parry", 240);
        set_skill("staff", 240);
        set_skill("dagou-bang", 240);
        set_skill("jiaohua-bangfa", 240);
        set_skill("begging", 280);
        set_skill("checking", 280);
        set_skill("literate", 260);
        set_skill("martial-cognize", 240);

        set("no_teach", ([
                "dagou-bang" : "�򹷰�������ֻ�м�λ�����ܹ�ѧ"
                               "ϰ��Ҫѧȥ�Ұ�����",
        ]));

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "jueming-tui");
        map_skill("strike", "tongchui-zhang");
        map_skill("staff", "dagou-bang");
        map_skill("claw", "suohou-gong");
        map_skill("parry", "suohou-gong");
        map_skill("dodge", "feiyan-zoubi");

        prepare_skill("claw", "suohou-gong");

        create_family("ؤ��", 18, "������");

        set("inquiry", ([
                "��צ����" : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "claw.suo" :),
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

        if (ob->query("combat_exp") < 200000)
        {
                command("say ��Ľ������鲻�������������λ����ѧϰ�ɡ�");
                return;
        }

        if (ob->query("shen") < 30000)
        {
                command("say ����Ϊؤ����ӣ���Ȼ�������£�");
                return;
        }

        if (ob->query("family/beggarlvl") < 5)
        {
                command("say ���ڱ���ĵ�λ̫�ͣ����������λ����ѧϰ�ɡ�");
                return;
        }

        if ((int)ob->query_str() < 26)
        {
                command("say �ҵ������Ը���Ϊ�������������У��������˰ɡ�");
                return;
        }

        if (ob->query_skill("force") < 150)
        {
                command("say ����ڹ���򻹲��������������λ����ѧϰ�ɡ�");
                return;
        }
        command("nod");
        command("say �ҽ��ձ�����Ϊͽ�������ڿ�Ŭ������������һ����Ϊ��");
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

        if (me->query("can_perform/suohou-gong/suo"))
                return "�Լ���ȥ��ϰ�������Ǿ������ݡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ǽ����������͵���ţ�����������";

        if (me->query_skill("suohou-gong", 1) < 1)
                return "��ѧ�������𣿲�ѧ�������С�";

        if (me->query("gongxian") < 400)
                return "����ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 20000)
                return "�������������ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("suohou-gong", 1) < 150)
                return "��������������ң�Ҫ��������";

        message_sort(HIY "\n$n" HIY "Ц��Ц����$N" HIY "�������ԣ���"
                     "����$N" HIY "���ߵ����Ը��˼��䣬��ʱ����ȭ��צ"
                     "�Ȼ���ʾ��ȫ���������еľ�΢Ҫ�裬$N" HIY "һ"
                     "����һ�߲�ס�ص�ͷ��\n\n" NOR, me, this_object());

        command("nod");
        command("say �����������Ҫ�����ڣ��ɼ�����ˣ�");
        tell_object(me, HIC "��ѧ���ˡ���צ������\n" NOR);

        if (me->can_improve_skill("claw"))
                me->improve_skill("claw", 1500000);
        if (me->can_improve_skill("suohou-gong"))
                me->improve_skill("suohou-gong", 1500000);

        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/suohou-gong/suo", 1);
        me->add("gongxian", -400);
        return 1;
}

