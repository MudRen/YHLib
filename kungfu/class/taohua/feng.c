#include <ansi.h>
#include "taohua.h"

inherit NPC;
inherit F_MASTER;

mixed ask_me();
mixed ask_skill1();

void create()
{
        set_name( "��Ĭ��" ,({ "feng mofeng", "feng", "mofeng" }));
        set("gender", "����");
        set("age", 39);
        set("long", "��Ĭ���ǻ�ҩʦ��С��һ��ͽ�ܣ����ĸ�������������\n"
                    "��Ϊ��³�����Ļ�������ʵ��һ���Һ���ʵ�����ӡ�\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 24);
        set("con", 27);
        set("dex", 23);
        set("shen_type",1);
        set("max_qi", 4200);
        set("max_jing", 2100);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);
        set("combat_exp", 800000);

        set_skill("force", 180);
        set_skill("luoying-xinfa", 180);
        set_skill("unarmed", 160);
        set_skill("xuanfeng-tui", 160);
        set_skill("strike", 160);
        set_skill("pikong-zhang", 160);
        set_skill("finger", 140);
        set_skill("canglang-zhi", 140);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("sword", 160);
        set_skill("luoying-shenjian", 160);
        set_skill("literate", 140);
        set_skill("martial-cognize", 140);

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

        set("chat_chance", 1);
        set("chat_msg", ({
            	CYN "��Ĭ��˵����ʦ���۰�Сʦ�ã�������⬼�һֱ��Сʦ�ô��š�\n" NOR,
            	CYN "��Ĭ�����������˵������ʦ�����õ�����һ������ǲ��򵥣�\n" NOR,
        }));

        set("inquiry", ([
           	"��ʦ" : (: ask_me :),
           	"Ͷʦ" : (: ask_me :),
           	"��а" : "��ʦ�˳ƶ�а���Ǻǡ�",
           	"����" : "ŷ���������ʦ���������ĸ��֣��˳��϶��",
           	"�ϵ�" : "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
           	"��ؤ" : "��ؤ���߹���ؤ��������������ݳ��⡣",
           	"����" : "����ʦ���İ�Ů��",
           	"��ҩʦ" : "��Ҫ�ݷü�ʦ��",
           	"�һ���" : "��������һ������������Ǳ��ɵ��ӣ�Ҫ���һ���",
           	"�һ���" : "���Ͼ����ˡ�",
           	"��������" : (: ask_skill1 :),
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

        if (me->query("can_perform/canglang-zhi/tao"))
                return "��һ���Ҳ����Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "�㲻�������һ������ˣ���������";

        if (me->query_skill("canglang-zhi", 1) < 1)
                return "��������ָ����ûѧ����̸ʲô���п��ԣ�";

        if (me->query("gongxian") < 50)
                return "ʦ���Ը��������������޹��͵ĵ��ӡ�";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊ���������Ƕ���������ɡ�";

        if (me->query_skill("canglang-zhi", 1) < 80)
                return "��Ĳ���ָ���������������������������ҡ�";

        message_sort(HIY "\n$n" HIY "���˵�ͷ����������Ȼ��ʦ�Ը����������Ҿ�"
                     "�������У���Ҫ�����ˡ���˵��ֻ��$n" HIY "��Ȼ���һָ��"
                     "�׷�����������ָ����Ȼ���죬ȫȫ����$N" HIY "���ܡ�\n\n"
                     NOR, me, this_object());

        command("nod");
        command("say ��������");
        tell_object(me, HIC "��ѧ���ˡ��������졹��\n" NOR);
        if (me->can_improve_skill("finger"))
                me->improve_skill("finger", 1500000);
        if (me->can_improve_skill("canglang-zhi"))
                me->improve_skill("canglang-zhi", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/canglang-zhi/tao", 1);
        me->add("gongxian", -50);

        return 1;
}

mixed ask_me()
{
        object me;
        me = this_player();

        if (me->query("family/family_name"))
        {
                if (me->query("family/family_name") != "�һ���")
                {
                        command("say �����������ɣ���ʦ�ǲ���������ģ����߰ɣ�");
                        return 1;
                }

                if (me->query("family/master_name"))
                {
                        command("say �㲻���Ѿ����������һ�����");
                        return 1;
                }
        }

        if (me->query("detach/�һ���"))
        {
                command("say �������뿪���һ��������컹�һ�������ʦ��");
                return 1;
        }

        if (me->query("betrayer/times"))
        {
                command("say ������ʦ֮�ˣ���ʦ�Ǿ��Բ�������Ϊͽ�ģ�");
                return 1;
        }
        command("say �ðɣ��Ҵ�����һ������Լ�ȥ�һƵ����ɡ�");
        message_vision(HIW "\n$N" HIW "�󲽵�������ȥ��$n" HIW "�������\n\n" NOR,
                       this_object(), me);
        this_object()->move("/d/taohua/damen");
        me->move("/d/taohua/damen");
        command("say ���ˣ��Ҵ��㵽���ţ����ȥ�Ϳ��Լ�����ʦ��");
        message_vision("$NͷҲ���ص���������ȥ��\n", this_object());
        this_object()->move(query("startroom"));
        message_vision("$N���Ҵҵ����˹�����\n", this_object());
        return 1;
}

void unconcious()
{
        die();
}
