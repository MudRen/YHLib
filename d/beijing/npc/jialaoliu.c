#include <ansi.h>

inherit NPC;
int ask_weiwang();

void create()
{
        set_name("������", ({ "jia laoliu", "jia" }));
        set("title", HIR "��ػ�"HIG"��ľ��"NOR"����");
        set("shen_type", 1);

        set("gender", "����");
        set("age", 35);
        set("long",
                "\n������ػ���ľ�û��ڣ�����������֮ʱ�����������ɣ�\n"+
                "�����ǲ���ɱ���췴��ֻ����˽©˰����û���ӵ�С���⣬\n"+
                "������������������׷ɱ��éʮ��Ҳ��˺���������\n");
        set("no_get_from", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("chat_chance", 3);
        set("chat_msg", ({
        "��������Ȼ˵�������η�����ɶ�\n",
        "������˵: ������������Ҫ������ֵ�ߴ��кô�����\n",
        "������ͻȻ˵��: ������ǰ�ֵ��ڣ����е㽫�������\n",
        }));
        set("inquiry", ([
                "�½���" :  "\n����ܶ����ɲ����װ���\n",
                "��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
                "����" :  "\nֻҪ��������ػᣬ��ҾͿ���һ���ิ����\n",
                "���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
       ]) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void die()
{
        message_vision("\n$N��е����ֵ��ǻ����ұ���ģ�ͷһƫ�����ˡ�\n", this_object());
	::die();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\n������˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
	say("��������˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
	return 1;
}

