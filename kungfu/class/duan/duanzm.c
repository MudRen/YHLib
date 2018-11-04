#include <ansi.h>
#include "duan.h"

#define MAIJING "/clone/lonely/book/jingluoxue1"
#define MAIJING2 "/clone/lonely/book/jingluoxue2"

inherit NPC;
inherit F_MASTER;

mixed ask_maijing1();
mixed ask_maijing2();

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();

void create()
{
        set_name("������", ({ "duan zhengming", "duan", "zhengming" }));
        set("title", "���������" );
        set("nickname", HIY "������" NOR);
        set("long", "�����Ǵ�����Ĺ������̳����������Ļ�ҵ��\n");
        set("gender", "����");
        set("age", 49);
        set("class", "royal");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 32);
        set("int", 35);
        set("con", 32);
        set("dex", 29);

        set("max_qi", 6000);
        set("max_jing", 4000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 200);
        set("combat_exp", 3000000);
        set("score", 60000);

        set_skill("force", 280);
        set_skill("duanshi-xinfa", 280);
        set_skill("kurong-changong", 240);
        set_skill("dodge", 240);
        set_skill("tiannan-bu", 240);
        set_skill("cuff", 240);
        set_skill("jinyu-quan", 240);
        set_skill("strike", 240);
        set_skill("wuluo-zhang", 240);
        set_skill("sword", 240);
        set_skill("staff", 240);
        set_skill("duanjia-jian", 240);
        set_skill("finger", 280);
        set_skill("qiantian-zhi", 260);
        set_skill("yiyang-zhi", 280);
        set_skill("parry", 240);
        set_skill("jingluo-xue", 280);
        set_skill("buddhism", 260);
        set_skill("literate", 260);
        set_skill("martial-cognize", 260);

        map_skill("force", "kurong-changong");
        map_skill("dodge", "tiannan-bu");
        map_skill("finger", "yiyang-zhi");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("parry", "yiyang-zhi");
        map_skill("sword", "duanjia-jian");
        map_skill("staff", "yiyang-zhi");

        prepare_skill("finger", "yiyang-zhi");

        create_family("���ϻ���", 15, "����");

        set("inquiry", ([
                "�������"   : (: ask_skill1 :),
                "��������"   : (: ask_skill2 :),
                "��ָ��Ѩ"   : (: ask_skill3 :),
                "һָǬ��"   : (: ask_skill4 :),
                "���������" : (: ask_maijing1 :),
                "��ȧ������" : (: ask_maijing2 :),
                "��������"   : "����˵����������һ�������Լ�����δ����͸����",
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.die" :),
                (: perform_action, "sword.jing" :),
                (: perform_action, "sword.lian" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();

        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query("shen") < 50000)
        {
                command("say �㽭���ϵ���������ô����������������ܹ��κ�"
                        "���ң�");
                return;
        }


        if (ob->query_skill("duanshi-xinfa", 1) < 100)
        {
                command("say ���Ⱥú�ѧϰ���Ƕμҵ��ķ����Ժ�����ָ���㡣");
                return;
        }

        if (ob->query("combat_exp") < 400000)
        {
                command("say ��ʵս����̫�ͣ�Ӧ�ú��ڽ�������������Ҫʧ��"
                        "���ϵ����ӡ�\n");
                return;
        }

        command("say �ã����������ˣ��似��Ȼ��Ҫ��Ҳ��Ҫ���Ƕ����ι���");
        command("recruit " + ob->query("id"));
        return;
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/duanjia-jian/lian"))
                return "�㲻���Ѿ�ѧ����ô������ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query_skill("duanjia-jian", 1) < 1)
                return "�����μҽ�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "��������µµ��Ϊ����������ŵù��㣿";

        if (me->query("shen") < 0)
                return "���˰ɣ��������ֻ������ȥ����";

        if (me->query_skill("force") < 160)
                return "����ڹ�����Ϊ�����������������ɡ�";

        if (me->query_skill("duanjia-jian", 1) < 120)
                return "��Ķμҽ��������У�������˵�ɣ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ���ȵ����������ˣ�����Ȼ����ǰ"
                     "��������Ϊ���������������У���ʽ�����ޱȣ�$N" HIY "��"
                     "��һ����ֻ�ܺ��ˡ�\n\n" NOR, me, this_object());

        command("nod");
        command("say �㿴�����ô���Ժ�Ҫ�������壬ĪҪ������Ϊ��");
        tell_object(me, HIC "��ѧ���ˡ������������\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("duanjia-jian"))
                me->improve_skill("duanjia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/duanjia-jian/lian", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/yiyang-zhi/heal"))
                return "�㲻���Ѿ�ѧ����ô������ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query_skill("yiyang-zhi", 1) < 1)
                return "����һ��ָ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "��������µµ��Ϊ����������ŵù��㣿";

        if (me->query_skill("force") < 150)
                return "���ڹ�����Ϊ�������������������ɡ�";

        if (me->query("max_neili") < 1500)
                return "���������Ϊ�����������ߵ������ɡ�";

        if (me->query_skill("jingluo-xue", 1) < 100)
                return "��Ծ���ѧ���˽⻹��͸�����о�͸���������Ұɡ�";

        if (me->query_skill("yiyang-zhi", 1) < 100)
                return "���һ��ָ����������������������˵�ɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ�����һָ��������磬˲��"
                     "����$N" HIY "��ǰ����Ѩ��$N" HIY "��ʱֻ��$n" HIY
                     "����ԴԴ������ӿ�룬ȫ��һ�����飬������ʧɫ��\n"
                     "\n" NOR, me, this_object()); 

        command("smile");
        command("say ��ʽ������ˣ��㶮����");
        command("say ��������Ч������������˫�������������ȴ��̫��");
        tell_object(me, HIC "��ѧ���ˡ�������������\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("yiyang-zhi"))
                me->improve_skill("yiyang-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yiyang-zhi/heal", 1);
        me->add("gongxian", -800);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();
        if (me->query("can_perform/yiyang-zhi/dian"))
                return "�㲻���Ѿ�ѧ����ô������ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query_skill("yiyang-zhi", 1) < 1)
                return "����һ��ָ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "��������µµ��Ϊ����������ŵù��㣿";

        if (me->query("shen") < 20000)
                return "�������������ò�������������ʱ�����ܴ��㣡";

        if (me->query_skill("force") < 160)
                return "���ڹ�����Ϊ�������������������ɡ�";

        if (me->query("max_neili") < 1800)
                return "���������Ϊ�����������ߵ������ɡ�";

        if (me->query_skill("jingluo-xue", 1) < 120)
                return "��Ծ���ѧ���˽⻹��͸�����о�͸���������Ұɡ�";

        if (me->query_skill("yiyang-zhi", 1) < 120)
                return "���һ��ָ����������������������˵�ɡ�";

        message_sort(HIY "\n$n" HIY "��΢���˵�ͷ��˵�����������ˣ���˵��$n"
                     HIY "����һ��ָ����������Ȼ���һָ���仯��ˣ��ɱ�$N"
                     HIY "���Ѩ����ʽɷΪ���\n\n" NOR, me, this_object()); 

        command("haha");
        command("say ��ʽ������ˣ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ���ָ��Ѩ����\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("yiyang-zhi"))
                me->improve_skill("yiyang-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yiyang-zhi/dian", 1);
        me->add("gongxian", -400);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();
        if (me->query("can_perform/yiyang-zhi/qian"))
                return "�㲻���Ѿ�ѧ����ô������ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query_skill("yiyang-zhi", 1) < 1)
                return "����һ��ָ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 1000)
                return "��������µµ��Ϊ����������ŵù��㣿";

        if (me->query("shen") < 30000)
                return "�������������ò�������������ʱ�����ܴ��㣡";

        if (me->query_skill("force") < 220)
                return "���ڹ�����Ϊ�������������������ɡ�";

        if (me->query("max_neili") < 2400)
                return "���������Ϊ�����������ߵ������ɡ�";

        if (me->query_skill("jingluo-xue", 1) < 160)
                return "��Ծ���ѧ���˽⻹��͸�����о�͸���������Ұɡ�";

        if (me->query_skill("yiyang-zhi", 1) < 160)
                return "���һ��ָ����������������������˵�ɡ�";

        message_sort(HIY "\n$n" HIY "������$N" HIY "��һ������漴���˵�"
                     "ͷ����$N" HIY "������ߣ��ڶ��Ե���ϸ˵���ã�$N" HIY
                     "������ĵ�һЦ��������$n" HIY "�Ľ̵���������\n\n"
                     NOR, me, this_object()); 

        command("nod");
        command("say ����ɱ�����أ�ƽʱһ��Ҫ���á�");
        tell_object(me, HIC "��ѧ���ˡ�һָǬ������\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("jingluo-xue"))
                me->improve_skill("jingluo-xue", 1500000);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("yiyang-zhi"))
                me->improve_skill("yiyang-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/yiyang-zhi/qian", 1);
        me->add("gongxian", -1000);

        return 1;
}


mixed ask_maijing1()
{
        object me;
        object ob;
        object owner;

        me = this_player();

        if (me->query("family/family_name") != "���ϻ���")
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query("family/master_id") != query("id"))
                return "���š������Ϊ�ҵĵ��Ӻ���˵�ɡ�";

        if (me->query("shen") < 10000)
                return "�������������ò������������Ҳ��ܸ��㡣";

        if (me->query("combat_exp") < 10000)
                return "�����ھ���̫ǳ������æ��ȥ�Ķ�������";

        if (me->query_skill("jingluo-xue", 1) > 149)
                return "��Ծ���ѧ���˽��Ѿ���͸����Զʤ������������";

        ob = find_object(MAIJING);
        if (! ob) ob = load_object(MAIJING);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "���Ǳ�����������������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š��������ڲ��������";

                if (owner->query("family/family_name") == "���ϻ���")
                        return "����������ʱ�����ֵ�" + owner->query("name") +
                               "�ڿ�����Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���Ǳ���������������" + owner->query("name") +
                               "���У���ȥ�������ذɡ�";
        }
        ob->move(this_object());
        command("say �Ȿ���������ȥ���ɣ���Ҫ�����ж���");
        command("give mai jing to " + me->query("id"));
        return 1;
}

mixed ask_maijing2()
{
        object me;
        object ob;
        object owner;

        me = this_player();
        
        if (me->query("family/family_name") != "���ϻ���")
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query("family/master_id") != query("id"))
                return "���š������Ϊ�ҵĵ��Ӻ���˵�ɡ�";

        if (me->query("shen") < 80000)
                return "�������������ò������������Ҳ��ܸ��㡣";

        if (me->query("combat_exp") < 300000)
                return "�����ھ���̫ǳ������æ��ȥ�Ķ�������";

        if (me->query_skill("jingluo-xue", 1) > 199)
                return "��Ծ���ѧ���˽��Ѿ���͸����Զʤ������������";

        ob = find_object(MAIJING2);
        if (! ob) ob = load_object(MAIJING2);
        owner = environment(ob);
        while (owner)
        {
                if (owner->is_character() || ! environment(owner))
                        break;
                owner = environment(owner);
        }

        if (owner == me)
                return "���Ǳ���ȧ�������������������ڿ���";

        if (objectp(owner) && owner != this_object())
        {
                if (! owner->is_character())
                        return "���š��������ڲ��������";

                if (owner->query("family/family_name") == "���ϻ���")
                        return "����������ʱ�����ֵ�" + owner->query("name") +
                               "�ڿ�����Ҫ�þ�ȥ�����ɡ�";
                else
                        return "���Ǳ���������������" + owner->query("name") +
                               "���У���ȥ�������ذɡ�";
        }
        ob->move(this_object());
        command("say �Ȿ���������ȥ���ɣ���Ҫ�����ж���");
        command("give yuquan jing to " + me->query("id"));
        return 1;
}
