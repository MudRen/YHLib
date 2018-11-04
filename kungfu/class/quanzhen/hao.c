#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("�´�ͨ", ({ "hao datong", "hao", "datong" }));
        set("long", @LONG
������ȫ�������еĺ´�ͨ�����ˡ������΢
�֣��������ģ�������ϴ��ĵ���˫����ޡ�
LONG);
        set("nickname", HIG "������" NOR);
        set("title", "ȫ������");
        set("gender", "����");
        set("age", 41);
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

        set("max_qi", 4200);
        set("max_jing", 3000);
        set("neili", 4800);
        set("max_neili", 4800);
        set("jiali", 150);

        set("combat_exp", 2000000);

        set_skill("force", 220);
        set_skill("quanzhen-xinfa", 220);
        set_skill("xuanmen-neigong", 220);
        set_skill("sword", 200);
        set_skill("qixing-jian", 200);
        set_skill("quanzhen-jian", 200);
        set_skill("dodge", 200);
        set_skill("tianshan-feidu", 200);
        set_skill("parry", 200);
        set_skill("strike", 200);
        set_skill("chongyang-shenzhang", 200);
        set_skill("finger", 200);
        set_skill("zhongnan-zhi", 200);
        set_skill("hand", 220);
        set_skill("qixing-shou", 220);
        set_skill("literate", 200);
        set_skill("taoism", 200);
        set_skill("martial-cognize", 180);

        map_skill("force", "xuanmen-neigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "tianshan-feidu");
        map_skill("hand", "qixing-shou");
        map_skill("parry", "qixing-shou");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "chongyang-shenzhang");

        prepare_skill("hand", "qixing-shou");

        create_family("ȫ���", 2, "����");

        set("inquiry", ([
                "�������" : (: ask_skill1 :),
        ]) );

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.po" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        setup();

        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query_skill("xuanmen-neigong", 1) < 60
           && (int)ob->query_skill("quanzhen-xinfa", 1) < 60)
        {
                command("say ��ı����ڹ��ķ�����㣬�������Ը�������书��");
                return;
        }

        if ((int)ob->query_skill("taoism", 1) < 60)
        {
                command("say �����������Է��滹���Ӷ����������ѧ�ķ����ߺ������ɡ�");
                return;
        }

        if ((int)ob->query("shen") < 8000)
        {
                command("say �����������������������̫�٣�\n");
                return;
        }

        command("nod");
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/qixing-shou/po"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("qixing-shou", 1) < 1)
                return "�������Ƿ����ֶ�ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 800)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 30000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("qixing-shou", 1) < 150)
                return "������Ƿ����ֲ�����죬���ߵ������ɡ�";

        if (me->query_skill("force") < 200)
                return "����ڹ���Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ���ӻ�������ȡ����һ��"
                     "С���ӣ�ָ�����е�һ�ζ�$N" HIY "ϸ˵���ã�$N"
                     HIY "һ����һ�ߵ�ͷ��\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say ���Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ�������ԡ���\n" NOR);
        if (me->can_improve_skill("hand"))
                me->improve_skill("hand", 1500000);
        if (me->can_improve_skill("qixing-shou"))
                me->improve_skill("qixing-shou", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qixing-shou/po", 1);
        me->add("gongxian", -800);

        return 1;
}
