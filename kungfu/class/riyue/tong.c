#include <ansi.h>
#include "riyue.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ͯ����", ({ "tong baixiong", "tong", "baixiong"}) );
        set("nickname", HIR "�൨����" NOR );
        set("title", "������̷����ó���");
        set("long", @LONG
�����������̷����ó���ͯ���ܣ����ڽ���
��λ�Ѿã�ֻ�����׷���ɢ��������ţ�����
�ļ��ⲻͣǣ����
LONG);
        set("gender", "����");
        set("class", "scholar");
        set("age", 75);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 36);
        set("int", 36);
        set("con", 36);
        set("dex", 36);
        
        set("max_qi", 5400);
        set("max_jing", 4000);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 250);
        set("combat_exp", 3000000);
        set("score", 50000);

        set_skill("force", 240);
        set_skill("tianhuan-shenjue", 240);
        set_skill("riyue-xinfa", 220);
        set_skill("dodge", 220);
        set_skill("juechen-shenfa", 220);
        set_skill("cuff", 220);
        set_skill("zhenyu-quan", 220);
        set_skill("claw", 220);
        set_skill("poyue-zhao", 220);
        set_skill("parry", 220);
        set_skill("hammer", 240);
        set_skill("pangu-qishi", 240);
        set_skill("club", 220);
        set_skill("jinyuan-gun", 220);
        set_skill("martial-cognize", 220);
        set_skill("literate", 180);

        map_skill("dodge", "juechen-shenfa");
        map_skill("force", "tianhuan-shenjue");
        map_skill("hammer", "pangu-qishi");
        map_skill("club", "jinyuan-gun");
        map_skill("parry", "pangu-qishi");
        map_skill("cuff", "zhenyu-quan");
        map_skill("claw", "poyue-zhao");

        prepare_skill("claw", "poyue-zhao");
        prepare_skill("cuff", "zhenyu-quan");

        create_family("�������", 13, "�����ó���");

        set_temp("apply/damage", 200);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "hammer.kai" :),
                (: perform_action, "cuff.tong" :),
                (: perform_action, "claw.duan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();

        carry_object("/d/heimuya/npc/obj/tongchui")->wield();
        carry_object("/d/heimuya/npc/obj/jinpao")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

     	command("say �Ϸ������Ѵ󣬲�����ͽ����ȥ���������Ϻ��ˡ�");
}
