// longquan.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("����", ({ "long quan", "long" }));
        set("title","��ţ��ݽ�ϰ");
        set("long", "����ү�������Ҳ���˺ö���ͷ�ˣ����ϵ���׳��\n");
        set("gender", "����");
        set("age", 60);

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("claw", 80);
        set_skill("blade", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        setup();

        carry_object("/clone/book/expert-sword");
        carry_object("/clone/book/expert-sword");                        carry_object("/clone/book/expert-sword");                        carry_object("/clone/book/expert-sword");                        carry_object("/clone/book/expert-sword");
        carry_object("/clone/book/expert-blade");
        carry_object("/clone/book/expert-blade");
        carry_object("/clone/book/expert-blade");
        carry_object("/clone/book/expert-blade");
        carry_object("/clone/book/expert-blade");
        carry_object("/clone/book/expert-dagger");
        carry_object("/clone/book/expert-dagger");
        carry_object("/clone/book/expert-dagger");
        carry_object("/clone/book/expert-dagger");
        carry_object("/clone/book/expert-dagger");
        carry_object("/clone/book/expert-unarmed");
        carry_object("/clone/book/expert-unarmed");
        carry_object("/clone/book/expert-unarmed");
        carry_object("/clone/book/expert-unarmed");
        carry_object("/clone/book/expert-unarmed");
        carry_object("/clone/book/expert-dodge");
        carry_object("/clone/book/expert-dodge");
        carry_object("/clone/book/expert-dodge");
        carry_object("/clone/book/expert-dodge");
        carry_object("/clone/book/expert-dodge");
        carry_object("/clone/book/expert-parry");
        carry_object("/clone/book/expert-parry");
        carry_object("/clone/book/expert-parry");
        carry_object("/clone/book/expert-parry");
        carry_object("/clone/book/expert-parry");
        carry_object("/clone/book/expert-force");
        carry_object("/clone/book/expert-force");
        carry_object("/clone/book/expert-force");
        carry_object("/clone/book/expert-force");
        carry_object("/clone/book/expert-force");
        carry_object("/clone/book/expert-staff");
        carry_object("/clone/book/expert-staff");
        carry_object("/clone/book/expert-staff");
        carry_object("/clone/book/expert-staff");
        carry_object("/clone/book/expert-staff");
        carry_object("/clone/book/expert-whip");
        carry_object("/clone/book/expert-whip");
        carry_object("/clone/book/expert-whip");
        carry_object("/clone/book/expert-whip");
        carry_object("/clone/book/expert-whip");
        carry_object("/clone/book/expert-throwing");
        carry_object("/clone/book/expert-throwing");
        carry_object("/clone/book/expert-throwing");
        carry_object("/clone/book/expert-throwing");
        carry_object("/clone/book/expert-throwing");
}

void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

int recognize_apprentice(object ob)
{
        if (! (int)ob->query_temp("marks/jinniu_paied") == 1) return 0;
        return 1;
}

