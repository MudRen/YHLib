#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

mixed  ask_skill1();
mixed  ask_skill2();
mixed  ask_skill3();
mixed  ask_skill4();
mixed  ask_skill5();

void create()
{
        set_name("������", ({ "wang chongyang", "wang", "chongyang" }));
        set("long", @LONG
������ȫ��̵Ŀ�ɽ��ʦ���״��ƽ���������
���ˡ�������ƮƮ�����ۻ��䣬üĿ��񳣬��
��Щ�ɷ���ǵ�ζ����������һǻ��Ѫ����Ч
���������������ϧ��͢���ܣ����Ǳ��Ļ���
�䣬���ʱ�ִӵ��¾�������������������
�Ĵ�����Ӷ��ִ�ȫ��̡�
LONG);
        set("title", "ȫ���ɿ�ɽ��ʦ");
        set("nickname", HIW "����ͨ" NOR);
        set("age", 76);
        set("gender", "����");
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 33);
        set("int", 35);
        set("con", 38);
        set("dex", 33);
        set("max_qi", 8000);
        set("max_jing", 8000);
        set("neili", 10000);
        set("jingli", 8000);
        set("max_neili", 10000);
        set("max_jingli", 8000);
        set("jiali", 250);
        set("combat_exp", 5000000);
        set("score", 500000);

        set_skill("force", 400);
        set_skill("quanzhen-xinfa", 380);
        set_skill("xuanmen-neigong", 380);
        set_skill("unarmed", 380);
        set_skill("xiantian-gong", 400);
        set_skill("dodge", 380);
        set_skill("tianshan-feidu", 360);
        set_skill("jinyan-gong", 380);
        set_skill("parry", 380);
        set_skill("jinguan-yusuo", 380);
        set_skill("strike", 380);
        set_skill("chongyang-shenzhang", 360);
        set_skill("haotian-zhang", 380);
        set_skill("finger", 380);
        set_skill("zhongnan-zhi", 360);
        set_skill("yiyang-zhi", 380);
        set_skill("hand", 380);
        set_skill("qixing-shou", 380);
        set_skill("sword", 380);
        set_skill("qixing-jian", 360);
        set_skill("tonggui-jian", 360);
        set_skill("quanzhen-jian", 380);
        set_skill("whip", 340);
        set_skill("tiangang-chenfa", 340);
        set_skill("jingluo-xue", 300);
        set_skill("taoism", 400);
        set_skill("literate", 340);
        set_skill("martial-cognize", 400);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jian");
        map_skill("whip", "tiangang-chenfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "jinguan-yusuo");
        map_skill("unarmed", "xiantian-gong");
        map_skill("finger", "yiyang-zhi");
        map_skill("strike", "haotian-zhang");
        map_skill("hand", "qixing-shou");

        prepare_skill("unarmed", "xiantian-gong");

        set("no_teach/sun-finger", "һ��ָ���Ƕμ��ش����Ҳ��ܽ��㡣");

        create_family("ȫ���", 1, "�ƽ�");

        set("inquiry", ([
                "ȫ���"     : "��ȫ��������µ����������ڡ�",
                "����"       : "����ѧʲô���У�",
                "����"       : "����ѧʲô���У�",
                "������Ԫ"   : (: ask_skill1 :),
                "һ��������" : (: ask_skill2 :),
                "������"     : (: ask_skill2 :),
                "��ػ�Ԫ"   : (: ask_skill3 :),
                "��������"   : (: ask_skill4 :),
                "�����Ƶ�"   : (: ask_skill5 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.hun" :),
                (: perform_action, "unarmed.fen" :),
                (: perform_action, "unarmed.dang" :),
                (: perform_action, "unarmed.jian" :),
                (: perform_action, "parry.suo" :),
                (: exert_function, "hup" :),
                (: exert_function, "shield" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 35)
        {
                command("say ������Ի������������������Ǽ���ͽ��ѧϰ�ɡ�");
                return;
        }


        if ((int)ob->query_skill("xuanmen-neigong", 1) < 120
           && (int)ob->query_skill("quanzhen-xinfa", 1) < 120)
        {
                command("say ��ı����ڹ��ķ�����㣬ֻ������"
                        "���Ը�������书��");
                return;
        }

        if (ob->query("combat_exp") < 450000)
        {
                command("say ���ʵս����̫������������Ը�������书��");
                return;
        }

        if ((int)ob->query("shen") < 80000)
        {
                command("say �����������ұ�ѧ���˵���ּ�������Щ��"
                        "��֮�£��ҷ�������Ϊͽ��");
                return;
        }
        command("say �����������ʶ��ɴ����²����Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}


mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xiantian-gong/hup"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("xiantian-gong", 1) < 1)
                return "�������칦��ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 500)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 100000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("xiantian-gong", 1) < 200)
                return "�����칦����Ϊ���������������������ɡ�";

        if (me->query("max_neili") < 2000)
                return "���������Ϊ�Բ��㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ���ӻ�������ȡ����һ��"
                     "С���ӣ�ָ�����е�һ�ζ�$N" HIY "ϸ˵���ã�$N"
                     HIY "һ����һ�ߵ�ͷ��\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say ���Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������Ԫ����\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiantian-gong/hup", 1);
        me->add("gongxian", -500);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/quanzhen-jian/hua"))
                return "��ȫ�潣���Ѵ�������裬����ûʲô�ɽ̵��ˡ�";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("quanzhen-jian", 1) < 1)
                return "����ȫ�潣����ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 1600)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 100000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("quanzhen-jian", 1) < 200)
                return "������ɽ������˽⻹����͸�����о�͸���������Ұɡ�";

        if (me->query_skill("xiantian-gong", 1) < 100)
                return "�����칦����Ϊ���������������������ɡ�";

        if (me->query("max_neili") < 4500)
                return "���������Ϊ�Բ��㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "����һЦ�����ִӵ�����˺��һ�ǲ�"
                     "�����������¼䣬ֻ���ǲ�����ʱ�����ͬ����������"
                     "�̴�������޷����������ѳ����������ʽ���������"
                     "�ȡ�ֻ����$N" HIY "Ŀ�ɿڴ���\n\n"
                     NOR, me, this_object()); 

        command("haha");
        command("say ���Լ���ȥ��Ħ�ɣ��м�Ī�߽�аħ�����");
        tell_object(me, HIC "��ѧ���ˡ�һ�������塹��\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/quanzhen-jian/hua", 1);
        me->add("gongxian", -1600);

        return 1;
}

mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xiantian-gong/hun"))
                return "�����㲻���Ѿ�ѧ������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("xiantian-gong", 1) < 1)
                return "�������칦��ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 1800)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 120000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("xiantian-gong", 1) < 200)
                return "�����칦����Ϊ���������������������ɡ�";

        if (me->query("max_neili") < 4000)
                return "���������Ϊ�Բ��㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "����һЦ����$N" HIY "˵���������"
                     "���칦��˾��磬ʵ������������Ϊʦ�����������к�"
                     "������˵��$n" HIY "��ڿ����ƣ���������ʾ������\n"
                     "\n" NOR, me, this_object()); 

        command("nod");
        command("say ��ʽ������ˣ��ܷ�����Ϳ����Լ��ˡ�");
        tell_object(me, HIC "��ѧ���ˡ���ػ�Ԫ����\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiantian-gong/hun", 1);
        me->add("gongxian", -1800);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xiantian-gong/fen"))
                return "�����㲻���Ѿ�ѧ������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("xiantian-gong", 1) < 1)
                return "�������칦��ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 2000)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 130000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("xiantian-gong", 1) < 240)
                return "�����칦����Ϊ���������������������ɡ�";

        if (me->query("max_neili") < 4000)
                return "���������Ϊ�Բ��㣬�������ߵ������ɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ����$N" HIY "˵�������ѵ�"
                     "����������裬����ʦ���ʹ������У��ɿ����ˣ���$n"
                     HIY "�漴һ��������ȫ������������ת��������Χ����"
                     "�������ѡ�����΢΢һ����������������ʽ����������"
                     "��ǧ�����ˣ�����֮ǿ�������þ���ء�������������"
                     "��ֱ����$N" HIY "Ŀ�ɿڴ���\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say ��ʽ������ˣ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ��������𡹡�\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiantian-gong/fen", 1);
        me->add("gongxian", -2000);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xiantian-gong/dang"))
                return "�����㲻���Ѿ�ѧ������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("xiantian-gong", 1) < 1)
                return "�������칦��ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 2500)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 150000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("xiantian-gong", 1) < 240)
                return "�����칦����Ϊ���������������������ɡ�";

        if (me->query("max_neili") < 5000)
                return "���������Ϊ�Բ��㣬�������ߵ������ɡ�";

        if (! me->query("can_perform/xiantian-gong/fen"))
                return "���������ɡ��������������������㻹����ѧϰ�ɣ�";

        message_sort(HIY "\n$n" HIY "΢΢���˵�ͷ�����ִ���$N" HIY "��"
                     "���ϣ�ͻȻ$N" HIY "����ȫ�����������Ϣ������ӿ"
                     "֮�������罭�Ӿ��̣���������Ƴ�һ�㣬���ɴ󾪡�"
                     "\n\n" NOR, me, this_object()); 

        command("haha");
        command("say ��������ˣ�");
        tell_object(me, HIC "��ѧ���ˡ������Ƶ�����\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiantian-gong/dang", 1);
        me->add("gongxian", -2500);

        return 1;
}

void unconcious()
{
        die();
}
