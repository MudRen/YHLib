#include <ansi.h>
#include "wudu.h"

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "pan xiuda", "pan" }));
        set("nickname", HIY "Ц������" NOR);
        set("long", @LONG
�������嶾�̵��󻤷����˳�Ц�����޵�����
�����һ��Ц���еģ����ǳ���ɱ���ڵ�
ָ֮�䡣
LONG);
        set("title","�嶾�̻���");
        set("gender", "����");
        set("age", 38);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2500);
        set("max_jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 500000);
        set("score", 50000);

        set("gender", "����");
        set("age", 38);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 20);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 120);
        set_skill("wudu-xinfa", 120);
        set_skill("dodge", 110);
        set_skill("jinshe-youshenbu", 110);
        set_skill("strike", 110);
        set_skill("tianchan-zhang", 110);
        set_skill("claw", 110);
        set_skill("wusheng-zhao", 110);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("jinwu-goufa", 120);
        set_skill("literate", 60);
        set_skill("poison", 120);
        set_skill("wudu-qishu", 120);
        set_skill("martial-cognize", 100);

        map_skill("force", "wudu-xinfa");
        map_skill("dodge", "jinshe-youshenbu");
        map_skill("strike", "tianchan-zhang");
        map_skill("claw", "wusheng-zhao");
        map_skill("parry", "jinwu-goufa");
        map_skill("sword", "jinwu-goufan");
        map_skill("poison", "wudu-qishu");

        prepare_skill("strike", "tianchan-zhang");
        prepare_skill("claw", "wusheng-zhao");

        create_family("�嶾��", 12, "����");

        setup();

        carry_object("/d/wudu/npc/obj/ganggou")->wield();
        carry_object("/d/city/obj/cloth")->wear();

        add_money("silver", 20);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") > -5000)
        {
                command("say �����嶾�̵��ӱ����ĺ�������");
                return;
        }
        if ((int)ob->query_skill("wudu-xinfa", 1) < 40)
        {
                command("say ����嶾�ķ���ѧ�Ĳ�������");
                return;
        }
        if ((int)ob->query_skill("wudu-qishu", 1) < 30)
        {
                command("say ���嶾�̵����Զ�ɱ�ˣ���ϰ��������Ҫ�ġ�");
                command("say ���Ƿ�Ӧ�ö�����б��ŵľ�ѧ��");
                return;
        }

        command("smile");
        command("say ��������");
        command("recruit " + ob->query("id"));
        return;
}
