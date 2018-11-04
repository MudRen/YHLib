#include <ansi.h>
#include "xueshan.h"
#include "tobebonze.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("���ײ�", ({ "ge lunbu", "ge", "lunbu" }));
        set("long", @LONG
���ײ��Ǵ����»���ɮ����ͷ�졣ͬʱ����
���Ӵ����书����һ����ɫ���ģ�ͷ��ɮñ��
LONG);
        set("title", "������ɮ��ͷ��");
        set("gender", "����");
        set("class", "bonze");
        set("age", 30);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 30);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 3000);
        set("max_jing", 2000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 80);
        set("combat_exp", 300000);

        set_skill("force", 120);
        set_skill("mizong-neigong", 120);
        set_skill("dodge", 120);
        set_skill("shenkong-xing", 120);
        set_skill("hammer", 140);
        set_skill("dali-chu", 140);
        set_skill("hand", 120);
        set_skill("dashou-yin", 120);
        set_skill("cuff", 120);
        set_skill("yujiamu-quan", 120);
        set_skill("parry", 120);
        set_skill("lamaism", 100);
        set_skill("literate", 80);
        set_skill("sanscrit", 200);
        set_skill("martial-cognize", 100);

        map_skill("force", "mizong-neigong");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "dali-chu");
        map_skill("hammer", "dali-chu");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");

        prepare_skill("cuff", "yujiamu-quan");
        prepare_skill("hand", "dashou-yin");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.hong" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "cuff.jiang" :),
                (: exert_function, "recover" :),
        }));

        create_family("������", 3, "����");

        set("inquiry",([
                "���" : (: ask_for_join :),
                "����" : (: ask_for_join :),
        ]));

        set("coagents", ({
                ([ "startroom" : "/d/xueshan/neidian",
                   "id"        : "jinlun fawang", ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "��$n" CYN "��ȵ���"
                                "�����վס�����Ǵ����������ɵ���"
                                "������߶��ط���" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ���������ҷ���"
                                "����" NOR,
        ]));

        setup();

        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/gangchu")->wield();
        add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;
 
        if ((string)ob->query("gender") != "����")
        {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) + "������"
                        "�ذɣ�");
                return;
        }

        command("say ��Ȼ������ϰ�䣬�Ҿʹ���һЩ�书�ɣ�");
        if ((string)ob->query("class") != "bonze")
	{
                command("say ����������������ϲ��书��ȴ�ǵ���" HIY "��"
                        "��" NOR + CYN "���ɡ�" NOR);
                ob->set("title", "ѩɽ���׼ҵ���");
	}
        command("recruit " + ob->query("id"));
}
