#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

#include "fight.h"

mixed ask_skill1();

void create()
{
        set_name("�ɳ���", ({ "xi zhanglao", "xi", "zhanglao" }));
        set("long", @LONG
�ɳ�����ؤ��Ԫ�ϣ��书��Ϊ�˵á�
LONG);
        set("nickname", HIR "���ǳ���" NOR);
        set("title", "ؤ��Ŵ�����");
        set("gender", "����");
        set("age", 53);
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
        set("shen_type", 1);
        
        set_skill("force", 240);
        set_skill("jiaohua-neigong", 220);
        set_skill("huntian-qigong", 240);
        set_skill("dodge", 200);
        set_skill("feiyan-zoubi", 200);
        set_skill("unarmed", 220);
        set_skill("changquan", 200);
        set_skill("jueming-tui", 220);
        set_skill("strike", 220);
        set_skill("tongchui-zhang", 220);
        set_skill("liuhe-zhang", 200);
        set_skill("parry", 200);
        set_skill("staff", 240);
        set_skill("jiaohua-bangfa", 220);
        set_skill("fumo-zhang", 240);
        set_skill("begging", 250);
        set_skill("checking", 250);
        set_skill("literate", 180);
        set_skill("martial-cognize", 220);

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "jueming-tui");
        map_skill("strike", "tongchui-zhang");
        map_skill("staff", "fumo-zhang");
        map_skill("parry", "fumo-zhang");
        map_skill("dodge", "feiyan-zoubi");

        prepare_skill("strike", "tongchui-zhang");
        prepare_skill("unarmed", "jueming-tui");

        create_family("ؤ��", 18, "����");

        set("inquiry", ([
                "�����" : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "staff.lun" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/gaibang/npc/obj/cloth")->wear();
        carry_object("/d/gaibang/npc/obj/staff")->wield();
}

void attempt_apprentice(object ob)
{
        string title = ob->query("title");
        int lvl = ob->query("family/beggarlvl");

        if (! permit_recruit(ob))
                return;

        if (ob->query("combat_exp") < 120000)
        {
                command("say ��Ľ������鲻����������������ʦ��ѧϰ�ɡ�");
                return;
        }

        if (ob->query("shen") < 20000)
        {
                command("say ����Ϊؤ����ӣ���Ȼ�������£�");
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
        command("nod");
        command("say �ұ������㣬ϣ���պ�Ŭ���Ͻ�����������Ϊ��");
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

        if (me->query("can_perform/fumo-zhang/lun"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("fumo-zhang", 1) < 1)
                return "������ħ�ȷ���ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 350)
                return "��������ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 30000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("fumo-zhang", 1) < 120)
                return "��Ķ�ʮ��·��ħ�Ȼ�򲻹�����ȥ���ߵ������ɡ�";

        if (me->query_skill("force") < 150)
                return "�����ڵ��ڹ���Ϊ���㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "΢Ц�Ŷ�$N" HIY "���˵�ͷ����"
                     "�������������Ȼһ�����ȣ����������ת���֣�"
                     "��Ӱ������������Ȧ��˲���ѽ�$N" HIY "���Ź���"
                     "���У������Ƿ����һ�㣬������磬��ʽ���棬"
                     "����̾Ϊ��ֹ��\n\n" NOR, me, this_object()); 

        command("haha");
        command("say ���Լ�ȥ����ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����֡���\n" NOR);
        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", 1500000);
        if (me->can_improve_skill("fumo-zhang"))
                me->improve_skill("fumo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/fumo-zhang/lun", 1);
        me->add("gongxian", -350);

        return 1;
}
