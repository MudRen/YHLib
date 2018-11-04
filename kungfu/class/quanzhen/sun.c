#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("�ﲻ��", ({ "sun buer", "sun", "buer" }));
        set("long", @LONG
������ȫ��̶���������Ψһ��Ů�����ﲻ��
�����ˡ��������������ǰ�����ӣ���������
��һ������ͷ��
LONG);
        set("nickname", CYN "�徻ɢ��" NOR);
        set("title", "ȫ������");
        set("gender", "Ů��");
        set("age", 33);
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

        set("max_qi", 3500);
        set("max_jing", 2800);
        set("neili", 4200);
        set("max_neili", 4200);
        set("jiali", 150);

        set("combat_exp", 1500000);

        set_skill("force", 200);
        set_skill("quanzhen-xinfa", 200);
        set_skill("xuanmen-neigong", 200);
        set_skill("sword", 180);
        set_skill("qixing-jian", 180);
        set_skill("dodge", 200);
        set_skill("tianshan-feidu", 200);
        set_skill("parry", 200);
        set_skill("strike", 180);
        set_skill("chongyang-shenzhang", 180);
        set_skill("finger", 180);
        set_skill("zhongnan-zhi", 180);
        set_skill("whip", 200);
        set_skill("tiangang-chenfa", 200);
        set_skill("literate", 180);
        set_skill("taoism", 180);
        set_skill("martial-cognize", 160);

        map_skill("force", "xuanmen-neigong");
        map_skill("sword", "qixing-jian");
        map_skill("dodge", "tianshan-feidu");
        map_skill("whip", "tiangang-chenfa");
        map_skill("parry", "tiangang-chenfa");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "chongyang-shenzhang");

        prepare_skill("finger", "zhongnan-zhi");
        prepare_skill("strike", "chongyang-shenzhang");

        create_family("ȫ���", 2, "����");

        set("inquiry", ([
                "�������" : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "whip.bai" :),
                (: perform_action, "finger.zhi" :),
                (: perform_action, "strike.lian" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        setup();

        carry_object("/d/beijing/npc/obj/fuchen")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query("gender") == "����")
        {
                command("say �Ҳ�����ͽ���㻹��ȥ���Ҽ�λʦ��Ϊʦ�ɡ�\n");
                return;
        }

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

        if (me->query("can_perform/tiangang-chenfa/bai"))
                return "�����Ҳ����Ѿ��̻�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "������ƶ���ز���ʶ����֪�˻��Ӻ�˵��";

        if (me->query_skill("tiangang-chenfa", 1) < 1)
                return "�����������ûѧ����̸���п��ԣ�";

        if (me->query("gongxian") < 150)
                return "������ȫ�����������Ϊ����������ʱ�����ܴ��㡣";

        if (me->query("shen") < 10000)
                return "����������»����ò�������������ʱ�����ܴ��㡣";

        if (me->query_skill("tiangang-chenfa", 1) < 120)
                return "��������������죬���ߵ������ɡ�";

        if (me->query("max_neili") < 1500)
                return "���������Ϊ�����������ߺ��������Ұɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ������վ��������һ������"
                     "�з�����ʱ�ܶ����ѣ����������������ʽ����Ϯ$N" HIY
                     "����Ҫ������ʽɷΪ�������̾Ϊ��ֹ��\n\n" NOR,
                     me, this_object()); 

        command("nod");
        command("say ��ʽ�Ҷ��Ѿ������ˣ��Լ���ȥ����ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����������\n" NOR);
        if (me->can_improve_skill("whip"))
                me->improve_skill("whip", 1500000);
        if (me->can_improve_skill("tiangang-chenfa"))
                me->improve_skill("tiangang-chenfa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/tiangang-chenfa/bai", 1);
        me->add("gongxian", -150);

        return 1;
}
