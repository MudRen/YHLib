#include <ansi.h>
inherit NPC;

mixed ask_me();

void create()
{
	set_name("����", ({ "meng po", "meng", "po" }) );
	set("title", HIR "�κ��Ŷ���" NOR);
	set("gender", "Ů��");
	set("age", 390);
	set("long",
		"������κ��ŵ����ţ���������ݣ��ݹ��㶡��\n");

	set("attitude", "peaceful");
	set("combat_exp", 2500000);

        set("chat_chance", 1);
        set("chat_msg",({
                CYN "����˵�������ӣ��������ɡ�\n" NOR,
                CYN "����˵���������κ��ţ�ǰ;�ͼ����ˡ�\n" NOR,
                CYN "���Ź�����������������\n" NOR,
                CYN "������������˼�����\n" NOR,
        }));

	set("inquiry", ([
		"������" : (: ask_me :),
		"��"     : (: ask_me :),
		"����"   : (: ask_me :),
		"tang"   : (: ask_me :),
	]));

	set("count", 10);

	setup();

	carry_object(__DIR__"obj/cloth3")->wear();
}

mixed ask_me()
{
	mapping fam; 
	object ob;
        object me = this_player();

        if ( ! me->is_ghost() && ! wizardp(me))
		return "���˺�ʲô��������";

        if (me->query("combat_exp") < 1500000)
		return "�㻹�ǻ�ȥ�ɣ��������㲻��Ҳ�ա�";

	if ( present("mengpo tang", this_player()) )
		return "�����ϲ��ǻ���һ������ô���˻���ô̰�ģ�";

        if (time() - me->query_temp("last_eat/mengpo_tang") < 20000)
		return "�㲻�Ǹողź���һ����";

	if (query("count") < 1)
		return "���Ѿ�Ҩ���ˣ���������һ����";

	ob = new("/d/death/obj/tang");
	ob->move(me);

	add("count", -1);

	message_vision(HIC "\n���Ź�������Ҩ��һ���������ݸ�$N" HIC "��\n\n" NOR, me);
		return "���ӣ����������͸���·�ˡ�";
}