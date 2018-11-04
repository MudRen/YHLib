#include <ansi.h>
#include "duan.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("���Ƴ�", ({ "gu ducheng", "gu", "ducheng" }));
        set("title", "���������" );
        set("nickname", HIY "���Ĺ���" NOR);
        set("long", "���Ǵ�����Ĵ���֮һ��\n");
        set("gender", "����");
        set("age", 40);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);

        set("max_qi", 1800);
        set("max_jing", 1000);
        set("neili", 2200);
        set("max_neili", 2200);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 120);
        set_skill("duanshi-xinfa", 120);
        set_skill("dodge", 120);
        set_skill("tiannan-bu", 120);
        set_skill("cuff", 120);
        set_skill("jinyu-quan", 120);
        set_skill("strike", 120);
        set_skill("wuluo-zhang", 120);
        set_skill("hammer", 140);
        set_skill("pangen-cuojiefu", 140);
        set_skill("parry", 120);
        set_skill("literate", 80);
        set_skill("martial-cognize", 140);

        map_skill("force", "duanshi-xinfa");
        map_skill("dodge", "tiannan-bu");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("hammer", "pangen-cuojiefu");
        map_skill("parry", "pangen-cuojiefu");

        prepare_skill("cuff", "jinyu-quan");
        prepare_skill("strike", "wuluo-zhang");

        set("inquiry", ([
                "���־�"   : (: ask_skill1 :),
        ]));

        create_family("���ϻ���", 15, "�ҳ�");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.cuo" :),
                (: perform_action, "cuff.man" :),
                (: perform_action, "strike.bian" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/d/dali/npc/obj/junfu")->wear();
        carry_object("/d/heimuya/npc/obj/dafu")->wield();
        add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("ah");
        command("say ���ӵ��º�����ˣ�ֻҪ���·Ը�����һ�����ǡ�");
        command("say �����Ӳ������������ﵹ����һ�׸������Դ������㡣");

        return;
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���ϻ���")
        {
                command("heng");
                command("say ����ʲô�ˣ���ĳΪ��Ҫ�������㣿");
                return -1;
        }

        if (skill != "pangen-cuojiefu" && skill != "hammer")
        {
                command("say �Ҿ�ֻ�����׸����õó��֣�����Ļ����������ѧ�ɡ�");
                return -1;
        }

        if (! ob->query_temp("can_learn/guducheng"))
        {
                command("hehe");
                command("say ��Ȼ��������ϰ�䣬�������߾����ܴ��ڡ�");
                ob->set_temp("can_learn/guducheng", 1);
        }
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/pangen-cuojiefu/cuo"))
                return "������⡭���²����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�͹�ĳ�ز���ʶ���γ����ԣ�";

        if (me->query_skill("pangen-cuojiefu", 1) < 1)
                return "���ӵ��»�����ѧ�����µ��̸���ڸ���˵�ɡ�";

        if (me->query("gongxian") < 150)
                return "����������Ҳ�Ը�⡭ֻ����ү�Ը��ˣ��޹����߲��á��Ǹ���";

        if (me->query_skill("force") < 120)
                return "��������ӵ��µ��ڹ���Ϊ���д���ߡ�";

        if ((int)me->query("max_neili", 1) < 800)
                return "��������ӵ��µ�������Ϊ���д���ߡ�";

        if (me->query_skill("pangen-cuojiefu", 1) < 100)
                return "���ӵ����̸���ڸ��Ļ�򻹲����������ò������С�";

        message_sort(HIY "\n$n" HIY "��$N" HIY "���˵�ͷ���漴ȡ����"
                     "��󸫣����ḫ������Ȼ��һ���Ϻȣ������ͻ�����"
                     "�������в�ʧ���棬�������������硣\n\n" NOR,
                     me, this_object()); 

        command("bow");
        command("say ��ĳ��ʶǳ������ѧ���˶��ѣ������ӵ��¼�Ц�ˡ�");
        tell_object(me, HIC "��ѧ���ˡ����־�����\n" NOR);
        if (me->can_improve_skill("hammer"))
                me->improve_skill("hammer", 1500000);
        if (me->can_improve_skill("pangen-cuojiefu"))
                me->improve_skill("pangen-cuojiefu", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pangen-cuojiefu/cuo", 1);
        me->add("gongxian", -150);
        return 1;
}
