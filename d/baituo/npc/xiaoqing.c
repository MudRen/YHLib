#include <ansi.h>
inherit NPC;

void create()
{
	set_name("С��", ({ "xiao qing", "xiao", "qing" }));
	set("title", "����ɽׯҩʦ");
	set("gender", "Ů��" );
	set("age", 17);
	set("long", "���Ǹ���������С���һϮ���£�ȴҲ�Ե��������¡�\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 20);
	set("int", 29);
	set("con", 23);
	set("dex", 22);

	set("max_qi", 430);
	set("max_jing", 220);
	set("neili", 320);
	set("max_neili", 320);

	set("combat_exp", 60000);
	set("score", 1000);

	set_skill("force", 40);
	set_skill("dodge", 50);
	set_skill("unarmed", 35);
	set_skill("parry", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 17);
	set_temp("apply/armor", 10);

	set_temp("dan",0);
	set_temp("times",5);

        set("inquiry", ([
	    	"���ڴ���" : "�⺣�ڴ���������õ�����ͷСԺ��ȥ����ˮ�ȡ�",
	    	"ҩ��"     : "ҩ�����Ƕ������Լ����ɡ�",
	]));

	setup();
	carry_object("/d/baituo/obj/qingpao")->wear();
}
