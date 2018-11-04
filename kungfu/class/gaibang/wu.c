#include <ansi.h>
#include "gaibang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

#include "fight.h"

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        set_name("�ⳤ��", ({ "wu changfeng", "wu", "changfeng" }));
        set("long", @LONG
�ⳤ����ؤ��Ԫ�ϣ��书��Ϊ�˵á�
LONG);
        set("nickname", HIR "���³���" NOR);
        set("title", "ؤ��Ŵ�����");
        set("gender", "����");
        set("age", 45);
        set("attitude", "peaceful");
        set("class", "beggar");

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 4200);
        set("max_jing", 3200);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 200);
        set("combat_exp", 2500000);
        set("score", 300000);
        set("shen_type", 1);
        
        set_skill("force", 240);
        set_skill("jiaohua-neigong", 220);
        set_skill("huntian-qigong", 240);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("unarmed", 180);
        set_skill("changquan", 180);
        set_skill("jueming-tui", 180);
        set_skill("strike", 240);
        set_skill("tongchui-zhang", 220);
        set_skill("liuhe-zhang", 240);
        set_skill("parry", 220);
        set_skill("staff", 180);
        set_skill("jiaohua-bangfa", 180);
        set_skill("blade", 240);
        set_skill("liuhe-dao", 240);
        set_skill("begging", 250);
        set_skill("checking", 250);
        set_skill("literate", 180);
        set_skill("martial-cognize", 220);

        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "changquan");
        map_skill("strike", "liuhe-zhang");
        map_skill("staff", "jiaohua-bangfa");
        map_skill("blade", "liuhe-dao");
        map_skill("parry", "liuhe-dao");
        map_skill("dodge", "feiyan-zoubi");

        prepare_skill("strike", "liuhe-zhang");

        create_family("ؤ��", 18, "����");

        set("inquiry", ([
                "����̽��" : (: ask_skill1 :),
                "������"   : (: ask_skill2 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.tan" :),
                (: perform_action, "blade.shan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 150);
        set_temp("apply/unarmed_damage", 150);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/gaibang/npc/obj/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
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

        if (me->query("can_perform/liuhe-zhang/tan"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("liuhe-zhang", 1) < 1)
                return "���������Ʒ���δ��ѧ�������������У�";

        if (me->query("gongxian") < 50)
                return "��������ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 3000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("liuhe-zhang", 1) < 60)
                return "��������Ʒ����δ�������ö���ϰ��ϰ��";

        message_sort(HIY "\n$n" HIY "����һЦ��Ҳ���𻰣���Ȼ�䵥���"
                     "��̽��������$N" HIY "��ǰ���䡣$N" HIY "��ʱ��"
                     "ʧɫ����æ���Ծ�����ߣ�����Ȼ������$n" HIY "��"
                     "����������$N" HIY "���ز���࣬������Ϊ���ɡ�\n"
                     "\n" NOR, me, this_object()); 

        if ((string)me->query("gender") == "Ů��")
        {
                command("ah");
                command("say ���ԡ��Բ�ס���ҡ�����������Ů�ġ�");
        } else
                command("haha");

        command("say ��ʽ������ˣ��Լ���ȥ��ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����̽������\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("liuhe-zhang"))
                me->improve_skill("liuhe-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/liuhe-zhang/tan", 1);
        me->add("gongxian", -50);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/liuhe-dao/shan"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("liuhe-dao", 1) < 1)
                return "�������ϵ�����δ��ѧ�������������У�";

        if (me->query("gongxian") < 200)
                return "��������ؤ����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 5000)
                return "�������������ò������������Ȳ�æ���㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����㣬ѧ�������С�";

        if (me->query_skill("liuhe-dao", 1) < 80)
                return "������ϵ������δ�������ö���ϰ��ϰ��";

        message_sort(HIY "\n$n" HIY "��$N" HIY "Ц��Ц���γ������嵶"
                     "�������У�˵�����������ϵ�����Ҫ��������չ��Ĩ"
                     "�������硢���������ƣ������ˡ���˵���ֻ��$n" HIY
                     "���иֵ����²��������������������ͻ��������任"
                     "�����ַ�λ�����ֻ�����һ�����䣬�����������"
                     "ֱ�졣\n" NOR, me, this_object());

        command("nod");
        command("say ֻҪ�������������ϵķ�λ�����б㲻����ϰ��");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("liuhe-dao"))
                me->improve_skill("liuhe-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/liuhe-dao/shan", 1);
        me->add("gongxian", -200);
        return 1;
}