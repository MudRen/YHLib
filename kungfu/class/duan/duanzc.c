#include <ansi.h>
#include "duan.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_skill1();
mixed ask_skill2();
mixed ask_skill3();
mixed ask_skill4();

void create()
{
        set_name("������", ({ "duan zhengchun", "duan", "zhengchun" }));
        set("title",  "����������󽫾�" );
        set("nickname", HIR "������" NOR);
        set("long", "�����Ǵ�������������������̫�ܣ��������İ���ʥ�֡�\n");
        set("gender", "����");
        set("age", 45);
        set("class", "royal");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 31);
        set("dex", 30);
        set("max_qi", 4500);
        set("max_jing", 3000);
        set("neili", 5800);
        set("max_neili", 5800);
        set("jiali", 200);
        set("combat_exp", 2500000);
        set("score", 50000);

        set_skill("force", 220);
        set_skill("duanshi-xinfa", 220);
        set_skill("dodge", 200);
        set_skill("tiannan-bu", 200);
        set_skill("cuff", 220);
        set_skill("jinyu-quan", 220);
        set_skill("strike", 220);
        set_skill("wuluo-zhang", 220);
        set_skill("sword", 220);
        set_skill("staff", 220);
        set_skill("duanjia-jian", 220);
        set_skill("finger", 200);
        set_skill("qiantian-zhi", 200);
        set_skill("yiyang-zhi", 200);
        set_skill("parry", 220);
        set_skill("jingluo-xue", 180);
        set_skill("literate", 240);
        set_skill("martial-cognize", 200);

        map_skill("force", "duanshi-xinfa");
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
                "Ǭ����ָ" : (: ask_skill1 :),
                "���Ʊ��" : (: ask_skill2 :),
                "��������" : (: ask_skill3 :),
                "����һ��" : (: ask_skill4 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.dian" :),
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
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver", 50);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("nod");
        command("say �Ҿ������㣬����ú�ѧϰ�Ҷμ��似������������Ϊ��");
        command("recruit " + ob->query("id"));
        return;
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/qiantian-zhi/zhi"))
                return "�㲻���Ѿ�ѧ����ô������ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query_skill("qiantian-zhi", 1) < 1)
                return "����Ǭ��ָ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "��������µµ��Ϊ����������ŵù��㣿";

        if (me->query_skill("force") < 100)
                return "���ڹ�����Ϊ�������������������ɡ�";

        if (me->query("max_neili") < 500)
                return "���������Ϊ�����������ߵ������ɡ�";

        if (me->query_skill("qiantian-zhi", 1) < 80)
                return "���Ǭ��ָ����������������������˵�ɡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ����$N" HIY "������ߣ���"
                     "$N" HIY "���Ե���ϸ˵���ã�$N" HIY "һ����һ�߲�"
                     "ס�ĵ�ͷ�������Ӵ�������\n\n" NOR,
                     me, this_object()); 

        command("nod");
        command("say ���кܼ򵥣��Լ���ϰ��ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�Ǭ����ָ����\n" NOR);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("qiantian-zhi"))
                me->improve_skill("qiantian-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qiantian-zhi/zhi", 1);
        me->add("gongxian", -50);

        return 1;
}


mixed ask_skill2()
{
        object me;

        me = this_player();
        if (me->query("can_perform/wuluo-zhang/bian"))
                return "�㲻���Ѿ�ѧ����ô������ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query_skill("wuluo-zhang", 1) < 1)
                return "�������������ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "��������µµ��Ϊ����������ŵù��㣿";

        if (me->query_skill("force") < 100)
                return "���ڹ�����Ϊ�������������������ɡ�";

        if (me->query("max_neili") < 500)
                return "���������Ϊ�����������ߵ������ɡ�";

        if (me->query_skill("wuluo-zhang", 1) < 100)
                return "������������ƻ���������������˵�ɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ�����¸����𻰣������������"
                     "һ������ʱ���������Ӱ����ƮƮ�����˳�ȥ��ȴ��������"
                     "�ۡ�������$n" HIY "��Ӱ����ľ��羹��$N" HIY "��Χ��"
                     "����ӡ���������ӡ��\n\n" NOR, me, this_object()); 

        command("say ������ô��");
        tell_object(me, HIC "��ѧ���ˡ����Ʊ�á���\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("wuluo-zhang"))
                me->improve_skill("wuluo-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/wuluo-zhang/bian", 1);
        me->add("gongxian", -150);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();
        if (me->query("can_perform/jinyu-quan/man"))
                return "�㲻���Ѿ�ѧ����ô������ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query_skill("jinyu-quan", 1) < 1)
                return "��������ȭ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "��������µµ��Ϊ����������ŵù��㣿";

        if (me->query_skill("force") < 100)
                return "���ڹ�����Ϊ�������������������ɡ�";

        if (me->query("max_neili") < 500)
                return "���������Ϊ�����������ߵ������ɡ�";

        if (me->query_skill("jinyu-quan", 1) < 80)
                return "��Ľ���ȭ������������������˵�ɡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ����$N" HIY "������ߣ���"
                     "$N" HIY "���Ե���ϸ˵���ã�$N" HIY "һ����һ�߲�"
                     "ס�ĵ�ͷ�������Ӵ�������\n\n" NOR,
                     me, this_object()); 

        command("nod");
        command("say ���ˣ����Լ�ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��������á���\n" NOR);
        if (me->can_improve_skill("cuff"))
                me->improve_skill("cuff", 1500000);
        if (me->can_improve_skill("jinyu-quan"))
                me->improve_skill("jinyu-quan", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jinyu-quan/man", 1);
        me->add("gongxian", -150);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();
        if (me->query("can_perform/duanjia-jian/jing"))
                return "�㲻���Ѿ�ѧ����ô������ʲô���ʣ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ������ǶμҵĴ��ˣ��⻰��ʲô��˼��";

        if (me->query_skill("duanjia-jian", 1) < 1)
                return "�����μҽ�����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "��������µµ��Ϊ����������ŵù��㣿";

        if (me->query("shen") < 0)
                return "���˰ɣ��������ֻ������ȥ����";

        if (me->query_skill("force") < 120)
                return "����ڹ�����Ϊ�����������������ɡ�";

        if (me->query("max_neili") < 800)
                return "���������Ϊ�����������ߵ������ɡ�";

        if (me->query_skill("duanjia-jian", 1) < 80)
                return "��Ķμҽ��������У�������˵�ɣ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ����������������͸�����ʾ"
                     "һ�飬�ɿ�����ˣ���˵��ֻ��$n" HIY "�γ����䳤��"
                     "������һ���������²�������������֮�������г���ʹ��"
                     "�������һ�㣬������$N" HIY "����ʽ֮���ʵ��$N"
                     HIY "ǰ��δ�š�\n\n" NOR, me, this_object());

        command("haha");
        command("say ��ʽ�Ѿ������ˣ����Լ���ȥ�ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�����һ������\n" NOR);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("duanjia-jian"))
                me->improve_skill("duanjia-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/duanjia-jian/jing", 1);
        me->add("gongxian", -300);

        return 1;
}

void unconcious()
{
        die();
}
