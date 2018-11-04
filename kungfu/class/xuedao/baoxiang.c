inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>
#include "xuedao.h"

mixed ask_skill1();

void create()
{
        set_name("����", ({ "bao xiang", "bao", "xiang" }));
        set("long", @LONG
һ�����߼��ݵ�ɮ�ˣ�������â���䡣������
Ѫ���������£������ĺ�������
LONG);
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 21);
        set("con", 24);
        set("dex", 22);
        set("max_qi", 5000);
        set("max_jing", 2500);
        set("neili", 2800);
        set("max_neili", 2800);
        set("jiali", 30);
        set("combat_exp", 250000);

        set_skill("force", 160);
        set_skill("mizong-neigong", 160);
        set_skill("xuedao-dafa", 80);
        set_skill("parry", 160);
        set_skill("blade", 160);
        set_skill("xueshan-dao", 160);
        set_skill("honglian-dao", 160);
        set_skill("dodge", 160);
        set_skill("shenkong-xing", 160);
        set_skill("hand", 160);
        set_skill("dashou-yin", 160);
        set_skill("cuff", 160);
        set_skill("yujiamu-quan", 160);
        set_skill("lamaism", 160);
        set_skill("literate", 140);
        set_skill("martial-cognize", 160);

        map_skill("force", "mizong-neigong");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");
        map_skill("parry", "honglian-dao");
        map_skill("blade", "honglian-dao");

        prepare_skill("cuff", "yujiamu-quan");
        prepare_skill("hand", "dashou-yin");

        set("no_teach", ([
                "xuedao-dafa" : "Ѫ���󷨱����������״���",
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huo" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "cuff.jiang" :),
                (: exert_function, "recover" :),
        }) );

        create_family("Ѫ����", 5, "����");
        set("class", "bonze");

        set("inquiry", ([
                "���ǻ���" : (: ask_skill1 :),
        ]));

	set("coagents", ({
		([ "startroom" : "/d/xuedao/shandong3",
		   "id" : "xuedao laozu" ]),
	}));

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

        add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query("class") != "bonze")
        {
                ob->set_temp("pending/join_bonze", 1);
                command("say �㲻�ǳ����ˣ�����Ѫ�����ǲ��������ġ�"
                        "�����Ҫ���ң���������ʦ�ܡ�");
                return;
        }

        if (ob->query("shen") > 0)
        {
                command("say ������������������Ļ�����\n");
                this_object()->kill_ob(ob);
                return;
        }

        if ((int)ob->query_skill("lamaism", 1) < 40)
        {
                command("say ����Ѫ���ţ���ϰ���ڷ�����Ҫ�ġ�\n");
                return;
        }

        if ((int)ob->query_skill("force") < 75)
        {
                command("say �������������ô���Ȱ��ڹ����ã�\n");
                return;
        }

        command("recruit " + ob->query("id"));
}

mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/honglian-dao/huo"))
                return "�Ҳ��Ƕ��Ѿ��̹�������";

        if (me->query("family/family_name") != query("family/family_name"))
                return "���ֲ�����Ѫ���ŵģ��������������㣡";

        if (me->query_skill("honglian-dao", 1) < 1)
                return "��������������ûѧ��������ʲô��";

        if (me->query("gongxian") < 80)
                return "����˵�ˣ�զ�ǵľ��������޹�֮�ˡ�";

        if (me->query("shen") > -8000)
                return "�������Ĵ���������ѧ����������ʲô�ã�";

        if (me->query_skill("force") < 120)
                return "����ڹ���Ϊʵ��̫���ȥ������������";

        if (me->query("max_neili") < 800)
                return "������������������Ȼ������˼�����ң�";

        if (me->query_skill("honglian-dao", 1) < 80)
                return "����Ѻ��������������������Ұɡ�";

        message_vision(HIY "$n" HIY "��Ц���������ֽ�$N" HIY "�е���ǰ��������$N" HIY
                       "�����ֹ��˰�\n�졣Ȼ���ְγ�������ת���£�б�ö������ƺ���"
                       "һ����Ϊ\n���صĵ�����\n" NOR, me, this_object());

        command("bored");
        command("say ���ˣ����ˡ����Լ�ȥ���ɡ�");
        tell_object(me, HIC "��ѧ���ˡ����ǻ��꡹��\n" NOR);

        if (me->can_improve_skill("blade"))
                me->improve_skill("blade", 1500000);
        if (me->can_improve_skill("honglian-dao"))
                me->improve_skill("honglian-dao", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/honglian-dao/huo", 1);
        me->add("gongxian", -80);

        return 1;
}