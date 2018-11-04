#include <ansi.h>
#include "wudu.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

void create()
{
        set_name("�κ�ҩ", ({ "he hongyao", "he" }));
        set("nickname", WHT "����ؤ��" NOR);
        set("long", @LONG
�������嶾�̵ĳ��ϣ������Ĺùúκ�ҩ����Ȼ��
�����ĳ�����������ȴ��һ����ϴ�����ѧ�ġ���
˵����������Ϊ�����̳��ˣ����������´����
�Ա������˴�����ʥ�أ�����ǰ�������һ����
�ɵ������������̺ۣ����ù������˫Ŀ������
Թ��֮ɫ��
LONG);
        set("title", "�嶾�̳���");
        set("gender", "Ů��");
        set("age", 45);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("score", 10000);

        set_skill("force", 180);
        set_skill("wudu-xinfa", 180);
        set_skill("xiuluo-yinshagong", 160);
        set_skill("dodge", 180);
        set_skill("jinshe-youshenbu", 180);
        set_skill("strike", 180);
        set_skill("tianchan-zhang", 180);
        set_skill("claw", 180);
        set_skill("wusheng-zhao", 180);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("jinwu-goufa", 180);
        set_skill("whip", 140);
        set_skill("xiewei-bian", 140);
        set_skill("throwing", 100);
        set_skill("hansha-sheying", 100);
        set_skill("literate", 100);
        set_skill("poison", 120);
        set_skill("wudu-qishu", 120 );
        set_skill("martial-cognize", 160);

        set("no_teach", ([
                "xiuluo-yinshagong"  : "������ɷ�������ɽ����״���",
                "hansha-sheying"     : "��ɳ��Ӱ�⼼���Ҷ�û�ܹ�ѧ�á�",
        ]));

        map_skill("force", "xiuluo-yinshagong");
        map_skill("dodge", "jinshe-youshenbu");
        map_skill("strike", "tianchan-zhang");
        map_skill("claw", "wusheng-zhao");
        map_skill("throwing", "hansha-sheying");
        map_skill("parry", "jinwu-goufa");
        map_skill("sword", "jinwu-goufa");
        map_skill("whip", "xiewei-bian");
        map_skill("poison", "wudu-qishu");

        prepare_skill("strike", "tianchan-zhang");
        prepare_skill("claw", "wusheng-zhao");

        set("coagents", ({
                ([ "startroom" : "/d/wudu/huating1",
                   "id"        : "he tieshou" ]),
        }));

        set("guarder", ([
                "refuse_other": CYN "$N" CYN "����һ�Σ���ס$n" CYN
                                "���ȵ���û�н���׼��˭Ҳ���ý���"
                                "����ʥ�ء�" NOR,
                "refuse_carry": CYN "$N" CYN "��$n" CYN "�ȵ�����"
                                "���ϱ�����ʲô�ˣ����ҷ�������" NOR,
        ]));

        create_family("�嶾��", 11, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "claw.lian" :),
                (: perform_action, "strike.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }) );

        setup();

        carry_object("/d/wudu/npc/obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/d/wudu/obj/wuxing");

        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -1000)
        {
                command("say ��Խ����Խ���������������Եס�");
                return;
        }
        if ((int)ob->query("shen") > -8000)
        {
                command("say ���Ĵ��������ǲ�������ģ�");
                return;
        }
        if ((int)ob->query("combat_exp") < 60000)
        {
                command("say �㻹����ȥ�����㾭��ɡ�");
                return;
        }
        if ((int)ob->query_skill("wudu-xinfa", 1) < 80)
        {
                command("say ����嶾�ķ���ѧ�Ĳ�������");
                return;
        }
        if ((int)ob->query_skill("wudu-qishu", 1) < 50)
        {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ���Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }

       command("nod");
       command("say ��������");
       command("recruit " + ob->query("id"));
       ob->set("title", "�嶾�̻���");
       return;
}
