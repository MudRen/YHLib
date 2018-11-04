#include <ansi.h>
#include "xiaoyao.h"

inherit NPC;
inherit F_MASTER;

mixed ask_item1();
mixed ask_item2();

void create()
{
        set_name("�밢��", ({ "feng asan", "feng" , "asan"}));
        set("long", "��˵������³��ĺ��ˣ������ĵ�һ�ɽ�����\n"
                    "��ƻ��ص����֡�\n");
        set("title", "��ң�ɺ��Ȱ���");
        set("nickname", HIY "�ɽ�" NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude", "friendly");
        set("class", "alchemist");
        set("shen_type", 1);
        set("str", 38);
        set("int", 28);
        set("con", 30);
        set("dex", 28);

	set("max_qi", 1800);
	set("max_jing", 1400);
	set("neili", 2200);
	set("max_neili", 2200);
	set("jiali", 70);
	set("combat_exp", 500000);

        set_skill("force", 120);
        set_skill("xiaoyao-xinfa", 120);
        set_skill("dodge", 120);
        set_skill("feiyan-zoubi", 120);
        set_skill("strike", 100);
        set_skill("panyang-zhang", 100);
        set_skill("hand", 100);
        set_skill("qingyun-shou", 100);
        set_skill("parry", 120);
        set_skill("blade", 120);
        set_skill("ruyi-dao", 120);
        set_skill("literate", 100);
        set_skill("qimen-wuxing", 180);
        set_skill("martial-cognize", 100);

	map_skill("force", "xiaoyao-xinfa");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("hand", "qingyun-shou");
	map_skill("strike", "panyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");

        prepare_skill("hand", "qingyun-shou");
        prepare_skill("strike", "panyang-zhang");

        set("inquiry", ([
                "������" : (: ask_item1 :),
                "������" : (: ask_item2 :),
        ]));

        if (random(5) > 3)
                set("bagua_count", 1);

        if (random(4) > 2)
        	set("xiang_count", 1);

	create_family("��ң��", 3, "����");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "hand.zhuo" :),
                (: perform_action, "strike.pan" :),
                (: perform_action, "blade.ruyi" :),
                (: exert_function, "recover" :),
        }));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 26)
        {
                command("say ���Դ��ֲ���⣬�ܸ�����ʲô��");
                return;
        }

        command("say �ðɣ��Ҿ��������ˣ���ɻ��˵����");
        command("recruit " + ob->query("id"));
}

mixed ask_item1()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "��ң��")
                return "����˭���������ģ�����ʶ��ô��";

        if (me->query("family/master_id") != "wuya zi"
           && me->query("family/master_id") != "su xinghe")
                return "���������������ң�ɾ�����Ҫ������";

        if (me->query_skill("qimen-wuxing", 1) < 80)
                return "���ֲ����������У���ȥ�����ã�";

        if (query("bagua_count") < 1)
                return "������Ҳû���ˣ����Լ�ȥ������һ���ɡ�";

        add("bagua_count", -1);
        ob = new("/d/taohua/obj/bagua");
        ob->move(this_object());

        command("give tie bagua to " + me->query("id"));
        return "��ֻ�������������ȥ�ðɡ�";
}

mixed ask_item2()
{
        object me;
        object ob;

        me = this_player();

        if (me->query("family/family_name") != "��ң��")
                return "����˭���������ģ�����ʶ��ô��";

        if (me->query("family/master_id") != "wuya zi"
           && me->query("family/master_id") != "su xinghe")
                return "���������������ң�ɾ�����Ҫ������";

        if (me->query_skill("qimen-wuxing", 1) < 80)
                return "���ֲ����������У���ȥ�����ã�";

        if (query("xiang_count") < 1)
                return "������Ҳû���ˣ�������������ɡ�";

        add("xiang_count", -1);
        ob = new("/d/taohua/obj/xiang");
        ob->move(this_object());

        command("give buzhen xiang to " + me->query("id"));
        return "����������ˣ��ɱ𵽴�ȥϹ���͡�";
}