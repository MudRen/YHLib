#include <ansi.h>

inherit NPC;
inherit F_MASTER;

#define JIASHA    "/clone/lonely/book/kuihua2"

mixed ask_me();

void create()
{
        object ob;
	set_name("��Ԫ��ʦ", ({ "duyuan chanshi", "duyuan", "chanshi" }) );
	set("title", "���������¸���");
	set("gender", "����");
	set("age", 63);
	set("long", "��Ԫ��ʦ�������������·��ɺ�Ҷ��ʦ�ĵ���\n"
                    "���ӣ�������Ͳ��ӷ�͵������������һ�¶�\n"
                    "��ɽ��á�\n");
	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 3500000);
	set("str", 33);
	set("int", 32);
	set("con", 34);
	set("dex", 31);

	set("max_qi", 6000);
	set("max_jing", 4000);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 200);
	create_family("������", 35, "����");

	set_skill("force", 280);
	set_skill("sword", 280);
	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("unarmed", 280);
	set_skill("strike", 260);
	set_skill("claw", 260);
	set_skill("hand", 260);
	set_skill("pixie-jian", 280);
	set_skill("yijinjing", 280);
	set_skill("shaolin-xinfa", 260);
	set_skill("damo-jian", 260);
	set_skill("fumo-jian", 260);
	set_skill("shaolin-shenfa", 260);
	set_skill("xumishan-zhang", 260);
	set_skill("longzhua-gong", 260);
	set_skill("qianye-shou", 260);
	set_skill("literate", 260);
	set_skill("buddhism", 300);
	set_skill("martial-cognize", 260);
	set_skill("medical", 240);
	set_skill("shaolin-yishu", 240);

	map_skill("force", "yijinjing");
	map_skill("sword", "pixie-jian");
	map_skill("parry", "pixie-jian");
	map_skill("dodge", "pixie-jian");
	map_skill("unarmed", "pixie-jian");
	map_skill("strike", "xumishan-zhang");
	map_skill("claw", "longzhua-gong");
	map_skill("hand", "qianye-shou");
	map_skill("medical", "pixie-jian");

	prepare_skill("unarmed", "pixie-jian");

	set("inquiry", ([
		"��а����" : (: ask_me :),
		"��������" : (: ask_me :),
	]));

        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/dodge", 150);
        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 200);

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.gui" :),
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.pi" :),
        }));

	setup();

        if (clonep())
        {
                ob = find_object(JIASHA);
                if (! ob) ob = load_object(JIASHA);
                if (! environment(ob))
                {
                        ob->move(this_object());
                        ob->wear();
                } else
		{
			ob = new("/d/shaolin/obj/xuan-cloth");
                        ob->move(this_object()); 
                        ob->wear();
		}
        }

        carry_object("/d/beijing/npc/obj/sword3")->wield();
}

mixed ask_me()
{
        message("vision", HIR "��Ԫ��ʦ��е�������ô֪��������Ҫ�־�ֻ"
                          "�ܹ�������ˣ�\n" NOR, environment(),
                          this_object() );
        kill_ob(this_player());
        return 1;
}
