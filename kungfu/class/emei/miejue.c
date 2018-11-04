inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

#include <ansi.h>
#include "emei.h"

string ask_for_quit();

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();
mixed ask_skill5();
mixed ask_skill6();
mixed ask_skill7();
mixed ask_skill8();
mixed ask_skill9();

void create()
{
        set_name("���ʦ̫", ({ "miejue shitai", "miejue", "shitai", "mie", "jue"}));
        set("long", "���Ƕ����ɵĵ��������ӣ����ζ����������ˡ�\n");
        set("gender", "Ů��");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "bonze");

        set("inquiry",([
                "���"     : "Ҫ����Ҿ�����",
                "����"     : "Ҫ����Ҿ�����",
                "�ƺ�����" : "�����޼�Ӧ������֮Լ�����Ұ����������ѷ��Ĳ���Ʈѩ�������ˡ�",
                "�������" : "�ߣ��Դӹ�����һս�������ѽ����з�棬���ұ��˰ɡ�",
                "����"     : "�Ҷ�ü�ɾ�ѧ���֮�࣬�㵽��Ҫ��ʲô���У�",
                "����"     : "�Ҷ�ü�ɾ�ѧ���֮�࣬�㵽��Ҫ��ʲô������",
                "����"     : (: ask_for_quit :),
                "��"     : (: ask_skill1 :),
                "����"     : (: ask_skill2 :),
                "�����岼" : (: ask_skill3 :),
                "��ʽ��һ" : (: ask_skill4 :),
                "�ؽ����" : (: ask_skill5 :),
                "���ָѨ" : (: ask_skill6 :),
                "���λ�Ӱ" : (: ask_skill7 :),
                "������" : (: ask_skill8 :),
                "��ħ����" : (: ask_skill9 :),
        ]));

        set("str", 35);
        set("int", 35);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jingli", 1200);
        set("max_jingli", 1200);
        set("jiali", 200);
        set("combat_exp", 2500000);
        set("score", 50000);

        set_skill("force", 260);
        set_skill("emei-xinfa", 260);
        set_skill("emei-jiuyang", 200);
        set_skill("linji-zhuang", 260);
        set_skill("dodge", 240);
        set_skill("zhutian-bu", 240);
        set_skill("finger", 240);
        set_skill("tiangang-zhi", 240);
        set_skill("hand", 240);
        set_skill("jieshou-jiushi", 240);
        set_skill("strike", 260);
        set_skill("jinding-zhang", 260);
        set_skill("piaoxue-zhang", 260);
        set_skill("sixiang-zhang", 260);
        set_skill("sword", 260);
        set_skill("huifeng-jian", 260);
        set_skill("emei-jian", 260);
        set_skill("yitian-jian", 260);
        set_skill("blade", 240);
        set_skill("yanxing-dao", 240);
        set_skill("parry", 260);
        set_skill("martial-cognize", 200);
        set_skill("literate", 200);
        set_skill("mahayana", 200);
        set_skill("buddhism", 200);

        set("no_teach", ([
                "emei-jiuyang" : "����Ҿ������˲�ȱ��ȫ�ľ����񹦣��ټ�ʮ��ׯ"
                "ʤ֮ǧ�����㻹��ѧ�����ˡ�",
        ]));

        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian-bu");
        map_skill("finger", "tiangang-zhi");
        map_skill("hand", "jieshou-jiushi");
        map_skill("strike", "jinding-zhang");
        map_skill("sword", "huifeng-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "yitian-jian");

        prepare_skill("strike", "jinding-zhang");
        prepare_skill("hand", "jieshou-jiushi");

        create_family("������", 3, "������");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.jue" :),
                (: perform_action, "finger.ling" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "hand.jie" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        string name, new_name;

        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 30000)
        {
                command("say ����������֮������̫�٣�ʵ����̫�٣�");
                return;
        }

        if ((int)ob->query("combat_exp") < 300000)
        {
                command("sigh");
                command("say ��Ľ�������̫ǳ�������ȶ����������˵�ɡ�");
                return;
        }

        if ((int)ob->query_skill("mahayana", 1) < 100)
        {
                command("say �������͹���Ϊ�����У��úø������");
                return;
        }

        if ((int)ob->query_skill("emei-xinfa",1) < 100)
        {
                command("say ��ô���£������ڹ��ķ�����ôѧ�ģ��úø�������ȥ��");
                return;
        }

        name = ob->query("name");
        new_name = "��" + name[2..3];
        NAME_D->remove_name(ob->query("name"), ob->query("id"));
        ob->set("name", new_name);
        NAME_D->map_name(ob->query("name"), ob->query("id"));

        command("say �ðɣ��Ҿ��������ˡ�");
        command("say �Ժ���ͽ���" + new_name + "��Ҫ��Ϊʦһ���������µĶ���ͳͳɱ�⣡");
        command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
        object me;
        me = this_player();

        if (me->query("family/family_name") != "������")
                return "����ʲô�ˣ��ܵ����������ң�\n";

        if( (string)me->query("class") != "bonze" )
                return "�����ӷ��㱾���׼��ˣ���̸���ף�\n";

        me->set_temp("pending/quit_bonze", 1);
        command("heng");
        return "��úõĸ��Ұ����������Ժ�����ħ�������������Ӳ�������\n";
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/huifeng-jian/mie"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("huifeng-jian", 1) < 1)
                return "�����ط����������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1000)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 180)
                return "����ڹ�����̫ǳ������ʹ����ط���������еľ���֮����";

        if (me->query_skill("huifeng-jian", 1) < 120)
                return "��ط����������δ�����þ��������������е�΢��֮����";

        if (me->query("shen") < 30000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "΢΢���˵�ͷ����¶�����ɫ����$N" HIY
                     "������ǰ���ڶ������ܵ�˵��Щʲô��$N" HIY "������ĵ�"
                     "һЦ���ƺ�������ʲô��\n\n" NOR, me, this_object());

        command("say �Ժ����Щ���˲�Ҫ����һ�����������У�");
        tell_object(me, HIC "��ѧ���ˡ��𽣡���\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("huifeng-jian"))
                me->improve_skill("huifeng-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/huifeng-jian/mie", 1);
        me->add("gongxian", -1000);
        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/huifeng-jian/jue"))
                return "���Լ���������������ħ�Ϳ�������Щ���ˣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("huifeng-jian", 1) < 1)
                return "�����ط����������ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1800)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 300)
                return "����ڹ�����̫ǳ������ʹ����ط���������еľ���֮����";

        if (me->query_skill("huifeng-jian", 1) < 180)
                return "��ط����������δ�����þ��������������е�΢��֮����";

        if (me->query("shen") < 30000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "������������գ�������֣������૵�"
                     "�����Ҷ��������Ǻ�����˰��������˰��Σ�$n" HIY "��"
                     "�ع���������$N" HIY "�������ܵ�˵��Щʲô��\n\n" NOR,
                     me, this_object());

        command("say �����ˣ��Ժ����Щ���˲�Ҫ������һ��ɱһ����"
                "������ɱһ˫��");
        tell_object(me, HIC "��ѧ���ˡ���������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("huifeng-jian"))
                me->improve_skill("huifeng-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/huifeng-jian/jue", 1);
        me->add("gongxian", -1800);
        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();
        if (me->query("can_perform/sixiang-zhang/xing"))
                return "���Լ���������������ħ�Ϳ�������Щ���ˣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("sixiang-zhang", 1) < 1)
                return "���������Ʒ���ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 80)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 100)
                return "����ڹ�����̫ǳ������ѧ������һ�С�";

        if (me->query_skill("sixiang-zhang", 1) < 70)
                return "��������Ʒ����δ��������ѧ������һ�С�";

        if (me->query("shen") < 5000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "��΢���˵�ͷ��˵�����������ˣ����漴"
                     "һ����Х��˫�Ʒ׷ɹ������Ӱ���ص�������ʵ�ѱ棬ȫȫ"
                     "����$N" HIY "ȫ��\n\n" NOR, me, this_object());

        command("say �ղ�����ʩչ�ı�����ʽ�����岼�����Լ���ȥ��ϰ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������岼����\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("sixiang-zhang"))
                me->improve_skill("sixiang-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/sixiang-zhang/xing", 1);
        me->add("gongxian", -80);
        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();
        if (me->query("can_perform/jinding-zhang/bashi"))
                return "���Լ���������������ħ�Ϳ�������Щ���ˣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("jinding-zhang", 1) < 1)
                return "���������ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 250)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 120)
                return "����ڹ�����̫ǳ������ѧ������һ�С�";

        if (me->query_skill("jinding-zhang", 1) < 100)
                return "��Ľ����ƻ��δ��������ѧ������һ�С�";

        if (me->query("shen") < 8000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "����$N" HIY "����ĵ��˵�ͷ��˵������"
                     "��Ȼ��ˣ������ұ㴫������У���˵��$n" HIY "������"
                     "��һ������վ������������ȫ������˫�������ĳ�����ʱ"
                     "ֻ�����顱��һ�����죬$N" HIY "��ǰ������ʯ����Ӧ��"
                     "���飬��ɳ����ʯм�ɽ���ֱ����$N" HIY "Ŀ�ɿڴ���"
                     "\n\n" NOR, me, this_object());

        command("say ���в������ӣ�ֻ����ȥ���ڼ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ���ʽ��һ����\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("jinding-zhang"))
                me->improve_skill("jinding-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jinding-zhang/bashi", 1);
        me->add("gongxian", -250);
        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();
        if (me->query("can_perform/jieshou-jiushi/jie"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("jieshou-jiushi", 1) < 1)
                return "�������־�ʽ��ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "�ߣ����ڱ�����µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("max_neili") < 850)
                return "�����������̫ǳ������ѧ������һ�С�";

        if (me->query_skill("force") < 120)
                return "����ڹ�����̫ǳ������ѧ������һ�С�";

        if (me->query_skill("jieshou-jiushi", 1) < 100)
                return "��Ľ��־�ʽ���δ��������ѧ������һ�С�";

        if (me->query("shen") < 12000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "��ϲ����$N" HIY "��ͷ������������"
                     "�����⺢�ӣ��治������ƽʱ�Ľ̻塣��˵�꽫$N" HIY
                     "������ǰ��ϸ˵���á�\n\n" NOR, me, this_object());

        command("say ���������Ը������ٺ��ʲ��������Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��ؽ��������\n" NOR);

        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("jieshou-jiushi"))
                me->improve_skill("jieshou-jiushi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jieshou-jiushi/jie", 1);
        me->add("gongxian", -300);
        return 1;
}

mixed ask_skill6()
{
        object me;

        me = this_player();
        if (me->query("can_perform/tiangang-zhi/ling"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("tiangang-zhi", 1) < 1)
                return "�������ָѨ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 250)
                return "�ߣ����ڱ�����µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("max_neili") < 800)
                return "�����������̫ǳ������ѧ������һ�С�";

        if (me->query_skill("force") < 100)
                return "����ڹ�����̫ǳ������ѧ������һ�С�";

        if (me->query_skill("tiangang-zhi", 1) < 100)
                return "������ָѨ�����δ��������ѧ������һ�С�";

        if (me->query("shen") < 10000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "��ϲ����$N" HIY "��ͷ������������"
                     "�����⺢�ӣ��治������ƽʱ�Ľ̻塣��˵�꽫$N" HIY
                     "������ǰ��ϸ˵���á�\n\n" NOR, me, this_object());

        command("say �ղ�����˵���㶼��ס�����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����ָѨ����\n" NOR);

        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("tiangang-zhi"))
                me->improve_skill("tiangang-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tiangang-zhi/ling", 1);
        me->add("gongxian", -250);
        return 1;
}

mixed ask_skill7()
{
        object me;

        me = this_player();
        if (me->query("can_perform/yanxing-dao/huan"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("yanxing-dao", 1) < 1)
                return "�������е�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "�ߣ����ڱ�����µµ��Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query("max_neili") < 800)
                return "�����������̫ǳ������ѧ������һ�С�";

        if (me->query_skill("force") < 120)
                return "����ڹ�����̫ǳ������ѧ������һ�С�";

        if (me->query_skill("yanxing-dao", 1) < 80)
                return "������е������δ��������ѧ������һ�С�";

        if (me->query("shen") < 15000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "΢΢һЦ������������Ҫ�޳���һ�У���"
                     "��ͨ���������֮ѧ����$N" HIY "���˵�ͷ������˵����"
                     "������̫��������������������̫������Ϊ����̫��ΪǬ"
                     "�ң�����Ϊ��������Ϊ�㿲��̫��Ϊ������Ǭ�ϡ�������"
                     "�붫���������𶫱����Ҷ��ϡ������ϡ���������������Ǭ"
                     "Ϊ˳����������Ϊ�档����ʦ�����̣���ض�λ��ɽ��ͨ��"
                     "���׷��ౡ��ˮ�����䣬�������������˳��֪������"
                     "����$n" HIY "�����ϲ��˵���������������ҹ�Ȼû"
                     "�����㣬��㴫������У���$n" HIY "��$N" HIY "���ϵ�"
                     "��ϸ˵���ã�$N" HIY "������ĵ�һЦ���ƺ�������ʲ"
                     "ô��\n\n" NOR, me, this_object());

        command("say �ղ�����˵��������ˣ��Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����λ�Ӱ����\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("yanxing-dao"))
                me->improve_skill("yanxing-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yanxing-dao/huan", 1);
        me->add("gongxian", -300);
        return 1;
}

mixed ask_skill8()
{
        object me;

        me = this_player();
        if (me->query("can_perform/emei-jian/xian"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("emei-jian", 1) < 1)
                return "�������ҽ�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 80)
                return "����ڹ�����̫ǳ���ò�����һ�У�";

        if (me->query_skill("emei-jian", 1) < 60)
                return "����ҽ�����δ�����þ��û�������С�";

        if (me->query("shen") < 3000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "΢΢���˵�ͷ����¶�����ɫ����$N" HIY
                     "������ǰ���ڶ���������˵��Щʲô��$N" HIY "�������"
                     "��һЦ���ƺ�������ʲô��\n\n" NOR, me, this_object());

        command("say ���кܼ򵥣���ȥ���Լ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ������֡���\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("emei-jian"))
                me->improve_skill("emei-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/emei-jian/xian", 1);
        me->add("gongxian", -50);
        return 1;
}

mixed ask_skill9()
{
        object me;

        me = this_player();
        if (me->query("can_perform/yitian-jian/fumo"))
                return "�����Ҳ����Ѿ��̹��������Լ���ȥ�����ɣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�����������ģ�����ҹ�����";

        if (me->query_skill("yitian-jian", 1) < 1)
                return "�������콣����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 500)
                return "�ߣ����ڱ�����������Ϊ����һ������ʱ�����ܴ��㡣";

        if (me->query_skill("force") < 180)
                return "����ڹ�����̫ǳ���ò�����һ�У�";

        if (me->query_skill("yitian-jian", 1) < 120)
                return "�����콣����δ�����þ��û�������С�";

        if (me->query("shen") < 20000)
                return "�ߣ���������������黹���ò��������ò�����";

        message_sort(HIY "\n$n" HIY "΢΢���˵�ͷ����¶�����ɫ����$N" HIY
                     "������ǰ���ڶ���������˵��Щʲô��$N" HIY "�������"
                     "��һЦ���ƺ�������ʲô��\n\n" NOR, me, this_object());

        command("sigh");
        command("say ����Ǳ����콣���ڵĻ�����������ˬ�첻����");
        tell_object(me, HIC "��ѧ���ˡ���ħ��������\n" NOR);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("yitian-jian"))
                me->improve_skill("yitian-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yitian-jian/fumo", 1);
        me->add("gongxian", -500);
        return 1;
}

void unconcious()
{
        die();
}
