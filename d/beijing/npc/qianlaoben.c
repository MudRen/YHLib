#include <ansi.h>

inherit NPC;
inherit F_BANKER;
int ask_weiwang();

void create()
{
        set_name("Ǯ�ϱ�", ({"qian laoben", "qian", "laoben"}));
        set("title", HIR "��ػ�"HIG"��ľ��"NOR"����");
        set("gender", "����");
        set("age", 34);

        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("qi", 500); 
        set("max_qi", 500);
        set("jing", 100);
        set("max_jing", 100);
        set("shen", 0);

        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set("inquiry", ([
                "��Ϣ" :  "\n��Ҫ��Ϣ����ᣡ\n",
                "�½���" :  "\n����ܶ�����û��ô���ס�\n",
                "��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
                "����" :  "\nֻҪ��������ػᣬ��ҾͿ���һ���ิ����\n",
                "���" :  "\nֻҪ��������ػᣬ��ҾͿ���һ���ิ����\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
       ]) );

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}

int ask_weiwang()
{
        command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +
                (string)(this_player()->query("weiwang")));
        say("\nǮ�ϱ�˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
            "�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
        say("Ǯ�ϱ���˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");

        return 1;
}

#include "/kungfu/class/yunlong/tiandihui.h"

