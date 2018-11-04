#include <ansi.h>
#include "honghua.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("����־", ({ "chang hezhi", "chang", "hezhi" }));
        set("title", "�컨���嵱��");
        set("nickname", HIB "���޳�" NOR);
        set("long", "������ָ����ݣ���ɫ���ƣ��۾���������\n"
                    "������һ�����룬üëбб�ĵ�����������\n"
                    "�����ǿɲ�����������ɻ��µ��˵�ͽ�ܡ�\n"
                    "��ɳ�ƵĹ��򣬽����������ܵС��ڰ��޳�\n"
                    "���ֵ��Ǵ�����������������һ��ٸ���ƶ��\n"
                    "�����ĺ���������˵�������������š�\n");
        set("gender", "����");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 120);
        set("combat_exp", 1000000);
        set("score", 10000);

        set_skill("force", 140);
        set_skill("honghua-xinfa", 140);
        set_skill("qingcheng-neigong", 140);
        set_skill("strike", 160);
        set_skill("heisha-zhang", 160);
        set_skill("dodge", 160);
        set_skill("yanzi-chuanyun", 160);
        set_skill("sword", 140);
        set_skill("songfeng-jian", 140);
        set_skill("parry", 160);
        set_skill("martial-cognize", 120);
        set_skill("literate", 140);

        map_skill("force"  , "qingcheng-neigong");
        map_skill("sword"  , "songfeng-jian");
        map_skill("strike" , "heisha-zhang");
        map_skill("dodge"  , "yanzi-chuanyun");
        map_skill("parry"  , "heisha-zhang");

        prepare_skill("strike", "heisha-zhang");

        set("no_teach", ([
                "qingcheng-neigong" : "���ڹ�û��ɶ���ã�������Ӻ������Ʒ������ˡ�",
        ]));

        create_family("�컨��", 4, "����");

        set("inquiry", ([
                "�߻���" : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.cui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
        setup();

        carry_object("/d/wudang/obj/greyrobe")->wear();
    
}

void attempt_apprentice(object me)
{
        if (! permit_recruit(me))
                return;

        if ((int)me->query("shen") < 5000)
        {
                command("say ������������ˣ��Ҳ������㡣");
                return;
        }

        if ((int)me->query_skill("honghua-xinfa", 1) < 50)
        {
                command("say ��ѱ��ŵ��ķ�������������");
                return;
        }

        command("heihei");
        command("say �Ժ���͸������Ӱɡ�");
        command("recruit " + me->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/heisha-zhang/cui"))
                return "���Ӱ�ɶ�Ӷ�����˵���ˣ�����զ��ô��Ŷ��";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���������Ķ����ģ������ϲ����㡣";

        if (me->query_skill("heisha-zhang", 1) < 1)
                return "������ɰ�ƶ�ûѧ����˵ɶ�Ӵ߻���Ŷ��";

        if (me->query("gongxian") < 150)
                return "�������׶����ò���������զ�������";

        if (me->query("shen") < 5000)
                return "�����������嶼�����ˣ��һ��Ҵ���ɶ���";

        if (me->query_skill("force") < 150)
                return "�����ڹ���ûѧ�ã�ѧɶ������Ŷ��";

        if (me->query_skill("heisha-zhang", 1) < 100)
                return "���ɰ��ѧ���⸱����ӵ��ԣ�զ�����߻����";

        message_vision(HIY "$n" HIY "���˿�$N" HIY "������һЦ��˵��"
                       "����Ҫ�ã�Ҫ�ã�������ѧ�û�\n���ԣ������Ҿ�"
                       "����߻��ơ���$n" HIY "˵�գ��������ĳ�һ�ƣ�"
                       "��\n�Ʋ��Ű������������$N" HIY "���Ƽ䣬����"
                       "���ۡ���һ�����漴��ɳ��\n����ƮȻ������ǰ"
                       "ɳ�ػ�Ȼ����һ���ںڵ���ӡ��ɷ�Ǿ��ˡ�\n" NOR,
                       me, this_object());

        command("heihei");
        command("say �ղ�����˵���㶼Ҫ�Ǻ��˺ã��Լ���ȥ����");
        tell_object(me, HIC "��ѧ���ˡ��߻��ơ���\n" NOR);

        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("heisha-zhang"))
                me->improve_skill("heisha-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/heisha-zhang/cui", 1);
        me->add("gongxian", -150);

        return 1;
}
