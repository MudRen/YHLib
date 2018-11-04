inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "emei.h"

mixed ask_skill1();
mixed ask_skill2();

void create()
{
       set_name("����ʦ̫", ({"fengling shitai", "fengling", "shitai", "feng", "ling"}));
       set("long", "�����Ƕ����ɵڶ��������˷���ʦ̫��\n"
                   "����Ŀ���飬����Ѱ������һ�㣬��\n"
                   "����һ˿����֮����\n");
        set("gender", "Ů��");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "bonze");

        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 7000);
        set("max_jing", 6000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 250);
        set("combat_exp", 5000000);

        set_skill("force", 320);
        set_skill("emei-xinfa", 300);
        set_skill("emei-jiuyang", 320);
        set_skill("linji-zhuang", 320);
        set_skill("dodge", 300);
        set_skill("zhutian-bu", 300);
        set_skill("finger", 300);
        set_skill("tiangang-zhi", 300);
        set_skill("hand", 300);
        set_skill("jieshou-jiushi", 300);
        set_skill("strike", 320);
        set_skill("jinding-zhang", 300);
        set_skill("piaoxue-zhang", 320);
        set_skill("sixiang-zhang", 300);
        set_skill("sword", 320);
        set_skill("huifeng-jian", 320);
        set_skill("emei-jian", 300);
        set_skill("blade", 300);
        set_skill("yanxing-dao", 300);
        set_skill("parry", 300);
        set_skill("martial-cognize", 300);
        set_skill("literate", 280);
        set_skill("mahayana", 300);
        set_skill("buddhism", 300);

        set("no_teach", ([
                "emei-jiuyang" : "����Ҿ������˲�ȱ��ȫ�ľ����񹦣��ټ�ʮ��ׯ"
                                 "ʤ֮ǧ�����㻹��ѧ�����ˡ�",
        ]));

        map_skill("force", "emei-jiuyang");
        map_skill("dodge", "zhutian-bu");
        map_skill("finger", "tiangang-zhi");
        map_skill("hand", "jieshou-jiushi");
        map_skill("strike", "piaoxue-zhang");
        map_skill("sword", "huifeng-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "jinding-zhang");

        prepare_skill("strike", "piaoxue-zhang");

        create_family("������", 2, "������");

        set("inquiry",([
                "���"     : "Ҫ����Ҿ�����",
                "����"     : "Ҫ����Ҿ�����",
                "�ƺ�����" : (: ask_skill1 :),
                "�������" : (: ask_skill2 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "strike.yun" :),
                (: perform_action, "strike.zhao" :),
                (: exert_function, "recover" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
        }));

        setup();

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        carry_object("/d/city/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        string name, new_name;

        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 30000)
        {
                command("say ��������������黹���ò���������ʱ���������㡣");
                return;
        }

        if ((int)ob->query("combat_exp") < 500000)
        {
                command("sigh");
                command("say ��Ľ�������̫ǳ�������ȶ����������˵�ɡ�");
                return;
        }

        if ((int)ob->query_skill("mahayana", 1) < 150)
        {
                command("say �������͹�����Ϊ�����У��úø������");
                return;
        }

        if ((int)ob->query_skill("linji-zhuang", 1) < 150)
        {
                command("say �ټ�ʮ��ׯ���Ҷ��ҵ�һ�湦����úú���ϰ��");
                return;
        }

        name = ob->query("name");
        new_name = "��" + name[2..3];
        NAME_D->remove_name(ob->query("name"), ob->query("id"));
        ob->set("name", new_name);
        NAME_D->map_name(ob->query("name"), ob->query("id"));

        command("say ��������");
        command("say �����ұ�����Ϊͽ������" + new_name + "��");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/piaoxue-zhang/yun"))
                return "��һ���Ҳ����Ѿ������������𣿻���ʲô�������Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�������������������֪���´���������";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ���ѧϰ���У��㻹���߰ɡ�";

        if (me->query_skill("piaoxue-zhang", 1) < 1)
                return "����Ʈѩ�����ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1800)
                return "��Զ������������Ĺ��׻���������������ʱ���ܴ��㡣";

        if (me->query_skill("force") < 200)
                return "����ڹ�����̫ǳ������ѧ������һ�С�";

        if (me->query("max_neili") < 2000)
                return "�����������̫ǳ������ѧ������һ�С�";

        if (me->query_skill("piaoxue-zhang", 1) < 150)
                return "���Ʈѩ�����ƻ��δ��������ѧ������һ�С�";

        if (me->query("shen") < 40000)
                return "��������������黹���ò���������ʱ�����ܴ�����С�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ����$N" HIY "˵��������Ȼ����"
                     "�⹦���Ѵ�����˾��磬Ҳ��������ƽʱ��һ�����ࡣ����"
                     "�ұ㴫����У�ϣ���պ��ܽ��Ҷ����ɷ����󡣡�˵�꣬"
                     "$n" HIY "��$N" HIY "������ǰ����$N" HIY "��������ϸ˵"
                     "���á�\n\n" NOR, me, this_object());

        command("nod");
        command("say �ղ�����˵���㶼�������𣿼����˾���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��ƺ����ơ���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("piaoxue-zhang"))
                me->improve_skill("piaoxue-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/piaoxue-zhang/yun", 1);
        me->add("gongxian", -1800);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/piaoxue-zhang/zhao"))
                return "��һ���Ҳ����Ѿ������������𣿻���ʲô�������Լ���ȥ���ɡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�������������������֪���´���������";

        if (me->query("family/master_id") != query("id"))
                return "ֻ���ҵĵ��Ӳ���ѧϰ���У��㻹���߰ɡ�";

        if (me->query_skill("piaoxue-zhang", 1) < 1)
                return "����Ʈѩ�����ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 2200)
                return "��Զ������������Ĺ��׻���������������ʱ���ܴ��㡣";

        if (me->query_skill("force") < 300)
                return "����ڹ�����̫ǳ������ѧ������һ�С�";

        if (me->query("max_neili") < 3500)
                return "�����������̫ǳ������ѧ������һ�С�";

        if (me->query_skill("piaoxue-zhang", 1) < 180)
                return "���Ʈѩ�����ƻ��δ��������ѧ������һ�С�";

        if (me->query("shen") < 40000)
                return "��������������黹���ò���������ʱ�����ܴ�����С�";

        message_sort(HIY "\n$n" HIY "����������$N" HIY "��ͷ��˵��������"
                     "�ɣ��ѵ���������ģ������Ҿͽ�������ʾһ�飬�ɵÿ�"
                     "���ˣ����������䣬ֻ��$n" HIY "�����ھ������������"
                     "����ž���죬�����Ѫ��ɷ�Ǿ��ˡ��漴$n" HIY "һ����"
                     "�ȣ�˫��Я����������֮��������ǰ�ĳ�����ʱֻ������"
                     "�ꡱһ�����죬ǰ���±�һ����ڴֵ�����Ӧ�����ϣ���"
                     "֦��������δ������ǰ�ַɳ����ɣ���ŵ�����ɽ��֮��"
                     "������������ɽ���»��������ڶ���Ⱥɽ�лص��˺�һ"
                     "�����ʧ������$n" HIY "΢΢һЦ������һ������������"
                     "���ھ�����$N" HIY "��ȥ����$N" HIY "���ѿ���Ŀ�ɿ�"
                     "����\n\n" NOR, me, this_object());

        command("say ��������ȥ��һ��Ҫ�ڼ���ϰ�����ܷ��ӳ�����������");
        tell_object(me, HIC "��ѧ���ˡ�������ա���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("piaoxue-zhang"))
                me->improve_skill("piaoxue-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/piaoxue-zhang/zhao", 1);
        me->add("gongxian", -2200);
        return 1;
}
