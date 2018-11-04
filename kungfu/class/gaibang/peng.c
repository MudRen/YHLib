#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include "fight.h"

mixed ask_skill1();

void create()
{
        set_name("���о�", ({ "peng youjing", "peng", "youjing" }));
        set("long", @LONG
���о���ؤ���о����ɵ����죬���Ÿɾ�����
����л��ӡ������Ϲ��Ŵ����Ц�ݣ�һ˫��
�����������ǵ�������
LONG);
        set("nickname", WHT "�Ʋ���ͷ" NOR);
        set("title", "ؤ��Ŵ�����");
        set("gender", "����");
        set("age", 48);
        set("attitude", "peaceful");
        set("class", "beggar");

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 4300);
        set("max_neili", 4300);
        set("jiali", 180);
        set("combat_exp", 2200000);
        set("score", 300000);
        set("shen_type", -1);
        
        set_skill("force", 220);
        set_skill("jiaohua-neigong", 180);
        set_skill("huntian-qigong", 220);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("unarmed", 200);
        set_skill("changquan", 200);
        set_skill("jueming-tui", 200);
        set_skill("strike", 200);
        set_skill("tongchui-zhang", 200);
        set_skill("parry", 220);
        set_skill("staff", 240);
        set_skill("jiaohua-bangfa", 220);
        set_skill("fengmo-zhang", 240);
        set_skill("mihun-dafa", 200);
        set_skill("begging", 250);
        set_skill("checking", 250);
        set_skill("literate", 180);
        set_skill("martial-cognize", 220);

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "jueming-tui");
        map_skill("strike", "tongchui-zhang");
        map_skill("staff", "fengmo-zhang");
        map_skill("parry", "fengmo-zhang");
        map_skill("dodge", "feiyan-zoubi");

        prepare_skill("strike", "tongchui-zhang");
        prepare_skill("unarmed", "jueming-tui");

        set("no_teach/mihun-dafa",  "��Ū���˰ɣ����������ĵĶ�������ô�ᡣ");

        create_family("ؤ��", 18, "����");

        set("coagents", ({
                ([ "startroom" : "/d/city/gbxiaowu",
                   "id"        : "hong qigong" ]),
        }));

        set("inquiry", ([
                "Ⱥħ����" : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.luan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/gaibang/npc/obj/cloth")->wear();
        carry_object("/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;

        if (ob->query("combat_exp") < 130000)
        {
                command("say ��Ľ������鲻�������������λ����ѧϰ�ɡ�");
                return;
        }

        if (ob->query("family/beggarlvl") < 4)
        {
                command("say ���ڱ���ĵ�λ̫�ͣ�������������ʦ��ѧϰ�ɡ�");
                return;
        }

        if (ob->query_skill("force") < 90)
        {
                command("say ����ڹ���򻹲�����������������ʦ��ѧϰ�ɡ�");
                return;
        }
        command("grin");
        command("say �����Ժ�͸����Ұɡ�");
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

        if (me->query("can_perform/fengmo-zhang/luan"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("fengmo-zhang", 1) < 1)
                return "������ħ�ȷ���ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "��������ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query_skill("fengmo-zhang", 1) < 120)
                return "��ķ�ħ�ȷ���򻹲�����������ȥ���ߵ������ɡ�";

        if (me->query_skill("force") < 150)
                return "�����ڵ��ڹ���Ϊ���㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ����$N" HIY "˵��������"
                     "�ҿ�����ˡ���ͻȻ����$n" HIY "һ�����ȣ�������"
                     "��һ�����裬���ƺ������������������Ӱ������"
                     "���ȣ������ɵ������Ƿ�ħ�ȷ��ľ�Ҫ���ڡ�\n\n" NOR,
                     me, this_object()); 

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ�Ⱥħ���衹��\n" NOR);
        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("fengmo-zhang"))
                me->improve_skill("fengmo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/fengmo-zhang/luan", 1);
        me->add("gongxian", -400);

        return 1;
}
