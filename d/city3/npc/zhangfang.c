// zhangfang.c

#include <ansi.h>

inherit NPC;
int  chu_hai();

void create()
{
        set_name("�˷��Ϸ���", ({ "lao zhangfang","zhangfang","lao" }));
        set("gender", "����");
        set("age", 56);
        set("long",
        "����һ����Ǯ�ۿ������˷���������˪������͸��һ˿�ƻ���\n", );

        set("combat_exp", 10000);
        set("shen_type", 1);

	set("eff_qi",2000);
	set("qi",2000);
        set("max_neili", 1000);
        set("neili", 1000);
        set("jiali", 100);

        set_skill("force", 200);
        set_skill("unarmed", 400);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set("inquiry", ([
            "ѧ��"  : "�������ӣ�\n",
            "ѧϰ"  : "�Ƚ��������ӣ�\n",
            "����"  : "�Ƚ��������ӣ�\n",
            "ѧ��"  : "�Ƚ��������ӣ�\n",
            "ѧ�书": "�Ƚ��������ӣ�\n",
            "�߼�Ǯ" : "���ٵ�������ƽ�\n",
        ]) );

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

int accept_object(object who, object ob)
{
    if (who->query("combat_exp")>= 50000
        && !who->query_temp("can_paid"))
    {
        message_vision("���˷�����$N˵������书Ӧ���������������ٳ�������"
                       "����û�������ˡ�\n", who);

        write("���˷����Ķ���˵���������������ϳ�" HIY "�߼�Ǯ" NOR"��Ҳ"
              "���ǲ����ԣ���\n");
 
        who->set_temp("can_paid", 1);

	return 0;
    }
    if (ob->query("money_id") && ob->value() >= 500
        && !who->query_temp("can_paid"))
    {
        who->set_temp("marks/jinniu_paied",1);
        message_vision("���˷���$N˵���ã���Ȼ��λ" + RANK_D->query_respect(who) 
          + "����Ͻ����Ǿͽ�ȥ��ʦ��ѧ�ɣ�\n" , who);
       	return 1;
    }
    else 
    if (who->query_temp("can_paid") 
        && ob->query("money_id") && ob->value() >= 5000000)
    {
        who->set_temp("marks/jinniu_paied",1);
        write("���ʷ���������˵��������ȥ�ɣ��ɱ�˵����ʶ�ң���\n");
       	return 1;
    }
    else  
        message_vision("���˷���ü��$N˵��������Ҳ̫���˵���ɣ�\n", who);
	return 0;
}
