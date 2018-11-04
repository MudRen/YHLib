#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "afanti" }) );
        set("gender", "����" );
        set("age", 48);
        set("long", "��ͷ�ϰ���ͷ�����������̵İ��ֺ�����ϲ��\n"
                    "׽Ū�������������ˡ����������˳����\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("dodge", 25);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2500);

        set("attitude", "peaceful");
        set("inquiry", ([
            	"name" : "�Ҿ������ն��İ����ᡣ",
            	"here" : "��������Ǹ��õط���",
            	"���ն�" : "���ҳ����ĵط���",
            	"����" : "�����ҹ�������г��кȣ��ҾͲ����ˡ������Ǹ�������Ը����ͷ�����",
            	"ë¿" : "�ҵ�Сë¿���ҵ�ɳĮ��ƭ�����ֽ���ʱ�߶��ˡ�",
            	"¿" : "�ҵ�Сë¿���ҵ�ɳĮ��ƭ�����ֽ���ʱ�߶��ˡ�",
            	"Сë¿" : "�ҵ�Сë¿���ҵ�ɳĮ��ƭ�����ֽ���ʱ�߶��ˡ�",
            	"����" : "������������������������",
            	"����" : "�����������������Ψ���������º�Ĭ����������ʹ�ߡ�",
        ]) );

        setup();
        carry_object("/clone/cloth/wcloth")->wear();
        carry_object("/d/xingxiu/obj/dongbula");
}

int accept_object(object who, object ob)
{
     	if ((string)ob->query("id") != "mao lv")
		return 0;

        write(CYN "\n������Ц���춼�ϲ����ˣ�˵����л��λ" + 
              RANK_D->query_respect(who) + "�İ�����\n" NOR);

	if (who->query("score") < 100)
	{
		who->add("score", 5 + random(5));
		tell_object(who, HIC "��Ľ�����������ˡ�\n" NOR);
	}

	destruct(ob);
	return 1;
}

