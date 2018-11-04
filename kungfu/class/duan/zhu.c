#include <ansi.h>
#include "duan.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create()
{
        set_name("�쵤��", ({ "zhu danchen", "zhu", "danchen" }));
        set("title", "���������" );
        set("nickname", CYN "������" NOR);
        set("long", "���Ǵ�����Ĵ���֮һ��һ������������Ĵ����ͷ��\n");
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
        set_skill("dagger", 140);
        set_skill("qingliang-daxuefa", 140);
        set_skill("parry", 120);
        set_skill("literate", 280);
        set_skill("martial-cognize", 140);

        map_skill("force", "duanshi-xinfa");
        map_skill("dodge", "tiannan-bu");
        map_skill("cuff", "jinyu-quan");
        map_skill("strike", "wuluo-zhang");
        map_skill("dagger", "qingliang-daxuefa");
        map_skill("parry", "qingliang-daxuefa");

        prepare_skill("cuff", "jinyu-quan");
        prepare_skill("strike", "wuluo-zhang");

        set("inquiry", ([
                "͸�Ƕ�"   : (: ask_skill1 :),
        ]));

        create_family("���ϻ���", 15, "�ҳ�");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "dagger.ding" :),
                (: perform_action, "cuff.man" :),
                (: perform_action, "strike.bian" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/d/dali/npc/obj/junfu")->wear();
        carry_object("/d/meizhuang/obj/panguanbi")->wield();
        add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        command("smile");
        command("say ���ӵ��º�����ˣ�ֻҪ���·Ը�����һ�����ǡ�");
        command("say �����Ӳ������������ﵹ����һ�ױʷ����Դ������㡣");

        return;
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "���ϻ���")
        {
                command("sneer");
                command("say ��������ز���ʶ����֪���´˻��Ӻ�˵��");
                return -1;
        }

        if (skill != "qingliang-daxuefa" && skill != "dagger")
        {
                command("say ��ĳ��ƽֻ�Աʷ�һ�������о�������������֪��ǳ��");
                return -1;
        }

        if (! ob->query_temp("can_learn/zhudanchen"))
        {
                command("hehe");
                command("say ��Ȼ��������ϰ�䣬�������߾����ܴ��ڡ�");
                ob->set_temp("can_learn/zhudanchen", 1);
        }
        return 1;
}

mixed ask_skill1()
{
        object me;

        me = this_player();
        if (me->query("can_perform/qingliang-daxuefa/ding"))
                return "�Ҳ����Ѿ��̸�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return RANK_D->query_respect(me) + "�������޹ϸ𣬺γ����ԣ�";

        if (me->query_skill("qingliang-daxuefa", 1) < 1)
                return "������������Ѩ����δѧ����ô������һ˵��";

        if (me->query("gongxian") < 400)
                return "ˡ����������ү�Ը��������ô������޹��ӵܡ�";

        if (me->query_skill("force") < 150)
                return "����ڹ���Ϊ̫�ѧ������һ�С�";

        if ((int)me->query("max_neili", 1) < 1200)
                return "���������Ϊ̫�ѧ������һ�С�";

        if (me->query_skill("qingliang-daxuefa", 1) < 100)
                return "��������Ѩ���Ļ�򻹲�������ȥ���������ɡ�";

        message_sort(HIY "\n$n" HIY "΢΢һЦ�����ֽ�$N" HIY "�е���ǰ����"
                     "����$N" HIY "�����ֹ��˰��졣Ȼ���ְγ��������ȷ�ת��"
                     "�£�б�̶������ƺ���һ����Ϊ���صĴ�Ѩ����\n\n" NOR,
                     me, this_object());

        command("smile");
        command("say ���в��������������ӵ����Ժܿ�Ϳ������������ˡ�");
        tell_object(me, HIC "��ѧ���ˡ�͸�Ƕ�����\n" NOR);
        if (me->can_improve_skill("dagger"))
                me->improve_skill("dagger", 1500000);
        if (me->can_improve_skill("qingliang-daxuefa"))
                me->improve_skill("qingliang-daxuefa", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/qingliang-daxuefa/ding", 1);
        me->add("gongxian", -400);
        return 1;
}
