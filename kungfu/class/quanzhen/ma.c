#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_skill1();

void create()
{
        set_name("����", ({ "ma yu", "ma", "yu" }));
        set("long", @LONG
�������������Ĵ���ӣ�ȫ������֮�ף�����
�����������ˡ�����ü��Ŀ���Ͱ����ף���Ц
�ſ����㡣
LONG);
        set("nickname", HIR "������" NOR);
        set("title", "ȫ������");
        set("gender", "����");
        set("age", 42);
        set("class", "taoist");
        set("shen_type",1);
        set("str", 32);
        set("int", 32);
        set("con", 32);
        set("dex", 32);
        set("max_qi", 5800);
        set("max_jing", 4500);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 200);

        set("combat_exp", 2800000);

        set_skill("force", 260);
        set_skill("quanzhen-xinfa", 260);
        set_skill("xuanmen-neigong", 260);
        set_skill("sword", 240);
        set_skill("qixing-jian", 240);
        set_skill("quanzhen-jian", 240);
        set_skill("whip", 220);
        set_skill("tiangang-chenfa", 220);
        set_skill("dodge", 240);
        set_skill("tianshan-feidu", 240);
        set_skill("jinyan-gong", 240);
        set_skill("parry", 240);
        set_skill("jinguan-yusuo", 240);
        set_skill("strike", 240);
        set_skill("chongyang-shenzhang", 240);
        set_skill("haotian-zhang", 240);
        set_skill("hand", 240);
        set_skill("qixing-shou", 240);
        set_skill("finger", 240);
        set_skill("zhongnan-zhi", 240);
        set_skill("literate", 240);
        set_skill("taoism", 240);
        set_skill("martial-cognize", 240);

        map_skill("force", "xuanmen-neigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("whip", "tiangang-chenfa");
        map_skill("parry", "jinguan-yusuo");
        map_skill("finger", "zhongnan-zhi");
        map_skill("hand", "qixing-shou");
        map_skill("strike", "haotian-zhang");

        prepare_skill("hand", "qixing-shou");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("inquiry", ([
                "���Ž���" : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.po" :),
                (: perform_action, "parry.suo" :),
                (: perform_action, "strike.ju" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        setup();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("xuanmen-neigong", 1) < 120
           && (int)ob->query_skill("quanzhen-xinfa", 1) < 120)
        {
                command("say ��ı����ڹ��ķ�����㣬�������Ը�������书��");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 120)
        {
                command("say �����������Է��滹���Ӷ����������ѧ�ķ����ߺ������ɡ�");
                return;
        }

        if (ob->query("combat_exp") < 200000)
        {
                command("say ���ʵս����̫������������Ը�������书��");
                return;
        }

        if ((int)ob->query("shen") < 30000)
        {
                command("say �����������ұ�ѧ���˵���ּ�����ⷽ�滹���ò�����\n");
                return;
        }

        command("haha");
        command("say ������������������ģ��Ҿ������㡣");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/jinguan-yusuo/suo"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("jinguan-yusuo", 1) < 1)
                return "�������������ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 400)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 50000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("jinguan-yusuo", 1) < 150)
                return "��Ľ������������죬���ߵ������ɡ�";

        if (me->query_skill("force") < 200)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ��˵�������Ҹ�����ʾһ�飬��"
                     "����ϸ�ˡ���ֻ��$n" HIY "�������䣬��ʱ���������˫"
                     "����Ļ�Ȧ�������������λ����$N" HIY "��ȥ����ʱ"
                     "$N" HIY "ֻ������һ��������˫��̱��ȫ���������Ʊ�"
                     "$n" HIY "��סһ�㡣\n\n" NOR, me, this_object()); 

        command("nod");
        command("say ���п��Ƽ򵥣�ʵȴ����ޱȣ����������ɡ�");
        command("say �պ����߽������мǵ����˴������ˣ�ĪҪ������");
        tell_object(me, HIC "��ѧ���ˡ����Ž�������\n" NOR);
        if (me->can_improve_skill("parry"))
                me->improve_skill("parry", 1500000);
        if (me->can_improve_skill("jinguan-yusuo"))
                me->improve_skill("jinguan-yusuo", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/jinguan-yusuo/suo", 1);
        me->add("gongxian", -400);

        return 1;
}

void unconcious()
{
        die();
}
