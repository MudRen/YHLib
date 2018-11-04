inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>
#include "xuedao.h"

string ask_for_join();
int do_kneel();

void create()
{
        set_name("����", ({ "shan yong", "shan", "yong" }));
        set("long", @LONG
һ�����ֵ�����ɮ�ˣ����Ц�ݣ�ȴ����Ц��ص����¡�
LONG);
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 21);
        set("con", 22);
        set("dex", 19);
        set("max_qi", 2800);
        set("max_jing", 1400);
        set("neili", 2600);
        set("max_neili", 2600);
        set("jiali", 15);
        set("combat_exp", 75000);

        set_skill("force", 120);
        set_skill("mizong-neigong", 120);
        set_skill("parry", 120);
        set_skill("blade", 120);
        set_skill("xueshan-dao", 120);
        set_skill("dodge", 120);
        set_skill("shenkong-xing", 120);
        set_skill("hand", 120);
        set_skill("dashou-yin", 120);
        set_skill("cuff", 120);
        set_skill("yujiamu-quan", 120);
        set_skill("lamaism", 140);
        set_skill("literate", 140);
        set_skill("martial-cognize", 100);

        map_skill("force", "mizong-neigong");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");
        map_skill("parry", "xueshan-dao");
        map_skill("blade", "xueshan-dao");

        prepare_skill("cuff", "yujiamu-quan");
        prepare_skill("hand", "dashou-yin");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "blade.kai" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "cuff.jiang" :),
                (: exert_function, "recover" :),
        }) );

        set("inquiry",([
                "���" : (: ask_for_join :),
                "����" : (: ask_for_join :),
        ]));

        create_family("Ѫ����", 5, "����");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
        add_action("do_kneel", "kneel");

}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((string)ob->query("gender") == "Ů��")
        {
                command("say �Ҳ���Ůͽ�ܡ�\n");
                return;
        }

        if ((string)ob->query("gender") != "����")
        {
                command("say ��������Ц�ˣ����ǸϿ�ع�ȥ�ź���ϰɡ�\n");
                return;
        }

        if (ob->query("class") != "bonze")
        {
                ob->set_temp("pending/join_bonze", 1);
                command("say �㲻�ǳ����ˣ�����Ѫ�����ǲ��������ġ������"
                        "����Ҫ���ң��͹��°�(" HIY "kneel" NOR + CYN ")��" NOR);
                return;
        }

        command("recruit " + ob->query("id"));
}

string ask_for_join()
{
        object me;

        me = this_player();

        if ((string)me->query("class") == "bonze")
                return "�����ӷ�����ͬ�ǳ����ˣ��ιʸ�ƶɮ�������Ц��\n";

        if ((string)me->query("gender") == "Ů��")
                return "ʩ��������������ǿ�ϲ�ɺأ���ϧ���²���Ůͽ��\n";

        if ((string)me->query("gender") != "����")
                return "��������Ц�ˣ����ǸϿ�ع�ȥ�ź���ϰɡ�\n";

        me->set_temp("pending/join_bonze", 1);
        return "�����ӷ����գ����գ�ʩ������������ҷ������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
        object me = this_player();

        if (! me->query_temp("pending/join_bonze"))
                return notify_fail("����˰�㣬���û�����㡣\n");

        message_vision(HIY "$N" HIY "˫�ֺ�ʮ�����������ع���������\n\n"
                       "$n" HIY "������ƣ���$N" HIY "ͷ�������Ħ���˼�"
                       "�£���$N" HIY "��ͷ��������ȥ��\n\n" NOR, me,
                       this_object());

        command("ke");

        me->set("class", "bonze");
        command("recruit " + me->query("id"));

        return 1;
}
