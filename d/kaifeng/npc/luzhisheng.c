#include <ansi.h>
inherit NPC;

void create()
{
	set_name("³����", ({"lu zhisheng", "lu", "zhisheng"}));
	set("long", "����ִ����¶����һ���壬������̨ɽ����ɮ�ˡ�\n");
        set("gender", "����");
	set("nickname", HIM "������" NOR);
	set("title", "��ɽ�ú�");
	set("age", 42);
	set("shen_type", 1);
	set("str", 35);
	set("int", 20);
	set("con", 20);
        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 200);
	set("combat_exp", 1500000);
	set("score", 20000);
        set("apply/attack",  100);
        set("apply/defense", 100);

        set_skill("cuff", 180);
        set_skill("force", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("strike", 180);
        set_skill("zixia-shengong", 180);
        set_skill("poyu-quan", 180);
        set_skill("hunyuan-zhang", 180);
        set_skill("feiyan-huixiang",180);

        map_skill("cuff", "poyu-quan");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("cuff", "poyu-quan");

	set("chat_chance", 5);
	set("chat_msg", ({
		CYN "³����ȵ��������ˣ���ü���۵Ŀ���ү��ʲô��\n" NOR,
		CYN "³����߷ߵĵ����������仧�Ҵ����Ҳ�԰�ӵ����⣬�ߣ��ߣ�\n" NOR,
		CYN "³����˵��������˵����һ������ҵ���������Ժ��ʲô�ġ�\n" NOR,
	}));
        setup();

	carry_object(__DIR__"obj/dao-cloth")->wear();
	add_money("silver", 50);
}
