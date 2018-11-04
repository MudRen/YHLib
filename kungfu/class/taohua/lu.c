#include <ansi.h>
#include "taohua.h"

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();
mixed ask_skill2();

void create()
{
        set_name( "½�˷�" ,({ "lu chengfeng", "lu", "chengfeng" }));
        set("gender", "����");
        set("nickname", HIC "����ׯ��" NOR);
        set("age", 52);
        set("long", "½�˷��ǻ�ҩʦ�ĵ��ĸ�ͽ�ܡ������޽���΢���׷�����\n"
                    "��Ŀ��࣬˫������\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 24);
        set("int", 30);
        set("con", 25);
        set("dex", 21);

        set("max_qi", 4500);
        set("max_jing", 2500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 120);
        set("combat_exp", 1000000);

        set_skill("force", 200);
        set_skill("luoying-xinfa", 200);
        set_skill("unarmed", 200);
        set_skill("xuanfeng-tui", 200);
        set_skill("strike", 200);
        set_skill("pikong-zhang", 200);
        set_skill("finger", 180);
        set_skill("canglang-zhi", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("luoying-shenjian", 200);
        set_skill("literate", 180);
        set_skill("qimen-wuxing", 160);
        set_skill("calligraphy", 160);
        set_skill("martial-cognize", 160);

        map_skill("force", "luoying-xinfa");
        map_skill("unarmed", "xuanfeng-tui");
        map_skill("strike", "pikong-zhang");
        map_skill("finger", "canglang-zhi");
        map_skill("dodge", "xuanfeng-tui");
        map_skill("parry", "luoying-shenjian");
        map_skill("sword", "luoying-shenjian");

        prepare_skill("unarmed", "xuanfeng-tui");
        prepare_skill("strike", "pikong-zhang");

        create_family("�һ���", 2, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.sui" :),
                (: perform_action, "finger.tao" :),
                (: perform_action, "strike.dai" :),
                (: perform_action, "unarmed.kuang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }));

        set("inquiry", ([
                "��а" : "��ʦ�˳ƶ�а���Ǻǡ�",
                "����" : "ŷ���������ʦ���������ĸ��֣��˳��϶��",
                "�ϵ�" : "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
                "��ؤ" : "��ؤ���߹���ؤ��������������ݳ��⡣",
                "����" : "����ʦ���İ�Ů��",
                "��ҩʦ" : "��Ҫ�ݷü�ʦ��",
                "�һ���" : "��������һ������������Ǳ��ɵ��ӣ�Ҫ���һ���",
                "�һ���" : "���Ͼ����ˡ�",
                "���Ǵ���" : (: ask_skill1 :),
                "������" : (: ask_skill2 :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
        string master;
        if (! permit_recruit(ob))
                return;
        
        if (stringp(master = ob->query_temp("taohua/master")))
        {
                if (master != name())
                {
                        command("say ��ʦ���������" + master + "��������ô��"
                                "�������ˣ�");
                        return;
                }

                command("say �ðɣ���Ȼ��ʦ����Ҿ��������ˣ�����Ҫ�ú�������"
                        "�����Ĺ�ء�");
                command("recruit " + ob->query("id"));
                ob->delete_temp("taohua/master");
                return;
        }

        command("shake");
        command("say �ҿɲ���������ͽ���㻹���Ҽ�ʦ�Ƶ����ɣ�");
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/pikong-zhang/dai"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ���������";

        if (me->query_skill("pikong-zhang", 1) < 1)
                return "���������ƶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 80)
                return "ʦ���Ը��������������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊ���������Ƕ���������ɡ�";

        if (me->query_skill("pikong-zhang", 1) < 80)
                return "��������ƻ������������������������ҡ�";

        message_sort(HIY "\n$n" HIY "����$N" HIY "���˵�ͷ��˵�������Ҹ�����ʾ"
                     "һ�飬�ɿ���ϸ�ˣ����������䣬��ʱֻ��$n" HIY "˫�ƽ�����"
                     "�����������������Ȧ������һ������$N" HIY "�ȥ����������"
                     "�����ޱȡ�\n\n" NOR, me, this_object());

        command("smile");
        command("say ��ʽ������ˣ����Լ���ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����Ǵ��¡���\n" NOR);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("pikong-zhang"))
                me->improve_skill("pikong-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/pikong-zhang/dai", 1);
        me->add("gongxian", -80);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xuanfeng-tui/kuang"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ���������";

        if (me->query_skill("xuanfeng-tui", 1) < 1)
                return "��������ɨҶ�ȶ�ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 300)
                return "ʦ���Ը��������������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 150)
                return "����ڹ���Ϊ���������Ƕ���������ɡ�";

        if (me->query_skill("xuanfeng-tui", 1) < 100)
                return "�������ɨҶ�Ȼ�����������������������";

        if (me->query_skill("pikong-zhang", 1) < 100)
                return "��������ƻ������������������������ҡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ���ȵ����������ˣ�������$n" HIY
                     "�������µ�һ˲�䣬���Ѱεض��𣬶�Ȼʹ������ɨҶ�ȿ��"
                     "�����������Ʈ������������糾����Я�������ʽ������"
                     "�ƻֺ룬����ֻϮ��$N" HIY "�����������ۡ�\n\n" NOR, me,
                     this_object());

        command("haha");
        command("say ��ȥ���Ҫ�ڼ���ϰ��Ī�����˶�ʦ��һ�����ࡣ");
        tell_object(me, HIC "��ѧ���ˡ�����������\n" NOR);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("strike"))
                me->improve_skill("strike", 1500000);
        if (me->can_improve_skill("xuanfeng-tui"))
                me->improve_skill("xuanfeng-tui", 1500000);
        if (me->can_improve_skill("pikong-zhang"))
                me->improve_skill("pikong-zhang", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xuanfeng-tui/kuang", 1);
        me->add("gongxian", -300);

        return 1;
}
