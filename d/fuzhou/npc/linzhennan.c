#include <ansi.h>
inherit NPC;

int ask_pixie();

void create()
{
        set_name("������", ({ "lin zhennan", "lin", "zhennan" }));
        set("gender", "����");
        set("age", 45);
        set("long", "�����ǡ������ھ֡�������ͷ�����ϡ�\n");
        set("title", HIY "�����ھ�����ͷ" NOR);
        set("combat_exp", 100000);
        set("shen_type", 1);

        set("max_qi", 800);
        set("max_neili", 1000);
        set("neili", 1000);
        set("jiali", 30);

        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("pixie-sword", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);

        map_skill("parry", "pixie-sword");
        map_skill("sword", "pixie-sword");

        set("inquiry", ([
                "������լ" : "�����Ҵ�ǰ�ڸ���ʱס�ļ�Ժ���Ѿ��ư��ˡ�\n",
                "�����ھ�" : "�����ھֿ������ڣ�������������Զͼ�����괳�µ�������\n",
                "Զͼ��"   : "�游����ʮ��·��а���������ھ֣�������ڵ��޵��֡�\n",
                "��Զͼ"   : "С������ôû��ò��ֱ���������䣡\n",
                "��а����" : (: ask_pixie :),
        ]) );

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int ask_pixie()
{
	message("vision", HIR "�����ϴ�ŭ�����㾹�ҿ������ּұ�а���ף����վ������ʶ"
                          "��ʶ��\n" NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}
